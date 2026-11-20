/* 0x88396180: frees and clears the eight buffers at +0x2d4 (file lbl_8802E890, line 0xEF) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8802E890[];
void fn_88315F10(void *heap, void *p, const char *file, int line);
typedef struct { char p[0x2d4]; void *buf[8]; } S;
void ts4_free_bufs8_2d4_88396180(S *s) { int i; for (i = 0; i < 8; i++) { if (s->buf[i]) fn_88315F10(lbl_88B3302C->heap, s->buf[i], lbl_8802E890, 0xef); s->buf[i] = 0; } }
