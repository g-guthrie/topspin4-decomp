/* 0x883C7278 near miss (1 off on /O1 or /Os): target tests flag 0x20 at +0x64 with extrwi. 1,26; every form here gives rlwinm. 0,26,26. */
typedef struct C { char pad[0x38]; void *obj; } C;
typedef struct B { char pad[0x30]; C *c; } B;
typedef struct T { char pad[0x28]; B *b; char pad2[0x64 - 0x2C]; unsigned short flags; } T;
int fn_883DBBA0(void *obj, T *t, int *out);
int ts4_query_child_value_883C7278(T *t)
{
    void *obj;
    if ((t->flags >> 5) & 1) {
        obj = t->b->c->obj;
        if (obj) {
            int v = 0;
            int r = fn_883DBBA0(obj, t, &v);
            if (r)
                return r;
            return v;
        }
    }
    return 0;
}
