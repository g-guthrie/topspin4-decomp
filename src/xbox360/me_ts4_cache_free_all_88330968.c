/* Swing_DLL.xex 0x88330968: frees the three 128-entry buffer tables (+0x20C, +0x830, +0x40C) through fn_88315F10 on the global heap
 * (file lbl_880292F8, lines 0x81/0x88/0x8F) and zeroes the size tables (+0xC, +0x630). agAE: /Oc. */
typedef struct Globals { char pad[4]; void *heap; } Globals;
extern Globals *lbl_88B3302C;
extern const char lbl_880292F8[];
void fn_88315F10(void *heap, void *buf, const char *file, int line);
typedef struct Cache {
    char pad[0xc]; unsigned int sizeA[128]; void *bufA[128]; void *bufC[128]; char pad60c[0x630 - 0x60c];
    unsigned int sizeB[128]; void *bufB[128];
} Cache;
int fn_88330968(Cache *c)
{
    int i;
    for (i = 0; i < 128; i++) {
        if (c->bufA[i]) {
            fn_88315F10(lbl_88B3302C->heap, c->bufA[i], lbl_880292F8, 0x81);
            c->bufA[i] = 0;
        }
        c->sizeA[i] = 0;
        if (c->bufB[i]) {
            fn_88315F10(lbl_88B3302C->heap, c->bufB[i], lbl_880292F8, 0x88);
            c->bufB[i] = 0;
        }
        c->sizeB[i] = 0;
        if (c->bufC[i]) {
            fn_88315F10(lbl_88B3302C->heap, c->bufC[i], lbl_880292F8, 0x8f);
            c->bufC[i] = 0;
        }
    }
    return 0;
}
