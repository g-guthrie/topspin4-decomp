typedef unsigned int ts4_u32;

/* Swing_DLL.xex 0x88151E50-0x88151E90, executable version 0.0.0.3. */
#define TS4_TYPE_CODE_GETTER(name, value) \
    ts4_u32 name(void) { return value; }

TS4_TYPE_CODE_GETTER(ts4_runtime_type_code_43, 0x43)
TS4_TYPE_CODE_GETTER(ts4_runtime_type_code_44, 0x44)
TS4_TYPE_CODE_GETTER(ts4_runtime_type_code_45, 0x45)
TS4_TYPE_CODE_GETTER(ts4_runtime_type_code_41, 0x41)
TS4_TYPE_CODE_GETTER(ts4_runtime_type_code_46, 0x46)
TS4_TYPE_CODE_GETTER(ts4_runtime_type_code_48, 0x48)
TS4_TYPE_CODE_GETTER(ts4_runtime_type_code_49, 0x49)
TS4_TYPE_CODE_GETTER(ts4_runtime_type_code_4a, 0x4a)
