typedef struct State { char p0[0x68]; int a68; unsigned int a6c; int a70; char p74[4]; int a78; char p7c[4]; int a80; char p84[0x324-0x84]; unsigned char b324; char p325[7]; int a32c; } State;
typedef struct Self { char p0[0x10]; void *m10; State *st; void *m18; char p1c[0x10]; void *m2c; } Self;
void fn_8871EA50(void *p);
void fn_88739110(void *p);
void fn_886EC870(void *p);
void ts4_reset_render_state_8873B6E8(Self *s){ State *st = s->st; st->a68 = -1; st->a6c = 0xFFFFFFFF; st->a70 = -1; st->a78 = -1; st->a80 = -1; st->b324 = 1; st->a32c = 0;
 fn_8871EA50(s->m18); fn_88739110(s->m10); fn_886EC870(s->m2c); }