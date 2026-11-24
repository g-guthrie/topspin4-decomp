extern double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif
struct W8bLimF { unsigned char pad00[0xec]; float f_ec; float f_f0; float f_f4; float f_f8; };
struct W8bBall {
    unsigned char pad00[0x28]; struct W8bLimF *lim; unsigned char pad2c[0x38 - 0x2c]; void *h38;
    unsigned char pad3c[0x304 - 0x3c]; float f304; float f308; unsigned char pad30c[0x314 - 0x30c]; float f314;
};
extern float *ts4_if_get_u32_off4c_8865EC70(float *out);
extern void ts4_shot_reward_list_push_88673630(void *h, unsigned id);

void ts4_check_ball_limits_88674218(struct W8bBall *self)
{
    float tmp[4];
    float *v = ts4_if_get_u32_off4c_8865EC70(tmp);
    float x = v[0];
    int a, b, c, d;
    x = (float)fabs(x);
    a = x < self->lim->f_ec;
    b = self->f308 < self->lim->f_f0;
    c = self->f304 < self->lim->f_f4;
    d = self->f314 > self->lim->f_f8;
    if ((unsigned char)b == 1 && (unsigned char)c == 1 && (unsigned char)a == 1 && (unsigned char)d == 1)
        ts4_shot_reward_list_push_88673630(self->h38, 0x1A64FED3u);
}
