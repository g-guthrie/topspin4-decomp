/* Swing_DLL.xex 0x88198888-0x88210FD8, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ts4VObject {
    void **vtable;
} Ts4VObject;

extern float g_ts4_script_constants[];
extern float g_ts4_event_value;
extern float *fn_881F5DE0(void *key);
extern void fn_8820F390(void *key, float *out);
extern u8 fn_881CCEE0(void);
extern void fn_881E19C0(void);
extern void fn_881DFE70(void);
extern void fn_881E0258(void);

typedef struct Ts4Range80 {
    u8 pad[0x80];
    u32 begin;
    u8 pad2[0x08];
    u32 length;
} Ts4Range80;

u8 ts4_in_range_88198888(Ts4Range80 *self, u32 value)
{
    return value >= self->begin && value < self->begin + self->length;
}

typedef struct Ts4ByteCompare {
    u8 pad[4];
    u8 *other;
    u8 value;
} Ts4ByteCompare;

typedef struct Ts4WordCompare {
    u8 pad[4];
    u32 *other;
    u32 value;
} Ts4WordCompare;

typedef struct Ts4FloatHolder {
    u8 pad[0x1c];
    float value;
} Ts4FloatHolder;

u8 ts4_float_differs_881CCA08(Ts4FloatHolder *self)
{
    return self->value != g_ts4_script_constants[0];
}

float ts4_lookup_x_881F3390(void *unused, void *key)
{
    (void)unused;
    return fn_881F5DE0(key)[0];
}

float ts4_lookup_y_881F3408(void *unused, void *key)
{
    (void)unused;
    return fn_881F5DE0(key)[1];
}

float ts4_lookup_z_881F3480(void *unused, void *key)
{
    (void)unused;
    return fn_881F5DE0(key)[2];
}

float ts4_query_x_8820C6B8(void *unused, void *key)
{
    float out[4];
    (void)unused;
    fn_8820F390(key, out);
    return out[0];
}

float ts4_query_y_8820C7A0(void *unused, void *key)
{
    float out[4];
    (void)unused;
    fn_8820F390(key, out);
    return out[1];
}

float ts4_query_z_8820C888(void *unused, void *key)
{
    float out[4];
    (void)unused;
    fn_8820F390(key, out);
    return out[2];
}

float ts4_query_w_8820C970(void *unused, void *key)
{
    float out[4];
    (void)unused;
    fn_8820F390(key, out);
    return out[3];
}

typedef struct Ts4FloatArrayA {
    u8 pad[0x20];
    float *data;
    u32 count;
} Ts4FloatArrayA;

float ts4_float_at_8820A318(Ts4FloatArrayA *self, u32 index)
{
    if (index < self->count) {
        return self->data[index];
    }
    return g_ts4_event_value;
}

typedef struct Ts4FloatArrayB {
    u8 pad[0x30];
    float *data;
    u32 count;
} Ts4FloatArrayB;

float ts4_float_at_8820A340(Ts4FloatArrayB *self, u32 index)
{
    if (index < self->count) {
        return self->data[index];
    }
    return g_ts4_event_value;
}

