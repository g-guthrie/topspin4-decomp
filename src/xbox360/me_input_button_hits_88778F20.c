
typedef struct { int button; int slot_a; int slot_b; int slot_c; } Map;
extern Map lbl_88C47750[10];
typedef struct { unsigned short flags; unsigned short pad; } Btn;
typedef struct { Btn btn[1]; } Input;
typedef struct { char pad[0x26]; unsigned char hit[0x5a]; int side; char pad84[0x10]; unsigned char mode; } O;
static unsigned char pressed(Input *in, int button, int side)
{
  if (!side) return (in->btn[button + 12].flags >> 7) & 1;
  return (in->btn[button + 12].flags >> 6) & 1;
}
void fn_88778F20(O *o, Input *in)
{
  Map *m;
  for (m = lbl_88C47750; m != lbl_88C47750 + 10; m++) {
    if (pressed(in, m->button, o->side != 0)) o->hit[m->slot_a] = 1;
    if (o->mode == 1) {
      if (m->slot_b != 0x26 && pressed(in, m->button, o->side != 1)) o->hit[m->slot_b] = 1;
      if (m->slot_c != 0x26 && pressed(in, m->button, o->side != 0)) o->hit[m->slot_c] = 1;
    }
  }
}
