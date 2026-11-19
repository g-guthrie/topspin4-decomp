/* 0x883E4C60: creates a 0xA0-byte sound (883FBD00) and, when none is given, its own 0x148-byte sub-object (883E3B60); initialises it (883FC5A0(snd, key, 10, sub)), attaches it to the target bus (88317D38, signed null test), finalises (883FB510) and stores both; on error frees the owned sub and destroys the sound (883FB4B8) */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
#ifdef _MSC_VER
#define PTR_INT(p) ((int)(p))
#else
#define PTR_INT(p) ((int)(long)(p))
#endif
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8803964C[];
extern const char lbl_880391F4[];
typedef struct Sub Sub;
typedef struct Snd { char pad[0x80]; void *bus; } Snd;
typedef struct T { int p0, p4; Snd *snd; int key; Sub *sub; } T;
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
void fn_88315F10(void *heap, void *buf, const char *file, int line);
Snd *fn_883FBD00(void *p);
Sub *fn_883E3B60(void *p);
void ts4_if_call_seq_fn_883FB3E8_883FB4B8(Snd *s);
int fn_883FC5A0(Snd *s, int key, int a, Sub *sub);
int ts4_lookup_then_forward_88317D38(void *tgt, void *bus);
int ts4_set_u8_off1d_883FB510(Snd *s);

int fn_883E4C60(T *t, void *tgt, Sub *sub)
{
    void *p;
    Snd *s;
    Sub *owned;
    int r;
    p = fn_88315C60(lbl_88B3302C->heap, 0xa0, lbl_8803964C, 0x191, 0, 0);
    s = p ? fn_883FBD00(p) : 0;
    if (!s)
        return 0x2c;
    owned = 0;
    if (!sub) {
        p = fn_88315C60(lbl_88B3302C->heap, 0x148, lbl_8803964C, 0x19c, 0, 0);
        sub = p ? fn_883E3B60(p) : 0;
        if (!sub) {
            ts4_if_call_seq_fn_883FB3E8_883FB4B8(s);
            return 0x2c;
        }
        owned = sub;
    }
    r = fn_883FC5A0(s, t->key, 10, sub);
    if (r) {
        if (owned)
            fn_88315F10(lbl_88B3302C->heap, owned, lbl_880391F4, 0xb7);
        ts4_if_call_seq_fn_883FB3E8_883FB4B8(s);
        return r;
    }
    if (tgt && PTR_INT(s->bus) != 0) {
        r = ts4_lookup_then_forward_88317D38(tgt, s->bus);
        if (r) {
            if (owned)
                fn_88315F10(lbl_88B3302C->heap, owned, lbl_880391F4, 0xb7);
            ts4_if_call_seq_fn_883FB3E8_883FB4B8(s);
            return r;
        }
    }
    r = ts4_set_u8_off1d_883FB510(s);
    if (r) {
        if (owned)
            fn_88315F10(lbl_88B3302C->heap, owned, lbl_880391F4, 0xb7);
        ts4_if_call_seq_fn_883FB3E8_883FB4B8(s);
        return r;
    }
    t->snd = s;
    t->sub = sub;
    return 0;
}
