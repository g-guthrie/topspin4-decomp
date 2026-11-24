/* CW40 part e: UI helpers (predicate helper inlined, vcall wrappers) in 0x887D0000-0x88800000. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX40_INL static __forceinline
#else
#define CX40_INL static inline
#endif

typedef struct Cx40E34 { void *s[13]; void (*s34)(void *, u32, u32); } Cx40E34;
typedef struct Cx40EObj { Cx40E34 *vt; } Cx40EObj;
/* 0x887F7890: when the first word behind +0x14 is set, notify the object at +0x24 and report 1. */
u32 ts4_notify_if_set_887F7890(char *s)
{
    u32 r = 0;
    if (**(int **)(s + 0x14) != 0) {
        Cx40EObj *o = *(Cx40EObj **)(s + 0x24);
        r = 1;
        o->vt->s34(o, *(u32 *)(s + 8), *(u32 *)(s + 0x2c));
    }
    return r;
}

typedef struct Cx40E30 { void *s[12]; u8 (*s30)(void *); } Cx40E30;
typedef struct Cx40EObj30 { Cx40E30 *vt; } Cx40EObj30;
/* sub-object at +0x1dc is ready: it exists (+0x1bc) and slot 0x30 reports true */
CX40_INL u8 cx40_sub_ready(char *self)
{
    if (*(u32 *)(self + 0x1bc) != 0) {
        Cx40EObj30 *o = (Cx40EObj30 *)(self + 0x1dc);
        if (o->vt->s30(o)) return 1;
    }
    return 0;
}

/* 0x887E94F8: flag +0x304 when the sub-object is ready. */
void ts4_flag_if_sub_ready_887E94F8(char *self)
{
    if (cx40_sub_ready(self)) self[0x304] = 1;
}

extern void ts4_loop_get_u32_off1dc_887EEF68(void *);
extern void fn_887EAC80(void *);
extern void ts4_anlz_publish_slot_25bd833a_887ECB68(void *);
/* 0x887EF2D8: when the sub-object is ready, reset its queue and refresh. */
void ts4_refresh_if_sub_ready_887EF2D8(char *self)
{
    if (cx40_sub_ready(self)) {
        ts4_loop_get_u32_off1dc_887EEF68(self);
        fn_887EAC80(self);
        ts4_anlz_publish_slot_25bd833a_887ECB68(*(void **)(self + 0x1bc));
    }
}

extern char *lbl_88D45A14;
extern u8 ts4_if_call_seq_u32_off0_887D4FF0(void *, void *);
extern u8 fn_887DD550(void *, void *);
/* slot has a live object whose +0x75 flag is set */
CX40_INL u8 cx40_slot_ready(char *p)
{
    if (*(char **)p != 0) {
        if ((*(char **)p)[0x75] != 0) return 1;
    }
    return 0;
}
/* 0x887D90D8: run the handler over the four ready slots of the manager; 0 if any fails. */
u32 ts4_slots_all_ok_887D90D8(void *self)
{
    u32 r = 1;
    char *p = lbl_88D45A14 + 4;
    int n = 4;
    do {
        if (cx40_slot_ready(p)) { if (ts4_if_call_seq_u32_off0_887D4FF0(self, p) == 0) r = 0; }
        p += 16;
        n--;
    } while (n != 0);
    return r;
}

/* 0x887DF390: same walk with the other handler. */
u32 ts4_slots_all_ok_887DF390(void *self)
{
    u32 r = 1;
    int off;
    for (off = 0; off < 4; off++) {
        char *p = lbl_88D45A14 + off * 16 + 4;
        if (cx40_slot_ready(p)) { if (fn_887DD550(self, p) == 0) r = 0; }
    }
    return r;
}

typedef struct Cx40E18 { void *s[6]; void (*s18)(void *, int, int, int, int); } Cx40E18;
typedef struct Cx40EObj18 { Cx40E18 *vt; } Cx40EObj18;
extern void *fn_887F1F00(void *);
/* 0x887F1F68: select the entry for object o in the manager (slot 0x18 with flag 1), then re-run it for the entry found. */
void ts4_select_entry_887F1F68(Cx40EObj18 *self, char *o)
{
    if (o != 0) {
        int k = *(int *)(o + 0x10);
        if (k != -1) {
            char *r;
            self->vt->s18(self, k, 1, 0, 0);
            r = (char *)fn_887F1F00(self);
            if (r != 0) {
                int k2 = *(int *)(r + 0x10);
                if (k2 != -1) self->vt->s18(self, k2, 0, 0, 0);
            }
        }
    }
}

extern u8 fn_887D3148(void *, void *);
extern void ts4_call_seq_fn_887DE6C0_887E04B0(void *);
/* config block at +0x11c is armed: +0x1c set and +0x1d clear */
CX40_INL u8 cx40_cfg_armed(char *c)
{
    if (c[0x1c] != 0) {
        if (c[0x1d] == 0) return 1;
    }
    return 0;
}
/* 0x887E1C50: when unarmed or in state 4, record the current value in one of two slots and run the follow-up. */
void ts4_record_value_887E1C50(char *self)
{
    char *c = *(char **)(self + 0x11c);
    if (!cx40_cfg_armed(c) || *(int *)(self + 0x58) == 4) {
        u32 key;
        u32 v = *(u32 *)(*(char **)(self + 0x104) + 0x6f8);
        if (fn_887D3148(self, &key) != 0) *(u32 *)(self + 0x37c) = v;
        else *(u32 *)(self + 0x378) = v;
        ts4_call_seq_fn_887DE6C0_887E04B0(self);
    }
}

/* 0x887E9C10: is value v present in the u32 vector at +0x40 (std::find unrolled by four). */
#ifdef _MSC_VER
__declspec(noinline)
#endif
u32 ts4_vec_contains_887E9C10(char *self, u32 v)
{
    u32 *e = *(u32 **)(self + 0x44);
    u32 *p = *(u32 **)(self + 0x40);
    int n = (e - p) >> 2;
    for (; n > 0; n--) {
        if (*p == v) goto done;
        p++;
        if (*p == v) goto done;
        p++;
        if (*p == v) goto done;
        p++;
        if (*p == v) goto done;
        p++;
    }
    switch (e - p) {
    case 3: if (*p == v) goto done; p++;
    case 2: if (*p == v) goto done; p++;
    case 1: if (*p == v) goto done; p++;
    case 0:
    default: p = e;
    }
done:
    return (char *)e - (char *)p != 0;
}

typedef struct Cx40G234 { char pad[0x234]; void *f234; } Cx40G234;
extern Cx40G234 *lbl_88D45B1C;
extern char *ts4_pad_record_find_88614938(void *);
typedef struct Cx40VO { void **vt; } Cx40VO;
/* 0x887EA5C8: with the guard at +0x1c held, test whether the current key is in the vector of the object at +0x20. */
u32 ts4_key_known_887EA5C8(char *self)
{
    char *r = ts4_pad_record_find_88614938(lbl_88D45B1C->f234);
    u32 key;
    Cx40VO *sub;
    u32 res;
    if (r != 0) key = *(u32 *)(r + 0x10); else key = (u32)-1;
    sub = (Cx40VO *)(*(char **)(self + 0x1c) + 8);
    ((void (*)(void *))sub->vt[1])(sub);
    res = ts4_vec_contains_887E9C10(*(char **)(self + 0x20), key);
    ((void (*)(void *))sub->vt[2])(sub);
    return res;
}
