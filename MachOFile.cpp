//
//  MachOFile.cpp
//  razzfuscator
//
//  Created by callum taylor on 07/08/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#include <fcntl.h>
#include <sys/mman.h>
#include "FileStream.h"
#include "MachOContainer.h"
#include "MachOFile.h"
#include "Utils.h"
#include "FatHeader.h"

MachOFileRef MachOFile::LoadFile(std::string path, bool* error) {
  MachOFileRef ref = std::make_unique<MachOFile>(path);
  StreamRef stream = std::make_unique<FileStream>(ref.get());

  bool valid = ref->ParseFile();
  if (error && !valid) *error = true;

  return ref;
}

MachOFileRef MachOFile::LoadFile(File* file, bool* error) {
  MachOFileRef ref = std::unique_ptr<MachOFile>(new MachOFile(*file));
  StreamRef stream = std::make_unique<FileStream>(ref.get());

  bool valid = ref->ParseFile();
  if (error && !valid) *error = true;

  return ref;
}

MachOFile::MachOFile(std::string path) : File(path) {}

MachOFile::~MachOFile() {}

bool MachOFile::ContainsSlice(Arch arch) {
  for (const MachOContainerRef& container : _conatiners) {
    if (container->GetArch() == arch) return true;
  }
  return false;
}

MachOContainer* MachOFile::ContainerForArchitecture(Arch arch) {
  for (const MachOContainerRef& ref : _conatiners) {
    if (ref->GetArch() == arch) {
      return ref.get();
    }
  }
  return nullptr;
}

bool MachOFile::ParseFile() {
  uint32_t magic = _stream->ReadUInt();
  // TODO: add FAT_MAGIC_64
  if (!is_magic(magic)) {
    return false;
  }

  if (magic_is_thin(magic)) {
    MachOContainerRef container = std::make_unique<MachOContainer>(_stream);
    if (container->TryLoad()) {
      _conatiners.push_back(std::move(container));
    } else {
      return false;
    }
  } else {
    return ParseFatFile();
  }

  return true;
}

bool MachOFile::ParseFatFile() {
    _stream->SetOffset(0x0);
    
    FatHeader header(_stream);
    
    return true;
}
/*bool MachOFile::LoadMachOFull(MachOFile *file)
{
    if (!file || file->Path().length() <= 0)
    return false;

    if (!IsValidMachOFile(file))
        return false;

    bool ret = true;

    ret &= LoadMachHeader(file);
    ret &= LoadLoadCommands(file);

    return ret;
}

bool MachOFile::LoadMachHeader(MachOFile *file)
{
    mach_header_xx header_xx;

    file->ReadBuf(&header_xx, sizeof(header_xx));

    if (header_xx.header32.magic == MH_MAGIC_64 ||
        header_xx.header32.magic == MH_CIGAM_64)
    {
        header_xx.header64.reserved = file->ReadUInt();
    }
    MachHeader *header = new MachHeader(header_xx);
    file->_mach_header = header;
    return true;
}

bool MachOFile::LoadLoadCommands(MachOFile *file)
{
    if (!file->_mach_header)
        LoadMachHeader(file);

    MachHeader header = *file->_mach_header;
    printf("%d", Swap(header.ncmds));
    for (int count = 0; count != Swap(header.ncmds); count++)
    {
        uint offset = file->Offset();
        uint cmd = 0;
        uint cmdsize = 0;
        cmd = file->ReadUInt();
        cmdsize = file->ReadUInt();

        file->_load_commands->emplace_back(cmd, cmdsize, offset);
    }
    return true;
} */

/*******************
 * MachOFile       *
 * class functions *
 *******************/
/*
MachOFile::MachOFile(std::string file)
: File(file), _mach_header(0), _load_commands(0)
{
    _load_commands = new LoadCommands();
    LoadMachOFull(this);
}

MachHeader *MachOFile::GetMachHeader()
{
    return _mach_header;
}

LoadCommands *MachOFile::GetLoadCommands()
{
    return _load_commands;
} */
