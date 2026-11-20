/* Swing_DLL.xex 0x889414F0: find the first empty 0xC0-byte slot in the entry keyed (keyA,keyB)
 * entry search as an inline returning the entry; slot loop pointer then takes r31 */
typedef unsigned char u8;
typedef unsigned int u32;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)

typedef struct Hdr { int off; int cnt; } Hdr;
typedef struct SlotC0 { char name[0xC0]; } SlotC0;
typedef struct Entry44 {
    Hdr slots;      /* +0x00 */
    u8 pad08[0x1C];
    u32 keyA;       /* +0x24 */
    u32 keyB;       /* +0x28 */
} Entry44;
extern void *ts4_offset_array_end44_88160B30(Hdr *h);
extern void *ts4_offset_array_end192_88160A58(Hdr *h);

static __inline SlotC0 *slots_begin(Hdr *h)
{
    SlotC0 *r = 0;
    if (h->off != -1)
        r = (SlotC0 *)((char *)h + h->off);
    return r;
}

static __inline Entry44 *find_entry(Hdr *h, u32 a, u32 b)
{
    Entry44 *e = 0;
    Entry44 *end;
    if (h->off != -1)
        e = (Entry44 *)((char *)h + h->off);
    end = (Entry44 *)ts4_offset_array_end44_88160B30(h);
    for (; e != end; e++) {
        if (e->keyA == a && e->keyB == b)
            return e;
    }
    return 0;
}

SlotC0 *fn_889414F0(Hdr *h, u32 a, u32 b)
{
    SlotC0 *result = 0;
    Entry44 *e = find_entry(h, a, b);
    if (e) {
        SlotC0 *s = slots_begin(&e->slots);
        SlotC0 *send = (SlotC0 *)ts4_offset_array_end192_88160A58(&e->slots);
        for (; s != send; s++) {
            unsigned int len = (int)strlen(s->name);
            if (len == 0) {
                result = s;
                break;
            }
        }
    }
    return result;
}
