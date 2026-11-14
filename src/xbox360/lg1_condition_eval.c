/* Family LG1: data-driven condition tree evaluator (region 0x886C9228; callers fn_886CEAC8 and fn_886CEB68).
 * Nodes are 8-byte records {self-relative offset to the node data, kind hash}; child lists are
 * self-relative arrays {offset (-1 = empty), count} of nodes. Kind names are not known; the hashes
 * are kept as constants. */

/* Self-relative array header: elements start at (char *)hdr + off. */
typedef struct lg1_rel_array {
    int off;   /* +0x0, -1 when empty */
    int count; /* +0x4 */
} lg1_rel_array;

/* Tree node (8 bytes). */
typedef struct lg1_cond_node {
    int data_off;      /* +0x0, self-relative offset to the kind-specific data */
    unsigned int kind; /* +0x4, kind hash */
} lg1_cond_node;

/* Per-slot state block reached from the evaluation context. */
typedef struct lg1_cond_state {
    char pad0[0xC];
    int row_words;  /* +0x0C, words per row of the value table */
    char pad10[0x40];
    int elems_off;  /* +0x50, self-relative offset to 0x8C-byte elements */
    char pad54[0x30];
    int values_off; /* +0x84, self-relative offset to the value table */
} lg1_cond_state;

typedef struct lg1_cond_owner2 {
    char pad0[0xC];
    lg1_cond_state *state; /* +0xC */
} lg1_cond_owner2;

typedef struct lg1_cond_owner {
    char pad0[0x18];
    lg1_cond_owner2 *inner; /* +0x18 */
} lg1_cond_owner;

/* 12-byte value reference. */
typedef struct lg1_value_ref12 {
    unsigned int *expected; /* +0x0 */
    int pad4;
    int column;             /* +0x8 */
} lg1_value_ref12;

/* 16-byte value reference. */
typedef struct lg1_value_ref16 {
    int pad0;
    int pad4;
    int column;        /* +0x8 */
    unsigned int mask; /* +0xC */
} lg1_value_ref16;

typedef struct lg1_cond_ctx {
    int pad0;
    lg1_cond_owner *owner;       /* +0x04 */
    lg1_value_ref16 *refs16;     /* +0x08 */
    int padc;
    int pad10;
    lg1_value_ref12 *refs12;     /* +0x14 */
    int pad18;
    int pad1c;
    unsigned char **flags;       /* +0x20 */
} lg1_cond_ctx;

/* Leaf data of the reference kinds. */
typedef struct lg1_cond_ref_data {
    int pad0[4];
    int ref;              /* +0x10 */
    unsigned char exact;  /* +0x14 */
} lg1_cond_ref_data;

typedef struct lg1_cond_mask_data {
    int pad0[2];
    int column;           /* +0x08 */
    unsigned int mask;    /* +0x0C */
    unsigned char exact;  /* +0x10 */
} lg1_cond_mask_data;

typedef struct lg1_cond_elem_data {
    unsigned int expected; /* +0x00 */
    int pad4[3];
    int flag;              /* +0x10 */
} lg1_cond_elem_data;

#define LG1_DATA(node) ((char *)(node) + (node)->data_off)

#ifdef _MSC_VER
#define LG1_INLINE __forceinline
#else
#define LG1_INLINE inline
#endif

/* Resolve a self-relative offset field. */
static LG1_INLINE char *lg1_rel(int *field)
{
    return (char *)field + *field;
}

static LG1_INLINE lg1_cond_node *lg1_end(lg1_rel_array *a)
{
    lg1_cond_node *e = 0;
    if (a->off != -1)
        e = (lg1_cond_node *)((char *)a + a->count * 8 + a->off);
    return e;
}

static LG1_INLINE lg1_cond_node *lg1_begin(lg1_rel_array *a)
{
    lg1_cond_node *b = 0;
    if (a->off != -1)
        b = (lg1_cond_node *)((char *)a + a->off);
    return b;
}

/* Evaluate condition node for slot index; returns 1 when true. Swing_DLL.xex 0x886C9F08 */
unsigned char ts4_data_condition_eval_886C9F08(lg1_cond_ctx *ctx, lg1_cond_node *node, int index)
{
    lg1_cond_owner2 *inner = ctx->owner->inner;
    unsigned int *row = (unsigned int *)lg1_rel(&inner->state->values_off) + inner->state->row_words * index;
    unsigned char result = 0;
    lg1_cond_node *end, *it;
    switch (node->kind) {
    case 0x332E57C4u: {
        lg1_cond_ref_data *d = (lg1_cond_ref_data *)LG1_DATA(node);
        lg1_value_ref12 *r = &ctx->refs12[d->ref];
        unsigned int expected = *r->expected;
        unsigned int value = row[r->column];
        if (d->exact)
            result = expected == value;
        else if (expected != 0)
            result = value == 0 || (value & expected) == expected;
        else
            result = value == 0;
        break;
    }
    case 0x1AE94A04u: {
        lg1_cond_ref_data *d = (lg1_cond_ref_data *)LG1_DATA(node);
        lg1_value_ref16 *r = &ctx->refs16[d->ref];
        unsigned int mask = r->mask;
        unsigned int value = row[r->column];
        if (d->exact)
            result = mask == value;
        else
            result = (value & mask) == mask;
        break;
    }
    case 0x00BF4FFCu: {
        lg1_cond_mask_data *d = (lg1_cond_mask_data *)LG1_DATA(node);
        unsigned int mask = d->mask;
        unsigned int value = row[d->column];
        if (d->exact)
            result = value == mask;
        else
            result = (value & mask) == mask;
        break;
    }
    case 0x9E4D5A77u: {
        lg1_cond_state *s = inner->state;
        lg1_cond_elem_data *d = (lg1_cond_elem_data *)LG1_DATA(node);
        char *elem = lg1_rel(&s->elems_off) + index * 0x8C;
        result = d->expected != *(unsigned int *)lg1_rel((int *)(elem + 0x64)) || *ctx->flags[d->flag] != 0;
        break;
    }
    case 0xD837CA33u: {
        lg1_rel_array *a = (lg1_rel_array *)LG1_DATA(node);
        result = 0;
        end = lg1_end(a);
        it = lg1_begin(a);
        for (; it != end; it++) {
            if (result)
                break;
            result = ts4_data_condition_eval_886C9F08(ctx, it, index);
        }
        break;
    }
    case 0xCB3C6C47u: {
        lg1_rel_array *a = (lg1_rel_array *)LG1_DATA(node);
        result = 1;
        end = lg1_end(a);
        it = lg1_begin(a);
        for (; it != end; it++) {
            if (!result)
                break;
            result = ts4_data_condition_eval_886C9F08(ctx, it, index);
        }
        break;
    }
    case 0xC4CC0A5Fu: {
        lg1_cond_node *child = (lg1_cond_node *)LG1_DATA(node);
        child = (lg1_cond_node *)LG1_DATA(child);
        result = !ts4_data_condition_eval_886C9F08(ctx, child, index);
        break;
    }
    }
    return result;
}
