//
//  FileStream.hpp
//  MachOTools
//
//  Created by callum taylor on 31/01/2016.
//  Copyright © 2016 razzile. All rights reserved.
//

#ifndef FileStream_hpp
#define FileStream_hpp

#include <string>
#include <fstream>
#include "Stream.h"

class File;

// TODO change offset to long
class FileStream : public Stream {
public:
    FileStream(std::string path);
    FileStream(File *file);
    ~FileStream();
    
    File *GetFile() const;
    
    virtual char ReadChar();
    virtual uchar ReadUChar();
    virtual short ReadShort();
    virtual ushort ReadUShort();
    virtual int ReadInt();
    virtual uint ReadUInt();
    virtual long long ReadLong();
    virtual unsigned long long ReadULong();
    virtual void ReadBuf(void *buf, size_t size);
    
    virtual char PeekChar();
    virtual uchar PeekUChar();
    virtual short PeekShort();
    virtual ushort PeekUShort();
    virtual int PeekInt();
    virtual uint PeekUInt();
    virtual long long PeekLong();
    virtual unsigned long long PeekULong();
    virtual void PeekBuf(void *buf, size_t size);
    
    virtual void WriteChar(char c);
    virtual void WriteUChar(uchar c);
    virtual void WriteShort(short s);
    virtual void WriteUShort(ushort s);
    virtual void WriteInt(int i);
    virtual void WriteUInt(uint i);
    virtual void WriteLong(long long l);
    virtual void WriteULong(unsigned long long l);
    virtual void WriteBuf(void *buf, size_t size);
    
    virtual size_t Offset();
    virtual void SetOffset(size_t offset);
    
    template <typename T> T Read();
    template <typename T> T Peek();
    template <typename T> void Write(T val);
    
protected:
    std::fstream _stream;
    File *_file;
};

template <typename T> T FileStream::Read() {
    T temp;
    ReadBuf(&temp, sizeof temp);
    return temp;
}

template <typename T> T FileStream::Peek() {
    T temp;
    PeekBuf(&temp, sizeof temp);
    return temp;
}

template <typename T> void FileStream::Write(T val) {
    writeBuf(&val, sizeof val);
}

#endif /* FileStream_hpp */
