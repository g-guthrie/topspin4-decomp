/* 0x886D8EF8: constructor: base-constructs from the handle, then inside a heap scope (vtable lbl_880F7AEC: enter at
 * slot 1, leave at slot 2) reads the string view 0xCEB2A4D9 of the handle, hashes it and looks the service up. */
typedef unsigned int u32;
typedef struct TS4TripleArg { u32 first, second, third; } TS4TripleArg;
typedef struct Ts4XdataRef Ts4XdataRef;
typedef struct Ts4XdataVt { void *s[20]; void *(*get_string)(void *node, Ts4XdataRef *r, u32 off, int n); } Ts4XdataVt;
typedef struct Ts4XdataNode { Ts4XdataVt *vt; } Ts4XdataNode;
struct Ts4XdataRef { Ts4XdataNode *node; u32 offset; u32 extra; };
typedef struct Ts4HeapScope Ts4HeapScope;
typedef struct Ts4HeapScopeVt { void *s0; void (*enter)(Ts4HeapScope *); void (*leave)(Ts4HeapScope *); } Ts4HeapScopeVt;
struct Ts4HeapScope { const Ts4HeapScopeVt *vt; void *heap; void *owner; };
typedef struct Ts4SvcUser { char p[0xc]; void *heap_owner; char p2[0x1c - 0x10]; void *service; } Ts4SvcUser;
extern const Ts4HeapScopeVt lbl_880F7AEC;
extern void *lbl_88D45B38;
void fn_88627EC0(void *self, TS4TripleArg value);
void *ts4_if_call_seq_fn_88883CD0_8860D250(void *heap);
extern Ts4XdataRef *ts4_handle_forward_88150770(Ts4XdataRef *out, TS4TripleArg *handle, u32 *type_hash);
u32 ts4_crc32_cstr_seed_88608590(int a, const char *s);
void *ts4_find_service(u32 hash);
static __inline void scope_init(Ts4HeapScope *s, void *owner) { s->vt = &lbl_880F7AEC; s->heap = ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38); s->owner = owner; }
void ts4_service_ref_init(Ts4SvcUser *self, TS4TripleArg value)
{
    Ts4HeapScope scope;
    u32 hash;
    Ts4XdataRef tmp, *r;
    fn_88627EC0(self, value);
    scope_init(&scope, self->heap_owner);
    scope.vt->enter(&scope);
    hash = 0xCEB2A4D9u;
    r = ts4_handle_forward_88150770(&tmp, &value, &hash);
    self->service = ts4_find_service(ts4_crc32_cstr_seed_88608590(0, (const char *)r->node->vt->get_string(r->node, r, r->offset, 1)));
    scope.vt->leave(&scope);
}
