/* CW41 part a: camera / minigame / publisher small objects (0x888D8000-0x88900000). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#define CX41_U32(p, o) (*(u32 *)((char *)(p) + (o)))
#define CX41_F32(p, o) (*(float *)((char *)(p) + (o)))
#define CX41_I32(p, o) (*(int *)((char *)(p) + (o)))
#define CX41_U8(p, o) (*(u8 *)((char *)(p) + (o)))
#define CX41_PTR(p, o) (*(char **)((char *)(p) + (o)))

extern void ts4_destroy_owned_object(void *p);
extern void fn_888F70A0(void *p);
extern void ts4_reset_four_slots_888CEBA8(void *p);
extern void ts4_if_get_u32_lbl_88D45B1C_888C0E18(void *a, u32 b);
extern void fn_888FBB40(u32 v);
extern void *ts4_hash_find_null_888E1D40(void *self);
extern char *ts4_find_record_by_key_881877A8(void *tbl, u32 *key);
extern void ts4_clear_script_prop_B1CA7E98_888C8190(void *obj);
extern void ts4_if_call_seq_NtSetEvent_8857C1F8(u32 h);
extern char lbl_88D45CC0[];
extern char *lbl_88D45B1C;

/* 0x888DC898 */
void ts4_clear_byte_vec_888DC898(u32 *self)
{
    u32 z = 0;
    u32 *v = self + 1;
    u32 b, e;
    *(volatile u32 *)&self[0] = z;
    *(volatile u32 *)&self[4] = z;
    b = *(volatile u32 *)&v[0];
    e = *(volatile u32 *)&v[1];
    if (b != e) {
        *(u8 *)(unsigned long)b = (u8)z;
        v[1] = v[0];
    }
    ts4_destroy_owned_object((void *)(unsigned long)v[0]);
}

/* 0x888F8110 */
void ts4_set_flag_e5_and_reset_888F8110(char *self, u8 flag)
{
    CX41_U8(self, 0xe5) = flag;
    if (flag == 0) {
        fn_888F70A0(self);
        ts4_reset_four_slots_888CEBA8(self);
    }
}


/* 0x888D8110 */
void ts4_init_slot_888D8110(u32 idx, u8 flag)
{
    char *s = lbl_88D45CC0 + 0xc + idx * 0x19c;
    if (flag) {
        u32 z = 0;
        char *g = CX41_PTR(lbl_88D45B1C, 0x270);
        CX41_U32(s, 0x150) = z;
        CX41_U32(s, 0x158) = z;
        CX41_U32(s, 8) = z;
        CX41_U32(s, 0xc) = (u32)(unsigned long)(g + 0x3c);
        CX41_U8(s, 0x198) = (u8)z;
        CX41_U8(s, 7) = (u8)z;
        ts4_if_call_seq_NtSetEvent_8857C1F8(CX41_U32(lbl_88D45CC0, 0x684));
    }
}

typedef struct Cx41PVec { char *begin; char *end; } Cx41PVec;
extern void ts4_vec204_move_tail_881B9148(void *p);
extern void fn_8816D1A8(void *p);
extern char *fn_88185AE8(char *first, char *last, char *dst);
extern void ts4_loop_call_seq_u32_off40_881815A8(char *first, char *last);
extern char *ts4_copy_e5c_88185D08(char *first, char *last, char *dst);
extern void fn_888EE920(void *p);
extern void ts4_opt_set_flag_888DF8E8(void *self, u32 f);
extern char lbl_880DBE94[];

/* 0x888EEB68 */
char *ts4_init_four_subobjs_888EEB68(char *self)
{
    char *p = self + 4;
    int n = 3;
    CX41_U32(self, 0) = (u32)(unsigned long)lbl_880DBE94;
    do {
        fn_888EE920(p);
        p += 0x54;
    } while (--n >= 0);
    return self;
}


/* 0x888F2430 */
void ts4_clear_f4_vec_888F2430(char *self)
{
    Cx41PVec *v = (Cx41PVec *)(self + 0x1c);
    char *p = fn_88185AE8(v->end, v->end, v->begin);
    ts4_loop_call_seq_u32_off40_881815A8(p, v->end);
    v->end = p;
    CX41_U32(self, 0x34) = 0;
    CX41_U32(self, 0x3c) = 0;
    CX41_U32(self, 0x38) = 0xFFFFF;
    CX41_U8(self, 8) = 0;
    ts4_vec204_move_tail_881B9148(self + 0x10);
}

static __inline void cx41_destroy_e5c(char *first, char *last)
{
    for (; first != last; first += 0x5c) ts4_destroy_owned_object(CX41_PTR(first, 0));
}

/* 0x888EF4F8 */
void ts4_clear_e5c_vec_888EF4F8(char *self)
{
    Cx41PVec *v;
    char *p;
    CX41_U8(self, 8) = 0;
    ts4_vec204_move_tail_881B9148(self + 0x10);
    v = (Cx41PVec *)(self + 0x2c);
    p = ts4_copy_e5c_88185D08(v->end, v->end, v->begin);
    cx41_destroy_e5c(p, v->end);
    v->end = p;
    ts4_opt_set_flag_888DF8E8(self, 0);
}

typedef struct Cx41Handle12 { u32 a, b, c; } Cx41Handle12;
extern char *lbl_88D458F0;
extern char *ts4_hash_find_arg_88180F08(char *table, u32 hash, u32 *arg, Cx41Handle12 h);
extern char *lbl_88D4591C;
extern int fn_8817CA20(void);
extern char *fn_888EC548(void *self);
extern void ts4_loop_get_fn_888D7920_888DAF90(void *self, void *a, u32 b);





