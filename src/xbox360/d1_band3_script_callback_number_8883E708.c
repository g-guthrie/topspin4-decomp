/* Swing_DLL.xex band3 script callbacks taking a numeric or boolean argument, executable version 0.0.0.3. */
struct TS4ArgList { void *list; };
struct TS4CallState { char reserved[0x6C]; struct TS4ArgList *args; };
struct TS4CallContext { struct TS4CallState *state; };
double fn_88822420(void *list, int index);
unsigned int fn_88822398(void *list, int index);

#define TS4_ARG_INT(context) ((int)fn_88822420((context)->state->args->list, 1))
#define TS4_ARG_UINT(context) ((unsigned int)fn_88822420((context)->state->args->list, 1))
#define TS4_ARG_FLAG(context) (fn_88822398((context)->state->args->list, 1))

struct TS4Vt { void *s0; void *s1; void (*slot2)(void *self, int a, int b); void *s3; void *s4; void (*slot5)(void *self, int a); };
struct TS4Sub { struct TS4Vt *vtable; };
struct TS4Inner24 { char reserved0[8]; unsigned int word8; unsigned int wordc; char reserved1[0xd0c]; int d1c; };
struct TS4Mgr {
    char reserved0[0x1C];
    struct TS4Sub sub;
    char reserved1[4];
    struct TS4Inner24 *inner;
    char reserved2[0xC];
    void *obj34;
    void *obj38;
    char reserved3[0x24];
    struct TS4Flag *obj60;
};
struct TS4Flag { char reserved[0x18]; unsigned char flag; };
extern struct TS4Mgr *lbl_88D459E8;

void ts4_loop_get_u32_lbl_88D459E0_8883CB50(int value);
void fn_888411F0(unsigned int value);
void fn_88841250(unsigned int value);
void fn_88852FA0(unsigned int value);
void ts4_loop_call_seq_u32_lbl_88D459E0_8884FDE8(int value);
void fn_8883EC28(struct TS4Mgr *mgr, unsigned int value);
void fn_8883F508(void *object, unsigned int value, int flag);
void fn_8885CC38(struct TS4Mgr *mgr, int value, int a, int b);
void fn_8885F628(void *object, int value);
void fn_88863D00(void *object, int value, int flag);
void *fn_88843650(struct TS4Mgr *mgr, int flag);
void fn_88851628(void *object, int value);

unsigned int ts4_script_callback_8883E708(void *unused, struct TS4CallContext *context)
{
    ts4_loop_get_u32_lbl_88D459E0_8883CB50(TS4_ARG_INT(context));
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_888455F0(void *unused, struct TS4CallContext *context)
{
    fn_888411F0(TS4_ARG_UINT(context));
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88845638(void *unused, struct TS4CallContext *context)
{
    fn_88841250(TS4_ARG_UINT(context));
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_888538A0(void *unused, struct TS4CallContext *context)
{
    fn_88852FA0(TS4_ARG_UINT(context));
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88853C58(void *unused, struct TS4CallContext *context)
{
    ts4_loop_call_seq_u32_lbl_88D459E0_8884FDE8(TS4_ARG_INT(context));
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88842F80(void *unused, struct TS4CallContext *context)
{
    fn_8883EC28(lbl_88D459E8, TS4_ARG_UINT(context));
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88845680(void *unused, struct TS4CallContext *context)
{
    fn_8883F508(lbl_88D459E8->obj34, TS4_ARG_UINT(context), 0);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8885ECD8(void *unused, struct TS4CallContext *context)
{
    int value = TS4_ARG_INT(context);
    fn_8885CC38(lbl_88D459E8, value, 0, 0);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8885ED30(void *unused, struct TS4CallContext *context)
{
    int value = TS4_ARG_INT(context);
    fn_8885CC38(lbl_88D459E8, value, 1, 1);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_888628F8(void *unused, struct TS4CallContext *context)
{
    fn_8885F628(lbl_88D459E8->obj38, TS4_ARG_INT(context));
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88864A28(void *unused, struct TS4CallContext *context)
{
    fn_88863D00(lbl_88D459E8, TS4_ARG_INT(context), 0);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8883E750(void *unused, struct TS4CallContext *context)
{
    unsigned int value = TS4_ARG_UINT(context);
    lbl_88D459E8->inner->wordc = value;
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8883C0C8(void *unused, struct TS4CallContext *context)
{
    int value = TS4_ARG_INT(context);
    lbl_88D459E8->sub.vtable->slot5(&lbl_88D459E8->sub, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88856010(void *unused, struct TS4CallContext *context)
{
    int value = TS4_ARG_INT(context);
    fn_88851628(lbl_88D459E8->obj38, lbl_88D459E8->inner->d1c + value);
    (void)unused;
    return 0;
}
