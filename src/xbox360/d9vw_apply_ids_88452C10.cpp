/* Swing_DLL.xex 0x88452C10-0x88452CA0, executable version 0.0.0.3. */
typedef unsigned short u16;
struct Ts4VwTarget {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void apply(int id, int arg);
};
struct Ts4VwIdSet {
    virtual void destroy(int flag);
    int pad4;
    Ts4VwTarget *target;
    u16 *ids;
    int count;
};
extern "C" {
void ts4_apply_ids_88452C10(Ts4VwIdSet *s, int arg)
{
    int i;
    if (s->target != 0) {
        for (i = 0; i < s->count; i++) {
            u16 id = s->ids[i];
            if (id != 0xffff)
                s->target->apply(id, arg);
        }
    }
    s->destroy(1);
}
}
