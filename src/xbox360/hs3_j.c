/* HS3 hand-matched: small object glue (0x887..0x88A). */
struct HS3VT2 {
    char pad[0x28];
    void (*slot28)(void *self, void *a, unsigned b, unsigned c, unsigned d, unsigned e);
    void (*slot2c)(void *self, void *a);
};
struct HS3Obj2 { struct HS3VT2 *vt; };

/* Invoke virtual slot 0x28 with the dereferenced argument, then virtual slot 0x2c. */
void ts4_obj_vcall_28_then_2c_88778E88(struct HS3Obj2 *self, void *a, unsigned *b, unsigned c)
{
    self->vt->slot28(self, a, *b, 0, 0, c);
    self->vt->slot2c(self, a);
}

struct HS3VTx { void (*fn[32])(void *self); };
struct HS3Objx { struct HS3VTx *vt; };

/* Return the number of 4-byte items between +0x48 and +0x4c after calling two virtual hooks on the sub-object at +0x24. */
int ts4_obj_sub_vcall_count_887E9778(char *self)
{
    struct HS3Objx *sub = (struct HS3Objx *)(self + 0x24);
    int n;
    sub->vt->fn[1](sub);
    n = (*(int *)(self + 0x4c) - *(int *)(self + 0x48)) >> 2;
    sub->vt->fn[2](sub);
    return n;
}

struct HS3VTsvc {
    char pad[0x30];
    unsigned char (*slot30)(void *self);
    char pad2[0x4c - 0x34];
    char *(*slot4c)(void *self, unsigned arg);
};
struct HS3Svc { struct HS3VTsvc *vt; };
struct HS3FlagHolder { char pad[0x1c]; unsigned char b1c; };
struct HS3Svc *ts4_find_service(unsigned id);

/* Store a flag, then mirror it into byte +0x787 of the service's state if the service is ready. */
void ts4_set_flag_mirror_to_service_787_88865508(struct HS3FlagHolder *self, unsigned char v)
{
    struct HS3Svc *svc;
    self->b1c = v;
    svc = ts4_find_service(0x8c5a4922);
    if (svc->vt->slot30(svc))
        svc->vt->slot4c(svc, 0)[0x787] = v;
}

/* Store a flag, then mirror it into byte +0x786 of the service's state if the service is ready. */
void ts4_set_flag_mirror_to_service_786_88865588(struct HS3FlagHolder *self, unsigned char v)
{
    struct HS3Svc *svc;
    self->b1c = v;
    svc = ts4_find_service(0x8c5a4922);
    if (svc->vt->slot30(svc))
        svc->vt->slot4c(svc, 0)[0x786] = v;
}
