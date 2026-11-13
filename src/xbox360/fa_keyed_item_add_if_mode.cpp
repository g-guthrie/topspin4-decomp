/* Family A: conditional "add keyed item if absent" thunks (Swing_DLL.xex).
   If *mode_flag == 1: scan the pointer vector [begin,end) for an element whose
   field +4 equals *key; if none, allocate an 8-byte object (vtable, key) with the
   shared allocator and append its pointer via fn_881898E8 (push_back-like).
   Otherwise forward the key value to fn_881507F0(vector, key). */
extern "C" {
extern void *lbl_88D45B38;   /* shared allocator heap, placeholder name */
void *fn_88613268(void *heap, int size, int align, int flags, int tag);
void fn_881898E8(void *vector, void *element_ptr);   /* push_back-like */
void fn_881507F0(void *vector, unsigned key);
extern int lbl_880D6B1C;   /* per-instance vtable, placeholder name */
extern int lbl_880D6B28;   /* per-instance vtable, placeholder name */
extern int lbl_880D6B34;   /* per-instance vtable, placeholder name */
extern int lbl_880D6B40;   /* per-instance vtable, placeholder name */
extern int lbl_880D6B4C;   /* per-instance vtable, placeholder name */
extern int lbl_880D6D78;   /* per-instance vtable, placeholder name */
extern int lbl_880DCF00;   /* per-instance vtable, placeholder name */
extern int lbl_880DF99C;   /* per-instance vtable, placeholder name */
extern int lbl_880DF9A8;   /* per-instance vtable, placeholder name */
extern int lbl_880DF9B4;   /* per-instance vtable, placeholder name */
extern int lbl_880E3AE8;   /* per-instance vtable, placeholder name */
extern int lbl_880E3AF4;   /* per-instance vtable, placeholder name */
extern int lbl_880E3B00;   /* per-instance vtable, placeholder name */
extern int lbl_880E3B0C;   /* per-instance vtable, placeholder name */
extern int lbl_880E438C;   /* per-instance vtable, placeholder name */
extern int lbl_880E4398;   /* per-instance vtable, placeholder name */
extern int lbl_880E43A4;   /* per-instance vtable, placeholder name */
extern int lbl_880E43B0;   /* per-instance vtable, placeholder name */
extern int lbl_880E43BC;   /* per-instance vtable, placeholder name */
extern int lbl_880E43C8;   /* per-instance vtable, placeholder name */
extern int lbl_880E43D4;   /* per-instance vtable, placeholder name */
extern int lbl_880E43E0;   /* per-instance vtable, placeholder name */
extern int lbl_880E43EC;   /* per-instance vtable, placeholder name */
extern int lbl_880E43F8;   /* per-instance vtable, placeholder name */
extern int lbl_880E4404;   /* per-instance vtable, placeholder name */
extern int lbl_880E4410;   /* per-instance vtable, placeholder name */
extern int lbl_880E441C;   /* per-instance vtable, placeholder name */
extern int lbl_880E4428;   /* per-instance vtable, placeholder name */
extern int lbl_880E4434;   /* per-instance vtable, placeholder name */
extern int lbl_880E4440;   /* per-instance vtable, placeholder name */
extern int lbl_880E444C;   /* per-instance vtable, placeholder name */
extern int lbl_880E4458;   /* per-instance vtable, placeholder name */
extern int lbl_880E4464;   /* per-instance vtable, placeholder name */
extern int lbl_880E4470;   /* per-instance vtable, placeholder name */
extern int lbl_880E4488;   /* per-instance vtable, placeholder name */
extern int lbl_880E4494;   /* per-instance vtable, placeholder name */
extern int lbl_880F3574;   /* per-instance vtable, placeholder name */
extern int lbl_880F3580;   /* per-instance vtable, placeholder name */
extern int lbl_880F358C;   /* per-instance vtable, placeholder name */
extern int lbl_880F382C;   /* per-instance vtable, placeholder name */
extern int lbl_880F3844;   /* per-instance vtable, placeholder name */
extern int lbl_880F4E68;   /* per-instance vtable, placeholder name */
extern int lbl_880F4E74;   /* per-instance vtable, placeholder name */
extern int lbl_880F4E80;   /* per-instance vtable, placeholder name */
extern int lbl_880F4E8C;   /* per-instance vtable, placeholder name */
extern int lbl_880F4E98;   /* per-instance vtable, placeholder name */
extern int lbl_880F4EA4;   /* per-instance vtable, placeholder name */
extern int lbl_880F4EB0;   /* per-instance vtable, placeholder name */
extern int lbl_880F4EBC;   /* per-instance vtable, placeholder name */
extern int lbl_880F4EC8;   /* per-instance vtable, placeholder name */
extern int lbl_880F4EE0;   /* per-instance vtable, placeholder name */
extern int lbl_880F4EEC;   /* per-instance vtable, placeholder name */
extern int lbl_880F4EF8;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F04;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F10;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F1C;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F28;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F34;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F40;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F4C;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F58;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F64;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F70;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F7C;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F88;   /* per-instance vtable, placeholder name */
extern int lbl_880F4F94;   /* per-instance vtable, placeholder name */
extern int lbl_880F4FA0;   /* per-instance vtable, placeholder name */
extern int lbl_880F4FAC;   /* per-instance vtable, placeholder name */
extern int lbl_880F4FB8;   /* per-instance vtable, placeholder name */
extern int lbl_880F4FC4;   /* per-instance vtable, placeholder name */
extern int lbl_880F6080;   /* per-instance vtable, placeholder name */
extern int lbl_880F608C;   /* per-instance vtable, placeholder name */
}

