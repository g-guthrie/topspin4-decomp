/* 0x883D4D08: resolves an info reference to a list link: by index for version >= 0x270000, otherwise by name (88329868 as strcmp, freeing the name); 0x25 when not found; then updates the node's bit-17 flag from 883D45F8 || 883C7068 */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_880391A8[];
typedef struct Link { struct Link *next; struct Link *prev; char pad[0x10 - 8]; const char *name; } Link;
typedef union Ref { int index; char *name; Link *link; } Ref;
typedef struct Info { char pad[0xc]; Ref ref; } Info;
typedef struct Node Node;
typedef struct Obj { char pad[0x14]; Info *info; char pad2[0x20 - 0x18]; Node *node; } Obj;
typedef struct Sys { char pad[0x8054]; Link head; } Sys;
void fn_88315F10(void *heap, void *buf, const char *file, int line);
int ts4_stricmp_ascii_88329868(const char *a, const char *b);
unsigned char ts4_if_call_seq_ts4_get_bits_24_1b_1_883E1880_883D45F8(Obj *o);
unsigned char ts4_get_bits_60_f_1_883C7068(Node *n);
void ts4_set_flag_bit17_off60_883C7078(Node *n, int on);

int fn_883D4D08(Sys *s, Link *start, int version, Obj *o)
{
    unsigned char found = 0;
    Link *n;
    if (version >= 0x270000) {
        int i;
        for (n = start, i = 0; n != &s->head && i < o->info->ref.index; i++)
            n = n->next;
        if (n == &s->head)
            return 0x25;
        o->info->ref.link = n;
    } else {
        for (n = start; n != &s->head; n = n->next) {
            if (!ts4_stricmp_ascii_88329868(o->info->ref.name, n->name)) {
                fn_88315F10(lbl_88B3302C->heap, o->info->ref.name, lbl_880391A8, 0x14c6);
                o->info->ref.link = n;
                found = 1;
                break;
            }
        }
        if (!found)
            return 0x25;
    }
    ts4_set_flag_bit17_off60_883C7078(o->node,
        ts4_if_call_seq_ts4_get_bits_24_1b_1_883E1880_883D45F8(o) || ts4_get_bits_60_f_1_883C7068(o->node));
    return 0;
}
