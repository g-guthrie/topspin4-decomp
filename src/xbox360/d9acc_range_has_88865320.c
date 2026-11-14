/* Swing_DLL.xex 0x88865320-0x88865358, executable version 0.0.0.3. */
struct R{unsigned k;int a,b;};struct S{char p[0x84];struct R*b;struct R*e;};
int ts4_has_key_88865320(struct S*s,unsigned k){struct R*i;for(i=s->b;i!=s->e;++i)if(k==i->k)break;return i!=s->e;}
