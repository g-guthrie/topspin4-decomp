/* 0x88275748: copies the 3-float value of the key before the first key (from index 1) whose time is not below x (16-byte keys at +0x4C) into out. */
/* Matched on /Oc (agAB). Sibling of 882757A0: start at i = 1 and copy keys[i - 1].v. */
typedef struct K { float t; float v[3]; } K;
typedef struct T { char p[0x4c]; K *keys; } T;
void fn_88275748(T *t, float x, float *out)
{
    int i = 1;
    float *v;
    while (t->keys[i].t < x)
        i++;
    v = t->keys[i - 1].v;
    out[0] = v[0];
    out[1] = v[1];
    out[2] = v[2];
}
