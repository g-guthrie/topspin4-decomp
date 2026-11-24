/* Swing_DLL.xex 0x8879CBE8: find the slot whose id matches key->id in the owner's self-relative slot table; build its 28-byte record vector (8879C7C0) and return a copy (88213EB8), or an empty vector.
 * /Oc. The slot array is at a self-relative offset from the table's offset field; the temporary vector is freed after the copy. */
typedef struct Rec28 { unsigned int w[7]; } Rec28;
typedef struct Rec28Vec { Rec28 *first; Rec28 *last; Rec28 *end; } Rec28Vec;
typedef struct Slot { unsigned int w[4]; unsigned int id; unsigned int pad; } Slot;
typedef struct SlotTable { unsigned char head[0x18]; int offset; int count; } SlotTable;
typedef struct Owner { unsigned char head[0x318]; SlotTable *table; } Owner;
typedef struct Key { unsigned int kind; unsigned int id; } Key;
void ts4_destroy_owned_object(void *obj);
Rec28Vec *fn_88213EB8(Rec28Vec *v, const Rec28Vec *src);
Rec28Vec *fn_8879C7C0(Rec28Vec *out, Owner *o, Slot *slot, const Key *key);

Rec28Vec *fn_8879CBE8(Rec28Vec *out, Owner *o, const Key *key)
{
    int *offset = &o->table->offset;
    int count = o->table->count;
    int i;
    for (i = 0; i < count; i++) {
        Slot *slot = (Slot *)((char *)offset + *offset) + i;
        if (slot->id == key->id) {
            Rec28Vec tmp;
            fn_8879C7C0(&tmp, o, slot, key);
            fn_88213EB8(out, &tmp);
            if (tmp.first) ts4_destroy_owned_object(tmp.first);
            return out;
        }
    }
    out->first = 0;
    out->last = 0;
    out->end = 0;
    return out;
}
