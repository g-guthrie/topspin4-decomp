/* Family FAM2: typed-record factories (Swing_DLL.xex 0x8892A170..0x8892B848).
   When the requested kind byte is 1, each allocates a SIZE-byte record from the shared heap
   lbl_88D45B38 (align 4, tag 2), constructs it with CTOR (NULL if the allocation failed), stores the
   key word into the record's +4 field and appends the record pointer with fn_881898E8. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Ts4TypedRecord { void *vt; u32 key; } Ts4TypedRecord;
extern void *lbl_88D45B38;
extern void *fn_88613268(void *heap, int size, int align, int flags, int tag);
extern void fn_881898E8(void *list, Ts4TypedRecord **rec);
extern Ts4TypedRecord *ts4_call_seq_lbl_880D6330_88929A60(void *p);
extern Ts4TypedRecord *fn_88929B08(void *p);
extern Ts4TypedRecord *fn_8892A2A8(void *p);
extern Ts4TypedRecord *ts4_loop_call_seq_lbl_880D6330_8892A460(void *p);
extern Ts4TypedRecord *fn_8892A5C0(void *p);
extern Ts4TypedRecord *fn_8892A810(void *p);

#define TS4_TYPED_FACTORY(A, SIZE, CTOR) \
void ts4_typed_factory_##A(void *list, const u32 *key, const u8 *kind); \
void ts4_typed_factory_##A(void *list, const u32 *key, const u8 *kind) \
{ \
    if (*kind == 1) { \
        void *mem = fn_88613268(lbl_88D45B38, SIZE, 4, 0, 2); \
        Ts4TypedRecord *rec = mem ? CTOR(mem) : 0; \
        rec->key = *key; \
        fn_881898E8(list, &rec); \
    } \
}

/* Swing_DLL.xex addresses */
TS4_TYPED_FACTORY(8892A170, 0x18, ts4_call_seq_lbl_880D6330_88929A60)
TS4_TYPED_FACTORY(8892A698, 0x4c, fn_88929B08)
TS4_TYPED_FACTORY(8892B698, 0x4c, fn_8892A2A8)
TS4_TYPED_FACTORY(8892B728, 0x1d4, ts4_loop_call_seq_lbl_880D6330_8892A460)
TS4_TYPED_FACTORY(8892B7B8, 0x4c, fn_8892A5C0)
TS4_TYPED_FACTORY(8892B848, 0x68, fn_8892A810)
