/* Swing_DLL.xex 0x887FD7A8 (/Oc): for every non-null source in the bank's source vector (+0x2C),
 * rebuild a scratch vector of 12-byte records through fn_8892DC70 and copy its first record to
 * out[i] (+0x38); then refresh the bank (fn_887FD688) and free the scratch storage.
 * Matching note: the count must come from the inline accessor size(); the same
 * `last - first` written in the body loads the source elements as lwzx base,index (2 off). */
struct Ts4Rec12 { unsigned int a, b, c; };
struct Ts4Rec12Vec { Ts4Rec12 *first; Ts4Rec12 *last; Ts4Rec12 *end; };
struct Ts4BankSource { int x; };
struct Ts4BankSourceVec {
    Ts4BankSource **first;
    Ts4BankSource **last;
    Ts4BankSource **end;
    unsigned int size() const { return last - first; }
};
struct Ts4SourceBank;

extern "C" void ts4_vec28_move_tail_88161540(Ts4Rec12Vec *v);
extern "C" void fn_8892DC70(Ts4BankSource *s, Ts4Rec12Vec *out);
extern "C" void fn_887FD688(Ts4SourceBank *b);
extern "C" void ts4_destroy_owned_object(void *p);

struct Ts4SourceBank {
    char pad00[0x2C];
    Ts4BankSourceVec sources;  /* +0x2C */
    Ts4Rec12Vec out;           /* +0x38 */
    void rebuild();
};

void Ts4SourceBank::rebuild()
{
    int n = sources.size();
    Ts4Rec12Vec tmp;
    unsigned int i;
    tmp.first = 0;
    tmp.last = 0;
    tmp.end = 0;
    for (i = 0; i < (unsigned int)n; ++i) {
        if (sources.first[i] != 0) {
            ts4_vec28_move_tail_88161540(&tmp);
            fn_8892DC70(sources.first[i], &tmp);
            {
                Ts4Rec12 e = *tmp.first;
                out.first[i] = e;
            }
        }
    }
    fn_887FD688(this);
    if (tmp.first)
        ts4_destroy_owned_object(tmp.first);
}
