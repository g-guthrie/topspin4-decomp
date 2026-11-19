/* Swing_DLL.xex 0x888C2FD8: record of the owner whose record key equals k, or 0 */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
/* Finds the owner whose record key equals k and returns its record, or 0. */
struct Q{char p[0x24];unsigned k;};struct O{char p[8];struct Q*q;};struct S{char p[0x268];struct O**b;struct O**e;};
static __forceinline struct O*find_owner(struct S*s,unsigned k){struct O**e=s->e;struct O**i=s->b;for(;e!=i;++i){if(k==(*i)->q->k)return *i;}return 0;}
struct Q*fn_888C2FD8(struct S*s,unsigned k){struct Q*q=0;struct O*o=find_owner(s,k);if(o)q=o->q;return q;}
