/* 0x883CE938: initialises a 0x40-byte state from an optional source (+0x14 kept, floats zeroed or copied from source +0x14/+0x18),
   allocating source->count words (file lbl_880390E4, line 0x3A); returns 0x2C on allocation failure. Matched plain /O1 (agT); 0.0f is lbl_88001A20. */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_880390E4[];
void *ts4_tailcall_fn_88315C60_88316068(void *heap, unsigned size, const char *file, int line, int a);
typedef struct Src { char pad[0x14]; float a; float b; char pad2[0x10]; int count; } Src;
typedef struct T {
    char pad[0x14]; Src *src; float f18; float f1c; float f20; int f24; int f28;
    float f2c; float f30; void *items; int f38; int f3c;
} T;
int ts4_init_from_source_883CE938(T *t, Src *s)
{
    t->src = s;
    t->f38 = 0;
    t->items = 0;
    t->f24 = 0;
    t->f18 = 0.0f;
    t->f28 = 0;
    t->f20 = 0.0f;
    t->f2c = s ? s->a : 0.0f;
    t->f30 = s ? s->b : 0.0f;
    t->f1c = 0.0f;
    t->f3c = 0;
    if (s) {
        if (s->count) {
            t->items = ts4_tailcall_fn_88315C60_88316068(lbl_88B3302C->heap, s->count * 4, lbl_880390E4, 0x3a, 0);
            if (!t->items)
                return 0x2c;
        } else {
            t->items = 0;
        }
    }
    return 0;
}
