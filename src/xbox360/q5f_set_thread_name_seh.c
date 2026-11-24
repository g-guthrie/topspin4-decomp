/* Q5F: debugger thread-name helper (Top Spin 4, Xbox 360, Swing_DLL.xex), plain route, byte match.
 *
 * 0x88883DE0 is the classic MSVC SetThreadName: it raises exception 0x406D1388 with a
 * THREADNAME_INFO block (type 0x1000, name, thread id, flags) inside __try/__except, so an
 * attached debugger can read the name and nothing happens otherwise.
 *
 * The compiler emits three pieces for it, and the split target has all three:
 *   0x88883DD8  except_data_88883DE0: {__C_specific_handler, scope table} before the function
 *   0x88883DE0  the function body (0x6c bytes, its own .pdata entry)
 *   0x88883E4C  the __except filter funclet (0x28 bytes, its own .pdata entry, target fn_88883E4C);
 *               it sits inside this function's symbol in the compiled object
 * tools/fn_check.py compares the two code ranges separately and the scope table with the image.
 * The funclet has no C-level name: it is the filter expression below.
 *
 * __try/__except is a Microsoft extension. A host compiler sees the plain call, so the file
 * still passes the host syntax check; only the _MSC_VER branch is the reconstruction. */
typedef unsigned int u32;

typedef struct Q5fThreadNameInfo {
    u32 type;               /* +0x0: 0x1000 */
    const char *name;       /* +0x4 */
    u32 thread_id;          /* +0x8 */
    u32 flags;              /* +0xc: 0 */
} Q5fThreadNameInfo;

#define Q5F_THREAD_NAME_EXCEPTION 0x406D1388u

/* 0x88581F50: RaiseException(code, flags, number of arguments, arguments) */
extern void fn_88581F50(u32 code, u32 flags, u32 nargs, const u32 *args);

#ifdef _MSC_VER
typedef struct Q5fExceptionRecord { u32 code; } Q5fExceptionRecord;
typedef struct Q5fExceptionPointers { Q5fExceptionRecord *record; } Q5fExceptionPointers;
/* the filter: swallow our own exception and resume (-1), otherwise run the empty handler (1) */
#define Q5F_THREAD_NAME_FILTER() \
    (((Q5fExceptionPointers *)_exception_info())->record->code == Q5F_THREAD_NAME_EXCEPTION ? -1 : 1)
#endif

/* Swing_DLL.xex 0x88883DE0 (+ filter funclet 0x88883E4C) */
void ts4_set_thread_name_88883DE0(u32 thread_id, const char *name)
{
    Q5fThreadNameInfo info;
    info.type = 0x1000;
    info.name = name;
    info.thread_id = thread_id;
    info.flags = 0;
#ifdef _MSC_VER
    __try {
        fn_88581F50(Q5F_THREAD_NAME_EXCEPTION, 0, sizeof(info) / sizeof(u32), (const u32 *)&info);
    } __except (Q5F_THREAD_NAME_FILTER()) {
    }
#else
    fn_88581F50(Q5F_THREAD_NAME_EXCEPTION, 0, sizeof(info) / sizeof(u32), (const u32 *)&info);
#endif
}
