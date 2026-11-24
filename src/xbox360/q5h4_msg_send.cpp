/* Q5h4: serialize a message into a scratch buffer and send it on the game channel (Top Spin 4, Xbox 360).
 * Clone of the 0x88867B20 template (q5_gameplay_msg_send.cpp). The sister 0x888D56D8 is identical except that its
 * first call is ts4_if_get_u32_lbl_88D45B1C_888C0198 instead of ts4_if_get_u32_lbl_88D45B1C_88864EF8.
 * Codegen: needs C++ (vtable loads are hoisted above calls); the allocation goes through an inline wrapper; the
 * sink is taken into a local inside the `if (h.sink)` block. */
typedef unsigned int u32;
#define Q5H4_V(n) virtual void n()
struct Q5h4Handle;
class Q5h4Owner { public:
    Q5H4_V(v00); Q5H4_V(v04); Q5H4_V(v08); Q5H4_V(v0c); Q5H4_V(v10); Q5H4_V(v14); Q5H4_V(v18); Q5H4_V(v1c);
    Q5H4_V(v20); Q5H4_V(v24); Q5H4_V(v28); Q5H4_V(v2c); Q5H4_V(v30); Q5H4_V(v34); Q5H4_V(v38); Q5H4_V(v3c);
    Q5H4_V(v40); Q5H4_V(v44); Q5H4_V(v48); Q5H4_V(v4c); Q5H4_V(v50); Q5H4_V(v54);
    virtual void release(Q5h4Handle *h); /* +0x58 */
};
class Q5h4Sink { public:
    Q5H4_V(v00); Q5H4_V(v04); Q5H4_V(v08); Q5H4_V(v0c);
    virtual void write(void *buf, u32 size); /* +0x10 */
    Q5h4Owner *owner;
};
struct Q5h4Handle { Q5h4Sink *sink; u32 w4; };
class Q5h4Channel { public:
    Q5H4_V(v00); Q5H4_V(v04); Q5H4_V(v08); Q5H4_V(v0c); Q5H4_V(v10); Q5H4_V(v14); Q5H4_V(v18); Q5H4_V(v1c);
    Q5H4_V(v20); Q5H4_V(v24); Q5H4_V(v28); Q5H4_V(v2c);
    virtual Q5h4Handle open(void *who, u32 flags, u32 size, u32 z); /* +0x30 */
};
class Q5h4Msg { public:
    Q5H4_V(v00);
    virtual void serialize(void *buf, u32 size); /* +0x04 */
    Q5H4_V(v08); Q5H4_V(v0c); Q5H4_V(v10);
    virtual u32 size(); /* +0x14 */
};
struct Q5h4Game { char p0[0x224]; Q5h4Channel *channel; };
extern "C" {
extern Q5h4Game *lbl_88D45B1C;
extern void *lbl_88D45B38;
extern void ts4_if_get_u32_lbl_88D45B1C_88864EF8(void *who);
extern void ts4_if_get_u32_lbl_88D45B1C_888C0198(void *who);
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 flags, u32 pool);
extern void ts4_registry_dispatch_888860A0(void *p);
}
static inline void *q5h4_alloc(u32 n) { return ts4_node_dispatch_with_target_88613268(lbl_88D45B38, n, 1, 0, 2); }

/* 0x888D56D8: the sister, first call is ..._888C0198. */
extern "C" bool ts4_msg_send_on_channel_888D56D8(void *who, Q5h4Msg *msg)
{
    bool ok;
    void *buf;
    ts4_if_get_u32_lbl_88D45B1C_888C0198(who);
    ok = false;
    buf = q5h4_alloc(msg->size());
    if (buf) {
        msg->serialize(buf, msg->size());
        Q5h4Channel *ch = lbl_88D45B1C->channel;
        Q5h4Handle h = ch->open(who, 0xc00, msg->size(), 0);
        if (h.sink) {
            Q5h4Sink *sink = h.sink;
            sink->write(buf, msg->size());
            h.sink->owner->release(&h);
            ok = true;
        }
        ts4_registry_dispatch_888860A0(buf);
    }
    return ok;
}
