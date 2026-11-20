/* 0x883EEAB8: allocates through the allocator object when given, else from the heap (file lbl_88039C34, line 0x4E) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039C34[];
void *fn_88315C60(void *heap, unsigned size, const char *file, int line, int a, int b);
typedef struct A { struct AVT *vt; } A;
typedef struct AVT { void *(*alloc)(A *, unsigned, int, int, int); } AVT;
void *ts4_alloc_via_or_heap_883EEAB8(A *a, unsigned size, int b, int c) { if (a) return a->vt->alloc(a, size, 0, b, c); return fn_88315C60(lbl_88B3302C->heap, size, lbl_88039C34, 0x4e, 0, 0); }
