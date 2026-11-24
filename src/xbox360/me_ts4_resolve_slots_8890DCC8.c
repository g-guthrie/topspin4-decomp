
typedef struct Slot { char b[0xc4]; } Slot;
typedef struct Tbl { char pad[0x1c]; int def; char pad2[0x10]; int *map; int n; char pad3[4]; Slot *slots; } Tbl;
typedef struct G { char pad[0x234]; Tbl *tbl; } G;
extern G *lbl_88D45B1C;
typedef struct Ent { char pad[0x18]; Slot *slot; char pad2[4]; int idx; char pad3[8]; const char *name; char pad4[4]; } Ent;
typedef struct O { char pad[0x1c]; Ent *begin, *end; } O;
void fn_8890DCC8(O *o)
{
    Ent *end = o->end;
    Ent *e = o->begin;
    Tbl *t = lbl_88D45B1C->tbl;
    for (; e != end; e++) {
        if (*e->name && e->idx >= 0 && e->idx != -1) {
            int k;
            if (e->idx >= t->n || (k = t->map[e->idx]) == -1)
                k = t->def;
            e->slot = &t->slots[k];
        }
    }
}
