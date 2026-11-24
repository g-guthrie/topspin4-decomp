/* CX36: LTCG route, context src/xbox360/cw1_ctx_format_text.c (varargs shape of ts4_format_text). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern const char lbl_880D58A4[];
typedef struct Cx36Ver { u8 pad[6]; u16 h6; u32 w8; } Cx36Ver;

/* 0x889317F0: format a four-byte value (a.b.c.d) plus a u16 into the caller's buffer */
void ts4_format_version_889317F0(Cx36Ver *v, char *dst, unsigned size)
{
    u32 x = v->w8;
    ts4_format_text(dst, size, lbl_880D58A4, x >> 24, (x >> 16) & 0xFF, (x >> 8) & 0xFF, x & 0xFF, v->h6);
}
