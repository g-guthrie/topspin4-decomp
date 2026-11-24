/* 0x88356BD8: 0x25 for a bad index or null out; otherwise writes the float of the index-th active slot (16 slots of 0x2C0 from +0x194) */
/* Matched on /Oc (agAH). Plain counted scan with the active count incremented after the index test. */
typedef struct Slot { void *active; char p[0x290]; float value; char p3[0x2c0 - 0x298]; } Slot;
typedef struct T { char p[0x194]; Slot slots[16]; } T;
int fn_88356BD8(T *t, int index, float *out)
{
    int n = 0, i;
    if (index < 0 || index >= 16 || !out)
        return 0x25;
    for (i = 0; i < 16; i++) {
        if (t->slots[i].active) {
            if (index == n) {
                *out = t->slots[i].value;
                return 0;
            }
            n++;
        }
    }
    return 0;
}
