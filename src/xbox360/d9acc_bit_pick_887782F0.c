/* Swing_DLL.xex 0x887782F0-0x88778314, executable version 0.0.0.3. */
struct S{char p[0x80];int k;};struct T{unsigned short h;unsigned short x;};
unsigned ts4_bit_pick_zero_887782F0(struct S*s,struct T*t,int i){if(s->k==0)return (t[i+0xc].h>>7)&1;return (t[i+0xc].h>>6)&1;}
