/* 0x886B14E0: destructor of a 0x2950-byte owner. It releases its owned object at +0x294c, then
 * destroys ten 0x41c-byte elements (each holding an owning sub-object at +0x24) and the member at +0x20. */
extern "C" void ts4_destroy_owned_object(void *p);
static inline void release_owned(void **pp) { if (*pp) ts4_destroy_owned_object(*pp); }

struct TS4OwnerHandle880D7604 { void *w04[4]; void *owned; virtual ~TS4OwnerHandle880D7604() { release_owned(&owned); } };
struct TS4Element880F4850 {
    TS4Element880F4850();
    virtual ~TS4Element880F4850() {}
    char p04[0x20];
    TS4OwnerHandle880D7604 handle;  /* +0x24 */
    char rest[0x41c - 0x24 - 0x18];
};
struct TS4Member880F4854 { void *w04; void *owned; virtual ~TS4Member880F4854() { release_owned(&owned); } char p0c[8]; };
struct TS4Owner880F4424 {
    virtual ~TS4Owner880F4424();
    char p04[0x1c];
    TS4Member880F4854 member;        /* +0x20 */
    TS4Element880F4850 elements[10]; /* +0x34 */
    void *owned;                     /* +0x294c */
};

TS4Owner880F4424::~TS4Owner880F4424()
{
    release_owned(&owned);
}
