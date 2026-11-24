/* Script handler: is the id in arg 0 present in the linked list at lbl_88D41FC4->0x6c? */
typedef unsigned int u32;
typedef unsigned char u8;
#define INL static __forceinline
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
/* First argument; the caller tests count != 0 (beq), not count > 0. */
INL Val *arg_first(Args *a)
{
    if (a->count) {
        return a->items;
    }
    return g_ts4_default_script_value;
}
INL double arg_number(Val *v)
{
    if (v->type == 4) {
        return v->value.number;
    } else if (v->type == 1) {
        return v->value.integer;
    }
    return g_ts4_script_constants[11];
}

typedef struct Node { struct Node *next; u8 r[0x28]; u32 id; } Node;
typedef struct L { u8 r[0x34]; Node *head; u8 r2[4]; u32 count; } L;
typedef struct M { u8 r[0x6c]; L *list; } M;
extern M *lbl_88D41FC4;
u8 ts4_script_list_has_id_8877C4A8(Ctx *c)
{
    u32 id = (u32)arg_number(arg_first(c->args));
    L *l = lbl_88D41FC4->list;
    Node *n;
    u8 r = 0;
    if (l->count) {
        for (n = l->head; n; n = n->next) {
            if (id == n->id) {
                r = 1;
                break;
            }
        }
    }
    return r;
}
