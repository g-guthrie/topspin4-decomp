/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l29_t8_crt_833E73F8.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Statically linked MSVC CRT: _nh_malloc (new-handler aware malloc). */
typedef unsigned long ts4_u32;

extern ts4_u32 ts4_get_u32_lbl_88D4E11C_88581A90(void);
extern void *fn_885805C0(ts4_u32 heap, ts4_u32 flags, ts4_u32 size);
extern void ts4_if_call_seq_fn_8856D820_8856D898(ts4_u32 arg);
extern void ts4_if_call_seq_fn_8856D820_8856D868(ts4_u32 code);
extern void ts4_tailcall_KeBugCheck_88564150(ts4_u32 code);
extern ts4_u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern int fn_8856F8C0(ts4_u32 size);
extern int lbl_88D2E740;

/* Swing_DLL.xex 0x88565258 */
void *ts4_crt_nh_malloc_88565258(ts4_u32 size)
{
    void *p;
    ts4_u32 n, e;
    if (size <= 0xFFFFF000u) {
        for (;;) {
            if (ts4_get_u32_lbl_88D4E11C_88581A90() == 0) {
                ts4_if_call_seq_fn_8856D820_8856D898(0);
                ts4_if_call_seq_fn_8856D820_8856D868(30);
                ts4_tailcall_KeBugCheck_88564150(255);
            }
            n = (size != 0) ? size : 1;
            p = fn_885805C0(ts4_get_u32_lbl_88D4E11C_88581A90(), 0, n);
            if (p != 0) break;
            e = 12;
            if (lbl_88D2E740 == 0) {
                *ts4_if_call_seq_fn_8856CD88_88567ED8() = e;
            } else if (fn_8856F8C0(size) != 0) {
                continue;
            }
            *ts4_if_call_seq_fn_8856CD88_88567ED8() = e;
            break;
        }
        return p;
    }
    fn_8856F8C0(size);
    *ts4_if_call_seq_fn_8856CD88_88567ED8() = 12;
    return 0;
}

