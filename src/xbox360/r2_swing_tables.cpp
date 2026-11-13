/*
 * R2 (gameplay core): small table objects owned by swing module state.
 */
extern "C" {
extern void *lbl_88D45B38;   /* shared allocator heap (placeholder name) */
void *fn_88613268(void *heap, int size, int align, int flags, int tag);
void ts4_noop_881B3360(void);
}

inline void *operator new(unsigned, void *heap, int size, int align, int flags, int tag)
{ return fn_88613268(heap, size, align, flags, tag); }

/* Five-entry handler array (function pointers). */
struct R2HandlerArray { void *entry[5]; };

/* Five-entry key array, zero-initialised on construction. */
struct R2KeyArray {
    unsigned int key[5];
    R2KeyArray() { key[0] = 0; key[1] = 0; key[2] = 0; key[3] = 0; key[4] = 0; }
};

struct R2HandlerTable {
    unsigned char pad00[4];
    void **handlers;           /* +0x04 */
    int handler_count;         /* +0x08 */
    unsigned int *keys;        /* +0x0c */
    int key_count;             /* +0x10 */
};

extern "C" {
/* Swing_DLL.xex 0x886A0548: build the five-entry handler/key table (all handlers no-op, keys are name hashes). */
void ts4_r2_handler_table_init_886A0548(R2HandlerTable *self)
{
    self->handlers = (void **)fn_88613268(lbl_88D45B38, 0x14, 4, 0, 2);
    self->handler_count = 5;
    self->keys = (unsigned int *)new(lbl_88D45B38, 0x14, 4, 0, 2) R2KeyArray();
    self->key_count = 5;
    self->handlers[0] = (void *)ts4_noop_881B3360;
    self->keys[0] = 0xf084c272u;
    self->handlers[1] = (void *)ts4_noop_881B3360;
    self->keys[1] = 0xe5f05652u;
    self->handlers[2] = (void *)ts4_noop_881B3360;
    self->keys[2] = 0x141d93ddu;
    self->handlers[3] = (void *)ts4_noop_881B3360;
    self->keys[3] = 0x6a4b2ea4u;
    self->handlers[4] = (void *)ts4_noop_881B3360;
    self->keys[4] = 0x01291adeu;
}
}
