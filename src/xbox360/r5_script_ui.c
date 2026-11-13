#include "script_context.h"

struct TS4R5Dispatcher;
struct TS4R5EventTarget;
struct TS4R5Visitor;
struct TS4R5StateMachine;

struct TS4R5DispatchVtable {
    void *slots0[10];
    int (*handle_a)(struct TS4R5Dispatcher *, int);
    int (*handle_b)(struct TS4R5Dispatcher *, int);
    int (*handle_c)(struct TS4R5Dispatcher *, int);
    int (*handle_d)(struct TS4R5Dispatcher *, int);
    int (*handle_e)(struct TS4R5Dispatcher *, int);
    int (*handle_f)(struct TS4R5Dispatcher *, int);
};
struct TS4R5Dispatcher {
    struct TS4R5DispatchVtable *vtable;
};
struct TS4R5Message {
    ts4_script_u32 type_id;
    ts4_script_u32 reserved;
    int payload;
};

extern ts4_script_u32 lbl_88C6C1EC;
extern ts4_script_u32 lbl_88C6C1F0;
extern ts4_script_u32 lbl_88C6C1F4;
extern ts4_script_u32 lbl_88C6C1F8;
extern ts4_script_u32 lbl_88C6C1FC;
extern ts4_script_u32 lbl_88C6C200;

/* Visitor-style dispatch: pick a virtual handler (slots 10..15) by comparing the message type id against six known ids; returns 8 when unmatched. */
int ts4_r5_dispatch_message_by_type_887E9AA0(struct TS4R5Dispatcher *self, struct TS4R5Message *message)
{
    int result = 8;
    ts4_script_u32 type = message->type_id;

    if (type == lbl_88C6C1EC) {
        return self->vtable->handle_a(self, message->payload);
    }
    if (type == lbl_88C6C1F0) {
        return self->vtable->handle_b(self, message->payload);
    }
    if (type == lbl_88C6C1F4) {
        return self->vtable->handle_c(self, message->payload);
    }
    if (type == lbl_88C6C1F8) {
        return self->vtable->handle_d(self, message->payload);
    }
    if (type == lbl_88C6C1FC) {
        return self->vtable->handle_e(self, message->payload);
    }
    if (type == lbl_88C6C200) {
        result = self->vtable->handle_f(self, message->payload);
    }
    return result;
}

struct TS4R5EventTarget;
struct TS4R5EventVtable {
    void *slots0[0x23];
    void (*on_event_a)(struct TS4R5EventTarget *);
    void (*on_event_b)(struct TS4R5EventTarget *);
};
struct TS4R5EventTarget {
    struct TS4R5EventVtable *vtable;
    ts4_script_u32 reserved[2];
    ts4_script_u32 event_id;
};

/* Forward a hashed event id (field +0xC) to virtual slot 0x8C or 0x90; unknown ids are ignored. */
void ts4_r5_forward_event_by_id_887F0180(struct TS4R5EventTarget *self)
{
    switch (self->event_id) {
    case 0x28921D4C:
        self->vtable->on_event_a(self);
        break;
    case 0x21245167:
        self->vtable->on_event_a(self);
        break;
    case 0x2FFFD955:
        self->vtable->on_event_b(self);
        break;
    case 0x58F8E9C3:
        self->vtable->on_event_a(self);
        break;
    case 0x562361F1:
        self->vtable->on_event_b(self);
        break;
    case 0x5F952DDA:
        self->vtable->on_event_a(self);
        break;
    case 0xB6F688EF:
        self->vtable->on_event_b(self);
        break;
    case 0xB19B4CF6:
        self->vtable->on_event_b(self);
        break;
    case 0xC1F1B879:
        self->vtable->on_event_a(self);
        break;
    case 0xC69C7C60:
        self->vtable->on_event_a(self);
        break;
    default:
        break;
    }
}

struct TS4R5NameKey {
    ts4_script_u8 reserved[8];
    ts4_script_u32 name_hash;
};

extern char lbl_880E5EE4[];
extern char lbl_880E5F14[];
extern char lbl_880E5F24[];
extern char lbl_880E5F34[];
extern char lbl_880E5F44[];
extern char lbl_880E5F54[];
extern char lbl_880E5F64[];
extern char lbl_880E5F74[];
extern char lbl_880E5F84[];
extern char lbl_880E5F94[];
extern char lbl_880E5FA8[];
extern char lbl_880E5FBC[];
extern char lbl_880E5FD0[];
void fn_8816CAA0(void *target, const char *name);

