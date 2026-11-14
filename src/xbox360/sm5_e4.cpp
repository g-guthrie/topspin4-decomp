/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
#include "script_context.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct TS4G8 { ts4_script_u8 pad[8]; ts4_script_u8 *flag; };
struct VT12 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual u8 m12(); };
struct VT12b { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual bool m12(); };
struct SP4 { virtual void f0(); };
extern "C" {
extern struct TS4ScriptValue *g_ts4_default_script_value;
extern const char g_ts4_true_string[];
bool ts4_script_string_equals(void *value, const char *text);
extern void *lbl_88D45B1C;
/* Swing_DLL.xex 0x887E94A0 */
bool ts4_vcall_flag_887E94A0(char *s) { return *(u32*)(s+0x1bc) != 0 && ((VT12b*)(s+0x1dc))->m12(); }
}
