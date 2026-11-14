/* Swing_DLL.xex 0x887F7548-0x887F7588, executable version 0.0.0.3. */
struct E{unsigned k;int v;};struct S{char p[0x48];struct E*b;struct E*e;};
int ts4_find_value_by_key_887F7548(struct S*s,unsigned*k){int r=0;struct E*i;for(i=s->b;i!=s->e;++i){if(i->k==*k){r=i->v;break;}}return r;}
