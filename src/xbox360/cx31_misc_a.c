/* CW31 part d: misc functions (0x88780000-0x88790000). */
typedef unsigned int u32;
typedef unsigned char u8;

extern void ts4_forward_varargs_88606270(char *dst, u32 size, const char *fmt, ...);
extern void fn_881AAF10(void *dst, const char *text);
extern const char lbl_880EAD84[];

/* 0x88781850: format a value into a 16-byte buffer and hand the text to the destination */
void ts4_format_small_text_88781850(u32 value, void *dst)
{
    char buf[32];
    ts4_forward_varargs_88606270(buf, 16, lbl_880EAD84, value);
    fn_881AAF10(dst, buf);
}
