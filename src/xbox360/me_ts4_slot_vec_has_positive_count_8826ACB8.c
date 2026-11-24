/* 0x8826ACB8: Looks up the 16-byte slot whose key (+8) equals *key in [begin, end) and returns whether its count (+4) is positive; 0 when not found. */
/* Matched on /Oc (agAH). Write the test with the constant on the left (0 < count): count > 0 compiles to neg/andc/srwi, 0 < count to the subfc/eqv/srwi/addze/clrlwi sequence the target has. */
typedef struct Slot { int unk0; int count; unsigned int key; int unkC; } Slot;
typedef struct SlotVec { Slot *begin; Slot *end; } SlotVec;

int fn_8826ACB8(SlotVec *v, const unsigned int *key)
{
    int result = 0;
    Slot *end = v->end;
    unsigned int k = *key;
    Slot *it;
    for (it = v->begin; it != end; it++) {
        if (it->key == k) {
            result = 0 < it->count;
            break;
        }
    }
    return result;
}
