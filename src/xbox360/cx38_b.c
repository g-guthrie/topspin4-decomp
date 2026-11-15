/* CW38 part b: PlayerCreator/UI helpers in 0x887B0000-0x887D0000. */
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 fn_887CB978(void *, void *);
extern u32 ts4_if_call_seq_RtlInitAnsiString_8857C370(void *);

int ts4_lookup_is_minus1_887CBA00(void *a, void *b)
{
    if (fn_887CB978(a, b) == 1) {
        return ts4_if_call_seq_RtlInitAnsiString_8857C370(b) != 0xFFFFFFFFu;
    }
    return 0;
}

extern u32 ts4_tailcall_XamContentClose_8857B2D8(void *, int);

int ts4_close_content_887CBBE8(char *self)
{
    int r = 0;
    if (self[0x370] == 1 && *(int *)(self + 0x374) == 0) {
        if (ts4_tailcall_XamContentClose_8857B2D8(*(void **)(self + 0x364), 0) == 0) {
            r = 1;
            self[0x370] = 0;
        }
    }
    return r;
}

typedef struct SvcB1C { char pad[0x220]; u32 f220; u32 f224; } SvcB1C;
extern SvcB1C *lbl_88D45B1C;
extern void ts4_destroy_owned_object(void *);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *);

extern void fn_887B62B8(void *, int);
extern void fn_887AD4F0(void *);
extern void fn_88798CF8(void *, int);

void ts4_update_rows_887B9F08(char *self)
{
    fn_887B62B8(self, 0);
    if (self[0x1fa] == 0) {
        u32 i = 0;
        u32 off;
        if (*(u32 *)(self + 0x1c4) > 0) {
            off = 0;
            do {
                fn_887AD4F0(*(char **)(self + 0xa4) + off);
                fn_88798CF8(*(char **)(self + 0xa4) + off, *(int *)(self + 0x1b0));
                i++;
                off += 0x98;
            } while (i < *(u32 *)(self + 0x1c4));
        }
    }
}

extern u32 ts4_check_hash_pair_887CE408(void *);

int ts4_check_hashes_887CF748(char *self)
{
    if (*(u32 *)(*(char **)(self + 0x2c) + 0x240) == 0xeae9069eU) {
        if (*(u32 *)(*(char **)(self + 0x38) + 0x2c) == 0xf202bb09U) return 1;
        if ((u8)ts4_check_hash_pair_887CE408(self)) return 1;
    }
    return 0;
}
