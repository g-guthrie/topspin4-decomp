/* Swing_DLL.xex 0x888C2F90-0x888C2FD4, executable version 0.0.0.3. */
struct Q{char p[0x24];unsigned k;};struct O{char p[8];struct Q*q;};struct S{char p[0x268];struct O**b;struct O**e;};
struct O*ts4_find_owner_by_key_888C2F90(struct S*s,unsigned k){struct O*r=0;struct O**e=s->e;struct O**i=s->b;for(;e!=i;++i){struct O*o=*i;if(k==o->q->k){r=o;break;}}return r;}
