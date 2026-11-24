/* 0x883D33B0: 0x1F not ready, 0x25 null out or key already owned; resolves the key's node (883CB130), allocates and constructs a 0x2C-byte object (883EDDD0, taken to return this) and binds it to the key (883ED420, freed on error); 0x2C on allocation failure */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_880391A8[];
typedef struct Own { void *first; } Own;
typedef struct Node { char pad[0xac]; Own *own; } Node;
typedef struct Obj Obj;
typedef struct Sys { char pad[0x809c]; void *ready; } Sys;
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
void fn_88315F10(void *heap, void *buf, const char *file, int line);
int fn_883CB130(void *key, Node **out);
Obj *ts4_addr_lbl_88039B00_883EDDD0(void *p);
int ts4_if_set_u32_off18_883ED420(Obj *o, void *key);

int fn_883D33B0(Sys *s, void *key, Obj **out)
{
    Node *node;
    void *p;
    Obj *o;
    int r;
    if (!s->ready)
        return 0x1f;
    if (!out)
        return 0x25;
    *out = 0;
    r = fn_883CB130(key, &node);
    if (r)
        return r;
    if (node->own ? node->own->first : 0)
        return 0x25;
    p = fn_88315C60(lbl_88B3302C->heap, 0x2c, lbl_880391A8, 0x1126, 0, 0);
    o = p ? ts4_addr_lbl_88039B00_883EDDD0(p) : 0;
    if (!o)
        return 0x2c;
    r = ts4_if_set_u32_off18_883ED420(o, key);
    if (r) {
        fn_88315F10(lbl_88B3302C->heap, o, lbl_880391A8, 0x112f);
        return r;
    }
    *out = o;
    return 0;
}
