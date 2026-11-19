/* 0x883C7278: when flag 0x20 at +0x64 is set, queries the owner chain object (+0x28->+0x30->+0x38) via fn_883DBBA0 and returns its error or out value, else 0. */
/* Matched on /O1 and /Os (agY): short flag field, (unsigned char)(((unsigned)f >> 5) & 1) gives the lhz extrwi. */
typedef struct C { char pad[0x38]; void *obj; } C;
typedef struct B { char pad[0x30]; C *c; } B;
typedef struct T { char pad[0x28]; B *b; char pad2[0x64 - 0x2C]; short flags; } T;
int fn_883DBBA0(void *obj, T *t, int *out);
int fn_883C7278(T *t)
{
    void *obj;
    if ((unsigned char)(((unsigned)t->flags >> 5) & 1)) {
        obj = t->b->c->obj;
        if (obj) { int v = 0; int r = fn_883DBBA0(obj, t, &v); if (r) return r; return v; }
    }
    return 0;
}
