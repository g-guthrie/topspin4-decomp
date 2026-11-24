/* Swing_DLL.xex 0x88376F08-0x88376FC0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4VwQuery { char pad[0x10c]; u32 value; char tail[0x20]; } Ts4VwQuery;
typedef struct Ts4VwProv Ts4VwProv;
struct Ts4VwProv {
    char pad0[0x64];
    int (*get_generic)(void *self, u32 *out);
    char pad1[0x74 - 0x68];
    int (*query)(void *self, u32 arg, Ts4VwQuery *q);
    char pad2[0xd0 - 0x78];
    u32 arg;
};
int ts4_provider_get_88376F08(Ts4VwProv *p, u32 *out, u32 kind)
{
    Ts4VwQuery q;
    int r;
    if (kind == 8) {
        r = p->query(p != 0 ? (char *)p + 0x1c : 0, p->arg, &q);
        if (r != 0)
            return r;
        *out = q.value;
        return 0;
    }
    if (p->get_generic == 0) {
        *out = 0;
        return 0x52;
    }
    return p->get_generic((char *)p + 0x1c, out);
}
