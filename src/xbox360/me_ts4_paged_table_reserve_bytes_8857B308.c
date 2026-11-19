/* 0x8857B308: Byte size to reserve for a paged table: page-aligned data plus 64-byte records, plus up to three index levels of 0xAA entries per page and 0x1A fixed pages. */
/* Matched on /O1 (agAH). u64 base truncated to u32 gives the clrrwi copy. */
static unsigned int align_page(unsigned int x)
{
    return (x + 0xFFF) & ~0xFFFu;
}
static unsigned int levels(unsigned int n)
{
    return n > 1 ? (n + 0xA9) / 0xAA : 0;
}
unsigned __int64 fn_8857B308(unsigned __int64 base, unsigned int count)
{
    unsigned int pages = (align_page(count * 64 + 0x40) * 2 + align_page((unsigned int)base)) >> 12;
    unsigned int l1 = (pages + 0xA9) / 0xAA;
    unsigned int l2 = levels(l1);
    unsigned int l3 = levels(l2);
    return ((unsigned __int64)((l3 + l2 + l1) * 2 + pages) + 0x1A) << 12;
}
