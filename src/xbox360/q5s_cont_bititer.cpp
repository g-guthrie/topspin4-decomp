/* q5s_cont: vector<bool>-style bit iterator (LTCG route, /Oc). Type: Ts4BitIt in include/ts4/containers.h. */
#include "include/ts4/ts4.h"

struct Ts4BitIter : Ts4BitIt {
    Ts4BitIter &operator+=(int n)
    {
        int o = bit + n;
        word += o / 32;
        if ((o %= 32) < 0) {
            bit = o + 32;
            --word;
        } else {
            bit = o;
        }
        return *this;
    }
    Ts4BitIter operator+(int n) const
    {
        Ts4BitIter tmp = *this;
        return tmp += n;
    }
};

extern "C" Ts4BitIter *ts4_bit_iter_add_8816FE78(Ts4BitIter *out, const Ts4BitIter *src, int n)
{
    *out = *src + n;
    return out;
}
