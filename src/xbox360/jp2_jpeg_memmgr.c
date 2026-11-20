/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "jp2_jpeg.h"

void *ts4_jpeg_get_small_882F51D8(struct ts4_jpeg_decomp *cinfo, unsigned int sizeofobject); /* jpeg_get_small, jpeg_get_large (jp2_jpeg_memsys.c) */

extern const unsigned int lbl_88025F00[];

/* Reports an allocation failure through the error manager (jmemmgr.c out_of_memory). */
static void out_of_memory(struct ts4_jpeg_decomp *cinfo, int which)
{
    JP1_ERREXIT1(cinfo, JP2_JERR_OUT_OF_MEMORY, which);
}

/* Allocates a small object from the pool list, adding a new pool when none has room (jmemmgr.c alloc_small). */
void *ts4_jpeg_alloc_small_882ECB68(struct ts4_jpeg_decomp *cinfo, int pool_id, unsigned int sizeofobject)
{
    struct jp2_memory_mgr *mem = (struct jp2_memory_mgr *)cinfo->mem;
    union jp2_pool_hdr *hdr_ptr, *prev_hdr_ptr;
    char *data_ptr;
    unsigned int odd_bytes, min_request, slop;

    if (sizeofobject > (unsigned int)(JP2_MAX_ALLOC_CHUNK - sizeof(union jp2_pool_hdr)))
        out_of_memory(cinfo, 1);

    odd_bytes = sizeofobject % 8;
    if (odd_bytes > 0)
        sizeofobject += 8 - odd_bytes;

    if (pool_id < 0 || pool_id >= JP2_JPOOL_NUMPOOLS)
        JP1_ERREXIT1(cinfo, JP2_JERR_BAD_POOL_ID, pool_id);
    prev_hdr_ptr = 0;
    hdr_ptr = mem->small_list[pool_id];
    while (hdr_ptr != 0) {
        if (hdr_ptr->hdr.bytes_left >= sizeofobject)
            break;
        prev_hdr_ptr = hdr_ptr;
        hdr_ptr = hdr_ptr->hdr.next;
    }

    if (hdr_ptr == 0) {
        min_request = sizeofobject + sizeof(union jp2_pool_hdr);
        if (prev_hdr_ptr == 0)
            slop = lbl_88025F00[pool_id];
        else
            slop = lbl_88025F00[2 + pool_id];
        if (slop > (unsigned int)(JP2_MAX_ALLOC_CHUNK - min_request))
            slop = (unsigned int)(JP2_MAX_ALLOC_CHUNK - min_request);
        for (;;) {
            hdr_ptr = (union jp2_pool_hdr *)ts4_jpeg_get_small_882F51D8(cinfo, min_request + slop);
            if (hdr_ptr != 0)
                break;
            slop /= 2;
            if (slop < 50)
                out_of_memory(cinfo, 2);
        }
        mem->total_space_allocated += min_request + slop;
        hdr_ptr->hdr.next = 0;
        hdr_ptr->hdr.bytes_used = 0;
        hdr_ptr->hdr.bytes_left = sizeofobject + slop;
        if (prev_hdr_ptr == 0)
            mem->small_list[pool_id] = hdr_ptr;
        else
            prev_hdr_ptr->hdr.next = hdr_ptr;
    }

    data_ptr = (char *)(hdr_ptr + 1);
    data_ptr += hdr_ptr->hdr.bytes_used;
    hdr_ptr->hdr.bytes_used += sizeofobject;
    hdr_ptr->hdr.bytes_left -= sizeofobject;
    return (void *)data_ptr;
}

void *ts4_if_get_u32_off4_882ECD40(struct ts4_jpeg_decomp *cinfo, int pool_id, unsigned int sizeofobject);
#define ts4_jpeg_alloc_large_882ECD40 ts4_if_get_u32_off4_882ECD40

