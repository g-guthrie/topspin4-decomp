/* Loader_DLL.xex 0x8340D2C0-0x8340D340, 0x8340D418-0x8340D498, 0x8340D5F0-0x8340D670, executable version 0.0.0.3. */
typedef unsigned long u32;
typedef struct { u32 len; char *buf; } Ts4lAnsiString;
typedef struct { int root; void *name; u32 attrs; } Ts4lObjectAttributes;
extern void ts4l_import_RtlInitAnsiString_835176D8(Ts4lAnsiString *s, const char *src);
extern int ts4l_import_ObOpenObjectByName_83517B88(Ts4lObjectAttributes *oa, void *type, u32 a, u32 *out);
extern void ts4_tailcall_fn_8340F088_834141B8(int status);
extern void *__imp_ExTimerObjectType;
extern void *__imp_ExSemaphoreObjectType;
extern void *__imp_ExEventObjectType;
#define OPEN(fn, T) u32 fn(u32 a, u32 b, const char *name) { Ts4lAnsiString s; Ts4lObjectAttributes oa; u32 h; int st; (void)a; (void)b; \
 if (name == 0) { ts4_tailcall_fn_8340F088_834141B8(0xC000000D); return 0; } \
 ts4l_import_RtlInitAnsiString_835176D8(&s, name); oa.root = -4; oa.attrs = 0; oa.name = &s; \
 st = ts4l_import_ObOpenObjectByName_83517B88(&oa, T, 0, &h); \
 if (st < 0) { ts4_tailcall_fn_8340F088_834141B8(st); return 0; } return h; }
OPEN(ts4l_open_timer_8340D5F0, __imp_ExTimerObjectType)
OPEN(ts4l_open_semaphore_8340D418, __imp_ExSemaphoreObjectType)
OPEN(ts4l_open_event_8340D2C0, __imp_ExEventObjectType)
