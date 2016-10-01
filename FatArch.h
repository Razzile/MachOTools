//
//  FatArch.h
//  MachOTools
//
//  Created by callum taylor on 07/07/2016.
//  Copyright © 2016 razzile. All rights reserved.
//

#ifndef FatArch_h
#define FatArch_h

#include "Component.h"
#include "Stream.h"

class FatArch : public Component {
 public:
  FatArch(StreamRef stream) : _stream(stream) {}
  bool TryLoad() { return true; }
  std::string Description() { return ""; }

 private:
  StreamRef _stream;
};

#endif /* FatArch_h */
