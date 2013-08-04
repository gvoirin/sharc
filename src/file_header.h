/*
 * Centaurean Sharc
 * http://www.centaurean.com/sharc
 *
 * Copyright (c) 2013, Guillaume Voirin
 * All rights reserved.
 *
 * This software is dual-licensed: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation. For the terms of this
 * license, see http://www.gnu.org/licenses/gpl.html
 *
 * You are free to use this software under the terms of the GNU General
 * Public License, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * Alternatively, you can license this library under a commercial
 * license, see http://www.centaurean.com/sharc for more
 * information.
 *
 * 17/06/13 18:14
 */

#ifndef SHARC_FILE_HEADER_H
#define SHARC_FILE_HEADER_H

#define __USE_LARGEFILE64
#define _LARGEFILE_SOURCE
#define _LARGEFILE64_SOURCE

#ifdef __FreeBSD__
#define stat64 stat
#endif

#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <utime.h>

#include "globals.h"

#pragma pack(push)
#pragma pack(4)
typedef struct {
    byte name[5];
    byte version[3];
    uint64_t originalFileSize;
    uint32_t bufferSize;
    uint32_t fileMode;
    uint64_t fileAccessed;
    uint64_t fileModified;
} SHARC_FILE_HEADER;
#pragma pack(pop)

SHARC_FILE_HEADER createFileHeader(const uint32_t, struct stat64);
bool checkFileType(byte*);
SHARC_FILE_HEADER readFileHeader(FILE*);
void restoreFileAttributes(SHARC_FILE_HEADER, const char*);

#endif