/* Map a hashed key (field +8) onto its name string (Corridor, PlayerNNDynNN, ...) and forward it to fn_8816CAA0 with the target. */
void ts4_r5_apply_name_for_hash_887DE350(struct TS4R5NameKey *key, void *target)
{
    if (key->name_hash != 0xDFA2AFF1) {
        switch (key->name_hash) {
        case 0x1539F4FB:
            fn_8816CAA0(target, lbl_880E5F84);
            break;
        case 0x2FF66566:
            fn_8816CAA0(target, lbl_880E5F34);
            break;
        case 0x58F155F0:
            fn_8816CAA0(target, lbl_880E5F44);
            break;
        case 0x623EC46D:
            fn_8816CAA0(target, lbl_880E5F74);
            break;
        case 0x8845BC01:
            fn_8816CAA0(target, lbl_880E5FBC);
            break;
        case 0x93AD8655:
            fn_8816CAA0(target, lbl_880E5F24);
            break;
        case 0x9F3EA842:
            fn_8816CAA0(target, lbl_880E5FD0);
            break;
        case 0xA6B39487:
            fn_8816CAA0(target, lbl_880E5F94);
            break;
        case 0xA96217C8:
            fn_8816CAA0(target, lbl_880E5F54);
            break;
        case 0xB1C880C4:
            fn_8816CAA0(target, lbl_880E5FA8);
            break;
        case 0xDE65275E:
            fn_8816CAA0(target, lbl_880E5F64);
            break;
        case 0xE4AAB6C3:
            fn_8816CAA0(target, lbl_880E5F14);
            break;
        default:
            break;
        }
    } else {
        fn_8816CAA0(target, lbl_880E5EE4);
    }
}

struct TS4R5Visitor;
struct TS4R5VisitVtable {
    void (*slot[0x30])(struct TS4R5Visitor *);
};
struct TS4R5Visitor {
    struct TS4R5VisitVtable *vtable;
};
struct TS4R5VisitMessage {
    ts4_script_u8 reserved[0x18];
    ts4_script_u32 type_id;
};

extern ts4_script_u32 lbl_88C6BF84;
extern ts4_script_u32 lbl_88C6BF88;
extern ts4_script_u32 lbl_88C6BF8C;
extern ts4_script_u32 lbl_88C6BF90;
extern ts4_script_u32 lbl_88C6BFC0;
extern ts4_script_u32 lbl_88C6BFC4;
extern ts4_script_u32 lbl_88C6C014;
extern ts4_script_u32 lbl_88C6BFC8;
extern ts4_script_u32 lbl_88C6BF94;
extern ts4_script_u32 lbl_88C6BFE0;
extern ts4_script_u32 lbl_88C6BFE8;
extern ts4_script_u32 lbl_88C6BFEC;
extern ts4_script_u32 lbl_88C6BFE4;
extern ts4_script_u32 lbl_88C6BFF0;
extern ts4_script_u32 lbl_88C6BFDC;

#define TS4_R5_VISIT(type_global, offset) \
    if ((type_global) == type) { \
        self->vtable->slot[(offset) / 4](self); \
        return; \
    }

/* Visitor dispatch: tail-call the virtual handler (slots 0x50..0x88) whose type-id global equals the message type at +0x18. */
void ts4_r5_visit_message_by_type_887F02D8(struct TS4R5Visitor *self, struct TS4R5VisitMessage *message)
{
    ts4_script_u32 type = message->type_id;

    TS4_R5_VISIT(lbl_88C6BF84, 0x5C)
    TS4_R5_VISIT(lbl_88C6BF88, 0x64)
    TS4_R5_VISIT(lbl_88C6BF8C, 0x68)
    TS4_R5_VISIT(lbl_88C6BF90, 0x60)
    TS4_R5_VISIT(lbl_88C6BFC0, 0x58)
    TS4_R5_VISIT(lbl_88C6BFC4, 0x54)
    TS4_R5_VISIT(lbl_88C6C014, 0x50)
    TS4_R5_VISIT(lbl_88C6BFC8, 0x6C)
    TS4_R5_VISIT(lbl_88C6BF94, 0x70)
    TS4_R5_VISIT(lbl_88C6BFE0, 0x78)
    TS4_R5_VISIT(lbl_88C6BFE8, 0x7C)
    TS4_R5_VISIT(lbl_88C6BFEC, 0x80)
    TS4_R5_VISIT(lbl_88C6BFE4, 0x84)
    TS4_R5_VISIT(lbl_88C6BFF0, 0x88)
    TS4_R5_VISIT(lbl_88C6BFDC, 0x74)
}

