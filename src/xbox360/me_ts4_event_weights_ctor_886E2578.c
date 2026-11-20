/* Swing_DLL.xex 0x886E2578 (ts4_event_weights_ctor_886E2578), size 0x3C: constructor. Installs the vtable lbl_880F37A4, empties the
 * {begin,end,capacity} list at +0xC, sets both weights (+0x1C, +0x20) to the event default value g_ts4_event_value,
 * then clears the link words (+0x4, +0x8) and the owner (+0x18); returns the object.
 * Matching note: the capacity store goes through a pointer local, so the weight load is scheduled after the
 * second list store (agP 2026-11-19; was a 2-off draft). Matches on plain /Oc and LTCG. */
extern char lbl_880F37A4[];
extern float g_ts4_event_value;
typedef struct Ts4EvList { void *begin; void *end; void *capacity; } Ts4EvList;
typedef struct Ts4EvWeights {
    void *vt;              /* +0x00 */
    void *link0;           /* +0x04 */
    void *link1;           /* +0x08 */
    Ts4EvList list;        /* +0x0C */
    void *owner;           /* +0x18 */
    float w0;              /* +0x1C */
    float w1;              /* +0x20 */
} Ts4EvWeights;
Ts4EvWeights *ts4_event_weights_ctor_886E2578(Ts4EvWeights *o)
{
    float z;
    o->vt = lbl_880F37A4;
    {
        Ts4EvList *pl = &o->list;
        pl->begin = 0;
        pl->end = 0;
        { void **pc = &pl->capacity; *pc = 0; }
    }
    z = g_ts4_event_value;
    o->w0 = z;
    o->w1 = z;
    o->link0 = 0;
    o->link1 = 0;
    o->owner = 0;
    return o;
}
