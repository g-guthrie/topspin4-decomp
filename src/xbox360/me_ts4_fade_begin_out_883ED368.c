/* 0x883ED368: starts the fade-out (state -> 2) unless in state 2 or 0; timer = out_time scaled by the remaining fraction when
   fading in (state 3), or 1 when out_time is 0. Matched plain /O1 (agT); keeps fn_ name (callee). */
typedef struct Fade {
    char pad[0x20];
    unsigned int in_time;
    unsigned int out_time;
    unsigned int timer;
    unsigned short rest : 14;
    unsigned short state : 2;
} Fade;
int fn_883ED368(Fade *o)
{
    float k;
    if (o->state == 2 || o->state == 0)
        return 0;
    if (o->out_time) {
        if (o->state == 3)
            k = 1.0f - (float)o->timer / (float)o->in_time;
        else
            k = 1.0f;
        o->timer = (unsigned int)((float)o->out_time * k);
    } else {
        o->timer = 1;
    }
    o->state = 2;
    return 0;
}