struct TS4R5StateMachineVtable {
    ts4_script_u8 reserved[0x54];
    void (*on_state_a_changed)(struct TS4R5StateMachine *, ts4_script_u32 *, ts4_script_u32 *);
    void (*on_state_b_changed)(struct TS4R5StateMachine *, ts4_script_u32 *, ts4_script_u32 *);
    void (*finish)(struct TS4R5StateMachine *);
    void (*post_event)(struct TS4R5StateMachine *, ts4_script_u32 *, int);
};
struct TS4R5StateSourceA {
    ts4_script_u8 reserved[0x1C0];
    ts4_script_u32 state;
};
struct TS4R5StateSourceB {
    ts4_script_u8 reserved[0x250];
    ts4_script_u32 state;
};
struct TS4R5StateFlags {
    ts4_script_u8 reserved[0x1C];
    ts4_script_u8 flag1c;
    ts4_script_u8 flag1d;
    ts4_script_u8 reserved1e[0x96 - 0x1E];
    ts4_script_u8 flag96;
    ts4_script_u8 reserved97[0xCD - 0x97];
    ts4_script_u8 flagcd;
    ts4_script_u8 reservedce[0xD7 - 0xCE];
    ts4_script_u8 flagd7;
    ts4_script_u8 reservedd8[0xE5 - 0xD8];
    ts4_script_u8 flage5;
};
struct TS4R5StateMachine {
    struct TS4R5StateMachineVtable *vtable;
    ts4_script_u8 reserved[0x20];
    ts4_script_u32 state_a;
    ts4_script_u32 state_b;
    struct TS4R5StateSourceA *source_a;
    struct TS4R5StateSourceB *source_b;
    struct TS4R5StateFlags *flags;
};
struct TS4R5NotifyHost108 {
    ts4_script_u8 reserved[0x8CA];
    ts4_script_u8 flag8ca;
};
struct TS4R5NotifyHost {
    ts4_script_u8 reserved[0x108];
    struct TS4R5NotifyHost108 *host108;
    ts4_script_u8 reserved10c[0x374 - 0x10C];
    ts4_script_u8 flag374;
};

extern struct TS4R5NotifyHost *g_ts4_tsu_notification_object;
void fn_887D2960(struct TS4R5StateMachine *machine, int arg);

/* Sync the state machine with its two sources, then post the follow-up events implied by the flag block. */
void ts4_r5_state_machine_sync_887D5D58(struct TS4R5StateMachine *self)
{
    ts4_script_u32 event_a;
    ts4_script_u32 event_b;

    if (self->source_a->state != self->state_a) {
        self->vtable->on_state_a_changed(self, &self->state_a, &self->source_a->state);
    }
    if (self->source_b->state != self->state_b) {
        self->vtable->on_state_b_changed(self, &self->state_b, &self->source_b->state);
    }
    if (self->flags->flage5 != 0) {
        fn_887D2960(self, 0);
    }
    if (self->flags->flagcd != 0 && self->flags->flagd7 == 0) {
        ts4_script_u8 blocked = (self->flags->flag1c != 0 && self->flags->flag1d == 0);
        if (blocked == 0 || (g_ts4_tsu_notification_object->flag374 == 0
                             && g_ts4_tsu_notification_object->host108->flag8ca != 0)) {
            event_a = 0x87B1920F;
            self->vtable->post_event(self, &event_a, 1);
        }
    }
    if (self->flags->flag96 != 0) {
        event_b = 0x29899E83;
        self->vtable->post_event(self, &event_b, 1);
    }
    if (self->state_a != 0x165BBDE9) {
        self->vtable->finish(self);
    }
}

