/* 0x883471D0: frees the buffer at +0x204 of the outer object (file lbl_8802AA4C, line 0xD7) and clears it and the count at +0x200; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8802AA4C[];
void fn_88315F10(void *heap, void *p, const char *file, int line);
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x200]; int n; void *buf; } O;
int ts4_free_buf_204_883471D0(Base *b) { O *o = b ? (O *)((char *)b - 0x1c) : 0; if (o->buf) { fn_88315F10(lbl_88B3302C->heap, o->buf, lbl_8802AA4C, 0xd7); o->n = 0; o->buf = 0; } return 0; }
