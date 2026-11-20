/* Swing_DLL.xex 0x883C6EE0-0x883C6F08, executable version 0.0.0.3. */
struct P{char p[0x1c];int n;};struct S{char p[0x68];int v;char q[0x3c];struct P*pp;};
unsigned char ts4_is_full_mask_883C6EE0(struct S*s){return s->v==((1<<s->pp->n)-1);}
