/* 0x88561E20: zeroes the first word of each 0x50-byte record at +0xFB4 (count +0x10) and of each 0x40-byte record at +0x50 (count +8). */
/* Matched on /Oc (agAB). Two plain indexed loops; counts re-read each pass. */
typedef struct A { int w; char p[0x4c]; } A;
typedef struct B { int w; char p[0x3c]; } B;
typedef struct T { char p[8]; int nb; char pc[4]; int na; char p14[0x50 - 0x14]; B b[4]; char pr[0xfb4 - 0x150]; A a[4]; } T;
void fn_88561E20(T *t)
{
    int i;
    for (i = 0; i < t->na; i++)
        t->a[i].w = 0;
    for (i = 0; i < t->nb; i++)
        t->b[i].w = 0;
}
