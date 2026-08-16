typedef unsigned int u32;

extern void *lbl_88D45B38;
extern u32 fn_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
extern void *fn_889285A0(void);
extern void *fn_889296C0(void);
extern void *fn_8892A0E0(void);
extern void *fn_8892AFF0(void);
extern void *fn_889270C0(void);

#define TS4_FACTORY(name, size, pool, constructor) \
    void *name(void) { \
        if (fn_88613268(lbl_88D45B38, size, 4, 0, pool) != 0) { \
            return constructor(); \
        } \
        return 0; \
    }

/* Swing_DLL.xex factory wrappers. */
TS4_FACTORY(ts4_create_runtime_object_28_pool2, 0x28, 2, fn_889285A0)
TS4_FACTORY(ts4_create_runtime_object_28_pool0, 0x28, 0, fn_889285A0)
TS4_FACTORY(ts4_create_runtime_object_54_pool2, 0x54, 2, fn_889296C0)
TS4_FACTORY(ts4_create_runtime_object_54_pool0, 0x54, 0, fn_889296C0)
TS4_FACTORY(ts4_create_runtime_object_80_pool2, 0x80, 2, fn_8892A0E0)
TS4_FACTORY(ts4_create_runtime_object_80_pool0, 0x80, 0, fn_8892A0E0)
TS4_FACTORY(ts4_create_runtime_object_54_alt_pool0, 0x54, 0, fn_8892AFF0)
TS4_FACTORY(ts4_create_runtime_object_20_pool0, 0x20, 0, fn_889270C0)
