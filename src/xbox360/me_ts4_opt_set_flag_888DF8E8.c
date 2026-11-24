/* 0x888DF8E8: set a boolean option. Resolves the setting named by lbl_880D8670 into a reference,
   asks its store (vtable slot 0x28) for the 4-byte value slot, writes -1/0 for on/off there and
   caches the flag at +0x1c. */
typedef unsigned int u32;
typedef unsigned char u8;
struct OptStore;
typedef struct OptRef { struct OptStore *store; u32 id; u32 extra; } OptRef;
typedef struct OptStoreVt { void *s[10]; int *(*slot)(struct OptStore *, OptRef *, u32, u32); } OptStoreVt;
typedef struct OptStore { OptStoreVt *vt; } OptStore;
typedef struct OptOwner { u32 pad[7]; u8 b1c; } OptOwner;
extern void ts4_if_set_u32_off0_8862BE08(OptRef *out, const char *name);
extern const char lbl_880D8670[];
void ts4_opt_set_flag_888DF8E8(OptOwner *o, u8 on)
{
    OptRef r;
    int *p;
    ts4_if_set_u32_off0_8862BE08(&r, lbl_880D8670);
    p = r.store->vt->slot(r.store, &r, r.id, 4);
    *p = on ? -1 : 0;
    o->b1c = on;
}
