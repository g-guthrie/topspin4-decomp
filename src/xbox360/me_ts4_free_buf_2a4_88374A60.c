/* 0x88374A60: publishes the context (+0x18), frees the buffer at +0x2a4 of the outer object (file lbl_8802BA68, line 0xDD) and clears it; returns 0 */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8802BA68[];
void fn_88315F10(void *heap, void *p, const char *file, int line);
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x18]; Ctx *ctx; char q[0x2a4 - 0x1c]; void *buf; } O;
int ts4_free_buf_2a4_88374A60(Base *b) { O *o = b ? (O *)((char *)b - 0x1c) : 0; lbl_88B3302C = o->ctx; if (o->buf) fn_88315F10(lbl_88B3302C->heap, o->buf, lbl_8802BA68, 0xdd); o->buf = 0; return 0; }
