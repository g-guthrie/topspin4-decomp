/* CW18 LTCG route, context: src/xbox360/cw1_ctx_format_text.c (varargs shape of ts4_format_text). Built with /Oc.
   Float zero stores read the shared pooled 0.0f constant; plain route only differs by that relocation name. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Cx18V3 { float x, y, z; } Cx18V3;
typedef struct Cx18F10 { float f[10]; } Cx18F10;

/* 0x88870A38: zero a 3-float vector */
void ts4_v3_zero_88870A38(Cx18V3 *v)
{
    v->x = 0.0f;
    v->y = 0.0f;
    v->z = 0.0f;
}

/* 0x88870A50, 0x88870A88, 0x88870FF0: zero ten floats */
#define CX18_ZERO10(NAME) \
void NAME(Cx18F10 *p) \
{ \
    p->f[0] = 0.0f; p->f[1] = 0.0f; p->f[2] = 0.0f; p->f[3] = 0.0f; p->f[4] = 0.0f; \
    p->f[5] = 0.0f; p->f[6] = 0.0f; p->f[7] = 0.0f; p->f[8] = 0.0f; p->f[9] = 0.0f; \
}
CX18_ZERO10(ts4_f10_zero_88870A50)
CX18_ZERO10(ts4_f10_zero_88870A88)
CX18_ZERO10(ts4_f10_zero_88870FF0)

/* ---- owner with an array of 0x84-byte elements at +0x84/+0x88; flag byte at +0x54, float at +0x74 ---- */
typedef struct Cx18Sub { u8 pad0[0x54]; u8 flag; u8 pad55[0x74 - 0x55]; float f74; u8 pad78[0x84 - 0x78]; } Cx18Sub;
typedef struct Cx18SubOwner { u8 pad0[0x54]; u8 flag; u8 pad55[0x74 - 0x55]; float f74; u8 pad78[0x84 - 0x78]; Cx18Sub *begin; Cx18Sub *end; } Cx18SubOwner;

/* 0x8886FF58: reset the flag and the float of the owner and every element */
void ts4_sub_reset_8886FF58(Cx18SubOwner *o)
{
    Cx18Sub *p = o->begin;
    Cx18Sub *end = o->end;
    o->flag = 0;
    o->f74 = 0.0f;
    for (; p != end; p++) {
        p->f74 = 0.0f;
        p->flag = 0;
    }
}

/* ---- portrait path builder ---- */
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern const char lbl_880DFEF0[]; /* Textures\%s_Portrait.dds */
extern const char lbl_880DFF38[]; /* Textures\Player_Portrait_%s.xpr */

/* 0x88864B28: format the portrait file path for the name, choosing the pattern by the flag */
void ts4_portrait_path_88864B28(char *out, const char *name, u8 per_player)
{
    if (per_player) ts4_format_text(out, 0x200, lbl_880DFEF0, name);
    else ts4_format_text(out, 0x200, lbl_880DFF38, name);
}
