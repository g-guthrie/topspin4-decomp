/* Loader_DLL.xex 0x830A0488-0x83227040, executable version 0.0.0.3.
   Hand-templated families (interlocked), byte-verified. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
#ifdef _MSC_VER
typedef struct __declspec(passinreg) __vector4 { float v[4]; } __vector4;
#else
typedef struct __vector4 { float v[4]; } __vector4;
#endif

long _InterlockedIncrement(long volatile *);
long _InterlockedDecrement(long volatile *);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)
#endif

/* Loader_DLL.xex 0x830A0488 */
void ts4l_interlocked_830A0488(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x30)); }

/* Loader_DLL.xex 0x830A5F78 */
long ts4l_interlocked_830A5F78(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x3c)); }

/* Loader_DLL.xex 0x830A77A8 */
long ts4l_interlocked_830A77A8(char *p) { return _InterlockedIncrement((long volatile *)(p + 0xc)); }

/* Loader_DLL.xex 0x830AAAC0 */
long ts4l_interlocked_830AAAC0(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x3c)); }

/* Loader_DLL.xex 0x830C7370 */
long ts4l_interlocked_830C7370(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x4db0)); }

/* Loader_DLL.xex 0x830C7808 */
long ts4l_interlocked_830C7808(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x4db0)); }

/* Loader_DLL.xex 0x830FEF20 */
void ts4l_interlocked_830FEF20(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x10)); }

/* Loader_DLL.xex 0x830FEF48 */
void ts4l_interlocked_830FEF48(char *p) { (void)_InterlockedDecrement((long volatile *)(p + 0x10)); }

/* Loader_DLL.xex 0x8313F0F0 */
void ts4l_interlocked_8313F0F0(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x8)); }

/* Loader_DLL.xex 0x831411B0 */
long ts4l_interlocked_831411B0(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x18)); }

/* Loader_DLL.xex 0x83142E30 */
void ts4l_interlocked_83142E30(char *p) { (void)_InterlockedDecrement((long volatile *)(p + 0x8)); }

/* Loader_DLL.xex 0x83144BC0 */
void ts4l_interlocked_83144BC0(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x10)); }

/* Loader_DLL.xex 0x83144E98 */
void ts4l_interlocked_83144E98(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x18)); }

/* Loader_DLL.xex 0x83146A98 */
void ts4l_interlocked_83146A98(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x4)); }

/* Loader_DLL.xex 0x83146C08 */
void ts4l_interlocked_83146C08(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x18)); }

/* Loader_DLL.xex 0x83147498 */
void ts4l_interlocked_83147498(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x4)); }

/* Loader_DLL.xex 0x831478F0 */
void ts4l_interlocked_831478F0(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x4)); }

/* Loader_DLL.xex 0x83147AB8 */
void ts4l_interlocked_83147AB8(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x10)); }

/* Loader_DLL.xex 0x83149E68 */
long ts4l_interlocked_83149E68(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x4)); }

/* Loader_DLL.xex 0x8314A818 */
long ts4l_interlocked_8314A818(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x4)); }

/* Loader_DLL.xex 0x8314EA98 */
long ts4l_interlocked_8314EA98(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x4)); }

/* Loader_DLL.xex 0x83150E50 */
long ts4l_interlocked_83150E50(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x80)); }

/* Loader_DLL.xex 0x83153250 */
void ts4l_interlocked_83153250(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0xc)); }

/* Loader_DLL.xex 0x83153278 */
long ts4l_interlocked_83153278(char *p) { return _InterlockedDecrement((long volatile *)(p + 0xc)); }

/* Loader_DLL.xex 0x8315E810 */
long ts4l_interlocked_8315E810(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x4)); }

/* Loader_DLL.xex 0x8316F4C8 */
long ts4l_interlocked_8316F4C8(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x4)); }

/* Loader_DLL.xex 0x83173260 */
long ts4l_interlocked_83173260(char *p) { return _InterlockedIncrement((long volatile *)(p + 0xc)); }

/* Loader_DLL.xex 0x83182410 */
long ts4l_interlocked_83182410(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x14)); }

/* Loader_DLL.xex 0x83183338 */
long ts4l_interlocked_83183338(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x1c)); }

/* Loader_DLL.xex 0x83183360 */
long ts4l_interlocked_83183360(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x1c)); }

/* Loader_DLL.xex 0x831841D8 */
long ts4l_interlocked_831841D8(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x1c)); }

/* Loader_DLL.xex 0x83185BF0 */
long ts4l_interlocked_83185BF0(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x1c)); }

/* Loader_DLL.xex 0x83186A18 */
long ts4l_interlocked_83186A18(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x1c)); }

/* Loader_DLL.xex 0x83187018 */
long ts4l_interlocked_83187018(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x1c)); }

/* Loader_DLL.xex 0x83187EB8 */
long ts4l_interlocked_83187EB8(char *p) { return _InterlockedIncrement((long volatile *)(p + 0x1c)); }

/* Loader_DLL.xex 0x8319D930 */
void ts4l_interlocked_8319D930(char *p) { (void)_InterlockedIncrement((long volatile *)(p + 0x10)); }

/* Loader_DLL.xex 0x83227018 */
long ts4l_interlocked_83227018(char *p) { return _InterlockedIncrement((long volatile *)(p + 0xc)); }
