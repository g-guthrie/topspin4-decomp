/* Swing_DLL.xex 0x88577518-0x885775DC, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _calloc_crt-style allocation with errno out-parameter. */
typedef unsigned int u32;
extern int lbl_88D2E740;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void *ts4_get_u32_lbl_88D4E11C_88581A90(void);
extern void *fn_885805C0(void *heap, u32 flags, u32 size);
extern int fn_8856F8C0(u32 size);

void *ts4_crt_calloc_88577518(u32 num, u32 size, int *perr)
{
    void *res;
    if (num != 0 && 0xFFFFF000u / num < size) {
        *ts4_if_call_seq_fn_8856CD88_88567ED8() = 12;
        return 0;
    }
    size = size * num;
    if (size == 0)
        size = 1;
    for (;;) {
        res = 0;
        if (size <= 0xFFFFF000u)
            res = fn_885805C0(ts4_get_u32_lbl_88D4E11C_88581A90(), 8, size);
        if (res || lbl_88D2E740 == 0) {
            if (res == 0) {
                if (perr)
                    *perr = 12;
            }
            return res;
        }
        if (!fn_8856F8C0(size)) {
            if (perr)
                *perr = 12;
            return 0;
        }
    }
}
