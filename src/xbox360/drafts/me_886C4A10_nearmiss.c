/* 0x886C4A10 near miss (34 off, /Oc plain or LTCG): zeroes item->value (+0x20) for every pointer in a vector,
 * walking backwards. Residue: game loads v->begin once per (unrolled / remainder) loop; we reload it every store.
 * restrict on v / on the item, an at() accessor, /Ow: no change. */
typedef struct Item { char p[0x20]; float value; } Item;
typedef struct ItemVec { int pad; Item **begin; Item **end; } ItemVec;
extern float lbl_8814B440;
void ts4_items_clear_value(ItemVec *v)
{
    int i = (int)(v->end - v->begin) - 1;
    if (i >= 0) { float z = lbl_8814B440; for (; i >= 0; i--) v->begin[i]->value = z; }
}
