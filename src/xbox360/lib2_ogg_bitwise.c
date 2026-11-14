/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE Ogg CONTAINER SOURCE CODE.              *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2010             *
 * by the Xiph.Org Foundation http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************

  function: packing variable sized words into an octet stream

 ********************************************************************/
/* Derived from libogg 1.2.x src/bitwise.c (BSD license); see THIRD_PARTY_NOTICES.md. */
#include "lib2_ogg.h"

extern const unsigned long lbl_88035F48[33];   /* mask[] */

/* oggpack_look: peek at up to 32 bits (LSb first) without advancing. */
long lib2_oggpack_look_883BD168(oggpack_buffer *b, int bits)
{
    unsigned long ret;
    unsigned long m = lbl_88035F48[bits];

    bits += b->endbit;

    if (b->endbyte + 4 >= b->storage) {
        /* not the main path */
        if (b->endbyte * 8 + bits > b->storage * 8) return (-1);
    }

    ret = b->ptr[0] >> b->endbit;
    if (bits > 8) {
        ret |= b->ptr[1] << (8 - b->endbit);
        if (bits > 16) {
            ret |= b->ptr[2] << (16 - b->endbit);
            if (bits > 24) {
                ret |= b->ptr[3] << (24 - b->endbit);
                if (bits > 32 && b->endbit)
                    ret |= b->ptr[4] << (32 - b->endbit);
            }
        }
    }
    return (m & ret);
}

/* oggpack_adv: advance the read cursor by bits. */
void lib2_oggpack_adv_883BD230(oggpack_buffer *b, int bits)
{
    bits += b->endbit;
    b->ptr += bits / 8;
    b->endbyte += bits / 8;
    b->endbit = bits & 7;
}

/* oggpack_read: read up to 32 bits (LSb first), -1 past the end. */
long lib2_oggpack_read_883BD268(oggpack_buffer *b, int bits)
{
    long ret;
    unsigned long m = lbl_88035F48[bits];

    bits += b->endbit;

    if (b->endbyte + 4 >= b->storage) {
        /* not the main path */
        ret = -1L;
        if (b->endbyte * 8 + bits > b->storage * 8) goto overflow;
    }

    ret = b->ptr[0] >> b->endbit;
    if (bits > 8) {
        ret |= b->ptr[1] << (8 - b->endbit);
        if (bits > 16) {
            ret |= b->ptr[2] << (16 - b->endbit);
            if (bits > 24) {
                ret |= b->ptr[3] << (24 - b->endbit);
                if (bits > 32 && b->endbit) {
                    ret |= b->ptr[4] << (32 - b->endbit);
                }
            }
        }
    }
    ret &= m;

overflow:

    b->ptr += bits / 8;
    b->endbyte += bits / 8;
    b->endbit = bits & 7;
    return (ret);
}
