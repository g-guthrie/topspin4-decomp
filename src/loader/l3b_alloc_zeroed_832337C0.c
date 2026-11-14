/* Loader_DLL.xex 0x832337C0-0x832337C0, executable version 0.0.0.3.
 * Allocate and clear a 2040-byte block, returning it through an out pointer
 * (0x8007000E when the allocation fails). */

extern void *fn_8340D710(unsigned, unsigned);
extern void *fn_833E3A30(void *, int, unsigned);

int ts4l_alloc_zeroed_block_832337C0(void **out)
{
    void *p = fn_8340D710(2040, 0x208c8000);
    if (p == 0)
        return 0x8007000e;
    fn_833E3A30(p, 0, 2040);
    *out = p;
    return 0;
}
