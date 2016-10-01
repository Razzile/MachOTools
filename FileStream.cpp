//
//  FileStream.cpp
//  MachOTools
//
//  Created by callum taylor on 31/01/2016.
//  Copyright © 2016 razzile. All rights reserved.
//

#include "File.h"
#include "FileStream.h"

FileStream::FileStream(std::string path) {
    _file = new File(path);
}

FileStream::FileStream(File *file) {
    if (file) {
        _file = file;
    }
    else throw new std::runtime_error("FileStream initialized with nullptr");
}

FileStream::~FileStream() {
    delete _file;
}

File *FileStream::GetFile() const {
    return _file;
}

char FileStream::ReadChar() {
    char c;
    ReadBuf(&c, sizeof(c));
    return c;
}

uchar FileStream::ReadUChar() {
    uchar c;
    ReadBuf(&c, sizeof(c));
    return c;
}

short FileStream::ReadShort() {
    short s;
    ReadBuf(&s, sizeof(s));
    return s;
}

ushort FileStream::ReadUShort() {
    ushort s;
    ReadBuf(&s, sizeof(s));
    return s;
}

int FileStream::ReadInt() {
    int i;
    ReadBuf(&i, sizeof(i));
    return i;
}

uint FileStream::ReadUInt() {
    uint i;
    ReadBuf(&i, sizeof(i));
    return i;
}

long long FileStream::ReadLong() {
    long long l;
    ReadBuf(&l, sizeof(l));
    return l;
}

unsigned long long FileStream::ReadULong() {
    unsigned long long l;
    ReadBuf(&l, sizeof(l));
    return l;
}

void FileStream::ReadBuf(void* buf, size_t size) {
    if (_stream.is_open()) {
        _stream.read(reinterpret_cast<char*>(buf), size);
    }
}

char FileStream::PeekChar() {
    char c;
    PeekBuf(&c, sizeof(c));
    return c;
}

uchar FileStream::PeekUChar() {
    uchar c;
    PeekBuf(&c, sizeof(c));
    return c;
}

short FileStream::PeekShort() {
    short s;
    PeekBuf(&s, sizeof(s));
    return s;
}

ushort FileStream::PeekUShort() {
    ushort s;
    PeekBuf(&s, sizeof(s));
    return s;
}

int FileStream::PeekInt() {
    int i;
    PeekBuf(&i, sizeof(i));
    return i;
}

uint FileStream::PeekUInt() {
    uint i;
    PeekBuf(&i, sizeof(i));
    return i;
}

long long FileStream::PeekLong() {
    long long l;
    PeekBuf(&l, sizeof(l));
    return l;
}

unsigned long long FileStream::PeekULong() {
    unsigned long long l;
    PeekBuf(&l, sizeof(l));
    return l;
}

void FileStream::PeekBuf(void* buf, size_t size) {
    size_t offset = Offset();
    if (_stream.is_open()) {
        _stream.read(reinterpret_cast<char*>(buf), size);
    }
    SetOffset(offset);
}

void FileStream::WriteChar(char c) {
    WriteBuf(&c, sizeof(c));
}

void FileStream::WriteUChar(uchar c) {
    WriteBuf(&c, sizeof(c));
}

void FileStream::WriteShort(short s) {
    WriteBuf(&s, sizeof(s));
}

void FileStream::WriteUShort(ushort s) {
    WriteBuf(&s, sizeof(s));
}

void FileStream::WriteInt(int i) {
    WriteBuf(&i, sizeof(i));
}

void FileStream::WriteUInt(uint i) {
    WriteBuf(&i, sizeof(i));
}

void FileStream::WriteLong(long long l) {
    WriteBuf(&l, sizeof(l));
}

void FileStream::WriteULong(unsigned long long l) {
    WriteBuf(&l, sizeof(l));
}

void FileStream::WriteBuf(void* buf, size_t size) {
    if (_stream.is_open()) {
        _stream.write(reinterpret_cast<char*>(buf), size);
        _stream.flush();  // needed?
    }
}

size_t FileStream::Offset() {
    return _stream.tellp();
}

void FileStream::SetOffset(size_t offset) {
    _stream.seekp(offset);
}