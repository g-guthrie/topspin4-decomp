/* 0x882DD880: recursive child-buffer layout (assigns each node a base pointer, advances by count*size*elemsize). */
/* Near miss /O1 (agV): 1 instruction scheduled differently (li r10,1 hoisted above the lwzx/lhz/cmplwi); ?:, helpers and if/else variants tried. */
typedef struct Hdr { char pad[0xa]; unsigned short n; } Hdr;
typedef struct Fmt { char pad[8]; unsigned short n; } Fmt;
typedef struct Node {
    char pad0[8];
    unsigned short wide;
    char pad1[0x18 - 0xa];
    void *hdr;
    char pad2[0x20 - 0x1c];
    unsigned int *base;
    char pad3[0x2c - 0x24];
    int count;
    char pad4[0x38 - 0x30];
    struct Node **kids;
} Node;

int fn_882DD880(Node *t, unsigned int *p)
{
    unsigned int i;
    t->base = p;
    for (i = 0; i < ((Hdr *)t->hdr)->n; i++) {
        int m;
        fn_882DD880(t->kids[i], p);
        m = 1; if (t->kids[i]->wide) m = 4;
        p += ((Fmt *)t->kids[i]->hdr)->n * t->kids[i]->count * m;
    }
    return 0;
}
