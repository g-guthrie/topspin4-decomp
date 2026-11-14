/* Swing_DLL.xex band3 constructors built on the shared base initialiser, executable version 0.0.0.3. */
struct TS4Triple {
    unsigned int first;
    unsigned int second;
    unsigned int third;
};
struct TS4Base {
    char reserved[8];
    unsigned char flag;
};
void *fn_88627EC0(void *object, struct TS4Triple value);
void fn_887849B0(void *object);
void fn_887D8F28(void *object);
void fn_887F48B8(void *object);
void fn_88803A30(void *object);
void ts4_call_seq_lbl_880E1614_88842FD0(void *object);
void ts4_call_seq_lbl_880DFDB4_88867958(void *object);
void fn_888B83E8(void *object);
void ts4_name_keys_register_88954210(void *object);

void ts4_construct_8878C340(struct TS4Base *self, struct TS4Triple value)
{
    void *base = fn_88627EC0(self, value);
    self->flag = 0;
    fn_887849B0(base);
}

void ts4_construct_887DABB8(struct TS4Base *self, struct TS4Triple value)
{
    void *base = fn_88627EC0(self, value);
    self->flag = 0;
    fn_887D8F28(base);
}

void ts4_construct_887F4F00(struct TS4Base *self, struct TS4Triple value)
{
    void *base = fn_88627EC0(self, value);
    self->flag = 0;
    fn_887F48B8(base);
}

void ts4_construct_88804010(struct TS4Base *self, struct TS4Triple value)
{
    void *base = fn_88627EC0(self, value);
    self->flag = 0;
    fn_88803A30(base);
}

void ts4_construct_888476F0(struct TS4Base *self, struct TS4Triple value)
{
    void *base = fn_88627EC0(self, value);
    self->flag = 0;
    ts4_call_seq_lbl_880E1614_88842FD0(base);
}

void ts4_construct_888681D8(struct TS4Base *self, struct TS4Triple value)
{
    void *base = fn_88627EC0(self, value);
    self->flag = 0;
    ts4_call_seq_lbl_880DFDB4_88867958(base);
}

void ts4_construct_888B8FD8(struct TS4Base *self, struct TS4Triple value)
{
    void *base = fn_88627EC0(self, value);
    self->flag = 0;
    fn_888B83E8(base);
}

void ts4_construct_8895B688(struct TS4Base *self, struct TS4Triple value)
{
    void *base = fn_88627EC0(self, value);
    self->flag = 0;
    ts4_name_keys_register_88954210(base);
}
