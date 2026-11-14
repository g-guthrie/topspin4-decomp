/* Loader_DLL.xex 0x832A5B48-0x832A5BF8, executable version 0.0.0.3. */
typedef unsigned long ts4l_u32;
extern ts4l_u32 ts4_tailcall_fn_83413818_8340CE50(ts4l_u32 handle, ts4l_u32 timeout);

#define TS4L_F(p, off, T) (*(T *)((char *)(p) + (off)))

int ts4l_poll_wait_832A5B48(void *a0, void *a1)
{
    unsigned short n;
    if (TS4L_F(a0, 18456, ts4l_u32) != 0) {
        if (TS4L_F(a1, 45228, int) == 0) {
            if (ts4_tailcall_fn_83413818_8340CE50(TS4L_F(a1, 45644, ts4l_u32), 0) == 258) {
                n = (unsigned short)(TS4L_F(a1, 45648, unsigned short) + 1);
                TS4L_F(a1, 45648, unsigned short) = n;
                if (n >= 2000) {
                    if (ts4_tailcall_fn_83413818_8340CE50(TS4L_F(a1, 45644, ts4l_u32), 2000) == 258) {
                        TS4L_F(a1, 45228, int) = -1;
                        TS4L_F(a1, 45796, int) = 1;
                    }
                    return 1;
                }
                return 0;
            }
        }
    }
    return 1;
}
