/* Loader_DLL.xex 0x8344D070-0x8344D248, 0x8344D368-0x8344D530, 0x8344D660-0x8344E170, executable version 0.0.0.3. */
/* Library routines: libjpeg jmemmgr.c (alloc_small, alloc_sarray, alloc_barray,
   realize_virt_arrays, do_sarray_io, do_barray_io, access_virt_sarray, access_virt_barray,
   free_pool, self_destruct). */
#include "l44_jpeg.h"

typedef struct ts4l_jmem_info {
    void (*read_backing_store)(struct ts4l_jpeg_decomp *cinfo, struct ts4l_jmem_info *info, void *buf,
                               int offset, int nbytes);  /* 0x00 */
    void (*write_backing_store)(struct ts4l_jpeg_decomp *cinfo, struct ts4l_jmem_info *info, void *buf,
                                int offset, int nbytes); /* 0x04 */
    void (*close_backing_store)(struct ts4l_jpeg_decomp *cinfo, struct ts4l_jmem_info *info); /* 0x08 */
} ts4l_jmem_info;

typedef struct ts4l_jvirt {
    void **mem_buffer;            /* 0x00 */
    unsigned int rows_in_array;   /* 0x04 */
    unsigned int samplesperrow;   /* 0x08 */
    unsigned int maxaccess;       /* 0x0c */
    unsigned int rows_in_mem;     /* 0x10 */
    unsigned int rowsperchunk;    /* 0x14 */
    unsigned int cur_start_row;   /* 0x18 */
    unsigned int first_undef_row; /* 0x1c */
    int pre_zero;                 /* 0x20 */
    int dirty;                    /* 0x24 */
    int b_s_open;                 /* 0x28 */
    struct ts4l_jvirt *next;      /* 0x2c */
    ts4l_jmem_info b_s_info;      /* 0x30 */
} ts4l_jvirt;

typedef struct ts4l_jpool_hdr {
    struct ts4l_jpool_hdr *next;  /* 0x00 */
    unsigned int bytes_used;      /* 0x04 */
    unsigned int bytes_left;      /* 0x08 */
    unsigned int pad;             /* 0x0c */
} ts4l_jpool_hdr;

typedef struct ts4l_jmemmgr {
    struct ts4l_jpeg_memory_mgr pub;  /* 0x00 */
    ts4l_jpool_hdr *small_list[2];    /* 0x34 */
    ts4l_jpool_hdr *large_list[2];    /* 0x3c */
    ts4l_jvirt *virt_sarray_list;     /* 0x44 */
    ts4l_jvirt *virt_barray_list;     /* 0x48 */
    int total_space_allocated;        /* 0x4c */
    unsigned int last_rowsperchunk;   /* 0x50 */
} ts4l_jmemmgr;

extern void *fn_83456200(struct ts4l_jpeg_decomp *cinfo, unsigned int size);
extern int ts4_get_u32_off4_834562F0(struct ts4l_jpeg_decomp *cinfo, int min_bytes, int max_bytes,
                                     int already);
extern void ts4l_if_set_fn_8346BD78_83456438(struct ts4l_jpeg_decomp *cinfo, ts4l_jmem_info *info,
                                             int total_bytes);
extern void ts4_tailcall_fn_833E3A30_8344EFA0(void *ptr, unsigned int size);
extern void ts4_if_get_u8_0x1_83456258(struct ts4l_jpeg_decomp *cinfo, void *p, unsigned int size);
extern void ts4_if_get_u8_0x1_834562D0(struct ts4l_jpeg_decomp *cinfo, void *p, unsigned int size);
extern void ts4_fn_834564E8(struct ts4l_jpeg_decomp *cinfo);
extern void *ts4l_if_get_u32_off4_8344D248(struct ts4l_jpeg_decomp *cinfo, int pool_id,
                                           unsigned int size);
extern const unsigned int lbl_8307A858[];

void *ts4l_jpeg_alloc_small_8344D070(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int sizeofobject);
void *ts4l_jpeg_alloc_sarray_8344D368(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int samplesperrow,
                  unsigned int numrows);
void *ts4l_jpeg_alloc_barray_8344D448(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int blocksperrow,
                  unsigned int numrows);

