extern void ts4_object_finalize(void *object);
extern void *lbl_88D45B38;
extern void fn_886131F0(void *context, void *owned, void *allocator);
extern void fn_885651F8(void *owned);

void fn_8871C748(void *obj)
{
    ts4_object_finalize(obj);
    if (*(void **)obj != 0) {
        if (lbl_88D45B38 != 0) {
            fn_886131F0(lbl_88D45B38, *(void **)obj, *(void **)((char *)obj + 8));
            return;
        }
        fn_885651F8(*(void **)obj);
    }
}