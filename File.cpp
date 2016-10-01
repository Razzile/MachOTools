//
//  File.cpp
//  razzfuscator
//
//  Created by callum taylor on 09/08/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#include <fcntl.h>
#include <sys/mman.h>
#include "File.h"

File::File(std::string path) : _path(path), _stream(path) {}

File::~File() {
    _stream.close();
    if (_possibleMap) {
        munmap(_possibleMap, this->Size());
    }
}

void *File::Map() {
    if (_possibleMap) return _possibleMap;
    
    int fd = open(_path.data(), O_RDONLY);
    size_t size = this->Size();
    _possibleMap = mmap((caddr_t)0, size, PROT_READ, MAP_SHARED, fd, 0);
    return _possibleMap;

}

size_t File::Start() {
    return 0;
}

size_t File::End() {
    size_t pos = 0;
    if (_stream.is_open())
    {
        _stream.seekg(0, _stream.end);
        pos = _stream.tellg();
        _stream.seekg(0, _stream.beg);
    }
    return pos;
}

size_t File::Size() {
    return Start() + End();
}

std::string File::Path() {
    return _path;
}
