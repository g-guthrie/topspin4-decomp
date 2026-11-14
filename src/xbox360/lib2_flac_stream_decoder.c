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
/* Derived from libFLAC 1.2.1 src/libFLAC/stream_decoder.c (BSD license); see THIRD_PARTY_NOTICES.md.
 * FMOD's copy: no Ogg, no FILE helpers, and a leading context argument on the
 * functions that reach the bitreader read callback. */

#include "lib2_flac.h"

#ifdef _MSC_VER
int memcmp(const void *a, const void *b, unsigned int n);
#pragma intrinsic(memcmp)
#else
#include <string.h>
#endif

typedef struct lib2_FILE lib2_FILE;
lib2_FILE *ts4_addr_lbl_88C30DA8_88567BC8(void);                                    /* __iob_func: stdin */
void *fn_8857ACB8(void *dst, const void *src, unsigned int n);   /* memcpy */
void *ts4_memset(void *dst, int c, unsigned int n);
void fn_885651F8(void *p);                                        /* free */
void *ts4_crt_nh_malloc_88565258(unsigned int n);                                /* malloc */
void *fn_88565320(void *p, unsigned int n);                       /* realloc */
void *fn_8856C298(unsigned int n, unsigned int m);                /* calloc */
#define memcpy fn_8857ACB8
#define memset ts4_memset
#define free fn_885651F8
#define malloc ts4_crt_nh_malloc_88565258
#define realloc fn_88565320
#define calloc fn_8856C298
#define stdin ((void *)ts4_addr_lbl_88C30DA8_88567BC8())
#define SIZE_MAX 0xffffffffu
#define max(a,b) ((a)>(b)?(a):(b))
#define FLAC__STREAM_METADATA_SEEKPOINT_LENGTH (18u)

/* libFLAC bitreader / format / md5 / lpc helpers (other units). */
FLAC__bool lib2_FLAC__bitreader_read_raw_uint32_883B70D8(void *ctx, FLAC__BitReader *br, FLAC__uint32 *val, unsigned bits);
FLAC__bool ts4_if_call_seq_fn_883B70D8_883B7328(void *ctx, FLAC__BitReader *br, FLAC__int32 *val, unsigned bits);
FLAC__bool lib2_FLAC__bitreader_read_raw_uint64_883B7380(void *ctx, FLAC__BitReader *br, FLAC__uint64 *val, unsigned bits);
FLAC__bool lib2_FLAC__bitreader_read_uint32_little_endian_883B7420(void *ctx, FLAC__BitReader *br, FLAC__uint32 *val);
FLAC__bool lib2_FLAC__bitreader_skip_byte_block_aligned_no_crc_883B74F0(void *ctx, FLAC__BitReader *br, unsigned nvals);
FLAC__bool lib2_FLAC__bitreader_read_byte_block_aligned_no_crc_883B75E0(void *ctx, FLAC__BitReader *br, FLAC__byte *val, unsigned nvals);
FLAC__bool lib2_FLAC__bitreader_read_unary_unsigned_883B7718(void *ctx, FLAC__BitReader *br, unsigned *val);
FLAC__bool lib2_FLAC__bitreader_read_rice_signed_block_883B7968(void *ctx, FLAC__BitReader *br, int vals[], unsigned nvals, unsigned parameter);
FLAC__bool lib2_FLAC__bitreader_read_utf8_uint32_883B7CF0(void *ctx, FLAC__BitReader *br, FLAC__uint32 *val, FLAC__byte *raw, unsigned *rawlen);
FLAC__bool lib2_FLAC__bitreader_read_utf8_uint64_883B7EA8(void *ctx, FLAC__BitReader *br, FLAC__uint64 *val, FLAC__byte *raw, unsigned *rawlen);
FLAC__bool lib2_FLAC__bitreader_skip_bits_no_crc_883B80F0(void *ctx, FLAC__BitReader *br, unsigned bits);
FLAC__uint16 lib2_FLAC__bitreader_get_read_crc16_883B7000(FLAC__BitReader *br);
void ts4_get_u32_off14_883B6FE8(FLAC__BitReader *br, FLAC__uint16 seed);
FLAC__bool ts4_get_u32_off14_883B7088(const FLAC__BitReader *br);
unsigned ts4_get_u32_off14_883B70A0(const FLAC__BitReader *br);
unsigned ts4_get_u32_off8_883B70B0(const FLAC__BitReader *br);
FLAC__bool ts4_set_u32_offc_883B6FC8(FLAC__BitReader *br);
FLAC__bool lib2_FLAC__bitreader_init_883B6EC0(void *ctx, FLAC__BitReader *br, FLAC__CPUInfo cpu, FLAC__bool (*rcb)(void *ctx, FLAC__byte buffer[], lib2_size_t *bytes, void *client_data), void *cd);
FLAC__BitReader *ts4_tailcall_fn_8856C298_883B6EB0(void);
void ts4_if_call_seq_u32_off0_883B6F68(FLAC__BitReader *br);
void ts4_if_call_seq_u32_off0_883B8088(FLAC__BitReader *br);
void ts4_set_u32_off40_883B8B68(FLAC__MD5Context *ctx);
void lib2_FLAC__MD5Final_883B8BB0(FLAC__byte digest[16], FLAC__MD5Context *ctx);
FLAC__bool lib2_FLAC__MD5Accumulate_883B8FD0(FLAC__MD5Context *ctx, const FLAC__int32 * const signal[], unsigned channels, unsigned samples, unsigned bytes_per_sample);
void ts4_set_u32_off0_883B6BD8(FLAC__EntropyCodingMethod_PartitionedRiceContents *object);
void ts4_if_call_seq_u32_off0_883B6BF0(FLAC__EntropyCodingMethod_PartitionedRiceContents *object);
FLAC__bool ts4_if_call_seq_u32_off8_883B6C48(FLAC__EntropyCodingMethod_PartitionedRiceContents *object, unsigned max_partition_order);
FLAC__bool ts4_if_call_seq_fn_88565258_883B9150(unsigned elements, FLAC__int32 **unaligned_pointer, FLAC__int32 **aligned_pointer);
void ts4_set_u32_off4_883BA9D0(FLAC__CPUInfo *info);
FLAC__uint8 ts4_table_chain_checksum_883BA9E8(const FLAC__byte *data, unsigned len);
void lib2_FLAC__fixed_restore_signal_883BAA20(const FLAC__int32 residual[], unsigned data_len, unsigned order, FLAC__int32 data[]);
void lib2_FLAC__lpc_restore_signal_883B91C8(const FLAC__int32 residual[], unsigned data_len, const FLAC__int32 qlp_coeff[], unsigned order, int lp_quantization, FLAC__int32 data[]);
void lib2_FLAC__lpc_restore_signal_wide_883B9BD0(const FLAC__int32 residual[], unsigned data_len, const FLAC__int32 qlp_coeff[], unsigned order, int lp_quantization, FLAC__int32 data[]);

extern FLAC__byte lbl_88B3AF40[3];   /* ID3V2_TAG_ */
#define ID3V2_TAG_ lbl_88B3AF40

static void *safe_malloc_(lib2_size_t size)
{
    if (!size)
        size++;
    return malloc(size);
}

static void *safe_malloc_add_2op_(lib2_size_t size1, lib2_size_t size2)
{
    size2 += size1;
    if (size2 < size1)
        return 0;
    return safe_malloc_(size2);
}

static void *safe_malloc_mul_2op_(lib2_size_t size1, lib2_size_t size2)
{
    if (!size1 || !size2)
        return malloc(1);
    if (size1 > SIZE_MAX / size2)
        return 0;
    return malloc(size1 * size2);
}

static void *safe_malloc_muladd2_(lib2_size_t size1, lib2_size_t size2, lib2_size_t size3)
{
    if (!size1 || (!size2 && !size3))
        return malloc(1);
    size2 += size3;
    if (size2 < size3)
        return 0;
    return safe_malloc_mul_2op_(size1, size2);
}

static void *safe_realloc_mul_2op_(void *ptr, lib2_size_t size1, lib2_size_t size2)
{
    if (!size1 || !size2)
        return realloc(ptr, 0);
    if (size1 > SIZE_MAX / size2)
        return 0;
    return realloc(ptr, size1 * size2);
}

static void *safe_calloc_(lib2_size_t nmemb, lib2_size_t size)
{
    if (!nmemb || !size)
        return malloc(1);
    return calloc(nmemb, size);
}

unsigned ts4_loop_fn_883BAB60(FLAC__uint32 v);                  /* FLAC__bitmath_ilog2 */
#define FLAC__bitmath_ilog2 ts4_loop_fn_883BAB60

int fn_88566FE8(void *f);                                       /* fclose */
extern unsigned lbl_88B3B008[256];                              /* FLAC__crc16_table */
#define FLAC__CRC16_UPDATE(data, crc) (((((crc)<<8) & 0xffff) ^ lbl_88B3B008[((crc)>>8) ^ (data)]))

FLAC__bool fn_883A4C20(void *ctx, FLAC__byte buffer[], lib2_size_t *bytes, void *client_data); /* read_callback_ (FMOD) */

typedef double FLAC__double;
#define FLAC__STREAM_METADATA_SEEKPOINT_PLACEHOLDER (~(FLAC__uint64)0)

/* Keep MSVC from inlining a callee that the original build kept out of line. */
#ifdef _MSC_VER
#define LIB2_NOINLINE __declspec(noinline)
#else
#define LIB2_NOINLINE
#endif

