/* W11A: gameplay entry-list walkers that call virtual slots through MSVC virtual-call thunks
 * (class layout only; the thunks are in d1_vcall_thunks_88271E68.cpp). */

class TS4VcallClass88271E68 {
public:
    virtual void slot_000(); virtual void slot_001(); virtual void slot_002(); virtual void slot_003();
    virtual void slot_004(); virtual void slot_005(); virtual void slot_006(); virtual void slot_007();
    virtual void slot_008(); virtual void slot_009(); virtual void slot_00a(); virtual void slot_00b();
    virtual void slot_00c(); virtual void slot_00d(); virtual void slot_00e(); virtual void slot_00f();
};

/* 16-byte entry: +0 started flag, +4 count, +0xC handle object. */
struct W11aEnt {
    unsigned char started;
    unsigned char pad[3];
    int count;
    unsigned pad8;
    TS4VcallClass88271E68 *h;
};
struct W11aVec { W11aEnt *begin; W11aEnt *end; };

struct W11aObj { void **vtbl; unsigned pad4; unsigned pad8; W11aVec vec; };

struct W11aBig { unsigned char pad[0x9f]; unsigned char flag; unsigned char pad2[0xc0 - 0xa0]; };
struct W11aSrc { unsigned char pad[0x28]; W11aBig *big; };
struct W11aMid { unsigned char pad[0x48]; W11aSrc *src; };
struct W11aObj2 { void **vtbl; unsigned pad4; W11aMid *mid; W11aVec vec; };

extern "C" {
void fn_8826B510(W11aVec *v);

/* 0x886619C0: start every entry that has a handle, a positive count and is not started yet (slot 0xA), then virtual call 11. */
void ts4_start_entries_886619C0(W11aObj *self)
{
    W11aEnt *p;
    W11aEnt *end = self->vec.end;
    for (p = self->vec.begin; p != end; p++) {
        if (p->h != 0 && p->count > 0 && p->started == 0) {
            p->started = 1;
            (p->h->*(&TS4VcallClass88271E68::slot_00a))();
        }
    }
    ((void (*)(W11aObj *))self->vtbl[11])(self);
}

/* 0x8866D248: service every live entry (slot 0xF); copy the 0xC0-byte record and refresh the list when its flag is set. */
void ts4_service_entries_8866D248(W11aObj2 *self)
{
    W11aVec *vec = &self->vec;
    W11aEnt *p;
    W11aEnt *end = vec->end;
    W11aBig big;
    for (p = vec->begin; p != end; p++) {
        if (p->h != 0 && p->count > 0)
            (p->h->*(&TS4VcallClass88271E68::slot_00f))();
    }
    big = *self->mid->src->big;
    if (big.flag != 0)
        fn_8826B510(vec);
}
}
