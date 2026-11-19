/* Swing_DLL.xex 0x887FD7A8 near-miss (2 off, /Oc): both lwzx come out base,index instead of index,base. */
typedef struct Elem12 { unsigned int a, b, c; } Elem12;
typedef struct Elem12Vec { Elem12 *first; Elem12 *last; Elem12 *end; } Elem12Vec;
typedef struct Src { int x; } Src;
typedef struct SrcVec { Src **first; Src **last; Src **end; } SrcVec;
typedef struct Bank {
    char p[0x2c]; SrcVec srcs; Elem12Vec out;
} Bank;
void ts4_vec28_move_tail_88161540(Elem12Vec *v);
void fn_8892DC70(Src *s, Elem12Vec *out);
void fn_887FD688(Bank *b);
void ts4_destroy_owned_object(void *p);

void fn_887FD7A8(Bank *b)
{
    int n = b->srcs.last - b->srcs.first;
    Elem12Vec tmp;
    unsigned int i;
    tmp.first = 0;
    tmp.last = 0;
    tmp.end = 0;
    for (i = 0; i < (unsigned int)n; ++i) {
        if (b->srcs.first[i] != 0) {
            ts4_vec28_move_tail_88161540(&tmp);
            fn_8892DC70(b->srcs.first[i], &tmp);
            {
                Elem12 e = *tmp.first;
                b->out.first[i] = e;
            }
        }
    }
    fn_887FD688(b);
    if (tmp.first)
        ts4_destroy_owned_object(tmp.first);
}
