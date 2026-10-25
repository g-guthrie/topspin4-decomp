typedef unsigned int u32;

extern void fn_88448BB8(void *buffer, u32 size);
extern u32 lbl_88D23A64;
extern u32 lbl_88046560;
extern void fn_884387E8(void);
extern void fn_88438800(void);

struct State {
    u32 *p1;
    void (*p2)();
    void (*p3)();
    u32 value;
};

void fn_88AF5EC0(void)
{
    u32 buffer[28];
    struct State *state = (struct State *)&lbl_88D23A64;

    fn_88448BB8(buffer, 0);

    state->p1 = &lbl_88046560;
    state->p2 = fn_884387E8;
    state->p3 = fn_88438800;
    state->value = buffer[0];
}
