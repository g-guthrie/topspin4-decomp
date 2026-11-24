/* Swing_DLL.xex 0x887782C8-0x887782EC, executable version 0.0.0.3. */
struct S{char p[0x80];int k;};struct T{unsigned short h;unsigned short x;};
unsigned ts4_bit_pick_k_887782C8(struct S*s,struct T*t,int i,int k){if(s->k==k)return (t[i+0xc].h>>7)&1;return (t[i+0xc].h>>6)&1;}
