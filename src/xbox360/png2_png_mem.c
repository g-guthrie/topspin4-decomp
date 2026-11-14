/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: libpng pngmem.c on top of the game's tagged allocator (/O1). */

#include "png2_png.h"

#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif

#define PNG2_STRUCT_PNG 1
#define PNG2_STRUCT_INFO 2
#define PNG2_MEM_TAG 0x24810000u

void *fn_88888668(unsigned int size, unsigned int tag); /* game allocator */
void fn_88884DE0(void *ptr, unsigned int tag);           /* game free */

/* Allocate and zero a png_struct (type 1) or png_info (type 2) (libpng png_create_struct). Swing_DLL.xex 0x882EC0E0 */
void *png2_png_create_struct_882EC0E0(int type)
{
    unsigned int size;
    void *struct_ptr;

    if (type == PNG2_STRUCT_INFO)
        size = 0x40;
    else if (type == PNG2_STRUCT_PNG)
        size = sizeof(png2_png_struct);
    else
        return 0;
    if ((struct_ptr = fn_88888668(size, PNG2_MEM_TAG)) != 0)
        memset(struct_ptr, 0, size);
    return struct_ptr;
}

/* Release memory obtained with png_malloc; ignores NULL arguments (libpng png_free). Swing_DLL.xex 0x882EC1E0 */
void png2_png_free_882EC1E0(png2_png_struct *png_ptr, void *ptr)
{
    if (png_ptr == 0 || ptr == 0)
        return;
    fn_88884DE0(ptr, PNG2_MEM_TAG);
}
