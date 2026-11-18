/* agentB 2026-11-18 pass 2: still 5 off (plain and LTCG). &t[0]/&t[1], first/second named locals, 2-iteration loops (17),
 * independent pair+off(+0xc) expressions (15): the second address is still rematerialised after the first call. */
/* NEAR MISS 0x886C4C60: 5 off. Target computes the second record address (t + 0xc) before the first call and
 * keeps it in r31; every spelling tried keeps t instead. Sibling 0x886C4CB8 is the same with offset 8. */
/* 0x886C4C60 (hand match): applies the link update to both halves of a relative-offset pair:
 * the record the first word points at, then the record 0xC bytes into it. */
typedef struct Rel { int offset; } Rel;
void fn_886DBF40(void *slot, void *rec, void *defs, unsigned int style, int marker, unsigned int value);
typedef struct Rec { char p[0xc]; } Rec;
typedef struct Two { Rec first; Rec second; } Two;
void f(void *slot, Rel *pair, void *defs, unsigned int style, int marker, unsigned int value)
{
    Two *t = (Two *)((char *)pair + pair->offset);
    Rec *s = &t->second;
    fn_886DBF40(slot, t, defs, style, marker, value);
    fn_886DBF40(slot, s, defs, style, marker, value);
}
