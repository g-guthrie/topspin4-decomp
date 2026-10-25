typedef unsigned int u32;

extern void fn_88478CE8(void *buffer, u32 size);
extern u32 lbl_88D24380;
extern u32 lbl_88045958;
extern void fn_88468768(void);
extern void fn_88468780(void);

struct State {
    u32 *p1;
    void (*p2)();
    void (*p3)();
    u32 value;
};

void fn_88AF6D50(void)
{
    u32 buffer[16];
    struct State *state = (struct State *)&lbl_88D24380;

    fn_88478CE8(buffer, 0);

    state->p1 = &lbl_88045958;
    state->p2 = fn_88468768;
    state->p3 = fn_88468780;
    state->value = buffer[0];
}