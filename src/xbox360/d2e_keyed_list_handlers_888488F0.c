/* Swing_DLL.xex 0x888488F0-0x8884BBF0, executable version 0.0.0.3. */
typedef struct Ts4KeyedItem { unsigned char reserved[0x180]; int key; } Ts4KeyedItem;
typedef struct Ts4KeyedList { unsigned char reserved[0x20]; Ts4KeyedItem **begin; Ts4KeyedItem **end; } Ts4KeyedList;
extern void ts4_if_get_fn_8883F238_88848698(Ts4KeyedItem *item, int flag);

/* Finds the list item with the given key (or null) and hands it to the follow-up routine. */
void ts4_find_item_by_key_then_handle_888488F0(Ts4KeyedList *list, int key)
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
    ts4_if_get_fn_8883F238_88848698(found, 0);
}

/* Finds the list item with the given key (or null) and hands it to the follow-up routine. */
void ts4_find_item_by_key_then_handle_8884BBB0(Ts4KeyedList *list, int key)
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
    ts4_if_get_fn_8883F238_88848698(found, 0);
}
