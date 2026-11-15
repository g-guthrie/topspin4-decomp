/* CX33: LTCG-only helper (Swing_DLL.xex 0x8890E810); context src/xbox360/cx33_ctx_e698.c supplies the callee body. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct I7Elem { u32 w0; u32 key; } I7Elem;
typedef struct I7Rel { int off; u32 count; } I7Rel;
typedef struct I7Src { u8 pad[0x1c]; I7Rel rel; } I7Src;
typedef struct I7Mid { u8 pad[4]; I7Src *src4; } I7Mid;
typedef struct I7Arg { u8 pad[8]; I7Mid *mid; u8 pad2[0x38 - 0xc]; u32 *out; } I7Arg;
typedef struct I7Self { u32 w0; } I7Self;
extern u32 fn_8890E698(I7Self *s, const u32 *key);

void ts4_fill_lookup_8890E810(I7Self *self, I7Arg *a)
{
    I7Rel *h = &a->mid->src4->rel;
    I7Elem *p, *end;
    u32 i;
    p = 0;
    if (h->off != -1)
        p = (I7Elem *)((char *)h + h->off);
    end = 0;
    if (h->off != -1)
        end = (I7Elem *)((char *)h + (h->count * 8 + h->off));
    i = 0;
    for (; p != end; p++, i++)
        { u32 r = fn_8890E698(self, &p->key); a->out[i] = r; }
}
