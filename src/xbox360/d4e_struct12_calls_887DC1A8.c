/* Swing_DLL.xex 0x887DC1A8-0x887DC338, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

/* 12-byte id passed by value (r4 holds the first two words, r5 the third). */
typedef struct Ts4Id12 {
    u32 a;
    u32 b;
    u32 c;
} Ts4Id12;

extern void fn_887DBFD0(void *out, Ts4Id12 id, int mode, int flag);

/* Apply four consecutive ids (mode -1), then the id at +0x250 (mode 0). */
void ts4_apply_id_table_887DC2D0(char *self)
{
    Ts4Id12 scratch_a;
    Ts4Id12 scratch_b;
    Ts4Id12 *id = (Ts4Id12 *)(self + 0x28c);
    int remaining = 4;
    do {
        fn_887DBFD0(&scratch_a, *id, -1, 1);
        remaining--;
        id++;
    } while (remaining != 0);
    fn_887DBFD0(&scratch_b, *(Ts4Id12 *)(self + 0x250), 0, 1);
}

/* Apply four pairs of ids (mode 0) from the table around +0x1c0/+0x1f0. */
void ts4_apply_id_pairs_887DC338(char *self)
{
    Ts4Id12 scratch_a;
    Ts4Id12 scratch_b;
    Ts4Id12 *id = (Ts4Id12 *)(self + 0x1f0);
    int remaining = 4;
    do {
        fn_887DBFD0(&scratch_a, id[-4], 0, 1);
        fn_887DBFD0(&scratch_b, *id, 0, 1);
        remaining--;
        id++;
    } while (remaining != 0);
}

/* Apply the four ids with mode -1 when the flag is clear, then the id at +0x250 with -1 when it is set. */
void ts4_apply_id_table_flag_887DD098(char *self, u8 flag)
{
    Ts4Id12 scratch_a;
    Ts4Id12 scratch_b;
    Ts4Id12 *id = (Ts4Id12 *)(self + 0x28c);
    int remaining = 4;
    do {
        fn_887DBFD0(&scratch_a, *id, flag ? 0 : -1, 0);
        remaining--;
        id++;
    } while (remaining != 0);
    fn_887DBFD0(&scratch_b, *(Ts4Id12 *)(self + 0x250), flag ? -1 : 0, 0);
}
