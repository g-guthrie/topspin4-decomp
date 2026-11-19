/* 0x883ED2B0: starts the fade-in (state bits 0-1 of +0x2C -> 3) unless already in state 3 or 1; timer +0x28 = in_time scaled by
   the remaining fraction when fading out (state 2), or 1 when in_time is 0. Matched plain /O1 (agT); keeps fn_ name (callee). */
typedef struct Fade {
    char pad[0x20];
    unsigned int in_time;
    unsigned int out_time;
    unsigned int timer;
    unsigned short rest : 14;
    unsigned short state : 2;
} Fade;
int fn_883ED2B0(Fade *o)
{
    float k;
    if (o->state == 3 || o->state == 1)
        return 0;
    if (o->in_time) {
        if (o->state == 2)
            k = 1.0f - (float)o->timer / (float)o->out_time;
        else
            k = 1.0f;
        o->timer = (unsigned int)((float)o->in_time * k);
    } else {
        o->timer = 1;
    }
    o->state = 3;
    return 0;
}
