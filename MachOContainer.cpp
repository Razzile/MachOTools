//
//  MachOContainer.cpp
//  razzfuscator
//
//  Created by callum taylor on 05/09/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#include "MachOContainer.h"

///* TODO: verify this is right */
//
//inline Magic MachOContainer::MagicForArchitecture(Architecture arch)
//{
//    switch (arch)
//    {
//        case Architecture::ARM64:
//            return x64l;
//        case Architecture::x86_64:
//            return x64b;
//        case Architecture::ARMv7:
//        case Architecture::ARMv7S:
//            return x32l;
//        default:
//            return x32b;
//    }
//}
//
//inline bool MachOContainer::Is64BitHeader(uint32_t header) {
//    return (header == 0xFEEDFACF || header == 0xCFFAEDFE);
//}
//
//uint MachOContainer::OffsetForArchitecture(Architecture arch)
//{
//    MachOFile *file = _fileRef;
//    if (file == nullptr)
//        return UINT_MAX;
//    
//    file->SetOffset(0x0); /* beginning of file */
//    uint magic = file->PeekUInt();
//    
//    /* binary is fat, find correct header */
//    if (Is64BitHeader(magic))
//    {
//        fat_header header;
//        file->ReadBuf(&header, sizeof(header));
//        
//        for (int i = 0; i < header.nfat_arch; i++)
//        {
//            fat_arch fat;
//            file->ReadBuf(&arch, sizeof(arch));
//            
//            /* go to slice offset */
//            uint oldOffset = file->Offset();
//            file->SetOffset(fat.offset);
//            
//            magic = file->ReadUInt();
//            if (magic == MachOContainer::MagicForArchitecture(arch))
//                return fat.offset;
//            
//            /* return to fat archs */
//            file->SetOffset(oldOffset);
//        }
//    }
//    
//    /* check binary has correct header at 0x0 */
//    else
//    {
//        if (magic == MachOContainer::MagicForArchitecture(arch))
//            return 0x0;
//    }
//    return UINT_MAX;
//}
//
//void MachOContainer::LoadContainer(Architecture arch, MachOFile *file)
//{
//    uint offset = MachOContainer::OffsetForArchitecture(arch);
//    if (offset == UINT_MAX)
//    {
//        /* error has occured, i.e binary doesn't contain arch */
//        return;
//    }
//    file->SetOffset(offset);
//    
//    if (!LoadMachHeader())
//        return;
//    if (!LoadLoadCommands())
//        return;
//}
//
//bool MachOContainer::LoadMachHeader()
//{
//    if (_mapped)
//    {
//        void *file = _fileRef->MappedFilePtr();
//        Magic magic = *(Magic *)file;
//    }
//    else {
//        Magic magic = (Magic)_fileRef->PeekUInt();
//        
//        magic = MagicForArchitecture(_currentArch);
//        if (m == x64l || m == x64b)
//        {
//            header_xx.header64.reserved = _fileRef->ReadUInt();
//        }
//    }
//
//    MachHeader *header = new MachHeader(header_xx);
//    this->_mach_header = header;
//    
//    return true;
//}
//
//bool MachOContainer::LoadLoadCommands()
//{
//    if (!this->_mach_header)
//        LoadMachHeader();
//    
//    MachHeader header = *_mach_header;
//    printf("%d", Swap(header.ncmds));
//    for (int count = 0; count != Swap(header.ncmds); count++)
//    {
//        uint offset = _fileRef->Offset();
//        uint cmd = 0;
//        uint cmdsize = 0;
//        cmd = _fileRef->ReadUInt();
//        cmdsize = _fileRef->ReadUInt();
//        
//        _load_commands->emplace_back(cmd, cmdsize, offset);
//    }
//    return true;
//
//}
