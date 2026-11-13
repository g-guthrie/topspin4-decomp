/* Swing_DLL.xex 0x8818BA38-0x881CD5C8, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ts4VObject {
    void **vtable;
} Ts4VObject;

extern void *lbl_880DD110[];
extern int fn_88565F50(void *a, int b, void *c, void *d);
extern void fn_88566FE8(void *a);
extern int fn_8857BBB0(void *a, void *b, void *c, u32 *out, int e);
extern float g_ts4_script_constants[];

typedef struct Ts4SlotCaller {
    u8 pad[0x10];
    Ts4VObject *target;
} Ts4SlotCaller;

typedef struct Ts4SimpleObject {
    void **vtable;
    int a;
    int b;
    u8 c;
    int d;
} Ts4SimpleObject;

Ts4SimpleObject *ts4_construct_simple_8818BC08(Ts4SimpleObject *self)
{
    if (self != 0) {
        self->a = 0;
        self->vtable = lbl_880DD110;
        self->b = 0;
        self->c = 0;
        self->d = 0;
        return self;
    }
    return 0;
}

typedef struct Ts4Handle10 {
    u8 pad[0x10];
    void *handle;
} Ts4Handle10;

void *ts4_call_with_handle_8818BE98(Ts4Handle10 *self, void *a, void *b)
{
    fn_88565F50(a, 1, b, self->handle);
    return b;
}

typedef struct Ts4Functor {
    u32 (*callback)(void *argument);
} Ts4Functor;

typedef struct Ts4VirtualMinus {
    Ts4VObject base;
    u8 pad[0x8c];
    int limit;
} Ts4VirtualMinus;

typedef struct Ts4Field14 {
    u8 pad[0x14];
    void *inner;
} Ts4Field14;

u32 ts4_query_value_881A55F8(Ts4Field14 *self, void *a, void *b)
{
    u32 out = 0;
    fn_8857BBB0(self->inner, a, b, &out, 0);
    return out;
}

typedef struct Ts4OffsetArrayHeader {
    int offset;
    int count;
} Ts4OffsetArrayHeader;

void *ts4_offset_array_end12_881AD078(Ts4OffsetArrayHeader *header)
{
    void *result = 0;
    if (header->offset != -1) {
        result = (char *)header + (header->count * 12 + header->offset);
    }
    return result;
}

void *ts4_offset_array_end40_881B8F18(Ts4OffsetArrayHeader *header)
{
    void *result = 0;
    if (header->offset != -1) {
        result = (char *)header + (header->count * 40 + header->offset);
    }
    return result;
}

typedef struct Ts4ValueSink {
    void **vtable;
    float *slot;
} Ts4ValueSink;

void ts4_store_float_notify_881B4608(Ts4ValueSink *self, float *value, u8 notify)
{
    if (self->slot == 0) {
        return;
    }
    *self->slot = *value;
    if (notify) {
        ((void (*)(Ts4ValueSink *))self->vtable[0])(self);
    }
}

void ts4_store_byte_notify_881B4670(Ts4ValueSink *self, u8 *value, u8 notify)
{
    u8 *slot = (u8 *)self->slot;
    if (slot == 0) {
        return;
    }
    *slot = *value;
    if (notify) {
        ((void (*)(Ts4ValueSink *))self->vtable[0])(self);
    }
}

void ts4_store_word_notify_881B46D8(Ts4ValueSink *self, u32 *value, u8 notify)
{
    u32 *slot = (u32 *)self->slot;
    if (slot == 0) {
        return;
    }
    *slot = *value;
    if (notify) {
        ((void (*)(Ts4ValueSink *))self->vtable[0])(self);
    }
}

typedef struct Ts4Node {
    struct Ts4Node *next;
} Ts4Node;

typedef struct Ts4NodeStack {
    Ts4Node *head;
    int count;
} Ts4NodeStack;

typedef struct Ts4PackedColor {
    u8 pad[0x24];
    u32 packed;
} Ts4PackedColor;

float ts4_color_byte0_881CD2E0(void *unused, Ts4PackedColor *color)
{
    u32 value = color->packed;
    (void)unused;
    return (float)((u8 *)&value)[1] * g_ts4_script_constants[17];
}

float ts4_color_byte1_881CD3D8(void *unused, Ts4PackedColor *color)
{
    u32 value = color->packed;
    (void)unused;
    return (float)((u8 *)&value)[2] * g_ts4_script_constants[17];
}

float ts4_color_byte2_881CD4D0(void *unused, Ts4PackedColor *color)
{
    u32 value = color->packed;
    (void)unused;
    return (float)((u8 *)&value)[3] * g_ts4_script_constants[17];
}

float ts4_color_byte3_881CD5C8(void *unused, Ts4PackedColor *color)
{
    u32 value = color->packed;
    (void)unused;
    return (float)((u8 *)&value)[0] * g_ts4_script_constants[17];
}
