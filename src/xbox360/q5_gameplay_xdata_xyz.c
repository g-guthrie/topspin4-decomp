/* Q5: load three u32 fields (x, y, z axis hashes) from an xdata record (0x888B0570).
 * Follows the by-value handle through hashes 0x725D27D9 and 0xB894A04C to a
 * node; if that node is valid, reads the x/y/z children (hashes 0xB7B2364B,
 * 0xC0B506DD, 0x59BC5767, the same axis keys as the camera "At" reader) with
 * a 4-byte get through the node's vtable slot +0x28 into self+0x90..+0x98,
 * skipping any child that is null. Always records the handle's offset word
 * in self+0x9c.
 * Sister 0x888B0788 is the same code with the fields at +0x80..+0x8c. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Q5XNode Q5XNode;
typedef struct Q5XRef { Q5XNode *node; u32 offset; u32 extra; } Q5XRef;
typedef struct Q5XNodeVt { void *s[10]; u32 (*get)(Q5XNode *n, Q5XRef *r, u32 offset, u32 size); } Q5XNodeVt;
struct Q5XNode { Q5XNodeVt *vt; };
typedef struct Q5Self { char p0[0x90]; u32 x, y, z, offset; } Q5Self;
extern Q5XRef *ts4_handle_forward_88610A48(Q5XRef *out, Q5XRef *handle, u32 *hash);
extern Q5XRef *ts4_handle_forward_88150770(Q5XRef *out, Q5XRef *handle, u32 *hash);
static u8 q5_null(Q5XRef *r) { return r->node == 0 || r->offset == 0xFFFFFu; }
static u32 q5_get(Q5XRef *r) { return r->node->vt->get(r->node, r, r->offset, 4); }
void ts4_xdata_load_xyz_888B0570(Q5Self *self, Q5XRef h)
{
    Q5XRef a, node, r;
    u32 h0, h1, hx, hy, hz;
    h0 = 0x725D27D9u;
    ts4_handle_forward_88610A48(&a, &h, &h0);
    h1 = 0xB894A04Cu;
    ts4_handle_forward_88610A48(&node, &a, &h1);
    if (!q5_null(&node)) {
        hx = 0xB7B2364Bu;
        ts4_handle_forward_88150770(&r, &node, &hx);
        if (!q5_null(&r)) self->x = q5_get(&r);
        hy = 0xC0B506DDu;
        { Q5XRef t; r = *ts4_handle_forward_88150770(&t, &node, &hy); }
        if (!q5_null(&r)) self->y = q5_get(&r);
        hz = 0x59BC5767u;
        { Q5XRef t; r = *ts4_handle_forward_88150770(&t, &node, &hz); }
        if (!q5_null(&r)) self->z = q5_get(&r);
    }
    self->offset = h.offset;
}
