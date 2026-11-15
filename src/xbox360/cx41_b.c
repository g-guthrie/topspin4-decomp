/* CW41 part b: camera / minigame / publisher small objects (0x888D8000-0x88900000). */
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


#ifndef _MSC_VER
#define __forceinline inline
#endif
extern void ts4_loop_get_fn_888D7920_888DAF90(void *self, void *a, u32 b);
static __forceinline char *cx41_tbl_end(char *t)
{
    int rel = CX41_I32(t, 0);
    char *r = 0;
    if (rel != -1) r = (char *)((unsigned long)(CX41_U32(t, 4) * 8 + rel) + (unsigned long)t);
    return r;
}
static __forceinline char *cx41_tbl_begin(char *t)
{
    int rel = CX41_I32(t, 0);
    char *r = 0;
    if (rel != -1) r = (char *)((unsigned long)rel + (unsigned long)t);
    return r;
}
static __forceinline char *cx41_rel_ptr(char *p)
{
    int r = CX41_I32(p, 0);
    if (r != -1) return p + r;
    return 0;
}
/* 0x888DB010: call the handler for every self-relative table entry */
void ts4_visit_rel_table_888DB010(char *self)
{
    void **vt = (void **)CX41_PTR(self, 8);
    char *t = ((char *(*)(void *, u32))vt[0x4c / 4])(self + 8, 0);
    char *end = cx41_tbl_end(t);
    char *p = cx41_tbl_begin(t);
    for (; end != p; p += 8) {
        ts4_loop_get_fn_888D7920_888DAF90(self, cx41_rel_ptr(p), CX41_U32(p, 4));
    }
}
