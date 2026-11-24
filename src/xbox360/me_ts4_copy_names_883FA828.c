/* 0x883FA828: copies name (+0x14, duplicated with fn_883299F0) and kind (+0x18) from s */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); duplicates +0x1C too when kind is 2, else copies it; returns 0x2C on allocation failure. */
typedef struct T { char pad[0x14]; char *name; int kind; char *extra; } T;
char *fn_883299F0(const char *s);
int ts4_copy_names_883FA828(T *d, const T *s)
{
    int k;
    d->name = 0;
    if (s->name) {
        d->name = fn_883299F0(s->name);
        if (!d->name)
            return 0x2c;
    }
    k = s->kind;
    d->kind = k;
    if (k == 2) {
        if (s->extra) {
            d->extra = fn_883299F0(s->extra);
            if (!d->extra)
                return 0x2c;
        }
    } else {
        d->extra = s->extra;
    }
    return 0;
}
