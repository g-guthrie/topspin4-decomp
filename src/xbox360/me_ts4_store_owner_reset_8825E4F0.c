/* Swing_DLL.xex 0x8825E4F0: Swing_DLL.xex 0x8825E4F0: Releases the four refs at +0x48/+0x4C/+0x40/+0x44, runs 8825DFE0 for each 0x44-byte record index, then clears the store at +0x4: erases the records (8825E0D8 + 8825E428) and empties its two byte vectors.
 * /Oc. Inline store_clear on &o->store; the second byte vector through a ByteVec *v local (gives the equal-path store and the r30 base). */
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Rec44 { char data[0x44]; } Rec44;
typedef struct RecVec { Rec44 *first; Rec44 *last; Rec44 *end; } RecVec;
typedef struct Store {
    ByteVec a;              /* 0x00 */
    char padc[4];
    ByteVec b;              /* 0x10 */
    char pad1c[4];
    RecVec recs;            /* 0x20 */
} Store;
typedef struct Owner {
    char pad[4];
    Store store;            /* 0x04 */
    char pad30[0x40 - 0x30];
    void *ref40;            /* 0x40 */
    void *ref44;            /* 0x44 */
    void *ref48;            /* 0x48 */
    void *ref4c;            /* 0x4c */
} Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ts4_if_atomic_interlocked_dec_88288530(void *ref);
void fn_8825DFE0(Owner *o, int index);
Rec44 *fn_8825E0D8(Rec44 *first, Rec44 *last, Rec44 *dest);
void ts4_loop_get_u32_off0_8825E428(Rec44 *first, Rec44 *last);
static __forceinline char *copy_bytes(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
static __inline int recvec_size(const RecVec *v) { return v->last - v->first; }
static __inline void recvec_erase_all(RecVec *v)
{
    Rec44 *last = fn_8825E0D8(v->last, v->last, v->first);
    ts4_loop_get_u32_off0_8825E428(last, v->last);
    v->last = last;
}
static __inline void store_clear(Store *s)
{
    recvec_erase_all(&s->recs);
    s->a.last = copy_bytes(s->a.last, s->a.last, s->a.first);
    { ByteVec *v = &s->b; v->last = copy_bytes(v->last, v->last, v->first); }
}
void fn_8825E4F0(Owner *o)
{
    int i;
    ts4_if_atomic_interlocked_dec_88288530(o->ref48);
    ts4_if_atomic_interlocked_dec_88288530(o->ref4c);
    ts4_if_atomic_interlocked_dec_88288530(o->ref40);
    ts4_if_atomic_interlocked_dec_88288530(o->ref44);
    for (i = 0; i < recvec_size(&o->store.recs); i++)
        fn_8825DFE0(o, i);
    store_clear(&o->store);
}
