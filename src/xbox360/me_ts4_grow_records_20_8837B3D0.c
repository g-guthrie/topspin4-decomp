/* 0x8837B3D0: doubles the record capacity (+0x30, 0x3d bytes each plus a 0x11 header) with a heap realloc (file lbl_8802BE58, line 0xC8); returns 0x2c on failure */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8802BE58[];
void *fn_88316070(void *heap, void *p, unsigned size, const char *file, int line, int a);
typedef struct { char p[0x20]; char *buf; char *first; char *data; int q; unsigned cap; } S;
int ts4_grow_records_20_8837B3D0(S *s) { char *p; int r; s->cap = s->cap * 2; p = fn_88316070(lbl_88B3302C->heap, s->buf, s->cap * 0x3d + 0x11, lbl_8802BE58, 0xc8, 0); s->buf = p; r = p ? 0 : 0x2c; if (!r) { s->first = p; s->data = p + 0x11; } return r; }
