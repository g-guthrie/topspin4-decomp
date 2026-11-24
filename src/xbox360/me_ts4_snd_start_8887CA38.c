
typedef unsigned int u32; typedef unsigned short u16; typedef unsigned char u8;
typedef struct Snd { char pad[8]; void *mgr; char pad2[0x1e]; u16 mode; u32 prio; } Snd;
typedef struct O { char pad[0x10]; Snd *snd; char pad2[0x44]; u32 hash; char pad3[0xc]; u8 playing; } O;
extern void ts4_if_call_seq_u32_off8_88473208(void *p, int a, int b, int c);
extern void fn_8846F580(void *a, void *b, int c, int d);
void fn_8887CA38(O *o)
{
    if (o->snd) {
        { u32 *h = &o->hash; *h = 0x29E6DBEF; }
        ts4_if_call_seq_u32_off8_88473208(o->snd, 7, 1, 0);
        o->snd->mode = 1;
        o->playing = 1;
        o->snd->prio = 10;
        fn_8846F580(o->snd->mgr, o->snd, 0, 0);
    }
}
