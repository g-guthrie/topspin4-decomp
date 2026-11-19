/* Swing_DLL.xex 0x886FA908: register a key with both the active module and the secondary registry, once each. */
typedef unsigned int u32;
typedef struct Ts4KeyVec { u32 *first; u32 *last; u32 *reserved; u32 *end; } Ts4KeyVec;
typedef struct Ts4KeyRegistry { char pad[0x1c]; Ts4KeyVec keys; } Ts4KeyRegistry;
extern Ts4KeyRegistry *lbl_88D45A6C;
extern void ts4_key_module_add_unique_886F62B8(u32 key);
extern u32 *ts4_find_u32_1c_886EBDF0(char *self, u32 key);
extern void ts4_vector_grow_append_scalar4_8816DD48(Ts4KeyVec *v, u32 *where, const u32 *val);
void ts4_key_register_886FA908(u32 key)
{
    Ts4KeyRegistry *r;
    ts4_key_module_add_unique_886F62B8(key);
    r = lbl_88D45A6C;
    if (r && r->keys.last == ts4_find_u32_1c_886EBDF0((char *)r, key)) {
        Ts4KeyVec *v = &r->keys;
        u32 k = key;
        if (v->last != v->end) {
            if (v->last) *v->last = k;
            v->last++;
        } else {
            ts4_vector_grow_append_scalar4_8816DD48(v, v->last, &k);
        }
    }
}
