/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x888C2860: formats the string argument with lbl_880D1B40 into the 0x100-byte buffer at o->b + 0x7CC; returns 1.
 * Source: drafts/me_888C2860_nearmiss_agAM.c (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_888C2860.json for route and flags. */
typedef unsigned char u8; typedef unsigned int u32;
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...); extern const char lbl_880D1B40[];
typedef struct { char p[0x7cc]; char buf[0x100]; } Ts4TextHolder; typedef struct { char p[0x1c]; Ts4TextHolder *b; } Ts4TextOwner;
u8 ts4_format_owner_text_888C2860(Ts4TextOwner *o, const char *s){ ts4_format_text(o->b->buf, 0x100, lbl_880D1B40, s); return 1; }
