//
//  File.h
//  razzfuscator
//
//  Created by callum taylor on 09/08/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#ifndef razzfuscator_File_h
#define razzfuscator_File_h

#include <fstream>
#include <string>

using uchar = uint8_t;

class File {
 public:
  File(std::string path);
  File() = default;
  ~File();

  std::string Path();

  size_t Size();
  size_t Start();
  size_t End();

  void *Map();

 protected:
  std::string _path;
  std::fstream _stream;
  void *_possibleMap;
};

#endif
