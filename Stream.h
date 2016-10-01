//
//  Header.h
//  MachOTools
//
//  Created by callum taylor on 31/01/2016.
//  Copyright © 2016 razzile. All rights reserved.
//

#ifndef __Stream__
#define __Stream__

#include <stdlib.h>
#include <sys/types.h>
#include <memory>

class Stream;

using uchar = uint8_t;
using StreamRef = std::shared_ptr<Stream>;

class Stream {
 public:
  virtual char ReadChar() = 0;
  virtual uchar ReadUChar() = 0;
  virtual short ReadShort() = 0;
  virtual ushort ReadUShort() = 0;
  virtual int ReadInt() = 0;
  virtual uint ReadUInt() = 0;
  virtual long long ReadLong() = 0;
  virtual unsigned long long ReadULong() = 0;
  virtual void ReadBuf(void *buf, size_t size) = 0;

  virtual char PeekChar() = 0;
  virtual uchar PeekUChar() = 0;
  virtual short PeekShort() = 0;
  virtual ushort PeekUShort() = 0;
  virtual int PeekInt() = 0;
  virtual uint PeekUInt() = 0;
  virtual long long PeekLong() = 0;
  virtual unsigned long long PeekULong() = 0;
  virtual void PeekBuf(void *buf, size_t size) = 0;

  virtual void WriteChar(char c) = 0;
  virtual void WriteUChar(uchar c) = 0;
  virtual void WriteShort(short s) = 0;
  virtual void WriteUShort(ushort s) = 0;
  virtual void WriteInt(int i) = 0;
  virtual void WriteUInt(uint i) = 0;
  virtual void WriteLong(long long l) = 0;
  virtual void WriteULong(unsigned long long l) = 0;
  virtual void WriteBuf(void *buf, size_t size) = 0;

  virtual size_t Offset() = 0;
  virtual void SetOffset(size_t offset) = 0;
};

#endif /* __Stream__ */
