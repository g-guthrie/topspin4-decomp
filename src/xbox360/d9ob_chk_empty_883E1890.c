/* Swing_DLL.xex 0x883E1890-0x883E18CC, executable version 0.0.0.3. */
typedef struct Ts4Ob2N { char pad0[8]; int f8; int fc; } Ts4Ob2N;
typedef struct Ts4Ob2M2 { char pad0[0xc]; Ts4Ob2N *c; } Ts4Ob2M2;
typedef struct Ts4Ob2M { char pad0[0xc]; Ts4Ob2M2 *c; } Ts4Ob2M;
typedef struct Ts4Ob2H { char pad0[0x14]; Ts4Ob2M *p; char pad18[0xc]; unsigned int f24; } Ts4Ob2H;

unsigned char ts4_chk_empty_883E1890(Ts4Ob2H *o)
{
    Ts4Ob2N *n;
    if ((o->f24 & 4) != 0) {
        n = o->p->c->c;
        if (n->f8 == 0 && n->fc == 0)
            return 1;
    }
    return 0;
}
