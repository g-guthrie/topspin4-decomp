/* 0x889170B8: writes four settings into a hashed record: +0xc copies s->a, +0x10 takes one of two
 * hashes for s->b == 0 / != 0, and the self-relative value table at d+d->rel gets s->c and s->d, each with a
 * 0x317C51B7 / 0xA2EDA1E7 hash chosen by its own flag (agAT, plain /Oc). The +0x10 store goes through a
 * pointer local so the d->rel load stays after it. */
typedef struct { char p[0x42c]; int a; int b; int c; int d; int e; int f; } TS4SetSrc889170B8;
typedef struct { int v; unsigned int k; } TS4HashedVal;
typedef struct { int rel; char p[8]; int a; unsigned int bk; } TS4SetDst889170B8;
void ts4_settings_write_889170B8(TS4SetSrc889170B8 *s, TS4SetDst889170B8 *d) {
  TS4HashedVal *kv; unsigned int t, f;
  d->a = s->a;
  { unsigned int *p = &d->bk; if (s->b == 0) *p = 0x23BAED9E; else *p = 0xD826E563; }
  t = 0x317C51B7; kv = (TS4HashedVal *)((char *)d + d->rel); f = 0xA2EDA1E7;
  kv[0].v = s->c;
  if (s->e == 0) kv[0].k = f; else kv[0].k = t;
  kv = (TS4HashedVal *)((char *)d + d->rel);
  kv[1].v = s->d;
  if (s->f == 0) kv[1].k = f; else kv[1].k = t;
}
