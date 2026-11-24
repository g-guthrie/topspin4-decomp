/* Pass/material drawability test: rejects materials with unset slots (-1), lazily resolves the pass resource
 * (key 0xE6BEB2A1), then for lit materials requires both texture handles and an idle context. LTCG. */
typedef unsigned int u32; typedef unsigned char u8;
typedef struct { char p[0x6a4]; u8 busy; } Ctx;
typedef struct { char p0[0x30]; Ctx *ctx; u32 *t34; u8 *res; char p3c[0x14]; u32 *t50; u32 *t54; } Pass;
typedef struct { char p0[0x24]; int a; int b; char p2c[0x68]; int *c94; char p98[0x1c]; int *cb4; u8 pb8; u8 lit; } Mat;
u8 *ts4_find_typed_entry_88781930(u32 *key);
u8 ts4_pass_mat_drawable_88714F10(Pass *s, Mat *m)
{
  u8 busy, hb4, h94;
  if (m->a == -1 || m->b == -1) return 0;
  if (!s->res) { u32 k = 0xE6BEB2A1; s->res = ts4_find_typed_entry_88781930(&k); }
  busy = s->ctx->busy;
  hb4 = m->cb4 && *m->cb4 != 0;
  if (m->lit) {
    h94 = m->c94 && *m->c94 != 0;
    return hb4 && h94 && !busy && (!*s->res || *s->t50 == 0x1DCA7285 || *s->t54 == 0x1DCA7285);
  }
  return hb4 && !busy && !*s->res && *s->t34 != 0x165BBDE9;
}
