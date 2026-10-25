typedef unsigned int ts4_u32;

extern unsigned int lbl_88B48D50;
extern unsigned int lbl_8803F634;
extern unsigned int lbl_88CB447C;
typedef unsigned int *ts4_ptr;

ts4_ptr fn_8841F080(ts4_ptr record, ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 ignored, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5, ts4_u32 a6, ts4_u32 a7, ts4_u32 a8, ts4_u32 a9, ts4_u32 a10);

ts4_ptr fn_889E5B60(void) {
    return fn_8841F080((ts4_ptr)&lbl_88CB447C, (ts4_u32)&lbl_8803F634, 0, 0, 0, 0, 0, 0, (ts4_u32)&lbl_88B48D50, 1, 0, 0, 0);
}