/* libFLAC format.c bit-length constants (FLAC__*), referenced by address. */
extern const FLAC__byte lbl_88035750[4];
#define FLAC__STREAM_SYNC_STRING lbl_88035750
extern const unsigned lbl_8803575C;
#define FLAC__STREAM_METADATA_STREAMINFO_MIN_BLOCK_SIZE_LEN lbl_8803575C
extern const unsigned lbl_88035760;
#define FLAC__STREAM_METADATA_STREAMINFO_MAX_BLOCK_SIZE_LEN lbl_88035760
extern const unsigned lbl_88035764;
#define FLAC__STREAM_METADATA_STREAMINFO_MIN_FRAME_SIZE_LEN lbl_88035764
extern const unsigned lbl_88035768;
#define FLAC__STREAM_METADATA_STREAMINFO_MAX_FRAME_SIZE_LEN lbl_88035768
extern const unsigned lbl_8803576C;
#define FLAC__STREAM_METADATA_STREAMINFO_SAMPLE_RATE_LEN lbl_8803576C
extern const unsigned lbl_88035770;
#define FLAC__STREAM_METADATA_STREAMINFO_CHANNELS_LEN lbl_88035770
extern const unsigned lbl_88035774;
#define FLAC__STREAM_METADATA_STREAMINFO_BITS_PER_SAMPLE_LEN lbl_88035774
extern const unsigned lbl_88035778;
#define FLAC__STREAM_METADATA_STREAMINFO_TOTAL_SAMPLES_LEN lbl_88035778
extern const unsigned lbl_88035780;
#define FLAC__STREAM_METADATA_APPLICATION_ID_LEN lbl_88035780
extern const unsigned lbl_88035784;
#define FLAC__STREAM_METADATA_SEEKPOINT_SAMPLE_NUMBER_LEN lbl_88035784
extern const unsigned lbl_88035788;
#define FLAC__STREAM_METADATA_SEEKPOINT_STREAM_OFFSET_LEN lbl_88035788
extern const unsigned lbl_8803578C;
#define FLAC__STREAM_METADATA_SEEKPOINT_FRAME_SAMPLES_LEN lbl_8803578C
extern const unsigned lbl_880357A0;
#define FLAC__STREAM_METADATA_CUESHEET_INDEX_OFFSET_LEN lbl_880357A0
extern const unsigned lbl_880357A4;
#define FLAC__STREAM_METADATA_CUESHEET_INDEX_NUMBER_LEN lbl_880357A4
extern const unsigned lbl_880357A8;
#define FLAC__STREAM_METADATA_CUESHEET_INDEX_RESERVED_LEN lbl_880357A8
extern const unsigned lbl_880357AC;
#define FLAC__STREAM_METADATA_CUESHEET_TRACK_OFFSET_LEN lbl_880357AC
extern const unsigned lbl_880357B0;
#define FLAC__STREAM_METADATA_CUESHEET_TRACK_NUMBER_LEN lbl_880357B0
extern const unsigned lbl_880357B4;
#define FLAC__STREAM_METADATA_CUESHEET_TRACK_ISRC_LEN lbl_880357B4
extern const unsigned lbl_880357B8;
#define FLAC__STREAM_METADATA_CUESHEET_TRACK_TYPE_LEN lbl_880357B8
extern const unsigned lbl_880357BC;
#define FLAC__STREAM_METADATA_CUESHEET_TRACK_PRE_EMPHASIS_LEN lbl_880357BC
extern const unsigned lbl_880357C0;
#define FLAC__STREAM_METADATA_CUESHEET_TRACK_RESERVED_LEN lbl_880357C0
extern const unsigned lbl_880357C4;
#define FLAC__STREAM_METADATA_CUESHEET_TRACK_NUM_INDICES_LEN lbl_880357C4
extern const unsigned lbl_880357C8;
#define FLAC__STREAM_METADATA_CUESHEET_MEDIA_CATALOG_NUMBER_LEN lbl_880357C8
extern const unsigned lbl_880357CC;
#define FLAC__STREAM_METADATA_CUESHEET_LEAD_IN_LEN lbl_880357CC
extern const unsigned lbl_880357D0;
#define FLAC__STREAM_METADATA_CUESHEET_IS_CD_LEN lbl_880357D0
extern const unsigned lbl_880357D4;
#define FLAC__STREAM_METADATA_CUESHEET_RESERVED_LEN lbl_880357D4
extern const unsigned lbl_880357D8;
#define FLAC__STREAM_METADATA_CUESHEET_NUM_TRACKS_LEN lbl_880357D8
extern const unsigned lbl_880357DC;
#define FLAC__STREAM_METADATA_PICTURE_TYPE_LEN lbl_880357DC
extern const unsigned lbl_880357E0;
#define FLAC__STREAM_METADATA_PICTURE_MIME_TYPE_LENGTH_LEN lbl_880357E0
extern const unsigned lbl_880357E4;
#define FLAC__STREAM_METADATA_PICTURE_DESCRIPTION_LENGTH_LEN lbl_880357E4
extern const unsigned lbl_880357E8;
#define FLAC__STREAM_METADATA_PICTURE_WIDTH_LEN lbl_880357E8
extern const unsigned lbl_880357EC;
#define FLAC__STREAM_METADATA_PICTURE_HEIGHT_LEN lbl_880357EC
extern const unsigned lbl_880357F0;
#define FLAC__STREAM_METADATA_PICTURE_DEPTH_LEN lbl_880357F0
extern const unsigned lbl_880357F4;
#define FLAC__STREAM_METADATA_PICTURE_COLORS_LEN lbl_880357F4
extern const unsigned lbl_880357F8;
#define FLAC__STREAM_METADATA_PICTURE_DATA_LENGTH_LEN lbl_880357F8
extern const unsigned lbl_880357FC;
#define FLAC__STREAM_METADATA_IS_LAST_LEN lbl_880357FC
extern const unsigned lbl_88035800;
#define FLAC__STREAM_METADATA_TYPE_LEN lbl_88035800
extern const unsigned lbl_88035804;
#define FLAC__STREAM_METADATA_LENGTH_LEN lbl_88035804
extern const unsigned lbl_88035830;
#define FLAC__FRAME_FOOTER_CRC_LEN lbl_88035830
extern const unsigned lbl_88035834;
#define FLAC__ENTROPY_CODING_METHOD_TYPE_LEN lbl_88035834
extern const unsigned lbl_88035838;
#define FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE_ORDER_LEN lbl_88035838
extern const unsigned lbl_8803583C;
#define FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE_PARAMETER_LEN lbl_8803583C
extern const unsigned lbl_88035840;
#define FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE2_PARAMETER_LEN lbl_88035840
extern const unsigned lbl_88035844;
#define FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE_RAW_LEN lbl_88035844
extern const unsigned lbl_88035848;
#define FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE_ESCAPE_PARAMETER lbl_88035848
extern const unsigned lbl_8803584C;
#define FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE2_ESCAPE_PARAMETER lbl_8803584C
extern const unsigned lbl_88035858;
#define FLAC__SUBFRAME_LPC_QLP_COEFF_PRECISION_LEN lbl_88035858
extern const unsigned lbl_8803585C;
#define FLAC__SUBFRAME_LPC_QLP_SHIFT_LEN lbl_8803585C

FLAC__bool fn_883A5780(void *ctx, FLAC__StreamDecoder *decoder); /* not yet matched; draft in work/lib2_drafts */
FLAC__bool fn_883A6748(void *ctx, FLAC__StreamDecoder *decoder, unsigned predictor_order, unsigned partition_order, FLAC__EntropyCodingMethod_PartitionedRiceContents *partitioned_rice_contents, FLAC__int32 *residual, FLAC__bool is_extended); /* not yet matched; draft in work/lib2_drafts */
FLAC__bool fn_883A79D8(void *ctx, FLAC__StreamDecoder *decoder, FLAC__uint64 stream_length, FLAC__uint64 target_sample); /* not yet matched; draft in work/lib2_drafts */
FLAC__bool lib2_FLAC__stream_decoder_reset_883A3C70(FLAC__StreamDecoder *decoder);
void lib2_set_defaults__883A3DB8(FLAC__StreamDecoder *decoder);
FLAC__bool lib2_allocate_output__883A3E68(FLAC__StreamDecoder *decoder, unsigned size, unsigned channels);
FLAC__bool lib2_read_metadata_streaminfo__883A3FD8(void *ctx, FLAC__StreamDecoder *decoder, FLAC__bool is_last, unsigned length);
FLAC__bool lib2_read_metadata_seektable__883A4220(void *ctx, FLAC__StreamDecoder *decoder, FLAC__bool is_last, unsigned length);
FLAC__bool lib2_read_metadata_vorbiscomment__883A43F0(void *ctx, FLAC__StreamDecoder *decoder, FLAC__StreamMetadata_VorbisComment *obj);
FLAC__bool lib2_read_metadata_cuesheet__883A4608(void *ctx, FLAC__StreamDecoder *decoder, FLAC__StreamMetadata_CueSheet *obj);
FLAC__bool lib2_read_metadata_picture__883A4988(void *ctx, FLAC__StreamDecoder *decoder, FLAC__StreamMetadata_Picture *obj);
FLAC__StreamDecoderWriteStatus lib2_write_audio_frame_to_client__883A4D58(FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[]);
FLAC__StreamDecoder *lib2_FLAC__stream_decoder_new_883A4EB8(void);
FLAC__StreamDecoderInitStatus lib2_init_stream_internal__883A50C0(void *ctx, 
    FLAC__StreamDecoder *decoder,
    FLAC__StreamDecoderReadCallback read_callback,
    FLAC__StreamDecoderSeekCallback seek_callback,
    FLAC__StreamDecoderTellCallback tell_callback,
    FLAC__StreamDecoderLengthCallback length_callback,
    FLAC__StreamDecoderEofCallback eof_callback,
    FLAC__StreamDecoderWriteCallback write_callback,
    FLAC__StreamDecoderMetadataCallback metadata_callback,
    FLAC__StreamDecoderErrorCallback error_callback,
    void *client_data,
    FLAC__bool is_ogg
);
FLAC__StreamDecoderInitStatus lib2_FLAC__stream_decoder_init_stream_883A52E8(void *ctx, 
    FLAC__StreamDecoder *decoder,
    FLAC__StreamDecoderReadCallback read_callback,
    FLAC__StreamDecoderSeekCallback seek_callback,
    FLAC__StreamDecoderTellCallback tell_callback,
    FLAC__StreamDecoderLengthCallback length_callback,
    FLAC__StreamDecoderEofCallback eof_callback,
    FLAC__StreamDecoderWriteCallback write_callback,
    FLAC__StreamDecoderMetadataCallback metadata_callback,
    FLAC__StreamDecoderErrorCallback error_callback,
    void *client_data
);
FLAC__bool lib2_FLAC__stream_decoder_finish_883A5320(void *ctx, FLAC__StreamDecoder *decoder);
FLAC__bool lib2_FLAC__stream_decoder_get_decode_position_883A54C0(void *ctx, const FLAC__StreamDecoder *decoder, FLAC__uint64 *position);
FLAC__bool lib2_find_metadata__883A5568(void *ctx, FLAC__StreamDecoder *decoder);
FLAC__bool lib2_frame_sync__883A5D30(void *ctx, FLAC__StreamDecoder *decoder);
FLAC__bool lib2_read_frame_header__883A5ED8(void *ctx, FLAC__StreamDecoder *decoder);
FLAC__bool lib2_FLAC__stream_decoder_process_until_end_of_metadata_883A6A40(void *ctx, FLAC__StreamDecoder *decoder);
FLAC__bool lib2_read_subframe_fixed__883A6AE8(void *ctx, FLAC__StreamDecoder *decoder, unsigned channel, unsigned bps, const unsigned order, FLAC__bool do_full_decode);
FLAC__bool lib2_read_subframe_lpc__883A6D00(void *ctx, FLAC__StreamDecoder *decoder, unsigned channel, unsigned bps, const unsigned order, FLAC__bool do_full_decode);
FLAC__bool lib2_read_subframe__883A70C0(void *ctx, FLAC__StreamDecoder *decoder, unsigned channel, unsigned bps, FLAC__bool do_full_decode);
FLAC__bool lib2_read_frame__883A7468(void *ctx, FLAC__StreamDecoder *decoder, FLAC__bool *got_a_frame, FLAC__bool do_full_decode);
FLAC__bool lib2_FLAC__stream_decoder_process_single_883A78E8(void *ctx, FLAC__StreamDecoder *decoder);
FLAC__bool lib2_FLAC__stream_decoder_seek_absolute_883A7EC8(void *ctx, FLAC__StreamDecoder *decoder, FLAC__uint64 sample);

static FLAC__uint64 FLAC__stream_decoder_get_total_samples(const FLAC__StreamDecoder *decoder)
{
    return decoder->private_->has_stream_info? decoder->private_->stream_info.data.stream_info.total_samples : 0;
}

static FLAC__bool FLAC__stream_decoder_flush(FLAC__StreamDecoder *decoder)
{

    decoder->private_->samples_decoded = 0;
    decoder->private_->do_md5_checking = false;

#if FLAC__HAS_OGG
    if(decoder->private_->is_ogg)
        FLAC__ogg_decoder_aspect_flush(&decoder->protected_->ogg_decoder_aspect);
#endif

    if(!ts4_set_u32_offc_883B6FC8(decoder->private_->input)) {
        decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
        return false;
    }
    decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;

    return true;
}

static void send_error_to_client_(const FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status)
{
    if(!decoder->private_->is_seeking)
        decoder->private_->error_callback(decoder, status, decoder->private_->client_data);
    else if(status == FLAC__STREAM_DECODER_ERROR_STATUS_UNPARSEABLE_STREAM)
        decoder->private_->unparseable_frame_count++;
}

static FLAC__bool skip_id3v2_tag_(void *ctx, FLAC__StreamDecoder *decoder)
{
    FLAC__uint32 x;
    unsigned i, skip;

    /* skip the version and flags bytes */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 24))
        return false; /* read_callback_ sets the state for us */
    /* get the size (in bytes) to skip */
    skip = 0;
    for(i = 0; i < 4; i++) {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 8))
            return false; /* read_callback_ sets the state for us */
        skip <<= 7;
        skip |= (x & 0x7f);
    }
    /* skip the rest of the tag */
    if(!lib2_FLAC__bitreader_skip_byte_block_aligned_no_crc_883B74F0(ctx, decoder->private_->input, skip))
        return false; /* read_callback_ sets the state for us */
    return true;
}

static FLAC__bool read_subframe_constant_(void *ctx, FLAC__StreamDecoder *decoder, unsigned channel, unsigned bps, FLAC__bool do_full_decode)
{
    FLAC__Subframe_Constant *subframe = &decoder->private_->frame.subframes[channel].data.constant;
    FLAC__int32 x;
    unsigned i;
    FLAC__int32 *output = decoder->private_->output[channel];

    decoder->private_->frame.subframes[channel].type = FLAC__SUBFRAME_TYPE_CONSTANT;

    if(!ts4_if_call_seq_fn_883B70D8_883B7328(ctx, decoder->private_->input, &x, bps))
        return false; /* read_callback_ sets the state for us */

    subframe->value = x;

    /* decode the subframe */
    if(do_full_decode) {
        for(i = 0; i < decoder->private_->frame.header.blocksize; i++)
            output[i] = x;
    }

    return true;
}

