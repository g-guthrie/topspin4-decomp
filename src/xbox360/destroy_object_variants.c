typedef unsigned int u32;

typedef struct Ts4Object {
    void *vtable;
} Ts4Object;

extern char lbl_880D6B74;
extern char lbl_880D6BC0;
extern void fn_88617D28(Ts4Object *object);
extern void ts4_tsu_cleanup_end(Ts4Object *object);

#define TS4_DESTROY_VARIANT(name, vtable_symbol) \
    Ts4Object *name(Ts4Object *object, u32 delete_object) \
    { \
        object->vtable = &vtable_symbol; \
        fn_88617D28(object); \
        if ((delete_object & 1U) != 0) { \
            ts4_tsu_cleanup_end(object); \
        } \
        return object; \
    }

TS4_DESTROY_VARIANT(ts4_destroy_variant_6b74, lbl_880D6B74)
TS4_DESTROY_VARIANT(ts4_destroy_variant_6bc0, lbl_880D6BC0)
