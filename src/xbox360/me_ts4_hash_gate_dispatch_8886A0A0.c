/* 0x8886A0A0: pick a target object by owner hash id (0x0F22AAA6/0xEB6BEE71 use a global hash lookup unless the event hash is whitelisted, otherwise resolve from the arg); reject non-positive counts for non-whitelisted events; dispatch when found. Matched /Oc (agBJ). */
typedef struct { char p[0x1c]; unsigned id; } O;
void *ts4_hash_lookup_null_888689A8(void);
void *fn_88869530(void *a);
void fn_888690F0(void *p, unsigned b, int c, int d, int e, int z, int f);
int fn_8886A0A0(O *o, void *a, unsigned b, int c, int d, int e, int f)
{
    void *p;
    unsigned id = o->id;
    if (id != 0x999EBBDC) {
        if (d <= 0 && b != 0x82252628 && b != 0xB8AAB84C)
            return 0;
        if (id == 0x0F22AAA6) {
            if (b != 0x58D09457 && b != 0x82252628 && b != 0xB8AAB84C) {
                p = ts4_hash_lookup_null_888689A8();
                goto have;
            }
        } else if (id == 0xEB6BEE71) {
            p = ts4_hash_lookup_null_888689A8();
            goto have;
        }
    }
    p = fn_88869530(a);
have:
    if (p)
        fn_888690F0(p, b, c, d, e, 0, f);
    return 1;
}
