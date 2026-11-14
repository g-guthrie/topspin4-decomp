/* libFLAC - Free Lossless Audio Codec library
 * Copyright (C) 2000,2001,2002,2003,2004,2005,2006,2007  Josh Coalson
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * - Neither the name of the Xiph.org Foundation nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/* Derived from libFLAC 1.2.1 src/libFLAC/bitreader.c (BSD license); see THIRD_PARTY_NOTICES.md.
 * FMOD's copy is built big-endian (no byte swap) and threads an extra leading
 * context argument through the read path and the read callback. */

typedef int FLAC__bool;
typedef unsigned char FLAC__byte;
typedef unsigned int FLAC__uint32;
typedef unsigned short FLAC__uint16;
typedef unsigned long long FLAC__uint64;
typedef unsigned int lib2_size_t;
typedef FLAC__uint32 brword;

#define FLAC__BYTES_PER_WORD 4
#define FLAC__BITS_PER_WORD 32
#define FLAC__WORD_ALL_ONES ((FLAC__uint32)0xffffffff)
#define SWAP_BE_WORD_TO_HOST(x) (x)
#define FLAC__U64L(x) x##ULL
#define COUNT_ZERO_MSBS(word) ( \
    (word) <= 0xffff ? \
        ( (word) <= 0xff? lbl_88035920[word] + 24 : lbl_88035920[(word) >> 8] + 16 ) : \
        ( (word) <= 0xffffff? lbl_88035920[word >> 16] + 8 : lbl_88035920[(word) >> 24] ) \
)
#define min(x,y) ((x)<(y)?(x):(y))
#define false 0
#define true 1

typedef struct {
    FLAC__bool cpuid, bswap, cmov, mmx, fxsr, sse, sse2, sse3, ssse3, _3dnow, ext3dnow, extmmx;
} FLAC__CPUInfo_IA32;
typedef struct {
    FLAC__bool altivec, ppc64;
} FLAC__CPUInfo_PPC;
typedef struct {
    FLAC__bool use_asm;
    int type;
    union {
        FLAC__CPUInfo_IA32 ia32;
        FLAC__CPUInfo_PPC ppc;
    } data;
} FLAC__CPUInfo;

typedef FLAC__bool (*FLAC__BitReaderReadCallback)(void *ctx, FLAC__byte buffer[], lib2_size_t *bytes, void *client_data);

typedef struct FLAC__BitReader {
    brword *buffer;
    unsigned capacity;       /* in words */
    unsigned words;          /* # of completed words in buffer */
    unsigned bytes;          /* # of bytes in incomplete word at buffer[words] */
    unsigned consumed_words;
    unsigned consumed_bits;
    unsigned read_crc16;
    unsigned crc16_align;
    FLAC__BitReaderReadCallback read_callback;
    void *client_data;
    FLAC__CPUInfo cpu_info;
} FLAC__BitReader;

extern unsigned lbl_88B3B008[256];       /* FLAC__crc16_table */
extern const unsigned char lbl_88035920[]; /* byte_to_unary_table */
void *fn_88562DC0(void *dst, const void *src, unsigned int n); /* memmove */
void *fn_88565258(unsigned int n);                              /* malloc */

#define FLAC__CRC16_UPDATE(data, crc) (((((crc)<<8) & 0xffff) ^ lbl_88B3B008[((crc)>>8) ^ (data)]))

/* crc16_update_word_: fold the remaining bytes of a consumed word into the frame CRC. */
void lib2_crc16_update_word__883B6CD0(FLAC__BitReader *br, brword word)
{
    register unsigned crc = br->read_crc16;
    switch (br->crc16_align) {
        case  0: crc = FLAC__CRC16_UPDATE((unsigned)(word >> 24), crc);
        case  8: crc = FLAC__CRC16_UPDATE((unsigned)((word >> 16) & 0xff), crc);
        case 16: crc = FLAC__CRC16_UPDATE((unsigned)((word >> 8) & 0xff), crc);
        case 24: br->read_crc16 = FLAC__CRC16_UPDATE((unsigned)(word & 0xff), crc);
    }
    br->crc16_align = 0;
}

