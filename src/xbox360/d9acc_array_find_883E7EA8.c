/* Swing_DLL.xex 0x883E7EA8-0x883E7EF4, executable version 0.0.0.3. */
struct E{unsigned k;int v;};struct S{char p[0x10];struct E*t;unsigned n;};
int ts4_lookup_value_883E7EA8(struct S*s,unsigned k){unsigned i=0;unsigned n=s->n;struct E*p;struct E*q;if(n!=0){p=s->t;q=p;do{if(q->k==k)return p[i].v;++i;++q;}while(i<n);}return 0;}
