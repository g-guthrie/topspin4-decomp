/* CX50: chunked read loop, Swing_DLL.xex 0x889C7C58. */
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wint-to-pointer-cast"
#pragma clang diagnostic ignored "-Wpointer-to-int-cast"
#endif
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 fn_889C6920(u32 s, u32 dst, int *remain, int *off);
extern void ts4_loop_call_seq_u32_off4_889C7BE8(u32 a, u32 b);
extern void ts4_if_call_seq_u32_off4_889C64C0(u32 a);
/* 0x889C7C58: read a chunked block through the stream until the requested length is consumed */
void ts4_cx50_read_chunks_889C7C58(u32 a0, u32 a1, u32 a2, int *a3)
{
    int off = 0;
    int remain;
    u32 s;
    if (*a3 != 0) {
        s = a1 + 4;
        do {
            remain = *a3 - off;
            if (fn_889C6920(s, off + a2, &remain, &off)) {
                ts4_loop_call_seq_u32_off4_889C7BE8(a0, a1);
                ts4_if_call_seq_u32_off4_889C64C0(s);
            }
        } while (*a3 != off);
    }
}