/* bitreader_read_from_client_: compact the buffer and refill it from the read callback. */
FLAC__bool lib2_bitreader_read_from_client__883B6D88(void *ctx, FLAC__BitReader *br)
{
    unsigned start, end;
    lib2_size_t bytes;
    FLAC__byte *target;

    if (br->consumed_words > 0) {
        start = br->consumed_words;
        end = br->words + (br->bytes ? 1 : 0);
        fn_88562DC0(br->buffer, br->buffer + start, FLAC__BYTES_PER_WORD * (end - start));

        br->words -= start;
        br->consumed_words = 0;
    }

    bytes = (br->capacity - br->words) * FLAC__BYTES_PER_WORD - br->bytes;
    if (bytes == 0)
        return false;
    target = ((FLAC__byte *)(br->buffer + br->words)) + br->bytes;

    if (!br->read_callback(ctx, target, &bytes, br->client_data))
        return false;

    end = (br->words * FLAC__BYTES_PER_WORD + br->bytes + bytes + (FLAC__BYTES_PER_WORD - 1)) / FLAC__BYTES_PER_WORD;
    for (start = br->words; start < end; start++)
        br->buffer[start] = SWAP_BE_WORD_TO_HOST(br->buffer[start]);

    end = br->words * FLAC__BYTES_PER_WORD + br->bytes + bytes;
    br->words = end / FLAC__BYTES_PER_WORD;
    br->bytes = end % FLAC__BYTES_PER_WORD;

    return true;
}

/* FLAC__bitreader_init: allocate the word buffer and bind the read callback. */
FLAC__bool lib2_FLAC__bitreader_init_883B6EC0(void *ctx, FLAC__BitReader *br, FLAC__CPUInfo cpu, FLAC__BitReaderReadCallback rcb, void *cd)
{
    (void)ctx;
    br->words = br->bytes = 0;
    br->consumed_words = br->consumed_bits = 0;
    br->capacity = 65536u / FLAC__BITS_PER_WORD;
    br->buffer = (brword *)fn_88565258(sizeof(brword) * br->capacity);
    if (br->buffer == 0)
        return false;
    br->read_callback = rcb;
    br->client_data = cd;
    br->cpu_info = cpu;
    return true;
}

/* FLAC__bitreader_get_read_crc16: finish the CRC over a partially consumed head word. */
FLAC__uint16 lib2_FLAC__bitreader_get_read_crc16_883B7000(FLAC__BitReader *br)
{
    if (br->consumed_bits) {
        const brword tail = br->buffer[br->consumed_words];
        for (; br->crc16_align < br->consumed_bits; br->crc16_align += 8)
            br->read_crc16 = FLAC__CRC16_UPDATE((unsigned)((tail >> (FLAC__BITS_PER_WORD - 8 - br->crc16_align)) & 0xff), br->read_crc16);
    }
    return br->read_crc16;
}

/* FLAC__bitreader_read_raw_uint32: read up to 32 bits MSB first. */
FLAC__bool lib2_FLAC__bitreader_read_raw_uint32_883B70D8(void *ctx, FLAC__BitReader *br, FLAC__uint32 *val, unsigned bits)
{
    if (bits == 0) {
        *val = 0;
        return true;
    }

    while ((br->words - br->consumed_words) * FLAC__BITS_PER_WORD + br->bytes * 8 - br->consumed_bits < bits) {
        if (!lib2_bitreader_read_from_client__883B6D88(ctx, br))
            return false;
    }
    if (br->consumed_words < br->words) {
        if (br->consumed_bits) {
            const unsigned n = FLAC__BITS_PER_WORD - br->consumed_bits;
            const brword word = br->buffer[br->consumed_words];
            if (bits < n) {
                *val = (word & (FLAC__WORD_ALL_ONES >> br->consumed_bits)) >> (n - bits);
                br->consumed_bits += bits;
                return true;
            }
            *val = word & (FLAC__WORD_ALL_ONES >> br->consumed_bits);
            bits -= n;
            lib2_crc16_update_word__883B6CD0(br, word);
            br->consumed_words++;
            br->consumed_bits = 0;
            if (bits) {
                *val <<= bits;
                *val |= (br->buffer[br->consumed_words] >> (FLAC__BITS_PER_WORD - bits));
                br->consumed_bits = bits;
            }
            return true;
        }
        else {
            const brword word = br->buffer[br->consumed_words];
            if (bits < FLAC__BITS_PER_WORD) {
                *val = word >> (FLAC__BITS_PER_WORD - bits);
                br->consumed_bits = bits;
                return true;
            }
            *val = word;
            lib2_crc16_update_word__883B6CD0(br, word);
            br->consumed_words++;
            return true;
        }
    }
    else {
        if (br->consumed_bits) {
            *val = (br->buffer[br->consumed_words] & (FLAC__WORD_ALL_ONES >> br->consumed_bits)) >> (FLAC__BITS_PER_WORD - br->consumed_bits - bits);
            br->consumed_bits += bits;
            return true;
        }
        else {
            *val = br->buffer[br->consumed_words] >> (FLAC__BITS_PER_WORD - bits);
            br->consumed_bits += bits;
            return true;
        }
    }
}