static FLAC__bool read_subframe_verbatim_(void *ctx, FLAC__StreamDecoder *decoder, unsigned channel, unsigned bps, FLAC__bool do_full_decode)
{
    FLAC__Subframe_Verbatim *subframe = &decoder->private_->frame.subframes[channel].data.verbatim;
    FLAC__int32 x, *residual = decoder->private_->residual[channel];
    unsigned i;

    decoder->private_->frame.subframes[channel].type = FLAC__SUBFRAME_TYPE_VERBATIM;

    subframe->data = residual;

    for(i = 0; i < decoder->private_->frame.header.blocksize; i++) {
        if(!ts4_if_call_seq_fn_883B70D8_883B7328(ctx, decoder->private_->input, &x, bps))
            return false; /* read_callback_ sets the state for us */
        residual[i] = x;
    }

    /* decode the subframe */
    if(do_full_decode)
        memcpy(decoder->private_->output[channel], subframe->data, sizeof(FLAC__int32) * decoder->private_->frame.header.blocksize);

    return true;
}

static FLAC__bool read_zero_padding_(void *ctx, FLAC__StreamDecoder *decoder)
{
    if(!ts4_get_u32_off14_883B7088(decoder->private_->input)) {
        FLAC__uint32 zero = 0;
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &zero, ts4_get_u32_off14_883B70A0(decoder->private_->input)))
            return false; /* read_callback_ sets the state for us */
        if(zero != 0) {
            send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_LOST_SYNC);
            decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
        }
    }
    return true;
}

static unsigned FLAC__stream_decoder_get_input_bytes_unconsumed(const FLAC__StreamDecoder *decoder)
{
    return ts4_get_u32_off8_883B70B0(decoder->private_->input) / 8;
}

FLAC__bool lib2_FLAC__stream_decoder_reset_883A3C70(FLAC__StreamDecoder *decoder)
{

    if(!FLAC__stream_decoder_flush(decoder)) {
        /* above call sets the state for us */
        return false;
    }

#if FLAC__HAS_OGG
    /*@@@ could go in !internal_reset_hack block below */
    if(decoder->private_->is_ogg)
        FLAC__ogg_decoder_aspect_reset(&decoder->protected_->ogg_decoder_aspect);
#endif

    /* Rewind if necessary.  If FLAC__stream_decoder_init() is calling us,
     * (internal_reset_hack) don't try to rewind since we are already at
     * the beginning of the stream and don't want to fail if the input is
     * not seekable.
     */
    if(!decoder->private_->internal_reset_hack) {
        if(decoder->private_->file == stdin)
            return false; /* can't rewind stdin, reset fails */
        if(decoder->private_->seek_callback && decoder->private_->seek_callback(decoder, 0, decoder->private_->client_data) == FLAC__STREAM_DECODER_SEEK_STATUS_ERROR)
            return false; /* seekable and seek fails, reset fails */
    }
    else
        decoder->private_->internal_reset_hack = false;

    decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_METADATA;

    decoder->private_->has_stream_info = false;
    if(decoder->private_->has_seek_table && 0 != decoder->private_->seek_table.data.seek_table.points) {
        free(decoder->private_->seek_table.data.seek_table.points);
        decoder->private_->seek_table.data.seek_table.points = 0;
        decoder->private_->has_seek_table = false;
    }
    decoder->private_->do_md5_checking = decoder->protected_->md5_checking;
    /*
     * This goes in reset() and not flush() because according to the spec, a
     * fixed-blocksize stream must stay that way through the whole stream.
     */
    decoder->private_->fixed_block_size = decoder->private_->next_fixed_block_size = 0;

    /* We initialize the FLAC__MD5Context even though we may never use it.  This
     * is because md5 checking may be turned on to start and then turned off if
     * a seek occurs.  So we init the context here and finalize it in
     * lib2_FLAC__stream_decoder_finish_883A5320() to make sure things are always cleaned up
     * properly.
     */
    ts4_set_u32_off40_883B8B68(&decoder->private_->md5context);

    decoder->private_->first_frame_offset = 0;
    decoder->private_->unparseable_frame_count = 0;

    return true;
}

void lib2_set_defaults__883A3DB8(FLAC__StreamDecoder *decoder)
{
#if FLAC__HAS_OGG
    decoder->private_->is_ogg = false;
#endif
    decoder->private_->read_callback = 0;
    decoder->private_->seek_callback = 0;
    decoder->private_->tell_callback = 0;
    decoder->private_->length_callback = 0;
    decoder->private_->eof_callback = 0;
    decoder->private_->write_callback = 0;
    decoder->private_->metadata_callback = 0;
    decoder->private_->error_callback = 0;
    decoder->private_->client_data = 0;

    memset(decoder->private_->metadata_filter, 0, sizeof(decoder->private_->metadata_filter));
    decoder->private_->metadata_filter[FLAC__METADATA_TYPE_STREAMINFO] = true;
    decoder->private_->metadata_filter_ids_count = 0;

    decoder->protected_->md5_checking = false;

#if FLAC__HAS_OGG
    FLAC__ogg_decoder_aspect_set_defaults(&decoder->protected_->ogg_decoder_aspect);
#endif
}

FLAC__bool lib2_allocate_output__883A3E68(FLAC__StreamDecoder *decoder, unsigned size, unsigned channels)
{
    unsigned i;
    FLAC__int32 *tmp;

    if(size <= decoder->private_->output_capacity && channels <= decoder->private_->output_channels)
        return true;

    /* simply using realloc() is not practical because the number of channels may change mid-stream */

    for(i = 0; i < FLAC__MAX_CHANNELS; i++) {
        if(0 != decoder->private_->output[i]) {
            free(decoder->private_->output[i]-4);
            decoder->private_->output[i] = 0;
        }
        if(0 != decoder->private_->residual_unaligned[i]) {
            free(decoder->private_->residual_unaligned[i]);
            decoder->private_->residual_unaligned[i] = decoder->private_->residual[i] = 0;
        }
    }

    for(i = 0; i < channels; i++) {
        /* WATCHOUT:
         * FLAC__lpc_restore_signal_asm_ia32_mmx() requires that the
         * output arrays have a buffer of up to 3 zeroes in front
         * (at negative indices) for alignment purposes; we use 4
         * to keep the data well-aligned.
         */
        tmp = (FLAC__int32*)safe_malloc_muladd2_(sizeof(FLAC__int32), /*times (*/size, /*+*/4/*)*/);
        if(tmp == 0) {
            decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
            return false;
        }
        memset(tmp, 0, sizeof(FLAC__int32)*4);
        decoder->private_->output[i] = tmp + 4;

        /* WATCHOUT:
         * minimum of quadword alignment for PPC vector optimizations is REQUIRED:
         */
        if(!ts4_if_call_seq_fn_88565258_883B9150(size, &decoder->private_->residual_unaligned[i], &decoder->private_->residual[i])) {
            decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
            return false;
        }
    }

    decoder->private_->output_capacity = size;
    decoder->private_->output_channels = channels;

    return true;
}

FLAC__bool lib2_read_metadata_streaminfo__883A3FD8(void *ctx, FLAC__StreamDecoder *decoder, FLAC__bool is_last, unsigned length)
{
    FLAC__uint32 x;
    unsigned bits, used_bits = 0;


    decoder->private_->stream_info.type = FLAC__METADATA_TYPE_STREAMINFO;
    decoder->private_->stream_info.is_last = is_last;
    decoder->private_->stream_info.length = length;

    bits = FLAC__STREAM_METADATA_STREAMINFO_MIN_BLOCK_SIZE_LEN;
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, bits))
        return false; /* read_callback_ sets the state for us */
    decoder->private_->stream_info.data.stream_info.min_blocksize = x;
    used_bits += bits;

    bits = FLAC__STREAM_METADATA_STREAMINFO_MAX_BLOCK_SIZE_LEN;
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_STREAMINFO_MAX_BLOCK_SIZE_LEN))
        return false; /* read_callback_ sets the state for us */
    decoder->private_->stream_info.data.stream_info.max_blocksize = x;
    used_bits += bits;

    bits = FLAC__STREAM_METADATA_STREAMINFO_MIN_FRAME_SIZE_LEN;
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_STREAMINFO_MIN_FRAME_SIZE_LEN))
        return false; /* read_callback_ sets the state for us */
    decoder->private_->stream_info.data.stream_info.min_framesize = x;
    used_bits += bits;

    bits = FLAC__STREAM_METADATA_STREAMINFO_MAX_FRAME_SIZE_LEN;
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_STREAMINFO_MAX_FRAME_SIZE_LEN))
        return false; /* read_callback_ sets the state for us */
    decoder->private_->stream_info.data.stream_info.max_framesize = x;
    used_bits += bits;

    bits = FLAC__STREAM_METADATA_STREAMINFO_SAMPLE_RATE_LEN;
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_STREAMINFO_SAMPLE_RATE_LEN))
        return false; /* read_callback_ sets the state for us */
    decoder->private_->stream_info.data.stream_info.sample_rate = x;
    used_bits += bits;

    bits = FLAC__STREAM_METADATA_STREAMINFO_CHANNELS_LEN;
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_STREAMINFO_CHANNELS_LEN))
        return false; /* read_callback_ sets the state for us */
    decoder->private_->stream_info.data.stream_info.channels = x+1;
    used_bits += bits;

    bits = FLAC__STREAM_METADATA_STREAMINFO_BITS_PER_SAMPLE_LEN;
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_STREAMINFO_BITS_PER_SAMPLE_LEN))
        return false; /* read_callback_ sets the state for us */
    decoder->private_->stream_info.data.stream_info.bits_per_sample = x+1;
    used_bits += bits;

    bits = FLAC__STREAM_METADATA_STREAMINFO_TOTAL_SAMPLES_LEN;
    if(!lib2_FLAC__bitreader_read_raw_uint64_883B7380(ctx, decoder->private_->input, &decoder->private_->stream_info.data.stream_info.total_samples, FLAC__STREAM_METADATA_STREAMINFO_TOTAL_SAMPLES_LEN))
        return false; /* read_callback_ sets the state for us */
    used_bits += bits;

    if(!lib2_FLAC__bitreader_read_byte_block_aligned_no_crc_883B75E0(ctx, decoder->private_->input, decoder->private_->stream_info.data.stream_info.md5sum, 16))
        return false; /* read_callback_ sets the state for us */
    used_bits += 16*8;

    /* skip the rest of the block */
    length -= (used_bits / 8);
    if(!lib2_FLAC__bitreader_skip_byte_block_aligned_no_crc_883B74F0(ctx, decoder->private_->input, length))
        return false; /* read_callback_ sets the state for us */

    return true;
}

FLAC__bool lib2_read_metadata_seektable__883A4220(void *ctx, FLAC__StreamDecoder *decoder, FLAC__bool is_last, unsigned length)
{
    FLAC__uint32 i, x;
    FLAC__uint64 xx;


    decoder->private_->seek_table.type = FLAC__METADATA_TYPE_SEEKTABLE;
    decoder->private_->seek_table.is_last = is_last;
    decoder->private_->seek_table.length = length;

    decoder->private_->seek_table.data.seek_table.num_points = length / FLAC__STREAM_METADATA_SEEKPOINT_LENGTH;

    /* use realloc since we may pass through here several times (e.g. after seeking) */
    decoder->private_->seek_table.data.seek_table.points = (FLAC__StreamMetadata_SeekPoint*)safe_realloc_mul_2op_(decoder->private_->seek_table.data.seek_table.points, decoder->private_->seek_table.data.seek_table.num_points, /*times*/sizeof(FLAC__StreamMetadata_SeekPoint));
    if(0 == decoder->private_->seek_table.data.seek_table.points) {
        decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
        return false;
    }
    for(i = 0; i < decoder->private_->seek_table.data.seek_table.num_points; i++) {
        if(!lib2_FLAC__bitreader_read_raw_uint64_883B7380(ctx, decoder->private_->input, &xx, FLAC__STREAM_METADATA_SEEKPOINT_SAMPLE_NUMBER_LEN))
            return false; /* read_callback_ sets the state for us */
        decoder->private_->seek_table.data.seek_table.points[i].sample_number = xx;

        if(!lib2_FLAC__bitreader_read_raw_uint64_883B7380(ctx, decoder->private_->input, &xx, FLAC__STREAM_METADATA_SEEKPOINT_STREAM_OFFSET_LEN))
            return false; /* read_callback_ sets the state for us */
        decoder->private_->seek_table.data.seek_table.points[i].stream_offset = xx;

        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_SEEKPOINT_FRAME_SAMPLES_LEN))
            return false; /* read_callback_ sets the state for us */
        decoder->private_->seek_table.data.seek_table.points[i].frame_samples = x;
    }
    length -= (decoder->private_->seek_table.data.seek_table.num_points * FLAC__STREAM_METADATA_SEEKPOINT_LENGTH);
    /* if there is a partial point left, skip over it */
    if(length > 0) {
        /*@@@ do a send_error_to_client_() here?  there's an argument for either way */
        if(!lib2_FLAC__bitreader_skip_byte_block_aligned_no_crc_883B74F0(ctx, decoder->private_->input, length))
            return false; /* read_callback_ sets the state for us */
    }

    return true;
}

