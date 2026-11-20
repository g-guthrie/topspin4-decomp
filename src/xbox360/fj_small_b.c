/* Tiny accessor/thunk/initializer functions (Swing_DLL.xex), file fj_small_b.c */
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Ts4Object { void *vtable; } Ts4Object;
#define W(p,o) (*(u32 *)((char *)(p) + (o)))
#define H(p,o) (*(u16 *)((char *)(p) + (o)))
#define B(p,o) (*(u8 *)((char *)(p) + (o)))
#define D(p,o) (*(u64 *)((char *)(p) + (o)))
#define FL(p,o) (*(float *)((char *)(p) + (o)))
#define LP(p,o) (*(char **)((char *)(p) + (o)))
#define VT(p,s) ((*(void ***)(p))[s])
extern void fn_88401F80(char *);
extern void fn_8826B918(char *);
extern void fn_88286E20(char *);
extern void fn_88286E38(char *);
extern void fn_8825DA28(u32 *);
extern void fn_88226B90(char *, u32, u32);
extern void ts4_forward_88718280(u32 *);
extern char lbl_880D5B10[];

/* call_for_each_16_byte_entry */
/* Swing_DLL.xex 0x8865A188 */
void ts4_call_for_each_16_byte_entry_8865A188(char *a)
{
    char *end = LP(a, 0x10);
    char *p = LP(a, 0xc);
    for (; p != end; p += 16) fn_88401F80(p);
}

/* Swing_DLL.xex 0x8865A720 */
void ts4_call_for_each_16_byte_entry_8865A720(char *a)
{
    char *end = LP(a, 0x10);
    char *p = LP(a, 0xc);
    for (; p != end; p += 16) fn_88401F80(p);
}

/* Swing_DLL.xex 0x8865A770 */
void ts4_call_for_each_16_byte_entry_8865A770(char *a)
{
    char *end = LP(a, 0x10);
    char *p = LP(a, 0xc);
    for (; p != end; p += 16) fn_8826B918(p);
}

/* call_for_each_nonnull_pointer_entry */
/* Swing_DLL.xex 0x8827F370 */
void ts4_call_for_each_nonnull_pointer_entry_8827F370(char *a)
{
    char **end = (char **)LP(a, 0x30);
    char **p = (char **)LP(a, 0x2c);
    for (; p != end; p++) {
        if (*p) fn_88286E20(*p);
    }
}

/* Swing_DLL.xex 0x8827F3C8 */
void ts4_call_for_each_nonnull_pointer_entry_8827F3C8(char *a)
{
    char **end = (char **)LP(a, 0x30);
    char **p = (char **)LP(a, 0x2c);
    for (; p != end; p++) {
        if (*p) fn_88286E38(*p);
    }
}

/* call_for_each_word_then_release_range */
/* Swing_DLL.xex 0x88752B80 */
void ts4_call_for_each_word_then_release_range_88752B80(char *a)
{
    u32 *p = (u32 *)W(a, 0);
    u32 *end = (u32 *)W(a, 4);
    for (; p != end; p++) fn_8825DA28(p);
    fn_88226B90(a, W(a, 0), W(a, 4));
}

/* Swing_DLL.xex 0x88752C10 */
void ts4_call_for_each_word_then_release_range_88752C10(char *a)
{
    u32 *p = (u32 *)W(a, 0);
    u32 *end = (u32 *)W(a, 4);
    for (; p != end; p++) ts4_forward_88718280(p);
    fn_88226B90(a, W(a, 0), W(a, 4));
}

/* call_slot5_if_valid_then_slot0 */
/* Swing_DLL.xex 0x8845B4B0 */
void ts4_call_slot5_if_valid_then_slot0_8845B4B0(char *a, int b)
{
    u16 v = H(a, 12);
    if (v != 0xFFFF) {
        void *o = LP(a, 8);
        ((void (*)(void *, u32, int))VT(o, 5))(o, v, b);
    }
    ((void (*)(void *, int))VT(a, 0))(a, 1);
}

/* Swing_DLL.xex 0x8845C548 */
void ts4_call_slot5_if_valid_then_slot0_8845C548(char *a, int b)
{
    u16 v = H(a, 12);
    if (v != 0xFFFF) {
        void *o = LP(a, 8);
        ((void (*)(void *, u32, int))VT(o, 5))(o, v, b);
    }
    ((void (*)(void *, int))VT(a, 0))(a, 1);
}

/* Swing_DLL.xex 0x8845D4E8 */
void ts4_call_slot5_if_valid_then_slot0_8845D4E8(char *a, int b)
{
    u16 v = H(a, 12);
    if (v != 0xFFFF) {
        void *o = LP(a, 8);
        ((void (*)(void *, u32, int))VT(o, 5))(o, v, b);
    }
    ((void (*)(void *, int))VT(a, 0))(a, 1);
}

/* call_vtable_slot4_then_slot5_with_zero */
/* Swing_DLL.xex 0x887EFCE8 */
void ts4_call_vtable_slot4_then_slot5_with_zero_887EFCE8(char *a)
{
    ((void (*)(void *, int))VT(a, 4))(a, 0);
    ((void (*)(void *, int))VT(a, 5))(a, 0);
}

/* Swing_DLL.xex 0x887EFE48 */
void ts4_call_vtable_slot4_then_slot5_with_zero_887EFE48(char *a)
{
    ((void (*)(void *, int))VT(a, 4))(a, 0);
    ((void (*)(void *, int))VT(a, 5))(a, 0);
}

/* set_vtable_call_table_fn_if_field4_valid */
/* Swing_DLL.xex 0x88932E80 */
void ts4_set_vtable_call_table_fn_if_field4_valid_88932E80(char *a)
{
    *(void **)a = lbl_880D5B10;
    if ((int)W(a, 4) != -1) {
        (*(void (**)(char *, int))(lbl_880D5B10 + 0x14))(a, (int)W(a, 4));
        W(a, 4) = (u32)-1;
    }
}

/* Swing_DLL.xex 0x88934920 */
void ts4_set_vtable_call_table_fn_if_field4_valid_88934920(char *a)
{
    *(void **)a = lbl_880D5B10;
    if ((int)W(a, 4) != -1) {
        (*(void (**)(char *, int))(lbl_880D5B10 + 0x14))(a, (int)W(a, 4));
        W(a, 4) = (u32)-1;
    }
}

/* dtor_two_vtables_destroy_field12 */
/* dtor_clear_global_then_two_calls */
/* ctor_base_then_init_range_fields */