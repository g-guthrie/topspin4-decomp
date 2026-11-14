/* Swing_DLL.xex 0x8899CFC0-0x8899CFF0, executable version 0.0.0.3. */
struct P{char p[0x40];int v;};struct Q{char p[0x1d];unsigned char b;};struct S{char p[0x14];struct P*p14;char q[0x88];struct Q*pa0;};
unsigned char ts4_zero_or_flag_8899CFC0(struct S*s){return s->p14->v==0||s->pa0->b!=0;}
