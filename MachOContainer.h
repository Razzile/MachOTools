//
//  MachOContainer.h
//  razzfuscator
//
//  Created by callum taylor on 05/09/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#ifndef __razzfuscator__MachOContainer__
#define __razzfuscator__MachOContainer__

#include "Component.h"
#include "MachOFile.h"
#include "Stream.h"
#include "Utils.h"

class MachOContainer;
class MachHeader;
class LoadCommand;

using LoadCommands = std::vector<LoadCommand>;
using MachOContainerRef = std::unique_ptr<MachOContainer>;

class MachOContainer : public Component {
 public:
  MachOContainer(StreamRef stream) : _stream(stream) {}

  bool TryLoad() { return true; }
  std::string Description() { return ""; }

  Arch GetArch() const { return _arch; }

 private:
  StreamRef _stream;
  Arch _arch;
};
#endif /* defined(__razzfuscator__MachOContainer__) */