extern void ts4_vec_resize_88176CD0(void *v, u32 n);
extern void ts4_vec16_resize_881593F8(void *v, u32 n);
extern char lbl_880DBEB8[];
extern u8 fn_888D4EF8(void *e);
extern void fn_888DC5E8(void *o, void *e, u32 f, u32 x);

/* 0x888DF4E0 */
char *ts4_init_table_obj_888DF4E0(char *self)
{
    char *v;
    short i;
    u32 z;
    CX41_U32(self, 0) = (u32)(unsigned long)lbl_880DBEB8;
    fn_8816D1A8(self + 4);
    z = 0;
    *(volatile u32 *)(self + 0x10) = z;
    *(volatile u32 *)(self + 0x18) = z;
    *(volatile u32 *)(self + 0x14) = 0xFFFFF;
    v = self + 0x28;
    *(volatile u32 *)(self + 0x1c) = z;
    *(volatile u32 *)(self + 0x20) = z;
    *(volatile u32 *)(self + 0x24) = z;
    *(volatile u32 *)(self + 0x28) = z;
    *(volatile u32 *)(self + 0x2c) = z;
    *(volatile u32 *)(self + 0x30) = z;
    *(volatile u8 *)(self + 0x34) = (u8)z;
    ts4_vec_resize_88176CD0(self + 0x1c, 9);
    ts4_vec16_resize_881593F8(v, 10);
    i = 0;
    do {
        ((short *)CX41_PTR(v, 0))[i] = -1;
        i++;
    } while (i < 10);
    return self;
}


extern void *ts4_assign_text_from_c_string(void *out, const char *s);
extern void ts4_call_seq_u32_off0_8819AD80(void *p);
extern void ts4_obj_vcall_28_then_2c_88778E88(void *obj, u32 *key, void *text, u32 f);
extern char *lbl_88D45A64;
extern char lbl_880DA42C[], lbl_880DA444[], lbl_880DA45C[];
extern char lbl_880DA3E0[], lbl_880DA3F8[], lbl_880DA410[];


extern void fn_888EB938(void *self);

/* 0x888F0650 */
u32 ts4_set_slot_pair_888F0650(char *self, u32 idx, int a, int b, u32 c)
{
    int x, y;
    if (CX41_U8(self, 0x15c)) {
        int v;
        char *e;
        CX41_U32(self, 0x158) = c;
        v = *(int *)CX41_PTR(self, 0x150);
        x = a;
        if (v != -1) x = v;
        ((int *)self)[idx + 0x4c] = x;
        v = *(int *)CX41_PTR(self, 0x150);
        y = b;
        if (v != -1) y = v;
        ((int *)self)[idx + 0x50] = y;
        e = self + idx * 0x3c + 0x1c;
        if (x == CX41_I32(e, 0x30) && y == CX41_I32(e, 0x34)) return 0;
        CX41_I32(e, 0x30) = x;
        CX41_I32(e, 0x34) = y;
        CX41_U8(e, 0x38) = 1;
        fn_888EB938(self);
        return 1;
    }
    return 0;
}

/* 0x888F0588 */
void ts4_sync_slot_pairs_888F0588(char *self)
{
    u32 v = *(u32 *)CX41_PTR(self, 0x10c);
    if (v != CX41_U32(self, 0x114)) CX41_U32(self, 0x114) = v;
    if (CX41_U8(self, 0x154)) {
        u32 chg = 0;
        char *s = self + 0x140;
        char *e = self + 0x4c;
        int i;
        CX41_U8(self, 0x154) = 0;
        i = 4;
        do {
            int a = CX41_I32(s, -0x10);
            int b = CX41_I32(s, 0);
            if (a != CX41_I32(e, 0) || b != CX41_I32(e, 4)) {
                CX41_I32(e, 0) = a;
                chg = 1;
                CX41_I32(e, 4) = b;
                CX41_U8(e, 8) = 1;
            }
            s += 4;
            e += 0x3c;
        } while (--i);
        if ((u8)chg) fn_888EB938(self);
        CX41_U32(self, 0x158) = 0;
    }
}

extern void fn_888C0698(void *self, u32 id);


extern void *ts4_if_call_seq_u32_lbl_88D459E4_8883F238(void *self);
extern char *ts4_pad_record_find_88614938(char *a, void *b);
extern void *fn_8860E208(void *svc, u32 id);
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);
extern void ts4_format_save_dir_88866980(void *self, char *buf, u32 n);
extern void fn_8861A008(void *svc, u32 id, void *p, char *buf);
extern void *fn_888CFFA8(void *self, void *node);
extern void ts4_registry_dispatch_888860A0(void *node);
extern char *lbl_88D45B38;


extern void ts4_if_set_u32_off0_8862BE08(void *out, void *src);
extern char lbl_880D8670[];
typedef u32 *(*Cx41Fn28)(void *obj, u32 *t, u32 b, u32 c);


extern void *ts4_find_service(u32 id);
extern void fn_886260B8(void *svc, u32 key, void *arg, u32 a, u32 b, void (*cb)(void), u32 c, u32 d);
extern void ts4_set_u8_lbl_88C46F6A_888BFCE0(void);
extern char lbl_88C46F6A[];

