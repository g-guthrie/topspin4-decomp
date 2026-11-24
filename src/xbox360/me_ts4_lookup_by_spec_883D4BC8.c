/* 0x883D4BC8: parses a 'path;x;y' spec in place (the scan stops one character before ';' and the field starts two characters after it, as in the target), resolves the group (883D4A98 or 883D4998), converts x and y (88329A88, taken as atoi) and looks them up through bank slot 42; 0x25 on a bad spec or missing group */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Bank Bank;
typedef struct BankVt { void *f[42]; int (*lookup)(Bank *b, int a, int c, int *out); } BankVt;
struct Bank { BankVt *vt; };
typedef struct Grp { char pad[0x138]; Bank *bank; } Grp;
typedef struct Sys Sys;
int fn_88329A88(const char *s);
Grp *fn_883D4A98(Sys *s, char *path);
Grp *fn_883D4998(Sys *s, char *path);

int fn_883D4BC8(Sys *s, char *spec, int *id, Grp **out, unsigned char alt)
{
    char *p, *a, *b;
    Grp *g;
    int x, y;
    if (!spec || !id || !out)
        return 0x25;
    *id = 0;
    *out = 0;
    for (p = spec; *p && *p != ';' && p[1] != ';'; p++)
        ;
    if (!*p)
        return 0x25;
    *++p = 0;
    p += 2;
    a = p;
    for (; *p && *p != ';' && p[1] != ';'; p++)
        ;
    if (!*p)
        return 0x25;
    *++p = 0;
    b = p + 2;
    g = alt ? fn_883D4A98(s, spec) : fn_883D4998(s, spec);
    if (!g)
        return 0x25;
    x = fn_88329A88(a);
    y = fn_88329A88(b);
    if (g->bank->vt->lookup(g->bank, x, y, id))
        return 0;
    *out = g;
    return 0;
}
