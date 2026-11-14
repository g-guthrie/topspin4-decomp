/* Swing_DLL.xex band3 script value wrappers and member serializers, executable version 0.0.0.3. */
#include "script_context.h"

void fn_888364F8(void *a, void *b, struct TS4ScriptValue *value);
void fn_888367F8(void *a, void *b, struct TS4ScriptValue *value);
void fn_888368B0(void *a, void *b, struct TS4ScriptValue *value);

void ts4_script_value_number_88836600(void *a, void *b, double number)
{
    struct TS4ScriptValue value;
    value.type = 3;
    value.value.number = number;
    fn_888364F8(a, b, &value);
}

void ts4_script_value_number_88837388(void *a, void *b, double number)
{
    struct TS4ScriptValue value;
    value.type = 3;
    value.value.number = number;
    fn_888368B0(a, b, &value);
}