FLAC__bool lib2_read_metadata_vorbiscomment__883A43F0(void *ctx, FLAC__StreamDecoder *decoder, FLAC__StreamMetadata_VorbisComment *obj)
{
    FLAC__uint32 i;


    /* read vendor string */
    if(!lib2_FLAC__bitreader_read_uint32_little_endian_883B7420(ctx, decoder->private_->input, &obj->vendor_string.length))
        return false; /* read_callback_ sets the state for us */
    if(obj->vendor_string.length > 0) {
        if(0 == (obj->vendor_string.entry = (FLAC__byte*)safe_malloc_add_2op_(obj->vendor_string.length, /*+*/1))) {
            decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
            return false;
        }
        if(!lib2_FLAC__bitreader_read_byte_block_aligned_no_crc_883B75E0(ctx, decoder->private_->input, obj->vendor_string.entry, obj->vendor_string.length))
            return false; /* read_callback_ sets the state for us */
        obj->vendor_string.entry[obj->vendor_string.length] = '\0';
    }
    else
        obj->vendor_string.entry = 0;

    /* read num comments */
    if(!lib2_FLAC__bitreader_read_uint32_little_endian_883B7420(ctx, decoder->private_->input, &obj->num_comments))
        return false; /* read_callback_ sets the state for us */

    /* read comments */
    if(obj->num_comments > 0) {
        if(0 == (obj->comments = (FLAC__StreamMetadata_VorbisComment_Entry*)safe_malloc_mul_2op_(obj->num_comments, /*times*/sizeof(FLAC__StreamMetadata_VorbisComment_Entry)))) {
            decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
            return false;
        }
        for(i = 0; i < obj->num_comments; i++) {
            if(!lib2_FLAC__bitreader_read_uint32_little_endian_883B7420(ctx, decoder->private_->input, &obj->comments[i].length))
                return false; /* read_callback_ sets the state for us */
            if(obj->comments[i].length > 0) {
                obj->comments[i].entry = (FLAC__byte*)safe_malloc_add_2op_(obj->comments[i].length, /*+*/1);
                if(0 == obj->comments[i].entry) {
                    decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
                    return false;
                }
                if(!lib2_FLAC__bitreader_read_byte_block_aligned_no_crc_883B75E0(ctx, decoder->private_->input, obj->comments[i].entry, obj->comments[i].length))
                    return false; /* read_callback_ sets the state for us */
                obj->comments[i].entry[obj->comments[i].length] = '\0';
            }
            else
                obj->comments[i].entry = 0;
        }
    }
    else {
        obj->comments = 0;
    }

    return true;
}

FLAC__bool lib2_read_metadata_cuesheet__883A4608(void *ctx, FLAC__StreamDecoder *decoder, FLAC__StreamMetadata_CueSheet *obj)
{
    FLAC__uint32 i, j, x;


    memset(obj, 0, sizeof(FLAC__StreamMetadata_CueSheet));

    if(!lib2_FLAC__bitreader_read_byte_block_aligned_no_crc_883B75E0(ctx, decoder->private_->input, (FLAC__byte*)obj->media_catalog_number, FLAC__STREAM_METADATA_CUESHEET_MEDIA_CATALOG_NUMBER_LEN/8))
        return false; /* read_callback_ sets the state for us */

    if(!lib2_FLAC__bitreader_read_raw_uint64_883B7380(ctx, decoder->private_->input, &obj->lead_in, FLAC__STREAM_METADATA_CUESHEET_LEAD_IN_LEN))
        return false; /* read_callback_ sets the state for us */

    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_CUESHEET_IS_CD_LEN))
        return false; /* read_callback_ sets the state for us */
    obj->is_cd = x? true : false;

    if(!lib2_FLAC__bitreader_skip_bits_no_crc_883B80F0(ctx, decoder->private_->input, FLAC__STREAM_METADATA_CUESHEET_RESERVED_LEN))
        return false; /* read_callback_ sets the state for us */

    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_CUESHEET_NUM_TRACKS_LEN))
        return false; /* read_callback_ sets the state for us */
    obj->num_tracks = x;

    if(obj->num_tracks > 0) {
        if(0 == (obj->tracks = (FLAC__StreamMetadata_CueSheet_Track*)safe_calloc_(obj->num_tracks, sizeof(FLAC__StreamMetadata_CueSheet_Track)))) {
            decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
            return false;
        }
        for(i = 0; i < obj->num_tracks; i++) {
            FLAC__StreamMetadata_CueSheet_Track *track = &obj->tracks[i];
            if(!lib2_FLAC__bitreader_read_raw_uint64_883B7380(ctx, decoder->private_->input, &track->offset, FLAC__STREAM_METADATA_CUESHEET_TRACK_OFFSET_LEN))
                return false; /* read_callback_ sets the state for us */

            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_CUESHEET_TRACK_NUMBER_LEN))
                return false; /* read_callback_ sets the state for us */
            track->number = (FLAC__byte)x;

            if(!lib2_FLAC__bitreader_read_byte_block_aligned_no_crc_883B75E0(ctx, decoder->private_->input, (FLAC__byte*)track->isrc, FLAC__STREAM_METADATA_CUESHEET_TRACK_ISRC_LEN/8))
                return false; /* read_callback_ sets the state for us */

            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_CUESHEET_TRACK_TYPE_LEN))
                return false; /* read_callback_ sets the state for us */
            track->type = x;

            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_CUESHEET_TRACK_PRE_EMPHASIS_LEN))
                return false; /* read_callback_ sets the state for us */
            track->pre_emphasis = x;

            if(!lib2_FLAC__bitreader_skip_bits_no_crc_883B80F0(ctx, decoder->private_->input, FLAC__STREAM_METADATA_CUESHEET_TRACK_RESERVED_LEN))
                return false; /* read_callback_ sets the state for us */

            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_CUESHEET_TRACK_NUM_INDICES_LEN))
                return false; /* read_callback_ sets the state for us */
            track->num_indices = (FLAC__byte)x;

            if(track->num_indices > 0) {
                if(0 == (track->indices = (FLAC__StreamMetadata_CueSheet_Index*)safe_calloc_(track->num_indices, sizeof(FLAC__StreamMetadata_CueSheet_Index)))) {
                    decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
                    return false;
                }
                for(j = 0; j < track->num_indices; j++) {
                    FLAC__StreamMetadata_CueSheet_Index *index = &track->indices[j];
                    if(!lib2_FLAC__bitreader_read_raw_uint64_883B7380(ctx, decoder->private_->input, &index->offset, FLAC__STREAM_METADATA_CUESHEET_INDEX_OFFSET_LEN))
                        return false; /* read_callback_ sets the state for us */

                    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_CUESHEET_INDEX_NUMBER_LEN))
                        return false; /* read_callback_ sets the state for us */
                    index->number = (FLAC__byte)x;

                    if(!lib2_FLAC__bitreader_skip_bits_no_crc_883B80F0(ctx, decoder->private_->input, FLAC__STREAM_METADATA_CUESHEET_INDEX_RESERVED_LEN))
                        return false; /* read_callback_ sets the state for us */
                }
            }
        }
    }

    return true;
}

FLAC__bool lib2_read_metadata_picture__883A4988(void *ctx, FLAC__StreamDecoder *decoder, FLAC__StreamMetadata_Picture *obj)
{
    FLAC__uint32 x;


    /* read type */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_PICTURE_TYPE_LEN))
        return false; /* read_callback_ sets the state for us */
    obj->type = x;

    /* read MIME type */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_PICTURE_MIME_TYPE_LENGTH_LEN))
        return false; /* read_callback_ sets the state for us */
    if(0 == (obj->mime_type = (char*)safe_malloc_add_2op_(x, /*+*/1))) {
        decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
        return false;
    }
    if(x > 0) {
        if(!lib2_FLAC__bitreader_read_byte_block_aligned_no_crc_883B75E0(ctx, decoder->private_->input, (FLAC__byte*)obj->mime_type, x))
            return false; /* read_callback_ sets the state for us */
    }
    obj->mime_type[x] = '\0';

    /* read description */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__STREAM_METADATA_PICTURE_DESCRIPTION_LENGTH_LEN))
        return false; /* read_callback_ sets the state for us */
    if(0 == (obj->description = (FLAC__byte*)safe_malloc_add_2op_(x, /*+*/1))) {
        decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
        return false;
    }
    if(x > 0) {
        if(!lib2_FLAC__bitreader_read_byte_block_aligned_no_crc_883B75E0(ctx, decoder->private_->input, obj->description, x))
            return false; /* read_callback_ sets the state for us */
    }
    obj->description[x] = '\0';

    /* read width */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &obj->width, FLAC__STREAM_METADATA_PICTURE_WIDTH_LEN))
        return false; /* read_callback_ sets the state for us */

    /* read height */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &obj->height, FLAC__STREAM_METADATA_PICTURE_HEIGHT_LEN))
        return false; /* read_callback_ sets the state for us */

    /* read depth */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &obj->depth, FLAC__STREAM_METADATA_PICTURE_DEPTH_LEN))
        return false; /* read_callback_ sets the state for us */

    /* read colors */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &obj->colors, FLAC__STREAM_METADATA_PICTURE_COLORS_LEN))
        return false; /* read_callback_ sets the state for us */

    /* read data */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &(obj->data_length), FLAC__STREAM_METADATA_PICTURE_DATA_LENGTH_LEN))
        return false; /* read_callback_ sets the state for us */
    if(0 == (obj->data = (FLAC__byte*)safe_malloc_(obj->data_length))) {
        decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
        return false;
    }
    if(obj->data_length > 0) {
        if(!lib2_FLAC__bitreader_read_byte_block_aligned_no_crc_883B75E0(ctx, decoder->private_->input, obj->data, obj->data_length))
            return false; /* read_callback_ sets the state for us */
    }

    return true;
}

FLAC__StreamDecoderWriteStatus lib2_write_audio_frame_to_client__883A4D58(FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[])
{
    if(decoder->private_->is_seeking) {
        FLAC__uint64 this_frame_sample = frame->header.number.sample_number;
        FLAC__uint64 next_frame_sample = this_frame_sample + (FLAC__uint64)frame->header.blocksize;
        FLAC__uint64 target_sample = decoder->private_->target_sample;


#if FLAC__HAS_OGG
        decoder->private_->got_a_frame = true;
#endif
        decoder->private_->last_frame = *frame; /* save the frame */
        if(this_frame_sample <= target_sample && target_sample < next_frame_sample) { /* we hit our target frame */
            unsigned delta = (unsigned)(target_sample - this_frame_sample);
            /* kick out of seek mode */
            decoder->private_->is_seeking = false;
            /* shift out the samples before target_sample */
            if(delta > 0) {
                unsigned channel;
                const FLAC__int32 *newbuffer[FLAC__MAX_CHANNELS];
                for(channel = 0; channel < frame->header.channels; channel++)
                    newbuffer[channel] = buffer[channel] + delta;
                decoder->private_->last_frame.header.blocksize -= delta;
                decoder->private_->last_frame.header.number.sample_number += (FLAC__uint64)delta;
                /* write the relevant samples */
                return decoder->private_->write_callback(decoder, &decoder->private_->last_frame, newbuffer, decoder->private_->client_data);
            }
            else {
                /* write the relevant samples */
                return decoder->private_->write_callback(decoder, frame, buffer, decoder->private_->client_data);
            }
        }
        else {
            return FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE;
        }
    }
    else {
        /*
         * If we never got STREAMINFO, turn off MD5 checking to save
         * cycles since we don't have a sum to compare to anyway
         */
        if(!decoder->private_->has_stream_info)
            decoder->private_->do_md5_checking = false;
        if(decoder->private_->do_md5_checking) {
            if(!lib2_FLAC__MD5Accumulate_883B8FD0(&decoder->private_->md5context, buffer, frame->header.channels, frame->header.blocksize, (frame->header.bits_per_sample+7) / 8))
                return FLAC__STREAM_DECODER_WRITE_STATUS_ABORT;
        }
        return decoder->private_->write_callback(decoder, frame, buffer, decoder->private_->client_data);
    }
}

