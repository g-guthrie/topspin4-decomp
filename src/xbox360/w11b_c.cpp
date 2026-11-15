/* W11B batch C: gameplay function that calls through a virtual-call thunk (see src/xbox360/ga3_c.cpp). */
class TS4VcallClass88286E38 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
};
struct W11bFlagEntry { unsigned char f; unsigned char pd[3]; int n; int p8; TS4VcallClass88286E38 *p; };
struct W11bFlagList { char pad[0xc]; W11bFlagEntry *begin; W11bFlagEntry *end; };

/* Swing_DLL.xex 0x8865E9D0: mark each live entry once and notify it. */
extern "C" void ts4_notify_flag_entries_8865E9D0(W11bFlagList *s)
{
    W11bFlagEntry *e;
    W11bFlagEntry *end = s->end;
    for (e = s->begin; e != end; e++) {
        if (e->p && e->n > 0 && e->f == 0) {
            e->f = 1;
            (e->p->*(&TS4VcallClass88286E38::slot_002))();
        }
    }
}
