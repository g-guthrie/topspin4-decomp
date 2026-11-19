/* 0x882A3178: Reads the time base through fn_8857AFF0 (mftb, a QueryPerformanceCounter-style helper) and returns (unsigned)(now >> 10) minus the start value at +0x5584. */
/* Matched on /Oc /Os (agAH). Built /Os; the (unsigned int) cast of the shifted 64-bit value gives clrrwi r11,r11,0. */
int fn_8857AFF0(long long *out);
typedef struct Timer { char pad[0x5584]; unsigned int base; } Timer;
unsigned int fn_882A3178(Timer *t)
{
    long long now;
    fn_8857AFF0(&now);
    return (unsigned int)(now >> 10) - t->base;
}