FLAC__StreamDecoder *lib2_FLAC__stream_decoder_new_883A4EB8(void)
{
    FLAC__StreamDecoder *decoder;
    unsigned i;
 /* we want to die right away if this is not true */

    decoder = (FLAC__StreamDecoder*)calloc(1, sizeof(FLAC__StreamDecoder));
    if(decoder == 0) {
        return 0;
    }

    decoder->protected_ = (FLAC__StreamDecoderProtected*)calloc(1, sizeof(FLAC__StreamDecoderProtected));
    if(decoder->protected_ == 0) {
        free(decoder);
        return 0;
    }

    decoder->private_ = (FLAC__StreamDecoderPrivate*)calloc(1, sizeof(FLAC__StreamDecoderPrivate));
    if(decoder->private_ == 0) {
        free(decoder->protected_);
        free(decoder);
        return 0;
    }

    decoder->private_->input = ts4_tailcall_fn_8856C298_883B6EB0();
    if(decoder->private_->input == 0) {
        free(decoder->private_);
        free(decoder->protected_);
        free(decoder);
        return 0;
    }

    decoder->private_->metadata_filter_ids_capacity = 16;
    decoder->private_->metadata_filter_ids = (FLAC__byte*)malloc((FLAC__STREAM_METADATA_APPLICATION_ID_LEN/8) * decoder->private_->metadata_filter_ids_capacity);
    if(0 == decoder->private_->metadata_filter_ids) {
        ts4_if_call_seq_u32_off0_883B8088(decoder->private_->input);
        free(decoder->private_);
        free(decoder->protected_);
        free(decoder);
        return 0;
    }

    for(i = 0; i < FLAC__MAX_CHANNELS; i++) {
        decoder->private_->output[i] = 0;
        decoder->private_->residual_unaligned[i] = decoder->private_->residual[i] = 0;
    }

    decoder->private_->output_capacity = 0;
    decoder->private_->output_channels = 0;
    decoder->private_->has_seek_table = false;

    for(i = 0; i < FLAC__MAX_CHANNELS; i++)
        ts4_set_u32_off0_883B6BD8(&decoder->private_->partitioned_rice_contents[i]);

    decoder->private_->file = 0;

    lib2_set_defaults__883A3DB8(decoder);

    decoder->protected_->state = FLAC__STREAM_DECODER_UNINITIALIZED;

    return decoder;
}

FLAC__StreamDecoderInitStatus lib2_init_stream_internal__883A50C0(void *ctx, 
    FLAC__StreamDecoder *decoder,
    FLAC__StreamDecoderReadCallback read_callback,
    FLAC__StreamDecoderSeekCallback seek_callback,
    FLAC__StreamDecoderTellCallback tell_callback,
    FLAC__StreamDecoderLengthCallback length_callback,
    FLAC__StreamDecoderEofCallback eof_callback,
    FLAC__StreamDecoderWriteCallback write_callback,
    FLAC__StreamDecoderMetadataCallback metadata_callback,
    FLAC__StreamDecoderErrorCallback error_callback,
    void *client_data,
    FLAC__bool is_ogg
)
{

    if(decoder->protected_->state != FLAC__STREAM_DECODER_UNINITIALIZED)
        return FLAC__STREAM_DECODER_INIT_STATUS_ALREADY_INITIALIZED;

#if !FLAC__HAS_OGG
    if(is_ogg)
        return FLAC__STREAM_DECODER_INIT_STATUS_UNSUPPORTED_CONTAINER;
#endif

    if(
        0 == read_callback ||
        0 == write_callback ||
        0 == error_callback ||
        (seek_callback && (0 == tell_callback || 0 == length_callback || 0 == eof_callback))
    )
        return FLAC__STREAM_DECODER_INIT_STATUS_INVALID_CALLBACKS;

#if FLAC__HAS_OGG
    decoder->private_->is_ogg = is_ogg;
    if(is_ogg && !FLAC__ogg_decoder_aspect_init(&decoder->protected_->ogg_decoder_aspect))
        return decoder->protected_->state = FLAC__STREAM_DECODER_OGG_ERROR;
#endif

    /*
     * get the CPU info and set the function pointers
     */
    ts4_set_u32_off4_883BA9D0(&decoder->private_->cpuinfo);
    /* first default to the non-asm routines */
    decoder->private_->local_lpc_restore_signal = lib2_FLAC__lpc_restore_signal_883B91C8;
    decoder->private_->local_lpc_restore_signal_64bit = lib2_FLAC__lpc_restore_signal_wide_883B9BD0;
    decoder->private_->local_lpc_restore_signal_16bit = lib2_FLAC__lpc_restore_signal_883B91C8;
    decoder->private_->local_lpc_restore_signal_16bit_order8 = lib2_FLAC__lpc_restore_signal_883B91C8;
    decoder->private_->local_bitreader_read_rice_signed_block = lib2_FLAC__bitreader_read_rice_signed_block_883B7968;
    /* now override with asm where appropriate */
#ifndef FLAC__NO_ASM
    if(decoder->private_->cpuinfo.use_asm) {
#ifdef FLAC__CPU_IA32
#ifdef FLAC__HAS_NASM
#if 1 /*@@@@@@ OPT: not clearly faster, needs more testing */
        if(decoder->private_->cpuinfo.data.ia32.bswap)
            decoder->private_->local_bitreader_read_rice_signed_block = FLAC__bitreader_read_rice_signed_block_asm_ia32_bswap;
#endif
        if(decoder->private_->cpuinfo.data.ia32.mmx) {
            decoder->private_->local_lpc_restore_signal = FLAC__lpc_restore_signal_asm_ia32;
            decoder->private_->local_lpc_restore_signal_16bit = FLAC__lpc_restore_signal_asm_ia32_mmx;
            decoder->private_->local_lpc_restore_signal_16bit_order8 = FLAC__lpc_restore_signal_asm_ia32_mmx;
        }
        else {
            decoder->private_->local_lpc_restore_signal = FLAC__lpc_restore_signal_asm_ia32;
            decoder->private_->local_lpc_restore_signal_16bit = FLAC__lpc_restore_signal_asm_ia32;
            decoder->private_->local_lpc_restore_signal_16bit_order8 = FLAC__lpc_restore_signal_asm_ia32;
        }
#endif
#elif defined FLAC__CPU_PPC
        if(decoder->private_->cpuinfo.data.ppc.altivec) {
            decoder->private_->local_lpc_restore_signal_16bit = FLAC__lpc_restore_signal_asm_ppc_altivec_16;
            decoder->private_->local_lpc_restore_signal_16bit_order8 = FLAC__lpc_restore_signal_asm_ppc_altivec_16_order8;
        }
#endif
    }
#endif

    /* from here on, errors are fatal */

    if(!lib2_FLAC__bitreader_init_883B6EC0(ctx, decoder->private_->input, decoder->private_->cpuinfo, fn_883A4C20, decoder)) {
        decoder->protected_->state = FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR;
        return FLAC__STREAM_DECODER_INIT_STATUS_MEMORY_ALLOCATION_ERROR;
    }

    decoder->private_->read_callback = read_callback;
    decoder->private_->seek_callback = seek_callback;
    decoder->private_->tell_callback = tell_callback;
    decoder->private_->length_callback = length_callback;
    decoder->private_->eof_callback = eof_callback;
    decoder->private_->write_callback = write_callback;
    decoder->private_->metadata_callback = metadata_callback;
    decoder->private_->error_callback = error_callback;
    decoder->private_->client_data = client_data;
    decoder->private_->fixed_block_size = decoder->private_->next_fixed_block_size = 0;
    decoder->private_->samples_decoded = 0;
    decoder->private_->has_stream_info = false;
    decoder->private_->cached = false;

    decoder->private_->do_md5_checking = decoder->protected_->md5_checking;
    decoder->private_->is_seeking = false;

    decoder->private_->internal_reset_hack = true; /* so the following reset does not try to rewind the input */
    if(!lib2_FLAC__stream_decoder_reset_883A3C70(decoder)) {
        /* above call sets the state for us */
        return FLAC__STREAM_DECODER_INIT_STATUS_MEMORY_ALLOCATION_ERROR;
    }

    return FLAC__STREAM_DECODER_INIT_STATUS_OK;
}

FLAC__StreamDecoderInitStatus lib2_FLAC__stream_decoder_init_stream_883A52E8(void *ctx, 
    FLAC__StreamDecoder *decoder,
    FLAC__StreamDecoderReadCallback read_callback,
    FLAC__StreamDecoderSeekCallback seek_callback,
    FLAC__StreamDecoderTellCallback tell_callback,
    FLAC__StreamDecoderLengthCallback length_callback,
    FLAC__StreamDecoderEofCallback eof_callback,
    FLAC__StreamDecoderWriteCallback write_callback,
    FLAC__StreamDecoderMetadataCallback metadata_callback,
    FLAC__StreamDecoderErrorCallback error_callback,
    void *client_data
)
{
    return lib2_init_stream_internal__883A50C0(ctx,
        decoder,
        read_callback,
        seek_callback,
        tell_callback,
        length_callback,
        eof_callback,
        write_callback,
        metadata_callback,
        error_callback,
        client_data,
        /*is_ogg=*/false
    );
}

FLAC__bool lib2_FLAC__stream_decoder_finish_883A5320(void *ctx, FLAC__StreamDecoder *decoder)
{
    FLAC__bool md5_failed = false;
    unsigned i;
    (void)ctx; /* FMOD context, unused here */

    if(decoder->protected_->state == FLAC__STREAM_DECODER_UNINITIALIZED)
        return true;

    /* see the comment in FLAC__seekable_stream_decoder_reset() as to why we
     * always call lib2_FLAC__MD5Final_883B8BB0()
     */
    lib2_FLAC__MD5Final_883B8BB0(decoder->private_->computed_md5sum, &decoder->private_->md5context);

    if(decoder->private_->has_seek_table && 0 != decoder->private_->seek_table.data.seek_table.points) {
        free(decoder->private_->seek_table.data.seek_table.points);
        decoder->private_->seek_table.data.seek_table.points = 0;
        decoder->private_->has_seek_table = false;
    }
    ts4_if_call_seq_u32_off0_883B6F68(decoder->private_->input);
    for(i = 0; i < FLAC__MAX_CHANNELS; i++) {
        /* WATCHOUT:
         * FLAC__lpc_restore_signal_asm_ia32_mmx() requires that the
         * output arrays have a buffer of up to 3 zeroes in front
         * (at negative indices) for alignment purposes; we use 4
         * to keep the data well-aligned.
         */
        if(0 != decoder->private_->output[i]) {
            free(decoder->private_->output[i]-4);
            decoder->private_->output[i] = 0;
        }
        if(0 != decoder->private_->residual_unaligned[i]) {
            free(decoder->private_->residual_unaligned[i]);
            decoder->private_->residual_unaligned[i] = decoder->private_->residual[i] = 0;
        }
    }
    decoder->private_->output_capacity = 0;
    decoder->private_->output_channels = 0;

#if FLAC__HAS_OGG
    if(decoder->private_->is_ogg)
        FLAC__ogg_decoder_aspect_finish(&decoder->protected_->ogg_decoder_aspect);
#endif

    if(0 != decoder->private_->file) {
        if(decoder->private_->file != stdin)
            fn_88566FE8(decoder->private_->file);
        decoder->private_->file = 0;
    }

    if(decoder->private_->do_md5_checking) {
        if(memcmp(decoder->private_->stream_info.data.stream_info.md5sum, decoder->private_->computed_md5sum, 16))
            md5_failed = true;
    }
    decoder->private_->is_seeking = false;

    lib2_set_defaults__883A3DB8(decoder);

    decoder->protected_->state = FLAC__STREAM_DECODER_UNINITIALIZED;

    return !md5_failed;
}

