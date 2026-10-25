typedef unsigned int u32;

extern void fn_88481278(void *buffer, u32 size);
extern u32 lbl_88D249F0;
extern u32 lbl_88045654;
extern void fn_88469570(void);
extern void fn_88469588(void);

struct State {
    u32 *p1;
    void (*p2)();
    void (*p3)();
    u32 value;
};

void fn_88AF7EA8(void)
{
    u32 buffer[16];
    struct State *state = (struct State *)&lbl_88D249F0;

    fn_88481278(buffer, 0);

    state->p1 = &lbl_88045654;
    state->p2 = fn_88469570;
    state->p3 = fn_88469588;
    state->value = buffer[0];
}