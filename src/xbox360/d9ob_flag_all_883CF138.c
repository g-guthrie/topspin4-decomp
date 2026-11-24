/* Swing_DLL.xex 0x883CF138-0x883CF19C, executable version 0.0.0.3. */
typedef struct Ts4Ob2Fl { unsigned short pad0[0x12]; unsigned short f24; } Ts4Ob2Fl;
typedef struct Ts4Ob2G1 { char pad0[0x2c]; int f2c; } Ts4Ob2G1;
typedef struct Ts4Ob2G2 { char pad0[0x14]; Ts4Ob2G1 *g; char pad18[0x1c]; Ts4Ob2Fl **arr; } Ts4Ob2G2;

int ts4_flag_all_883CF138(Ts4Ob2G2 *o)
{
    int i;
    for (i = 0; i < o->g->f2c; i++) {
        if (o->arr != 0 && o->arr[i] != 0)
            o->arr[i]->f24 |= 1;
    }
    return 0;
}
