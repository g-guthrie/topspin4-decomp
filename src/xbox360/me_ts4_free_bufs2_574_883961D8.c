/* 0x883961D8: frees and clears the two buffers at +0x574 (file lbl_8802E890, line 0xFC) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8802E890[];
void fn_88315F10(void *heap, void *p, const char *file, int line);
typedef struct { char p[0x574]; void *buf[2]; } S;
void ts4_free_bufs2_574_883961D8(S *s) { int i; for (i = 0; i < 2; i++) { if (s->buf[i]) fn_88315F10(lbl_88B3302C->heap, s->buf[i], lbl_8802E890, 0xfc); s->buf[i] = 0; } }
