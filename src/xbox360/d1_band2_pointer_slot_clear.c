/* Swing_DLL.xex family of pointer array slot clearing helpers, executable version 0.0.0.3. */
typedef struct Ts4PointerArray {
    void **items;
    int count;
} Ts4PointerArray;

void ts4_clear_pointer_slot_8846AF88(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0xf0);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846AFD8(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x114);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B028(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0xfc);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B078(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x108);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B0C8(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x12c);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B118(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x150);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B168(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x138);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B1B8(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x144);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B208(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x168);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B258(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x15c);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B2A8(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x174);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B2F8(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x120);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}

void ts4_clear_pointer_slot_8846B348(char *owner, void *pointer)
{
    Ts4PointerArray *array = (Ts4PointerArray *)(owner + 0x180);
    int i = 0;
    if (array->count > 0) {
        do {
            if (array->items[i] == pointer) {
                goto found;
            }
            i++;
        } while (i < array->count);
    }
    i = -1;
found:
    array->items[i] = 0;
}
