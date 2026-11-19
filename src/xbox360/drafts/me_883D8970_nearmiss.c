typedef struct Link { struct Link *next; } Link;
typedef struct Var { int f0; Link link; char pad[0xc]; const char *name; unsigned int type; union { int i; float f; } v; } Var;
typedef struct T { char pad[0x40]; Link head; } T;
int fn_88329868(const char *a, const char *b);
int fn_883D8970(T *t, const char *name, void *out)
{
    Link *n;
    if (out) {
        for (n = t->head.next; n != &t->head; n = n->next) {
            Var *v = n ? (Var *)((char *)n - 4) : 0;
            if (fn_88329868(v->name, name) == 0) {
                switch (v->type) {
                case 0:
                case 2:
                    *(int *)out = v->v.i;
                    break;
                case 1:
                    *(float *)out = v->v.f;
                    break;
                }
                return 0;
            }
        }
    }
    return 0x25;
}
