/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88475BF8: remove-by-key from a 16-byte slot array (+0x74), returning the removed 8-byte value through a hidden
 * pointer (0 if absent). Find uses r->slots.* and the remove a separate SlotArray *a, so the count is reloaded.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_88475BF8_nearmiss.c (Q5S sweep, 2026-11-24): the `rpadN` locals are OP1 symbol-numbering pads (docs/agents/regalloc.md, family `pad`).
 * See work/specs/Q5S/sweep_88475BF8.json for route and flags. */
typedef struct Value { unsigned __int64 bits; } Value;
typedef struct Slot { unsigned int key; unsigned int pad; Value value; } Slot;
typedef struct SlotArray { Slot *data; int count; } SlotArray;
typedef struct Registry { unsigned char pad[0x74]; SlotArray slots; } Registry;
Value *ts4_registry_remove_88475BF8(Value *out, Registry *r, unsigned int key)
{ int rpad0 = 0; int rpad1 = 0; int rpad2 = 0; 
    int i;
    for (i = 0; i < r->slots.count; i++) {
        if (r->slots.data[i].key == key) {
            Slot s = r->slots.data[i];
            SlotArray *a = &r->slots;
            a->count--;
            for (; i < a->count; i++) a->data[i] = a->data[i + 1];
            {  *out = s.value; }
            return out;
        }
    }
    out->bits = 0;
    return out;
}
