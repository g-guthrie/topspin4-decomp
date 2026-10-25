typedef struct Ts4OwnedList {
    void *allocator;
    void *owned;
} Ts4OwnedList;
extern void *lbl_88D45B38;
extern void fn_8825E668(Ts4OwnedList *list);
extern void fn_886131F0(void *context, void *owned, void *allocator);
extern void fn_885651F8(void *owned);

void fn_8825E6C8(Ts4OwnedList *list)
{
    fn_8825E668(list);
    if (list->owned != 0) {
        if (lbl_88D45B38 != 0) {
            fn_886131F0(lbl_88D45B38, list->owned, list->allocator);
            return;
        }
        fn_885651F8(list->owned);
    }
}