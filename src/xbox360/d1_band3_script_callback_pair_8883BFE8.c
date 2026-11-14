/* Swing_DLL.xex band3 script callbacks taking two arguments, executable version 0.0.0.3. */
struct TS4ArgList { void *list; };
struct TS4CallState { char reserved[0x6C]; struct TS4ArgList *args; };
struct TS4CallContext { struct TS4CallState *state; };
double fn_88822420(void *list, int index);
unsigned int fn_888348A0(void *list, int index);
unsigned int fn_88822398(void *list, int index);
extern void *lbl_88D459E0;
extern void *lbl_88D459E8;
void fn_8883B478(void *object, int first, int second);
void fn_8883B4F8(void *object, int first, int second);
void fn_8883DBA8(void *object, int first, unsigned int second);
void fn_8883DC28(void *object, int first, unsigned int second);
void fn_8883DCA8(void *object, int first, unsigned int second);
void fn_8884E738(void *object, int first, unsigned int second);
void fn_88853058(void *object, int first, unsigned int second);
void fn_88863460(void *object, int first, unsigned int second);
void fn_88852F10(void *object, int second, int first);
void fn_88862E38(void *object, int first, unsigned int second);
void fn_88842698(void *object, int first, unsigned int second);
void fn_88842740(void *object, int first, unsigned int second);
void fn_888427E8(void *object, int first, unsigned int second);
void fn_88842890(void *object, int first, unsigned int second);
void fn_8884FC28(void *object, int first, unsigned int second);

unsigned int ts4_script_callback_8883BFE8(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    int second = (int)fn_88822420(list, 2);
    fn_8883B478(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8883C058(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    int second = (int)fn_88822420(list, 2);
    fn_8883B4F8(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8883E5B8(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = (unsigned int)fn_88822420(list, 2);
    fn_8883DBA8(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8883E628(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = (unsigned int)fn_88822420(list, 2);
    fn_8883DC28(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8883E698(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = (unsigned int)fn_88822420(list, 2);
    fn_8883DCA8(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_8884F320(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = (unsigned int)fn_88822420(list, 2);
    fn_8884E738(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_888538E8(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = (unsigned int)fn_88822420(list, 2);
    fn_88853058(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88863BC0(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = (unsigned int)fn_88822420(list, 2);
    fn_88863460(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_888537E0(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    int second = (int)fn_88822420(list, 2);
    fn_88852F10(lbl_88D459E0, second, first);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88863B50(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = (unsigned int)fn_88822420(list, 2);
    fn_88862E38(lbl_88D459E8, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88842DE0(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = fn_888348A0(list, 2);
    fn_88842698(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88842E48(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = fn_888348A0(list, 2);
    fn_88842740(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88842EB0(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = fn_888348A0(list, 2);
    fn_888427E8(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88842F18(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = fn_888348A0(list, 2);
    fn_88842890(lbl_88D459E0, first, second);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88853D90(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int first = (int)fn_88822420(args->list, 1);
    void *list = args->list;
    unsigned int second = fn_88822398(list, 2) != 0;
    fn_8884FC28(lbl_88D459E8, first, second);
    (void)unused;
    return 0;
}
