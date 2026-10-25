typedef unsigned int u32;

extern void fn_88448290(void *buffer, u32 size);
extern u32 lbl_88D23A24;
extern u32 lbl_8804653C;
extern void fn_88438788(void);
extern void fn_884387A0(void);

struct State {
    u32 *p1;
    void (*p2)();
    void (*p3)();
    u32 value;
};

void fn_88AF5DE8(void)
{
    u32 buffer[20];
    struct State *state = (struct State *)&lbl_88D23A24;

    fn_88448290(buffer, 0);

    state->p1 = &lbl_8804653C;
    state->p2 = fn_88438788;
    state->p3 = fn_884387A0;
    state->value = buffer[0];
}