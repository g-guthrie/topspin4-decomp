/* Swing_DLL.xex band3 script callbacks passing one numeric argument to a global object, executable version 0.0.0.3. */
struct TS4ArgList { void *list; };
struct TS4CallState { char reserved[0x6C]; struct TS4ArgList *args; };
struct TS4CallContext { struct TS4CallState *state; };
double fn_88822420(void *list, int index);
extern void *lbl_88D459E8;
void ts4_reltbl_flag_nth_active_8883C608(void *object, int value);
extern void *lbl_88D459E0;
void fn_8884E380(void *object, int value);
void fn_88852AC0(void *object, int value);
void fn_88852CB0(void *object, int value);
void fn_888532F8(void *object, int value);
void fn_88853E18(void *object, int value);
void fn_88855B70(void *object, int value);
extern void *lbl_88D459D4;
void fn_8886BB78(void *object, int value);
void fn_8885D370(void *object, int value);
void fn_8885B830(void *object, int value);
void fn_8886E910(void *object, int value);
void fn_888602E0(void *object, int value);
void fn_888622C8(void *object, int value);
void fn_88863998(void *object, int value);
void fn_88863138(void *object, int value);

unsigned int ts4_script_callback_8883E548(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    ts4_reltbl_flag_nth_active_8883C608(lbl_88D459E8, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8884F2D0(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_8884E380(lbl_88D459E0, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88853740(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_88852AC0(lbl_88D459E0, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88853790(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_88852CB0(lbl_88D459E0, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88853850(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_888532F8(lbl_88D459E0, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88856070(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_88853E18(lbl_88D459E8, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88857AF8(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_88855B70(lbl_88D459E0, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88858EE0(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_8886BB78(lbl_88D459D4, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8885EB90(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_8885D370(lbl_88D459E8, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8885EC18(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_8885B830(lbl_88D459E8, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8885ED88(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_8886E910(lbl_88D459D4, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_888620B8(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_888602E0(lbl_88D459E0, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_888628A8(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_888622C8(lbl_88D459E8, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88863C30(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_88863998(lbl_88D459E0, value);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88863C80(void *unused, struct TS4CallContext *context)
{
    int value = (int)fn_88822420(context->state->args->list, 1);
    fn_88863138(lbl_88D459E8, value);
    (void)unused;
    return 0;
}
