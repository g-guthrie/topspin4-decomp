/* Loader_DLL.xex 0x8341B6D8-0x8341B738, executable version 0.0.0.3. */
typedef unsigned long u32;
extern void ts4_set_u32_off4_83423410(void *o);
extern int fn_83428BE8(void *o, u32 a, u32 b, u32 c, u32 d);
extern void ts4l_if_call_seq_u32_off4_83423F10(void *o);
int ts4l_run_83428BE8_8341B6D8(u32 a, u32 b, u32 c)
{
    char obj[0x60];
    int r;
    ts4_set_u32_off4_83423410(obj);
    r = fn_83428BE8(obj, a, b, c, 0);
    if (r < 0) {
        ts4l_if_call_seq_u32_off4_83423F10(obj);
        return r;
    }
    ts4l_if_call_seq_u32_off4_83423F10(obj);
    return 0;
}
