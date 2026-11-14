/* SM2: virtual-call thunks that redirect to the owner object stored at this-8 and append a global argument. */
extern int lbl_88D26FE4;

typedef int (*ts4_vfn3)(void *self, int a, int b, int g);
typedef int (*ts4_vfn4)(void *self, int a, int b, int c, int g);
typedef int (*ts4_vfn5)(void *self, int a, int b, int c, int d, int g);

#define VTHUNK3(NAME, SLOT) \
    int NAME(char *self, int a, int b) \
    { \
        char *o = *(char **)(self - 8); \
        return ((ts4_vfn3)(*(void ***)o)[SLOT])(o, a, b, lbl_88D26FE4); \
    }
#define VTHUNK4(NAME, SLOT) \
    int NAME(char *self, int a, int b, int c) \
    { \
        char *o = *(char **)(self - 8); \
        return ((ts4_vfn4)(*(void ***)o)[SLOT])(o, a, b, c, lbl_88D26FE4); \
    }
#define VTHUNK5(NAME, SLOT) \
    int NAME(char *self, int a, int b, int c, int d) \
    { \
        char *o = *(char **)(self - 8); \
        return ((ts4_vfn5)(*(void ***)o)[SLOT])(o, a, b, c, d, lbl_88D26FE4); \
    }
VTHUNK3(ts4_vthunk_slot4_884EF150, 4)
VTHUNK3(ts4_vthunk_slot7_884EF1A8, 7)
VTHUNK3(ts4_vthunk_slot10_884EF208, 10)
VTHUNK3(ts4_vthunk_slot12_884EF110, 12)
VTHUNK3(ts4_vthunk_slot3_884EF130, 3)
VTHUNK4(ts4_vthunk_slot8_884EF1C8, 8)
VTHUNK4(ts4_vthunk_slot11_884EF228, 11)
VTHUNK4(ts4_vthunk_slot13_884EF0F0, 13)
VTHUNK4(ts4_vthunk_slot1_884EF0B0, 1)
VTHUNK4(ts4_vthunk_slot2_884EF0D0, 2)
VTHUNK5(ts4_vthunk_slot9_884EF1E8, 9)
