/* agBA near-miss, 1 off: LTCG, ctx flags(/Ob1):src/xbox360/cx39_ctx_hash.c. Only the add operand order of t->rel + i*4 differs (target add r11,r6(i),r11(rel)). fn_POST is the 0x88002A00-area callee (placeholder name; get the real one from RENAME). */

typedef unsigned char u8; typedef unsigned int u32;
typedef struct { int rel; int n; } Tab;
typedef struct { char p[0x14]; char s14[0x14]; Tab *t; char p2c[0xc]; void *e38, *e3c, *e40; } Obj;
u32 *ts4_index_to_name_hash_887F7BC8(u32 *out, u8 index);
void fn_POST(void *p, int k, u32 *z);
void fn_887FAA48(Obj *o)
{
  Tab *t = o->t;
  if (t->n > 0) {
    int n = t->n;
    int i;
    for (i = 0; i < n; i++) {
      u8 *e = (u8 *)t + (i * 4 + t->rel);
      u32 h;
      u32 v = *ts4_index_to_name_hash_887F7BC8(&h, *e);
      switch (v) {
      case 0xBDC27917: o->e38 = e; break;
      case 0xB9D1485A: o->e3c = e; break;
      case 0x83060705: o->e40 = e; break;
      }
    }
  }
  {
    u32 z = 0;
    fn_POST(o->s14, 3, &z);
  }
}
