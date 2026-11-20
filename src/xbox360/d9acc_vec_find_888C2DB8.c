/* Swing_DLL.xex 0x888C2DB8-0x888C2DF8, executable version 0.0.0.3. */
struct E{int v;char p[0x48];unsigned k;};struct P{char p[0x2c];struct E*b;struct E*e;};struct S{char p[0x20];struct P*q;};
int ts4_find_value_by_key_50_888C2DB8(struct S*s,unsigned*k){int r=0;struct E*i=s->q->b;struct E*e=s->q->e;for(;e!=i;++i){if(*k==i->k){r=i->v;break;}}return r;}
