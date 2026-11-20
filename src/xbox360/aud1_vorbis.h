/********************************************************************
 *                                                                  *
 * THIS FILE IS PART OF THE OggVorbis SOFTWARE CODEC SOURCE CODE.   *
 * USE, DISTRIBUTION AND REPRODUCTION OF THIS LIBRARY SOURCE IS     *
 * GOVERNED BY A BSD-STYLE SOURCE LICENSE INCLUDED WITH THIS SOURCE *
 * IN 'COPYING'. PLEASE READ THESE TERMS BEFORE DISTRIBUTING.       *
 *                                                                  *
 * THE OggVorbis SOURCE CODE IS (C) COPYRIGHT 1994-2009             *
 * by the Xiph.Org Foundation http://www.xiph.org/                  *
 *                                                                  *
 ********************************************************************/
/* Derived from libvorbis 1.2.3 include/vorbis/codec.h, lib/codec_internal.h,
   lib/codebook.h, lib/backends.h (BSD license); see THIRD_PARTY_NOTICES.md.
   Layouts are those of the copy inside FMOD Ex (Swing_DLL.xex), measured from
   the machine code: vorbis_dsp_state has no analysisp, codec_setup_info has no
   psys/psy/bitrate/highlevel members (halfrate_flag follows fullbooks), the
   static codebook has no encoder search trees, and every allocating entry
   point takes a leading FMOD context argument. */
#ifndef AUD1_VORBIS_H
#define AUD1_VORBIS_H

#include "lib2_ogg.h"

#define OV_FALSE -1
#define OV_EOF -2
#define OV_HOLE -3
#define OV_EREAD -128
#define OV_EFAULT -129
#define OV_EIMPL -130
#define OV_EINVAL -131
#define OV_ENOTVORBIS -132
#define OV_EBADHEADER -133
#define OV_EVERSION -134
#define OV_ENOTAUDIO -135
#define OV_EBADPACKET -136
#define OV_EBADLINK -137
#define OV_ENOSEEK -138
#define OV_EMEMORY -139 /* FMOD addition: allocation failure */

typedef struct vorbis_info {
    int version;
    int channels;
    long rate;
    long bitrate_upper;
    long bitrate_nominal;
    long bitrate_lower;
    long bitrate_window;
    void *codec_setup;
} vorbis_info;

typedef struct vorbis_dsp_state {
    vorbis_info *vi;
    float **pcm;
    float **pcmret;
    int pcm_storage;
    int pcm_current;
    int pcm_returned;
    int preextrapolate;
    int eofflag;
    long lW;
    long W;
    long nW;
    long centerW;
    ogg_int64_t granulepos;
    ogg_int64_t sequence;
    ogg_int64_t glue_bits;
    ogg_int64_t time_bits;
    ogg_int64_t floor_bits;
    ogg_int64_t res_bits;
    void *backend_state;
} vorbis_dsp_state;

typedef struct vorbis_block {
    float **pcm;
    oggpack_buffer opb;
    long lW;
    long W;
    long nW;
    int pcmend;
    int mode;
    int eofflag;
    ogg_int64_t granulepos;
    ogg_int64_t sequence;
    vorbis_dsp_state *vd;
    void *localstore;
    long localtop;
    long localalloc;
    long totaluse;
    struct alloc_chain *reap;
    long glue_bits;
    long time_bits;
    long floor_bits;
    long res_bits;
} vorbis_block;

struct alloc_chain {
    void *ptr;
    struct alloc_chain *next;
};

typedef struct vorbis_comment {
    char **user_comments;
    int *comment_lengths;
    int comments;
    char *vendor;
} vorbis_comment;

typedef struct static_codebook {
    long dim;
    long entries;
    long *lengthlist;
    int maptype;
    long q_min;
    long q_delta;
    int q_quant;
    int q_sequencep;
    long *quantlist;
    int allocedp;
} static_codebook;

typedef struct codebook {
    long dim;
    long entries;
    long used_entries;
    const static_codebook *c;
    float *valuelist;
    ogg_uint32_t *codelist;
    int *dec_index;
    char *dec_codelengths;
    ogg_uint32_t *dec_firsttable;
    int dec_firsttablen;
    int dec_maxlength;
} codebook;

typedef void vorbis_look_floor;
typedef void vorbis_look_residue;
typedef void vorbis_look_transform;
typedef void vorbis_info_floor;
typedef void vorbis_info_residue;
typedef void vorbis_info_mapping;

typedef struct {
    int blockflag;
    int windowtype;
    int transformtype;
    int mapping;
} vorbis_info_mode;

