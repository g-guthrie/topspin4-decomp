#include "w4b_types.h"

struct W4bObjVtbl { void (*slot[16])(void *); };
struct W4bObj { struct W4bObjVtbl *vtbl; };
struct W4bEntry { w4b_u32 w0; int refs; w4b_u32 id; struct W4bObj *obj; };
struct W4bHook { struct W4bObjVtbl *vtbl; };
struct W4bRegistry {
    W4B_PAD(0x50);
    struct W4bObj *hook;          /* +0x50 */
    W4B_PAD(0x94 - 0x54);
    struct W4bEntry *begin;       /* +0x94 */
    struct W4bEntry *end;         /* +0x98 */
};
struct W4bKey { w4b_u32 id; };

W4B_INLINE int *w4b_entry_refs(struct W4bEntry *e) { return &e->refs; }

/* Swing_DLL.xex 0x8866DD78 */
void ts4_registry_release_8866DD78(struct W4bRegistry *self, struct W4bKey *key)
{
    struct W4bEntry *end;
    struct W4bEntry *e;
    w4b_u32 want;
    if (key->id != 0xC4CEEEC0u)
        self->hook->vtbl->slot[10](self->hook);
    end = self->end;
    e = self->begin;
    want = key->id;
    for (; e != end; e++) {
        if (e->id == want) {
            if (e->obj == 0)
                return;
            --*w4b_entry_refs(e);
            if (*w4b_entry_refs(e) == 0)
                e->obj->vtbl->slot[13](e->obj);
            return;
        }
    }
}