void *ts4l_jpeg_alloc_small_8344D070(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int sizeofobject)
{
    ts4l_jmemmgr *mem = (ts4l_jmemmgr *)cinfo->mem;
    ts4l_jpool_hdr *hdr_ptr;
    ts4l_jpool_hdr *prev_hdr_ptr;
    char *data_ptr;
    unsigned int odd_bytes, min_request, slop;

    if (sizeofobject > 1000000000 - 16)
        TS4L_ERREXIT1(cinfo, 54, 1);

    odd_bytes = sizeofobject % 8;
    if (odd_bytes > 0)
        sizeofobject += 8 - odd_bytes;

    if (pool_id < 0 || pool_id >= 2)
        TS4L_ERREXIT1(cinfo, 14, pool_id);

    prev_hdr_ptr = 0;
    hdr_ptr = mem->small_list[pool_id];
    while (hdr_ptr != 0) {
        if (hdr_ptr->bytes_left >= sizeofobject)
            break;
        prev_hdr_ptr = hdr_ptr;
        hdr_ptr = hdr_ptr->next;
    }

    if (hdr_ptr == 0) {
        min_request = sizeofobject + 16;
        if (prev_hdr_ptr == 0)
            slop = lbl_8307A858[pool_id];
        else
            slop = lbl_8307A858[2 + pool_id];
        if (slop > 1000000000 - min_request)
            slop = 1000000000 - min_request;
        for (;;) {
            hdr_ptr = (ts4l_jpool_hdr *)fn_83456200(cinfo, min_request + slop);
            if (hdr_ptr != 0)
                break;
            slop /= 2;
            if (slop < 50)
                TS4L_ERREXIT1(cinfo, 54, 2);
        }
        mem->total_space_allocated += min_request + slop;
        hdr_ptr->next = 0;
        hdr_ptr->bytes_used = 0;
        hdr_ptr->bytes_left = sizeofobject + slop;
        if (prev_hdr_ptr == 0)
            mem->small_list[pool_id] = hdr_ptr;
        else
            prev_hdr_ptr->next = hdr_ptr;
    }

    data_ptr = (char *)(hdr_ptr + 1);
    data_ptr += hdr_ptr->bytes_used;
    hdr_ptr->bytes_used += sizeofobject;
    hdr_ptr->bytes_left -= sizeofobject;

    return (void *)data_ptr;
}

void *ts4l_jpeg_alloc_sarray_8344D368(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int samplesperrow,
                  unsigned int numrows)
{
    ts4l_jmemmgr *mem = (ts4l_jmemmgr *)cinfo->mem;
    unsigned char **result;
    unsigned char *workspace;
    unsigned int rowsperchunk, currow, i;
    unsigned int ltemp;

    ltemp = (1000000000 - 16) / samplesperrow;
    if ((int)ltemp <= 0)
        TS4L_ERREXIT(cinfo, 70);
    if ((int)ltemp < (int)numrows)
        rowsperchunk = (unsigned int)ltemp;
    else
        rowsperchunk = numrows;
    mem->last_rowsperchunk = rowsperchunk;

    result = (unsigned char **)ts4l_jpeg_alloc_small_8344D070(cinfo, pool_id, numrows * 4);

    currow = 0;
    while (currow < numrows) {
        rowsperchunk = (rowsperchunk < numrows - currow ? rowsperchunk : numrows - currow);
        workspace = (unsigned char *)ts4l_if_get_u32_off4_8344D248(cinfo, pool_id,
                                                                    rowsperchunk * samplesperrow);
        for (i = rowsperchunk; i > 0; i--) {
            result[currow++] = workspace;
            workspace += samplesperrow;
        }
    }

    return result;
}

