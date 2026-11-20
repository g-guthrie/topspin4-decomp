/* 0x88671A98 (hand match). */
typedef unsigned int u32;
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void fn_8890DDA8(void *p);
extern void ts4_loop_get_u32_off10_88671A28(void *p);
typedef struct Vec { char *first; char *last; } Vec;
static __inline char *vcopy(char *first, char *last, char *dest)
{ if (first == last) { return dest; } else { u32 n = (u32)(last - first); dest = (char *)fn_88562DC0(dest, first, n); return dest + n; } }
struct Sub { char a[0x44]; char b[4]; };
struct Self { int f0, f4, f8, fc; Vec v; char p18[4]; struct Sub sub; char p[0x104-0x1c-0x48]; char o104[4]; };
void ts4_destroy_two_subs_88671A98(struct Self *s){ Vec *v; struct Sub *b; fn_8890DDA8(s->o104); b=&s->sub; fn_8890DDA8(b->b); fn_8890DDA8(b); ts4_loop_get_u32_off10_88671A28(s);
 v=&s->v; v->last = vcopy(v->last, v->last, v->first); s->fc=0; s->f4=0; s->f8=0; s->f0=0; }
