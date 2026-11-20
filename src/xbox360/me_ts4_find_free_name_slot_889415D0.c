/* Swing_DLL.xex 0x889415D0: find the first empty 0x84-byte name slot of the entry keyed (keyA,keyB)
 * found/break result local keeps r28; strlen intrinsic converted to unsigned int */
typedef unsigned char u8;
typedef unsigned int u32;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)

typedef struct Hdr { int off; int cnt; } Hdr;
typedef struct Slot84 { char name[0x84]; } Slot84;
typedef struct Entry44 {
    u8 pad00[0xC];
    Hdr slots;      /* +0x0C */
    u8 pad14[0x10];
    u32 keyA;       /* +0x24 */
    u32 keyB;       /* +0x28 */
} Entry44;
extern void *ts4_offset_array_end44_88160B30(Hdr *h);

static __inline Slot84 *slots_end(Hdr *h)
{
    Slot84 *r = 0;
    if (h->off != -1)
        r = (Slot84 *)((char *)h + (h->cnt * 0x84 + h->off));
    return r;
}

static __inline Slot84 *slots_begin(Hdr *h)
{
    Slot84 *r = 0;
    if (h->off != -1)
        r = (Slot84 *)((char *)h + h->off);
    return r;
}

Slot84 *fn_889415D0(Hdr *h, u32 a, u32 b)
{
    Slot84 *result = 0;
    Entry44 *e = 0;
    Entry44 *end;
    if (h->off != -1)
        e = (Entry44 *)((char *)h + h->off);
    end = (Entry44 *)ts4_offset_array_end44_88160B30(h);
    for (; e != end; e++) {
        if (e->keyA == a && e->keyB == b) {
            Slot84 *s;
            for (s = slots_begin(&e->slots); s != slots_end(&e->slots); s++) {
                unsigned int len = (int)strlen(s->name);
                if (len == 0)
                {
                    result = s;
                    break;
                }
            }
            break;
        }
    }
    return result;
}
