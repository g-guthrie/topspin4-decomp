
typedef struct Mtx { float m[12]; float t[3]; float w; } Mtx;
typedef struct Node { char pad[0xe0]; char xf[4]; } Node;
typedef struct O { char pad[0x10]; float scale; } O;
extern void fn_8841C7D8(void *xf, Mtx *out);
extern void *memcpy(void *d, const void *s, unsigned int n);
void fn_8887A5B8(O *o, Node *n, Mtx *out)
{
    if (n) {
        Mtx m;
        fn_8841C7D8(n->xf, &m);
        m.t[0] = o->scale * m.t[0];
        m.t[1] = o->scale * m.t[1];
        m.t[2] = o->scale * m.t[2];
        memcpy(out, &m, 0x40);
    }
}
