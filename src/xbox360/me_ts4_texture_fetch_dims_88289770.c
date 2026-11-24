/* Swing_DLL.xex 0x88289770: Width/height/depth from a GPU texture fetch constant: dimension bits of dword 5 select the 1D, 3D or 2D/cube size packing of dword 2.
 * Leaf; base is 1 or 3 from dword 3 bit 31 (depth of 2D uses +1). Matches only on /O1 (cr0 extrwi.). */
typedef struct FetchConstant {
    unsigned int w0, w1, size, w3, w4, dim;
} FetchConstant;
void fn_88289770(const FetchConstant *f, unsigned int *width, unsigned int *height, unsigned int *depth)
{
    unsigned int base = ((f->w3 >> 31) << 1) + 1;
    unsigned int dim = (f->dim >> 9) & 3;
    if (dim == 0) {
        *width = (f->size & 0xffffff) + base;
        *height = 1;
        *depth = 1;
    } else if (dim == 2) {
        *width = (f->size & 0x7ff) + base;
        *height = ((f->size >> 11) & 0x7ff) + base;
        *depth = (f->size >> 22) + base;
    } else {
        *width = (f->size & 0x1fff) + base;
        *height = ((f->size >> 13) & 0x1fff) + base;
        *depth = (f->size >> 26) + 1;
    }
}
