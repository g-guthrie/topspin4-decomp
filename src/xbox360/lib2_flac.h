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
/* Types derived from libFLAC 1.2.1 include/FLAC/format.h, src/libFLAC/stream_decoder.c
 * and src/libFLAC/include/protected/stream_decoder.h (BSD license); see
 * THIRD_PARTY_NOTICES.md.  FMOD's copy adds a leading context argument to the
 * bitreader read path (and the decoder functions that reach it). */
#ifndef LIB2_FLAC_H
#define LIB2_FLAC_H

typedef int FLAC__bool;
typedef signed char FLAC__int8;
typedef unsigned char FLAC__uint8;
typedef short FLAC__int16;
typedef int FLAC__int32;
typedef long long FLAC__int64;
typedef unsigned short FLAC__uint16;
typedef unsigned int FLAC__uint32;
typedef unsigned long long FLAC__uint64;
typedef FLAC__uint8 FLAC__byte;
typedef float FLAC__real;
typedef unsigned int lib2_size_t;

#define false 0
#define true 1
#define FLAC__MAX_METADATA_TYPE_CODE (126u)
#define FLAC__MAX_CHANNELS (8u)
#define FLAC__MAX_LPC_ORDER (32u)
#define FLAC__MAX_FIXED_ORDER (4u)
#define FLAC__U64L(x) x##ULL

typedef enum { FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE = 0, FLAC__ENTROPY_CODING_METHOD_PARTITIONED_RICE2 = 1 } FLAC__EntropyCodingMethodType;
typedef enum { FLAC__SUBFRAME_TYPE_CONSTANT = 0, FLAC__SUBFRAME_TYPE_VERBATIM = 1, FLAC__SUBFRAME_TYPE_FIXED = 2, FLAC__SUBFRAME_TYPE_LPC = 3 } FLAC__SubframeType;
typedef enum { FLAC__CHANNEL_ASSIGNMENT_INDEPENDENT = 0, FLAC__CHANNEL_ASSIGNMENT_LEFT_SIDE = 1, FLAC__CHANNEL_ASSIGNMENT_RIGHT_SIDE = 2, FLAC__CHANNEL_ASSIGNMENT_MID_SIDE = 3 } FLAC__ChannelAssignment;
typedef enum { FLAC__FRAME_NUMBER_TYPE_FRAME_NUMBER, FLAC__FRAME_NUMBER_TYPE_SAMPLE_NUMBER } FLAC__FrameNumberType;
typedef enum {
    FLAC__METADATA_TYPE_STREAMINFO = 0, FLAC__METADATA_TYPE_PADDING = 1, FLAC__METADATA_TYPE_APPLICATION = 2,
    FLAC__METADATA_TYPE_SEEKTABLE = 3, FLAC__METADATA_TYPE_VORBIS_COMMENT = 4, FLAC__METADATA_TYPE_CUESHEET = 5,
    FLAC__METADATA_TYPE_PICTURE = 6, FLAC__METADATA_TYPE_UNDEFINED = 7
} FLAC__MetadataType;
typedef enum { FLAC__STREAM_METADATA_PICTURE_TYPE_OTHER = 0, FLAC__STREAM_METADATA_PICTURE_TYPE_UNDEFINED = 21 } FLAC__StreamMetadata_Picture_Type;

