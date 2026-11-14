/* Swing_DLL.xex 0x8860EEA0-0x8860EED0, executable version 0.0.0.3. */
#define MIN(a,b) ((a)<(b)?(a):(b))
struct S{char p[0x14];int a;int lim;};
int ts4_clamped_length_8860EEA0(struct S*s,int x){int r=0;if(s->a>=0){r=MIN(s->a+x,s->lim)-s->a;}return r;}
