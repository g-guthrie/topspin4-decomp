/* 0x883DBDC0: sizes a voice pool: creates its 0x10-byte shared buffer object (base ctor 883EEA50, vtable lbl_880391E0) sized n*0x298, allocates the voice table and creates and initialises each voice (883DBD18, 883CBD20); 0x2C on allocation failure */
/* Matched on /O1 plain only (agV, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039444[];
extern const char lbl_880391E0[];
typedef struct Buf { const void *vt; char pad[0xc]; } Buf;
typedef struct Voice Voice;
typedef struct Pool { char pad[8]; unsigned int count; unsigned int cap; Voice **voices; Buf *buf; } Pool;
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
void ts4_addr_lbl_880391E0_883EEA50(Buf *b);
unsigned char ts4_buffer_init_883EEBE8(Buf *b, unsigned int size, void *mem);
int ts4_if_get_u32_lbl_88CAC988_883DBD18(Pool *p, Voice **out, Buf *b);
int fn_883CBD20(Voice *v);

static Buf *buf_new(void *p)
{
    Buf *b = (Buf *)p;
    ts4_addr_lbl_880391E0_883EEA50(b);
    b->vt = lbl_880391E0;
    return b;
}

int fn_883DBDC0(Pool *t, unsigned int n)
{
    void *p;
    unsigned int i;
    int r;
    t->cap = n;
    t->count = n;
    p = fn_88315C60(lbl_88B3302C->heap, 0x10, lbl_88039444, 0x34, 0, 0);
    t->buf = p ? buf_new(p) : 0;
    if (!t->buf)
        return 0x2c;
    if (!ts4_buffer_init_883EEBE8(t->buf, (t->count * 0x298 + 3) & ~3u, 0))
        return 0x2c;
    t->voices = (Voice **)fn_88315C60(lbl_88B3302C->heap, t->count * 4, lbl_88039444, 0x3e, 0, 0);
    if (!t->voices)
        return 0x2c;
    for (i = 0; i < t->count; i++) {
        r = ts4_if_get_u32_lbl_88CAC988_883DBD18(t, &t->voices[i], t->buf);
        if (r)
            return r;
        r = fn_883CBD20(t->voices[i]);
        if (r)
            return r;
    }
    return 0;
}
