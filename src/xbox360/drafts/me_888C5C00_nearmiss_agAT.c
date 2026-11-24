/* NEAR-MISS (agAT): 0x888C5C00, 2 off. LTCG with ctx flags(/Ob1):src/xbox360/pr2_signin.c (f1/f2 live across
 * ts4_pad_record_find_88614938). Only diff: target `fmuls f13,f2,f0` / `fmuls f12,f1,f0`; every operand order,
 * inline helper and /Ox build gives `fmuls fX,f0,fN`. Converts a stick (x,y) to u16 and sends it to the pad. */

typedef struct { char p[0x10]; int id; } PadRec;
typedef struct ModList ModList;
typedef struct { char p[0x234]; ModList *modules; } Engine;
extern Engine *lbl_88D45B1C;
extern char g_ts4_script_constants[];
PadRec *ts4_pad_record_find_88614938(ModList *m, int pad);
int ts4_if_call_seq_u32_off0_8857B180(int a, void *b);
typedef struct { char p[0x20c]; unsigned short xy[2]; } Obj;
static int pad_id(int i) { PadRec *e = ts4_pad_record_find_88614938(lbl_88D45B1C->modules, i); return e ? e->id : -1; }
int fn_888C5C00(Obj *o, int pad, float x, float y) {
  int id = pad_id(pad);
  float k = *(float *)(g_ts4_script_constants + 0x84);
  o->xy[1] = (unsigned short)(k * y);
  o->xy[0] = (unsigned short)(k * x);
  return ts4_if_call_seq_u32_off0_8857B180(id, o->xy) == 0;
}