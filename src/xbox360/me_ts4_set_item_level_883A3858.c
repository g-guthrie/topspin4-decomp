/* 0x883A3858: stores x (0..1) as the level (+0x270) of item i of the outer object; returns 0x25 when out of range */
/* Matched on /Oc plain only (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x270]; float level; } It;
typedef struct { char p[0x31c]; int n; It *items[1]; } O;
int ts4_set_item_level_883A3858(Base *b, int i, float x) { O *o = b ? (O *)((char *)b - 0x1c) : 0; if (i >= 0 && i < o->n && x >= 0.0f && x <= 1.0f) { o->items[i]->level = x; return 0; } return 0x25; }