FLAC__bool lib2_FLAC__stream_decoder_get_decode_position_883A54C0(void *ctx, const FLAC__StreamDecoder *decoder, FLAC__uint64 *position)
{
    (void)ctx; /* FMOD context, unused here */
#if FLAC__HAS_OGG
    if(decoder->private_->is_ogg)
        return false;
#endif
    if(0 == decoder->private_->tell_callback)
        return false;
    if(decoder->private_->tell_callback(decoder, position, decoder->private_->client_data) != FLAC__STREAM_DECODER_TELL_STATUS_OK)
        return false;
    /* should never happen since all FLAC frames and metadata blocks are byte aligned, but check just in case */
    if(!ts4_get_u32_off14_883B7088(decoder->private_->input))
        return false;
    *position -= FLAC__stream_decoder_get_input_bytes_unconsumed(decoder);
    return true;
}

LIB2_NOINLINE FLAC__bool lib2_find_metadata__883A5568(void *ctx, FLAC__StreamDecoder *decoder)
{
    FLAC__uint32 x;
    unsigned i, id;
    FLAC__bool first = true;


    for(i = id = 0; i < 4; ) {
        if(decoder->private_->cached) {
            x = (FLAC__uint32)decoder->private_->lookahead;
            decoder->private_->cached = false;
        }
        else {
            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 8))
                return false; /* read_callback_ sets the state for us */
        }
        if(x == FLAC__STREAM_SYNC_STRING[i]) {
            first = true;
            i++;
            id = 0;
            continue;
        }
        if(x == ID3V2_TAG_[id]) {
            id++;
            i = 0;
            if(id == 3) {
                if(!skip_id3v2_tag_(ctx, decoder))
                    return false; /* skip_id3v2_tag_ sets the state for us */
            }
            continue;
        }
        id = 0;
        if(x == 0xff) { /* MAGIC NUMBER for the first 8 frame sync bits */
            decoder->private_->header_warmup[0] = (FLAC__byte)x;
            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 8))
                return false; /* read_callback_ sets the state for us */

            /* we have to check if we just read two 0xff's in a row; the second may actually be the beginning of the sync code */
            /* else we have to check if the second byte is the end of a sync code */
            if(x == 0xff) { /* MAGIC NUMBER for the first 8 frame sync bits */
                decoder->private_->lookahead = (FLAC__byte)x;
                decoder->private_->cached = true;
            }
            else if(x >> 2 == 0x3e) { /* MAGIC NUMBER for the last 6 sync bits */
                decoder->private_->header_warmup[1] = (FLAC__byte)x;
                decoder->protected_->state = FLAC__STREAM_DECODER_READ_FRAME;
                return true;
            }
        }
        i = 0;
        if(first) {
            send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_LOST_SYNC);
            first = false;
        }
    }

    decoder->protected_->state = FLAC__STREAM_DECODER_READ_METADATA;
    return true;
}

FLAC__bool lib2_frame_sync__883A5D30(void *ctx, FLAC__StreamDecoder *decoder)
{
    FLAC__uint32 x;
    FLAC__bool first = true;

    /* If we know the total number of samples in the stream, stop if we've read that many. */
    /* This will stop us, for example, from wasting time trying to sync on an ID3V1 tag. */
    if(FLAC__stream_decoder_get_total_samples(decoder) > 0) {
        if(decoder->private_->samples_decoded >= FLAC__stream_decoder_get_total_samples(decoder)) {
            decoder->protected_->state = FLAC__STREAM_DECODER_END_OF_STREAM;
            return true;
        }
    }

    /* make sure we're byte aligned */
    if(!ts4_get_u32_off14_883B7088(decoder->private_->input)) {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, ts4_get_u32_off14_883B70A0(decoder->private_->input)))
            return false; /* read_callback_ sets the state for us */
    }

    while(1) {
        if(decoder->private_->cached) {
            x = (FLAC__uint32)decoder->private_->lookahead;
            decoder->private_->cached = false;
        }
        else {
            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 8))
                return false; /* read_callback_ sets the state for us */
        }
        if(x == 0xff) { /* MAGIC NUMBER for the first 8 frame sync bits */
            decoder->private_->header_warmup[0] = (FLAC__byte)x;
            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 8))
                return false; /* read_callback_ sets the state for us */

            /* we have to check if we just read two 0xff's in a row; the second may actually be the beginning of the sync code */
            /* else we have to check if the second byte is the end of a sync code */
            if(x == 0xff) { /* MAGIC NUMBER for the first 8 frame sync bits */
                decoder->private_->lookahead = (FLAC__byte)x;
                decoder->private_->cached = true;
            }
            else if(x >> 2 == 0x3e) { /* MAGIC NUMBER for the last 6 sync bits */
                decoder->private_->header_warmup[1] = (FLAC__byte)x;
                decoder->protected_->state = FLAC__STREAM_DECODER_READ_FRAME;
                return true;
            }
        }
        if(first) {
            send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_LOST_SYNC);
            first = false;
        }
    }

    return true;
}

FLAC__bool lib2_read_frame_header__883A5ED8(void *ctx, FLAC__StreamDecoder *decoder)
{
    FLAC__uint32 x;
    FLAC__uint64 xx;
    unsigned i, blocksize_hint = 0, sample_rate_hint = 0;
    FLAC__byte crc8, raw_header[16]; /* MAGIC NUMBER based on the maximum frame header size, including CRC */
    unsigned raw_header_len;
    FLAC__bool is_unparseable = false;


    /* init the raw header with the saved bits from synchronization */
    raw_header[0] = decoder->private_->header_warmup[0];
    raw_header[1] = decoder->private_->header_warmup[1];
    raw_header_len = 2;

    /* check to make sure that reserved bit is 0 */
    if(raw_header[1] & 0x02) /* MAGIC NUMBER */
        is_unparseable = true;

    /*
     * Note that along the way as we read the header, we look for a sync
     * code inside.  If we find one it would indicate that our original
     * sync was bad since there cannot be a sync code in a valid header.
     *
     * Three kinds of things can go wrong when reading the frame header:
     *  1) We may have sync'ed incorrectly and not landed on a frame header.
     *     If we don't find a sync code, it can end up looking like we read
     *     a valid but unparseable header, until getting to the frame header
     *     CRC.  Even then we could get a false positive on the CRC.
     *  2) We may have sync'ed correctly but on an unparseable frame (from a
     *     future encoder).
     *  3) We may be on a damaged frame which appears valid but unparseable.
     *
     * For all these reasons, we try and read a complete frame header as
     * long as it seems valid, even if unparseable, up until the frame
     * header CRC.
     */

    /*
     * read in the raw header as bytes so we can CRC it, and parse it on the way
     */
    for(i = 0; i < 2; i++) {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 8))
            return false; /* read_callback_ sets the state for us */
        if(x == 0xff) { /* MAGIC NUMBER for the first 8 frame sync bits */
            /* if we get here it means our original sync was erroneous since the sync code cannot appear in the header */
            decoder->private_->lookahead = (FLAC__byte)x;
            decoder->private_->cached = true;
            send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_BAD_HEADER);
            decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
            return true;
        }
        raw_header[raw_header_len++] = (FLAC__byte)x;
    }

    switch(x = raw_header[2] >> 4) {
        case 0:
            is_unparseable = true;
            break;
        case 1:
            decoder->private_->frame.header.blocksize = 192;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            decoder->private_->frame.header.blocksize = 576 << (x-2);
            break;
        case 6:
        case 7:
            blocksize_hint = x;
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            decoder->private_->frame.header.blocksize = 256 << (x-8);
            break;
        default:
            break;
    }

    switch(x = raw_header[2] & 0x0f) {
        case 0:
            if(decoder->private_->has_stream_info)
                decoder->private_->frame.header.sample_rate = decoder->private_->stream_info.data.stream_info.sample_rate;
            else
                is_unparseable = true;
            break;
        case 1:
            decoder->private_->frame.header.sample_rate = 88200;
            break;
        case 2:
            decoder->private_->frame.header.sample_rate = 176400;
            break;
        case 3:
            decoder->private_->frame.header.sample_rate = 192000;
            break;
        case 4:
            decoder->private_->frame.header.sample_rate = 8000;
            break;
        case 5:
            decoder->private_->frame.header.sample_rate = 16000;
            break;
        case 6:
            decoder->private_->frame.header.sample_rate = 22050;
            break;
        case 7:
            decoder->private_->frame.header.sample_rate = 24000;
            break;
        case 8:
            decoder->private_->frame.header.sample_rate = 32000;
            break;
        case 9:
            decoder->private_->frame.header.sample_rate = 44100;
            break;
        case 10:
            decoder->private_->frame.header.sample_rate = 48000;
            break;
        case 11:
            decoder->private_->frame.header.sample_rate = 96000;
            break;
        case 12:
        case 13:
        case 14:
            sample_rate_hint = x;
            break;
        case 15:
            send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_BAD_HEADER);
            decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
            return true;
        default:
        break;
    }

    x = (unsigned)(raw_header[3] >> 4);
    if(x & 8) {
        decoder->private_->frame.header.channels = 2;
        switch(x & 7) {
            case 0:
                decoder->private_->frame.header.channel_assignment = FLAC__CHANNEL_ASSIGNMENT_LEFT_SIDE;
                break;
            case 1:
                decoder->private_->frame.header.channel_assignment = FLAC__CHANNEL_ASSIGNMENT_RIGHT_SIDE;
                break;
            case 2:
                decoder->private_->frame.header.channel_assignment = FLAC__CHANNEL_ASSIGNMENT_MID_SIDE;
                break;
            default:
                is_unparseable = true;
                break;
        }
    }
    else {
        decoder->private_->frame.header.channels = (unsigned)x + 1;
        decoder->private_->frame.header.channel_assignment = FLAC__CHANNEL_ASSIGNMENT_INDEPENDENT;
    }

    switch(x = (unsigned)(raw_header[3] & 0x0e) >> 1) {
        case 0:
            if(decoder->private_->has_stream_info)
                decoder->private_->frame.header.bits_per_sample = decoder->private_->stream_info.data.stream_info.bits_per_sample;
            else
                is_unparseable = true;
            break;
        case 1:
            decoder->private_->frame.header.bits_per_sample = 8;
            break;
        case 2:
            decoder->private_->frame.header.bits_per_sample = 12;
            break;
        case 4:
            decoder->private_->frame.header.bits_per_sample = 16;
            break;
        case 5:
            decoder->private_->frame.header.bits_per_sample = 20;
            break;
        case 6:
            decoder->private_->frame.header.bits_per_sample = 24;
            break;
        case 3:
        case 7:
            is_unparseable = true;
            break;
        default:
            break;
    }

    /* check to make sure that reserved bit is 0 */
    if(raw_header[3] & 0x01) /* MAGIC NUMBER */
        is_unparseable = true;

    /* read the frame's starting sample number (or frame number as the case may be) */
    if(
        raw_header[1] & 0x01 ||
        /*@@@ this clause is a concession to the old way of doing variable blocksize; the only known implementation is flake and can probably be removed without inconveniencing anyone */
        (decoder->private_->has_stream_info && decoder->private_->stream_info.data.stream_info.min_blocksize != decoder->private_->stream_info.data.stream_info.max_blocksize)
    ) { /* variable blocksize */
        if(!lib2_FLAC__bitreader_read_utf8_uint64_883B7EA8(ctx, decoder->private_->input, &xx, raw_header, &raw_header_len))
            return false; /* read_callback_ sets the state for us */
        if(xx == FLAC__U64L(0xffffffffffffffff)) { /* i.e. non-UTF8 code... */
            decoder->private_->lookahead = raw_header[raw_header_len-1]; /* back up as much as we can */
            decoder->private_->cached = true;
            send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_BAD_HEADER);
            decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
            return true;
        }
        decoder->private_->frame.header.number_type = FLAC__FRAME_NUMBER_TYPE_SAMPLE_NUMBER;
        decoder->private_->frame.header.number.sample_number = xx;
    }
    else { /* fixed blocksize */
        if(!lib2_FLAC__bitreader_read_utf8_uint32_883B7CF0(ctx, decoder->private_->input, &x, raw_header, &raw_header_len))
            return false; /* read_callback_ sets the state for us */
        if(x == 0xffffffff) { /* i.e. non-UTF8 code... */
            decoder->private_->lookahead = raw_header[raw_header_len-1]; /* back up as much as we can */
            decoder->private_->cached = true;
            send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_BAD_HEADER);
            decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
            return true;
        }
        decoder->private_->frame.header.number_type = FLAC__FRAME_NUMBER_TYPE_FRAME_NUMBER;
        decoder->private_->frame.header.number.frame_number = x;
    }

    if(blocksize_hint) {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 8))
            return false; /* read_callback_ sets the state for us */
        raw_header[raw_header_len++] = (FLAC__byte)x;
        if(blocksize_hint == 7) {
            FLAC__uint32 _x;
            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &_x, 8))
                return false; /* read_callback_ sets the state for us */
            raw_header[raw_header_len++] = (FLAC__byte)_x;
            x = (x << 8) | _x;
        }
        decoder->private_->frame.header.blocksize = x+1;
    }

    if(sample_rate_hint) {
        if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 8))
            return false; /* read_callback_ sets the state for us */
        raw_header[raw_header_len++] = (FLAC__byte)x;
        if(sample_rate_hint != 12) {
            FLAC__uint32 _x;
            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &_x, 8))
                return false; /* read_callback_ sets the state for us */
            raw_header[raw_header_len++] = (FLAC__byte)_x;
            x = (x << 8) | _x;
        }
        if(sample_rate_hint == 12)
            decoder->private_->frame.header.sample_rate = x*1000;
        else if(sample_rate_hint == 13)
            decoder->private_->frame.header.sample_rate = x;
        else
            decoder->private_->frame.header.sample_rate = x*10;
    }

    /* read the CRC-8 byte */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 8))
        return false; /* read_callback_ sets the state for us */
    crc8 = (FLAC__byte)x;

    if(ts4_table_chain_checksum_883BA9E8(raw_header, raw_header_len) != crc8) {
        send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_BAD_HEADER);
        decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
        return true;
    }

    /* calculate the sample number from the frame number if needed */
    decoder->private_->next_fixed_block_size = 0;
    if(decoder->private_->frame.header.number_type == FLAC__FRAME_NUMBER_TYPE_FRAME_NUMBER) {
        x = decoder->private_->frame.header.number.frame_number;
        decoder->private_->frame.header.number_type = FLAC__FRAME_NUMBER_TYPE_SAMPLE_NUMBER;
        if(decoder->private_->fixed_block_size)
            decoder->private_->frame.header.number.sample_number = (FLAC__uint64)decoder->private_->fixed_block_size * (FLAC__uint64)x;
        else if(decoder->private_->has_stream_info) {
            if(decoder->private_->stream_info.data.stream_info.min_blocksize == decoder->private_->stream_info.data.stream_info.max_blocksize) {
                decoder->private_->frame.header.number.sample_number = (FLAC__uint64)decoder->private_->stream_info.data.stream_info.min_blocksize * (FLAC__uint64)x;
                decoder->private_->next_fixed_block_size = decoder->private_->stream_info.data.stream_info.max_blocksize;
            }
            else
                is_unparseable = true;
        }
        else if(x == 0) {
            decoder->private_->frame.header.number.sample_number = 0;
            decoder->private_->next_fixed_block_size = decoder->private_->frame.header.blocksize;
        }
        else {
            /* can only get here if the stream has invalid frame numbering and no STREAMINFO, so assume it's not the last (possibly short) frame */
            decoder->private_->frame.header.number.sample_number = (FLAC__uint64)decoder->private_->frame.header.blocksize * (FLAC__uint64)x;
        }
    }

    if(is_unparseable) {
        send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_UNPARSEABLE_STREAM);
        decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
        return true;
    }

    return true;
}

