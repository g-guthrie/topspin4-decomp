/* CX44 part a: Pam Display renderer small helpers (0x886E8000-0x88700000), plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
#define CX44_INL static __forceinline
#else
#define CX44_INL static inline
#endif
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))

extern char *lbl_88D45AD4;
extern char lbl_88D48CC0[];
extern void fn_88290568(u32 dev, u32 reg, void *p, u32 cnt, u32 flags);
typedef struct { u32 x, y, z; } V3;
typedef struct Cx44XRef { int node; u32 offset; } Cx44XRef;
extern u32 ts4_gp0_xdata_get_bool_88163C60(Cx44XRef *ref);
CX44_INL u8 cx44_xref_invalid(Cx44XRef *r) { return r->node == 0 || r->offset == 0xfffff; }
typedef struct Cx44Bf { u8 pad[0xa0]; u8 mode; u8 cnt : 7; u8 flag : 1; } Cx44Bf;

/* self-relative pair table lookups: entry i of the table at the owner block +8 / +0x14 */
CX44_INL u32 sr_lookup(char *blk, u32 i)
{
    char *h = blk + 8;
    return *(u32 *)((char *)h + (i * 8 + *(int *)h) + 4);
}
CX44_INL u32 sr_lookup14(char *blk, u32 i)
{
    char *h = blk + 0x14;
    return *(u32 *)((char *)h + (i * 8 + *(int *)h) + 4);
}

/* 0x886F70B0: upload 4 vertex-shader constant registers (reg 0xB1) from slot a of the display's constant block */
void ts4_set_vs_const_slot_886F70B0(u32 a)
{
    char *g = lbl_88D45AD4;
    fn_88290568(*(u32 *)(g + 0x15720), 0xb1, *(char **)(*(char **)(g + 0x1c) + 0x2c) + (a << 6), 4, 0xc0000);
}

/* 0x886F79C0: store the slot index, then upload its 4 vertex-shader constant registers (reg 0xB1) */
void ts4_set_vs_const_slot_store_886F79C0(u32 *dst, u32 a)
{
    char *g;
    *dst = a;
    g = lbl_88D45AD4;
    fn_88290568(*(u32 *)(g + 0x15720), 0xb1, *(char **)(*(char **)(g + 0x1c) + 0x2c) + (a << 6), 4, 0xc0000);
}

/* 0x886F3268: self[2] = lookup of self[1] in the table at owner block +8 */
void ts4_sr_lookup_a_886F3268(u32 *self, char *owner)
{
    self[2] = sr_lookup(*(char **)(owner + 0xc), self[1]);
}

/* 0x886F35E8: both lookups above */
void ts4_sr_lookup_both_886F35E8(char *self, char *owner)
{
    W(self, 0x24) = sr_lookup(*(char **)(owner + 0xc), W(*(char **)(self + 0xc), 0x30));
    W(self, 0x20) = sr_lookup14(*(char **)(owner + 0xc), W(*(char **)(self + 0xc), 0x34));
}

/* 0x886F01F0: set the +0x7c field of one entry (0x8c bytes) or of every element of its list */
void ts4_set_entry_field7c_886F01F0(u32 idx, u32 val)
{
    char *e = *(char **)(*(char **)(lbl_88D45AD4 + 0x18) + 0x20) + idx * 0x8c;
    if (B(e, 0x1c) == 0) {
        W(e, 0x7c) = val;
    } else {
        char *last = *(char **)(e + 0x40);
        char *p = *(char **)(e + 0x3c);
        if (p == last) return;
        do {
            W(p, 0x7c) = val;
            p += 0x8c;
        } while (p != last);
    }
}

/* 0x886F5C80: is there an element (0x134 bytes) whose +0x10c equals key */
u8 ts4_has_elem_10c_886F5C80(char **v, u32 key)
{
    char *p = v[0];
    char *end = v[1];
    if (p < end) {
        do {
            if (W(p, 0x10c) == key) break;
            p += 0x134;
        } while (p < end);
        if (!(p < end)) p = 0;
    } else {
        p = 0;
    }
    return p != 0;
}

