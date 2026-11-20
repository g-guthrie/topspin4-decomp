/* Swing_DLL.xex 0x88941FA0: copy name range and suffixed label into looked-up items
 * lookup fn_889416A8 by (keyA,keyB); sibling of 88941E90 */
typedef unsigned int u32;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)
void *memcpy(void *d, const void *s, unsigned int n);

typedef struct SrcRec {
    const char *nameFirst; /* +0x00 */
    const char *nameLast;  /* +0x04 */
    u32 pad08[13];
    const char *label;     /* +0x3C */
    u32 pad40[2];
    float value;           /* +0x48 */
    u32 keyA;              /* +0x4C */
    u32 keyB;              /* +0x50 */
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
extern DstItem *fn_889416A8(void *table, u32 keyA, u32 keyB);
extern void ts4_cw2_strcpy_cat_88165118(char *dst, const char *a, const char *b);

int fn_88941FA0(void *table, SrcRecVec *recs, const char *suffix)
{
    SrcRec *r;
    if (lbl_88D458D0 == 0)
        return 0;
    for (r = recs->first; r != recs->last; r++) {
        DstItem *d = fn_889416A8(table, r->keyA, r->keyB);
        if (d) {
            char label[256];
            ts4_cw2_strcpy_cat_88165118(label, r->label, suffix);
            memcpy(d->name, r->nameFirst, r->nameLast - r->nameFirst + 1);
            memcpy(d->label, label, (int)strlen(label) + 1);
            d->value = r->value;
        }
    }
    return 1;
}
