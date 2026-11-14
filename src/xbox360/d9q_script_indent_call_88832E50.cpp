/* Swing_DLL.xex 0x88832E50-0x88832EB0, executable version 0.0.0.3. */
typedef struct lua_State lua_State;
typedef unsigned int u32;
struct Ts9Sink;

struct Ts9Args {
    lua_State *L;
};

extern "C" Ts9Sink *lib3_lua_touserdata_88822230(lua_State *L, int idx);
extern "C" double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern "C" void fn_888327C0(Ts9Sink *sink, u32 n);

/* Script binding: write an indent of the given depth to the sink in argument 1. */
extern "C" int ts4_script_indent_88832E50(Ts9Args *args)
{
    Ts9Sink *sink = lib3_lua_touserdata_88822230(args->L, 1);
    lua_State *L = args->L;
    fn_888327C0(sink, (u32)(int)ts4_lua_tonumber_88822420(L, 2));
    return 0;
}