/* Allocates a 2-D sample array in chunks of rows (jmemmgr.c alloc_sarray). */
ts4_jsamparray ts4_jpeg_alloc_sarray_882ECE60(struct ts4_jpeg_decomp *cinfo, int pool_id,
                                              ts4_jdim samplesperrow, ts4_jdim numrows)
{
    struct jp2_memory_mgr *mem = (struct jp2_memory_mgr *)cinfo->mem;
    ts4_jsamparray result;
    ts4_jsamprow workspace;
    ts4_jdim rowsperchunk, currow, i;
    int ltemp;

    ltemp = (JP2_MAX_ALLOC_CHUNK - sizeof(union jp2_pool_hdr)) / ((unsigned int)samplesperrow * 1);
    if (ltemp <= 0)
        JP1_ERREXIT(cinfo, 70);
    if (ltemp < (int)numrows)
        rowsperchunk = (ts4_jdim)ltemp;
    else
        rowsperchunk = numrows;
    mem->last_rowsperchunk = rowsperchunk;

    result = (ts4_jsamparray)ts4_jpeg_alloc_small_882ECB68(cinfo, pool_id, (unsigned int)(numrows * sizeof(ts4_jsamprow)));

    currow = 0;
    while (currow < numrows) {
        rowsperchunk = rowsperchunk < numrows - currow ? rowsperchunk : numrows - currow;
        workspace = (ts4_jsamprow)ts4_jpeg_alloc_large_882ECD40(
            cinfo, pool_id, (unsigned int)((unsigned int)rowsperchunk * (unsigned int)samplesperrow * 1));
        for (i = rowsperchunk; i > 0; i--) {
            result[currow++] = workspace;
            workspace += samplesperrow;
        }
    }
    return result;
}

/* Allocates a 2-D coefficient block array in chunks of rows (jmemmgr.c alloc_barray). */
ts4_jblockarray ts4_jpeg_alloc_barray_882ECF40(struct ts4_jpeg_decomp *cinfo, int pool_id,
                                               ts4_jdim blocksperrow, ts4_jdim numrows)
{
    struct jp2_memory_mgr *mem = (struct jp2_memory_mgr *)cinfo->mem;
    ts4_jblockarray result;
    ts4_jblockrow workspace;
    ts4_jdim rowsperchunk, currow, i;
    int ltemp;

    ltemp = (JP2_MAX_ALLOC_CHUNK - sizeof(union jp2_pool_hdr)) / ((unsigned int)blocksperrow * sizeof(ts4_jblock));
    if (ltemp <= 0)
        JP1_ERREXIT(cinfo, 70);
    if (ltemp < (int)numrows)
        rowsperchunk = (ts4_jdim)ltemp;
    else
        rowsperchunk = numrows;
    mem->last_rowsperchunk = rowsperchunk;

    result = (ts4_jblockarray)ts4_jpeg_alloc_small_882ECB68(cinfo, pool_id, (unsigned int)(numrows * sizeof(ts4_jblockrow)));

    currow = 0;
    while (currow < numrows) {
        rowsperchunk = rowsperchunk < numrows - currow ? rowsperchunk : numrows - currow;
        workspace = (ts4_jblockrow)ts4_jpeg_alloc_large_882ECD40(
            cinfo, pool_id, (unsigned int)((unsigned int)rowsperchunk * (unsigned int)blocksperrow * sizeof(ts4_jblock)));
        for (i = rowsperchunk; i > 0; i--) {
            result[currow++] = workspace;
            workspace += blocksperrow;
        }
    }
    return result;
}

struct ts4_jpeg_virt_sarray *ts4_if_get_u32_off4_882ED028(struct ts4_jpeg_decomp *cinfo, int pool_id, int pre_zero,
                                                          ts4_jdim samplesperrow, ts4_jdim numrows, ts4_jdim maxaccess);
struct ts4_jpeg_virt_barray *ts4_if_get_u32_off4_882ED0C0(struct ts4_jpeg_decomp *cinfo, int pool_id, int pre_zero,
                                                          ts4_jdim blocksperrow, ts4_jdim numrows, ts4_jdim maxaccess);
int ts4_get_u32_off4_882F5250(struct ts4_jpeg_decomp *cinfo, int min_bytes_needed, int max_bytes_needed,
                              int already_allocated); /* jpeg_mem_available */
void ts4_if_set_fn_8856C130_882F5398(struct ts4_jpeg_decomp *cinfo, struct jp2_backing_store *info,
                                     int total_bytes_needed); /* jpeg_open_backing_store */