FLAC__bool lib2_FLAC__stream_decoder_process_until_end_of_metadata_883A6A40(void *ctx, FLAC__StreamDecoder *decoder)
{

    while(1) {
        switch(decoder->protected_->state) {
            case FLAC__STREAM_DECODER_SEARCH_FOR_METADATA:
                if(!lib2_find_metadata__883A5568(ctx, decoder))
                    return false; /* above function sets the status for us */
                break;
            case FLAC__STREAM_DECODER_READ_METADATA:
                if(!fn_883A5780(ctx, decoder))
                    return false; /* above function sets the status for us */
                break;
            case FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC:
            case FLAC__STREAM_DECODER_READ_FRAME:
            case FLAC__STREAM_DECODER_END_OF_STREAM:
            case FLAC__STREAM_DECODER_ABORTED:
                return true;
            default:
                return false;
        }
    }
}

FLAC__bool lib2_read_subframe_fixed__883A6AE8(void *ctx, FLAC__StreamDecoder *decoder, unsigned channel, unsigned bps, const unsigned order, FLAC__bool do_full_decode)
{
    FLAC__Subframe_Fixed *subframe = &decoder->private_->frame.subframes[channel].data.fixed;
    FLAC__int32 i32;
    FLAC__uint32 u32;
    unsigned u;

    decoder->private_->frame.subframes[channel].type = FLAC__SUBFRAME_TYPE_FIXED;

    subframe->residual = decoder->private_->residual[channel];
    subframe->order = order;

    /* read warm-up samples */
    for(u = 0; u < order; u++) {
        if(!ts4_if_call_seq_fn_883B70D8_883B7328(ctx, decoder->private_->input, &i32, bps))
            return false; /* read_callback_ sets the state for us */
        subframe->warmup[u] = i32;
    }

    /* read entropy coding method info */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &u32, FLAC__ENTROPY_CODING_METHOD_TYPE_LEN))
        return false; /* read_callback_ sets the state for us */
    subframe->entropy_coding_method.type = (FLAC__EntropyCodingMethodType)u32;
    switch(subframe->entropy_coding_method.type) {
        case FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE:
        case FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE2:
            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &u32, FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE_ORDER_LEN))
                return false; /* read_callback_ sets the state for us */
            subframe->entropy_coding_method.data.partitioned_rice.order = u32;
            subframe->entropy_coding_method.data.partitioned_rice.contents = &decoder->private_->partitioned_rice_contents[channel];
            break;
        default:
            send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_UNPARSEABLE_STREAM);
            decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
            return true;
    }

    /* read residual */
    switch(subframe->entropy_coding_method.type) {
        case FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE:
        case FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE2:
            if(!fn_883A6748(ctx, decoder, order, subframe->entropy_coding_method.data.partitioned_rice.order, &decoder->private_->partitioned_rice_contents[channel], decoder->private_->residual[channel], /*is_extended=*/subframe->entropy_coding_method.type == FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE2))
                return false;
            break;
        default:
        break;
    }

    /* decode the subframe */
    if(do_full_decode) {
        memcpy(decoder->private_->output[channel], subframe->warmup, sizeof(FLAC__int32) * order);
        lib2_FLAC__fixed_restore_signal_883BAA20(decoder->private_->residual[channel], decoder->private_->frame.header.blocksize-order, order, decoder->private_->output[channel]+order);
    }

    return true;
}

FLAC__bool lib2_read_subframe_lpc__883A6D00(void *ctx, FLAC__StreamDecoder *decoder, unsigned channel, unsigned bps, const unsigned order, FLAC__bool do_full_decode)
{
    FLAC__Subframe_LPC *subframe = &decoder->private_->frame.subframes[channel].data.lpc;
    FLAC__int32 i32;
    FLAC__uint32 u32;
    unsigned u;

    decoder->private_->frame.subframes[channel].type = FLAC__SUBFRAME_TYPE_LPC;

    subframe->residual = decoder->private_->residual[channel];
    subframe->order = order;

    /* read warm-up samples */
    for(u = 0; u < order; u++) {
        if(!ts4_if_call_seq_fn_883B70D8_883B7328(ctx, decoder->private_->input, &i32, bps))
            return false; /* read_callback_ sets the state for us */
        subframe->warmup[u] = i32;
    }

    /* read qlp coeff precision */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &u32, FLAC__SUBFRAME_LPC_QLP_COEFF_PRECISION_LEN))
        return false; /* read_callback_ sets the state for us */
    if(u32 == (1u << FLAC__SUBFRAME_LPC_QLP_COEFF_PRECISION_LEN) - 1) {
        send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_LOST_SYNC);
        decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
        return true;
    }
    subframe->qlp_coeff_precision = u32+1;

    /* read qlp shift */
    if(!ts4_if_call_seq_fn_883B70D8_883B7328(ctx, decoder->private_->input, &i32, FLAC__SUBFRAME_LPC_QLP_SHIFT_LEN))
        return false; /* read_callback_ sets the state for us */
    subframe->quantization_level = i32;

    /* read quantized lp coefficiencts */
    for(u = 0; u < order; u++) {
        if(!ts4_if_call_seq_fn_883B70D8_883B7328(ctx, decoder->private_->input, &i32, subframe->qlp_coeff_precision))
            return false; /* read_callback_ sets the state for us */
        subframe->qlp_coeff[u] = i32;
    }

    /* read entropy coding method info */
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &u32, FLAC__ENTROPY_CODING_METHOD_TYPE_LEN))
        return false; /* read_callback_ sets the state for us */
    subframe->entropy_coding_method.type = (FLAC__EntropyCodingMethodType)u32;
    switch(subframe->entropy_coding_method.type) {
        case FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE:
        case FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE2:
            if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &u32, FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE_ORDER_LEN))
                return false; /* read_callback_ sets the state for us */
            subframe->entropy_coding_method.data.partitioned_rice.order = u32;
            subframe->entropy_coding_method.data.partitioned_rice.contents = &decoder->private_->partitioned_rice_contents[channel];
            break;
        default:
            send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_UNPARSEABLE_STREAM);
            decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
            return true;
    }

    /* read residual */
    switch(subframe->entropy_coding_method.type) {
        case FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE:
        case FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE2:
            if(!fn_883A6748(ctx, decoder, order, subframe->entropy_coding_method.data.partitioned_rice.order, &decoder->private_->partitioned_rice_contents[channel], decoder->private_->residual[channel], /*is_extended=*/subframe->entropy_coding_method.type == FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE2))
                return false;
            break;
        default:
        break;
    }

    /* decode the subframe */
    if(do_full_decode) {
        memcpy(decoder->private_->output[channel], subframe->warmup, sizeof(FLAC__int32) * order);
        /*@@@@@@ technically not pessimistic enough, should be more like
        if( (FLAC__uint64)order * ((((FLAC__uint64)1)<<bps)-1) * ((1<<subframe->qlp_coeff_precision)-1) < (((FLAC__uint64)-1) << 32) )
        */
        if(bps + subframe->qlp_coeff_precision + FLAC__bitmath_ilog2(order) <= 32)
            if(bps <= 16 && subframe->qlp_coeff_precision <= 16) {
                if(order <= 8)
                    decoder->private_->local_lpc_restore_signal_16bit_order8(decoder->private_->residual[channel], decoder->private_->frame.header.blocksize-order, subframe->qlp_coeff, order, subframe->quantization_level, decoder->private_->output[channel]+order);
                else
                    decoder->private_->local_lpc_restore_signal_16bit(decoder->private_->residual[channel], decoder->private_->frame.header.blocksize-order, subframe->qlp_coeff, order, subframe->quantization_level, decoder->private_->output[channel]+order);
            }
            else
                decoder->private_->local_lpc_restore_signal(decoder->private_->residual[channel], decoder->private_->frame.header.blocksize-order, subframe->qlp_coeff, order, subframe->quantization_level, decoder->private_->output[channel]+order);
        else
            decoder->private_->local_lpc_restore_signal_64bit(decoder->private_->residual[channel], decoder->private_->frame.header.blocksize-order, subframe->qlp_coeff, order, subframe->quantization_level, decoder->private_->output[channel]+order);
    }

    return true;
}

