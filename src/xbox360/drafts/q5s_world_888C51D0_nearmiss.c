/* nearmiss: 12 off; only the lower-bound constant load (lfs f13, script_constants+0x38c) is hoisted above the counter
 * increment in the target. Local/hoisted constant, helper range check, inc helper: 11-12 off. */
/* 0x888C51D0: look up the bank value for the selected (row, col) of the self-relative row table at tab(+0x28)+0x50,
 * count it in count[k] (+0xa0), and clear live[k] (+0x98) when the selection value (+0xec) is out of range. */
extern const float g_ts4_script_constants[];
typedef struct Rel { int off; } Rel;
typedef struct Row { Rel items; int pad[3]; } Row;
typedef struct Tab { char p[0x50]; Rel rows; } Tab;
typedef struct Sel { char p[0xec]; float v; char p2[0x190 - 0xf0]; int row; int col; } Sel;
typedef struct O { char p[0x28]; Tab *tab; char p2c[8]; Sel *sel; char p38[0x98 - 0x38]; unsigned char live[8]; int count[8]; } O;
static Row *row_at(Rel *r, int i){ return (Row *)((char *)r + (i * 16 + r->off)); }
static int item_at(Row *r, int i){ return *(int *)((char *)r + (i * 4 + r->items.off)); }
static int in_range(float v){ return v >= g_ts4_script_constants[0x38c / 4] && v <= g_ts4_script_constants[0x10c / 4]; }
void ts4_bank_count_selected_888C51D0(O *o){ float v; int k = item_at(row_at(&o->tab->rows, o->sel->row), o->sel->col);  o->count[k]++; v = o->sel->v; if (v < g_ts4_script_constants[0x38c / 4] || v > g_ts4_script_constants[0x10c / 4]) o->live[k] = 0; }
