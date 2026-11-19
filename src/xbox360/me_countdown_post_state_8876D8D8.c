/* 0x8876D8D8: if a definition is bound: mark +0x6B, decrement counter +0xC; on underflow post state 5 (def id 0x016DB2D0) or 6, else state 2 when slot +0x14 is set and def->x20 < 0, else 0; dispatch via fn_8876D770. */
typedef struct { char p0[0x20]; int x20; char p24[8]; unsigned int id; } Def;
typedef struct { Def *def; char p4[8]; int cnt; char p10[4]; int idx; char p18[0x53]; unsigned char flag; } Obj;
void fn_8876D770(Obj *o, const int *state);
void fn_8876D8D8(Obj *o)
{
    Def *d = o->def;
    int st; /* event state passed by address */
    if (d) {
        o->flag = 1;
        st = 0;
        if (--o->cnt < 0)
            st = (d->id == 0x016DB2D0) ? 5 : 6;
        else if (o->idx != -1 && d->x20 < 0)
            st = 2;
        fn_8876D770(o, &st);
    }
}
