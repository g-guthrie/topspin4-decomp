/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2010             *
 * by the Xiph.Org Foundation http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************/
/* Derived from libogg 1.2.x (BSD license); see THIRD_PARTY_NOTICES.md.
   FMOD Ex links a copy whose allocating entry points take an extra leading
   context argument (the FMOD codec), passed through to its memory hooks. */
#ifndef LIB2_OGG_H
#define LIB2_OGG_H

typedef long long ogg_int64_t;
typedef unsigned int ogg_uint32_t;
typedef unsigned int lib2_size_t;

typedef struct {
    unsigned char *header;
    long header_len;
    unsigned char *body;
    long body_len;
} ogg_page;

typedef struct {
    unsigned char *body_data;
    long body_storage;
    long body_fill;
    long body_returned;
    int *lacing_vals;
    ogg_int64_t *granule_vals;
    long lacing_storage;
    long lacing_fill;
    long lacing_packet;
    long lacing_returned;
    unsigned char header[282];
    int header_fill;
    int e_o_s;
    int b_o_s;
    long serialno;
    long pageno;
    ogg_int64_t packetno;
    ogg_int64_t granulepos;
} ogg_stream_state;

typedef struct {
    unsigned char *data;
    int storage;
    int fill;
    int returned;
    int unsynced;
    int headerbytes;
    int bodybytes;
} ogg_sync_state;

typedef struct {
    unsigned char *packet;
    long bytes;
    long b_o_s;
    long e_o_s;
    ogg_int64_t granulepos;
    ogg_int64_t packetno;
} ogg_packet;

typedef struct {
    long endbyte;
    int endbit;
    unsigned char *buffer;
    unsigned char *ptr;
    long storage;
} oggpack_buffer;

/* FMOD codec memory hooks (context first). */
void *fn_8836CBE8(void *ctx, long size);
void *fn_8836CCD8(void *ctx, void *ptr, long size);
void fn_8836CD70(void *ctx, void *ptr);

/* C library routines as they are named in the symbol map. */
void *fn_8857ACB8(void *dst, const void *src, lib2_size_t n);   /* memcpy */
void *fn_88562DC0(void *dst, const void *src, lib2_size_t n);   /* memmove */
void *fn_88569CF0(const void *s, int c, lib2_size_t n);         /* memchr */
void *ts4_memset(void *dst, int c, lib2_size_t n);

#ifdef _MSC_VER
int memcmp(const void *a, const void *b, lib2_size_t n);
#pragma intrinsic(memcmp)
#else
#include <string.h>
#endif

#endif
