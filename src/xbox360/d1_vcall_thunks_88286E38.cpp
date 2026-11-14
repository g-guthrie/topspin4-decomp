/* Swing_DLL.xex 0x88286E38-0x88286E48, executable version 0.0.0.3.
 * MSVC virtual-call thunks. The original class is unknown; this stand-in
 * declares its virtual slots so that taking each member's address emits
 * the same thunk the game's code did. */

class TS4VcallClass88286E38 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
};

typedef void (TS4VcallClass88286E38::*TS4VcallClass88286E38_method)();

extern const TS4VcallClass88286E38_method ts4_vcall_table_88286E38[] = {
    &TS4VcallClass88286E38::slot_002,
};
