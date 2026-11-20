typedef struct Self { char p0[0x68]; int a68; unsigned int a6c; int a70, a74, a78; char p7c[4]; int a80; char sub[0x31c-0x84]; unsigned int a31c; int a320; unsigned char b324; char p325[3]; int a328; } Self;
void fn_88222678(Self *s);
void fn_887481C0(void *p);
Self *ts4_ctor_render_state_887482D8(Self *s){ fn_88222678(s); s->a68 = -1; s->a6c = 0xFFFFFFFF; s->a70 = -1; s->a74 = -1; s->a78 = -1; s->a80 = -1; fn_887481C0(s->sub); s->a31c = 0xFFFFFFFF; s->a320 = 0; s->b324 = 0; s->a328 = 0; return s; }