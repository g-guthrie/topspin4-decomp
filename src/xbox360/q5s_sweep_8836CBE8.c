/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8836CBE8: allocate n bytes from the global heap (line tag 0x14) and, on success with a counter object,
 * add n to its total at +0x500.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_8836CBE8_nearmiss.c (Q5S sweep, 2026-11-24): the alias local(s) of the parameter change which symbol the indexed access goes through (regalloc.md C1/R2).
 * See work/specs/Q5S/sweep_8836CBE8.json for route and flags. */
typedef struct Ts4HeapCtx { int a; void *heap; } Ts4HeapCtx;
extern Ts4HeapCtx *lbl_88B3302C;
extern const char lbl_8802B898[];
void *fn_88315C60(void *heap, unsigned size, const char *file, int line, int a, int b);
typedef struct { char p[0x500]; unsigned total; } Ts4AllocCounter;
void *ts4_alloc_count_500_8836CBE8(Ts4AllocCounter *s, unsigned n) { Ts4AllocCounter* self = s;  Ts4AllocCounter* self2 = self;  unsigned size = n;  void *p = fn_88315C60(lbl_88B3302C->heap, size, lbl_8802B898, 0x14, 0, 0); if (p && self2) self->total = size + self2->total; return p; }
