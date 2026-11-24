/* CW2 batch e: chunk reader helpers (Swing_DLL.xex). */
typedef unsigned char cw2_u8;
#ifdef _MSC_VER
extern char *strcpy(char *, const char *);
extern char *strcat(char *, const char *);
#pragma intrinsic(strcpy, strcat)
#else
#include <string.h>
#endif

struct Cw2Chunk {
    int pad0;
    int pos;
    int pad1;
    cw2_u8 flag;
};
struct Cw2Reader {
    cw2_u8 pad[0x70];
    struct Cw2Chunk sub;
};

void ts4_chunk_reader_read_8816B5A8(struct Cw2Chunk *c, int *pos);

/* Swing_DLL.xex 0x881649B0: read the pending chunk header when the flag is set, then skip 8 bytes and round the position */
int ts4_cw2_reader_skip_header_881649B0(struct Cw2Reader *r)
{
    struct Cw2Chunk *c = &r->sub;
    if (c->flag != 0) {
        int p = c->pos;
        ts4_chunk_reader_read_8816B5A8(c, &p);
    }
    if (c->flag != 0) {
        int p = c->pos + 8;
        c->pos = p;
        if (p - (p / 4) * 4 != 0)
            c->pos = p + 4;
    }
    return 1;
}

/* Swing_DLL.xex 0x881654A8: strcpy(dst, a); strcat(dst, b); strcat(dst, c); strcat(dst, d); strcat(dst, literal) */
extern char lbl_880D35C4[];
void ts4_cw2_strcat5_881654A8(char *dst, const char *a, const char *b, const char *c, const char *d)
{
    strcpy(dst, a);
    strcat(dst, b);
    strcat(dst, c);
    strcat(dst, d);
    strcat(dst, lbl_880D35C4);
}

/* Swing_DLL.xex 0x8815FBE0: all eight byte-range members of two records compare equal */
cw2_u8 fn_88162C60(const void *a, const void *b);
int ts4_cw2_ranges_equal_8815FBE0(const char *a, const char *b)
{
    if (fn_88162C60(a + 0xc, b + 0xc) && fn_88162C60(a, b) && fn_88162C60(a + 0x18, b + 0x18)
        && fn_88162C60(a + 0x34, b + 0x34) && fn_88162C60(a + 0x4c, b + 0x4c)
        && fn_88162C60(a + 0x58, b + 0x58) && fn_88162C60(a + 0x6c, b + 0x6c)
        && fn_88162C60(a + 0x78, b + 0x78))
        return 1;
    return 0;
}
