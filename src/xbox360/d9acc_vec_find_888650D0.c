/* Swing_DLL.xex 0x888650D0-0x88865118, executable version 0.0.0.3. */
struct O{char p[0x180];int k;};struct S{char p[0x1c];int n;struct O**b;struct O**e;};
struct O*ts4_find_by_index_888650D0(struct S*s){struct O*r=0;struct O**e=s->e;struct O**i=s->b;int n=s->n;for(;i!=e;++i){struct O*o=*i;if(o->k==n-1){r=o;break;}}return r;}
