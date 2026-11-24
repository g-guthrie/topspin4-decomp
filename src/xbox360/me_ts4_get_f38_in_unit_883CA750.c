/* 0x883CA750: writes the float at +0x38 to *out converted by unit (1: x4, 2: x48, 3: x24, else unchanged); 0x25 when out is null. */
/* Matched on /O1 (agAF). Constants written as literals (the labels hold 4.0, 48.0, 24.0); a switch on a local v with default return 0; sibling 0x883DF940. */
typedef struct T { char p[0x38]; float v; } T;
int fn_883CA750(T *t, float *out, int unit)
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
