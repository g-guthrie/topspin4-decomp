/* 0x8849FCB0: walks from head (+0x10) while the next node kind (u16) is >= 0x17; returns the last such node */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct N { unsigned short kind; char pad[0x12]; struct N *next; } N;
typedef struct { char pad[0x10]; N *head; } O;
N *ts4_last_low_kind_node_8849FCB0(O *o)
{
    N *p = o->head;
    if (p == 0) return p;
    while (p->next->kind >= 0x17) p = p->next;
    return p;
}
