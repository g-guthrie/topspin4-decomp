/* Swing_DLL.xex 0x88621080: Swing_DLL.xex 0x88621080: Shuts down the TSU block: registry lookup of id 0x0FB36679, ends and clears the session at +0x4, resets the lists at +0x150/+0x170, empties the 0x58-byte record vector at +0x160 and the byte vector at +0x180.
 * /Oc. Counted copy loop increments first before dest (--n, ++first, ++dest). */
typedef unsigned int u32;
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Rec58 { u32 w[0x58 / 4]; } Rec58;
typedef struct RecVec { Rec58 *first; Rec58 *last; Rec58 *end; } RecVec;
typedef struct Tsu {
    char pad0[4];
    void *session;          /* 0x004 */
    char pad8[0x150 - 8];
    char list150[0x160 - 0x150];
    RecVec recs;            /* 0x160 */
    char pad16c[4];
    char list170[0x180 - 0x170];
    ByteVec data;           /* 0x180 */
} Tsu;
extern void *lbl_88D45B38;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void *fn_88618998(void *reg, u32 id);
void ts4_tsu_cleanup_end(void *session);
void ts4_if_call_seq_u32_off8_88280958(void *list);
static __inline Rec58 *copy_recs(Rec58 *first, Rec58 *last, Rec58 *dest)
{
    int n;
    for (n = last - first; 0 < n; --n, ++first, ++dest)
        *dest = *first;
    return dest;
}
static __inline char *copy_bytes(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
void fn_88621080(Tsu *t)
{
    RecVec *r;
    ByteVec *v;
    fn_88618998(lbl_88D45B38, 0x0FB36679);
    ts4_tsu_cleanup_end(t->session);
    t->session = 0;
    ts4_if_call_seq_u32_off8_88280958(t->list150);
    r = &t->recs;
    r->last = copy_recs(r->last, r->last, r->first);
    ts4_if_call_seq_u32_off8_88280958(t->list170);
    v = &t->data;
    v->last = copy_bytes(v->last, v->last, v->first);
}
