/* Swing_DLL.xex band3 script callbacks taking three or four arguments, executable version 0.0.0.3. */
struct TS4ArgList { void *list; };
struct TS4CallState { char reserved[0x6C]; struct TS4ArgList *args; };
struct TS4CallContext { struct TS4CallState *state; };
struct TS4Manager { char reserved[0x34]; void *member; };
double fn_88822420(void *list, int index);
unsigned int fn_88822398(void *list, int index);
extern void *lbl_88D459E0;
extern struct TS4Manager *lbl_88D459E8;
void fn_8883B3F8(void *object, int a0, int a1, int a2, int a3);
void fn_88845780(void *object, unsigned int a0, int a1, int a2);
void fn_8884CF80(void *object, unsigned int a0, unsigned int a1, int a2, int extra);
void fn_88858208(void *object, int a0, int a1, int a2);

unsigned int ts4_script_callback_8883BF50(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int a0 = (int)fn_88822420(args->list, 1);
    void *list1 = args->list;
    int a1 = (int)fn_88822420(list1, 2);
    void *list2 = args->list;
    int a2 = (int)fn_88822420(list2, 3);
    void *list3 = args->list;
    int a3 = (int)fn_88822420(list3, 4);
    fn_8883B3F8(lbl_88D459E0, a0, a1, a2, a3);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88847660(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    unsigned int a0 = (unsigned int)fn_88822420(args->list, 1);
    void *list1 = args->list;
    int a1 = (int)fn_88822420(list1, 2);
    void *list2 = args->list;
    int a2 = fn_88822398(list2, 3) != 0;
    fn_88845780(lbl_88D459E8, a0, a1, a2);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88853958(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    unsigned int a0 = (unsigned int)fn_88822420(args->list, 1);
    void *list1 = args->list;
    unsigned int a1 = (unsigned int)fn_88822420(list1, 2);
    void *list2 = args->list;
    int a2 = (int)fn_88822420(list2, 3);
    fn_8884CF80(lbl_88D459E8->member, a0, a1, a2, 0);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_888539F8(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    unsigned int a0 = (unsigned int)fn_88822420(args->list, 1);
    void *list1 = args->list;
    unsigned int a1 = (unsigned int)fn_88822420(list1, 2);
    void *list2 = args->list;
    int a2 = (int)fn_88822420(list2, 3);
    fn_8884CF80(lbl_88D459E8->member, a0, a1, a2, 0);
    (void)unused;
    return 0;
}

unsigned int ts4_script_callback_88858DE0(void *unused, struct TS4CallContext *context)
{
    struct TS4ArgList *args = context->state->args;
    int a0 = (int)fn_88822420(args->list, 1);
    void *list1 = args->list;
    int a1 = fn_88822398(list1, 2) != 0;
    void *list2 = args->list;
    int a2 = fn_88822398(list2, 3) != 0;
    fn_88858208(lbl_88D459E8, a0, a1, a2);
    (void)unused;
    return 0;
}