FLAC__bool lib2_FLAC__bitreader_skip_byte_block_aligned_no_crc_883B74F0(void *ctx, FLAC__BitReader *br, unsigned nvals);

FLAC__bool lib2_FLAC__bitreader_read_raw_uint64_883B7380(void *ctx, FLAC__BitReader *br, FLAC__uint64 *val, unsigned bits)
{
    FLAC__uint32 hi, lo;

    if(bits > 32) {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &hi, bits-32))
            return false;
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &lo, 32))
            return false;
        *val = hi;
        *val <<= 32;
        *val |= lo;
    }
    else {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &lo, bits))
            return false;
        *val = lo;
    }
    return true;
}

FLAC__bool lib2_FLAC__bitreader_read_uint32_little_endian_883B7420(void *ctx, FLAC__BitReader *br, FLAC__uint32 *val)
{
    FLAC__uint32 x8, x32 = 0;

    /* this doesn't need to be that fast as currently it is only used for vorbis comments */

    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x32, 8))
        return false;

    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x8, 8))
        return false;
    x32 |= (x8 << 8);

    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x8, 8))
        return false;
    x32 |= (x8 << 16);

    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x8, 8))
        return false;
    x32 |= (x8 << 24);

    *val = x32;
    return true;
}

FLAC__bool lib2_FLAC__bitreader_skip_bits_no_crc_883B80F0(void *ctx, FLAC__BitReader *br, unsigned bits)
{
    /*
     * OPT: a faster implementation is possible but probably not that useful
     * since this is only called a couple of times in the metadata readers.
     */

    if(bits > 0) {
        const unsigned n = br->consumed_bits & 7;
        unsigned m;
        FLAC__uint32 x;

        if(n != 0) {
            m = min(8-n, bits);
            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x, m))
                return false;
            bits -= m;
        }
        m = bits / 8;
        if(m > 0) {
            if(!lib2_FLAC__bitreader_skip_byte_block_aligned_no_crc_883B74F0(ctx, br, m))
                return false;
            bits %= 8;
        }
        if(bits > 0) {
            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x, bits))
                return false;
        }
    }

    return true;
}

FLAC__bool lib2_FLAC__bitreader_skip_byte_block_aligned_no_crc_883B74F0(void *ctx, FLAC__BitReader *br, unsigned nvals)
{
    FLAC__uint32 x;

    /* step 1: skip over partial head word to get word aligned */
    while(nvals && br->consumed_bits) { /* i.e. run until we read 'nvals' bytes or we hit the end of the head word */
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x, 8))
            return false;
        nvals--;
    }
    if(0 == nvals)
        return true;
    /* step 2: skip whole words in chunks */
    while(nvals >= FLAC__BYTES_PER_WORD) {
        if(br->consumed_words < br->words) {
            br->consumed_words++;
            nvals -= FLAC__BYTES_PER_WORD;
        }
        else if(!lib2_bitreader_read_from_client__883B6D88(ctx, br))
            return false;
    }
    /* step 3: skip any remainder from partial tail bytes */
    while(nvals) {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x, 8))
            return false;
        nvals--;
    }

    return true;
}

