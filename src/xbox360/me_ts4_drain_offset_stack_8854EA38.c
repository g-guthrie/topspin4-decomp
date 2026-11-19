/* 0x8854EA38: While the offset stack at +4 is non-empty, calls fn_8854E778 on the node at base + top offset - 0x80 with the two pass-through arguments (the callee pops the stack). */
/* Matched on /Oc (agAH). Stack addressed through a local pointer to the embedded struct. */
typedef struct OffsetStack { int *items; int count; } OffsetStack;
typedef struct Walker { char *base; OffsetStack stack; } Walker;
void fn_8854E778(Walker *w, char *node, void *a, void *b);
void fn_8854EA38(Walker *w, void *a, void *b)
{
    while (w->stack.count != 0) {
        OffsetStack *st = &w->stack;
        fn_8854E778(w, w->base + st->items[st->count - 1] - 0x80, a, b);
    }
}
