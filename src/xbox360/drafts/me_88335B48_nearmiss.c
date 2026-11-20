/* 0x88335B48: If s->impl (+0x44) and its op at +0xa8 are set, tail-calls it with &impl->handle (+0x1c), args passed through; else 0x19. */
/* Near miss (agAH): 2 off: target puts addi r3 before mtctr (siblings 88335B18/88335B78 match with mtctr first); arity variants (0-3 args, int, u64) do not change the order. */
typedef int (*StreamOpFn)(void *handle, void *a, void *b);
typedef struct StreamImpl {
    char pad0[0x1c];
    char handle[0xa4 - 0x1c];
    StreamOpFn opA4;
    StreamOpFn opA8;
    StreamOpFn opAC;
} StreamImpl;
typedef struct Stream { char pad0[0x44]; StreamImpl *impl; } Stream;
int fn_88335B48(Stream *s, void *a, void *b)
{
    StreamImpl *impl = s->impl;
    if (impl != 0 && impl->opA8 != 0)
        return impl->opA8(impl->handle, a, b);
    return 0x19;
}