/* Allocates memory (and backing store if needed) for all requested virtual arrays (jmemmgr.c realize_virt_arrays). */
void ts4_jpeg_realize_virt_arrays_882ED158(struct ts4_jpeg_decomp *cinfo)
{
    struct jp2_memory_mgr *mem = (struct jp2_memory_mgr *)cinfo->mem;
    int space_per_minheight, maximum_space, avail_mem;
    int minheights, max_minheights;
    struct ts4_jpeg_virt_sarray *sptr;
    struct ts4_jpeg_virt_barray *bptr;

    space_per_minheight = 0;
    maximum_space = 0;
    for (sptr = mem->virt_sarray_list; sptr != 0; sptr = sptr->next) {
        if (sptr->mem_buffer == 0) {
            space_per_minheight += (int)sptr->maxaccess * (int)sptr->samplesperrow * 1;
            maximum_space += (int)sptr->rows_in_array * (int)sptr->samplesperrow * 1;
        }
    }
    for (bptr = mem->virt_barray_list; bptr != 0; bptr = bptr->next) {
        if (bptr->mem_buffer == 0) {
            space_per_minheight += (int)bptr->maxaccess * (int)bptr->blocksperrow * sizeof(ts4_jblock);
            maximum_space += (int)bptr->rows_in_array * (int)bptr->blocksperrow * sizeof(ts4_jblock);
        }
    }

    if (space_per_minheight <= 0)
        return;

    avail_mem = ts4_get_u32_off4_882F5250(cinfo, space_per_minheight, maximum_space,
                                          mem->total_space_allocated);

    if (avail_mem >= maximum_space)
        max_minheights = 1000000000L;
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
                sptr->rows_in_mem = (ts4_jdim)(max_minheights * sptr->maxaccess);
                ts4_if_set_fn_8856C130_882F5398(cinfo, &sptr->b_s_info,
                                                (int)sptr->rows_in_array * (int)sptr->samplesperrow * 1);
                sptr->b_s_open = 1;
            }
            sptr->mem_buffer = ts4_jpeg_alloc_sarray_882ECE60(cinfo, JP2_JPOOL_IMAGE, sptr->samplesperrow,
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
                bptr->rows_in_mem = (ts4_jdim)(max_minheights * bptr->maxaccess);
                ts4_if_set_fn_8856C130_882F5398(cinfo, &bptr->b_s_info,
                                                (int)bptr->rows_in_array * (int)bptr->blocksperrow * sizeof(ts4_jblock));
                bptr->b_s_open = 1;
            }
            bptr->mem_buffer = ts4_jpeg_alloc_barray_882ECF40(cinfo, JP2_JPOOL_IMAGE, bptr->blocksperrow,
                                                              bptr->rows_in_mem);
            bptr->rowsperchunk = mem->last_rowsperchunk;
            bptr->cur_start_row = 0;
            bptr->first_undef_row = 0;
            bptr->dirty = 0;
        }
    }
}

void ts4_tailcall_fn_8856ABA0_882EE910(void *target, unsigned int bytestozero); /* jzero_far */

/* Reads or writes the in-memory part of a virtual sample array to its backing store. */
void ts4_jpeg_do_sarray_io_882ED390(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_virt_sarray *ptr, int writing)
{
    int bytesperrow, file_offset, byte_count, rows, thisrow, i;

    bytesperrow = (int)ptr->samplesperrow * 1;
    file_offset = ptr->cur_start_row * bytesperrow;
    for (i = 0; i < (int)ptr->rows_in_mem; i += ptr->rowsperchunk) {
        rows = (int)ptr->rowsperchunk < (int)ptr->rows_in_mem - i ? (int)ptr->rowsperchunk : (int)ptr->rows_in_mem - i;
        thisrow = (int)ptr->cur_start_row + i;
        rows = rows < (int)ptr->first_undef_row - thisrow ? rows : (int)ptr->first_undef_row - thisrow;
        rows = rows < (int)ptr->rows_in_array - thisrow ? rows : (int)ptr->rows_in_array - thisrow;
        if (rows <= 0)
            break;
        byte_count = rows * bytesperrow;
        if (writing)
            (*ptr->b_s_info.write_backing_store)(cinfo, &ptr->b_s_info, (void *)ptr->mem_buffer[i], file_offset,
                                                 byte_count);
        else
            (*ptr->b_s_info.read_backing_store)(cinfo, &ptr->b_s_info, (void *)ptr->mem_buffer[i], file_offset,
                                                byte_count);
        file_offset += byte_count;
    }
}

