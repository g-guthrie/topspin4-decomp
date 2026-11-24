/* Swing_DLL.xex 0x884A2940-0x884A2984, executable version 0.0.0.3. */
typedef struct Ts4IdList {
    char pad[0x6C];
    unsigned *items;
    int count;
} Ts4IdList;
int ts4_find_index_884A2940(Ts4IdList *list, unsigned key)
{
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->items[i] == key) {
            return i;
        }
    }
    return -1;
}
