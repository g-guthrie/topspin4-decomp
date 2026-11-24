/* CW11 LTCG route, context: src/xbox360/cw1_ctx_format_text.c (varargs shape of ts4_format_text). Built with /Oc. */
typedef unsigned int u32;
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern char lbl_88C47594[];
extern const char lbl_880F759C[];

/* 0x88606450: format one value into the shared 16-byte scratch string and return it */
char *ts4_format_value_scratch_88606450(u32 value)
{
    ts4_format_text(lbl_88C47594, 0x10, lbl_880F759C, value);
    return lbl_88C47594;
}

/* 0x8860C1C0: same, formatting the value an id pointer refers to */
char *ts4_format_value_ptr_scratch_8860C1C0(u32 *value)
{
    ts4_format_text(lbl_88C47594, 0x10, lbl_880F759C, *value);
    return lbl_88C47594;
}
