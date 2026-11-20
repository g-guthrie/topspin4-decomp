/* Swing_DLL.xex 0x883242E0-0x883243AC, executable version 0.0.0.3. */
typedef unsigned int u32;

typedef struct Ts4PairTable {
    char pad0[0x4C];
    u32 ready;
    char pad1[0x88 - 0x50];
    u32 values[8];
} Ts4PairTable;

int ts4_pair_table_lookup_883242E0(
    Ts4PairTable *table,
    int index,
    u32 *first,
    u32 *second
)
{
    if (table->ready == 0) {
        return 0x24;
    }
    if (first != 0) {
        if (index == 0) {
            *first = table->values[0];
        } else if (index == 1) {
            *first = table->values[2];
        } else if (index == 2) {
            *first = table->values[4];
        } else if (index == 3) {
            *first = table->values[6];
        } else {
            return 0x25;
        }
    }
    if (second != 0) {
        if (index == 0) {
            *second = 0;
            return 0;
        } else if (index == 1) {
            *second = table->values[3];
            return 0;
        } else if (index == 2) {
            *second = table->values[5];
            return 0;
        } else if (index == 3) {
            *second = table->values[7];
        } else {
            return 0x25;
        }
    }
    return 0;
}
