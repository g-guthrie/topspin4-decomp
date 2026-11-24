/* Swing_DLL.xex 0x88334648: frees each pair buffer (+4 of 8-byte pairs at +0x8, count from owner (+0xC)->+0x130) and then the
 * pair array, with fn_88315F10 on the global heap (file lbl_88029420, lines 0xAC/0xB1). agAE: /Oc. */
typedef struct Globals { char pad[4]; void *heap; } Globals;
extern Globals *lbl_88B3302C;
extern const char lbl_88029420[];
void fn_88315F10(void *heap, void *buf, const char *file, int line);
typedef struct Pair { unsigned int key; void *buf; } Pair;
typedef struct Owner { char pad[0x130]; int count; } Owner;
typedef struct Table { char pad[8]; Pair *pairs; Owner *owner; } Table;
int fn_88334648(Table *t)
{
    int i;
    if (t->pairs) {
        for (i = 0; i < t->owner->count; i++) {
            if (t->pairs[i].buf) {
                fn_88315F10(lbl_88B3302C->heap, t->pairs[i].buf, lbl_88029420, 0xac);
                t->pairs[i].buf = 0;
            }
        }
        fn_88315F10(lbl_88B3302C->heap, t->pairs, lbl_88029420, 0xb1);
        t->pairs = 0;
    }
    return 0;
}
