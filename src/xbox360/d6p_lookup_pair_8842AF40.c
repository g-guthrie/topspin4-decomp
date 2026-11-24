/* Swing_DLL.xex 0x8842AF40-0x8842AF8C, executable version 0.0.0.3. */
typedef struct Ts4Pair { unsigned key; void *value; } Ts4Pair;
typedef struct Ts4PairList { Ts4Pair *items; int count; } Ts4PairList;
void *ts4_lookup_pair_8842AF40(unsigned key, Ts4PairList *list)
{
    int i;
    for (i = 0; i < list->count; i++) {
        if (list->items[i].key == key) {
            return list->items[i].value;
        }
    }
    return 0;
}