void *ts4l_jpeg_alloc_barray_8344D448(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int blocksperrow,
                  unsigned int numrows)
{
    ts4l_jmemmgr *mem = (ts4l_jmemmgr *)cinfo->mem;
    short (**result)[64];
    short (*workspace)[64];
    unsigned int rowsperchunk, currow, i;
    unsigned int ltemp;

    ltemp = (1000000000 - 16) / (blocksperrow * 128);
    if ((int)ltemp <= 0)
        TS4L_ERREXIT(cinfo, 70);
    if ((int)ltemp < (int)numrows)
        rowsperchunk = (unsigned int)ltemp;
    else
        rowsperchunk = numrows;
    mem->last_rowsperchunk = rowsperchunk;

    result = (short (**)[64])ts4l_jpeg_alloc_small_8344D070(cinfo, pool_id, numrows * 4);

    currow = 0;
    while (currow < numrows) {
        rowsperchunk = (rowsperchunk < numrows - currow ? rowsperchunk : numrows - currow);
        workspace = (short (*)[64])ts4l_if_get_u32_off4_8344D248(cinfo, pool_id,
                                                                  rowsperchunk * blocksperrow * 128);
        for (i = rowsperchunk; i > 0; i--) {
            result[currow++] = workspace;
            workspace += blocksperrow;
        }
    }

    return result;
}

void ts4l_jpeg_realize_virt_arrays_8344D660(struct ts4l_jpeg_decomp *cinfo)
{
    ts4l_jmemmgr *mem = (ts4l_jmemmgr *)cinfo->mem;
    int space_per_minheight, maximum_space, avail_mem;
    int minheights, max_minheights;
    ts4l_jvirt *sptr;
    ts4l_jvirt *bptr;

    space_per_minheight = 0;
    maximum_space = 0;
    for (sptr = mem->virt_sarray_list; sptr != 0; sptr = sptr->next) {
        if (sptr->mem_buffer == 0) {
            space_per_minheight += (int)sptr->maxaccess * (int)sptr->samplesperrow;
            maximum_space += (int)sptr->rows_in_array * (int)sptr->samplesperrow;
        }
    }
    for (bptr = mem->virt_barray_list; bptr != 0; bptr = bptr->next) {
        if (bptr->mem_buffer == 0) {
            space_per_minheight += (int)bptr->maxaccess * (int)bptr->samplesperrow * 128;
            maximum_space += (int)bptr->rows_in_array * (int)bptr->samplesperrow * 128;
        }
    }

    if (space_per_minheight <= 0)
        return;

    avail_mem = ts4_get_u32_off4_834562F0(cinfo, space_per_minheight, maximum_space,
                                          mem->total_space_allocated);

    if (avail_mem >= maximum_space)
        max_minheights = 1000000000;
    else {
        max_minheights = avail_mem / space_per_minheight;
        if (max_minheights <= 0)
            max_minheights = 1;
    }

    for (sptr = mem->virt_sarray_list; sptr != 0; sptr = sptr->next) {
        if (sptr->mem_buffer == 0) {
            minheights = ((int)sptr->rows_in_array - 1) / sptr->maxaccess + 1;
            if (minheights <= max_minheights) {
                sptr->rows_in_mem = sptr->rows_in_array;
            } else {
                sptr->rows_in_mem = (unsigned int)(max_minheights * sptr->maxaccess);
                ts4l_if_set_fn_8346BD78_83456438(cinfo, &sptr->b_s_info,
                                                 (int)sptr->rows_in_array * (int)sptr->samplesperrow);
                sptr->b_s_open = 1;
            }
            sptr->mem_buffer = (void **)ts4l_jpeg_alloc_sarray_8344D368(cinfo, 1, sptr->samplesperrow,
                                                                       sptr->rows_in_mem);
            sptr->rowsperchunk = mem->last_rowsperchunk;
            sptr->cur_start_row = 0;
            sptr->first_undef_row = 0;
            sptr->dirty = 0;
        }
    }

    for (bptr = mem->virt_barray_list; bptr != 0; bptr = bptr->next) {
        if (bptr->mem_buffer == 0) {
            minheights = ((int)bptr->rows_in_array - 1) / bptr->maxaccess + 1;
            if (minheights <= max_minheights) {
                bptr->rows_in_mem = bptr->rows_in_array;
            } else {
                bptr->rows_in_mem = (unsigned int)(max_minheights * bptr->maxaccess);
                ts4l_if_set_fn_8346BD78_83456438(cinfo, &bptr->b_s_info,
                                                 (int)bptr->rows_in_array * (int)bptr->samplesperrow * 128);
                bptr->b_s_open = 1;
            }
            bptr->mem_buffer = (void **)ts4l_jpeg_alloc_barray_8344D448(cinfo, 1, bptr->samplesperrow,
                                                                       bptr->rows_in_mem);
            bptr->rowsperchunk = mem->last_rowsperchunk;
            bptr->cur_start_row = 0;
            bptr->first_undef_row = 0;
            bptr->dirty = 0;
        }
    }
}

