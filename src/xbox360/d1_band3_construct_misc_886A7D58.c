/* Swing_DLL.xex band3 misc constructors using the shared base initialiser, executable version 0.0.0.3. */
struct TS4Triple {
    unsigned int first;
    unsigned int second;
    unsigned int third;
};
struct TS4Owner {
    char reserved[0x74];
    char *base;
};
struct TS4A {
    char reserved0[0x1C];
    struct TS4Owner *owner;
    char reserved1[0x18];
    char *result;
};
struct TS4B {
    char reserved0[0x38];
    void *link_a;
    void *link_b;
    void *self;
};
struct TS4F {
    char reserved0[8];
    unsigned char flag;
    char reserved1[0x13];
    unsigned int word1c;
    unsigned int word20;
};
struct TS4D {
    char reserved0[0x1C];
    unsigned char byte1c;
    unsigned char byte1d;
};
struct TS4E {
    char reserved0[0x54];
    unsigned int word54;
};
void *fn_88627EC0(void *object, struct TS4Triple value);
void fn_88736FB8(void *object, struct TS4Triple value);
void ts4_call_seq_lbl_880EA4F0_887C8268(void *object);

void ts4_construct_886A7D58(struct TS4A *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->result = self->owner->base + 0xE80;
}

void ts4_construct_886A7E00(struct TS4B *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->link_b = &self->link_a;
    self->self = self;
}

void ts4_construct_8873C678(struct TS4E *self, struct TS4Triple value)
{
    fn_88736FB8(self, value);
    self->word54 = 0;
}

void ts4_construct_887C84C8(struct TS4F *self, struct TS4Triple value)
{
    void *base = fn_88627EC0(self, value);
    self->word1c = 0;
    self->word20 = 0;
    self->flag = 0;
    ts4_call_seq_lbl_880EA4F0_887C8268(base);
}

void ts4_construct_88868058(struct TS4F *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->word1c = 0x2CE33943;
}

void ts4_construct_88871CA8(struct TS4F *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->flag = 0;
}

void ts4_construct_888DC4B8(struct TS4D *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->byte1c = 0;
}

void ts4_construct_889564F8(struct TS4D *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->byte1c = 1;
    self->byte1d = 1;
}
