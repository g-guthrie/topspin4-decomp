/* 0x8836D120: calls the open on the handle at +0x118 with a 64-bit size; maps -0x8b to 0x2c and other failures to 0x14 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x118]; int h; } O;
int fn_883A9F50(O *o, int *h, unsigned __int64 n);
int ts4_open_handle_118_8836D120(Base *b, int unused, unsigned n) { int r; O *o = b ? (O *)((char *)b - 0x1c) : 0; r = fn_883A9F50(o, &o->h, n); if (r < 0) { if (r == -0x8b) return 0x2c; return 0x14; } return 0; }
