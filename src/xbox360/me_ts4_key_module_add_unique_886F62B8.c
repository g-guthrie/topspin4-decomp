/* Swing_DLL.xex 0x886F62B8: register a key with the active module, once. */
typedef unsigned int u32;
typedef struct Ts4KeyVec { u32 *first; u32 *last; u32 *reserved; u32 *end; } Ts4KeyVec;
typedef struct Ts4KeyModule { char pad[0x54]; Ts4KeyVec keys; } Ts4KeyModule;
extern Ts4KeyModule *lbl_88D45A70;
extern u32 *ts4_find_u32_54_886EBFC0(char *self, u32 key);
extern void ts4_vector_grow_append_scalar4_8816DD48(Ts4KeyVec *v, u32 *where, const u32 *val);
void ts4_key_module_add_unique_886F62B8(u32 key)
{
    Ts4KeyModule *m = lbl_88D45A70;
    if (m && m->keys.last == ts4_find_u32_54_886EBFC0((char *)m, key)) {
        Ts4KeyVec *v = &m->keys;
        u32 k = key;
        if (v->last != v->end) {
            if (v->last) *v->last = k;
            v->last++;
        } else {
            ts4_vector_grow_append_scalar4_8816DD48(v, v->last, &k);
        }
    }
}
