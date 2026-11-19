/* 0x88803198: returns the default object (+0x9C) for id 0, else the object in the pointer vector at +0x90/+0x94 whose id (+0x1C) equals *key, or 0. */
/* Matched on /Oc (agAB). r = 0 result with break; end loaded into a local before the loop and compared as end != it. */
typedef struct O { char p[0x1c]; unsigned int id; } O;
typedef struct T { char p[0x90]; O **begin; O **end; char p98[4]; O *def; } T;
O *fn_88803198(T *t, const unsigned int *key)
{
    O *r = 0;
    O **it;
    if (*key == 0)
        return t->def;
    {
        O **end = t->end;
        for (it = t->begin; end != it; it++) {
            if (*key == (*it)->id) {
                r = *it;
                break;
            }
        }
    }
    return r;
}