typedef struct {
    unsigned *parameters;
    unsigned *raw_bits;
    unsigned capacity_by_order;
} FLAC__EntropyCodingMethod_PartitionedRiceContents;
typedef struct {
    unsigned order;
    const FLAC__EntropyCodingMethod_PartitionedRiceContents *contents;
} FLAC__EntropyCodingMethod_PartitionedRice;
typedef struct {
    FLAC__EntropyCodingMethodType type;
    union {
        FLAC__EntropyCodingMethod_PartitionedRice partitioned_rice;
    } data;
} FLAC__EntropyCodingMethod;
typedef struct {
    FLAC__int32 value; 
} FLAC__Subframe_Constant;
typedef struct {
    const FLAC__int32 *data; 
} FLAC__Subframe_Verbatim;
typedef struct {
    FLAC__EntropyCodingMethod entropy_coding_method;
    unsigned order;
    FLAC__int32 warmup[FLAC__MAX_FIXED_ORDER];
    const FLAC__int32 *residual;
} FLAC__Subframe_Fixed;
typedef struct {
    FLAC__EntropyCodingMethod entropy_coding_method;
    unsigned order;
    unsigned qlp_coeff_precision;
    int quantization_level;
    FLAC__int32 qlp_coeff[FLAC__MAX_LPC_ORDER];
    FLAC__int32 warmup[FLAC__MAX_LPC_ORDER];
    const FLAC__int32 *residual;
} FLAC__Subframe_LPC;
typedef struct {
    FLAC__SubframeType type;
    union {
        FLAC__Subframe_Constant constant;
        FLAC__Subframe_Fixed fixed;
        FLAC__Subframe_LPC lpc;
        FLAC__Subframe_Verbatim verbatim;
    } data;
    unsigned wasted_bits;
} FLAC__Subframe;
typedef struct {
    unsigned blocksize;
    unsigned sample_rate;
    unsigned channels;
    FLAC__ChannelAssignment channel_assignment;
    unsigned bits_per_sample;
    FLAC__FrameNumberType number_type;
    union {
        FLAC__uint32 frame_number;
        FLAC__uint64 sample_number;
    } number;
    FLAC__uint8 crc;
} FLAC__FrameHeader;
typedef struct {
    FLAC__uint16 crc;
} FLAC__FrameFooter;
typedef struct {
    FLAC__FrameHeader header;
    FLAC__Subframe subframes[FLAC__MAX_CHANNELS];
    FLAC__FrameFooter footer;
} FLAC__Frame;
typedef struct {
    unsigned min_blocksize, max_blocksize;
    unsigned min_framesize, max_framesize;
    unsigned sample_rate;
    unsigned channels;
    unsigned bits_per_sample;
    FLAC__uint64 total_samples;
    FLAC__byte md5sum[16];
} FLAC__StreamMetadata_StreamInfo;
typedef struct {
    int dummy;
} FLAC__StreamMetadata_Padding;
typedef struct {
    FLAC__byte id[4];
    FLAC__byte *data;
} FLAC__StreamMetadata_Application;
typedef struct {
    FLAC__uint64 sample_number;
    FLAC__uint64 stream_offset;
    unsigned frame_samples;
} FLAC__StreamMetadata_SeekPoint;
typedef struct {
    unsigned num_points;
    FLAC__StreamMetadata_SeekPoint *points;
} FLAC__StreamMetadata_SeekTable;
typedef struct {
    FLAC__uint32 length;
    FLAC__byte *entry;
} FLAC__StreamMetadata_VorbisComment_Entry;
typedef struct {
    FLAC__StreamMetadata_VorbisComment_Entry vendor_string;
    FLAC__uint32 num_comments;
    FLAC__StreamMetadata_VorbisComment_Entry *comments;
} FLAC__StreamMetadata_VorbisComment;
typedef struct {
    FLAC__uint64 offset;
    FLAC__byte number;
} FLAC__StreamMetadata_CueSheet_Index;
typedef struct {
    FLAC__uint64 offset;
    FLAC__byte number;
    char isrc[13];
    unsigned type:1;
    unsigned pre_emphasis:1;
    FLAC__byte num_indices;
    FLAC__StreamMetadata_CueSheet_Index *indices;
} FLAC__StreamMetadata_CueSheet_Track;
typedef struct {
    char media_catalog_number[129];
    FLAC__uint64 lead_in;
    FLAC__bool is_cd;
    unsigned num_tracks;
    FLAC__StreamMetadata_CueSheet_Track *tracks;
} FLAC__StreamMetadata_CueSheet;
typedef struct {
    FLAC__StreamMetadata_Picture_Type type;
    char *mime_type;
    FLAC__byte *description;
    FLAC__uint32 width;
    FLAC__uint32 height;
    FLAC__uint32 depth;
    FLAC__uint32 colors;
    FLAC__uint32 data_length;
    FLAC__byte *data;
} FLAC__StreamMetadata_Picture;
typedef struct {
    FLAC__byte *data;
} FLAC__StreamMetadata_Unknown;
typedef struct {
    FLAC__MetadataType type;
    FLAC__bool is_last;
    unsigned length;
    union {
        FLAC__StreamMetadata_StreamInfo stream_info;
        FLAC__StreamMetadata_Padding padding;
        FLAC__StreamMetadata_Application application;
        FLAC__StreamMetadata_SeekTable seek_table;
        FLAC__StreamMetadata_VorbisComment vorbis_comment;
        FLAC__StreamMetadata_CueSheet cue_sheet;
        FLAC__StreamMetadata_Picture picture;
        FLAC__StreamMetadata_Unknown unknown;
    } data;
} FLAC__StreamMetadata;


