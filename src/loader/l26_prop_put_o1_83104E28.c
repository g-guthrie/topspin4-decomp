/* Loader_DLL.xex 0x83104E28-0x83104F74, executable version 0.0.0.3. */

typedef struct ts4l_pg_desc {
    unsigned int flags;           /* 0x00 */
    unsigned int pad04;
    unsigned int offset;          /* 0x08 */
    unsigned int mask;            /* 0x0C */
    unsigned int pad10;
    int type;                     /* 0x14 */
    unsigned int pad18[3];
    int (*custom)(int, void *, void *); /* 0x24 */
} ts4l_pg_desc;

typedef struct ts4l_v3 { float x, y, z; } ts4l_v3;
typedef struct ts4l_v4 { unsigned int x, y, z, w; } ts4l_v4;

extern int fn_830FFBE8(void *dst, unsigned int v);

int ts4l_prop_put_83104E28(char *base, int a, ts4l_pg_desc *desc, void *c, int *v)
{
    unsigned int *p;

    if (base == 0 || desc == 0 || v == 0)
        return (int)0x80070057;
    p = (unsigned int *)(base + desc->offset);
    if (desc->custom != 0)
        return desc->custom(a, c, v);
    if (desc->flags & 1)
        return (int)0x80300001;
    if (v[0] != desc->type)
        return (int)0x80300008;
    switch (desc->type) {
    case 1:
        if (desc->mask != 0) {
            if (v[1] != 0)
                *p = *p | desc->mask;
            else
                *p = *p & ~desc->mask;
            break;
        }
    case 2:
    case 3:
    case 6:
        *p = v[1];
        break;
    case 4:
        *(float *)p = *(float *)&v[1];
        break;
    case 5:
        return fn_830FFBE8(p, v[1]);
    case 7:
    {
        volatile float *s = (volatile float *)(v + 1); float *d = (float *)p;
        float a = s[0]; float b = s[1]; float c = s[2];
        d[0] = a; d[1] = b; d[2] = c;
        break;
    }
    case 8:
    {
        ts4l_v4 *sv = (ts4l_v4 *)(v + 1);
        *(ts4l_v4 *)p = *sv;
        break;
    }
    default:
        return (int)0x80300001;
    }
    return 0;
}
