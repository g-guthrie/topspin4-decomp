/* 0x88335B18: If s->impl (+0x44) and its op at +0xa4 are set, tail-calls that op with &impl->handle (+0x1c) and the remaining args passed through; otherwise returns 0x19. */
/* Matched on /Oc (agAH). Impl pointer read into a local; both null checks joined with &&. The op arity is not visible in the body (args pass through in r4/r5), so two pointer args are assumed. */
typedef int (*StreamOpFn)(void *handle, void *a, void *b);
typedef struct StreamImpl {
    char pad0[0x1c];
    char handle[0xa4 - 0x1c];
    StreamOpFn opA4;
    StreamOpFn opA8;
    StreamOpFn opAC;
} StreamImpl;
typedef struct Stream { char pad0[0x44]; StreamImpl *impl; } Stream;
int fn_88335B18(Stream *s, void *a, void *b)
{
    StreamImpl *impl = s->impl;
    if (impl != 0 && impl->opA4 != 0)
        return impl->opA4(impl->handle, a, b);
    return 0x19;
}
