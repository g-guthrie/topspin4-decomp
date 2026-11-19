/* 0x88884798: typed allocation. Type 0 uses the default heap (aligned or plain); other types build an
 * attribute word (0x400 for type 2, 0x200 for type 3, 2 or 4 from the flags, 0x20000000 above 200 MB) for fn_8857B048. */
typedef unsigned int u32;
extern void *ts4_if_call_seq_fn_88565258_885690E0(u32 size, u32 align);
extern void *ts4_get_u32_lbl_88D4E11C_88581A90(void);
extern void *fn_885805C0(void *heap, u32 fl, u32 size);
extern void *fn_8857B048(u32 size, u32 id, u32 align, u32 attr);
void *ts4_mem_alloc_typed_88884798(u32 size, u32 id, u32 flags, int type, u32 align) {
    u32 attr;
    if (type == 0) {
        if (align) return ts4_if_call_seq_fn_88565258_885690E0(size, align);
        return fn_885805C0(ts4_get_u32_lbl_88D4E11C_88581A90(), 0, size);
    }
    if (!id) id = 0xFFFFFFFF;
    attr = 0;
    if (type == 2) attr = 0x400;
    else if (type == 3) attr = 0x200;
    if ((flags & 1) && !(flags & 2)) attr |= 2; else attr |= 4;
    if (size > 0xC800000) attr |= 0x20000000;
    return fn_8857B048(size, id, align, attr);
}
