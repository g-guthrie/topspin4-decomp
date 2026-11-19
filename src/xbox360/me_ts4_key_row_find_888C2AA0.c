/* 0x888C2AA0: returns the row (0 or 1) of the self-relative key table at s+0x220 whose key list holds key,
 * or 0. The rows hold one key, or two when s->kind is 0xDD4BF7D9 (agAT, plain /Oc). */
typedef struct { int off; int pad[3]; } TS4KeyRow;
typedef struct { char p[0x220]; int rel; char q[8]; unsigned int kind; } TS4KeyRowSet;
typedef struct { char p[0x154]; TS4KeyRowSet *s; } TS4KeyRowOwner;
int ts4_key_row_find_888C2AA0(TS4KeyRowOwner *o, int key) {
  TS4KeyRowSet *s = o->s; int n = 1; int r, j;
  if (s->kind == 0xDD4BF7D9) n = 2;
  for (r = 0; r < 2; r++) {
    for (j = 0; j < n; j++) {
      int *b = &s->rel;
      TS4KeyRow *row = (TS4KeyRow *)((char *)b + *b + r * 16);
      if (key == ((int *)((char *)row + row->off))[j]) return r;
    }
  }
  return 0;
}
