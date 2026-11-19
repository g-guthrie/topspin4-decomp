/* 0x883DFA10 near miss (3 off on /O1 and 4 off on /Oc, plain and LTCG): if the child at +0x44 is set, calls 0x88317BD8 on it, then stores the flag byte at +0x1d and returns 0. */
/* The rest is r30/r31 swapped (this vs flag); C, a local copy, an int flag and a C++ member all give the same swap. Check: work/army/ME/v.py chk. */
typedef struct Obj { char pad[0x1d]; unsigned char flag; char pad2[0x26]; void *child; } Obj;
void ts4_call_then_conditionally_forward_result_88317BD8(void *child);
int ts4_set_flag_after_child_883DFA10(Obj *o, unsigned char flag)
{
    if (o->child)
        ts4_call_then_conditionally_forward_result_88317BD8(o->child);
    o->flag = flag;
    return 0;
}
