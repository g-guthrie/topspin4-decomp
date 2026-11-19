/* 0x883D1B80: reads a count of (index, int) pairs into a 33-entry stat table (unknown indices skipped with 88319C40, negative index 0x13) and copies selected entries and sums into the output record */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Out {
    char pad0[8];
    int total;
    int pc;
    int s0;
    int p14;
    int s10_11;
    int p1c;
    int s7;
    int p24;
    int s8a;
    int p2c;
    int s8b;
    int p34;
    int s9;
    int p3c;
    int s6a;
    int p44;
    int s6b;
    int p4c;
    int s5a;
    int p54;
    int s5b;
} Out;
int fn_883194F0(void *stream, void *dst, unsigned int size, unsigned int count, int a);
int fn_88319C40(void *stream, unsigned int size, unsigned int count);

int fn_883D1B80(void *stream, Out *o)
{
    int n = 0, i, idx, r;
    r = fn_883194F0(stream, &n, 4, 1, 0);
    if (r)
        return r;
    {
    int s[33] = { 0 };
    for (i = 0; i < n; i++) {
        r = fn_883194F0(stream, &idx, 4, 1, 0);
        if (r)
            return r;
        if (idx < 0)
            return 0x13;
        if (idx < 0x21) {
            r = fn_883194F0(stream, &s[idx], 4, 1, 0);
            if (r)
                return r;
        } else {
            r = fn_88319C40(stream, 4, 1);
            if (r)
                return r;
        }
    }
    o->s0 = s[0];
    o->s8a = s[8];
    o->s7 = s[7];
    o->s10_11 = s[10] + s[11];
    o->s8b = s[8];
    o->s5a = s[5];
    o->s5b = s[5];
    o->s9 = s[9];
    o->s6a = s[6];
    o->s6b = s[6];
    o->total = s[19] + s[20] + s[22] + s[23] + s[24] + s[25] + s[27];
    }
    return 0;
}
