/* PC4 batch A: functions reading the script float-constant pool (Swing_DLL.xex). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

/* Pool declared per translation unit: only this form reproduces the original addressing. */
static const float g_ts4_script_constants[668] = {1.0f};
extern float lbl_8814B440;

/* 0x88800CA8: reset a small record, float fields to zero, +0xC to pool[0]. */
void ts4_init_record_const0_88800CA8(float *self)
{
    int *w = (int *)self;
    float one = g_ts4_script_constants[0];
    float zero = lbl_8814B440;
    w[0x28 / 4] = 0;
    w[2] = 0;
    w[1] = 0;
    w[0] = 0;
    self[0x18 / 4] = zero;
    self[0x1C / 4] = zero;
    self[0x20 / 4] = zero;
    w[4] = 0;
    self[5] = zero;
    self[9] = zero;
    self[3] = one;
}