FLAC__bool lib2_FLAC__bitreader_read_byte_block_aligned_no_crc_883B75E0(void *ctx, FLAC__BitReader *br, FLAC__byte *val, unsigned nvals)
{
    FLAC__uint32 x;

    /* step 1: read from partial head word to get word aligned */
    while(nvals && br->consumed_bits) { /* i.e. run until we read 'nvals' bytes or we hit the end of the head word */
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x, 8))
            return false;
        *val++ = (FLAC__byte)x;
        nvals--;
    }
    if(0 == nvals)
        return true;
    /* step 2: read whole words in chunks */
    while(nvals >= FLAC__BYTES_PER_WORD) {
        if(br->consumed_words < br->words) {
            const brword word = br->buffer[br->consumed_words++];
#if FLAC__BYTES_PER_WORD == 4
            val[0] = (FLAC__byte)(word >> 24);
            val[1] = (FLAC__byte)(word >> 16);
            val[2] = (FLAC__byte)(word >> 8);
            val[3] = (FLAC__byte)word;
#elif FLAC__BYTES_PER_WORD == 8
            val[0] = (FLAC__byte)(word >> 56);
            val[1] = (FLAC__byte)(word >> 48);
            val[2] = (FLAC__byte)(word >> 40);
            val[3] = (FLAC__byte)(word >> 32);
            val[4] = (FLAC__byte)(word >> 24);
            val[5] = (FLAC__byte)(word >> 16);
            val[6] = (FLAC__byte)(word >> 8);
            val[7] = (FLAC__byte)word;
#else
            for(x = 0; x < FLAC__BYTES_PER_WORD; x++)
                val[x] = (FLAC__byte)(word >> (8*(FLAC__BYTES_PER_WORD-x-1)));
#endif
            val += FLAC__BYTES_PER_WORD;
            nvals -= FLAC__BYTES_PER_WORD;
        }
        else if(!lib2_bitreader_read_from_client__883B6D88(ctx, br))
            return false;
    }
    /* step 3: read any remainder from partial tail bytes */
    while(nvals) {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x, 8))
            return false;
        *val++ = (FLAC__byte)x;
        nvals--;
    }

    return true;
}

FLAC__bool lib2_FLAC__bitreader_read_unary_unsigned_883B7718(void *ctx, FLAC__BitReader *br, unsigned *val)

{
    unsigned i;

    *val = 0;
    while(1) {
        while(br->consumed_words < br->words) { /* if we've not consumed up to a partial tail word... */
            brword b = br->buffer[br->consumed_words] << br->consumed_bits;
            if(b) {
                i = COUNT_ZERO_MSBS(b);
                *val += i;
                i++;
                br->consumed_bits += i;
                if(br->consumed_bits >= FLAC__BITS_PER_WORD) { /* faster way of testing if(br->consumed_bits == FLAC__BITS_PER_WORD) */
                    lib2_crc16_update_word__883B6CD0(br, br->buffer[br->consumed_words]);
                    br->consumed_words++;
                    br->consumed_bits = 0;
                }
                return true;
            }
            else {
                *val += FLAC__BITS_PER_WORD - br->consumed_bits;
                lib2_crc16_update_word__883B6CD0(br, br->buffer[br->consumed_words]);
                br->consumed_words++;
                br->consumed_bits = 0;
                /* didn't find stop bit yet, have to keep going... */
            }
        }
        /* at this point we've eaten up all the whole words; have to try
         * reading through any tail bytes before calling the read callback.
         * this is a repeat of the above logic adjusted for the fact we
         * don't have a whole word.  note though if the client is feeding
         * us data a byte at a time (unlikely), br->consumed_bits may not
         * be zero.
         */
        if(br->bytes) {
            const unsigned end = br->bytes * 8;
            brword b = (br->buffer[br->consumed_words] & (FLAC__WORD_ALL_ONES << (FLAC__BITS_PER_WORD-end))) << br->consumed_bits;
            if(b) {
                i = COUNT_ZERO_MSBS(b);
                *val += i;
                i++;
                br->consumed_bits += i;
                return true;
            }
            else {
                *val += end - br->consumed_bits;
                br->consumed_bits += end;
                /* didn't find stop bit yet, have to keep going... */
            }
        }
        if(!lib2_bitreader_read_from_client__883B6D88(ctx, br))
            return false;
    }
}

