/* CW38: functions with a divide (need /Oc). */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Ev3 { char pad[0x2c]; char *p2c; char pad2[0x1c]; int f4c; } Ev3;
void ts4_check_minute_887CF598(u32 *out, Ev3 *ev, u32 *res)
{
    int m = *(int *)(ev->p2c + 0x368) / 60;
    u8 ok;
    if (m >= 10 && m % 10 == 0 && m > ev->f4c) ok = 1; else ok = 0;
    *out = 0;
    if (ok) {
        res[8] = m;
        *out = 0x724b20beU;
    }
    ev->f4c = m;
}
