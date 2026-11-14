/* PC4 batch A: functions reading the script float-constant pool (Swing_DLL.xex). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

/* Pool declared per translation unit: only this form reproduces the original addressing. */
static const float g_ts4_script_constants[668] = {1.0f};

extern double fn_88565040(double);
extern double fn_88564D68(double, double);
extern float lbl_88D488B4;
extern u32 ts4_get_u32__imp_KeTimeStampBundle_8857B830(void);
extern void ts4_lua_pushnumber_888240B8(void *L, double n);

/* 0x88883BA0: timestamp tick count scaled by pool[32]. */
float ts4_get_scaled_timestamp_88883BA0(void)
{
    return (float)ts4_get_u32__imp_KeTimeStampBundle_8857B830() * g_ts4_script_constants[32];
}

/* 0x889D2FA0: store pool[0] / (float)fn_88565040(pool double at +0xA68). */
void ts4_set_inverse_of_const_double_889D2FA0(void)
{
    lbl_88D488B4 = g_ts4_script_constants[0] / (float)fn_88565040(*(const double *)&g_ts4_script_constants[0xA68 / 4]);
}

typedef struct pc4_ptr_holder { char pad[0x20]; float *p; } pc4_ptr_holder;

/* 0x888C0480: self->p[0x2C/4] = (float)fn(self->p[0x2C/4] + pool[109], pool double at +0xD0). */
void ts4_update_field_via_fn_888C0480(pc4_ptr_holder *self)
{
    float x = self->p[0x2C / 4] + g_ts4_script_constants[109];
    self->p[0x2C / 4] = (float)fn_88564D68(x, *(const double *)&g_ts4_script_constants[0xD0 / 4]);
}

/* 0x88804D90: Lua binding pushing timestamp * pool[32]; returns 1 result. */
int ts4_lua_push_scaled_timestamp_88804D90(void **unused, void **state)
{
    (void)unused;
    ts4_lua_pushnumber_888240B8(*state, (float)ts4_get_u32__imp_KeTimeStampBundle_8857B830() * g_ts4_script_constants[32]);
    return 1;
}
