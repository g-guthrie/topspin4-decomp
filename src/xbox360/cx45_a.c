/* CX45 part a: Pam Display renderer helpers (0x88700000-0x88720000), plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX45_INL static __forceinline
#else
#define CX45_INL static inline
#endif
#define W(p, o) (*(u32 *)((char *)(p) + (o)))

extern char *lbl_88D45AD4;
extern void fn_88290568(u32 dev, u32 reg, void *p, u32 cnt, u32 flags);
extern void fn_88707360(void *, u32, int, u32);
extern void ts4_object_finalize(void *p);
extern void *fn_88562DC0(void *dst, const void *src, u32 n);
extern void ts4_loop_get_u32_off8_8861DDB0(u32 a, u32 b);
extern char lbl_880F2894[];
extern void fn_88617D88(char *self);
extern void ts4_small_string256_ctor_88163B90(void *p);
extern void *ts4_find_record_by_key_881AC778(void *tbl, void *key);

/* 0x88714680: when the slot matches upload 4 constants (reg 0xB5) from the block at +0x50, else forward */
void ts4_upload_slot_const_88714680(char *self, u32 a, int slot, u32 idx)
{
    if (*(int *)(self + 0x110) != slot) {
        fn_88707360(self, a, slot, idx);
        return;
    }
    fn_88290568(*(u32 *)(lbl_88D45AD4 + 0x15720), 0xb5, self + (idx << 6) + 0x50, 4, 0x60000);
}

typedef struct Cx45PV { char *first; char *last; } Cx45PV;
CX45_INL char *cx45_mv(char *first, char *last, char *dst)
{
    if (first == last) return dst;
    {
        u32 n = (u32)(last - first);
        return (char *)fn_88562DC0(dst, first, n) + n;
    }
}
/* 0x88713DA8: finalize +0x50, clear the vector at +0x34, finalize +0x18 */
void ts4_clear_finalize_88713DA8(char *self)
{
    Cx45PV *v;
    ts4_object_finalize(self + 0x50);
    v = (Cx45PV *)(self + 0x34);
    v->last = cx45_mv(v->last, v->last, v->first);
    ts4_object_finalize(self + 0x18);
}

/* 0x88708408: run slot 13 then slot 12 per 0xbc-byte entry, and visit each non-null handle */
void ts4_visit_entries_88708408(char *self)
{
    char *end = *(char **)(self + 0x20);
    char *p;
    if ((u8)((u32 (*)(char *))(*(void ***)self)[13])(self)) {
        u32 a = W(self, 0x3c);
        if (a != 0) ts4_loop_get_u32_off8_8861DDB0(W(self, 0x2c), a);
    }
    p = *(char **)(self + 0x1c);
    for (; p != end; p += 0xbc) {
        if ((u8)((u32 (*)(char *, char *))(*(void ***)self)[12])(self, p)) {
            u32 a = W(p, 0);
            if (a != 0) ts4_loop_get_u32_off8_8861DDB0(W(self, 0x2c), a);
        }
    }
}

/* 0x887104B8: constructor with a base init, a vtable, three scalar fields and a 256-byte small string at +0x38 */
char *ts4_ctor_named_887104B8(char *self)
{
    volatile u32 *v = (volatile u32 *)self;
    fn_88617D88(self);
    v[0] = (u32)(unsigned long)lbl_880F2894;
    v[7] = 0;
    W(self, 0x24) = 0;
    W(self, 0x20) = 0xfffff;
    ts4_small_string256_ctor_88163B90(self + 0x38);
    return self;
}

/* 0x88714280: set the two mode words +0x84 / +0x80 from the kind of the record named by a fixed key */
void ts4_set_mode_words_88714280(char *self, char *obj)
{
    u32 key = 0xf9db8239;
    u32 *rec = (u32 *)ts4_find_record_by_key_881AC778(obj + 0x3c, &key);
    if (rec != 0) {
        u32 h = rec[1];
        u32 v;
        if (h == 0xe178c892) {
            v = 1;
            W(self, 0x84) = v;
        } else if (h == 0xaec2acd3) {
            W(self, 0x84) = 1;
            v = 0;
        } else if (h == 0x8a3fb8ef) {
            W(self, 0x84) = 0;
            v = 1;
        } else if (h == 0x4905ed7b) {
            v = 0;
            W(self, 0x84) = v;
        } else {
            return;
        }
        W(self, 0x80) = v;
    }
}
