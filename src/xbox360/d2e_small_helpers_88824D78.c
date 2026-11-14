/* Swing_DLL.xex 0x88824D78-0x888846D8, executable version 0.0.0.3. */
typedef unsigned short ts4_u16;

typedef struct Ts4KeyedItem { unsigned char reserved[0x180]; int key; } Ts4KeyedItem;
typedef struct Ts4KeyedList { unsigned char reserved[0x20]; Ts4KeyedItem **begin; Ts4KeyedItem **end; } Ts4KeyedList;
typedef struct Ts4VCallTable { unsigned char reserved[0x28]; void (*invoke)(void *result, void *object, int value); } Ts4VCallTable;
typedef struct Ts4VCallObject { Ts4VCallTable *vtable; } Ts4VCallObject;

extern void *lbl_88D459DC;
void fn_88865388(void *service, int mode, void *target, unsigned char *flag);

/* Length of a zero-terminated UTF-16 string. */
int ts4_wide_string_length_88824D78(const ts4_u16 *text)
{
    const ts4_u16 *end = text;
    while (*end) {
        ++end;
    }
    return (int)(end - text);
}

/* Length of a zero-terminated UTF-16 string. */
int ts4_wide_string_length_8882B340(const ts4_u16 *text)
{
    const ts4_u16 *end = text;
    while (*end) {
        ++end;
    }
    return (int)(end - text);
}

/* Length of a zero-terminated UTF-16 string. */
int ts4_wide_string_length_8882DB10(const ts4_u16 *text)
{
    const ts4_u16 *end = text;
    while (*end) {
        ++end;
    }
    return (int)(end - text);
}

/* Length of a zero-terminated UTF-16 string. */
int ts4_wide_string_length_8882EDC8(const ts4_u16 *text)
{
    const ts4_u16 *end = text;
    while (*end) {
        ++end;
    }
    return (int)(end - text);
}

/* Length of a zero-terminated UTF-16 string. */
int ts4_wide_string_length_888345D0(const ts4_u16 *text)
{
    const ts4_u16 *end = text;
    while (*end) {
        ++end;
    }
    return (int)(end - text);
}

/* Length of a zero-terminated UTF-16 string. */
int ts4_wide_string_length_888362F8(const ts4_u16 *text)
{
    const ts4_u16 *end = text;
    while (*end) {
        ++end;
    }
    return (int)(end - text);
}

/* Copies a UTF-16 string into a byte buffer by truncating each unit. */
void ts4_narrow_wide_string_8882B368(const ts4_u16 *source, char *dest)
{
    while (*source) {
        *dest++ = (char)*source++;
    }
    *dest = 0;
}

/* Copies a UTF-16 string into a byte buffer by truncating each unit. */
void ts4_narrow_wide_string_8882ED98(const ts4_u16 *source, char *dest)
{
    while (*source) {
        *dest++ = (char)*source++;
    }
    *dest = 0;
}

/* Linear search of a pointer list for the item whose key matches. */
Ts4KeyedItem *ts4_find_item_by_key_88838770(Ts4KeyedList *list, int key)
{
    Ts4KeyedItem **it;
    Ts4KeyedItem **end = list->end;
    Ts4KeyedItem *found = 0;
    for (it = list->begin; it != end; ++it) {
        Ts4KeyedItem *item = *it;
        if (item->key == key) {
            found = item;
            break;
        }
    }
    return found;
}

/* Linear search of a pointer list for the item whose key matches. */
Ts4KeyedItem *ts4_find_item_by_key_88838980(Ts4KeyedList *list, int key)
{
    Ts4KeyedItem **it;
    Ts4KeyedItem **end = list->end;
    Ts4KeyedItem *found = 0;
    for (it = list->begin; it != end; ++it) {
        Ts4KeyedItem *item = *it;
        if (item->key == key) {
            found = item;
            break;
        }
    }
    return found;
}

/* Linear search of a pointer list for the item whose key matches. */
Ts4KeyedItem *ts4_find_item_by_key_88865090(Ts4KeyedList *list, int key)
{
    Ts4KeyedItem **it;
    Ts4KeyedItem **end = list->end;
    Ts4KeyedItem *found = 0;
    for (it = list->begin; it != end; ++it) {
        Ts4KeyedItem *item = *it;
        if (item->key == key) {
            found = item;
            break;
        }
    }
    return found;
}




