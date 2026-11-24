/* CW40 ltcg part b: callers of the slot-table validity leaf fn_887E9D78 (r4 stays live across the call). LTCG route, context cx40_ctx_b.c, /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;

extern u32 fn_887E9D78(void *, u32, u8);

/* 0x887EAA40: if the slot id is valid, clear the first word of its 20-byte entry. */
void ts4_slot_clear_887EAA40(char *self, u32 idx)
{
    if ((u8)fn_887E9D78(self, idx, 0) == 1) {
        *(u32 *)(*(char **)(self + 0x30) + (idx & 0x3fff) * 20) = 0;
    }
}
