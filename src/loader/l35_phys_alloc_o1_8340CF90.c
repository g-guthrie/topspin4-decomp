/* Loader_DLL.xex 0x8340CF90-0x8340D014, executable version 0.0.0.3. */
typedef unsigned long u32;
extern int lbl_8354472C;
extern void *ts4l_import_MmAllocatePhysicalMemoryEx_83517458(u32 type, u32 size, u32 prot, u32 lo, u32 hi, u32 align);
extern void ts4_tailcall_fn_8340F070_8340F068(u32 code);
void *ts4l_phys_alloc_8340CF90(u32 size, int lo, u32 align, u32 prot)
{
    u32 min, max, al;
    void *p;
    if (lbl_8354472C != 0)
        prot &= 0xDFFFFFFF;
    if (lo != -1) {
        min = lo; max = size + lo - 1; al = 0;
    } else {
        min = 0; max = (u32)-1; al = align;
    }
    p = ts4l_import_MmAllocatePhysicalMemoryEx_83517458(0, size, prot, min, max, al);
    if (!p) ts4_tailcall_fn_8340F070_8340F068(8);
    return p;
}
