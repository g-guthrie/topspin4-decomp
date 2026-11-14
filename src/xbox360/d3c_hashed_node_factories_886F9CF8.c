/* Swing_DLL.xex 0x886F9CF8-0x886FDAC4, executable version 0.0.0.3. */
typedef unsigned int u32;

#ifdef _MSC_VER
#define TS4_FORCEINLINE static __forceinline
#else
#define TS4_FORCEINLINE static inline
#endif

typedef struct Ts4Handle12 {
    u32 a, b, c;
} Ts4Handle12;

typedef struct Ts4HashedNode {
    void *vtbl;
    u32 a, b, c;
} Ts4HashedNode;

typedef struct Ts4HashedNodeBase {
    void *vtbl;
    volatile u32 a, b;
} Ts4HashedNodeBase;

extern void *lbl_88D45B38;
extern void *lbl_88D45AD4;
extern void *fn_88613268(void *heap, u32 size, u32 align, u32 tag, u32 pool);
extern u32 fn_88923530(u32 pool, Ts4Handle12 h, u32 hash);
extern void *lbl_880F2C8C[];
extern void *lbl_880F2BF0[];
extern void *lbl_880F2958[];
extern void *lbl_880F2A74[];
extern void *lbl_880F2B70[];
extern void *lbl_880F2AF0[];
extern void *lbl_880F29F8[];
extern void *lbl_880F26D0[];
extern void *lbl_880F2668[];
extern void *lbl_880F2410[];
extern void *lbl_880F22D4[];
extern void *lbl_880F24A4[];
extern void *lbl_880F2738[];
extern void *lbl_880F2530[];
extern void *lbl_880F259C[];
extern void *lbl_880F2600[];
TS4_FORCEINLINE Ts4HashedNodeBase *ts4_hashed_node_base_init(Ts4HashedNodeBase *p)
{
    p->a = 0;
    p->b = 0;
    return p;
}

/* Allocate a node on the global heap, install its vtable, then look up the typed view for the given handle. */
#define TS4_HASHED_NODE_FACTORY(NAME, VTBL, HASH) \
    void *NAME(void *unused, Ts4Handle12 h) \
    { \
        u32 tag = 0; \
        Ts4HashedNode *o; \
        Ts4HashedNode *r; \
        (void)unused; \
        if (lbl_88D45AD4) tag = *(u32 *)((char *)lbl_88D45AD4 + 0x15680); \
        o = (Ts4HashedNode *)fn_88613268(lbl_88D45B38, 0x10, 4, tag, 2); \
        if (o) { \
            ts4_hashed_node_base_init((Ts4HashedNodeBase *)o); \
            r = o; \
            r->a = 0; \
            r->b = 0; \
            r->vtbl = VTBL; \
            r->c = 0; \
        } else { \
            r = 0; \
        } \
        r->c = fn_88923530(h.c, h, HASH); \
        return r; \
    }

TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886F9CF8, lbl_880F2C8C, 0x9E0BC3E1) /* 0x886F9CF8 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886F9FC8, lbl_880F2BF0, 0xDA4EBC10) /* 0x886F9FC8 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FA858, lbl_880F2958, 0x19403F3E) /* 0x886FA858 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FA9A8, lbl_880F2A74, 0x66B84A34) /* 0x886FA9A8 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FAF90, lbl_880F2B70, 0xB13C7DAD) /* 0x886FAF90 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FB040, lbl_880F2AF0, 0xA447E647) /* 0x886FB040 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FB468, lbl_880F29F8, 0xE6B7157E) /* 0x886FB468 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FBCE0, lbl_880F26D0, 0x461DB829) /* 0x886FBCE0 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FBDE0, lbl_880F2668, 0xFB6B11AF) /* 0x886FBDE0 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FC110, lbl_880F2410, 0xA488FC98) /* 0x886FC110 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FC2A8, lbl_880F22D4, 0x139F8DA5) /* 0x886FC2A8 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FC780, lbl_880F24A4, 0xD658D9BA) /* 0x886FC780 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FD018, lbl_880F2738, 0xC1CABF2D) /* 0x886FD018 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FD3F0, lbl_880F2530, 0x695FF6A7) /* 0x886FD3F0 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FD4A0, lbl_880F259C, 0x16B95B83) /* 0x886FD4A0 */
TS4_HASHED_NODE_FACTORY(ts4_create_hashed_node_886FDA18, lbl_880F2600, 0xD3994F67) /* 0x886FDA18 */
