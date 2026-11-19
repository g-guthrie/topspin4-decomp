/* Twin of 0x887F81B0 (ts4_u32_vec_push_8861AA20 in src/xbox360/cx40_a.c). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Cx40Vt { void *s[64]; } Cx40Vt;
typedef struct Cx40Obj { void **vt; } Cx40Obj;
typedef struct Cx40VtKey { void *s[13]; void (*s34)(void *, void *); void *s38[2]; void (*s40)(void *, void *); } Cx40VtKey;
extern void *fn_887F0CA0(void *, void *);
extern char lbl_88C6C014[];
typedef struct Cx40Vt28 { void *s[10]; u8 (*s28)(void *, void *, void *, void *); } Cx40Vt28;
extern void fn_887EA898(void *, void *);
extern void ts4_if_call_seq_u32_off0_887D3C88(void *, void *);
extern void *fn_887D02A8(void *, int, int, int, int, int);
extern u32 fn_8857B6D8(u32, u32, u32, u32);
typedef struct Cx40B { u8 a, b; u8 pad[2]; u32 c, d; } Cx40B;
typedef struct Cx40PVv { u32 *first, *last, *cap; } Cx40PVv;
extern void ts4_vector_grow_append_scalar4_88174A38(Cx40PVv *, u32 *, u32 *);

/* 0x8861AA20: push one u32 onto the vector at +0x3c. */
void ts4_u32_vec_push_8861AA20(char *self, u32 val)
{
    Cx40PVv *v = (Cx40PVv *)(self + 0x14b4);
    u32 *last = v->last;
    if (last != v->cap) {
        if (last) *last = val;
        v->last++;
    } else {
        ts4_vector_grow_append_scalar4_88174A38(v, last, &val);
    }
}
