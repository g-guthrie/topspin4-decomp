/* 0x8836CCD8: reallocates old to n bytes (file lbl_8802B898, line 0x3B), keeping the running byte total at +0x500 (old size read from the block header at -0x10) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8802B898[];
void *fn_88316070(void *heap, void *p, unsigned size, const char *file, int line, int a);
typedef struct { char p[0x500]; unsigned total; } S;
void *ts4_realloc_count_500_8836CCD8(S *s, void *old, unsigned n) { void *p; if (old && s) s->total -= ((unsigned *)old)[-4]; p = fn_88316070(lbl_88B3302C->heap, old, n, lbl_8802B898, 0x3b, 0); if (p && s) s->total += n; return p; }
