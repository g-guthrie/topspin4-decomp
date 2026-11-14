/* HS2 hand-decompiled functions, group A (Swing_DLL.xex 0x884xxxxx).
 * Each function is named ts4_<role>_<address>. */

#ifdef _MSC_VER
#define HS2_NOINLINE __declspec(noinline)
#else
#define HS2_NOINLINE
#endif

/* ---- growable byte buffer writers (size/capacity buffer, grow = fn_8841C678) ---- */

typedef struct Hs2ByteBuf {
    unsigned char *data;
    int size;
    int cap; /* low 30 bits = capacity */
} Hs2ByteBuf;

void fn_8841C678(Hs2ByteBuf *buf, int grow_by);

static void hs2_push_byte(Hs2ByteBuf *b, unsigned char v)
{
    if (b->size == (b->cap & 0x3fffffff))
        fn_8841C678(b, 1);
    b->data[b->size] = v;
    b->size++;
}

/* Appends one byte to the buffer. */
void ts4_buf_push_u8_8840FFD8(unsigned char v, Hs2ByteBuf *b)
{
    hs2_push_byte(b, v);
}

/* Appends n zero bytes to the buffer. */
void ts4_buf_push_zeros_88410048(int n, Hs2ByteBuf *b)
{
    if (n > 0) {
        int i = n;
        do {
            hs2_push_byte(b, 0);
        } while (--i);
    }
}

/* ---- removal from an array of 8-byte entries ---- */

typedef struct Hs2KeyEntry {
    unsigned value;
    unsigned key;
} Hs2KeyEntry;

typedef struct Hs2KeyTable {
    char pad[0x34];
    Hs2KeyEntry *volatile items;
    int count;
} Hs2KeyTable;

/* Removes every entry whose key matches by overwriting it with the last entry. */
void ts4_remove_entries_by_key_884D3520(Hs2KeyTable *t, unsigned key)
{
    int i;
    for (i = t->count - 1; i >= 0; i--) {
        if (t->items[i].key == key) {
            int n = t->count - 1;
            Hs2KeyEntry *e = t->items;
            t->count = n;
            e[i] = e[n];
        }
    }
}

/* ---- vtable initialisation ---- */

extern char lbl_88088DD4, lbl_88088E4C, lbl_88088E3C, lbl_88088E1C, lbl_88088E04;
void fn_884B70D0(void *);

typedef struct Hs2MultiVtbl {
    const void *v0;
    int p4;
    const void *v8;
    int pc[5];
    const void *v20;
    int p24;
    const void *volatile v28;
} Hs2MultiVtbl;

/* Runs the base constructor then installs the derived vtable pointers. */
void *ts4_init_vtbls_884AFB70(Hs2MultiVtbl *o)
{
    fn_884B70D0(o);
    o->v28 = &lbl_88088DD4;
    o->v0 = &lbl_88088E3C;
    o->v8 = &lbl_88088E1C;
    o->v20 = &lbl_88088E4C;
    o->v28 = &lbl_88088E04;
    return o;
}

/* ---- vtable dispatch ---- */

typedef struct Hs2Obj {
    void **vtbl;
} Hs2Obj;

typedef struct Hs2IdEntry {
    unsigned short id;
    unsigned short extra;
} Hs2IdEntry;

typedef struct Hs2IdList {
    void **vtbl;
    int pad4;
    Hs2Obj *target;
    unsigned short pad0c[3];
    Hs2IdEntry ents[1];
    char pad16[0x1b];
    unsigned char count;
} Hs2IdList;

/* Calls target->vtbl[5](id, arg) for every id entry, then vtbl[0](self, 1). */
void ts4_dispatch_ids_8845EE98(Hs2IdList *s, int arg)
{
    int i;
    for (i = 0; i < s->count; i++) {
        Hs2Obj *t = s->target;
        ((void (*)(Hs2Obj *, int, int))t->vtbl[5])(t, s->ents[i].id, arg);
    }
    ((void (*)(Hs2IdList *, int))s->vtbl[0])(s, 1);
}

typedef struct Hs2Writer {
    void **vtbl;
    char pad[0x24];
    int stride;
} Hs2Writer;

#define HS2_STREAM_WRITE_SCALED(w, unused, count, sp) \
    do { \
        char tmp[8]; \
        int src = ((int (*)(Hs2Writer *))(w)->vtbl[0x34 / 4])(w); \
        Hs2Obj *s; \
        int bytes; \
        (void)(unused); \
        s = *(sp); \
        bytes = (w)->stride * (count) * 4; \
        ((void (*)(Hs2Obj *))s->vtbl[0x2c / 4])(s); \
        s = *(sp); \
        ((void (*)(void *, Hs2Obj *, int, int))s->vtbl[0x1c / 4])(tmp, s, src, bytes); \
        s = *(sp); \
        ((void (*)(Hs2Obj *))s->vtbl[0x30 / 4])(s); \
    } while (0)

/* Writes stride*count*4 bytes from the writer's source into the stream. */
void ts4_stream_write_scaled_8840B9F8(Hs2Writer *w, int unused, int count, Hs2Obj **sp)
{
    HS2_STREAM_WRITE_SCALED(w, unused, count, sp);
}

/* Same body as ts4_stream_write_scaled_8840B9F8. */
void ts4_stream_write_scaled_88413840(Hs2Writer *w, int unused, int count, Hs2Obj **sp)
{
    HS2_STREAM_WRITE_SCALED(w, unused, count, sp);
}
