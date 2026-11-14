/* Loader_DLL.xex 0x8324D518-0x8324D6C4, executable version 0.0.0.3. */

typedef struct ts4l_sm_ctx {
    unsigned char pad0[0x50];
    unsigned int state;
    unsigned char pad1[0xE0 - 0x54];
    void *dev;
    int flag_e4;
    int flag_e8;
} ts4l_sm_ctx;

typedef struct ts4l_sm_obj {
    unsigned char pad[0x1C];
    ts4l_sm_ctx *ctx;
} ts4l_sm_obj;

extern int fn_8324B100(ts4l_sm_obj *o);
extern int fn_83249770(ts4l_sm_obj *o);
extern int fn_8324C3A8(ts4l_sm_obj *o);
extern int ts4l_if_get_u32_off0_83233A38(void *dev, int a, int b, int c);
extern int ts4l_if_call_seq_fn_83233950_83233AE8(void *dev, int a, int b, int c, int d, int e, int f);

int ts4l_sm_step_8324D518(ts4l_sm_obj *o)
{
    ts4l_sm_ctx *c = o->ctx;
    int r = 0;

    if (c == 0)
        r = (int)0x80070057;
    else if (c->flag_e4 == 0) for (;;) {
        switch (c->state) {
        case 0:
        case 1:
        case 2:
        case 3:
            r = fn_8324B100(o);
            if (r < 0)
                return r;
            break;
        case 4:
            c->state = 5;
            r = ts4l_if_get_u32_off0_83233A38(c->dev, 1, 0, 0);
            if (r < 0)
                return r;
            if (r != 0x500006)
                goto ok;
            c->state = 14;
            break;
        case 14: case 15: case 16:
            r = fn_83249770(o);
            if (r < 0)
                return r;
            break;
        case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13:
            r = fn_8324C3A8(o);
            if (r < 0)
                return r;
            if (c->flag_e4 == 0 && c->flag_e8 == 0)
                break;
            if (c->flag_e8 == 0)
                return r;
            c->flag_e8 = 0;
            return r;
        case 17:
            c->state = 5;
            r = ts4l_if_call_seq_fn_83233950_83233AE8(c->dev, 1, 0x10010, 0, 0, 0, 4);
            if (r < 0)
                return r;
        ok:
            return 0;
        case 18:
            return 0x50000B;
        }
    }
    return r;
}
