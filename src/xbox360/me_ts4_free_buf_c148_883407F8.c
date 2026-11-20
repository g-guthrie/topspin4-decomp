/* 0x883407F8: frees the buffer at +0xC148 of the outer object (file lbl_8802A0A0, line 0x339) and clears it; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8802A0A0[];
void fn_88315F10(void *heap, void *p, const char *file, int line);
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0xc148]; void *buf; } O;
int ts4_free_buf_c148_883407F8(Base *b) { void **pb; O *o = b ? (O *)((char *)b - 0x1c) : 0; pb = &o->buf; if (*pb) { fn_88315F10(lbl_88B3302C->heap, *pb, lbl_8802A0A0, 0x339); *pb = 0; } return 0; }
