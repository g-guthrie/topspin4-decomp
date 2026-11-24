/* Swing_DLL.xex 0x88271E68-0x88271ED8, executable version 0.0.0.3.
 * MSVC virtual-call thunks. The original class is unknown; this stand-in
 * declares its virtual slots so that taking each member's address emits
 * the same thunk the game's code did. */

class TS4VcallClass88271E68 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008();
    virtual void slot_009();
    virtual void slot_00a();
    virtual void slot_00b();
    virtual void slot_00c();
    virtual void slot_00d();
    virtual void slot_00e();
    virtual void slot_00f();
};

typedef void (TS4VcallClass88271E68::*TS4VcallClass88271E68_method)();

extern const TS4VcallClass88271E68_method ts4_vcall_table_88271E68[] = {
    &TS4VcallClass88271E68::slot_00f,
    &TS4VcallClass88271E68::slot_00c,
    &TS4VcallClass88271E68::slot_001,
    &TS4VcallClass88271E68::slot_005,
    &TS4VcallClass88271E68::slot_00d,
    &TS4VcallClass88271E68::slot_00a,
    &TS4VcallClass88271E68::slot_00e,
};
