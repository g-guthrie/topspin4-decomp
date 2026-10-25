typedef struct Ts4OwnedList {
    void *owned;
    void *unknown;
    void *allocator;
} Ts4OwnedList;

extern void fn_88260968(void *arg, void *unknown);
extern void *lbl_88D45B38;
extern void fn_886131F0(void *context, void *owned, void *allocator);
extern void fn_885651F8(void *owned);

void fn_88229A78(Ts4OwnedList *list)
{
    fn_88260968(list->owned, list->unknown);
    if (list->owned != 0) {
        if (lbl_88D45B38 != 0) {
            fn_886131F0(lbl_88D45B38, list->owned, list->allocator);
            return;
        }
        fn_885651F8(list->owned);
    }
}