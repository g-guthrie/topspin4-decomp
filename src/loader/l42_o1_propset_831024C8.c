/* Loader_DLL.xex 0x831024C8-0x83103C40, executable version 0.0.0.3. */
/* Property setters: look the object up by id (fn_830FF250), check the property type, store the value. */
typedef unsigned int u32;
typedef struct Prop { int type; u32 val; } Prop;
#ifdef _MSC_VER
__declspec(noinline)
#endif
/* Same-file stand-in so the compiler knows the callee preserves r5-r7. */
static int fn_830FF250(int id, void **out)
{
    *out = (void *)(unsigned long)(id + 1);
    return 0;
}

#define SETLIM(NAME, N) \
int NAME(void *self, int id, Prop *p) \
{ \
    char *o = 0; \
    int r; \
    (void)self; \
    fn_830FF250(id, (void **)&o); \
    if (o != 0 && p->type == 3 && p->val < (N)) { \
        *(u32 *)(o + 4) = p->val; \
        r = 0; \
    } else { \
        r = (int)0x80070057; \
    } \
    return r; \
}

SETLIM(ts4l_set_prop_lim6_831024C8, 6u)
SETLIM(ts4l_set_prop_lim4_83102548, 4u)
SETLIM(ts4l_set_prop_lim2_831025E0, 2u)

int ts4l_set_prop_range_83103478(void *self, int id, Prop *p)
{
    char *o = 0;
    int r;
    (void)self;
    fn_830FF250(id, (void **)&o);
    if (o != 0 && p->type == 3 && p->val >= 1 && p->val <= *(u32 *)(o + 8)) {
        *(u32 *)(o + 0x14) = p->val;
        r = 0;
    } else {
        r = (int)0x80070057;
    }
    return r;
}

int ts4l_set_prop_min_831034F0(void *self, int id, Prop *p)
{
    char *o = 0;
    int r;
    (void)self;
    fn_830FF250(id, (void **)&o);
    if (o != 0 && p->type == 3 && p->val >= *(u32 *)(o + 0x14)) {
        *(u32 *)(o + 8) = p->val;
        r = 0;
    } else {
        r = (int)0x80070057;
    }
    return r;
}

int ts4l_set_prop_low2_83103B68(void *self, int id, Prop *p)
{
    char *o;
    int r;
    (void)self;
    fn_830FF250(id, (void **)&o);
    if (o != 0 && p->type == 3 && p->val <= 3) {
        u32 v = p->val;
        *(u32 *)(o + 0xf0) = (*(u32 *)(o + 0xf0) & ~3u) | v;
        *(u32 *)(o + 0xc) |= 2;
        r = 0;
    } else {
        r = (int)0x80070057;
    }
    return r;
}

int ts4l_set_prop_mid2_83103C40(void *self, int id, Prop *p)
{
    char *o;
    int r;
    (void)self;
    fn_830FF250(id, (void **)&o);
    if (o != 0 && p->type == 3 && p->val <= 3) {
        u32 v = p->val;
        *(u32 *)(o + 0xf0) = (v << 2) | (*(u32 *)(o + 0xf0) & ~0xCu);
        *(u32 *)(o + 0xc) |= 2;
        r = 0;
    } else {
        r = (int)0x80070057;
    }
    return r;
}

int ts4l_set_prop_u32_83102908(void *self, int id, Prop *p)
{
    char *o;
    int r;
    (void)self;
    fn_830FF250(id, (void **)&o);
    if (p->type != 3) {
        r = (int)0x80070057;
    } else {
        *(u32 *)(o + 0x10) = p->val;
        r = 0;
    }
    return r;
}

/* Setters whose target object was already resolved by the caller. */
#define SETFIELD(NAME, MASK, SH) \
int NAME(void *self, char *o, Prop *p) \
{ \
    (void)self; \
    if (o != 0 && p->type == 3 && p->val <= 3) { \
        *(u32 *)(o + 0x84) = (p->val << (SH)) | (*(u32 *)(o + 0x84) & ~(MASK)); \
        return 0; \
    } \
    return (int)0x80070057u; \
}
SETFIELD(ts4l_set_bits_830FDD78, 0xCu, 2)
SETFIELD(ts4l_set_bits_830FDDC0, 0x30u, 4)
