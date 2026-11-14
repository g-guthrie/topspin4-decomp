/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: libpng png.c helpers (signature check, zlib allocator, chunk CRC); 1.0.x-era code, /O1. */

#include "png2_png.h"

#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
extern int memcmp(const void *, const void *, unsigned int);
#else
#include <string.h>
#endif

extern const unsigned char lbl_88007DF0[8]; /* png_sig: 137 80 78 71 13 10 26 10 */
void *ts4_if_call_seq_fn_88888668_882EC170(png2_png_struct *png_ptr, unsigned int size); /* png_malloc */
unsigned int png2_zlib_crc32_882EC228(unsigned int crc, const unsigned char *buf, unsigned int len); /* zlib crc32 */

#define PNG2_FLAG_CRC_ANCILLARY_USE 0x0100u
#define PNG2_FLAG_CRC_ANCILLARY_NOWARN 0x0200u
#define PNG2_FLAG_CRC_CRITICAL_IGNORE 0x0800u
#define PNG2_FLAG_CRC_ANCILLARY_MASK (PNG2_FLAG_CRC_ANCILLARY_USE | PNG2_FLAG_CRC_ANCILLARY_NOWARN)

/* Compare up to 8 bytes of a buffer with the PNG file signature, from offset start (libpng png_sig_cmp).
 * Swing_DLL.xex 0x882E27D0 */
int png2_png_sig_cmp_882E27D0(const unsigned char *sig, unsigned int start, unsigned int num_to_check)
{
    if (num_to_check > 8)
        num_to_check = 8;
    else if (num_to_check < 1)
        return 0;
    if (start > 7)
        return 0;
    if (start + num_to_check > 8)
        num_to_check = 8 - start;
    return memcmp(&sig[start], &lbl_88007DF0[start], num_to_check);
}

/* zlib allocator: png_malloc items*size bytes and zero them, in 32K pieces (libpng png_zalloc).
 * Swing_DLL.xex 0x882E2848 */
void *png2_png_zalloc_882E2848(void *png_ptr, unsigned int items, unsigned int size)
{
    unsigned int num_bytes = items * size;
    void *ptr = ts4_if_call_seq_fn_88888668_882EC170((png2_png_struct *)png_ptr, num_bytes);

    if (ptr == 0)
        return 0;
    if (num_bytes > 0x8000u) {
        memset(ptr, 0, 0x8000u);
        memset((unsigned char *)ptr + 0x8000u, 0, num_bytes - 0x8000u);
    } else {
        memset(ptr, 0, num_bytes);
    }
    return ptr;
}

/* Fold bytes of the current chunk into the running CRC unless the CRC flags say to ignore it
 * (libpng png_calculate_crc). Swing_DLL.xex 0x882E2900 */
void png2_png_calculate_crc_882E2900(png2_png_struct *png_ptr, const unsigned char *ptr, unsigned int length)
{
    int need_crc = 1;

    if (png_ptr->chunk_name[0] & 0x20) {
        if ((png_ptr->flags & PNG2_FLAG_CRC_ANCILLARY_MASK) ==
            (PNG2_FLAG_CRC_ANCILLARY_USE | PNG2_FLAG_CRC_ANCILLARY_NOWARN))
            need_crc = 0;
    } else {
        if (png_ptr->flags & PNG2_FLAG_CRC_CRITICAL_IGNORE)
            need_crc = 0;
    }
    if (need_crc)
        png_ptr->crc = png2_zlib_crc32_882EC228(png_ptr->crc, ptr, length);
}
