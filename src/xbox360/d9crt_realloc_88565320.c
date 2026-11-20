/* Swing_DLL.xex 0x88565320-0x88565410, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: realloc. */
typedef unsigned int u32;
extern int lbl_88D2E740;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern u32 ts4_tailcall_fn_88582660_8857B840(void);
extern int fn_88567E68(u32 oserr);
extern void *ts4_get_u32_lbl_88D4E11C_88581A90(void);
extern void *ts4_crt_nh_malloc_88565258(u32 size);
extern void *fn_885651F8(void *block);
extern void *fn_885811B0(void *heap, u32 flags, void *block, u32 size);
extern int fn_8856F8C0(u32 size);

void *ts4_crt_realloc_88565320(void *block, u32 size)
{
    void *res;
    if (block == 0)
        return ts4_crt_nh_malloc_88565258(size);
    if (size == 0) {
        fn_885651F8(block);
        return 0;
    }
    for (;;) {
        res = 0;
        if (size <= 0xFFFFF000u) {
            if (size == 0)
                size = 1;
            res = fn_885811B0(ts4_get_u32_lbl_88D4E11C_88581A90(), 0, block, size);
        } else {
            fn_8856F8C0(size);
            *ts4_if_call_seq_fn_8856CD88_88567ED8() = 12;
            return 0;
        }
        if (res || lbl_88D2E740 == 0) {
            if (res == 0)
                *ts4_if_call_seq_fn_8856CD88_88567ED8() = fn_88567E68(ts4_tailcall_fn_88582660_8857B840());
            return res;
        }
        if (!fn_8856F8C0(size)) {
            *ts4_if_call_seq_fn_8856CD88_88567ED8() = fn_88567E68(ts4_tailcall_fn_88582660_8857B840());
            return 0;
        }
    }
}
