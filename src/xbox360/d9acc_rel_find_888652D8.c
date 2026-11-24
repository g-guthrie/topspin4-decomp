/* Swing_DLL.xex 0x888652D8-0x88865320, executable version 0.0.0.3. */
struct R{unsigned k;int a,b;};struct S{char p[0x84];struct R*b;struct R*e;};
int ts4_entry_enabled_888652D8(struct S*s,unsigned k){struct R*i;for(i=s->b;i!=s->e;++i)if(k==i->k)break;if(i!=s->e)return i->b!=0;return 1;}