FLAC__bool lib2_FLAC__bitreader_read_rice_signed_block_883B7968(void *ctx, FLAC__BitReader *br, int vals[], unsigned nvals, unsigned parameter)
{
    unsigned i;
    unsigned uval = 0;
    unsigned bits; /* the # of binary LSBs left to read to finish a rice codeword */

    /* try and get br->consumed_words and br->consumed_bits into register;
     * must remember to flush them back to *br before calling other
     * bitwriter functions that use them, and before returning */
    register unsigned cwords;
    register unsigned cbits;
    /* WATCHOUT: code does not work with <32bit words; we can make things much faster with this assertion */
    /* the above two asserts also guarantee that the binary part never straddles more that 2 words, so we don't have to loop to read it */

    if(nvals == 0)
        return true;

    cbits = br->consumed_bits;
    cwords = br->consumed_words;

    while(1) {

        /* read unary part */
        while(1) {
            while(cwords < br->words) { /* if we've not consumed up to a partial tail word... */
                brword b = br->buffer[cwords] << cbits;
                if(b) {
                    i = COUNT_ZERO_MSBS(b);
                    uval += i;
                    bits = parameter;
                    i++;
                    cbits += i;
                    if(cbits == FLAC__BITS_PER_WORD) {
                        lib2_crc16_update_word__883B6CD0(br, br->buffer[cwords]);
                        cwords++;
                        cbits = 0;
                    }
                    goto break1;
                }
                else {
                    uval += FLAC__BITS_PER_WORD - cbits;
                    lib2_crc16_update_word__883B6CD0(br, br->buffer[cwords]);
                    cwords++;
                    cbits = 0;
                    /* didn't find stop bit yet, have to keep going... */
                }
            }
            /* at this point we've eaten up all the whole words; have to try
             * reading through any tail bytes before calling the read callback.
             * this is a repeat of the above logic adjusted for the fact we
             * don't have a whole word.  note though if the client is feeding
             * us data a byte at a time (unlikely), br->consumed_bits may not
             * be zero.
             */
            if(br->bytes) {
                const unsigned end = br->bytes * 8;
                brword b = (br->buffer[cwords] & (FLAC__WORD_ALL_ONES << (FLAC__BITS_PER_WORD-end))) << cbits;
                if(b) {
                    i = COUNT_ZERO_MSBS(b);
                    uval += i;
                    bits = parameter;
                    i++;
                    cbits += i;
                    goto break1;
                }
                else {
                    uval += end - cbits;
                    cbits += end;
                    /* didn't find stop bit yet, have to keep going... */
                }
            }
            /* flush registers and read; bitreader_read_from_client_() does
             * not touch br->consumed_bits at all but we still need to set
             * it in case it fails and we have to return false.
             */
            br->consumed_bits = cbits;
            br->consumed_words = cwords;
            if(!lib2_bitreader_read_from_client__883B6D88(ctx, br))
                return false;
            cwords = br->consumed_words;
        }
break1:
        /* read binary part */

        if(bits) {
            while((br->words-cwords)*FLAC__BITS_PER_WORD + br->bytes*8 - cbits < bits) {
                /* flush registers and read; bitreader_read_from_client_() does
                 * not touch br->consumed_bits at all but we still need to set
                 * it in case it fails and we have to return false.
                 */
                br->consumed_bits = cbits;
                br->consumed_words = cwords;
                if(!lib2_bitreader_read_from_client__883B6D88(ctx, br))
                    return false;
                cwords = br->consumed_words;
            }
            if(cwords < br->words) { /* if we've not consumed up to a partial tail word... */
                if(cbits) {
                    /* this also works when consumed_bits==0, it's just a little slower than necessary for that case */
                    const unsigned n = FLAC__BITS_PER_WORD - cbits;
                    const brword word = br->buffer[cwords];
                    if(bits < n) {
                        uval <<= bits;
                        uval |= (word & (FLAC__WORD_ALL_ONES >> cbits)) >> (n-bits);
                        cbits += bits;
                        goto break2;
                    }
                    uval <<= n;
                    uval |= word & (FLAC__WORD_ALL_ONES >> cbits);
                    bits -= n;
                    lib2_crc16_update_word__883B6CD0(br, word);
                    cwords++;
                    cbits = 0;
                    if(bits) { /* if there are still bits left to read, there have to be less than 32 so they will all be in the next word */
                        uval <<= bits;
                        uval |= (br->buffer[cwords] >> (FLAC__BITS_PER_WORD-bits));
                        cbits = bits;
                    }
                    goto break2;
                }
                else {
                    uval <<= bits;
                    uval |= br->buffer[cwords] >> (FLAC__BITS_PER_WORD-bits);
                    cbits = bits;
                    goto break2;
                }
            }
            else {
                /* in this case we're starting our read at a partial tail word;
                 * the reader has guaranteed that we have at least 'bits' bits
                 * available to read, which makes this case simpler.
                 */
                uval <<= bits;
                if(cbits) {
                    /* this also works when consumed_bits==0, it's just a little slower than necessary for that case */
                    uval |= (br->buffer[cwords] & (FLAC__WORD_ALL_ONES >> cbits)) >> (FLAC__BITS_PER_WORD-cbits-bits);
                    cbits += bits;
                    goto break2;
                }
                else {
                    uval |= br->buffer[cwords] >> (FLAC__BITS_PER_WORD-bits);
                    cbits += bits;
                    goto break2;
                }
            }
        }
break2:
        /* compose the value */
        *vals = (int)(uval >> 1 ^ -(int)(uval & 1));

        /* are we done? */
        --nvals;
        if(nvals == 0) {
            br->consumed_bits = cbits;
            br->consumed_words = cwords;
            return true;
        }

        uval = 0;
        ++vals;

    }
}
FLAC__bool lib2_FLAC__bitreader_read_utf8_uint32_883B7CF0(void *ctx, FLAC__BitReader *br, FLAC__uint32 *val, FLAC__byte *raw, unsigned *rawlen)
{
    FLAC__uint32 v = 0;
    FLAC__uint32 x;
    unsigned i;

    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x, 8))
        return false;
    if(raw)
        raw[(*rawlen)++] = (FLAC__byte)x;
    if(!(x & 0x80)) { /* 0xxxxxxx */
        v = x;
        i = 0;
    }
    else if(x & 0xC0 && !(x & 0x20)) { /* 110xxxxx */
        v = x & 0x1F;
        i = 1;
    }
    else if(x & 0xE0 && !(x & 0x10)) { /* 1110xxxx */
        v = x & 0x0F;
        i = 2;
    }
    else if(x & 0xF0 && !(x & 0x08)) { /* 11110xxx */
        v = x & 0x07;
        i = 3;
    }
    else if(x & 0xF8 && !(x & 0x04)) { /* 111110xx */
        v = x & 0x03;
        i = 4;
    }
    else if(x & 0xFC && !(x & 0x02)) { /* 1111110x */
        v = x & 0x01;
        i = 5;
    }
    else {
        *val = 0xffffffff;
        return true;
    }
    for( ; i; i--) {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x, 8))
            return false;
        if(raw)
            raw[(*rawlen)++] = (FLAC__byte)x;
        if(!(x & 0x80) || (x & 0x40)) { /* 10xxxxxx */
            *val = 0xffffffff;
            return true;
        }
        v <<= 6;
        v |= (x & 0x3F);
    }
    *val = v;
    return true;
}


