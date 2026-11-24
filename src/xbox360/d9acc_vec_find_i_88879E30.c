/* Swing_DLL.xex 0x88879E30-0x88879E64, executable version 0.0.0.3. */
struct O{char p[0x44];int k;};struct S{char p[0x1c];struct O**b;struct O**e;};
struct O*ts4_find_by_id_88879E30(struct S*s,int k){struct O**i;for(i=s->b;i!=s->e;++i){struct O*o=*i;if(o->k==k)return o;}return 0;}
