/*
 * W11E: small gameplay wrappers (plain route, /Oc).
 * Swing_DLL.xex sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 */
class TS4VcallClass88286E38 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
};
typedef void (TS4VcallClass88286E38::*W11eSlot)();

extern "C" void ts4_loop_get_u32_off4_8826C568(void *a, void *b);

/* Swing_DLL.xex 0x88661A38: pass a one-word stack temp holding the slot_002 thunk address */
extern "C" void ts4_call_with_tmp_88661A38(char *s)
{
    W11eSlot t = &TS4VcallClass88286E38::slot_002;
    ts4_loop_get_u32_off4_8826C568(s + 0xc, &t);
}
