/* Swing_DLL.xex band3 constructors that register a named instance, executable version 0.0.0.3. */
struct TS4Triple {
    unsigned int first;
    unsigned int second;
    unsigned int third;
};
struct TS4Base {
    char reserved0[8];
    unsigned char flag;
};
struct TS4W50 {
    char reserved0[0x50];
    unsigned int value;
};
struct TS4W84 {
    char reserved0[0x84];
    unsigned int value;
};
struct TS4W2C {
    char reserved0[0x2C];
    unsigned int value;
};
void *fn_88627EC0(void *object, struct TS4Triple value);
extern char lbl_880C8F93[];
extern char lbl_880C91A2[];
extern char lbl_880C9D1A[];
extern char lbl_880CFF37[];
extern char lbl_880D052A[];
extern char lbl_880D0532[];
void ts4_call_seq_lbl_880F345C_886E8448(char *name);
void *ts4_call_seq_lbl_880EFA80_88771440(char *name);
void ts4_type_register_88771378(void *object);
void fn_8887E558(char *name);
void fn_8893CBE0(char *name);
void ts4_call_seq_lbl_880D2570_8899A0D8(char *name);
void fn_889A7D38(char *name);
void *ts4_call_seq_lbl_880E4A08_887ECBD0(void *object);
void ts4_call_seq_lbl_880E4A34_887EC120(void *object);
extern void *lbl_88D458DC;
extern void *lbl_88D45848;
extern void *lbl_88D45838;
void *ts4_if_call_seq_fn_88627EC0_887ED750(void *object, struct TS4Triple value);
void *fn_888FF738(void *object, struct TS4Triple value);
void *fn_8893F548(void *object, struct TS4Triple value);
unsigned int ts4_tailcall_XamNotifyCreateListener_8857A988(int index);
void fn_88999060(void *object);

void ts4_construct_named_886E93F0(struct TS4Base *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->flag = 0;
    ts4_call_seq_lbl_880F345C_886E8448(lbl_880C8F93);
}

void ts4_construct_named_88771E58(struct TS4Base *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->flag = 0;
    ts4_type_register_88771378(ts4_call_seq_lbl_880EFA80_88771440(lbl_880C91A2));
}

void ts4_construct_named_8887EAC0(struct TS4Base *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->flag = 0;
    fn_8887E558(lbl_880C9D1A);
}

void ts4_construct_named_8893E8D0(struct TS4Base *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->flag = 0;
    fn_8893CBE0(lbl_880CFF37);
    lbl_88D458DC = self;
}

void ts4_construct_named_8899B910(struct TS4Base *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->flag = 0;
    ts4_call_seq_lbl_880D2570_8899A0D8(lbl_880D052A);
    lbl_88D45848 = self;
}

void ts4_construct_named_889B1450(struct TS4Base *self, struct TS4Triple value)
{
    fn_88627EC0(self, value);
    self->flag = 0;
    fn_889A7D38(lbl_880D0532);
    lbl_88D45838 = self;
}

void ts4_construct_named_887EE5D8(struct TS4Base *self, struct TS4Triple value)
{
    void *base = fn_88627EC0(self, value);
    self->flag = 0;
    ts4_call_seq_lbl_880E4A34_887EC120(ts4_call_seq_lbl_880E4A08_887ECBD0(base));
}

void ts4_construct_named_887CC2D8(struct TS4W50 *self, struct TS4Triple value)
{
    ts4_if_call_seq_fn_88627EC0_887ED750(self, value);
    self->value = ts4_tailcall_XamNotifyCreateListener_8857A988(3);
}

void ts4_construct_named_88901770(struct TS4W84 *self, struct TS4Triple value)
{
    fn_888FF738(self, value);
    self->value = ts4_tailcall_XamNotifyCreateListener_8857A988(1);
}

void ts4_construct_named_8899BDD8(struct TS4W2C *self, struct TS4Triple value)
{
    fn_8893F548(self, value);
    self->value = ts4_tailcall_XamNotifyCreateListener_8857A988(5);
    fn_88999060(self);
}