typedef struct codec_setup_info {
    long blocksizes[2];
    int modes;
    int maps;
    int floors;
    int residues;
    int books;
    vorbis_info_mode *mode_param[64];
    int map_type[64];
    vorbis_info_mapping *map_param[64];
    int floor_type[64];
    vorbis_info_floor *floor_param[64];
    int residue_type[64];
    vorbis_info_residue *residue_param[64];
    static_codebook *book_param[256];
    codebook *fullbooks;
    int halfrate_flag;
} codec_setup_info;

/* private_state as kept by the FMOD decoder (no envelope, fft, psy or
   bitrate state). */
typedef struct private_state {
    int window[2];
    vorbis_look_transform **transform[2]; /* block, type */
    int modebits;
    vorbis_look_floor **flr;
    vorbis_look_residue **residue;
    ogg_int64_t sample_count;
} private_state;

typedef struct {
    int n;
    int log2n;
    float *trig;
    int *bitrev;
    float scale;
} mdct_lookup;

/* backends.h function tables (encoder slots kept as placeholders) */
typedef struct {
    void (*pack)(vorbis_info_floor *, oggpack_buffer *);
    vorbis_info_floor *(*unpack)(void *, vorbis_info *, oggpack_buffer *);
    vorbis_look_floor *(*look)(void *, vorbis_dsp_state *, vorbis_info_floor *);
    void (*free_info)(void *, vorbis_info_floor *);
    void (*free_look)(void *, vorbis_look_floor *);
    void *(*inverse1)(void *, struct vorbis_block *, vorbis_look_floor *);
    int (*inverse2)(void *, struct vorbis_block *, vorbis_look_floor *, void *buffer, float *);
} vorbis_func_floor;

typedef struct {
    void (*pack)(vorbis_info_residue *, oggpack_buffer *);
    vorbis_info_residue *(*unpack)(void *, vorbis_info *, oggpack_buffer *);
    vorbis_look_residue *(*look)(void *, vorbis_dsp_state *, vorbis_info_residue *);
    void (*free_info)(void *, vorbis_info_residue *);
    void (*free_look)(void *, vorbis_look_residue *);
    long **(*classx)(struct vorbis_block *, vorbis_look_residue *, float **, int *, int);
    int (*forward)(void);
    int (*inverse)(void *, struct vorbis_block *, vorbis_look_residue *, float **, int *, int);
} vorbis_func_residue;

typedef struct {
    void (*pack)(vorbis_info *, vorbis_info_mapping *, oggpack_buffer *);
    vorbis_info_mapping *(*unpack)(void *, vorbis_info *, oggpack_buffer *);
    void (*free_info)(void *, vorbis_info_mapping *);
    void (*free_look)(void *, void *);
    int (*inverse)(void *, struct vorbis_block *vb, vorbis_info_mapping *);
} vorbis_func_mapping;

/* registry.c tables */
extern const vorbis_func_floor *const lbl_88035FCC[];   /* _floor_P */
extern const vorbis_func_residue *const lbl_88035FD4[]; /* _residue_P */
extern const vorbis_func_mapping *const lbl_88035FE0[]; /* _mapping_P */

/* FMOD calloc(ctx, n, size) */
void *ts4_if_call_seq_u32_lbl_88B3302C_8836CC60(void *ctx, long n, long size);

/* libogg bitwise (lib2 / generator names) */
void ts4_call_seq_ts4_memset_883BD130(oggpack_buffer *b, unsigned char *buf, int bytes); /* oggpack_readinit */
long lib2_oggpack_look_883BD168(oggpack_buffer *b, int bits);
void lib2_oggpack_adv_883BD230(oggpack_buffer *b, int bits);
long lib2_oggpack_read_883BD268(oggpack_buffer *b, int bits);
long ts4_bit_cursor_byte_end_883BD358(oggpack_buffer *b); /* oggpack_bytes */
int ts4_bit_length_883BD378(unsigned int v);              /* _ilog (sharedbook.c) */

/* block.c / codebook.c entry points shared between files */
void *aud1__vorbis_block_alloc_883BBDD8(void *ctx, vorbis_block *vb, long bytes);
long ts4_if_call_seq_u32_off8_883BE820(codebook *book, oggpack_buffer *b); /* vorbis_book_decode */
long aud1_vorbis_book_decodev_add_883BEA60(codebook *book, float *a, oggpack_buffer *b, int n);
long fn_883BE888(codebook *book, float *a, oggpack_buffer *b, int n); /* vorbis_book_decodevs_add */
long fn_883BECA0(codebook *book, float **a, long offset, int ch,
                 oggpack_buffer *b, int n);                           /* vorbis_book_decodevv_add */

#endif
