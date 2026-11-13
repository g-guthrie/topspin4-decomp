/* Swing_DLL.xex family of forwarding virtual call helpers, executable version 0.0.0.3. */
typedef struct Ts4VCallee {
    void (**vtable)(void *, struct Ts4VCallee *);
} Ts4VCallee;

void *ts4_invoke_arg_vslot_8841B148(void *self, char *argument)
{
    Ts4VCallee *callee = *(Ts4VCallee **)(argument + 0x8);
    callee->vtable[9](self, callee);
    return self;
}

void *ts4_invoke_arg_vslot_8841CEC8(void *self, char *argument)
{
    Ts4VCallee *callee = *(Ts4VCallee **)(argument + 0x8);
    callee->vtable[3](self, callee);
    return self;
}

