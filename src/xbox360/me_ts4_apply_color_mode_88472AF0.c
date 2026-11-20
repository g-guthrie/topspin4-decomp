/* 0x88472AF0: mode 1 clears the +0xD0 colour block, mode 2 sets it on with the value at +0xC0 and the source's RGB bytes (or black) */
/* Matched on /Oc (agAH). A switch with case 2 first puts the mode-1 call last, as in the target. */
typedef struct Src { char p[0x2c5]; unsigned char r, g, b; } Src;
typedef struct T { char p0[8]; Src *src; char p0c[0xb4]; int value; char pc4[0xc]; char light[0x10]; } T;
extern void ts4_if_set_u16_offa_88472A00(void *l, int on, int value, int r, int g, int b);
void fn_88472AF0(T *t, int mode)
{
    switch (mode) {
    case 2:
        if (t->src)
            ts4_if_set_u16_offa_88472A00(t->light, 1, t->value, t->src->r, t->src->g, t->src->b);
        else
            ts4_if_set_u16_offa_88472A00(t->light, 1, t->value, 0, 0, 0);
        break;
    case 1:
        ts4_if_set_u16_offa_88472A00(t->light, 0, 0, 0, 0, 0);
        break;
    }
}