#define TS4L_DO_IO(NAME, ROWSHIFT)                                                                  \
    void NAME(struct ts4l_jpeg_decomp *cinfo, ts4l_jvirt *ptr, int writing)                           \
    {                                                                                                \
        int bytesperrow, file_offset, byte_count, rows, thisrow, i;                                 \
                                                                                                     \
        bytesperrow = ptr->samplesperrow ROWSHIFT;                                                   \
        file_offset = ptr->cur_start_row * bytesperrow;                                              \
        i = 0;                                                                                       \
        while (i < (int)ptr->rows_in_mem) {                                                          \
            rows = ((int)ptr->rowsperchunk < (int)ptr->rows_in_mem - i ? (int)ptr->rowsperchunk      \
                                                                        : (int)ptr->rows_in_mem - i);\
            thisrow = (int)ptr->cur_start_row + i;                                                   \
            rows = (rows < (int)ptr->first_undef_row - thisrow ? rows                                 \
                                                               : (int)ptr->first_undef_row - thisrow);\
            rows = (rows < (int)ptr->rows_in_array - thisrow ? rows                                   \
                                                             : (int)ptr->rows_in_array - thisrow);    \
            if (rows <= 0)                                                                           \
                break;                                                                               \
            byte_count = rows * bytesperrow;                                                         \
            if (writing)                                                                             \
                (*ptr->b_s_info.write_backing_store)(cinfo, &ptr->b_s_info, ptr->mem_buffer[i],      \
                                                     file_offset, byte_count);                       \
            else                                                                                     \
                (*ptr->b_s_info.read_backing_store)(cinfo, &ptr->b_s_info, ptr->mem_buffer[i],       \
                                                    file_offset, byte_count);                        \
            file_offset += byte_count;                                                               \
            i += ptr->rowsperchunk;                                                                  \
        }                                                                                            \
    }

TS4L_DO_IO(ts4l_jpeg_do_sarray_io_8344D898, * 1)
TS4L_DO_IO(ts4l_jpeg_do_barray_io_8344D978, << 7)

#define TS4L_ACCESS(NAME, IOFN, ZEROBYTES)                                                           \
    void *NAME(struct ts4l_jpeg_decomp *cinfo, ts4l_jvirt *ptr, unsigned int start_row,               \
               unsigned int num_rows, int writable)                                                  \
    {                                                                                                \
        unsigned int end_row = start_row + num_rows;                                                 \
        unsigned int undef_row;                                                                      \
                                                                                                     \
        if (end_row > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == 0)      \
            TS4L_ERREXIT(cinfo, 22);                                                                 \
                                                                                                     \
        if (start_row < ptr->cur_start_row || end_row > ptr->cur_start_row + ptr->rows_in_mem) {    \
            if (!ptr->b_s_open)                                                                      \
                TS4L_ERREXIT(cinfo, 69);                                                             \
            if (ptr->dirty) {                                                                        \
                IOFN(cinfo, ptr, 1);                                                                 \
                ptr->dirty = 0;                                                                      \
            }                                                                                        \
            if (start_row > ptr->cur_start_row) {                                                    \
                ptr->cur_start_row = start_row;                                                      \
            } else {                                                                                 \
                int ltemp = (int)end_row - (int)ptr->rows_in_mem;                                    \
                if (ltemp < 0)                                                                       \
                    ltemp = 0;                                                                       \
                ptr->cur_start_row = (unsigned int)ltemp;                                            \
            }                                                                                        \
            IOFN(cinfo, ptr, 0);                                                                     \
        }                                                                                            \
                                                                                                     \
        if (ptr->first_undef_row < end_row) {                                                        \
            if (ptr->first_undef_row < start_row) {                                                  \
                if (writable)                                                                        \
                    TS4L_ERREXIT(cinfo, 22);                                                         \
                undef_row = start_row;                                                               \
            } else {                                                                                 \
                undef_row = ptr->first_undef_row;                                                    \
            }                                                                                        \
            if (writable)                                                                            \
                ptr->first_undef_row = end_row;                                                      \
            if (ptr->pre_zero) {                                                                     \
                unsigned int bytesperrow = ptr->samplesperrow ZEROBYTES;                             \
                undef_row -= ptr->cur_start_row;                                                     \
                end_row -= ptr->cur_start_row;                                                       \
                while (undef_row < end_row) {                                                        \
                    ts4_tailcall_fn_833E3A30_8344EFA0(ptr->mem_buffer[undef_row], bytesperrow);      \
                    undef_row++;                                                                     \
                }                                                                                    \
            } else {                                                                                 \
                if (!writable)                                                                       \
                    TS4L_ERREXIT(cinfo, 22);                                                         \
            }                                                                                        \
        }                                                                                            \
                                                                                                     \
        if (writable)                                                                                \
            ptr->dirty = 1;                                                                          \
                                                                                                     \
        return ptr->mem_buffer + (start_row - ptr->cur_start_row);                                   \
    }

