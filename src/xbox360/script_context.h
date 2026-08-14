#ifndef TOPSPIN4_XBOX360_SCRIPT_CONTEXT_H
#define TOPSPIN4_XBOX360_SCRIPT_CONTEXT_H

typedef unsigned char ts4_script_u8;
typedef unsigned int ts4_script_u32;

#define TS4_SCRIPT_VALUE_INTEGER 1
#define TS4_SCRIPT_VALUE_NUMBER 4

struct TS4ScriptValue {
    int type;
    ts4_script_u32 reserved;
    union {
        int integer;
        double number;
    } value;
    ts4_script_u8 payload[1];
};

struct TS4ScriptArguments {
    ts4_script_u8 reserved[0x380];
    struct TS4ScriptValue *first_value;
    ts4_script_u32 count;
};

struct TS4ScriptContext {
    ts4_script_u8 reserved[0x10];
    struct TS4ScriptArguments *arguments;
};

#endif
