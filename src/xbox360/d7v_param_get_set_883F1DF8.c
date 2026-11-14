/* Swing_DLL.xex 0x883F1DF8-0x883F1E88, 0x883F1F10-0x883F1FA0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4X7Link { struct Ts4X7Link *next; } Ts4X7Link;
typedef struct Ts4X7Param { char pad0[0x14]; void *name; u32 type; union { u32 i; float f; } v; } Ts4X7Param;
typedef struct Ts4X7Obj { char pad0[0x24]; Ts4X7Link params; } Ts4X7Obj;
int fn_88329868(void *name, u32 key);

#define TS4_X7_FIND(o, key, e, p) \
    for (e = (o)->params.next; e != head; e = e->next) { \
        p = e != 0 ? (Ts4X7Param *)((char *)e - 4) : 0; \
        if (fn_88329868(p->name, key) == 0) \
            goto found; \
    } \
    return 0x25;

int ts4_param_get_883F1DF8(Ts4X7Obj *o, u32 key, u32 *out)
{
    Ts4X7Link *e;
    Ts4X7Param *p;
    Ts4X7Link *head = &o->params;
    TS4_X7_FIND(o, key, e, p)
found:
    switch (p->type) {
    case 0:
    case 2:
        *out = p->v.i;
        break;
    case 1:
        *(float *)out = p->v.f;
        break;
    default:
        break;
    }
    return 0;
}

int ts4_param_set_883F1F10(Ts4X7Obj *o, u32 key, u32 *in)
{
    Ts4X7Link *e;
    Ts4X7Param *p;
    Ts4X7Link *head = &o->params;
    TS4_X7_FIND(o, key, e, p)
found:
    switch (p->type) {
    case 0:
    case 2:
        p->v.i = *in;
        break;
    case 1:
        p->v.f = *(float *)in;
        break;
    default:
        break;
    }
    return 0;
}