/* Reads or writes the in-memory part of a virtual block array to its backing store. */
void ts4_jpeg_do_barray_io_882ED470(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_virt_barray *ptr, int writing)
{
    int bytesperrow, file_offset, byte_count, rows, thisrow, i;

    bytesperrow = (int)ptr->blocksperrow * sizeof(ts4_jblock);
    file_offset = ptr->cur_start_row * bytesperrow;
    for (i = 0; i < (int)ptr->rows_in_mem; i += ptr->rowsperchunk) {
        rows = (int)ptr->rowsperchunk < (int)ptr->rows_in_mem - i ? (int)ptr->rowsperchunk : (int)ptr->rows_in_mem - i;
        thisrow = (int)ptr->cur_start_row + i;
        rows = rows < (int)ptr->first_undef_row - thisrow ? rows : (int)ptr->first_undef_row - thisrow;
        rows = rows < (int)ptr->rows_in_array - thisrow ? rows : (int)ptr->rows_in_array - thisrow;
        if (rows <= 0)
            break;
        byte_count = rows * bytesperrow;
        if (writing)
            (*ptr->b_s_info.write_backing_store)(cinfo, &ptr->b_s_info, (void *)ptr->mem_buffer[i], file_offset,
                                                 byte_count);
        else
            (*ptr->b_s_info.read_backing_store)(cinfo, &ptr->b_s_info, (void *)ptr->mem_buffer[i], file_offset,
                                                byte_count);
        file_offset += byte_count;
    }
}

/* Makes a window of a virtual sample array addressable (jmemmgr.c access_virt_sarray). */
ts4_jsamparray ts4_jpeg_access_virt_sarray_882ED550(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_virt_sarray *ptr,
                                                    ts4_jdim start_row, ts4_jdim num_rows, int writable)
{
    ts4_jdim end_row = start_row + num_rows;
    ts4_jdim undef_row;

    if (end_row > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == 0)
        JP1_ERREXIT(cinfo, JP2_JERR_BAD_VIRTUAL_ACCESS);

    if (start_row < ptr->cur_start_row || end_row > ptr->cur_start_row + ptr->rows_in_mem) {
        if (!ptr->b_s_open)
            JP1_ERREXIT(cinfo, JP2_JERR_VIRTUAL_BUG);
        if (ptr->dirty) {
            ts4_jpeg_do_sarray_io_882ED390(cinfo, ptr, 1);
            ptr->dirty = 0;
        }
        if (start_row > ptr->cur_start_row) {
            ptr->cur_start_row = start_row;
        } else {
            int ltemp;
            ltemp = (int)end_row - (int)ptr->rows_in_mem;
            if (ltemp < 0)
                ltemp = 0;
            ptr->cur_start_row = (ts4_jdim)ltemp;
        }
        ts4_jpeg_do_sarray_io_882ED390(cinfo, ptr, 0);
    }

    if (ptr->first_undef_row < end_row) {
        if (ptr->first_undef_row < start_row) {
            if (writable)
                JP1_ERREXIT(cinfo, JP2_JERR_BAD_VIRTUAL_ACCESS);
            undef_row = start_row;
        } else {
            undef_row = ptr->first_undef_row;
        }
        if (writable)
            ptr->first_undef_row = end_row;
        if (ptr->pre_zero) {
            unsigned int bytesperrow = (unsigned int)ptr->samplesperrow * 1;
            undef_row -= ptr->cur_start_row;
            end_row -= ptr->cur_start_row;
            while (undef_row < end_row) {
                ts4_tailcall_fn_8856ABA0_882EE910((void *)ptr->mem_buffer[undef_row], bytesperrow);
                undef_row++;
            }
        } else {
            if (!writable)
                JP1_ERREXIT(cinfo, JP2_JERR_BAD_VIRTUAL_ACCESS);
        }
    }
    if (writable)
        ptr->dirty = 1;
    return ptr->mem_buffer + (start_row - ptr->cur_start_row);
}

