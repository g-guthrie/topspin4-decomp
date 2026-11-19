/* 0x887C7BD0: Stores level. If the control is active, finds key 0xD2284DB4 in the global registry and calls fn_886FFB60 on that slot target with its stored value. */
/* Near miss (agAH): /Oc, 1 off: the slot address add is (base, index) in the target; named locals tb/end/slots/idx do not flip it. */
typedef struct KeyIndex { unsigned int key; int index; } KeyIndex;
typedef struct Target { char p0[0x18]; float value; } Target;
typedef struct Slot { char p0[8]; Target *target; char pc[0x120 - 0xc]; } Slot;
typedef struct Registry { char p0[4]; KeyIndex *begin; KeyIndex *end; char pc[0x18]; Slot *slots; } Registry;
typedef struct Tables { char p0[0x2c]; Registry *reg; } Tables;
typedef struct Ctl { char p0[0x71]; unsigned char active; char p72[0xe]; float level; } Ctl;
extern Tables *lbl_88D45AD4;
extern void fn_886FFB60(Target *t, float v);
void fn_887C7BD0(Ctl *c, float level)
{
    Registry *r;
    KeyIndex *p;
    c->level = level;
    if (!c->active)
        return;
    r = lbl_88D45AD4->reg;
    for (p = r->begin; p != r->end; p++) {
        if (p->key == 0xD2284DB4u)
            break;
    }
    if (p == r->end || p->index == -1)
        return;
    {
        Target *t = r->slots[p->index].target;
        fn_886FFB60(t, t->value);
    }
}
