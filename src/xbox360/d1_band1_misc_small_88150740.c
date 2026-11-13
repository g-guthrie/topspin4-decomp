/* Swing_DLL.xex 0x88150740-0x881DD970, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ts4VObject {
    void **vtable;
} Ts4VObject;

extern void ts4_assign_formatted_text(void *object, const char *text);
extern char lbl_880C1320[];
extern int fn_881932B8(void *self, int a, int b);
extern int lbl_88C6A86C[];
extern void *lbl_880DD0A0[];

typedef struct Ts4LimitPair {
    int first;
    u32 second;
} Ts4LimitPair;

u8 ts4_is_unset_or_max_88150740(Ts4LimitPair *self)
{
    return self->first == 0 || self->second == 0xfffff;
}

void *ts4_assign_default_text_8815F060(void *self)
{
    ts4_assign_formatted_text(self, lbl_880C1320);
    return self;
}

typedef struct Ts4Forwarder34 {
    u8 pad[0x34];
    long target;
} Ts4Forwarder34;

int ts4_forward_slot7_8818AD58(Ts4Forwarder34 *self, int arg, u32 index)
{
    Ts4VObject *target = (Ts4VObject *)self->target;
    if (self->target != 0) {
        return ((int (*)(Ts4VObject *, int, int))target->vtable[7])(target, arg, lbl_88C6A86C[index]);
    }
    return fn_881932B8(self, arg, index);
}

typedef struct Ts4SimpleObject {
    void **vtable;
    int a;
    int b;
    u8 c;
    int d;
} Ts4SimpleObject;

Ts4SimpleObject *ts4_construct_simple_8818B6D0(Ts4SimpleObject *self)
{
    if (self != 0) {
        self->a = 0;
        self->vtable = lbl_880DD0A0;
        self->b = 0;
        self->c = 0;
        self->d = 0;
        return self;
    }
    return 0;
}

typedef struct Ts4FlagOwner {
    u8 pad[0xc];
    long child;
    u8 pad2[0x10];
    u8 flag;
} Ts4FlagOwner;

void ts4_set_flag_notify_881DD970(Ts4FlagOwner *self, u8 value)
{
    Ts4VObject *child = (Ts4VObject *)self->child;
    self->flag = value;
    if (self->child != 0) {
        ((void (*)(Ts4VObject *, int))child->vtable[20])(child, 1);
    }
}
