/* 0x884C51D0: Inserts node into the global index under its name (vt slot 7), adds item to the global registry (slot 3), and notifies the listener with item->handle and node (slot 3). */
/* Matched on /Oc (agAH). Three vcalls through globals. */
typedef struct Node Node;
typedef struct Item { char p0[0xc]; void *handle; } Item;
typedef struct Index Index;
typedef struct IndexVt { void *s[7]; void (*insert)(Index *, Node *, const char *); } IndexVt;
struct Index { IndexVt *vt; };
typedef struct Listener Listener;
typedef struct ListenerVt { void *s[3]; void (*notify)(Listener *, void *, void *); } ListenerVt;
struct Listener { ListenerVt *vt; };
extern Index *lbl_88D3CB4C;
typedef struct Registry Registry;
typedef struct RegistryVt { void *s[3]; void (*add)(Registry *, Item *); } RegistryVt;
struct Registry { RegistryVt *vt; };
extern Registry *lbl_88D3CB50;
extern Listener *lbl_88CAD568;
extern const char *ts4_get_u32_off0_8841EAC8(Node *n);
void fn_884C51D0(void *self, Item *item, Node *node)
{
    Index *idx = lbl_88D3CB4C;
    idx->vt->insert(idx, node, ts4_get_u32_off0_8841EAC8(node));
    lbl_88D3CB50->vt->add(lbl_88D3CB50, item);
    lbl_88CAD568->vt->notify(lbl_88CAD568, item->handle, node);
}
