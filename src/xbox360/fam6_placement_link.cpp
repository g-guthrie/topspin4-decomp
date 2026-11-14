/* FAM6: "allocate an object, construct it, then placement-construct a link
   record inside it" factories (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).

   Each factory allocates SIZE bytes from the owner's heap (owner->+0x1c->+0x2c)
   with fn_8860DCF8(heap, size, align, 2), runs the object's base constructor and
   stores its vtable(s), then builds a 0x1c-byte link record at object+OFF with
   placement new: {owner word, 16-byte {offset, object, 0, 0} pair, word 0,
   byte 0}.  The record pointer (or null when the allocation failed) is returned.

   Matching notes: the null path returns the zero register that the record's
   zero stores use (`mr r3,r30`) only when the record is built by a C++
   placement new (the compiler's own null check); the pair is copied as two
   64-bit words, so the record is a pack(4) struct with two u64 members. */
typedef unsigned long ts4_word;
typedef unsigned long long ts4_u64;

extern "C" {
extern char lbl_880D1F4C[];
extern char lbl_880D1F5C[];
extern char lbl_880D1F6C[];
extern char lbl_880D1F74[];
extern char lbl_880D2054[];
extern char lbl_880D2068[];
extern char lbl_880D207C[];
ts4_word fn_8860DCF8(ts4_word heap, ts4_word size, ts4_word align, ts4_word flags);
ts4_word fn_88995D18(ts4_word object);
ts4_word fn_88995DB0(ts4_word object);
ts4_word fn_88995E48(ts4_word object);
ts4_word fn_88995F30(ts4_word object);
}

#ifdef _MSC_VER
#define TS4_ALIGN8 __declspec(align(8))
#else
#define TS4_ALIGN8 __attribute__((aligned(8)))
#endif
inline void *operator new(decltype(sizeof(0)), void *where) { return where; }

/* {offset of the record in its object, object, 0, 0} */
struct TS4_ALIGN8 ts4_link_pair { ts4_word offset, object, zero0, zero1; };

#pragma pack(push, 4)
struct ts4_link_record {
    ts4_word owner;
    ts4_u64 pair_lo;
    ts4_u64 pair_hi;
    ts4_word count;
    unsigned char active;
    ts4_link_record(ts4_word who, const ts4_link_pair &pair)
    {
        owner = who;
        count = 0;
        active = 0;
        pair_lo = *(const ts4_u64 *)&pair.offset;
        pair_hi = *(const ts4_u64 *)&pair.zero0;
    }
};
#pragma pack(pop)

/* INIT runs on the freshly allocated object `obj` (non-null). */
#define TS4_LINK_FACTORY(NAME, SIZE, ALIGN, OFF, INIT)                             \
    extern "C" ts4_word NAME(ts4_word owner, ts4_word who)                         \
    {                                                                              \
        ts4_word ctx = *(ts4_word *)(owner + 0x1c);                                \
        ts4_link_pair pair;                                                        \
        ts4_word obj;                                                              \
        ts4_word made;                                                             \
        pair.zero0 = 0;                                                            \
        pair.zero1 = 0;                                                            \
        obj = fn_8860DCF8(*(ts4_word *)(ctx + 0x2c), SIZE, ALIGN, 2);              \
        if (obj != 0) {                                                            \
            INIT                                                                   \
            made = obj;                                                            \
        } else {                                                                   \
            made = 0;                                                              \
        }                                                                          \
        pair.object = made;                                                        \
        pair.offset = OFF;                                                         \
        return (ts4_word)new ((void *)(obj + OFF)) ts4_link_record(who, pair);     \
    }

/* Swing_DLL.xex 0x881534C0 */
TS4_LINK_FACTORY(ts4_create_linked_object_881534C0, 0x644, 4, 0x628,
    fn_88995E48(obj);
    *(ts4_word *)(obj + 0) = (ts4_word)lbl_880D2054;
    *(ts4_word *)(obj + 0x20) = (ts4_word)lbl_880D1F5C;)

/* Swing_DLL.xex 0x88153570 */
TS4_LINK_FACTORY(ts4_create_linked_object_88153570, 0x34C, 4, 0x330,
    fn_88995F30(obj);
    *(ts4_word *)(obj + 0) = (ts4_word)lbl_880D207C;
    *(ts4_word *)(obj + 0x1c) = (ts4_word)lbl_880D1F4C;)

/* Swing_DLL.xex 0x88153870 */
TS4_LINK_FACTORY(ts4_create_linked_object_88153870, 0x8C, 8, 0x70,
    fn_88995D18(obj);
    *(ts4_word *)(obj + 0) = (ts4_word)lbl_880D1F74;)

/* Swing_DLL.xex 0x88153910 */
TS4_LINK_FACTORY(ts4_create_linked_object_88153910, 0x64C, 8, 0x630,
    fn_88995DB0(obj);
    *(ts4_word *)(obj + 0) = (ts4_word)lbl_880D2068;
    *(ts4_word *)(obj + 0x1c) = (ts4_word)lbl_880D1F6C;)

/* Swing_DLL.xex 0x881539C0 */
TS4_LINK_FACTORY(ts4_create_linked_object_881539C0, 0x350, 4, 0x334,
    fn_88995F30(obj);
    *(ts4_word *)(obj + 0x330) = 0;
    *(ts4_word *)(obj + 0) = (ts4_word)lbl_880D207C;
    *(ts4_word *)(obj + 0x1c) = (ts4_word)lbl_880D1F4C;)
