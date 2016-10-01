//
//  FatHeader.h
//  MachOTools
//
//  Created by callum taylor on 07/07/2016.
//  Copyright © 2016 razzile. All rights reserved.
//

#ifndef FatHeader_h
#define FatHeader_h

#include <mach-o/fat.h>
#include <memory>
#include "Component.h"
#include "FatArch.h"
#include "Stream.h"

using FatArchRef = std::unique_ptr<FatArch>;

inline const char *fat_magic_to_name(uint magic) {
  switch (magic) {
    case FAT_CIGAM:
      return "Fat header (big endian)";
    case FAT_MAGIC:
      return "Fat header (little endian)";
    default:
      return "Error";
  }
}

class FatHeader : public Component {
 public:
  FatHeader(fat_header *header) : _header(header) {}

  FatHeader(StreamRef stream)
      : _stream(stream) {
          _fatArch = std::make_unique<FatArch>(stream);
      }

  fat_header *operator->() { return _header; }

  operator fat_header *() { return _header; }

  bool TryLoad() {
      _stream->ReadBuf(&_header, sizeof(_header));
      if (_header->magic == FAT_CIGAM) {
          this->Swap();
      }
      return _fatArch->TryLoad(); // maybe pass endian to fatArch?
  }

  std::string Description() {
    return FormatString("fat header: %X (%s)\n", _header->magic,
                        fat_magic_to_name(_header->magic));
  }

  void Swap() {
    _header->magic = SwapUint32(_header->magic);
    _header->nfat_arch = SwapUint32(_header->nfat_arch);
  }

 private:
  fat_header *_header;
  StreamRef _stream;
  FatArchRef _fatArch;
};

#endif /* FatHeader_h */