/* 0x886ED1A8: copy the vec3 at +0x40 of table record (o->+0x70) */
void ts4_copy_table_vec3_886ED1A8(V3 *out, char *o)
{
    V3 v = *(V3 *)(lbl_88D48CC0 + 0x40 + *(int *)(o + 0x70) * 0x4c);
    *out = v;
}

/* 0x886EBCE8: value of one hex digit character, 0 when not a hex digit */
u8 ts4_hex_digit_value_886EBCE8(u16 c)
{
    if (c >= '0' && c <= '9') return (u8)(c - '0');
    if (c >= 'A' && c <= 'F') return (u8)(c - 'A' + 10);
    if (c >= 'a' && c <= 'f') return (u8)(c - 'a' + 10);
    return 0;
}

/* 0x886EF100: the xdata ref at +0x9c is valid and reads as true */
u8 ts4_xref_bool_9c_886EF100(char *self)
{
    Cx44XRef *r = (Cx44XRef *)(self + 0x9c);
    if (cx44_xref_invalid(r) != 1) {
        if ((u8)ts4_gp0_xdata_get_bool_88163C60(r)) return 1;
    }
    return 0;
}

/* 0x886EF270: the xdata ref at +0x44 is valid and reads as true */
u8 ts4_xref_bool_44_886EF270(char *self)
{
    Cx44XRef *r = (Cx44XRef *)(self + 0x44);
    if (cx44_xref_invalid(r) != 1) {
        if ((u8)ts4_gp0_xdata_get_bool_88163C60(r)) return 1;
    }
    return 0;
}

/* 0x886ED728: set the mode byte and the 7-bit counter from the sum of two bytes */
void ts4_set_mode_cnt_886ED728(Cx44Bf *s, u8 a, u8 b)
{
    s->mode = a;
    s->cnt = a + b;
}

/* range find of a value, unrolled by four (same shape as 0x881655A0) */
#define CX44_FIND_RANGE(NAME, FOFF, LOFF) \
    u32 *NAME(char *self, u32 key) \
    { \
        u32 *last = *(u32 **)(self + LOFF); \
        u32 *first = *(u32 **)(self + FOFF); \
        int n = (last - first) >> 2; \
        for (; n > 0; --n) { \
            if (*first == key) return first; \
            ++first; \
            if (*first == key) return first; \
            ++first; \
            if (*first == key) return first; \
            ++first; \
            if (*first == key) return first; \
            ++first; \
        } \
        switch (last - first) { \
        case 3: if (*first == key) return first; ++first; \
        case 2: if (*first == key) return first; ++first; \
        case 1: if (*first == key) return first; ++first; \
        case 0: \
        default: break; \
        } \
        return last; \
    }

/* 0x886EBDF0: find key in the u32 vector at +0x1c/+0x20 */
CX44_FIND_RANGE(ts4_find_u32_1c_886EBDF0, 0x1c, 0x20)
/* 0x886EBFC0: find key in the u32 vector at +0x54/+0x58 */
CX44_FIND_RANGE(ts4_find_u32_54_886EBFC0, 0x54, 0x58)


/* 0x886F5CB8: state at +0x11c of the element (0x134 bytes) whose +0x10c equals key is 0 or 1 */
u8 ts4_elem_state_ready_886F5CB8(char **v, u32 key)
{
    char *p = v[0];
    char *end = v[1];
    int st;
    if (p < end) {
        do {
            if (W(p, 0x10c) == key) {
                u32 r;
                st = (int)W(p, 0x11c);
                if (st == 1 || st == 0) r = 1;
                else r = 0;
                return (u8)r;
            }
            p += 0x134;
        } while (p < end);
    }
    return 0;
}
