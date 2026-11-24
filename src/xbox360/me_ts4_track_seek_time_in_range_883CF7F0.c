/* 0x883CF7F0: finds the next key time in [lo,hi] via fn_883CEBB8 (skip counter at +0x24), stores it at +0x18 and sets *found.
   LTCG only (agT): t kept in r7, found in r5 across the call; keeps fn_ name (callee of 0x883CF8A8). */
typedef struct Track { char pad[0x20]; float *times; int count; } Track;
typedef struct T { char pad[0x14]; Track *track; float time; char pad2[8]; int skip; } T;
int fn_883CEBB8(T *t, float lo, float hi, int *skip);
int fn_883CF7F0(T *t, float lo, float hi, unsigned char *found)
{
    int i;
    if (found)
        *found = 0;
    i = fn_883CEBB8(t, lo, hi, &t->skip);
    if (i >= 0) {
        t->time = t->track->times[i];
        if (found)
            *found = 1;
    }
    return 0;
}
