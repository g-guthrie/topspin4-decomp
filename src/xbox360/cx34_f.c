/* CW34 part f: small objects and constructors (0x888C0000-0x888D8000), plain route. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
#define CX34_U32(p, o) (*(u32 *)((char *)(p) + (o)))
#define CX34_F32(p, o) (*(float *)((char *)(p) + (o)))
#define CX34_I32(p, o) (*(int *)((char *)(p) + (o)))
#define CX34_U8(p, o) (*(u8 *)((char *)(p) + (o)))
#define CX34_PTR(p, o) (*(char **)((char *)(p) + (o)))

extern char *lbl_88D45B1C;
extern void *fn_88617D88(void *self);
extern char lbl_880DB88C[];
extern char lbl_880DBC04[];
extern char lbl_880DBDD0[];
extern char *lbl_88D4593C;



/* 0x888C9588 */
char *ts4_init_state_888C9588(char *self)
{
    fn_88617D88(self);
    *(volatile u32 *)(self + 0) = (u32)(unsigned long)lbl_880DB88C;
    *(volatile u32 *)(self + 0x30) = 0;
    *(volatile u32 *)(self + 0x38) = 0;
    CX34_U32(self, 0x34) = 0xFFFFF;
    CX34_U32(self, 0x2c) = 0;
    CX34_U32(self, 0x3c) = 0;
    CX34_U32(self, 0x40) = (u32)-1;
    return self;
}

/* 0x888CB730 */
char *ts4_init_singleton_888CB730(char *self)
{
    fn_88617D88(self);
    *(volatile u32 *)(self + 0x50) = (u32)-1;
    *(volatile u32 *)(self + 0) = (u32)(unsigned long)lbl_880DBC04;
    *(volatile u32 *)(self + 0x54) = (u32)-1;
    *(volatile u32 *)(self + 0x58) = 0;
    *(volatile u32 *)(self + 0x60) = 0;
    *(volatile u32 *)(self + 0x64) = 0;
    CX34_U8(self, 0x28) = 0;
    CX34_U32(self, 0x24) = 1;
    lbl_88D4593C = self;
    return self;
}

/* 0x888CED28 */
char *ts4_init_flags_888CED28(char *self)
{
    fn_88617D88(self);
    *(volatile u32 *)(self + 0) = (u32)(unsigned long)lbl_880DBDD0;
    *(volatile u32 *)(self + 0x1c) = 0;
    *(volatile u32 *)(self + 0x24) = 0;
    CX34_U32(self, 0x20) = 0xFFFFF;
    CX34_U8(self, 0x2c) = 1;
    CX34_U8(self, 0x2d) = 0;
    CX34_U8(self, 0x2e) = 0;
    return self;
}


extern void ts4_format_save_name_888677D0(u32 id, char *out);
extern void *ts4_if_call_seq_u32_lbl_88D459E4_8883F238(void);
extern void fn_886223B0(void *a, u32 i, char *name);

extern char lbl_880DB4B8[];
extern char lbl_880D6B70[];
extern char *lbl_88D45940;

extern char lbl_880DB904[];
extern char *lbl_88D45958;
extern void ts4_object_finalize(void *);

extern void ts4_clear_intrusive_list(void *list);
/* 0x888CEBA8: reset four slots (u16 at +0xAC.., id at +0xC0.., list at +0x9C.., 3-byte flags at +0xB4..) */
void ts4_reset_four_slots_888CEBA8(char *self)
{
    u8 i = 0;
    do {
        *(u16 *)(self + (i + 0x56) * 2) = 0;
        CX34_I32(self, (i + 0x30) * 4) = -1;
        ts4_clear_intrusive_list(self + (i + 0x27) * 4);
        {
            char *e = self + (i + 0x3c) + (i + 0x3c) * 2;
            CX34_U8(e, 0) = 0;
            CX34_U8(e, 1) = 0;
            CX34_U8(e, 2) = 0;
        }
        i = (u8)(i + 1);
    } while (i < 4);
}


extern void fn_8887CA38(void *o);
typedef struct Cx34PV { char **begin; char **end; } Cx34PV;

extern char lbl_880DB200[];
extern char *lbl_88D45948;
extern u32 ts4_dc44_copy_881817A0(u32 first, u32 last, u32 dst);
extern void ts4_destroy_owned_object(void *);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);

extern void ts4_xform_record_set_88187BC0(char *a, char *b);

extern char *ts4_pad_record_find_88614938(char *o, u32 i);
extern u32 ts4_if_call_seq_u32_off0_8857B180(int id, char *out);

extern void *fn_88617788(char *o, u32 id);
extern char lbl_880D7B28[];
extern char *lbl_88D45908;

extern void fn_888C2E58(void *o);
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void ts4_vec204_move_tail_881B9148(void *p);
typedef void (*Cx34Fn1)(void *, int);
typedef void (*Cx34Fn0)(void *);
static __inline u32 **cx34_move_pp(u32 **first, u32 **last, u32 **dst)
{
    if (first == last) {
        return dst;
    } else {
        u32 n = (u32)((char *)last - (char *)first);
        dst = (u32 **)fn_88562DC0(dst, first, n);
        return (u32 **)((char *)dst + n);
    }
}
/* 0x888CCDF0: destroy and delete every object in the vector at +0x1c, then clear */
void ts4_delete_all_objects_888CCDF0(char *self)
{
    u32 **e = (u32 **)CX34_PTR(self, 0x20);
    char *v = self + 0x1c;
    u32 **p = (u32 **)CX34_PTR(v, 0);
    for (; p != e; p++) {
        fn_888C2E58(*p);
        if (*p) ((Cx34Fn1)(*(void ***)*p)[0])(*p, 1);
    }
    CX34_PTR(v, 4) = (char *)cx34_move_pp((u32 **)CX34_PTR(v, 4), (u32 **)CX34_PTR(v, 4), (u32 **)CX34_PTR(v, 0));
    CX34_U8(self, 8) = 0;
    ts4_vec204_move_tail_881B9148(self + 0x10);
}


extern void ts4_set_state_4_8887C9A8(void *o);

extern char *lbl_88D459CC;
extern char *lbl_88D45A08;

extern void fn_888BB670(void *o);
extern char *ts4_find_child_by_id_888AD568(char *self, u32 *key);
typedef void (*Cx34FnU)(void *, u32);
typedef u8 (*Cx34FnB)(void *);
