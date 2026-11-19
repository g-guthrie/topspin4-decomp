/* 0x883CEBB8: index of the (*skip)-th key time of t->track inside [lo,hi] (searched backwards when lo >= hi), decrementing
   *skip for each earlier hit; -1 when none. Matched plain /O1 (agT); keeps fn_ name (callee of 0x883CF7F0). */
typedef struct Track { char pad[0x20]; float *times; int count; } Track;
typedef struct T { char pad[0x14]; Track *track; } T;
int fn_883CEBB8(T *t, float lo, float hi, int *skip)
{
    int i;
    if (lo < hi) {
        for (i = 0; i < t->track->count; i++) {
            float v = t->track->times[i];
            if (v >= lo && v <= hi) {
                if (*skip == 0)
                    return i;
                (*skip)--;
            }
        }
    } else {
        for (i = t->track->count - 1; i >= 0; i--) {
            float v = t->track->times[i];
            if (v <= lo && v >= hi) {
                if (*skip == 0)
                    return i;
                (*skip)--;
            }
        }
    }
    return -1;
}
