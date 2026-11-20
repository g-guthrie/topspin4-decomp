/* 0x8837E640: returns 0x4F when any of the n u16 rows at +0x28 has a nonzero element in columns 1..m-1; 0 otherwise or when m is 1. */
/* Matched on /Oc (agAF). Count-guarded pointer walk (agAD fourth run): j = 1; if (j < m) { p = rows[i] + 1; for (; j < m; j++, p++) ... }. */
typedef struct T { char p[0x28]; unsigned short *rows[1]; } T;
int fn_8837E640(T *t, int n, int m)
{
    int i, j;
    if (m == 1)
        return 0;
    for (i = 0; i < n; i++) {
        j = 1;
        if (j < m) {
            unsigned short *p = t->rows[i] + 1;
            for (; j < m; j++, p++)
                if (*p)
                    return 0x4f;
        }
    }
    return 0;
}
