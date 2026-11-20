/* Swing_DLL.xex 0x88286E20-0x88286E30, executable version 0.0.0.3.
 * MSVC virtual-call thunks. The original class is unknown; this stand-in
 * declares its virtual slots so that taking each member's address emits
 * the same thunk the game's code did. */

class TS4VcallClass88286E20 {
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
};

typedef void (TS4VcallClass88286E20::*TS4VcallClass88286E20_method)();

extern const TS4VcallClass88286E20_method ts4_vcall_table_88286E20[] = {
    &TS4VcallClass88286E20::slot_00b,
};
