extern const float g_ts4_script_constants[];
extern const float g_ts4_event_value;
struct W10lB { unsigned char pad[0xb4]; int xb4; };
struct W10lA { unsigned char pad[0x44]; struct W10lB *p44; };
struct W10lO { unsigned char pad[4]; struct W10lA *p4; };
extern float fn_8861E598(void *p, float a, float b);
float ts4_segment_value_8867EB98(struct W10lO *o, float a, float b, float c)
{
    float zero = g_ts4_event_value;
    float r = fn_8861E598(&o->p4->p44->xb4, zero, a + b + c);
    if (r > zero && r < a)
        return g_ts4_script_constants[14];
    if (a < r && r < a + b)
        return zero;
    {
        float ab = a + b;
        if (ab < r && r < ab + c)
            return g_ts4_script_constants[0];
    }
    return zero;
}
