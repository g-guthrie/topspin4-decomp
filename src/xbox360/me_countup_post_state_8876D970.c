
/* 0x8876D970: count-up sibling of fn_8876D8D8: if a definition is bound: mark +0x6B, increment counter +0xC; at or past def->limit post state 3 (def id 0x016DB2D0) or 4, else state 1 when slot +0x14 is set and def->x20 + counter exceeds it, else 0; dispatch via fn_8876D770. */
typedef struct { char p0[0x20]; int x20; int limit; char p28[4]; unsigned int id; } Def;
typedef struct { Def *def; char p4[8]; int cnt; char p10[4]; int idx; char p18[0x53]; unsigned char flag; } Obj;
void fn_8876D770(Obj *o, const int *state);
void fn_8876D970(Obj *o)
{
    Def *d = o->def;
    int st; /* event state passed by address */
    if (d) {
        o->flag = 1;
        st = 0;
        if (++o->cnt >= d->limit)
            st = (d->id == 0x016DB2D0) ? 3 : 4;
        else if (o->idx != -1 && d->x20 + o->cnt > o->idx)
            st = 1;
        fn_8876D770(o, &st);
    }
}
