/* Q5: serialize a message into a scratch buffer and send it on the game channel.
 * 0x88867B20: prepare the sender, allocate msg->size() bytes from the heap at
 * lbl_88D45B38 (align 1, pool 2), let the message serialize into it, open a
 * channel handle (flags 0xC00) on lbl_88D45B1C->channel, write the buffer to
 * the handle's sink, release the handle, free the buffer. Returns true only
 * when a sink was opened.
 * Codegen: needs C++ (vtable loads are hoisted above calls); the allocation
 * goes through an inline wrapper (direct call reorders the li of 1 and 2);
 * the sink is taken into a local inside the `if (h.sink)` block.
 * Sister 0x888D56D8 calls ts4_if_get_u32_lbl_88D45B1C_888C0198 instead. */
typedef unsigned int u32;
#define V4(n) virtual void n()
struct Q5Handle;
class Q5Owner { public:
    V4(v00); V4(v04); V4(v08); V4(v0c); V4(v10); V4(v14); V4(v18); V4(v1c);
    V4(v20); V4(v24); V4(v28); V4(v2c); V4(v30); V4(v34); V4(v38); V4(v3c);
    V4(v40); V4(v44); V4(v48); V4(v4c); V4(v50); V4(v54);
    virtual void release(Q5Handle *h); /* +0x58 */
};
class Q5Sink { public:
    V4(v00); V4(v04); V4(v08); V4(v0c);
    virtual void write(void *buf, u32 size); /* +0x10 */
    Q5Owner *owner;
};
struct Q5Handle { Q5Sink *sink; u32 w4; };
class Q5Channel { public:
    V4(v00); V4(v04); V4(v08); V4(v0c); V4(v10); V4(v14); V4(v18); V4(v1c);
    V4(v20); V4(v24); V4(v28); V4(v2c);
    virtual Q5Handle open(void *who, u32 flags, u32 size, u32 z); /* +0x30 */
};
class Q5Msg { public:
    V4(v00);
    virtual void serialize(void *buf, u32 size); /* +0x04 */
    V4(v08); V4(v0c); V4(v10);
    virtual u32 size(); /* +0x14 */
};
struct Q5Game { char p0[0x224]; Q5Channel *channel; };
extern "C" {
extern Q5Game *lbl_88D45B1C;
extern void *lbl_88D45B38;
extern void ts4_if_get_u32_lbl_88D45B1C_88864EF8(void *who);
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 flags, u32 pool);
extern void ts4_registry_dispatch_888860A0(void *p);
}
static inline void *q5_alloc(u32 n) { return ts4_node_dispatch_with_target_88613268(lbl_88D45B38, n, 1, 0, 2); }
extern "C" bool ts4_msg_send_on_channel_88867B20(void *who, Q5Msg *msg)
{
    bool ok;
    void *buf;
    ts4_if_get_u32_lbl_88D45B1C_88864EF8(who);
    ok = false;
    buf = q5_alloc(msg->size());
    if (buf) {
        msg->serialize(buf, msg->size());
        Q5Channel *ch = lbl_88D45B1C->channel;
        Q5Handle h = ch->open(who, 0xc00, msg->size(), 0);
        if (h.sink) {
            Q5Sink *sink = h.sink;
            sink->write(buf, msg->size());
            h.sink->owner->release(&h);
            ok = true;
        }
        ts4_registry_dispatch_888860A0(buf);
    }
    return ok;
}
