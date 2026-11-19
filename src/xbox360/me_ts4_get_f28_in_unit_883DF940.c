/* 0x883DF940: writes the float at +0x28 to *out converted by unit (1: x4, 2: x48, 3: x24, else unchanged); 0x25 when out is null. */
/* Matched on /O1 (agAF). Same source as 0x883CA750 with the field at +0x28. */
typedef struct T { char p[0x28]; float v; } T;
int fn_883DF940(T *t, float *out, int unit)
{
    float v;
    if (!out)
        return 0x25;
    v = t->v;
    *out = v;
    switch (unit) {
    case 1:
        v *= 4.0f;
        break;
    case 2:
        v *= 48.0f;
        break;
    case 3:
        v *= 24.0f;
        break;
    default:
        return 0;
    }
    *out = v;
    return 0;
}