TS4L_ACCESS(ts4l_jpeg_access_virt_sarray_8344DA58, ts4l_jpeg_do_sarray_io_8344D898, * 1)
TS4L_ACCESS(ts4l_jpeg_access_virt_barray_8344DC48, ts4l_jpeg_do_barray_io_8344D978, << 7)

void ts4l_jpeg_free_pool_8344DE40(struct ts4l_jpeg_decomp *cinfo, int pool_id)
{
    ts4l_jmemmgr *mem = (ts4l_jmemmgr *)cinfo->mem;
    ts4l_jpool_hdr *shdr_ptr;
    ts4l_jpool_hdr *lhdr_ptr;
    ts4l_jvirt *sptr;
    ts4l_jvirt *bptr;
    unsigned int space_freed;

    if (pool_id < 0 || pool_id >= 2)
        TS4L_ERREXIT1(cinfo, 14, pool_id);

    if (pool_id == 1) {
        for (sptr = mem->virt_sarray_list; sptr != 0; sptr = sptr->next) {
            if (sptr->b_s_open) {
                sptr->b_s_open = 0;
                (*sptr->b_s_info.close_backing_store)(cinfo, &sptr->b_s_info);
            }
        }
        mem->virt_sarray_list = 0;
        for (bptr = mem->virt_barray_list; bptr != 0; bptr = bptr->next) {
            if (bptr->b_s_open) {
                bptr->b_s_open = 0;
                (*bptr->b_s_info.close_backing_store)(cinfo, &bptr->b_s_info);
            }
        }
        mem->virt_barray_list = 0;
    }

    lhdr_ptr = mem->large_list[pool_id];
    mem->large_list[pool_id] = 0;
    while (lhdr_ptr != 0) {
        ts4l_jpool_hdr *next_lhdr_ptr = lhdr_ptr->next;
        space_freed = lhdr_ptr->bytes_used + lhdr_ptr->bytes_left + 16;
        ts4_if_get_u8_0x1_834562D0(cinfo, lhdr_ptr, space_freed);
        mem->total_space_allocated -= space_freed;
        lhdr_ptr = next_lhdr_ptr;
    }

    shdr_ptr = mem->small_list[pool_id];
    mem->small_list[pool_id] = 0;
    while (shdr_ptr != 0) {
        ts4l_jpool_hdr *next_shdr_ptr = shdr_ptr->next;
        space_freed = shdr_ptr->bytes_used + shdr_ptr->bytes_left + 16;
        ts4_if_get_u8_0x1_83456258(cinfo, shdr_ptr, space_freed);
        mem->total_space_allocated -= space_freed;
        shdr_ptr = next_shdr_ptr;
    }
}

void ts4l_jpeg_self_destruct_8344DFC8(struct ts4l_jpeg_decomp *cinfo)
{
    int pool;

    for (pool = 1; pool >= 0; pool--) {
        ts4l_jpeg_free_pool_8344DE40(cinfo, pool);
    }

    ts4_if_get_u8_0x1_83456258(cinfo, cinfo->mem, 0x54);
    cinfo->mem = 0;
    ts4_fn_834564E8(cinfo);
}
