/* 0x8836D0C8: clears the handle at +0x118 of the outer object and passes it to the release call; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x118]; int h; } O;
void aud1_ov_clear_883A9440(O *o, int *h);
int ts4_reset_handle_118_8836D0C8(Base *b) { O *o = b ? (O *)((char *)b - 0x1c) : 0; o->h = 0; aud1_ov_clear_883A9440(o, &o->h); return 0; }