/* Makes a window of a virtual block array addressable (jmemmgr.c access_virt_barray). */
ts4_jblockarray ts4_jpeg_access_virt_barray_882ED740(struct ts4_jpeg_decomp *cinfo, struct ts4_jpeg_virt_barray *ptr,
                                                    ts4_jdim start_row, ts4_jdim num_rows, int writable)
{
    ts4_jdim end_row = start_row + num_rows;
    ts4_jdim undef_row;

    if (end_row > ptr->rows_in_array || num_rows > ptr->maxaccess || ptr->mem_buffer == 0)
        JP1_ERREXIT(cinfo, JP2_JERR_BAD_VIRTUAL_ACCESS);

    if (start_row < ptr->cur_start_row || end_row > ptr->cur_start_row + ptr->rows_in_mem) {
        if (!ptr->b_s_open)
            JP1_ERREXIT(cinfo, JP2_JERR_VIRTUAL_BUG);
        if (ptr->dirty) {
            ts4_jpeg_do_barray_io_882ED470(cinfo, ptr, 1);
            ptr->dirty = 0;
        }
        if (start_row > ptr->cur_start_row) {
            ptr->cur_start_row = start_row;
        } else {
            int ltemp;
            ltemp = (int)end_row - (int)ptr->rows_in_mem;
            if (ltemp < 0)
                ltemp = 0;
            ptr->cur_start_row = (ts4_jdim)ltemp;
        }
        ts4_jpeg_do_barray_io_882ED470(cinfo, ptr, 0);
    }

    if (ptr->first_undef_row < end_row) {
        if (ptr->first_undef_row < start_row) {
            if (writable)
                JP1_ERREXIT(cinfo, JP2_JERR_BAD_VIRTUAL_ACCESS);
            undef_row = start_row;
        } else {
            undef_row = ptr->first_undef_row;
        }
        if (writable)
            ptr->first_undef_row = end_row;
        if (ptr->pre_zero) {
            unsigned int bytesperrow = (unsigned int)ptr->blocksperrow * sizeof(ts4_jblock);
            undef_row -= ptr->cur_start_row;
            end_row -= ptr->cur_start_row;
            while (undef_row < end_row) {
                ts4_tailcall_fn_8856ABA0_882EE910((void *)ptr->mem_buffer[undef_row], bytesperrow);
                undef_row++;
            }
        } else {
            if (!writable)
                JP1_ERREXIT(cinfo, JP2_JERR_BAD_VIRTUAL_ACCESS);
        }
    }
    if (writable)
        ptr->dirty = 1;
    return ptr->mem_buffer + (start_row - ptr->cur_start_row);
}

void ts4_if_get_u8_0x1_882F5230(struct ts4_jpeg_decomp *cinfo, void *object, unsigned int sizeofobject); /* jpeg_free_small, jpeg_free_large */
void ts4_noop_881B3360(struct ts4_jpeg_decomp *cinfo); /* jpeg_mem_term */
int ts4_fn_882F5438(struct ts4_jpeg_decomp *cinfo); /* jpeg_mem_init */

