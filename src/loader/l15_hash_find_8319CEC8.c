/* Loader_DLL.xex 0x8319CEC8-0x8319CF10, executable version 0.0.0.3. */
typedef struct Ts4lItem8319CEC8 { char pad[0x30]; int key; } Ts4lItem8319CEC8;
typedef struct Ts4lNode8319CEC8 { Ts4lItem8319CEC8 *item; struct Ts4lNode8319CEC8 *next; } Ts4lNode8319CEC8;
typedef struct { char pad[0x20]; Ts4lNode8319CEC8 *head; char pad2[0x4]; } Ts4lBucket8319CEC8;

Ts4lItem8319CEC8 *ts4l_hash_find_8319CEC8(Ts4lBucket8319CEC8 *t, int key)
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
