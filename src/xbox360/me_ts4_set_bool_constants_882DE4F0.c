/* 0x882DE4F0: Turns count*4 int flags into 0.0/1.0 floats in as_float, then copies the raw values into the constant store (vt slot 3 data) at first*16. Returns 0. */
/* Matched on /O1 (agAH). A precomputed n with i != n gives the bdnz loop. */
void *memcpy(void *d, const void *s, unsigned int n);
typedef struct Consts Consts;
typedef struct ConstsVt { void *s[3]; char *(*data)(Consts *); } ConstsVt;
struct Consts { ConstsVt *vt; };
int fn_882DE4F0(Consts *c, unsigned int first, const int *values, float *as_float, unsigned int count)
{
    unsigned int n = count * 4;
    unsigned int i;
    for (i = 0; i != n; i++)
        as_float[i] = (float)(values[i] != 0);
    memcpy(c->vt->data(c) + first * 16, values, count * 16);
    return 0;
}
