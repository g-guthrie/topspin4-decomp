/* nearmiss: 3 off; the idx*5 slot index uses clrlwi r9 / clrlslwi r11 in the target, ours does them in the other order. perm_auto --ltcg (33 candidates) found nothing better. Check: --flags /Oc --include fn_887E9D78 --context 'flags(/Ob1):src/xbox360/me_ts4_handle_is_valid_887E9D78.c' --context src/xbox360/pp1_pool_primer.c */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Ref { u8 pad[0xc]; int refs; } Ref;
typedef struct Obj { u8 pad[0xc]; Ref *ref; } Obj;
typedef struct Slot { u32 handle; int pad; Obj *obj; int pad2[2]; } Slot;
typedef struct T { u8 p[0x30]; Slot *slots; } T;
extern u8 fn_887E9D78(T *t, u32 h, u8 mode);
void fn_887EA898(T *t, u32 h)
{
    if (fn_887E9D78(t, h, 0) == 1) {
        Ref *r = t->slots[h & 0x3fff].obj->ref;
        if (r)
            r->refs--;
    }
}
