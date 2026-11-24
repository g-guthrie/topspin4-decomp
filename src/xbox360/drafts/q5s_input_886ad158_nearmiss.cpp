/* nearmiss: 9 off (LTCG /Oc, pool primer, symbol ??0TS4Element880F4850@@QAA@XZ); only scheduling: target interleaves handle floats 28/2c with 48, 30, 4c, 34, then mtctr, 50, 44; ours emits 48, mtctr, 4c, 50 before the floats. Blocker: true layout of +0x3c..+0x58 unknown (owner dtor 0x886B14E0 gives the handle as 0x18 bytes, which then yields the wrong size). */
extern "C" void ts4_destroy_owned_object(void *p);
extern "C" const float g_ts4_event_value;
static inline void release_owned(void **pp) { if (*pp) ts4_destroy_owned_object(*pp); }

struct Vec3P { void *b, *e, *c; Vec3P() : b(0), e(0), c(0) {} };
struct Pair { int a, b; Pair() : a(0), b(0) {} };
struct Slot30 { int a, b, c; char rest[0x24]; Slot30() : a(0), b(0), c(0) {} };

struct TS4OwnerHandle880D7604 {
    float v[4];
    Vec3P vec;       /* +0x14 (owned = vec.b) */
    int f20;
    Vec3P vec2;      /* +0x24 */
    TS4OwnerHandle880D7604() {
        float z = g_ts4_event_value;
        v[0] = z; v[1] = z; v[2] = z; v[3] = z;
        f20 = 0;
    }
    virtual ~TS4OwnerHandle880D7604() { release_owned(&vec.b); }
};
struct TS4Element880F4850 {
    TS4Element880F4850();
    virtual ~TS4Element880F4850() {}
    unsigned char active;
    Pair p08;
    int f10[5];
    TS4OwnerHandle880D7604 handle;  /* +0x24 */
    int pad54, pad58;
    Slot30 slots[20];               /* +0x5c */
};

TS4Element880F4850::TS4Element880F4850()
{
    f10[0] = 0; f10[1] = 0; f10[2] = 0; f10[3] = 0; f10[4] = 0;
    active = 0;
}
