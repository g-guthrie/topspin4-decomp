/* Swing_DLL.xex 0x888860A0-0x888860FF, executable version 0.0.0.3. */
typedef struct Ts4Registry {
    unsigned char reserved[0x24];
    void *fallback;
} Ts4Registry;

extern Ts4Registry *lbl_88D45B38;
extern void *fn_8860D360(Ts4Registry *registry, void *key);
extern void fn_8860DBC8(void *entry, void *key);

/* Looks the key up in the registry and hands the entry (or the registry fallback) to the follow-up routine. */
void ts4_registry_dispatch_888860A0(void *key)
{
    Ts4Registry *registry = lbl_88D45B38;
    void *entry;
    if (key == 0) {
        return;
    }
    entry = fn_8860D360(registry, key);
    if (entry != 0) {
        fn_8860DBC8(entry, key);
    } else {
        fn_8860DBC8(registry->fallback, key);
    }
}
