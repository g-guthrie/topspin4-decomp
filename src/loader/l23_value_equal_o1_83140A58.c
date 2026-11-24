/* Loader_DLL.xex 0x83140A58-0x83140BF4, executable version 0.0.0.3. */

typedef struct ts4l_val ts4l_val;

typedef struct ts4l_val_ops {
    unsigned char pad[0x18];
    int (*equal)(void *a, void *b, int flags);
} ts4l_val_ops;

struct ts4l_val {
    int type;                      /* 0x00 */
    union {
        unsigned int u;
        float f[4];
        const unsigned short *w;
        void *p;
    } d;                           /* 0x04 */
};

typedef struct ts4l_obj_val {
    int type;
    void *p;
    ts4l_val_ops *ops;
} ts4l_obj_val;

extern int fn_833E4108(const unsigned short *a, const unsigned short *b);

int ts4l_value_equal_83140A58(ts4l_val *a, ts4l_val *b)
{
    if (a->type != b->type)
        return 0;
    switch (a->type) {
    case 1:
    case 2:
    case 3:
    case 6:
        if (a->d.u == b->d.u)
            return 1;
        break;
    case 4:
        if (a->d.f[0] == b->d.f[0])
            return 1;
        break;
    case 5:
        if (a->d.w == 0 && b->d.w == 0)
            return 1;
        if (a->d.w == 0 && b->d.w != 0 && *b->d.w == 0)
            return 1;
        if (b->d.w == 0 && a->d.w != 0 && *a->d.w == 0)
            return 1;
        if (a->d.w == 0 || b->d.w == 0)
            return 0;
        return fn_833E4108(a->d.w, b->d.w) == 0;
    case 7:
        if (a->d.f[0] == b->d.f[0] && a->d.f[1] == b->d.f[1] && a->d.f[2] == b->d.f[2])
            return 1;
        break;
    case 8:
        if (a->d.f[0] == b->d.f[0] && a->d.f[1] == b->d.f[1] && a->d.f[2] == b->d.f[2] && a->d.f[3] == b->d.f[3])
            return 1;
        break;
    case 10: {
        ts4l_obj_val *oa = (ts4l_obj_val *)a;
        ts4l_obj_val *ob = (ts4l_obj_val *)b;

        if (oa->ops == 0 || oa->ops->equal == 0)
            return 0;
        return oa->ops->equal(oa->p, ob->p, 0);
    }
    default:
        break;
    }
    return 0;
}
