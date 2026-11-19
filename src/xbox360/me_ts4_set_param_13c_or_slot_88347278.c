/* 0x88347278: k 16: stores x at +0x13c; k 0..15: stores x in the float array at +0x180; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char p[0x1c]; } Base;
typedef struct { char p[0x13c]; float v; char q[0x180 - 0x140]; float arr[16]; } O;
int ts4_set_param_13c_or_slot_88347278(Base *b, int k, float x) { O *o = b ? (O *)((char *)b - 0x1c) : 0; switch (k) { case 16: o->v = x; break; default: if (k >= 0 && k <= 15) o->arr[k] = x; } return 0; }
