/* agBI near-miss: fn_88224728 vertex-declaration builder, plain /Oc, 2 off.
 * Remaining diff: target schedules `addi r3,r1,0x50` (arg of fn_88714730) before `sth r31,0x7c(r1)`;
 * candidate swaps them. Aggregate initializer, init helper, .cpp, decl order did not change it.
 * Key fix vs agBG (35 off): 12-byte element is {u16,u16,u32,u8,u8,u8}; copy with
 * `{ W3 t = *(W3*)s; *(W3*)p = t; }` (3-word struct temp) gives load-all-then-store and no end reload.
 * Twins 887323F8 and 88224728 (1.00) give the same 2-off diff with this body (callee names not verified).
 */

typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 stream, off; u32 fmt; u8 method, usage, idx; } El;
typedef struct { u32 w[3]; } W3;
typedef struct { El *first; El *last; u32 x; El *cap; u32 pad[4]; } V;
void fn_88714730(V *v);
void ts4_vector_grow_append_88226CF8(V *v, El *at, const El *x);
u32 fn_887312A8(void *c, V *v);
void fn_886F79F8(V *v);
extern char *lbl_88D45AD4;
typedef struct { u32 a; u32 b; u32 pad[1]; u32 c; u32 pad2[10]; u32 d; } Out;
void fn_88224728(void *self, Out *o) {
  El e[4]; V v; El *s; int n; El *p;
  e[0].stream=0; e[0].off=0; e[0].fmt=0x2A23B9; e[0].method=0; e[0].usage=0; e[0].idx=0;
  e[1].stream=0; e[1].off=0xc; e[1].fmt=0x2C23A5; e[1].method=0; e[1].usage=5; e[1].idx=0;
  e[2].stream=0; e[2].off=0x14; e[2].fmt=0x182886; e[2].method=0; e[2].usage=0xa; e[2].idx=0;
  e[3].stream=0xff; e[3].off=0; e[3].fmt=0xFFFFFFFF; e[3].method=0; e[3].usage=0; e[3].idx=0;
  fn_88714730(&v);
  p = v.last; s = e; n = 4;
  do {
    if (p != v.cap) { if (p) { W3 t = *(W3*)s; *(W3*)p = t; } p++; v.last = p; }
    else { ts4_vector_grow_append_88226CF8(&v, p, s); p = v.last; }
    s++;
  } while (--n);
  o->b = fn_887312A8(*(char**)(lbl_88D45AD4+0x24)+0x84, &v);
  o->a = 0; o->c = 0x18; o->d = 0x15;
  fn_886F79F8(&v);
}
