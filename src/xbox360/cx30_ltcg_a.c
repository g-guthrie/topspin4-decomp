/* CX30 LTCG part a: callers of the varargs text formatter (LTCG route, context src/xbox360/cw1_ctx_format_text.c). */
typedef unsigned int u32;
typedef unsigned char u8;

extern void *ts4_memset(void *, int, u32);
extern int ts4_format_text(char *, unsigned, const char *, ...);
extern char lbl_880F6EB8[];

typedef struct Cx30FmtOwner { u8 pad[0x20]; u32 f20; u32 f24; u8 pad2[4]; u32 f2c; } Cx30FmtOwner;
typedef struct Cx30Sink { struct Cx30SinkV *vt; } Cx30Sink;
typedef struct Cx30SinkV { u8 pad[0x10]; void (*f10)(Cx30Sink *, char *, u32); } Cx30SinkV;

/* 0x8860DB48: format three fields of the owner into a 0x56-byte buffer and hand the text to the sink (vtable slot 4) */
void ts4_format_owner_fields_8860DB48(Cx30FmtOwner *o, Cx30Sink *s)
{
    char buf[0x56];
    u32 n;
    u32 c;
    u32 b;
    u32 a;
    ts4_memset(buf, 0, 0x56);
    c = o->f2c;
    b = o->f24;
    a = o->f20;
    n = ts4_format_text(buf, 0x56, lbl_880F6EB8, a, c, b);
    s->vt->f10(s, buf, n);
}
