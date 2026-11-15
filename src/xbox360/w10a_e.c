/* W10A: slot table init (Swing_DLL.xex 0x886A02B0); 20 elements of 0x30 bytes cleared by the counted loop. Plain route, /Oc. */
typedef struct A5E { unsigned w0, w4, w8, wc, w10; unsigned char pad[8]; unsigned char b1c, b1d; unsigned char pad2[0x30 - 0x1e]; } A5E;
typedef struct A5P74 { unsigned char pad[0x38c]; unsigned w38c; unsigned w390; unsigned w394; } A5P74;
typedef struct A5P18 { unsigned char pad[0x74]; A5P74 *p74; } A5P18;
typedef struct A5O {
    unsigned char pad0[4]; unsigned char b4, b5; unsigned char pad6[2];
    unsigned w8, wc, w10, w14; A5P18 *p18; unsigned char pad1c[4]; int *w20;
    unsigned char sub24[0x6c - 0x24];
    A5E el[20];
} A5O;
extern void ts4_loop_call_seq_u32_off20_8890F158(void *dst, char *n);
void ts4_slot_table_init_886A02B0(A5O *s, int *src)
{
    int i;
    s->w20 = src;
    s->b5 = 0;
    s->b4 = 1;
    s->w10 = 0;
    s->w14 = 0;
    for (i = 0; i < 20; i++) {
        s->el[i].b1c = 0;
        s->el[i].b1d = 0;
        s->el[i].w4 = 0;
        s->el[i].w0 = 0;
        s->el[i].w10 = 0;
    }
    { int *h = src + 2; ts4_loop_call_seq_u32_off20_8890F158(s->sub24, ((char *)h - *h)); }
    { unsigned *p = &s->w8; *p = s->p18->p74->w38c; }
    s->wc = s->p18->p74->w394;
}
