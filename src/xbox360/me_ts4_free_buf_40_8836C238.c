/* 0x8836C238: frees the buffer at +0x40 of the outer object (file lbl_8802B82C, line 0x214) and clears it and the count at +0x20; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8802B82C[];
void fn_88315F10(void *heap, void *p, const char *file, int line);
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x20]; int n; char q[0x1c]; void *buf; } O;
int ts4_free_buf_40_8836C238(Base *b) { O *o = b ? (O *)((char *)b - 0x1c) : 0; if (o->buf) { fn_88315F10(lbl_88B3302C->heap, o->buf, lbl_8802B82C, 0x214); o->buf = 0; } o->n = 0; return 0; }
