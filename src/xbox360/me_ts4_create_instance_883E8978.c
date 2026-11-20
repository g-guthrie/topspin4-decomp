/* 0x883E8978: allocates and inline-constructs a 0x60-byte instance, binds it to the source's slot entry (883E8410) when the source has an index (883E51B8 >= 0), otherwise sets it directly (883E54A8, taken as 2 arguments; another file declares it with 3) and clears +0x44; 0x2C on allocation failure */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef unsigned long long u64;
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039A20[];
extern const char lbl_88039908[];
typedef struct Slot { char b[0x10]; } Slot;
typedef struct Inst {
    const void *vt;
    int p4;
    int a, b, c;
    int p14;
    u64 q18, q20, q28;
    char pad0[0x38 - 0x30];
    int x38;
    int p3c;
    int x40, x44, x48, x4c, x50, x54;
    unsigned char x58;
} Inst;
typedef struct T { char pad[0xc]; Slot *slots; } T;
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
int ts4_if_get_u32_off4_883E51B8(void *src);
int ts4_bind_source_883E8410(Inst *o, void *src, Slot *s);
int ts4_set_u32_offc_883E54A8(Inst *o, void *src);

static Inst *inst_init(Inst *o)
{
    o->a = 0;
    o->b = 0;
    o->c = 0;
    o->q18 = 0;
    o->vt = lbl_88039908;
    o->q20 = 0;
    o->q28 = 0;
    o->x38 = 0;
    o->x40 = 0;
    o->x44 = 0;
    o->x48 = 0;
    o->x4c = 0;
    o->x50 = 0;
    o->x54 = 0;
    o->x58 = 0;
    return o;
}

static int inst_set_plain(Inst *o, void *src)
{
    int r = ts4_set_u32_offc_883E54A8(o, src);
    if (r)
        return r;
    o->x44 = 0;
    return 0;
}

int fn_883E8978(T *t, void *src, Inst **out)
{
    void *p;
    Inst *o;
    int r;
    p = fn_88315C60(lbl_88B3302C->heap, 0x60, lbl_88039A20, 0x3b4, 0, 0);
    o = p ? inst_init((Inst *)p) : 0;
    if (!o)
        return 0x2c;
    if (ts4_if_get_u32_off4_883E51B8(src) >= 0) {
        r = ts4_bind_source_883E8410(o, src, &t->slots[ts4_if_get_u32_off4_883E51B8(src)]);
        if (r)
            return r;
    } else {
        r = inst_set_plain(o, src);
        if (r)
            return r;
    }
    *out = o;
    return 0;
}
