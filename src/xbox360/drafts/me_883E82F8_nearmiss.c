/* NEAR MISS 0x883E82F8 (fn_883E82F8), /O1: 2 instructions swapped. The target emits the dead addi r11,r4,0x14 before the first lbz; ours puts it after. Tried: field copy, pointer local, inline helper, return by value, C++, /Oc /Os /O2, LTCG (agU 2026-11-19, work/army/ME/v.py chk, matching-b154). */
typedef struct { unsigned char a, b; } P;
typedef struct { char pad[0x14]; P p; } S;
void ts4_nearmiss_883E82F8(P *d, S *s) { *d = s->p; }
