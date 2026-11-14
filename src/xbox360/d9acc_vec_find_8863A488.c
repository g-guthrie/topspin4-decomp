/* Swing_DLL.xex 0x8863A488-0x8863A4C4, executable version 0.0.0.3. */
struct E{char p[8];unsigned k;char q[8];};struct S{char p[0x4a0];struct E*b;struct E*e;};
struct E*ts4_find_entry_by_id_8863A488(struct S*s,unsigned k){struct E*r=0;struct E*i;struct E*e=s->e;for(i=s->b;i!=e;++i){if(i->k==k){r=i;break;}}return r;}
