/* Family SWB2 (jump-table switch). */
typedef struct Obj Obj;
typedef struct Hooks {
    int (*step0)(Obj *);
    int (*step1)(Obj *);
    int (*step2)(Obj *);
} Hooks;
typedef struct Owner {
    int (*notify)(Obj *);
    char pad[0x14 - 4];
    int state;
    int arg;
} Owner;
struct Obj {
    Owner *owner;           /* 0x00 */
    char pad0[0x14 - 4];
    int state;              /* 0x14 */
    Hooks *hooks_a;         /* 0x18 */
    char pad1[0x1b8 - 0x1c];
    Hooks *hooks_b;         /* 0x1b8 */
};

void ts4_jpeg_default_decompress_parms_882E2AE8(Obj *o);

int ts4_state_step_882E2D10(Obj *o)
{
    int result = 0;

    switch (o->state) {
    case 200:
        o->hooks_b->step1(o);
        o->hooks_a->step2(o);
        o->state = 201;
        /* fallthrough */
    case 201:
        result = o->hooks_b->step0(o);
        if (result == 1) {
            ts4_jpeg_default_decompress_parms_882E2AE8(o);
            o->state = 202;
        }
        break;
    case 202:
        return 1;
    case 203: case 204: case 205: case 206: case 207: case 208: case 210:
        return o->hooks_b->step0(o);
    default:
        o->owner->state = 20;
        o->owner->arg = o->state;
        o->owner->notify(o);
        break;
    }
    return result;
}
