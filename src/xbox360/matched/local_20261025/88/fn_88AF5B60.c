typedef unsigned int u32;

extern void fn_88446CB8(void *buffer, u32 size);
extern u32 lbl_88D23964;
extern u32 lbl_880465E8;
extern void fn_88438668(void);
extern void fn_88438680(void);

struct State {
    u32 *p1;
    void (*p2)();
    void (*p3)();
    u32 value;
};

void fn_88AF5B60(void)
{
    u32 buffer[20];
    struct State *state = (struct State *)&lbl_88D23964;

    fn_88446CB8(buffer, 0);

    state->p1 = &lbl_880465E8;
    state->p2 = fn_88438668;
    state->p3 = fn_88438680;
    state->value = buffer[0];
}