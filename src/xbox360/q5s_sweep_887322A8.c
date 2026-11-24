/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x887322A8: vertex-declaration builder: four 12-byte elements (FLOAT3 position at 0, FLOAT2 texcoord at 0xC, D3DCOLOR at 0x14, end marker)
 * are appended to a temporary vector, the declaration is created through the device (lbl_88D45AD4->+0x24, +0x84) and the result,
 * stride 0x18 and count 0x15 are stored in the output. Identical bodies: 0x88224728, 0x887322A8, 0x887323F8.
 * Source: drafts/me_887322A8_nearmiss_agBI.c (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_887322A8.json for route and flags. */
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct { u16 stream, off; u32 fmt; u8 method, usage, idx; } Ts4VertexElement;
typedef struct { u32 w[3]; } Ts4VertexElementWords;
typedef struct { Ts4VertexElement *first; Ts4VertexElement *last; u32 x; Ts4VertexElement *cap; u32 pad[4]; } Ts4VertexElementVec;
void ts4_call_seq_fn_88255AA0_88714730(Ts4VertexElementVec *v);
void ts4_vector_grow_append_88226CF8(Ts4VertexElementVec *v, Ts4VertexElement *at, const Ts4VertexElement *x);
u32 fn_887312A8(void *c, Ts4VertexElementVec *v);
void fn_886F79F8(Ts4VertexElementVec *v);
extern char *lbl_88D45AD4;
typedef struct { u32 a; u32 b; u32 pad[1]; u32 c; u32 pad2[10]; u32 d; } Ts4VertexDeclOut;
void ts4_vdecl_build_pos_uv_color_887322A8(void *self, Ts4VertexDeclOut *o) {
  Ts4VertexElement e[4]; Ts4VertexElementVec v; Ts4VertexElement *s; int n; Ts4VertexElement *p;
  e[0].stream=0; e[0].off=0; e[0].fmt=0x2A23B9; e[0].method=0; e[0].usage=0; e[0].idx=0;
  e[1].stream=0; e[1].off=0xc; e[1].fmt=0x2C23A5; e[1].method=0; e[1].usage=5; e[1].idx=0;
  e[2].stream=0; e[2].off=0x14; e[2].fmt=0x182886; e[2].method=0; e[2].usage=0xa; e[2].idx=0;
  e[3].stream=0xff; e[3].off=0; e[3].fmt=0xFFFFFFFF; e[3].method=0; e[3].usage=0; e[3].idx=0;
  ts4_call_seq_fn_88255AA0_88714730(&v);
  p = v.last; s = e; n = 4;
  do {
    if (p != v.cap) { if (p) { Ts4VertexElementWords t = *(Ts4VertexElementWords*)s; *(Ts4VertexElementWords*)p = t; } p++; v.last = p; }
    else { ts4_vector_grow_append_88226CF8(&v, p, s); p = v.last; }
    s++;
  } while (--n);
  o->b = fn_887312A8(*(char**)(lbl_88D45AD4+0x24)+0x84, &v);
  o->a = 0; o->c = 0x18; o->d = 0x15;
  fn_886F79F8(&v);
}
