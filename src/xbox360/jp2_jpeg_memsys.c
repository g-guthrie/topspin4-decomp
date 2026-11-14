/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
#include "jp2_jpeg.h"

void *fn_88888668(unsigned int size, unsigned int tag);
int fn_88566750(void *stream, int offset, int origin);
unsigned int ts4_tailcall_fn_885659E8_88565AF8(void *buffer, unsigned int size, unsigned int count, void *stream);
unsigned int fn_88565F50(const void *buffer, unsigned int size, unsigned int count, void *stream);

enum {
    JP2_JERR_TFILE_READ = 64,
    JP2_JERR_TFILE_SEEK = 65,
    JP2_JERR_TFILE_WRITE = 66
};

/* Allocates sizeofobject bytes aligned to 16, with the alignment slack recorded in the byte before the
 * result (jmemnobs.c jpeg_get_small and jpeg_get_large). */
void *ts4_jpeg_get_small_882F51D8(struct ts4_jpeg_decomp *cinfo, unsigned int sizeofobject)
{
    unsigned char *raw;
    unsigned char *aligned;

    (void)cinfo;
    raw = (unsigned char *)fn_88888668(sizeofobject + 16, 0x24810000);
    if (raw == 0)
        return 0;
    aligned = (unsigned char *)(((unsigned long)(raw + 16)) & ~15UL);
    aligned[-1] = (unsigned char)(aligned - raw);
    return aligned;
}

/* Reads byte_count bytes at file_offset from the backing-store temp file (jmemansi.c read_backing_store). */
void ts4_jpeg_read_backing_store_882F5260(struct ts4_jpeg_decomp *cinfo, struct jp2_backing_store *info,
                                          void *buffer_address, int file_offset, int byte_count)
{
    if (fn_88566750(info->temp_file, file_offset, 0))
        JP1_ERREXIT(cinfo, JP2_JERR_TFILE_SEEK);
    if (ts4_tailcall_fn_885659E8_88565AF8(buffer_address, 1, (unsigned int)byte_count, info->temp_file) !=
        (unsigned int)byte_count)
        JP1_ERREXIT(cinfo, JP2_JERR_TFILE_READ);
}

/* Writes byte_count bytes at file_offset to the backing-store temp file (jmemansi.c write_backing_store). */
void ts4_jpeg_write_backing_store_882F52F8(struct ts4_jpeg_decomp *cinfo, struct jp2_backing_store *info,
                                           void *buffer_address, int file_offset, int byte_count)
{
    if (fn_88566750(info->temp_file, file_offset, 0))
        JP1_ERREXIT(cinfo, JP2_JERR_TFILE_SEEK);
    if (fn_88565F50(buffer_address, 1, (unsigned int)byte_count, info->temp_file) != (unsigned int)byte_count)
        JP1_ERREXIT(cinfo, JP2_JERR_TFILE_WRITE);
}
