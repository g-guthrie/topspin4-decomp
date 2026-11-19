/* 0x889A4930: if the id at lbl_88D458E8->+0x3C->+0x2D0 is 0x054AB17F or 0x582B3086, returns ts4_grid_valid_889A0478(t + 0xBC); else 1. */
/* Near-miss on /Oc (agAB): 2 instructions off at +0x10. The target reuses r11 down the pointer chain; this source puts the middle pointer in r8. */
typedef struct C { char p[0x2d0]; unsigned int id; } C;
typedef struct B { char p[0x3c]; C *c; } B;
extern B *lbl_88D458E8;
typedef struct T { char p[0xbc]; char grid[4]; } T;
int ts4_grid_valid_889A0478(void *g);
int fn_889A4930(T *t)
{
    unsigned int id = lbl_88D458E8->c->id;
    if (id == 0x054AB17F || id == 0x582B3086)
        return ts4_grid_valid_889A0478(t->grid);
    return 1;
}
