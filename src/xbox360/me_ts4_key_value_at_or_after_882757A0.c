/* 0x882757A0: copies the 3-float value of the first 16-byte key (array at +0x4C) whose time is not below x into out. */
/* Matched on /Oc (agAB). while (t->keys[i].t < x) i++; through the chain, then copy through a float pointer to keys[i].v. */
typedef struct K { float t; float v[3]; } K;
typedef struct T { char p[0x4c]; K *keys; } T;
void fn_882757A0(T *t, float x, float *out)
{
    int i = 0;
    float *v;
    while (t->keys[i].t < x)
        i++;
    v = t->keys[i].v;
    out[0] = v[0];
    out[1] = v[1];
    out[2] = v[2];
}
