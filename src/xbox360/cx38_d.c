/* CW38 part d: operand-order-padded helpers in 0x887B0000-0x887D0000. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int cx38_uptr;
#else
typedef unsigned long cx38_uptr;
#endif
typedef struct E1F8Arg { char pad[0x2c]; char *p2c; } E1F8Arg;

/* 0x887CE1F8: unlock check on the player-creator context. */
void ts4_check_unlock_887CE1F8(u32 *out, E1F8Arg *a, u32 *res)
{
    int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0;
    char *c = a->p2c;
    char *t = c + 0x35c;
    char *b = (char *)(*(int *)t + (cx38_uptr)t);
    (void)op1_pad0; (void)op1_pad1; (void)op1_pad2;
    if (*(u32 *)(b + 0x54) >= 10 && *(u32 *)(c + 0x338) >= 14 && c[0x370] == 1) {
        res[8] = *(u32 *)(c + 0x338);
        *out = 0x8054adbaU;
    } else {
        *out = 0;
    }
}

/* 0x887CEA80: self-relative table row, then 0xb4-stride record. */
char *ts4_table_record_887CEA80(char *self, int idx)
{
    int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0, op1_pad3 = 0;
    char *h = *(char **)(self + 0x104) + 0x220;
    char *t = *(char **)(self + 0xa8) + 0x1c0;
    char *e = h + (idx * 16 + *(int *)h);
    int off = *(int *)e;
    int k = *(int *)(e + off);
    (void)op1_pad0; (void)op1_pad1; (void)op1_pad2; (void)op1_pad3;
    return t + k * 0xb4 + *(int *)t;
}
