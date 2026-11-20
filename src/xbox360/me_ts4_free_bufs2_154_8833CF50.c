/* 0x8833CF50: frees the two buffers at +0x154 (file lbl_88029A20, line 0xB3), clearing each and its count at +0x14c; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88029A20[];
void fn_88315F10(void *heap, void *p, const char *file, int line);
typedef struct { char p[0x14c]; int n[2]; void *buf[2]; } S;
int ts4_free_bufs2_154_8833CF50(S *s) { int i; for (i = 0; i < 2; i++) { if (s->buf[i]) { fn_88315F10(lbl_88B3302C->heap, s->buf[i], lbl_88029A20, 0xb3); s->buf[i] = 0; s->n[i] = 0; } } return 0; }
