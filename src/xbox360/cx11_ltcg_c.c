/* CW11 LTCG route, context: src/xbox360/cw1_ctx_format_text.c. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern void *ts4_memset(void *, int, u32);
extern const char lbl_880F7494[];
typedef struct Cx11Ls Cx11Ls;
typedef struct Cx11LsVt { void *s[4]; void (*f10)(Cx11Ls *, const char *, int); } Cx11LsVt;
struct Cx11Ls { const Cx11LsVt *vt; };
typedef struct Cx11LogOb { u8 pad[0x24]; u32 f24; u8 pad2[4]; u32 f2c; } Cx11LogOb;

/* 0x8860CEB0: format two fields of the object into a 1 KiB buffer and write it through the sink's slot 4 */
void ts4_log_object_8860CEB0(Cx11LogOb *o, Cx11Ls *log)
{
    char buf[0x400];
    int n;
    u32 a;
    u32 b;
    ts4_memset(buf, 0, 0x400);
    a = o->f2c;
    b = o->f24;
    n = ts4_format_text(buf, 0x400, lbl_880F7494, a, b);
    log->vt->f10(log, buf, n);
}
