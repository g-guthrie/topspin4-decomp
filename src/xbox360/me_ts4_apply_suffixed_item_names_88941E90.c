/* Swing_DLL.xex 0x88941E90: copy suffixed name/label strings into looked-up items
 * lookup fn_889415D0 by (keyA,keyB); strlen intrinsic converted to int */
typedef unsigned int u32;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
void *memcpy(void *d, const void *s, unsigned int n);

typedef struct SrcRec {
    const char *name;     /* +0x00 */
    u32 pad04[14];
    const char *label;    /* +0x3C */
    u32 pad40[2];
    float value;          /* +0x48 */
    u32 keyA;             /* +0x4C */
    u32 keyB;             /* +0x50 */
} SrcRec;

typedef struct SrcRecVec {
    SrcRec *first;
    SrcRec *last;
} SrcRecVec;

typedef struct DstItem {
    char name[0x40];
    char label[0x40];
    float value;
} DstItem;

extern u32 lbl_88D458D0;
extern DstItem *fn_889415D0(void *table, u32 keyA, u32 keyB);
extern void ts4_cw2_strcpy_cat_88165118(char *dst, const char *a, const char *b);

int fn_88941E90(void *table, SrcRecVec *recs, const char *suffix)
{
    SrcRec *r;
    if (lbl_88D458D0 == 0)
        return 0;
    for (r = recs->first; r != recs->last; r++) {
        DstItem *d = fn_889415D0(table, r->keyA, r->keyB);
        if (d) {
            char name[256];
            char label[256];
            ts4_cw2_strcpy_cat_88165118(name, r->name, suffix);
            ts4_cw2_strcpy_cat_88165118(label, r->label, suffix);
            memcpy(d->name, name, (int)strlen(name) + 1);
            memcpy(d->label, label, (int)strlen(label) + 1);
            d->value = r->value;
        }
    }
    return 1;
}