typedef enum {
    FLAC__STREAM_DECODER_SEARCH_FOR_METADATA = 0,
    FLAC__STREAM_DECODER_READ_METADATA,
    FLAC__STREAM_DECODER_SEARCH_FOR_FRAME_SYNC,
    FLAC__STREAM_DECODER_READ_FRAME,
    FLAC__STREAM_DECODER_END_OF_STREAM,
    FLAC__STREAM_DECODER_OGG_ERROR,
    FLAC__STREAM_DECODER_SEEK_ERROR,
    FLAC__STREAM_DECODER_ABORTED,
    FLAC__STREAM_DECODER_MEMORY_ALLOCATION_ERROR,
    FLAC__STREAM_DECODER_UNINITIALIZED
} FLAC__StreamDecoderState;
typedef enum {
    FLAC__STREAM_DECODER_INIT_STATUS_OK = 0,
    FLAC__STREAM_DECODER_INIT_STATUS_UNSUPPORTED_CONTAINER,
    FLAC__STREAM_DECODER_INIT_STATUS_INVALID_CALLBACKS,
    FLAC__STREAM_DECODER_INIT_STATUS_MEMORY_ALLOCATION_ERROR,
    FLAC__STREAM_DECODER_INIT_STATUS_ERROR_OPENING_FILE,
    FLAC__STREAM_DECODER_INIT_STATUS_ALREADY_INITIALIZED
} FLAC__StreamDecoderInitStatus;
typedef enum { FLAC__STREAM_DECODER_READ_STATUS_CONTINUE, FLAC__STREAM_DECODER_READ_STATUS_END_OF_STREAM, FLAC__STREAM_DECODER_READ_STATUS_ABORT } FLAC__StreamDecoderReadStatus;
typedef enum { FLAC__STREAM_DECODER_SEEK_STATUS_OK, FLAC__STREAM_DECODER_SEEK_STATUS_ERROR, FLAC__STREAM_DECODER_SEEK_STATUS_UNSUPPORTED } FLAC__StreamDecoderSeekStatus;
typedef enum { FLAC__STREAM_DECODER_TELL_STATUS_OK, FLAC__STREAM_DECODER_TELL_STATUS_ERROR, FLAC__STREAM_DECODER_TELL_STATUS_UNSUPPORTED } FLAC__StreamDecoderTellStatus;
typedef enum { FLAC__STREAM_DECODER_LENGTH_STATUS_OK, FLAC__STREAM_DECODER_LENGTH_STATUS_ERROR, FLAC__STREAM_DECODER_LENGTH_STATUS_UNSUPPORTED } FLAC__StreamDecoderLengthStatus;
typedef enum { FLAC__STREAM_DECODER_WRITE_STATUS_CONTINUE, FLAC__STREAM_DECODER_WRITE_STATUS_ABORT } FLAC__StreamDecoderWriteStatus;
typedef enum {
    FLAC__STREAM_DECODER_ERROR_STATUS_LOST_SYNC,
    FLAC__STREAM_DECODER_ERROR_STATUS_BAD_HEADER,
    FLAC__STREAM_DECODER_ERROR_STATUS_FRAME_CRC_MISMATCH,
    FLAC__STREAM_DECODER_ERROR_STATUS_UNPARSEABLE_STREAM
} FLAC__StreamDecoderErrorStatus;

typedef struct {
    FLAC__bool cpuid, bswap, cmov, mmx, fxsr, sse, sse2, sse3, ssse3, _3dnow, ext3dnow, extmmx;
} FLAC__CPUInfo_IA32;
typedef struct { FLAC__bool altivec, ppc64; } FLAC__CPUInfo_PPC;
typedef struct {
    FLAC__bool use_asm;
    int type;
    union { FLAC__CPUInfo_IA32 ia32; FLAC__CPUInfo_PPC ppc; } data;
} FLAC__CPUInfo;

typedef struct {
    FLAC__uint32 in[16];
    FLAC__uint32 buf[4];
    FLAC__uint32 bytes[2];
    FLAC__byte *internal_buf;
    lib2_size_t capacity;
} FLAC__MD5Context;

typedef struct FLAC__BitReader FLAC__BitReader;
struct FLAC__StreamDecoder;

