/* NEAR MISS (agO, 2026-11-19): 1 off on plain and LTCG (/Oc): add r11,r11,r30 (base first) vs add r11,r30,r11.
 * Same operand-order residue as the self-relative add-order group. Tried pointer local, explicit +, i[base]. */
/* Swing_DLL.xex 0x88432B08: constructs the table at self (fn_88423CE0) and inserts every {key, value} pair of src
 * with fn_88423660; returns self. */
typedef struct Pair { int key; int value; } Pair;
typedef struct PairVec { Pair *items; int count; } PairVec;
void fn_88423CE0(void *self);
void fn_88423660(void *self, int key, int value);

void *fn_88432B08(void *self, PairVec *src)
{
    int i;
    fn_88423CE0(self);
    for (i = 0; i < src->count; i++)
        fn_88423660(self, src->items[i].key, src->items[i].value);
    return self;
}
