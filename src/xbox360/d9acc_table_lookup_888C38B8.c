/* Swing_DLL.xex 0x888C38B8-0x888C38E0, executable version 0.0.0.3. */
struct E{int a,b,c;};struct R{char a;unsigned char b;char c[6];};struct S{char p[0x18];struct E*t;char q[8];struct R*r;};
int ts4_indexed_entry_first_888C38B8(struct S*s,int i){return s->t[s->r[i].b].a;}
