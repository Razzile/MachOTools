//
//  Utils.h
//  razzfuscator
//
//  Created by callum taylor on 07/08/2015.
//  Copyright (c) 2015 satori. All rights reserved.
//

#ifndef razzfuscator_Utils_h
#define razzfuscator_Utils_h

static uint16_t SwapUint16(uint16_t value) {
    return
    ((value >>  8) & 0x00ff) |
    ((value <<  8) & 0xff00);
}

static uint32_t SwapUint32(uint32_t value) {
    value = ((value >>  8) & 0x00ff00ff) |
    ((value <<  8) & 0xff00ff00);
    value = ((value >> 16) & 0x0000ffff) |
    ((value << 16) & 0xffff0000);
    return value;
}

static uint64_t SwapUint64(uint64_t value) {
    value = (value & 0x00000000ffffffff) << 32 | (value & 0xffffffff00000000) >> 32;
    value = (value & 0x0000ffff0000ffff) << 16 | (value & 0xffff0000ffff0000) >> 16;
    value = (value & 0x00ff00ff00ff00ff) << 8  | (value & 0xff00ff00ff00ff00) >> 8;
    return value;
}

static int16_t SwapInt16(int16_t value) {
    return SwapUint16(static_cast<uint16_t>(value));
}

static int32_t SwapInt32(int32_t value) {
    return SwapUint32(static_cast<uint32_t>(value));
}

static int64_t SwapInt64(int64_t value) {
    return SwapUint64(static_cast<uint64_t>(value));
}

std::string FormatString(const std::string fmt_str, ...) {
    int final_n, n = ((int)fmt_str.size()) * 2; /* Reserve two times as much as the length of the fmt_str */
    std::string str;
    std::unique_ptr<char[]> formatted;
    va_list ap;
    while(1) {
        formatted.reset(new char[n]); /* Wrap the plain char array into the unique_ptr */
        strcpy(&formatted[0], fmt_str.c_str());
        va_start(ap, fmt_str);
        final_n = vsnprintf(&formatted[0], n, fmt_str.c_str(), ap);
        va_end(ap);
        if (final_n < 0 || final_n >= n)
            n += abs(final_n - n + 1);
        else
            break;
    }
    return std::string(formatted.get());
}

#endif
