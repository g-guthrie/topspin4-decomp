/* near-miss 0x88656C88 (C++, /Oc): 45 instructions off, same size. Open: each resize reads self_off through an addi'd vector pointer before the size store (target stores size first, reads self_off from the block base); block pointer in r28 vs target r30; loop compare signedness. result-local form fixed the early return. */
/* 0x88656C88: when the save slot is ready, clears every stat array whose stored length differs from its expected
 * length, then reports whether all arrays are at least their minimum sizes. */
typedef unsigned int u32;
extern "C" void *ts4_memset(void *dst, int c, u32 n);
struct StatVec {
    int self_off; u32 size; u32 expected;
    void *data() { return self_off == -1 ? 0 : (char *)this + self_off; }
    void reset(u32 elem) { if (size != expected) { size = expected; ts4_memset(data(), 0, expected * elem); } }
};
struct StatRec { StatVec bytes; StatVec shorts; char p[0x1c - 0x18]; };
struct StatRecs { int self_off; StatRec *at(int i) { return (StatRec *)((char *)this + self_off) + i; } };
struct StatBlock { char p[0x18]; StatVec bytes; StatVec shorts; StatVec words; StatVec words2; StatRecs recs; };
class SaveSlot {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual bool is_ready(); virtual void v34(); virtual void v38(); virtual void v3c(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual StatBlock *block(int i);
};
struct StatOwner { char p[0x1c]; SaveSlot slot; };
extern "C" bool fn_88656C88(StatOwner *o)
{
    bool result = false;
    if (o->slot.is_ready()) {
    StatBlock *b;
    bool ok;
    int i;
    b = o->slot.block(0);
    b->bytes.reset(1);
    b->shorts.reset(2);
    b->words.reset(4);
    b->words2.reset(4);
    for (i = 0; i < 4; i++) {
        StatRec *r = b->recs.at(i);
        r->bytes.reset(1);
        r->shorts.reset(2);
        ok = r->bytes.size >= 0x33 && r->shorts.size >= 3;
    }
    result = ok && b->bytes.size >= 0x65 && b->shorts.size >= 0x37 && b->words.size >= 0x46 && b->words2.size >= 4;
    }
    return result;
}