/* on return, if *val == 0xffffffffffffffff then the utf-8 sequence was invalid, but the return value will be true */
FLAC__bool lib2_FLAC__bitreader_read_utf8_uint64_883B7EA8(void *ctx, FLAC__BitReader *br, FLAC__uint64 *val, FLAC__byte *raw, unsigned *rawlen)
{
    FLAC__uint64 v = 0;
    FLAC__uint32 x;
    unsigned i;

    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x, 8))
        return false;
    if(raw)
        raw[(*rawlen)++] = (FLAC__byte)x;
    if(!(x & 0x80)) { /* 0xxxxxxx */
        v = x;
        i = 0;
    }
    else if(x & 0xC0 && !(x & 0x20)) { /* 110xxxxx */
        v = x & 0x1F;
        i = 1;
    }
    else if(x & 0xE0 && !(x & 0x10)) { /* 1110xxxx */
        v = x & 0x0F;
        i = 2;
    }
    else if(x & 0xF0 && !(x & 0x08)) { /* 11110xxx */
        v = x & 0x07;
        i = 3;
    }
    else if(x & 0xF8 && !(x & 0x04)) { /* 111110xx */
        v = x & 0x03;
        i = 4;
    }
    else if(x & 0xFC && !(x & 0x02)) { /* 1111110x */
        v = x & 0x01;
        i = 5;
    }
    else if(x & 0xFE && !(x & 0x01)) { /* 11111110 */
        v = 0;
        i = 6;
    }
    else {
        *val = FLAC__U64L(0xffffffffffffffff);
        return true;
    }
    for( ; i; i--) {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, br, &x, 8))
            return false;
        if(raw)
            raw[(*rawlen)++] = (FLAC__byte)x;
        if(!(x & 0x80) || (x & 0x40)) { /* 10xxxxxx */
            *val = FLAC__U64L(0xffffffffffffffff);
            return true;
        }
        v <<= 6;
        v |= (x & 0x3F);
    }
    *val = v;
    return true;
}
