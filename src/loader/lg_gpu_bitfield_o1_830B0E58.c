/* Loader_DLL.xex 0x830B0E58-0x830B28EC, executable version 0.0.0.3.
   Hand-templated families (gpu_bitfield), byte-verified. */
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

/* Loader_DLL.xex 0x830B0E58 */
struct T_830B0E58 { unsigned a:29; unsigned b:3; };
struct D_830B0E58 { char pad[0x10]; ts4l_u64 f; char pad2[0x2948 - 0x18]; struct T_830B0E58 x; };
void ts4l_set_bits_mark_dirty_830B0E58(struct D_830B0E58 *p, unsigned v) { struct T_830B0E58 t = p->x; t.b = v; *(volatile struct T_830B0E58 *)&p->x = t; p->f |= 0x40ull; }

/* Loader_DLL.xex 0x830B0E88 */
struct T_830B0E88 { unsigned a:21; unsigned b:8; unsigned c:3; };
struct D_830B0E88 { char pad[0x10]; ts4l_u64 f; char pad2[0x2948 - 0x18]; struct T_830B0E88 x; };
void ts4l_set_bits_mark_dirty_830B0E88(struct D_830B0E88 *p, unsigned v) { struct T_830B0E88 t = p->x; t.b = v; *(volatile struct T_830B0E88 *)&p->x = t; p->f |= 0x40ull; }

/* Loader_DLL.xex 0x830B13F0 */
struct T_830B13F0 { unsigned a:29; unsigned b:3; };
struct D_830B13F0 { char pad[0x10]; ts4l_u64 f; char pad2[0x293c - 0x18]; struct T_830B13F0 x; };
void ts4l_set_bits_mark_dirty_830B13F0(struct D_830B13F0 *p, unsigned v) { struct T_830B13F0 t = p->x; t.b = v; *(volatile struct T_830B13F0 *)&p->x = t; p->f |= 0x200ull; }

/* Loader_DLL.xex 0x830B1648 */
struct T_830B1648 { unsigned a:29; unsigned b:1; unsigned c:2; };
struct D_830B1648 { char pad[0x10]; ts4l_u64 f; char pad2[0x2934 - 0x18]; struct T_830B1648 x; };
void ts4l_set_bits_mark_dirty_830B1648(struct D_830B1648 *p, unsigned v) { struct T_830B1648 t = p->x; t.b = v; *(volatile struct T_830B1648 *)&p->x = t; p->f |= 0x800ull; }

/* Loader_DLL.xex 0x830B1728 */
struct T_830B1728 { unsigned a:21; unsigned b:3; unsigned c:8; };
struct D_830B1728 { char pad[0x10]; ts4l_u64 f; char pad2[0x2934 - 0x18]; struct T_830B1728 x; };
void ts4l_set_bits_mark_dirty_830B1728(struct D_830B1728 *p, unsigned v) { struct T_830B1728 t = p->x; t.b = v; *(volatile struct T_830B1728 *)&p->x = t; p->f |= 0x800ull; }

/* Loader_DLL.xex 0x830B17C8 */
struct T_830B17C8 { unsigned a:15; unsigned b:3; unsigned c:14; };
struct D_830B17C8 { char pad[0x10]; ts4l_u64 f; char pad2[0x2934 - 0x18]; struct T_830B17C8 x; };
void ts4l_set_bits_mark_dirty_830B17C8(struct D_830B17C8 *p, unsigned v) { struct T_830B17C8 t = p->x; t.b = v; *(volatile struct T_830B17C8 *)&p->x = t; p->f |= 0x800ull; }

/* Loader_DLL.xex 0x830B17F8 */
struct T_830B17F8 { unsigned a:9; unsigned b:3; unsigned c:20; };
struct D_830B17F8 { char pad[0x10]; ts4l_u64 f; char pad2[0x2934 - 0x18]; struct T_830B17F8 x; };
void ts4l_set_bits_mark_dirty_830B17F8(struct D_830B17F8 *p, unsigned v) { struct T_830B17F8 t = p->x; t.b = v; *(volatile struct T_830B17F8 *)&p->x = t; p->f |= 0x800ull; }

/* Loader_DLL.xex 0x830B1898 */
struct T_830B1898 { unsigned a:3; unsigned b:3; unsigned c:26; };
struct D_830B1898 { char pad[0x10]; ts4l_u64 f; char pad2[0x2934 - 0x18]; struct T_830B1898 x; };
void ts4l_set_bits_mark_dirty_830B1898(struct D_830B1898 *p, unsigned v) { struct T_830B1898 t = p->x; t.b = v; *(volatile struct T_830B1898 *)&p->x = t; p->f |= 0x800ull; }

/* Loader_DLL.xex 0x830B1B78 */
struct T_830B1B78 { unsigned a:16; unsigned b:1; unsigned c:15; };
struct D_830B1B78 { char pad[0x10]; ts4l_u64 f; char pad2[0x2948 - 0x18]; struct T_830B1B78 x; };
void ts4l_set_bits_mark_dirty_830B1B78(struct D_830B1B78 *p, unsigned v) { struct T_830B1B78 t = p->x; t.b = v; *(volatile struct T_830B1B78 *)&p->x = t; p->f |= 0x40ull; }

