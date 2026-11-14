/*
 * GP1 draft (near match): ts4_call_seq_u32_off0_88683D78, 3 instructions differ: the compiler stores the float payload
 * field (+0x14) before the two leading integer fields, the original stores it third.
 * Parameter order is (this, name_hash, target, arg_a, arg_b, arg_c, float value): the float travels in f1.
 */
/* GP1: gameplay event posting used by the shot-evaluation package (WP1). */

struct Gp1Pair32 {
    int first;
    int second;
};

struct Gp1EventPayload {
    unsigned int name_hash;   /* +0x00 crc32 of the event name, e.g. "SetExcitement" */
    int target;               /* +0x04 */
    int arg_a;                /* +0x08 */
    int arg_b;                /* +0x0c */
    int arg_c;                /* +0x10 */
    float value;              /* +0x14 */
};

struct Gp1Event {
    unsigned char pad0[8];
    struct Gp1EventPayload *payload; /* +0x08 */
};

struct Gp1EventQueue;

struct Gp1Event *fn_88181240(struct Gp1EventQueue *queue, unsigned int name_hash, struct Gp1Pair32 zero);
void fn_8861DDB0(struct Gp1EventQueue *queue, struct Gp1Event *event);

struct Gp1EventSource {
    struct Gp1EventQueue *queue; /* +0x00 */
};

/* Swing_DLL.xex 0x88683D78: allocates an event, fills its payload and pushes it to the queue. */
void ts4_gameplay_post_event_88683D78(
    struct Gp1EventSource *self,
    unsigned int name_hash,
    int target,
    int arg_a,
    int arg_b,
    int arg_c,
    float value
)
{
    struct Gp1Pair32 zero;
    struct Gp1Event *event;
    struct Gp1EventPayload *payload;

    zero.first = 0;
    zero.second = 0;
    event = fn_88181240(self->queue, name_hash, zero);
    payload = event->payload;
    payload->name_hash = name_hash;
    payload->target = target;
    payload->arg_a = arg_a;
    payload->arg_b = arg_b;
    payload->arg_c = arg_c;
    payload->value = value;
    fn_8861DDB0(self->queue, event);
}

