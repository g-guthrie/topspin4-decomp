/* Swing_DLL.xex 0x88270E28-0x88271230, executable version 0.0.0.3. */
typedef unsigned int u32;
extern void ts4_registry_dispatch_888860A0(void *p);
extern void ts4_tsu_cleanup_end(void *p);
extern void ts4_object_dtor_8869CD68(void *p);
extern void fn_886A7988(void *p);
extern void fn_886ACB08(void *p);
extern void fn_886B4C10(void *p);

/* Vector/scalar deleting destructor for a 976-byte element type: flag 2 destroys the counted array. */
void *ts4_vector_deleting_destructor_88270E28(char *self, u32 flags)
{
    if (flags & 2) {
        char *base = self - 16;
        int n = *(int *)(self - 16);
        char *e = self + n * 976;
        int i;
        for (i = n - 1; i >= 0; --i) {
            e -= 976;
            fn_886B4C10(e);
        }
        if (flags & 1) {
            ts4_registry_dispatch_888860A0(base);
        }
        return base;
    }
    fn_886B4C10(self);
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

/* Vector/scalar deleting destructor for a 432-byte element type: flag 2 destroys the counted array. */
void *ts4_vector_deleting_destructor_88270EC0(char *self, u32 flags)
{
    if (flags & 2) {
        char *base = self - 16;
        int n = *(int *)(self - 16);
        char *e = self + n * 432;
        int i;
        for (i = n - 1; i >= 0; --i) {
            e -= 432;
            ts4_object_dtor_8869CD68(e);
        }
        if (flags & 1) {
            ts4_registry_dispatch_888860A0(base);
        }
        return base;
    }
    ts4_object_dtor_8869CD68(self);
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

/* Vector/scalar deleting destructor for a 684-byte element type: flag 2 destroys the counted array. */
void *ts4_vector_deleting_destructor_88271008(char *self, u32 flags)
{
    if (flags & 2) {
        char *base = self - 4;
        int n = *(int *)(self - 4);
        char *e = self + n * 684;
        int i;
        for (i = n - 1; i >= 0; --i) {
            e -= 684;
            fn_886A7988(e);
        }
        if (flags & 1) {
            ts4_registry_dispatch_888860A0(base);
        }
        return base;
    }
    fn_886A7988(self);
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}

/* Vector/scalar deleting destructor for a 172-byte element type: flag 2 destroys the counted array. */
void *ts4_vector_deleting_destructor_88271230(char *self, u32 flags)
{
    if (flags & 2) {
        char *base = self - 4;
        int n = *(int *)(self - 4);
        char *e = self + n * 172;
        int i;
        for (i = n - 1; i >= 0; --i) {
            e -= 172;
            fn_886ACB08(e);
        }
        if (flags & 1) {
            ts4_registry_dispatch_888860A0(base);
        }
        return base;
    }
    fn_886ACB08(self);
    if (flags & 1) {
        ts4_tsu_cleanup_end(self);
    }
    return self;
}
