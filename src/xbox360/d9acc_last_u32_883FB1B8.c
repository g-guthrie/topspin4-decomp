/* Swing_DLL.xex 0x883FB1B8-0x883FB1E8, executable version 0.0.0.3. */
struct S{char p[0x14];unsigned n;char q[4];unsigned long long*a;};
unsigned ts4_last_low_word_883FB1B8(struct S*s){if(s->n!=0){unsigned long long v=s->a[s->n-1];return ((unsigned*)&v)[1];}return 0;}
