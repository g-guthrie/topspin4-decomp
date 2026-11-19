/* 0x8848B978: Returns the slot record for key: looks up the u8 slot index in the table at +0x20 (0xFF = none, returns 0) and returns layout + stride * slot + headerBlocks * 32 + 0x30. */
/* Near miss (agAH): 3 off: lbzx operand order and the two registers feeding it (tried key[table], a local table pointer, pointer-plus-key). */
typedef struct Layout { char pad[6]; unsigned short headerBlocks; char pad8[2]; unsigned char stride; } Layout;
typedef struct Map { char pad[0x20]; unsigned char *slotOf; char pad24[0x18]; Layout *layout; } Map;
static __forceinline void *Layout_Slot(Layout *l, short slot)
{
    return (char *)l + l->stride * slot + l->headerBlocks * 32 + 0x30;
}
void *fn_8848B978(Map *m, unsigned short key)
{
    int slot = m->slotOf[key];
    if (slot == 0xff)
        return 0;
    return Layout_Slot(m->layout, (short)slot);
}
