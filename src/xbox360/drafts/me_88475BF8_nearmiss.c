/* Near-miss for Swing_DLL.xex 0x88475BF8 (/Oc): 1 instruction off.
 * Remove-by-key from a 16-byte slot array, returning the removed 8-byte value through a hidden pointer (0 if absent).
 * Find uses r->slots.* and the remove uses a separate SlotArray *a, so the count is reloaded (agAD CSE-by-operand rule).
 * Remaining diff: the shift loop emits add r11,r11,r9 where the target has add r11,r9,r11 (data + i*16 operand order). */
typedef struct Value { unsigned __int64 bits; } Value;
typedef struct Slot { unsigned int key; unsigned int pad; Value value; } Slot;
typedef struct SlotArray { Slot *data; int count; } SlotArray;
typedef struct Registry { unsigned char pad[0x74]; SlotArray slots; } Registry;
Value *fn_88475BF8(Value *out, Registry *r, unsigned int key)
{
    int i;
    for (i = 0; i < r->slots.count; i++) {
        if (r->slots.data[i].key == key) {
            Slot s = r->slots.data[i];
            SlotArray *a = &r->slots;
            a->count--;
            for (; i < a->count; i++) a->data[i] = a->data[i + 1];
            *out = s.value;
            return out;
        }
    }
    out->bits = 0;
    return out;
}
