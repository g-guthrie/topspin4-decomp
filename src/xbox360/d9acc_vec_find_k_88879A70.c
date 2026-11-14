/* Swing_DLL.xex 0x88879A70-0x88879AA8, executable version 0.0.0.3. */
struct O{char p[0x1c];unsigned k;};struct S{char p[0x28];struct O**b;struct O**e;};
struct O*ts4_find_by_key_88879A70(struct S*s,unsigned*k){struct O**i;for(i=s->b;i!=s->e;++i){struct O*o=*i;if(*k==o->k)return o;}return 0;}
