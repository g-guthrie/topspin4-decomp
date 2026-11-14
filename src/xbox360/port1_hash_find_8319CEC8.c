/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l15_hash_find_8319CEC8.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
typedef struct Ts4lItem8319CEC8 { char pad[0x30]; int key; } Ts4lItem8319CEC8;
typedef struct Ts4lNode8319CEC8 { Ts4lItem8319CEC8 *item; struct Ts4lNode8319CEC8 *next; } Ts4lNode8319CEC8;
typedef struct { char pad[0x20]; Ts4lNode8319CEC8 *head; char pad2[0x4]; } Ts4lBucket8319CEC8;



/* Swing_DLL.xex 0x885B5320 */
Ts4lItem8319CEC8 *ts4_hash_find_885B5320(Ts4lBucket8319CEC8 *t, int key)
{
    Ts4lNode8319CEC8 *n = t[key % 13].head;
    Ts4lNode8319CEC8 *c;
    Ts4lItem8319CEC8 *it;
    do {
        c = n;
        if (c) {
            n = c->next;
            it = c->item;
        } else {
            it = 0;
        }
    } while (it->key != key);
    return it;
}

