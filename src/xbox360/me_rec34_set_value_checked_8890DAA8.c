/* 0x8890DAA8: in the 0x34-byte record vector at +0x1C/+0x20, writes value into record[i].val (+0x24) only when
 * record[i].idx (+0x20) is a valid index into the same vector. Sub-struct rule: count() takes &o->vec. */
typedef unsigned int u32;
typedef struct Ts4Rec34 { char p[0x20]; u32 idx; int val; char q[0x34 - 0x28]; } Ts4Rec34;
typedef struct Ts4Rec34Vec { Ts4Rec34 *begin; Ts4Rec34 *end; } Ts4Rec34Vec;
typedef struct Ts4Rec34Owner { char p[0x1c]; Ts4Rec34Vec vec; } Ts4Rec34Owner;
static u32 count(Ts4Rec34Vec *v) { return v->end - v->begin; }
void ts4_rec34_set_value_checked_8890DAA8(Ts4Rec34Owner *o, int i, int value)
{
    Ts4Rec34 *r = &o->vec.begin[i];
    if (r->idx < count(&o->vec) && (int)r->idx >= 0)
        r->val = value;
}
