/* Loader_DLL.xex 0x833E73F8-0x833E74C0, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _nh_malloc (new-handler aware malloc). */
typedef unsigned long ts4l_u32;

extern ts4l_u32 ts4_get_u32_lbl_8354BA9C_83413808(void);
extern void *fn_83411680(ts4l_u32 heap, ts4l_u32 flags, ts4l_u32 size);
extern void ts4l_if_call_seq_fn_833E8E50_833E8EC8(ts4l_u32 arg);
extern void ts4_if_call_seq_fn_833E8E50_833E8E98(ts4l_u32 code);
extern void ts4_tailcall_KeBugCheck_833E8688(ts4l_u32 code);
extern ts4l_u32 *ts4_if_call_seq_fn_833E8350_833E9F90(void);
extern int fn_833E80A0(ts4l_u32 size);
extern int lbl_835444F0;

void *ts4l_crt_nh_malloc_833E73F8(ts4l_u32 size)
{
    void *p;
    ts4l_u32 n, e;
    if (size <= 0xFFFFF000u) {
        for (;;) {
            if (ts4_get_u32_lbl_8354BA9C_83413808() == 0) {
                ts4l_if_call_seq_fn_833E8E50_833E8EC8(0);
                ts4_if_call_seq_fn_833E8E50_833E8E98(30);
                ts4_tailcall_KeBugCheck_833E8688(255);
            }
            n = (size != 0) ? size : 1;
            p = fn_83411680(ts4_get_u32_lbl_8354BA9C_83413808(), 0, n);
            if (p != 0) break;
            e = 12;
            if (lbl_835444F0 == 0) {
                *ts4_if_call_seq_fn_833E8350_833E9F90() = e;
            } else if (fn_833E80A0(size) != 0) {
                continue;
            }
            *ts4_if_call_seq_fn_833E8350_833E9F90() = e;
            break;
        }
        return p;
    }
    fn_833E80A0(size);
    *ts4_if_call_seq_fn_833E8350_833E9F90() = 12;
    return 0;
}
