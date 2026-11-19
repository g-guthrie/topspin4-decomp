/* Swing_DLL.xex 0x883E4F58: open-addressing hash find: probes slots from hash(key) % size, wrapping once,
 * stops at an empty slot, returns the slot whose eq(key, item) is true. agAE: /O1. */
typedef unsigned int (*HashFn)(const void *key);
typedef unsigned char (*EqFn)(const void *key, void *item);
typedef struct HashTable { char pad[8]; void **slots; unsigned int size; EqFn eq; HashFn hash; } HashTable;
void *fn_883E4F58(HashTable *t, const void *key)
{
    unsigned int start, i;
    if (t->slots) {
        start = t->hash(key) % t->size;
        i = start;
        do {
            void *item = t->slots[i];
            if (!item) break;
            if (t->eq(key, item)) return item;
            i = (i + 1) % t->size;
        } while (i != start);
    }
    return 0;
}
