/* 0x883E8AE0: returns 1 when the set at +0x10 is null, otherwise whether fn_883E4F58(set, &key) is non-null. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /Oc gives cmpwi cr6 where the target has cr0. */
typedef struct Obj { char pad[0x10]; void *set; } Obj;
void *fn_883E4F58(void *set, const unsigned *key);
unsigned char ts4_check_key_883E8AE0(Obj *o, unsigned key)
{
    return !o->set || fn_883E4F58(o->set, &key) != 0;
}
