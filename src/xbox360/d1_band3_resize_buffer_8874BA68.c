/* Swing_DLL.xex band3 buffer helpers calling a shared finaliser, executable version 0.0.0.3. */
struct TS4BufferPair {
    unsigned int size;
    void *data;
};
struct TS4Buffered {
    char reserved[0x80];
    struct TS4BufferPair pair;
};
void *fn_8823DF18(void *data, void *same, unsigned int size);
void *fn_8823EF28(void *data, void *same, unsigned int size);
void *fn_8823F280(void *data, void *same, unsigned int size);
void *fn_8823F440(void *data, void *same, unsigned int size);
void fn_8874B9B8(void *object);

void ts4_buffer_step_8874BA68(struct TS4Buffered *self)
{
    struct TS4BufferPair *pair = &self->pair;
    pair->data = fn_8823EF28(pair->data, pair->data, pair->size);
    fn_8874B9B8(self);
}

void ts4_buffer_step_8874BAB0(struct TS4Buffered *self)
{
    struct TS4BufferPair *pair = &self->pair;
    pair->data = fn_8823F440(pair->data, pair->data, pair->size);
    fn_8874B9B8(self);
}

void ts4_buffer_step_8874BAF8(struct TS4Buffered *self)
{
    struct TS4BufferPair *pair = &self->pair;
    pair->data = fn_8823F280(pair->data, pair->data, pair->size);
    fn_8874B9B8(self);
}

void ts4_buffer_step_88751550(struct TS4Buffered *self)
{
    struct TS4BufferPair *pair = &self->pair;
    pair->data = fn_8823DF18(pair->data, pair->data, pair->size);
    fn_8874B9B8(self);
}

void ts4_buffer_step_88709D58(struct TS4Buffered *self)
{
    struct TS4BufferPair *pair = &self->pair;
    pair->data = fn_8823DF18(pair->data, pair->data, pair->size);
}

