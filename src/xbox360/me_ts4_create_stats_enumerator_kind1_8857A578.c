/* 0x8857A578: checks the title with fn_88582680 and, when it returns 0, creates an XAM stats enumerator of kind 1 with a 64-bit pivot widened from u32. */
/* Matched on /O1 (agAF). Sibling of 0x8857A5D8 (kind 0, 32-bit pivot); r = check; if (r == 0) r = Xam(...). */
unsigned int fn_88582680(unsigned int title);
unsigned int XamUserCreateStatsEnumerator(unsigned int title, unsigned int kind, unsigned __int64 pivot, unsigned int rows,
                                          unsigned int nspecs, const void *specs, unsigned int *size, void **handle);
unsigned int fn_8857A578(unsigned int title, unsigned int pivot, unsigned int rows, unsigned int nspecs, const void *specs,
                         unsigned int *size, void **handle)
{
    unsigned int r = fn_88582680(title);
    if (r == 0)
        r = XamUserCreateStatsEnumerator(title, 1, pivot, rows, nspecs, specs, size, handle);
    return r;
}
