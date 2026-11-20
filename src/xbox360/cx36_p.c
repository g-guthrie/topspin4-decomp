/* CX36: range anchor with three kind hashes, Swing_DLL.xex 0x88925270 (look-alike of 0x88924FA0 in cx36_l.c). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Cx36V3 { u32 a, b, c; } Cx36V3;
typedef struct Cx36Kind { u8 pad[0x14]; u32 hash; } Cx36Kind;
typedef struct Cx36A { u8 pad[0xc]; char *w0c; u32 **p10; } Cx36A;
typedef struct Cx36Anch { u8 pad[0xc]; Cx36Kind *kind; Cx36A *inner; } Cx36Anch;
typedef struct Cx36AnchSrc { u8 pad[8]; u32 w8; } Cx36AnchSrc;

/* 0x88925270 */
void ts4_range_anchor3_88925270(Cx36Anch *o, Cx36AnchSrc *src, u32 base, Cx36V3 *out)
{
    u32 a = (u32)(unsigned long)(o->inner->w0c + 0x28);
    if (o->kind->hash == 0x59BC5767) {
        out->b = 0xFFFFF;
    } else {
        out->b = base + 4;
        if (o->kind->hash == 0xC0B506DD)
            a = (*o->inner->p10)[2];
        else if (o->kind->hash == 0xB7B2364B)
            a = (*o->inner->p10)[1];
    }
    out->a = a;
    out->c = src->w8;
}
