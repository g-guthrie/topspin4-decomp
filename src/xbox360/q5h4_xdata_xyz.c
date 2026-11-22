/* Q5h4: load three u32 fields (x, y, z axis hashes) from an xdata record (Top Spin 4, Xbox 360).
 * Clone of the 0x888B0570 template (q5_gameplay_xdata_xyz.c). Follows the by-value handle through hashes
 * 0x725D27D9 and 0xB894A04C to a node; if that node is valid, reads the x/y/z children (hashes 0xB7B2364B,
 * 0xC0B506DD, 0x59BC5767) with a 4-byte get through the node's vtable slot +0x28, skipping any child that is null.
 * Always records the handle's offset word in self.
 * Sister 0x888B0788 is the same code with the fields at +0x80..+0x8c (the template has them at +0x90..+0x9c). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Q5h4XNode Q5h4XNode;
typedef struct Q5h4XRef { Q5h4XNode *node; u32 offset; u32 extra; } Q5h4XRef;
typedef struct Q5h4XNodeVt { void *s[10]; u32 (*get)(Q5h4XNode *n, Q5h4XRef *r, u32 offset, u32 size); } Q5h4XNodeVt;
struct Q5h4XNode { Q5h4XNodeVt *vt; };
typedef struct Q5h4Self { char p0[0x80]; u32 x, y, z, offset; } Q5h4Self;
extern Q5h4XRef *ts4_handle_forward_88610A48(Q5h4XRef *out, Q5h4XRef *handle, u32 *hash);
extern Q5h4XRef *ts4_handle_forward_88150770(Q5h4XRef *out, Q5h4XRef *handle, u32 *hash);
static u8 q5h4_null(Q5h4XRef *r) { return r->node == 0 || r->offset == 0xFFFFFu; }
static u32 q5h4_get(Q5h4XRef *r) { return r->node->vt->get(r->node, r, r->offset, 4); }

/* 0x888B0788 */
void ts4_xdata_load_xyz_888B0788(Q5h4Self *self, Q5h4XRef h)
{
    Q5h4XRef a, node, r;
    u32 h0, h1, hx, hy, hz;
    h0 = 0x725D27D9u;
    ts4_handle_forward_88610A48(&a, &h, &h0);
    h1 = 0xB894A04Cu;
    ts4_handle_forward_88610A48(&node, &a, &h1);
    if (!q5h4_null(&node)) {
        hx = 0xB7B2364Bu;
        ts4_handle_forward_88150770(&r, &node, &hx);
        if (!q5h4_null(&r)) self->x = q5h4_get(&r);
        hy = 0xC0B506DDu;
        { Q5h4XRef t; r = *ts4_handle_forward_88150770(&t, &node, &hy); }
        if (!q5h4_null(&r)) self->y = q5h4_get(&r);
        hz = 0x59BC5767u;
        { Q5h4XRef t; r = *ts4_handle_forward_88150770(&t, &node, &hz); }
        if (!q5h4_null(&r)) self->z = q5h4_get(&r);
    }
    self->offset = h.offset;
}
