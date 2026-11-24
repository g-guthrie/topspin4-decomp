/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex): indexed entry lookups on a node that is entry 0 itself and
 * owns a vector of further 0x84-byte entries (begin/end at +0x84/+0x88). Callers reach the node
 * through +0x1C of their owner (0x888C2B30, 0x888C2B38). No shared type covers this class yet, so
 * the layout here holds only the fields these two functions touch.
 *
 * Codegen notes (LTCG route, /Oc):
 * - The no-op `clrrwi rX,r3,0` copy of the vector's begin pointer comes from reading begin twice
 *   through a nested inline accessor (size() and at() both call vbegin()), as in the CL1 rule.
 * - The out pointers are __restrict: the target loads every field before the first store.
 * - `idx--` before the range test keeps `(idx-1)*0x84` (not `idx*0x84 - 0x84`) and the target's
 *   register numbering.
 */
#include "include/ts4/ts4.h"

typedef unsigned int q5e_u32;

typedef struct Q5eElem18 { char data[0x18]; } Q5eElem18;
typedef struct Q5eVec18 { Q5eElem18 *begin; Q5eElem18 *end; } Q5eVec18;

/* One entry (0x84 bytes). */
typedef struct Q5eEntry {
    Q5eVec18 items;          /* +0x00 0x18-byte elements (count reported by 0x8886FED0) */
    char pad_08[0x50];
    q5e_u32 w58;             /* +0x58 reported by both */
    char pad_5c[0x8];
    q5e_u32 w64;             /* +0x64 reported by 0x8886FED0 */
    char pad_68[0x4];
    q5e_u32 w6c;             /* +0x6C reported by 0x8886FE50 */
    q5e_u32 w70;             /* +0x70 reported by 0x8886FE50 */
    char pad_74[0x10];
} Q5eEntry;

typedef struct Q5eEntryVec { Q5eEntry *begin; Q5eEntry *end; } Q5eEntryVec;

/* The node: entry 0 is the node itself; entries 1.. are children[idx - 1]. */
typedef struct Q5eEntryNode {
    Q5eEntry self;           /* +0x00 */
    Q5eEntryVec children;    /* +0x84 */
} Q5eEntryNode;

TS4_ASSERT_OFFSET(Q5eEntry, w58, 0x58);
TS4_ASSERT_OFFSET(Q5eEntry, w64, 0x64);
TS4_ASSERT_OFFSET(Q5eEntry, w6c, 0x6C);
TS4_ASSERT_SIZE(Q5eEntry, 0x84);
TS4_ASSERT_OFFSET(Q5eEntryNode, children, 0x84);
TS4_ASSERT_SIZE(Q5eEntryNode, 0x8C);

static Q5eEntry *q5e_vbegin(const Q5eEntryVec *v) { return v->begin; }
static Q5eEntry *q5e_vend(const Q5eEntryVec *v) { return v->end; }
static q5e_u32 q5e_vsize(const Q5eEntryVec *v) { return (q5e_u32)(q5e_vend(v) - q5e_vbegin(v)); }
static Q5eEntry *q5e_vat(const Q5eEntryVec *v, q5e_u32 i) { return q5e_vbegin(v) + i; }

static Q5eElem18 *q5e_v18begin(const Q5eVec18 *v) { return v->begin; }
static Q5eElem18 *q5e_v18end(const Q5eVec18 *v) { return v->end; }
static q5e_u32 q5e_v18size(const Q5eVec18 *v) { return (q5e_u32)(q5e_v18end(v) - q5e_v18begin(v)); }

static void q5e_entry_info(const Q5eEntry *e, q5e_u32 *a, q5e_u32 *b, q5e_u32 *c)
{
    *a = e->w58;
    *b = e->w70;
    *c = e->w6c;
}

static void q5e_entry_counts(const Q5eEntry *e, q5e_u32 *a, q5e_u32 *b, q5e_u32 *count)
{
    *count = q5e_v18size(&e->items);
    *a = e->w58;
    *b = e->w64;
}

/* Swing_DLL.xex 0x8886FE50: report (+0x58, +0x70, +0x6C) of entry `idx`; 0 when idx is out of range. */
int ts4_entry_node_info_8886FE50(Q5eEntryNode *node, q5e_u32 idx, q5e_u32 *__restrict a,
                                 q5e_u32 *__restrict b, q5e_u32 *__restrict c)
{
    if (idx == 0) {
        q5e_entry_info(&node->self, a, b, c);
        return 1;
    }
    idx--;
    if (idx < q5e_vsize(&node->children)) {
        q5e_entry_info(q5e_vat(&node->children, idx), a, b, c);
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x8886FED0: report the element count, +0x58 and +0x64 of entry `idx`; an out-of-range
 * index leaves the outputs untouched. Always returns 1. */
int ts4_entry_node_counts_8886FED0(Q5eEntryNode *node, q5e_u32 idx, q5e_u32 *__restrict a,
                                   q5e_u32 *__restrict b, q5e_u32 *__restrict count)
{
    if (idx == 0) {
        q5e_entry_counts(&node->self, a, b, count);
        return 1;
    }
    idx--;
    if (idx < q5e_vsize(&node->children)) {
        q5e_entry_counts(q5e_vat(&node->children, idx), a, b, count);
        return 1;
    }
    return 1;
}