/* Releases every object in one pool, closing backing store first for the image pool (jmemmgr.c free_pool). */
void ts4_jpeg_free_pool_882ED938(struct ts4_jpeg_decomp *cinfo, int pool_id)
{
    struct jp2_memory_mgr *mem = (struct jp2_memory_mgr *)cinfo->mem;
    union jp2_pool_hdr *shdr_ptr;
    union jp2_pool_hdr *lhdr_ptr;
    unsigned int space_freed;

    if (pool_id < 0 || pool_id >= JP2_JPOOL_NUMPOOLS)
        JP1_ERREXIT1(cinfo, JP2_JERR_BAD_POOL_ID, pool_id);

    if (pool_id == JP2_JPOOL_IMAGE) {
        struct ts4_jpeg_virt_sarray *sptr;
        struct ts4_jpeg_virt_barray *bptr;

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
        union jp2_pool_hdr *next_lhdr_ptr = lhdr_ptr->hdr.next;
        space_freed = lhdr_ptr->hdr.bytes_used + lhdr_ptr->hdr.bytes_left + sizeof(union jp2_pool_hdr);
        ts4_if_get_u8_0x1_882F5230(cinfo, (void *)lhdr_ptr, space_freed);
        mem->total_space_allocated -= space_freed;
        lhdr_ptr = next_lhdr_ptr;
    }

    shdr_ptr = mem->small_list[pool_id];
    mem->small_list[pool_id] = 0;
    while (shdr_ptr != 0) {
        union jp2_pool_hdr *next_shdr_ptr = shdr_ptr->hdr.next;
        space_freed = shdr_ptr->hdr.bytes_used + shdr_ptr->hdr.bytes_left + sizeof(union jp2_pool_hdr);
        ts4_if_get_u8_0x1_882F5230(cinfo, (void *)shdr_ptr, space_freed);
        mem->total_space_allocated -= space_freed;
        shdr_ptr = next_shdr_ptr;
    }
}

/* Frees all pools and the memory manager itself (jmemmgr.c self_destruct). */
void ts4_jpeg_self_destruct_882EDAC0(struct ts4_jpeg_decomp *cinfo)
{
    int pool;

    for (pool = JP2_JPOOL_NUMPOOLS - 1; pool >= JP2_JPOOL_PERMANENT; pool--) {
        ts4_jpeg_free_pool_882ED938(cinfo, pool);
    }
    ts4_if_get_u8_0x1_882F5230(cinfo, (void *)cinfo->mem, sizeof(struct jp2_memory_mgr));
    cinfo->mem = 0;
    ts4_noop_881B3360(cinfo);
}

/* Creates the memory manager and installs it in cinfo->mem (jmemmgr.c jinit_memory_mgr). */
void ts4_jpeg_jinit_memory_mgr_882EDC68(struct ts4_jpeg_decomp *cinfo)
{
    struct jp2_memory_mgr *mem;
    int max_to_use;
    int pool;

    cinfo->mem = 0;

    max_to_use = ts4_fn_882F5438(cinfo);

    mem = (struct jp2_memory_mgr *)ts4_jpeg_get_small_882F51D8(cinfo, sizeof(struct jp2_memory_mgr));

    if (mem == 0) {
        ts4_noop_881B3360(cinfo);
        JP1_ERREXIT1(cinfo, JP2_JERR_OUT_OF_MEMORY, 0);
    }

    mem->pub.alloc_small = ts4_jpeg_alloc_small_882ECB68;
    mem->pub.alloc_large = ts4_jpeg_alloc_large_882ECD40;
    mem->pub.alloc_sarray = ts4_jpeg_alloc_sarray_882ECE60;
    mem->pub.alloc_barray = ts4_jpeg_alloc_barray_882ECF40;
    mem->pub.request_virt_sarray = ts4_if_get_u32_off4_882ED028;
    mem->pub.request_virt_barray = ts4_if_get_u32_off4_882ED0C0;
    mem->pub.realize_virt_arrays = ts4_jpeg_realize_virt_arrays_882ED158;
    mem->pub.access_virt_sarray = ts4_jpeg_access_virt_sarray_882ED550;
    mem->pub.access_virt_barray = ts4_jpeg_access_virt_barray_882ED740;
    mem->pub.free_pool = ts4_jpeg_free_pool_882ED938;
    mem->pub.self_destruct = ts4_jpeg_self_destruct_882EDAC0;

    mem->pub.max_alloc_chunk = JP2_MAX_ALLOC_CHUNK;
    mem->pub.max_memory_to_use = max_to_use;

    for (pool = JP2_JPOOL_NUMPOOLS - 1; pool >= JP2_JPOOL_PERMANENT; pool--) {
        mem->small_list[pool] = 0;
        mem->large_list[pool] = 0;
    }
    mem->virt_sarray_list = 0;
    mem->virt_barray_list = 0;

    mem->total_space_allocated = sizeof(struct jp2_memory_mgr);

    cinfo->mem = &mem->pub;
}
