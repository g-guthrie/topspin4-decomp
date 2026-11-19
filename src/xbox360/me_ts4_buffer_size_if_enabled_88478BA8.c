/* 0x88478BA8: When enabled (a char, sign-extended), writes out->count = 3n and out->bytes = 3n * 8 from n at +0x1c; otherwise zeroes both. Sibling of 88480FB8. */
/* Matched on /Oc (agAH). 3n read into a local and reused; else branch stores bytes then count. */
typedef struct SizeReq { unsigned int bytes; unsigned int count; } SizeReq;
typedef struct Mesh { char pad[0x1c]; unsigned int n; } Mesh;
void fn_88478BA8(Mesh *m, char enabled, SizeReq *out)
{
    if (enabled != 0) {
        unsigned int c = m->n * 3;
        out->count = c;
        out->bytes = c * 8;
    } else {
        out->bytes = 0;
        out->count = 0;
    }
}