/* Loader_DLL.xex 0x830B1F78 */
struct T_830B1F78 { unsigned b:4; unsigned c:28; };
struct D_830B1F78 { char pad[0x10]; ts4l_u64 f; char pad2[0x292c - 0x18]; struct T_830B1F78 x; };
void ts4l_set_bits_mark_dirty_830B1F78(struct D_830B1F78 *p, unsigned v) { struct T_830B1F78 t = p->x; t.b = v; *(volatile struct T_830B1F78 *)&p->x = t; p->f |= 0x2000ull; }

/* Loader_DLL.xex 0x830B20A8 */
struct T_830B20A8 { unsigned b:4; unsigned c:28; };
struct D_830B20A8 { char pad[0x10]; ts4l_u64 f; char pad2[0x2930 - 0x18]; struct T_830B20A8 x; };
void ts4l_set_bits_mark_dirty_830B20A8(struct D_830B20A8 *p, unsigned v) { struct T_830B20A8 t = p->x; t.b = v; *(volatile struct T_830B20A8 *)&p->x = t; p->f |= 0x1000ull; }

/* Loader_DLL.xex 0x830B2670 */
struct T_830B2670 { unsigned a:10; unsigned b:1; unsigned c:21; };
struct D_830B2670 { char pad[0x10]; ts4l_u64 f; char pad2[0x2948 - 0x18]; struct T_830B2670 x; };
void ts4l_set_bits_mark_dirty_830B2670(struct D_830B2670 *p, unsigned v) { struct T_830B2670 t = p->x; t.b = v; *(volatile struct T_830B2670 *)&p->x = t; p->f |= 0x40ull; }

/* Loader_DLL.xex 0x830B26C8 */
struct T_830B26C8 { unsigned a:27; unsigned b:1; unsigned c:4; };
struct D_830B26C8 { char pad[0x10]; ts4l_u64 f; char pad2[0x293c - 0x18]; struct T_830B26C8 x; };
void ts4l_set_bits_mark_dirty_830B26C8(struct D_830B26C8 *p, unsigned v) { struct T_830B26C8 t = p->x; t.b = v; *(volatile struct T_830B26C8 *)&p->x = t; p->f |= 0x200ull; }

/* Loader_DLL.xex 0x830B26F8 */
struct T_830B26F8 { unsigned b:8; unsigned c:24; };
struct D_830B26F8 { char pad[0x10]; ts4l_u64 f; char pad2[0x293c - 0x18]; struct T_830B26F8 x; };
void ts4l_set_bits_mark_dirty_830B26F8(struct D_830B26F8 *p, unsigned v) { struct T_830B26F8 t = p->x; t.b = v; *(volatile struct T_830B26F8 *)&p->x = t; p->f |= 0x200ull; }

/* Loader_DLL.xex 0x830B27D8 */
struct T_830B27D8 { unsigned a:9; unsigned b:3; unsigned c:20; };
struct D_830B27D8 { char pad[0x10]; ts4l_u64 f; char pad2[0x2efc - 0x18]; struct T_830B27D8 x; };
void ts4l_set_bits_mark_dirty_830B27D8(struct D_830B27D8 *p, unsigned v) { struct T_830B27D8 t = p->x; t.b = v; *(volatile struct T_830B27D8 *)&p->x = t; p->f |= 0x20000ull; }

/* Loader_DLL.xex 0x830B2870 */
struct T_830B2870 { unsigned a:28; unsigned b:1; unsigned c:3; };
struct D_830B2870 { char pad[0x10]; ts4l_u64 f; char pad2[0x2940 - 0x18]; struct T_830B2870 x; };
void ts4l_set_bits_mark_dirty_830B2870(struct D_830B2870 *p, unsigned v) { struct T_830B2870 t = p->x; t.b = v; *(volatile struct T_830B2870 *)&p->x = t; p->f |= 0x100ull; }

/* Loader_DLL.xex 0x830B28A0 */
struct T_830B28A0 { unsigned a:29; unsigned b:1; unsigned c:2; };
struct D_830B28A0 { char pad[0x10]; ts4l_u64 f; char pad2[0x2940 - 0x18]; struct T_830B28A0 x; };
void ts4l_set_bits_mark_dirty_830B28A0(struct D_830B28A0 *p, unsigned v) { struct T_830B28A0 t = p->x; t.b = v; *(volatile struct T_830B28A0 *)&p->x = t; p->f |= 0x100ull; }

/* Loader_DLL.xex 0x830B28D0 */
struct T_830B28D0 { unsigned a:26; unsigned b:1; unsigned c:5; };
struct D_830B28D0 { char pad[0x10]; ts4l_u64 f; char pad2[0x2940 - 0x18]; struct T_830B28D0 x; };
void ts4l_set_bits_mark_dirty_830B28D0(struct D_830B28D0 *p, unsigned v) { struct T_830B28D0 t = p->x; t.b = v; *(volatile struct T_830B28D0 *)&p->x = t; p->f |= 0x100ull; }