typedef FLAC__StreamDecoderReadStatus (*FLAC__StreamDecoderReadCallback)(const struct FLAC__StreamDecoder *decoder, FLAC__byte buffer[], lib2_size_t *bytes, void *client_data);
typedef FLAC__StreamDecoderSeekStatus (*FLAC__StreamDecoderSeekCallback)(const struct FLAC__StreamDecoder *decoder, FLAC__uint64 absolute_byte_offset, void *client_data);
typedef FLAC__StreamDecoderTellStatus (*FLAC__StreamDecoderTellCallback)(const struct FLAC__StreamDecoder *decoder, FLAC__uint64 *absolute_byte_offset, void *client_data);
typedef FLAC__StreamDecoderLengthStatus (*FLAC__StreamDecoderLengthCallback)(const struct FLAC__StreamDecoder *decoder, FLAC__uint64 *stream_length, void *client_data);
typedef FLAC__bool (*FLAC__StreamDecoderEofCallback)(const struct FLAC__StreamDecoder *decoder, void *client_data);
typedef FLAC__StreamDecoderWriteStatus (*FLAC__StreamDecoderWriteCallback)(const struct FLAC__StreamDecoder *decoder, const FLAC__Frame *frame, const FLAC__int32 * const buffer[], void *client_data);
typedef void (*FLAC__StreamDecoderMetadataCallback)(const struct FLAC__StreamDecoder *decoder, const FLAC__StreamMetadata *metadata, void *client_data);
typedef void (*FLAC__StreamDecoderErrorCallback)(const struct FLAC__StreamDecoder *decoder, FLAC__StreamDecoderErrorStatus status, void *client_data);

typedef struct FLAC__StreamDecoderProtected {
    FLAC__StreamDecoderState state;
    unsigned channels;
    FLAC__ChannelAssignment channel_assignment;
    unsigned bits_per_sample;
    unsigned sample_rate;
    unsigned blocksize;
    FLAC__bool md5_checking;
} FLAC__StreamDecoderProtected;

typedef struct FLAC__StreamDecoderPrivate {
    FLAC__StreamDecoderReadCallback read_callback;
    FLAC__StreamDecoderSeekCallback seek_callback;
    FLAC__StreamDecoderTellCallback tell_callback;
    FLAC__StreamDecoderLengthCallback length_callback;
    FLAC__StreamDecoderEofCallback eof_callback;
    FLAC__StreamDecoderWriteCallback write_callback;
    FLAC__StreamDecoderMetadataCallback metadata_callback;
    FLAC__StreamDecoderErrorCallback error_callback;
    void (*local_lpc_restore_signal)(const FLAC__int32 residual[], unsigned data_len, const FLAC__int32 qlp_coeff[], unsigned order, int lp_quantization, FLAC__int32 data[]);
    void (*local_lpc_restore_signal_64bit)(const FLAC__int32 residual[], unsigned data_len, const FLAC__int32 qlp_coeff[], unsigned order, int lp_quantization, FLAC__int32 data[]);
    void (*local_lpc_restore_signal_16bit)(const FLAC__int32 residual[], unsigned data_len, const FLAC__int32 qlp_coeff[], unsigned order, int lp_quantization, FLAC__int32 data[]);
    void (*local_lpc_restore_signal_16bit_order8)(const FLAC__int32 residual[], unsigned data_len, const FLAC__int32 qlp_coeff[], unsigned order, int lp_quantization, FLAC__int32 data[]);
    FLAC__bool (*local_bitreader_read_rice_signed_block)(void *ctx, FLAC__BitReader *br, int vals[], unsigned nvals, unsigned parameter);
    void *client_data;
    void *file;
    FLAC__BitReader *input;
    FLAC__int32 *output[FLAC__MAX_CHANNELS];
    FLAC__int32 *residual[FLAC__MAX_CHANNELS];
    FLAC__EntropyCodingMethod_PartitionedRiceContents partitioned_rice_contents[FLAC__MAX_CHANNELS];
    unsigned output_capacity, output_channels;
    FLAC__uint32 fixed_block_size, next_fixed_block_size;
    FLAC__uint64 samples_decoded;
    FLAC__bool has_stream_info, has_seek_table;
    FLAC__StreamMetadata stream_info;
    FLAC__StreamMetadata seek_table;
    FLAC__bool metadata_filter[128];
    FLAC__byte *metadata_filter_ids;
    lib2_size_t metadata_filter_ids_count, metadata_filter_ids_capacity;
    FLAC__Frame frame;
    FLAC__bool cached;
    FLAC__CPUInfo cpuinfo;
    FLAC__byte header_warmup[2];
    FLAC__byte lookahead;
    FLAC__int32 *residual_unaligned[FLAC__MAX_CHANNELS];
    FLAC__bool do_md5_checking;
    FLAC__bool internal_reset_hack;
    FLAC__bool is_seeking;
    FLAC__MD5Context md5context;
    FLAC__byte computed_md5sum[16];
    FLAC__Frame last_frame;
    FLAC__uint64 first_frame_offset;
    FLAC__uint64 target_sample;
    unsigned unparseable_frame_count;
} FLAC__StreamDecoderPrivate;

typedef struct FLAC__StreamDecoder {
    FLAC__StreamDecoderProtected *protected_;
    FLAC__StreamDecoderPrivate *private_;
} FLAC__StreamDecoder;

#endif
