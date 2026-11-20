/* agAM: 2 off (plain and LTCG). Only the frame size differs (target 0x80, ours 0x60); the body matches. Formats text into o->b->buf+0x7CC with lbl_880D1B40 and returns 1. */
typedef unsigned char u8; typedef unsigned int u32;
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...); extern const char lbl_880D1B40[];
typedef struct { char p[0x7cc]; char buf[0x100]; } B; typedef struct { char p[0x1c]; B *b; } O;
u8 f(O *o, const char *s){ ts4_format_text(o->b->buf, 0x100, lbl_880D1B40, s); return 1; }
