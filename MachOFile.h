//
//  MachOFile.h
//  razzfuscator
//
//  Created by callum taylor on 07/08/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#ifndef __razzfuscator__MachOFile__
#define __razzfuscator__MachOFile__

#include <mach-o/fat.h>
#include <mach-o/loader.h>
#include <fstream>
#include <string>
#include <vector>
#include "File.h"
#include "FileStream.h"

class MachOContainer;
class MachOFile;

using MachOFileRef = std::unique_ptr<MachOFile>;
using MachOContainerRef = std::unique_ptr<MachOContainer>;

inline static bool is_magic(uint32_t magic) {
  return (magic == MH_MAGIC || magic == MH_MAGIC_64 || magic == MH_CIGAM ||
          magic == MH_CIGAM_64 || magic == FAT_MAGIC || magic == FAT_CIGAM);
}
inline static bool magic_is_thin(uint32_t magic) {
  return (magic == FAT_CIGAM || magic == FAT_MAGIC);
}

enum class Arch {

};

// TODO: make File superclass extend FileStream instead of this?
class MachOFile : public File {
 public:
  /* TODO: change error to a more substantial type (error class?) */
  static MachOFileRef LoadFile(std::string path, bool *error);
  static MachOFileRef LoadFile(File *file, bool *error);

  MachOFile(std::string path);
  MachOFile(const File &file) : File() {}
  ~MachOFile();

  bool ContainsSlice(Arch slice);
  MachOContainer *ContainerForArchitecture(Arch arch);
  std::vector<Arch> AvailableSlices();

 private:
  bool ParseFile();
  bool ParseFatFile();

  StreamRef _stream;
  std::vector<MachOContainerRef> _conatiners;
  std::vector<Arch> _archs;
};

#endif /* defined(__razzfuscator__MachOFile__) */
