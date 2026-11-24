/* HKB (from the W11F batch B draft): gameplay code that calls virtual slots through MSVC thunks (??_9TS4VcallClass88271E68@@$B...).
 * Same class layout as ga3_c.cpp. */

class TS4VcallClass88271E68 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008();
    virtual void slot_009();
    virtual void slot_00a();
    virtual void slot_00b();
    virtual void slot_00c();
    virtual void slot_00d();
    virtual void slot_00e();
    virtual void slot_00f();
};

/* List of 16-byte entries whose last word is a handle (signed address compare as in ga3_c.cpp). */
typedef long HkbAddr;
struct HkbHandleList { HkbAddr begin; HkbAddr end; };
struct HkbHandleOwner {
    unsigned char pad_00[0x08];
    int state;                        /* +0x08 */
    struct HkbHandleList handles;    /* +0x0C begin, +0x10 end */
};

extern "C" {

/* Releases every handle with slot 0xE, then again with slot 0xC, and clears the state. */
/* Swing_DLL.xex 0x8865E8C0 */
void ts4_release_handles_8865E8C0(struct HkbHandleOwner *self)
{
    struct HkbHandleList *list;
    HkbAddr first;
    HkbAddr it;
    list = &self->handles;
    first = list->begin;
    for (it = list->end; it != first; it -= 0x10) {
        TS4VcallClass88271E68 *h = *(TS4VcallClass88271E68 **)(it - 4);
        if (h) (h->*(&TS4VcallClass88271E68::slot_00e))();
    }
    first = list->begin;
    for (it = list->end; it != first; it -= 0x10) {
        TS4VcallClass88271E68 *h = *(TS4VcallClass88271E68 **)(it - 4);
        if (h) (h->*(&TS4VcallClass88271E68::slot_00c))();
    }
    self->state = 0;
}

}