FLAC__bool lib2_read_subframe__883A70C0(void *ctx, FLAC__StreamDecoder *decoder, unsigned channel, unsigned bps, FLAC__bool do_full_decode)
{
    FLAC__uint32 x;
    FLAC__bool wasted_bits;
    unsigned i;

    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, 8)) /* MAGIC NUMBER */
        return false; /* read_callback_ sets the state for us */

    wasted_bits = (x & 1);
    x &= 0xfe;

    if(wasted_bits) {
        unsigned u;
        if(!lib2_FLAC__bitreader_read_unary_unsigned_883B7718(ctx, decoder->private_->input, &u))
            return false; /* read_callback_ sets the state for us */
        decoder->private_->frame.subframes[channel].wasted_bits = u+1;
        bps -= decoder->private_->frame.subframes[channel].wasted_bits;
    }
    else
        decoder->private_->frame.subframes[channel].wasted_bits = 0;

    /*
     * Lots of magic numbers here
     */
    if(x & 0x80) {
        send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_LOST_SYNC);
        decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
        return true;
    }
    else if(x == 0) {
        if(!read_subframe_constant_(ctx, decoder, channel, bps, do_full_decode))
            return false;
    }
    else if(x == 2) {
        if(!read_subframe_verbatim_(ctx, decoder, channel, bps, do_full_decode))
            return false;
    }
    else if(x < 16) {
        send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_UNPARSEABLE_STREAM);
        decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
        return true;
    }
    else if(x <= 24) {
        if(!lib2_read_subframe_fixed__883A6AE8(ctx, decoder, channel, bps, (x>>1)&7, do_full_decode))
            return false;
        if(decoder->protected_->state == FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC) /* means bad sync or got corruption */
            return true;
    }
    else if(x < 64) {
        send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_UNPARSEABLE_STREAM);
        decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
        return true;
    }
    else {
        if(!lib2_read_subframe_lpc__883A6D00(ctx, decoder, channel, bps, ((x>>1)&31)+1, do_full_decode))
            return false;
        if(decoder->protected_->state == FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC) /* means bad sync or got corruption */
            return true;
    }

    if(wasted_bits && do_full_decode) {
        x = decoder->private_->frame.subframes[channel].wasted_bits;
        for(i = 0; i < decoder->private_->frame.header.blocksize; i++)
            decoder->private_->output[channel][i] <<= x;
    }

    return true;
}

FLAC__bool lib2_read_frame__883A7468(void *ctx, FLAC__StreamDecoder *decoder, FLAC__bool *got_a_frame, FLAC__bool do_full_decode)
{
    unsigned channel;
    unsigned i;
    FLAC__int32 mid, side;
    unsigned frame_crc; /* the one we calculate from the input stream */
    FLAC__uint32 x;

    *got_a_frame = false;

    /* init the CRC */
    frame_crc = 0;
    frame_crc = FLAC__CRC16_UPDATE(decoder->private_->header_warmup[0], frame_crc);
    frame_crc = FLAC__CRC16_UPDATE(decoder->private_->header_warmup[1], frame_crc);
    ts4_get_u32_off14_883B6FE8(decoder->private_->input, (FLAC__uint16)frame_crc);

    if(!lib2_read_frame_header__883A5ED8(ctx, decoder))
        return false;
    if(decoder->protected_->state == FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC) /* means we didn't sync on a valid header */
        return true;
    if(!lib2_allocate_output__883A3E68(decoder, decoder->private_->frame.header.blocksize, decoder->private_->frame.header.channels))
        return false;
    for(channel = 0; channel < decoder->private_->frame.header.channels; channel++) {
        /*
         * first figure the correct bits-per-sample of the subframe
         */
        unsigned bps = decoder->private_->frame.header.bits_per_sample;
        switch(decoder->private_->frame.header.channel_assignment) {
            case FLAC__CHANNEL_ASSIGNMENT_INDEPENDENT:
                /* no adjustment needed */
                break;
            case FLAC__CHANNEL_ASSIGNMENT_LEFT_SIDE:
                if(channel == 1)
                    bps++;
                break;
            case FLAC__CHANNEL_ASSIGNMENT_RIGHT_SIDE:
                if(channel == 0)
                    bps++;
                break;
            case FLAC__CHANNEL_ASSIGNMENT_MID_SIDE:
                if(channel == 1)
                    bps++;
                break;
            default:
            break;
        }
        /*
         * now read it
         */
        if(!lib2_read_subframe__883A70C0(ctx, decoder, channel, bps, do_full_decode))
            return false;
        if(decoder->protected_->state == FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC) /* means bad sync or got corruption */
            return true;
    }
    if(!read_zero_padding_(ctx, decoder))
        return false;
    if(decoder->protected_->state == FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC) /* means bad sync or got corruption (i.e. "zero bits" were not all zeroes) */
        return true;

    /*
     * Read the frame CRC-16 from the footer and check
     */
    frame_crc = lib2_FLAC__bitreader_get_read_crc16_883B7000(decoder->private_->input);
    if(!lib2_FLAC__bitreader_read_raw_uint32_883B70D8(ctx, decoder->private_->input, &x, FLAC__FRAME_FOOTER_CRC_LEN))
        return false; /* read_callback_ sets the state for us */
    if(frame_crc == x) {
        if(do_full_decode) {
            /* Undo any special channel coding */
            switch(decoder->private_->frame.header.channel_assignment) {
                case FLAC__CHANNEL_ASSIGNMENT_INDEPENDENT:
                    /* do nothing */
                    break;
                case FLAC__CHANNEL_ASSIGNMENT_LEFT_SIDE:
                    for(i = 0; i < decoder->private_->frame.header.blocksize; i++)
                        decoder->private_->output[1][i] = decoder->private_->output[0][i] - decoder->private_->output[1][i];
                    break;
                case FLAC__CHANNEL_ASSIGNMENT_RIGHT_SIDE:
                    for(i = 0; i < decoder->private_->frame.header.blocksize; i++)
                        decoder->private_->output[0][i] += decoder->private_->output[1][i];
                    break;
                case FLAC__CHANNEL_ASSIGNMENT_MID_SIDE:
                    for(i = 0; i < decoder->private_->frame.header.blocksize; i++) {
#if 1
                        mid = decoder->private_->output[0][i];
                        side = decoder->private_->output[1][i];
                        mid <<= 1;
                        mid |= (side & 1); /* i.e. if 'side' is odd... */
                        decoder->private_->output[0][i] = (mid + side) >> 1;
                        decoder->private_->output[1][i] = (mid - side) >> 1;
#else
                        /* OPT: without 'side' temp variable */
                        mid = (decoder->private_->output[0][i] << 1) | (decoder->private_->output[1][i] & 1); /* i.e. if 'side' is odd... */
                        decoder->private_->output[0][i] = (mid + decoder->private_->output[1][i]) >> 1;
                        decoder->private_->output[1][i] = (mid - decoder->private_->output[1][i]) >> 1;
#endif
                    }
                    break;
                default:
                    break;
            }
        }
    }
    else {
        /* Bad frame, emit error and zero the output signal */
        send_error_to_client_(decoder, FLAC__STREAM_DECODER_ERROR_STATUS_FRAME_CRC_MISMATCH);
        if(do_full_decode) {
            for(channel = 0; channel < decoder->private_->frame.header.channels; channel++) {
                memset(decoder->private_->output[channel], 0, sizeof(FLAC__int32) * decoder->private_->frame.header.blocksize);
            }
        }
    }

    *got_a_frame = true;

    /* we wait to update fixed_block_size until here, when we're sure we've got a proper frame and hence a correct blocksize */
    if(decoder->private_->next_fixed_block_size)
        decoder->private_->fixed_block_size = decoder->private_->next_fixed_block_size;

    /* put the latest values into the public section of the decoder instance */
    decoder->protected_->channels = decoder->private_->frame.header.channels;
    decoder->protected_->channel_assignment = decoder->private_->frame.header.channel_assignment;
    decoder->protected_->bits_per_sample = decoder->private_->frame.header.bits_per_sample;
    decoder->protected_->sample_rate = decoder->private_->frame.header.sample_rate;
    decoder->protected_->blocksize = decoder->private_->frame.header.blocksize;

    decoder->private_->samples_decoded = decoder->private_->frame.header.number.sample_number + decoder->private_->frame.header.blocksize;

    /* write it */
    if(do_full_decode) {
        if(lib2_write_audio_frame_to_client__883A4D58(decoder, &decoder->private_->frame, (const FLAC__int32 * const *)decoder->private_->output) != FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE)
            return false;
    }

    decoder->protected_->state = FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC;
    return true;
}

FLAC__bool lib2_FLAC__stream_decoder_process_single_883A78E8(void *ctx, FLAC__StreamDecoder *decoder)
{
    FLAC__bool got_a_frame;

    while(1) {
        switch(decoder->protected_->state) {
            case FLAC__STREAM_DECODER_SEARCH_FOR_METADATA:
                if(!lib2_find_metadata__883A5568(ctx, decoder))
                    return false; /* above function sets the status for us */
                break;
            case FLAC__STREAM_DECODER_READ_METADATA:
                if(!fn_883A5780(ctx, decoder))
                    return false; /* above function sets the status for us */
                else
                    return true;
            case FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC:
                if(!lib2_frame_sync__883A5D30(ctx, decoder))
                    return true; /* above function sets the status for us */
                break;
            case FLAC__STREAM_DECODER_READ_FRAME:
                if(!lib2_read_frame__883A7468(ctx, decoder, &got_a_frame, /*do_full_decode=*/true))
                    return false; /* above function sets the status for us */
                if(got_a_frame)
                    return true; /* above function sets the status for us */
                break;
            case FLAC__STREAM_DECODER_END_OF_STREAM:
            case FLAC__STREAM_DECODER_ABORTED:
                return true;
            default:
                return false;
        }
    }
}

FLAC__bool lib2_FLAC__stream_decoder_seek_absolute_883A7EC8(void *ctx, FLAC__StreamDecoder *decoder, FLAC__uint64 sample)
{
    FLAC__uint64 length;


    if(
        decoder->protected_->state != FLAC__STREAM_DECODER_SEARCH_FOR_METADATA &&
        decoder->protected_->state != FLAC__STREAM_DECODER_READ_METADATA &&
        decoder->protected_->state != FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC &&
        decoder->protected_->state != FLAC__STREAM_DECODER_READ_FRAME &&
        decoder->protected_->state != FLAC__STREAM_DECODER_END_OF_STREAM
    )
        return false;

    if(0 == decoder->private_->seek_callback)
        return false;


    if(FLAC__stream_decoder_get_total_samples(decoder) > 0 && sample >= FLAC__stream_decoder_get_total_samples(decoder))
        return false;

    decoder->private_->is_seeking = true;

    /* turn off md5 checking if a seek is attempted */
    decoder->private_->do_md5_checking = false;

    /* get the file length (currently our algorithm needs to know the length so it's also an error to get FLAC__STREAM_DECODER_LENGTH_STATUS_UNSUPPORTED) */
    if(decoder->private_->length_callback(decoder, &length, decoder->private_->client_data) != FLAC__STREAM_DECODER_LENGTH_STATUS_OK) {
        decoder->private_->is_seeking = false;
        return false;
    }

    /* if we haven't finished processing the metadata yet, do that so we have the STREAMINFO, SEEK_TABLE, and first_frame_offset */
    if(
        decoder->protected_->state == FLAC__STREAM_DECODER_SEARCH_FOR_METADATA ||
        decoder->protected_->state == FLAC__STREAM_DECODER_READ_METADATA
    ) {
        if(!lib2_FLAC__stream_decoder_process_until_end_of_metadata_883A6A40(ctx, decoder)) {
            /* above call sets the state for us */
            decoder->private_->is_seeking = false;
            return false;
        }
        /* check this again in case we didn't know total_samples the first time */
        if(FLAC__stream_decoder_get_total_samples(decoder) > 0 && sample >= FLAC__stream_decoder_get_total_samples(decoder)) {
            decoder->private_->is_seeking = false;
            return false;
        }
    }

    {
        const FLAC__bool ok =
#if FLAC__HAS_OGG
            decoder->private_->is_ogg?
            seek_to_absolute_sample_ogg_(decoder, length, sample) :
#endif
            fn_883A79D8(ctx, decoder, length, sample)
        ;
        decoder->private_->is_seeking = false;
        return ok;
    }
}
