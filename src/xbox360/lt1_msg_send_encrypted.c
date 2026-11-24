/* Family LT1: message channel send with Blowfish encryption, verified with the LTCG route
 * (tools/fn_check_ltcg.py, docs/ltcg-route.md). The original keeps r6 (the old buffer) across
 * the call to the message-pool getter and r4 (the scratch buffer) across the Blowfish call:
 * whole-program register knowledge that needs fam3_msg_dtor.cpp and d3f_blowfish_ecb_88605010.c
 * in the same /LTCG link. Swing_DLL.xex. */

struct Ts4MsgList;
struct Ts4MsgCodec;

struct Ts4MsgCodecVtbl {
    void *slot0;
    int (*packet_capacity)(struct Ts4MsgCodec *codec);              /* +0x04 */
    int (*encode)(struct Ts4MsgCodec *codec, char *buffer);         /* +0x08 returns the packet length */
};

struct Ts4MsgCodec {
    struct Ts4MsgCodecVtbl *vtbl;
};

struct Ts4MsgCodecOwner {
    char pad_00[0x08];
    struct Ts4MsgCodec *codec;   /* +0x08 */
};

struct Ts4MsgSocket {
    char pad_00[0x04];
    void *socket;                /* +0x04 */
};

struct Ts4MsgPacket {
    int capacity;                /* +0x00 */
    char *data;                  /* +0x04 pooled buffer: 8-byte header, then the payload */
};

struct Ts4MsgChannel {
    char pad_00[0x0C];
    char pending[0x04];          /* +0x0C message list {count, head, tail} */
    struct Ts4MsgCodecOwner *codec_owner; /* +0x10 */
    char pad_14[0x10];
    void **lock;                 /* +0x24 points at the critical section pointer */
    char pad_28[0x2C];
    struct Ts4MsgPacket packet;  /* +0x54 */
    char pad_5c[0x24];
    struct Ts4MsgSocket *net;    /* +0x80 */
};

extern void RtlEnterCriticalSection(void *section);
extern void RtlLeaveCriticalSection(void *section);
#ifdef _MSC_VER
extern void *memset(void *dst, int c, unsigned int n);
extern void *memcpy(void *dst, const void *src, unsigned long n);
#else
#include <string.h>
#endif
extern char *ts4_msg_buffer_alloc_88278620(int size);
extern void *ts4_msg_pool_service_get_8864DFF0(void);
extern void ts4_registry_dispatch_888860A0(void *block);
extern void ts4_blowfish_encrypt_ecb_88605220(void *cipher, void *out, const void *in, int len);
extern int ts4_tailcall_NetDll_send_884F0350(void *socket, void *data, int len, int flags);
#ifdef _MSC_VER
#define LT1_NOINLINE __declspec(noinline)
#else
#define LT1_NOINLINE
#endif
extern LT1_NOINLINE void ts4_msg_list_pop_882784F0(void *list);
extern void fn_889BD8B0(struct Ts4MsgCodec *codec);
extern char lbl_88D44240[]; /* Blowfish key schedule of the session */

/* Encode the next packet into the channel buffer (growing it to the codec's capacity), encrypt the
   payload after the 8-byte header with Blowfish ECB, send it, and pop the sent message.
   Returns 0 when the whole packet was sent, -1 otherwise. Swing_DLL.xex 0x8864BE20 */
int lt1_msg_channel_send_encrypted_8864BE20(struct Ts4MsgChannel *self)
{
    void **lock = self->lock;
    struct Ts4MsgCodec *codec;
    int need;
    int len;
    int sent;
    char *scratch;
    struct Ts4MsgPacket *packet;
    RtlEnterCriticalSection(*lock);
    codec = self->codec_owner->codec;
    need = codec->vtbl->packet_capacity(codec);
    packet = &self->packet;
    if (packet->capacity < need) {
        char *grown = ts4_msg_buffer_alloc_88278620(need);
        char *old = packet->data;
        if (old) {
            ts4_msg_pool_service_get_8864DFF0();
            ts4_registry_dispatch_888860A0(old - 8);
        }
        packet->data = grown;
        packet->capacity = need;
    }
    len = codec->vtbl->encode(codec, self->packet.data);
    scratch = ts4_msg_buffer_alloc_88278620(len);
    memset(scratch, 0, len);
    ts4_blowfish_encrypt_ecb_88605220(lbl_88D44240, scratch, self->packet.data + 8, len - 8);
    memcpy(self->packet.data + 8, scratch, len - 8);
    sent = ts4_tailcall_NetDll_send_884F0350(self->net->socket, self->packet.data, len, 0);
    ts4_msg_list_pop_882784F0(self->pending);
    fn_889BD8B0(codec);
    if (scratch) {
        ts4_msg_pool_service_get_8864DFF0();
        ts4_registry_dispatch_888860A0(scratch - 8);
    }
    if (sent != len) {
        RtlLeaveCriticalSection(*lock);
        return -1;
    }
    RtlLeaveCriticalSection(*lock);
    return 0;
}
