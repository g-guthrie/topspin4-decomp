/* W8A batch C: timed state pump (plain route, /Oc) */

/* 0x8864CF98: run the state handler (1/2/3) until the wait object signals or the 30 s watchdog resets the state. */
typedef unsigned long long u64;
typedef struct W8aH8CF98 { void *h; } W8aH8CF98;
typedef struct W8aP8CF98 { W8aH8CF98 *p0; } W8aP8CF98;
typedef struct W8aS8CF98 {
    char pad[4]; int state; int f8; char pc[0x4c - 0xc]; W8aP8CF98 *p4c;
    unsigned char f50; unsigned char f51;
} W8aS8CF98;
extern unsigned ts4_get_u32__imp_KeTimeStampBundle_8857B830();
extern int ts4_tailcall_fn_88582F30_8857A128(void *h, int ms);
void fn_8864C980(W8aS8CF98 *s);
void ts4_if_call_seq_u32_off80_8864B318(W8aS8CF98 *s);
void ts4_if_call_seq_fn_884F0388_8864B3D8(W8aS8CF98 *s);
void ts4_pump_state_8864CF98(W8aS8CF98 *s)
{
    u64 start = (unsigned)ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    if (s->f50 != 0)
        return;
    do {
        if (!s->f51) {
            u64 now = (unsigned)ts4_get_u32__imp_KeTimeStampBundle_8857B830();
            u64 d;
            if (now < start)
                d = now - start + (u64)0xffffffffu;
            else
                d = now - start;
            if (d > 30000) {
                s->state = 0;
                s->f8 = 2;
            }
        }
        switch (s->state) {
        case 1: ts4_if_call_seq_fn_884F0388_8864B3D8(s); break;
        case 2: ts4_if_call_seq_u32_off80_8864B318(s); break;
        case 3: fn_8864C980(s); break;
        }
        {
            unsigned r = ts4_tailcall_fn_88582F30_8857A128(s->p4c->p0->h, 200);
            if (r != 0x102 && r == 0)
                return;
        }
    } while (s->f50 == 0);
}
