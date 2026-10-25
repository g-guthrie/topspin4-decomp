typedef unsigned int u32;

extern void fn_88446CD0(void *buffer, u32 size);
extern u32 lbl_88D239A4;
extern u32 lbl_88046588;
extern void fn_884386C8(void);
extern void fn_884386E0(void);

struct State {
    u32 *p1;
    void (*p2)();
    void (*p3)();
    u32 value;
};

void fn_88AF5C38(void)
{
    u32 buffer[16];
    struct State *state = (struct State *)&lbl_88D239A4;

    fn_88446CD0(buffer, 0);

    state->p1 = &lbl_88046588;
    state->p2 = fn_884386C8;
    state->p3 = fn_884386E0;
    state->value = buffer[0];
}