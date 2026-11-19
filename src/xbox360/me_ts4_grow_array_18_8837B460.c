/* 0x8837B460: doubles the capacity (+0x1c) of the pointer array at +0x18 with a heap realloc (file lbl_8802BE58, line 0xD6); returns 0x2c on failure */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8802BE58[];
void *fn_88316070(void *heap, void *p, unsigned size, const char *file, int line, int a);
typedef struct { char p[0x18]; void **buf; unsigned cap; } S;
int ts4_grow_array_18_8837B460(S *s) { void *p; s->cap = s->cap * 2; p = fn_88316070(lbl_88B3302C->heap, s->buf, s->cap * 4, lbl_8802BE58, 0xd6, 0); s->buf = p; return p ? 0 : 0x2c; }
