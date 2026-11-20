/* CX20 LTCG route, context: src/xbox360/cw1_ctx_format_text.c (varargs shape of ts4_format_text). Built with /Oc.
   Value-to-text wrappers: format one value into a caller buffer. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef long long s64;
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern const char lbl_880D312C[]; /* %d */
extern const char lbl_880D5854[]; /* %u */
extern const char lbl_880D5858[]; /* %f */
extern const char lbl_880D6B68[]; /* 0x%08X */
extern const char lbl_880D6B58[]; /* %I64d */

/* 0x8816C408: format an int through a pointer with %d */
void ts4_format_int_8816C408(void *unused_self, const int *v, char *dst, unsigned size)
{
    (void)unused_self;
    ts4_format_text(dst, size, lbl_880D312C, *v);
}

/* 0x8816CE58: format an unsigned through a pointer with %u */
void ts4_format_uint_8816CE58(void *unused_self, const u32 *v, char *dst, unsigned size)
{
    (void)unused_self;
    ts4_format_text(dst, size, lbl_880D5854, *v);
}

/* 0x88171DB0: format a value as 0x%08X */
void ts4_format_hex_88171DB0(void *unused_self, u32 v, char *dst, unsigned size)
{
    (void)unused_self;
    ts4_format_text(dst, size, lbl_880D6B68, v);
}

/* 0x88171DE8: format a 64-bit int through a pointer */
void ts4_format_s64_88171DE8(void *unused_self, const s64 *v, char *dst, unsigned size)
{
    (void)unused_self;
    ts4_format_text(dst, size, lbl_880D6B58, *v);
}

/* 0x88171E20: format a byte through a pointer with %u */
void ts4_format_u8_88171E20(void *unused_self, const u8 *v, char *dst, unsigned size)
{
    (void)unused_self;
    ts4_format_text(dst, size, lbl_880D5854, *v);
}

/* 0x8816CCA0: format a float through a pointer with %f */
void ts4_format_float_8816CCA0(void *unused_self, const float *v, char *dst, unsigned size)
{
    (void)unused_self;
    ts4_format_text(dst, size, lbl_880D5858, *v);
}

extern const char lbl_880D1B40[]; /* %s */
extern const char lbl_880F759C[]; /* 0x%x */
extern const char g_ts4_true_string[];
extern const char lbl_880D1B30[]; /* false */
extern char lbl_88C47594[];

/* 0x8816BDD8: format a bool through a pointer as true/false text */
void ts4_format_bool_8816BDD8(void *unused_self, const u8 *v, char *dst, unsigned size)
{
    const char *s;
    (void)unused_self;
    if (*v != 0) s = g_ts4_true_string;
    else s = lbl_880D1B30;
    ts4_format_text(dst, size, lbl_880D1B40, s);
}

/* 0x8816BD20: format a value as 0x%x into a shared scratch buffer, then copy that text out as %s */
void ts4_format_hex_via_scratch_8816BD20(void *unused_self, const u32 *v, char *dst, unsigned size)
{
    (void)unused_self;
    ts4_format_text(lbl_88C47594, 0x10, lbl_880F759C, *v);
    ts4_format_text(dst, size, lbl_880D1B40, lbl_88C47594);
}
