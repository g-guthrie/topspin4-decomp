/* NEAR MISS 0x8836CBE8 (fn_8836CBE8), /Oc: 1 off, add r11,r30,r11 (n + total) vs ours total + n. += and n + total both give ours; operand_order_pad 0-8 no change; LTCG same (agU 2026-11-19, work/army/ME/v.py chk, matching-b154). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8802B898[];
void *fn_AAA(void *heap, unsigned size, const char *file, int line, int a, int b);
typedef struct { char p[0x500]; unsigned total; } S;
void *ts4_alloc_count_500_8836CBE8(S *s, unsigned n) { void *p = fn_AAA(lbl_88B3302C->heap, n, lbl_8802B898, 0x14, 0, 0); if (p && s) s->total = n + s->total; return p; }