struct ts4_keyed_item;
struct ts4_item_vector { ts4_keyed_item **begin; ts4_keyed_item **end; };

inline void *operator new(unsigned, void *heap, int size, int align, int flags, int tag)
{ return fn_88613268(heap, size, align, flags, tag); }

#define TS4_KEYED_ITEM_ADD_IF_MODE(NAME, VTBL) \
struct NAME##_item { void *vtbl; unsigned key; \
    NAME##_item(unsigned k) { key = k; vtbl = &VTBL; } }; \
static __forceinline void NAME##_push(ts4_item_vector *vec, NAME##_item *item) \
{ fn_881898E8(vec, &item); } \
extern "C" void NAME(ts4_item_vector *vec, unsigned *key, unsigned char *mode_flag) \
{ \
    if (*mode_flag == 1) { \
        NAME##_item **end = (NAME##_item **)vec->end; \
        NAME##_item **it = (NAME##_item **)vec->begin; \
        unsigned k = *key; \
        for (; it != end; it++) \
            if ((*it)->key == k) return; \
        NAME##_item *tmp = new(lbl_88D45B38, 8, 4, 0, 2) NAME##_item(k); \
        NAME##_push(vec, tmp); \
    } else \
        fn_881507F0(vec, *key); \
}

/* Swing_DLL.xex 0x886487A0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886487A0, lbl_880F608C)
/* Swing_DLL.xex 0x88649058 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88649058, lbl_880F6080)
/* Swing_DLL.xex 0x8867E2C0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8867E2C0, lbl_880F4FC4)
/* Swing_DLL.xex 0x8867EC50 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8867EC50, lbl_880F4FB8)
/* Swing_DLL.xex 0x886810C0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886810C0, lbl_880F4FAC)
/* Swing_DLL.xex 0x886811F8 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886811F8, lbl_880F4FA0)
/* Swing_DLL.xex 0x886812D8 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886812D8, lbl_880F4F94)
/* Swing_DLL.xex 0x88681468 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88681468, lbl_880F4F88)
/* Swing_DLL.xex 0x886815E8 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886815E8, lbl_880F4F7C)
/* Swing_DLL.xex 0x88681768 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88681768, lbl_880F4F70)
/* Swing_DLL.xex 0x88681DC0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88681DC0, lbl_880F4F64)
/* Swing_DLL.xex 0x88681F40 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88681F40, lbl_880F4F58)
/* Swing_DLL.xex 0x886820C0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886820C0, lbl_880F4F4C)
/* Swing_DLL.xex 0x88682A78 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88682A78, lbl_880F4F40)
/* Swing_DLL.xex 0x88682E60 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88682E60, lbl_880F4F34)
/* Swing_DLL.xex 0x886871C0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886871C0, lbl_880F4F28)
/* Swing_DLL.xex 0x8868BFB0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8868BFB0, lbl_880F4F1C)
/* Swing_DLL.xex 0x8868C998 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8868C998, lbl_880F4F10)
/* Swing_DLL.xex 0x8868CE18 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8868CE18, lbl_880F4F04)
/* Swing_DLL.xex 0x8868CF98 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8868CF98, lbl_880F4EF8)
/* Swing_DLL.xex 0x8868D118 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8868D118, lbl_880F4EEC)
/* Swing_DLL.xex 0x8868D298 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8868D298, lbl_880F4EE0)
/* Swing_DLL.xex 0x88690208 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88690208, lbl_880F4EC8)
/* Swing_DLL.xex 0x88690760 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88690760, lbl_880F4EBC)
/* Swing_DLL.xex 0x88690840 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88690840, lbl_880F4EB0)
/* Swing_DLL.xex 0x886927C0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886927C0, lbl_880F4EA4)
/* Swing_DLL.xex 0x88692F60 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88692F60, lbl_880F4E98)
/* Swing_DLL.xex 0x88693630 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88693630, lbl_880F4E8C)
/* Swing_DLL.xex 0x88693710 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88693710, lbl_880F4E80)
/* Swing_DLL.xex 0x88693D48 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88693D48, lbl_880F4E74)
/* Swing_DLL.xex 0x88693E28 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88693E28, lbl_880F4E68)
/* Swing_DLL.xex 0x886D1B90 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886D1B90, lbl_880F3844)
/* Swing_DLL.xex 0x886D2910 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886D2910, lbl_880F382C)
/* Swing_DLL.xex 0x886E7FC8 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886E7FC8, lbl_880F358C)
/* Swing_DLL.xex 0x886E80E8 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886E80E8, lbl_880F3580)
/* Swing_DLL.xex 0x886E8228 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_886E8228, lbl_880F3574)
/* Swing_DLL.xex 0x887F9CE0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887F9CE0, lbl_880E4494)
/* Swing_DLL.xex 0x887F9E38 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887F9E38, lbl_880E4488)
/* Swing_DLL.xex 0x887F9FC8 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887F9FC8, lbl_880E4470)
/* Swing_DLL.xex 0x887FA0A8 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA0A8, lbl_880E4464)
/* Swing_DLL.xex 0x887FA188 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA188, lbl_880E4458)
/* Swing_DLL.xex 0x887FA268 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA268, lbl_880E444C)
/* Swing_DLL.xex 0x887FA348 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA348, lbl_880E4440)
/* Swing_DLL.xex 0x887FA428 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA428, lbl_880E4434)
/* Swing_DLL.xex 0x887FA508 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA508, lbl_880E4428)
/* Swing_DLL.xex 0x887FA5E8 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA5E8, lbl_880E441C)
/* Swing_DLL.xex 0x887FA6C8 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA6C8, lbl_880E4410)
/* Swing_DLL.xex 0x887FA7A8 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA7A8, lbl_880E4404)
/* Swing_DLL.xex 0x887FA888 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA888, lbl_880E43F8)
/* Swing_DLL.xex 0x887FA968 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FA968, lbl_880E43EC)
/* Swing_DLL.xex 0x887FAB00 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FAB00, lbl_880E43E0)
/* Swing_DLL.xex 0x887FABE0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FABE0, lbl_880E43D4)
/* Swing_DLL.xex 0x887FACC0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FACC0, lbl_880E43C8)
/* Swing_DLL.xex 0x887FADA0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FADA0, lbl_880E43BC)
/* Swing_DLL.xex 0x887FAE80 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FAE80, lbl_880E43B0)
/* Swing_DLL.xex 0x887FAF60 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FAF60, lbl_880E43A4)
/* Swing_DLL.xex 0x887FB040 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FB040, lbl_880E4398)
/* Swing_DLL.xex 0x887FB190 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_887FB190, lbl_880E438C)
/* Swing_DLL.xex 0x88800EB0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88800EB0, lbl_880E3B0C)
/* Swing_DLL.xex 0x88800F90 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88800F90, lbl_880E3B00)
/* Swing_DLL.xex 0x888010E0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_888010E0, lbl_880E3AF4)
/* Swing_DLL.xex 0x88801218 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88801218, lbl_880E3AE8)
/* Swing_DLL.xex 0x8887DA90 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8887DA90, lbl_880DF9B4)
/* Swing_DLL.xex 0x8887DF50 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8887DF50, lbl_880DF9A8)
/* Swing_DLL.xex 0x8887E328 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_8887E328, lbl_880DF99C)
/* Swing_DLL.xex 0x88890F50 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88890F50, lbl_880DCF00)
/* Swing_DLL.xex 0x88918CA0 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88918CA0, lbl_880D6D78)
/* Swing_DLL.xex 0x88928A10 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88928A10, lbl_880D6B4C)
/* Swing_DLL.xex 0x88929120 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88929120, lbl_880D6B40)
/* Swing_DLL.xex 0x88929470 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88929470, lbl_880D6B34)
/* Swing_DLL.xex 0x88929550 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88929550, lbl_880D6B28)
/* Swing_DLL.xex 0x88929758 */ TS4_KEYED_ITEM_ADD_IF_MODE(ts4_keyed_item_list_add_unique_if_mode_88929758, lbl_880D6B1C)
