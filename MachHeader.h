//
//  MachHeader.h
//  MachOTools
//
//  Created by callum taylor on 03/01/2016.
//  Copyright © 2016 razzile. All rights reserved.
//

#ifndef MachHeader_h
#define MachHeader_h

#include <mach_o/loader.h>
#include <string>
#include "Component.h"
#include "Utils.h"

inline const char *magic_to_name(uint magic) {
  switch (magic) {
    case 0xFEEDFACE:
      return "Little Endian 32-bit";
    case 0xFEEDFACF:
      return "Little Endian 64-bit";
    case 0xCEFAEDFE:
      return "Big Endian 32-bit";
    case 0xCFFAEDFE:
      return "Big Endian 64-bit";
    default:
      return "Error";
  }
}

class MachHeader : public Component {
 public:
  MachHeader(mach_header *header) : _header(header) {}

  mach_header *operator->() { return _header; }

  operator mach_header *() { return _header; }

  std::string Description() {
    return FormatString("mach header: %X (%s)\n", _header->magic,
                        magic_to_name(_header->magic));
  }

 private:
  mach_header *_header;
};

#endif /* MachHeader_h */
