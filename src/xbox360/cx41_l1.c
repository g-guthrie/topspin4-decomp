/* CW41 LTCG part 1 (context: cx41_ctx_get_u32.c). */
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
extern u32 ts4_if_get_u32_lbl_88D45B1C_888C0E18(u32 a, u32 b);
extern void ts4_school_play_power_up_888FBB40(u32 v);
extern void *ts4_hash_find_null_888E1D40(void *self);
extern char *ts4_find_record_by_key_881877A8(void *tbl, u32 *key);
extern void ts4_clear_script_prop_B1CA7E98_888C8190(void *obj);
extern void ts4_if_call_seq_NtSetEvent_8857C1F8(u32 h);
extern char lbl_88D45CC0[];
extern char *lbl_88D45B1C;

/* 0x888FBC50 */
void ts4_set_value_b0_888FBC50(char *self, u32 v, u32 b, u8 flag)
{
    CX41_U32(self, 0xb0) = v;
    CX41_U32(CX41_PTR(CX41_PTR(CX41_PTR(self, 4), 0x44), 0x10), 0x48) = v;
    ts4_if_get_u32_lbl_88D45B1C_888C0E18((u32)(unsigned long)self, b);
    if (flag) ts4_school_play_power_up_888FBB40(v);
}

/* 0x888FBBF0 */
void ts4_add_value_b0_888FBBF0(char *self, u32 d, u32 b, u8 flag)
{
    u32 v = d + CX41_U32(self, 0xb0);
    CX41_U32(self, 0xb0) = v;
    CX41_U32(CX41_PTR(CX41_PTR(CX41_PTR(self, 4), 0x44), 0x10), 0x48) = v;
    ts4_if_get_u32_lbl_88D45B1C_888C0E18((u32)(unsigned long)self, b);
    if (flag) ts4_school_play_power_up_888FBB40(CX41_U32(self, 0xb0));
}

