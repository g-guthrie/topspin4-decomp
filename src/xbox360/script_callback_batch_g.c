typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern void *lbl_88D45A60;
extern void *lbl_88D459D4;
extern void *lbl_88D459E0;
extern void *lbl_88D4594C;
extern void *lbl_88D41FC4;
void fn_887AE088(void *object);
void fn_8886FCC0(void *object);
void fn_888647B0(void *object);
void fn_88908258(void *object);
void fn_88202CD8(void *manager, void *value);

/* Registered as DLL_InitMasterPad. */
ts4_u32 ts4_script_dll_init_master_pad(void)
{
    fn_887AE088(lbl_88D45A60);
    return 0;
}

/* Registered as Debug_UnlockAll. */
ts4_u32 ts4_script_debug_unlock_all(void)
{
    fn_8886FCC0(lbl_88D459D4);
    return 0;
}

/* Registered as EndOfMatch_ApplyCoachProgress. */
ts4_u32 ts4_script_end_of_match_apply_coach_progress(void)
{
    fn_888647B0(lbl_88D459E0);
    return 0;
}

struct TS4LoadingState {
    ts4_u8 reserved[0x38];
    ts4_u8 starting;
};

/* Registered as StartLoading. */
ts4_u32 ts4_script_start_loading(void)
{
    struct TS4LoadingState *state = lbl_88D4594C;
    state->starting = 1;
    fn_88908258(state);
    return 0;
}

struct TS4PopContext {
    void *vtable;
    ts4_u8 *value;
};

struct TS4PopGlobals {
    ts4_u8 reserved[0x6C];
    void *manager;
};

/* Registered as PopMe. */
ts4_u32 ts4_script_pop_me(struct TS4PopContext *context)
{
    fn_88202CD8(
        ((struct TS4PopGlobals *)lbl_88D41FC4)->manager,
        context->value + 0x60
    );
    return 0;
}
