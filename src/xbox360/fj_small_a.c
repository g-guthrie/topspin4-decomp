/* Tiny accessor/thunk/initializer functions (Swing_DLL.xex), file fj_small_a.c */
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct Ts4Object { void *vtable; } Ts4Object;
#define W(p,o) (*(u32 *)((char *)(p) + (o)))
#define H(p,o) (*(u16 *)((char *)(p) + (o)))
#define B(p,o) (*(u8 *)((char *)(p) + (o)))
#define D(p,o) (*(u64 *)((char *)(p) + (o)))
#define FL(p,o) (*(float *)((char *)(p) + (o)))
#define LP(p,o) (*(char **)((char *)(p) + (o)))
#define VT(p,s) ((*(void ***)(p))[s])
extern void * lbl_88D45B38;
extern void * fn_88613268(void *, int, int, int, int);
extern void * fn_888CB730(void *);
extern void * fn_887EB298(void *);
extern void * fn_88629B60(void *);
extern void * fn_888DE430(void *);
extern void * fn_887EE810(void *);
extern void * fn_88721D08(void *);
extern void * fn_888CA9A0(void *);
extern void * fn_88773390(void *);
extern void * fn_887732E8(void *);
extern void * fn_888DF9C0(void *);
extern void * fn_887F90F0(void *);
extern void * fn_88795E40(void *);
extern void * fn_888663D0(void *);
extern void * fn_887D2F98(void *);
extern void * fn_88798368(void *);
extern void fn_88614298(char *);
extern void fn_8862E858(char *, int);
extern void fn_88793DA8(char *);
extern void fn_881F5A68(char *, int);
extern void fn_88797798(char *);
extern void fn_88613418(char *);
extern void fn_881B9148(char *);
extern void fn_887ED9F0(char *);
extern void ts4_loop_call_seq_ts4_if_addr_lbl_88D45908_888E7A80_888EE890(char *);
extern void * fn_88951BB8(void *);
extern void * fn_888DF630(void *);
extern void * fn_88951690(void *);
extern void * fn_88772FD8(void *);
extern void * fn_889666A8(void *);
extern void * fn_88850648(void *);
extern void * fn_8896BD28(void *);
extern void * fn_888DDF98(void *);
extern void * fn_8891A388(void *);
extern void * fn_888B0CA8(void *);
extern void * fn_888DF440(void *);
extern void * fn_8872A910(void *);
extern void * fn_888CB860(void *);
extern void * fn_88626840(void *);
extern void * fn_888DE030(void *);
extern void * fn_887F13B8(void *);
extern void * fn_888B92C0(void *);
extern void * fn_888041C0(void *);
extern void * fn_888B0FF8(void *);
extern void * fn_888682F0(void *);
extern void * fn_88887FA0(void *);
extern void * fn_886214A0(void *);
extern void * fn_88866480(void *);
extern void * fn_887CBD40(void *);
extern void * fn_887C85E0(void *);
extern void * fn_88793C60(void *);
extern void fn_88661A70(char *);
extern void ts4_destroy_owned_object(char *);
extern void ts4_tsu_cleanup_begin(char *);
extern char * fn_881519D0(char *);
extern char * fn_8819A098(char *);
extern char lbl_880DC520;
extern void fn_88616160(char *);
extern int fn_8832F930(char *, char **);
extern void fn_8832FC40(char *, char *, int);
extern void fn_8832FD28(char *, char *, int);
extern char lbl_880F908C;
extern void fn_888860A0(char *);
extern char lbl_880F907C;
extern char lbl_880F50FC;
extern char lbl_880F9018;
extern void * lbl_88D41FC0;
extern char * fn_88198CE0(void *);
extern void * lbl_88D45290;
extern void fn_8863F8D0(void *);
extern void * lbl_88D45AF4;
extern void fn_886E0E60(void *);
extern void * lbl_88D45AF8;
extern void fn_886E53F0(void *);
extern int lbl_88D45B14;
extern char * fn_88883CD0(int);
extern void * ts4_find_service(u32);
extern void ts4_object_finalize(char *);
extern void fn_88922B28(char *);
extern void fn_881B1860(void);
extern u32 fn_88836968(int, int, void (*)(void), int, int, u32 *, int);
extern void fn_881B1818(void);
extern u32 fn_88374760(char *, int, int, int, int, int, int, int, int);
extern u32 fn_88374BD8(char *, int, int, int, int, int, int, int, int);
extern char lbl_880F98FC;
extern char lbl_880F9510;
extern void fn_8890DDA8(char *);
extern void fn_8890F1E8(char *);
extern char * g_ts4_session_context;
extern void fn_889A4970(char *);
extern void fn_889A53A8(char *);
extern void fn_88177110(char *);
extern void fn_88912090(char *);
extern char lbl_880F96E0;
extern char lbl_880F9498;
extern char lbl_880F93F8;
extern u32 fn_886328B0(char *);
extern char lbl_880D44A8[];
extern char * fn_8816CF48(char *, char *, char *);
extern void fn_8881C828(u32 *, int, u32);
extern u32 fn_888367F8(int, int, u32 *);
extern u32 fn_888368B0(int, int, u32 *);
extern void fn_887EA320(void);
extern void fn_88563110(int);
extern void fn_887EA6E0(void);
extern u32 fn_881AD020(char *, u32 *);
extern u32 fn_881518D0(char *, u32 *);
extern void fn_8831AD58(char *);
extern void fn_8831AD98(char *);
extern char lbl_880F58C0;
extern char lbl_880F58A8;
extern char lbl_880F46FC;
extern char lbl_880F46F4;
extern char * lbl_88D45AD4;
extern u32 fn_88290568(u32, int, int, int, int);
extern void fn_8857B010(u64 *);
extern void fn_8857AFF0(u64 *);
extern int lbl_88C6E210;
extern u32 fn_882C36E0(void *);
extern u32 fn_882C3628(void *);
extern int lbl_88B310D0;
extern u32 fn_882EBEF0(void *);
extern u32 fn_882EB7C8(void *);
extern u32 fn_882EBF70(void *);
extern u32 fn_882EB938(void *);
extern char lbl_88029418;
extern char lbl_880F4518;
extern char lbl_880D6B70;
extern char lbl_880F5848;
extern void fn_8860BBD8(void *);
extern char lbl_880F4E18;
extern char lbl_88C6ADC8;
extern u32 fn_88891310(char *, int, int, int, int, int);
extern char lbl_88C6ADAC;
extern float g_ts4_script_constants[];
extern u8 lbl_88D429E3;
extern u8 lbl_88D429E2;
extern u8 lbl_88D429E1;
extern u32 fn_888B2CE8(char *, float);
extern u32 fn_888B2838(char *, float);
extern u32 fn_888B2AB0(char *, float);
extern u32 fn_888B24E8(char *, float);
extern char lbl_880D5AA0;
extern char lbl_880D5A64;
extern u32 ts4_lookup_then_forward_88318390(char *);
extern u32 ts4_lookup_then_forward_883183D8(char *);
extern void * lbl_88D45B18;
extern u32 fn_88638188(void *, int, int);
extern char lbl_880D1F18;
extern char * fn_881934E8(char *);
extern char * fn_88193748(char *);
extern u32 fn_8857BA40(char *, int, int, int);
extern u32 fn_88276028(int, int);
extern u32 fn_88888668(int, int);
extern u32 fn_88884DE0(int, int);
extern int NetDll_XNetUnregisterInAddr(int, int);
extern int NetDll_XNetConnect(int, int);
extern int NetDll_XNetGetConnectStatus(int, int);
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif
extern char * lbl_88D45B1C;
extern u32 fn_886C48C8(char *, float);
extern u32 fn_886C4970(char *, float);
extern char * lbl_88D45A4C;
extern char * lbl_88D45A48;
extern char * lbl_88D459E8;
extern char * lbl_88D45A08;
extern u32 fn_888C7AF8(u32);
extern u32 fn_8857BF40(char *, int);
extern void fn_881C38D0(char *);
extern void fn_8890E988(char *);
extern u32 fn_88319C40(int, int, int);
extern u32 fn_88336AD8(int, int, int);
extern u32 fn_887D7D98(int, int, int);
extern u32 fn_884372E0(char *);
extern u32 fn_884AB860(char *);
extern u32 fn_884B2308(char *);
extern char lbl_88C2289C;
extern u32 fn_884A9828(char *);
extern u32 fn_8857A128(u32, int);
extern char lbl_88C476D8;
extern char lbl_88C4763C;
extern void fn_8819C190(char *);
extern u32 fn_8856CAD0(char *);
extern u32 fn_8856C878(char *);
extern u32 fn_88566FE8(char *);
extern u32 fn_88867F10(char *);
extern u32 fn_88334C60(int, int, int, int);
extern u32 fn_88851F00(int, int, int, int);
extern u32 fn_88438270(char *);
extern u32 fn_8843AF20(char *);
extern u32 fn_884A1328(char *);
extern u32 fn_884A14F8(char *);
extern u32 fn_884AA7D8(char *);
extern u32 fn_884B1008(char *);
extern u32 fn_8859F380(char *);
extern u32 fn_8885EDD8(char *);
extern void ts4_if_atomic_interlocked_dec_885949C0(char *);
extern char * fn_88801428(int);
extern u32 fn_8860DBC8(char *);
extern u32 fn_8841B5E0(char *);
extern u32 fn_886917F8(int, int, int);
extern u32 fn_88816C30(int, int, int);
extern char * fn_885643D0(int);
extern u32 fn_888364F8(int, int, u32 *);
extern void fn_884259B8(void);
extern void fn_889D0020(void);
extern void fn_889AC440(void);
extern void fn_889AC4B0(void);
extern void * lbl_88C6CBFC;
extern u32 fn_887961A0(int, void *, int);
extern void * lbl_88C6CBF8;

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88183B38 */
void * ts4_allocate_object_in_global_heap_and_construct_88183B38(void)
{
    void *p = fn_88613268(lbl_88D45B38, 108, 4, 0, 0);
    if (p) return fn_888CB730(p);
    return 0;
}

/* Swing_DLL.xex 0x881BA3D0 */
void * ts4_allocate_object_in_global_heap_and_construct_881BA3D0(void)
{
    void *p = fn_88613268(lbl_88D45B38, 108, 4, 0, 0);
    if (p) return fn_887EB298(p);
    return 0;
}

/* Swing_DLL.xex 0x88285980 */
void * ts4_allocate_object_in_global_heap_and_construct_88285980(void)
{
    void *p = fn_88613268(lbl_88D45B38, 108, 4, 0, 0);
    if (p) return fn_88629B60(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x881842E8 */
void * ts4_allocate_object_in_global_heap_and_construct_881842E8(void)
{
    void *p = fn_88613268(lbl_88D45B38, 100, 4, 0, 0);
    if (p) return fn_888DE430(p);
    return 0;
}

/* Swing_DLL.xex 0x881BA230 */
void * ts4_allocate_object_in_global_heap_and_construct_881BA230(void)
{
    void *p = fn_88613268(lbl_88D45B38, 100, 4, 0, 0);
    if (p) return fn_887EE810(p);
    return 0;
}

/* Swing_DLL.xex 0x88235728 */
void * ts4_allocate_object_in_global_heap_and_construct_88235728(void)
{
    void *p = fn_88613268(lbl_88D45B38, 100, 4, 0, 0);
    if (p) return fn_88721D08(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88184448 */
void * ts4_allocate_object_in_global_heap_and_construct_88184448(void)
{
    void *p = fn_88613268(lbl_88D45B38, 96, 4, 0, 0);
    if (p) return fn_888CA9A0(p);
    return 0;
}

/* Swing_DLL.xex 0x8821A248 */
void * ts4_allocate_object_in_global_heap_and_construct_8821A248(void)
{
    void *p = fn_88613268(lbl_88D45B38, 96, 4, 0, 0);
    if (p) return fn_88773390(p);
    return 0;
}

/* Swing_DLL.xex 0x8821A2F8 */
void * ts4_allocate_object_in_global_heap_and_construct_8821A2F8(void)
{
    void *p = fn_88613268(lbl_88D45B38, 96, 4, 0, 0);
    if (p) return fn_887732E8(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88185278 */
void * ts4_allocate_object_in_global_heap_and_construct_88185278(void)
{
    void *p = fn_88613268(lbl_88D45B38, 84, 4, 0, 0);
    if (p) return fn_888DF9C0(p);
    return 0;
}

/* Swing_DLL.xex 0x881B7F10 */
void * ts4_allocate_object_in_global_heap_and_construct_881B7F10(void)
{
    void *p = fn_88613268(lbl_88D45B38, 84, 4, 0, 0);
    if (p) return fn_887F90F0(p);
    return 0;
}

/* Swing_DLL.xex 0x882174C0 */
void * ts4_allocate_object_in_global_heap_and_construct_882174C0(void)
{
    void *p = fn_88613268(lbl_88D45B38, 84, 4, 0, 0);
    if (p) return fn_88795E40(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x881AC190 */
void * ts4_allocate_object_in_global_heap_and_construct_881AC190(void)
{
    void *p = fn_88613268(lbl_88D45B38, 56, 4, 0, 0);
    if (p) return fn_888663D0(p);
    return 0;
}

/* Swing_DLL.xex 0x881BC760 */
void * ts4_allocate_object_in_global_heap_and_construct_881BC760(void)
{
    void *p = fn_88613268(lbl_88D45B38, 56, 4, 0, 0);
    if (p) return fn_887D2F98(p);
    return 0;
}

/* Swing_DLL.xex 0x88217060 */
void * ts4_allocate_object_in_global_heap_and_construct_88217060(void)
{
    void *p = fn_88613268(lbl_88D45B38, 56, 4, 0, 0);
    if (p) return fn_88798368(p);
    return 0;
}

/* call_two_with_this_then_arg */
/* Swing_DLL.xex 0x8862E9C8 */
void ts4_call_two_with_this_then_arg_8862E9C8(char *a, int b)
{
    fn_88614298(a);
    fn_8862E858(a, b);
}

/* Swing_DLL.xex 0x887A19F0 */
void ts4_call_two_with_this_then_arg_887A19F0(char *a, int b)
{
    fn_88793DA8(a);
    fn_881F5A68(a, b);
}

/* Swing_DLL.xex 0x887A1A38 */
void ts4_call_two_with_this_then_arg_887A1A38(char *a, int b)
{
    fn_88797798(a);
    fn_881F5A68(a, b);
}

/* init_base_then_clear_byte8_then_sub16 */
/* Swing_DLL.xex 0x88618A78 */
void ts4_init_base_then_clear_byte8_then_sub16_88618A78(char *a)
{
    fn_88613418(a);
    B(a, 8) = 0;
    fn_881B9148(a + 16);
}

/* Swing_DLL.xex 0x887EE3F0 */
void ts4_init_base_then_clear_byte8_then_sub16_887EE3F0(char *a)
{
    fn_887ED9F0(a);
    B(a, 8) = 0;
    fn_881B9148(a + 16);
}

/* Swing_DLL.xex 0x888F1DC8 */
void ts4_init_base_then_clear_byte8_then_sub16_888F1DC8(char *a)
{
    ts4_loop_call_seq_ts4_if_addr_lbl_88D45908_888E7A80_888EE890(a);
    B(a, 8) = 0;
    fn_881B9148(a + 16);
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88167C58 */
void * ts4_allocate_object_in_global_heap_and_construct_88167C58(void)
{
    void *p = fn_88613268(lbl_88D45B38, 236, 4, 0, 2);
    if (p) return fn_88951BB8(p);
    return 0;
}

/* Swing_DLL.xex 0x88182F30 */
void * ts4_allocate_object_in_global_heap_and_construct_88182F30(void)
{
    void *p = fn_88613268(lbl_88D45B38, 236, 4, 0, 2);
    if (p) return fn_888DF630(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88167E68 */
void * ts4_allocate_object_in_global_heap_and_construct_88167E68(void)
{
    void *p = fn_88613268(lbl_88D45B38, 88, 4, 0, 2);
    if (p) return fn_88951690(p);
    return 0;
}

/* Swing_DLL.xex 0x8821A4B0 */
void * ts4_allocate_object_in_global_heap_and_construct_8821A4B0(void)
{
    void *p = fn_88613268(lbl_88D45B38, 88, 4, 0, 2);
    if (p) return fn_88772FD8(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88168788 */
void * ts4_allocate_object_in_global_heap_and_construct_88168788(void)
{
    void *p = fn_88613268(lbl_88D45B38, 112, 4, 0, 2);
    if (p) return fn_889666A8(p);
    return 0;
}

/* Swing_DLL.xex 0x881AF408 */
void * ts4_allocate_object_in_global_heap_and_construct_881AF408(void)
{
    void *p = fn_88613268(lbl_88D45B38, 112, 4, 0, 2);
    if (p) return fn_88850648(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88168A98 */
void * ts4_allocate_object_in_global_heap_and_construct_88168A98(void)
{
    void *p = fn_88613268(lbl_88D45B38, 120, 4, 0, 2);
    if (p) return fn_8896BD28(p);
    return 0;
}

/* Swing_DLL.xex 0x88184B70 */
void * ts4_allocate_object_in_global_heap_and_construct_88184B70(void)
{
    void *p = fn_88613268(lbl_88D45B38, 120, 4, 0, 2);
    if (p) return fn_888DDF98(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88173100 */
void * ts4_allocate_object_in_global_heap_and_construct_88173100(void)
{
    void *p = fn_88613268(lbl_88D45B38, 244, 4, 0, 2);
    if (p) return fn_8891A388(p);
    return 0;
}

/* Swing_DLL.xex 0x88189190 */
void * ts4_allocate_object_in_global_heap_and_construct_88189190(void)
{
    void *p = fn_88613268(lbl_88D45B38, 244, 4, 0, 2);
    if (p) return fn_888B0CA8(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88183330 */
void * ts4_allocate_object_in_global_heap_and_construct_88183330(void)
{
    void *p = fn_88613268(lbl_88D45B38, 104, 4, 0, 2);
    if (p) return fn_888DF440(p);
    return 0;
}

/* Swing_DLL.xex 0x88235620 */
void * ts4_allocate_object_in_global_heap_and_construct_88235620(void)
{
    void *p = fn_88613268(lbl_88D45B38, 104, 4, 0, 2);
    if (p) return fn_8872A910(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88183A30 */
void * ts4_allocate_object_in_global_heap_and_construct_88183A30(void)
{
    void *p = fn_88613268(lbl_88D45B38, 160, 4, 0, 2);
    if (p) return fn_888CB860(p);
    return 0;
}

/* Swing_DLL.xex 0x882848F8 */
void * ts4_allocate_object_in_global_heap_and_construct_882848F8(void)
{
    void *p = fn_88613268(lbl_88D45B38, 160, 4, 0, 2);
    if (p) return fn_88626840(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88184960 */
void * ts4_allocate_object_in_global_heap_and_construct_88184960(void)
{
    void *p = fn_88613268(lbl_88D45B38, 272, 4, 0, 2);
    if (p) return fn_888DE030(p);
    return 0;
}

/* Swing_DLL.xex 0x881B8AB8 */
void * ts4_allocate_object_in_global_heap_and_construct_881B8AB8(void)
{
    void *p = fn_88613268(lbl_88D45B38, 272, 4, 0, 2);
    if (p) return fn_887F13B8(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88188B48 */
void * ts4_allocate_object_in_global_heap_and_construct_88188B48(void)
{
    void *p = fn_88613268(lbl_88D45B38, 184, 4, 0, 2);
    if (p) return fn_888B92C0(p);
    return 0;
}

/* Swing_DLL.xex 0x881B2FD0 */
void * ts4_allocate_object_in_global_heap_and_construct_881B2FD0(void)
{
    void *p = fn_88613268(lbl_88D45B38, 184, 4, 0, 2);
    if (p) return fn_888041C0(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x881890E0 */
void * ts4_allocate_object_in_global_heap_and_construct_881890E0(void)
{
    void *p = fn_88613268(lbl_88D45B38, 172, 4, 0, 2);
    if (p) return fn_888B0FF8(p);
    return 0;
}

/* Swing_DLL.xex 0x881AC298 */
void * ts4_allocate_object_in_global_heap_and_construct_881AC298(void)
{
    void *p = fn_88613268(lbl_88D45B38, 172, 4, 0, 2);
    if (p) return fn_888682F0(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88189418 */
void * ts4_allocate_object_in_global_heap_and_construct_88189418(void)
{
    void *p = fn_88613268(lbl_88D45B38, 184, 4, 0, 0);
    if (p) return fn_888B92C0(p);
    return 0;
}

/* Swing_DLL.xex 0x881B3028 */
void * ts4_allocate_object_in_global_heap_and_construct_881B3028(void)
{
    void *p = fn_88613268(lbl_88D45B38, 184, 4, 0, 0);
    if (p) return fn_888041C0(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x881A5CF8 */
void * ts4_allocate_object_in_global_heap_and_construct_881A5CF8(void)
{
    void *p = fn_88613268(lbl_88D45B38, 552, 4, 0, 0);
    if (p) return fn_88887FA0(p);
    return 0;
}

/* Swing_DLL.xex 0x88284A00 */
void * ts4_allocate_object_in_global_heap_and_construct_88284A00(void)
{
    void *p = fn_88613268(lbl_88D45B38, 552, 4, 0, 0);
    if (p) return fn_886214A0(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x881AC0E0 */
void * ts4_allocate_object_in_global_heap_and_construct_881AC0E0(void)
{
    void *p = fn_88613268(lbl_88D45B38, 32, 4, 0, 0);
    if (p) return fn_88866480(p);
    return 0;
}

/* Swing_DLL.xex 0x88211E28 */
void * ts4_allocate_object_in_global_heap_and_construct_88211E28(void)
{
    void *p = fn_88613268(lbl_88D45B38, 32, 4, 0, 0);
    if (p) return fn_887CBD40(p);
    return 0;
}

/* allocate_object_in_global_heap_and_construct */
/* Swing_DLL.xex 0x88212208 */
void * ts4_allocate_object_in_global_heap_and_construct_88212208(void)
{
    void *p = fn_88613268(lbl_88D45B38, 204, 4, 0, 0);
    if (p) return fn_887C85E0(p);
    return 0;
}

/* Swing_DLL.xex 0x882172E0 */
void * ts4_allocate_object_in_global_heap_and_construct_882172E0(void)
{
    void *p = fn_88613268(lbl_88D45B38, 204, 4, 0, 0);
    if (p) return fn_88793C60(p);
    return 0;
}

/* dtor_base_then_destroy_fields_12_0 */
/* Swing_DLL.xex 0x886A1088 */
void ts4_dtor_base_then_destroy_fields_12_0_886A1088(char *a)
{
    fn_88661A70(a);
    if (W(a, 12)) ts4_destroy_owned_object(LP(a, 12));
    if (W(a, 0)) ts4_destroy_owned_object(LP(a, 0));
}

/* Swing_DLL.xex 0x8878A1F0 */
void ts4_dtor_base_then_destroy_fields_12_0_8878A1F0(char *a)
{
    ts4_tsu_cleanup_begin(a);
    if (W(a, 12)) ts4_destroy_owned_object(LP(a, 12));
    if (W(a, 0)) ts4_destroy_owned_object(LP(a, 0));
}

/* set_field0_to_vcall_result_plus_16 */
/* Swing_DLL.xex 0x88187858 */
char * ts4_set_field0_to_vcall_result_plus_16_88187858(char *a)
{
    char *o = fn_881519D0(a);
    char *r = ((char *(*)(char *))VT(o, 4))(o);
    W(a, 0) = (u32)(r + 16);
    return a;
}

/* Swing_DLL.xex 0x8819AD38 */
char * ts4_set_field0_to_vcall_result_plus_16_8819AD38(char *a)
{
    char *o = fn_8819A098(a);
    char *r = ((char *(*)(char *))VT(o, 4))(o);
    W(a, 0) = (u32)(r + 16);
    return a;
}

/* dtor_set_vtable_base_destroy_field4 */
/* Swing_DLL.xex 0x88188868 */
void ts4_dtor_set_vtable_base_destroy_field4_88188868(char *a)
{
    *(void **)a = &lbl_880DC520;
    fn_88616160(a);
    if (W(a, 4)) ts4_destroy_owned_object(LP(a, 4));
}

/* Swing_DLL.xex 0x88629068 */
void ts4_dtor_set_vtable_base_destroy_field4_88629068(char *a)
{
    *(void **)a = &lbl_880DC520;
    fn_88616160(a);
    if (W(a, 4)) ts4_destroy_owned_object(LP(a, 4));
}

/* call_then_conditionally_forward_result */
/* Swing_DLL.xex 0x88317B90 */
void ts4_call_then_conditionally_forward_result_88317B90(char *a, char *b)
{
    char *v;
    if (fn_8832F930(a, &v) == 0) fn_8832FC40(v, b, 1);
}

/* Swing_DLL.xex 0x88317BD8 */
void ts4_call_then_conditionally_forward_result_88317BD8(char *a, char *b)
{
    char *v;
    if (fn_8832F930(a, &v) == 0) fn_8832FD28(v, b, 1);
}

/* dtor_two_vtables_with_call */
/* Swing_DLL.xex 0x886059B8 */
void ts4_dtor_two_vtables_with_call_886059B8(char *a)
{
    *(void **)a = &lbl_880F908C;
    fn_888860A0(LP(a, 4));
    *(void **)a = &lbl_880F907C;
}

/* Swing_DLL.xex 0x886575A8 */
void ts4_dtor_two_vtables_with_call_886575A8(char *a)
{
    *(void **)a = &lbl_880F50FC;
    fn_888860A0(LP(a, 4));
    *(void **)a = &lbl_880F9018;
}

/* call_wrapped_around_lookup */
/* Swing_DLL.xex 0x8863FB58 */
void ts4_call_wrapped_around_lookup_8863FB58(void)
{
    char *r = fn_88198CE0(lbl_88D41FC0);
    fn_8863F8D0(lbl_88D45290);
    fn_88198CE0(r);
}

/* Swing_DLL.xex 0x8863FBA8 */
void ts4_call_wrapped_around_lookup_8863FBA8(void)
{
    char *r = fn_88198CE0(lbl_88D41FC0);
    fn_8863F8D0(lbl_88D45290);
    fn_88198CE0(r);
}

/* call_if_global_set_twice */
/* Swing_DLL.xex 0x886E37D0 */
void ts4_call_if_global_set_twice_886E37D0(void)
{
    if (lbl_88D45AF4) fn_886E0E60(lbl_88D45AF4);
    if (lbl_88D45AF8) fn_886E0E60(lbl_88D45AF8);
}

/* Swing_DLL.xex 0x886E6198 */
void ts4_call_if_global_set_twice_886E6198(void)
{
    if (lbl_88D45AF4) fn_886E53F0(lbl_88D45AF4);
    if (lbl_88D45AF8) fn_886E53F0(lbl_88D45AF8);
}

/* deref_result_of_global_lookup */
/* Swing_DLL.xex 0x8863A418 */
u32 ts4_deref_result_of_global_lookup_8863A418(void)
{
    return W(fn_88883CD0(lbl_88D45B14), 0);
}

/* Swing_DLL.xex 0x8863A4E8 */
u32 ts4_deref_result_of_global_lookup_8863A4E8(void)
{
    return W(fn_88883CD0(lbl_88D45B14), 0);
}

/* Swing_DLL.xex 0x8863A570 */
u32 ts4_deref_result_of_global_lookup_8863A570(void)
{
    return W(fn_88883CD0(lbl_88D45B14), 0);
}

/* find_service_by_hash_return_zero */
/* Swing_DLL.xex 0x887799C0 */
u32 ts4_find_service_by_hash_return_zero_887799C0(void)
{
    ts4_find_service(0xFB595DB2);
    return 0;
}

/* Swing_DLL.xex 0x887799F0 */
u32 ts4_find_service_by_hash_return_zero_887799F0(void)
{
    ts4_find_service(0xFB595DB2);
    return 0;
}

/* Swing_DLL.xex 0x88779A20 */
u32 ts4_find_service_by_hash_return_zero_88779A20(void)
{
    ts4_find_service(0xFB595DB2);
    return 0;
}

/* call_field8_vtable_slot6 */
/* Swing_DLL.xex 0x884D11F8 */
char * ts4_call_field8_vtable_slot6_884D11F8(char *a, char *b)
{
    char *o = LP(b, 8);
    ((void (*)(char *, char *))VT(o, 6))(a, o);
    return a;
}

/* Swing_DLL.xex 0x885ED678 */
char * ts4_call_field8_vtable_slot6_885ED678(char *a, char *b)
{
    char *o = LP(b, 8);
    ((void (*)(char *, char *))VT(o, 6))(a, o);
    return a;
}

/* call_vtable_slot13_of_second_arg */
/* Swing_DLL.xex 0x88608D70 */
char * ts4_call_vtable_slot13_of_second_arg_88608D70(char *a, char *b, int c, int d, int e, int f)
{
    ((void (*)(char *, char *, int, int, int))VT(b, 13))(a, b, c, d, f);
    return a;
}

/* Swing_DLL.xex 0x88884658 */
char * ts4_call_vtable_slot13_of_second_arg_88884658(char *a, char *b, int c, int d, int e, int f)
{
    ((void (*)(char *, char *, int, int, int))VT(b, 13))(a, b, c, d, f);
    return a;
}

/* count_nonzero_words */
/* Swing_DLL.xex 0x884C5580 */
u32 ts4_count_nonzero_words_884C5580(u32 *a)
{
    u32 n = 0;
    while (a[n]) n++;
    return n;
}

/* Swing_DLL.xex 0x884CCED0 */
u32 ts4_count_nonzero_words_884CCED0(u32 *a)
{
    u32 n = 0;
    while (a[n]) n++;
    return n;
}

/* Swing_DLL.xex 0x884CCEF8 */
u32 ts4_count_nonzero_words_884CCEF8(u32 *a)
{
    u32 n = 0;
    while (a[n]) n++;
    return n;
}

/* finalize_then_destroy_owned_field0 */
/* Swing_DLL.xex 0x88627A90 */
void ts4_finalize_then_destroy_owned_field0_88627A90(char *a)
{
    ts4_object_finalize(a);
    if (W(a, 0)) ts4_destroy_owned_object(LP(a, 0));
}

/* Swing_DLL.xex 0x889285F8 */
void ts4_finalize_then_destroy_owned_field0_889285F8(char *a)
{
    fn_88922B28(a);
    if (W(a, 0)) ts4_destroy_owned_object(LP(a, 0));
}

/* call_with_callback_and_local_word */
/* Swing_DLL.xex 0x88836B28 */
u32 ts4_call_with_callback_and_local_word_88836B28(int a, int b, u32 c)
{
    return fn_88836968(a, b, fn_881B1860, 0, 0, &c, 4);
}

/* Swing_DLL.xex 0x88836B68 */
u32 ts4_call_with_callback_and_local_word_88836B68(int a, int b, u32 c)
{
    return fn_88836968(a, b, fn_881B1818, 0, 0, &c, 4);
}

/* adjust_this_minus_28_forward_9_args */
/* Swing_DLL.xex 0x88374908 */
u32 ts4_adjust_this_minus_28_forward_9_args_88374908(char *a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    char *p = a ? a - 28 : 0;
    return fn_88374760(p, b, c, d, e, f, g, h, i);
}

/* Swing_DLL.xex 0x88374D80 */
u32 ts4_adjust_this_minus_28_forward_9_args_88374D80(char *a, int b, int c, int d, int e, int f, int g, int h, int i)
{
    char *p = a ? a - 28 : 0;
    return fn_88374BD8(p, b, c, d, e, f, g, h, i);
}

/* find_char_in_string */
/* Swing_DLL.xex 0x88514D18 */
char * ts4_find_char_in_string_88514D18(char *a, int b)
{
    char c = (char)b;
    while (*a != c) {
        if (*a == 0) return 0;
        a++;
    }
    return a;
}

/* Swing_DLL.xex 0x885156B0 */
char * ts4_find_char_in_string_885156B0(char *a, int b)
{
    char c = (char)b;
    while (*a != c) {
        if (*a == 0) return 0;
        a++;
    }
    return a;
}

/* init_vtable_object_with_fields */
/* Swing_DLL.xex 0x885F9B98 */
void ts4_init_vtable_object_with_fields_885F9B98(char *a, u8 b, u8 c)
{
    B(a, 10) = b;
    B(a, 11) = c;
    W(a, 4) = 0;
    *(void **)a = &lbl_880F98FC;
    H(a, 8) = 0;
    H(a, 12) = 0;
    H(a, 14) = 0;
    H(a, 16) = 0;
    W(a, 20) = 0;
    W(a, 24) = 0;
}

/* Swing_DLL.xex 0x88601668 */
void ts4_init_vtable_object_with_fields_88601668(char *a, u8 b, u8 c)
{
    B(a, 10) = b;
    B(a, 11) = c;
    W(a, 4) = 0;
    *(void **)a = &lbl_880F9510;
    H(a, 8) = 0;
    H(a, 12) = 0;
    H(a, 14) = 0;
    H(a, 16) = 0;
    W(a, 20) = 0;
    W(a, 24) = 0;
}

/* call_on_subobject_then_self */
/* Swing_DLL.xex 0x88662DB8 */
void ts4_call_on_subobject_then_self_88662DB8(char *a)
{
    fn_8890DDA8(a + 0x44);
    fn_8890DDA8(a);
}

/* Swing_DLL.xex 0x88695D40 */
void ts4_call_on_subobject_then_self_88695D40(char *a)
{
    fn_8890F1E8(a + 0x44);
    fn_8890F1E8(a);
}

/* call_on_session_field28_if_set_return_zero */
/* Swing_DLL.xex 0x88787590 */
u32 ts4_call_on_session_field28_if_set_return_zero_88787590(void)
{
    char *p = LP(g_ts4_session_context, 0x1c);
    if (p) fn_889A4970(p);
    return 0;
}

/* Swing_DLL.xex 0x887876E0 */
u32 ts4_call_on_session_field28_if_set_return_zero_887876E0(void)
{
    char *p = LP(g_ts4_session_context, 0x1c);
    if (p) fn_889A53A8(p);
    return 0;
}

/* call_on_subobject8_then_self */
/* Swing_DLL.xex 0x887982D0 */
void ts4_call_on_subobject8_then_self_887982D0(char *a)
{
    fn_88177110(a + 8);
    fn_88912090(a);
}

/* Swing_DLL.xex 0x88912A00 */
void ts4_call_on_subobject8_then_self_88912A00(char *a)
{
    fn_88177110(a + 8);
    fn_88912090(a);
}

/* init_vtable_object_with_two_bytes */
/* Swing_DLL.xex 0x885FAC98 */
void ts4_init_vtable_object_with_two_bytes_885FAC98(char *a, u8 b, u8 c)
{
    B(a, 10) = b;
    B(a, 11) = c;
    W(a, 4) = 0;
    *(void **)a = &lbl_880F96E0;
    H(a, 8) = 0;
}

/* Swing_DLL.xex 0x88601BC0 */
void ts4_init_vtable_object_with_two_bytes_88601BC0(char *a, u8 b, u8 c)
{
    B(a, 10) = b;
    B(a, 11) = c;
    W(a, 4) = 0;
    *(void **)a = &lbl_880F9498;
    H(a, 8) = 0;
}

/* Swing_DLL.xex 0x88603E50 */
void ts4_init_vtable_object_with_two_bytes_88603E50(char *a, u8 b, u8 c)
{
    B(a, 10) = b;
    B(a, 11) = c;
    W(a, 4) = 0;
    *(void **)a = &lbl_880F93F8;
    H(a, 8) = 0;
}

/* key_matches_chain_or_constant */
/* Swing_DLL.xex 0x88269E30 */
void ts4_key_matches_chain_or_constant_88269E30(char *a, u32 key, u8 *out)
{
    *out = (key == W(LP(LP(a, 24), 116), 0x364) || key == 0x5BE8962F);
}

/* Swing_DLL.xex 0x88660E90 */
void ts4_key_matches_chain_or_constant_88660E90(char *a, u32 key, u8 *out)
{
    *out = (key == W(LP(LP(a, 24), 116), 0x364) || key == 0x5BE8962F);
}

/* scale_four_floats */
/* Swing_DLL.xex 0x88516E00 */
void ts4_scale_four_floats_88516E00(float *a, float s)
{
    a[0] = a[0] * s;
    a[1] = a[1] * s;
    a[2] = a[2] * s;
    a[3] = a[3] * s;
}

/* Swing_DLL.xex 0x8864E278 */
void ts4_scale_four_floats_8864E278(float *a, float s)
{
    a[0] = a[0] * s;
    a[1] = a[1] * s;
    a[2] = a[2] * s;
    a[3] = a[3] * s;
}

/* find_pointer_entry_by_field4 */
/* Swing_DLL.xex 0x88933248 */
char * ts4_find_pointer_entry_by_field4_88933248(char *a, int key)
{
    char **end = (char **)LP(a, 8);
    char **p = (char **)LP(a, 4);
    for (; p != end; p++) {
        char *o = *p;
        if (key == (int)W(o, 4)) return o;
    }
    return 0;
}

/* Swing_DLL.xex 0x88933280 */
char * ts4_find_pointer_entry_by_field4_88933280(char *a, int key)
{
    char **end = (char **)LP(a, 8);
    char **p = (char **)LP(a, 4);
    for (; p != end; p++) {
        char *o = *p;
        if (key == (int)W(o, 4)) return o;
    }
    return 0;
}

/* set_pair_by_signed_flag */
/* Swing_DLL.xex 0x88478AB0 */
void ts4_set_pair_by_signed_flag_88478AB0(int a, signed char b, u32 *out)
{
    if (b) {
        out[1] = 3;
        out[0] = 24;
    } else {
        out[0] = 0;
        out[1] = 0;
    }
}

/* Swing_DLL.xex 0x88482A58 */
void ts4_set_pair_by_signed_flag_88482A58(int a, signed char b, u32 *out)
{
    if (b) {
        out[1] = 3;
        out[0] = 24;
    } else {
        out[0] = 0;
        out[1] = 0;
    }
}

/* offset_ptr_or_one */
/* Swing_DLL.xex 0x886329F8 */
u32 ts4_offset_ptr_or_one_886329F8(char *a)
{
    int o = *(int *)a;
    u32 r = 1;
    if (o != -1) r = fn_886328B0(a + o);
    return r;
}

/* Swing_DLL.xex 0x887DF370 */
u32 ts4_offset_ptr_or_one_887DF370(char *a)
{
    int o = *(int *)a;
    u32 r = 1;
    if (o != -1) r = fn_886328B0(a + o);
    return r;
}

/* Swing_DLL.xex 0x887E0520 */
u32 ts4_offset_ptr_or_one_887E0520(char *a)
{
    int o = *(int *)a;
    u32 r = 1;
    if (o != -1) r = fn_886328B0(a + o);
    return r;
}

/* skip_if_dot_before_cursor_else_call */
/* Swing_DLL.xex 0x88713850 */
char * ts4_skip_if_dot_before_cursor_else_call_88713850(char *a)
{
    char *p = LP(a, 4);
    if (B(p, -4) == 0x2e) return a;
    if (B(p, -5) == 0x2e) return a;
    return fn_8816CF48(a, lbl_880D44A8, lbl_880D44A8 + 4);
}

/* Swing_DLL.xex 0x88714650 */
char * ts4_skip_if_dot_before_cursor_else_call_88714650(char *a)
{
    char *p = LP(a, 4);
    if (B(p, -4) == 0x2e) return a;
    if (B(p, -5) == 0x2e) return a;
    return fn_8816CF48(a, lbl_880D44A8, lbl_880D44A8 + 4);
}

/* call_with_address_of_arg_and_4 */
/* Swing_DLL.xex 0x8881C9A0 */
void ts4_call_with_address_of_arg_and_4_8881C9A0(u32 a, u32 b)
{
    fn_8881C828(&a, 4, b);
}

/* Swing_DLL.xex 0x8881C9D0 */
void ts4_call_with_address_of_arg_and_4_8881C9D0(u32 a, u32 b)
{
    fn_8881C828(&a, 4, b);
}

/* call_with_local_tag2_record */
/* Swing_DLL.xex 0x88837018 */
u32 ts4_call_with_local_tag2_record_88837018(int a, int b, u32 c)
{
    u32 rec[3];
    rec[0] = 2;
    rec[2] = c;
    return fn_888367F8(a, b, rec);
}

/* Swing_DLL.xex 0x88837050 */
u32 ts4_call_with_local_tag2_record_88837050(int a, int b, u32 c)
{
    u32 rec[3];
    rec[0] = 2;
    rec[2] = c;
    return fn_888368B0(a, b, rec);
}

/* pop_u16_from_buffer */
/* Swing_DLL.xex 0x88603C68 */
int ts4_pop_u16_from_buffer_88603C68(u16 *a, u16 *b, u32 *c)
{
    u32 n = *c;
    if (n < 2) return -1;
    {
        u16 v = *a;
        *c = n - 2;
        *b = v;
        return 2;
    }
}

/* Swing_DLL.xex 0x88603CF8 */
int ts4_pop_u16_from_buffer_88603CF8(u16 *a, u16 *b, u32 *c)
{
    u32 n = *c;
    if (n < 2) return -1;
    {
        u16 v = *a;
        *c = n - 2;
        *b = v;
        return 2;
    }
}

/* call_twice_chained_on_global */
/* Swing_DLL.xex 0x8863C038 */
void ts4_call_twice_chained_on_global_8863C038(void)
{
    fn_88198CE0(fn_88198CE0(lbl_88D41FC0));
}

/* Swing_DLL.xex 0x8863C640 */
void ts4_call_twice_chained_on_global_8863C640(void)
{
    fn_88198CE0(fn_88198CE0(lbl_88D41FC0));
}

/* call_then_call_zero_return_zero */
/* Swing_DLL.xex 0x887EB348 */
u32 ts4_call_then_call_zero_return_zero_887EB348(void)
{
    fn_887EA320();
    fn_88563110(0);
    return 0;
}

/* Swing_DLL.xex 0x887EC638 */
u32 ts4_call_then_call_zero_return_zero_887EC638(void)
{
    fn_887EA6E0();
    fn_88563110(0);
    return 0;
}

/* call_field28_with_address_of_arg */
/* Swing_DLL.xex 0x88841CE0 */
u32 ts4_call_field28_with_address_of_arg_88841CE0(char *a, u32 b)
{
    return fn_881AD020(LP(a, 28), &b);
}

/* Swing_DLL.xex 0x88928AF0 */
u32 ts4_call_field28_with_address_of_arg_88928AF0(char *a, u32 b)
{
    return fn_881518D0(LP(a, 28), &b);
}

/* call_field4352_return_zero */
/* Swing_DLL.xex 0x8830C0B8 */
u32 ts4_call_field4352_return_zero_8830C0B8(char *a)
{
    fn_8831AD58(LP(a, 0x1100));
    return 0;
}

/* Swing_DLL.xex 0x8830C0E0 */
u32 ts4_call_field4352_return_zero_8830C0E0(char *a)
{
    fn_8831AD98(LP(a, 0x1100));
    return 0;
}

/* init_vtable_zero_fields_4_to_20 */
/* Swing_DLL.xex 0x8864F398 */
void ts4_init_vtable_zero_fields_4_to_20_8864F398(char *a)
{
    W(a, 4) = 0;
    *(void **)a = &lbl_880F58C0;
    W(a, 12) = 0;
    W(a, 8) = 0;
    W(a, 16) = 0;
    W(a, 20) = 0;
}

/* Swing_DLL.xex 0x8864F3E0 */
void ts4_init_vtable_zero_fields_4_to_20_8864F3E0(char *a)
{
    W(a, 4) = 0;
    *(void **)a = &lbl_880F58A8;
    W(a, 12) = 0;
    W(a, 8) = 0;
    W(a, 16) = 0;
    W(a, 20) = 0;
}

/* init_vtable_zero_fields_4_to_24 */
/* Swing_DLL.xex 0x88670298 */
void ts4_init_vtable_zero_fields_4_to_24_88670298(char *a)
{
    W(a, 4) = 0;
    *(void **)a = &lbl_880F46FC;
    W(a, 8) = 0;
    W(a, 12) = 0;
    W(a, 16) = 0;
    W(a, 24) = 0;
}

/* Swing_DLL.xex 0x886702F0 */
void ts4_init_vtable_zero_fields_4_to_24_886702F0(char *a)
{
    W(a, 4) = 0;
    *(void **)a = &lbl_880F46F4;
    W(a, 8) = 0;
    W(a, 12) = 0;
    W(a, 16) = 0;
    W(a, 24) = 0;
}

/* call_with_global_field_b1_and_arg */
/* Swing_DLL.xex 0x886F70E8 */
u32 ts4_call_with_global_field_b1_and_arg_886F70E8(int a)
{
    return fn_88290568(W(lbl_88D45AD4, 0x15720), 0xb1, a, 4, 0xC0000);
}

/* Swing_DLL.xex 0x886F7998 */
u32 ts4_call_with_global_field_b1_and_arg_886F7998(int a)
{
    return fn_88290568(W(lbl_88D45AD4, 0x15720), 0xb1, a, 4, 0xC0000);
}

/* index_table_entry_stride_12 */
/* Swing_DLL.xex 0x887F74F8 */
char * ts4_index_table_entry_stride_12_887F74F8(char *a, u32 i)
{
    char *p = LP(LP(a, 28), 32) + 0x54;
    return p + W(p, 0) + i * 12;
}

/* Swing_DLL.xex 0x887F7520 */
char * ts4_index_table_entry_stride_12_887F7520(char *a, u32 i)
{
    char *p = LP(LP(a, 28), 32) + 0x54;
    return p + W(p, 0) + i * 12;
}

/* call_with_out_u64_return_it */
/* Swing_DLL.xex 0x88883BE8 */
u64 ts4_call_with_out_u64_return_it_88883BE8(void)
{
    u64 v;
    fn_8857B010(&v);
    return v;
}

/* Swing_DLL.xex 0x88883C10 */
u64 ts4_call_with_out_u64_return_it_88883C10(void)
{
    u64 v;
    fn_8857AFF0(&v);
    return v;
}

/* dispatch_on_global_flag */
/* Swing_DLL.xex 0x882C38D8 */
u32 ts4_dispatch_on_global_flag_882C38D8(void *a)
{
    if (lbl_88C6E210) return fn_882C36E0(a);
    return fn_882C3628(a);
}

/* Swing_DLL.xex 0x882EC0B0 */
u32 ts4_dispatch_on_global_flag_882EC0B0(void *a)
{
    if (lbl_88B310D0) return fn_882EBEF0(a);
    return fn_882EB7C8(a);
}

/* Swing_DLL.xex 0x882EC0C8 */
u32 ts4_dispatch_on_global_flag_882EC0C8(void *a)
{
    if (lbl_88B310D0) return fn_882EBF70(a);
    return fn_882EB938(a);
}

/* init_vtable_zero_field8 */
/* Swing_DLL.xex 0x88334420 */
void ts4_init_vtable_zero_field8_88334420(char *a)
{
    W(a, 8) = 0;
    *(void **)a = &lbl_88029418;
}

/* Swing_DLL.xex 0x88659DD0 */
void ts4_init_vtable_zero_field8_88659DD0(char *a)
{
    W(a, 8) = 0;
    *(void **)a = &lbl_880F4518;
}

/* Swing_DLL.xex 0x8876D0B8 */
void ts4_init_vtable_zero_field8_8876D0B8(char *a)
{
    W(a, 8) = 0;
    *(void **)a = &lbl_880D6B70;
}

/* extract_bits_5_4_of_byte38_or_zero */
/* Swing_DLL.xex 0x88473FC0 */
void ts4_extract_bits_5_4_of_byte38_or_zero_88473FC0(u8 *a, char *b)
{
    int p = (int)W(b, 0xb8);
    if (p == 0) {
        *a = 0;
        return;
    }
    *a = (B((char *)p, 0x26) >> 4) & 3;
}

/* Swing_DLL.xex 0x88473FE8 */
void ts4_extract_bits_5_4_of_byte38_or_zero_88473FE8(u8 *a, char *b)
{
    int p = (int)W(b, 0xb8);
    if (p == 0) {
        *a = 0;
        return;
    }
    *a = (B((char *)p, 0x26) >> 4) & 3;
}

/* init_vtable_zero_field8_call_base */
/* Swing_DLL.xex 0x8864EC70 */
void ts4_init_vtable_zero_field8_call_base_8864EC70(char *a)
{
    W(a, 8) = 0;
    *(void **)a = &lbl_880F5848;
    fn_8860BBD8(a);
}

/* Swing_DLL.xex 0x8865ACE0 */
void ts4_init_vtable_zero_field8_call_base_8865ACE0(char *a)
{
    W(a, 8) = 0;
    *(void **)a = &lbl_880F4E18;
    fn_8860BBD8(a);
}

/* Swing_DLL.xex 0x8865AD18 */
void ts4_init_vtable_zero_field8_call_base_8865AD18(char *a)
{
    W(a, 8) = 0;
    *(void **)a = &lbl_880F4E18;
    fn_8860BBD8(a);
}

/* forward_with_global_and_one */
/* Swing_DLL.xex 0x88894B08 */
u32 ts4_forward_with_global_and_one_88894B08(int a, int b, int c, int d)
{
    return fn_88891310(&lbl_88C6ADC8, a, 1, b, c, d);
}

/* Swing_DLL.xex 0x88894B58 */
u32 ts4_forward_with_global_and_one_88894B58(int a, int b, int c, int d)
{
    return fn_88891310(&lbl_88C6ADAC, a, 1, b, c, d);
}

/* compare_chain_field_to_key */
/* Swing_DLL.xex 0x88269E68 */
void ts4_compare_chain_field_to_key_88269E68(char *a, u32 key, u8 *out)
{
    *out = ((W(LP(LP(a, 24), 116), 940) - key) == 0);
}

/* Swing_DLL.xex 0x88660E70 */
void ts4_compare_chain_field_to_key_88660E70(char *a, u32 key, u8 *out)
{
    *out = ((W(LP(LP(a, 24), 116), 940) - key) == 0);
}

/* init_vtable_zero_fields_call_base */
/* Swing_DLL.xex 0x8864F510 */
void ts4_init_vtable_zero_fields_call_base_8864F510(char *a)
{
    W(a, 20) = 0;
    *(void **)a = &lbl_880F5848;
    W(a, 16) = 0;
    W(a, 8) = 0;
    fn_8860BBD8(a);
}

/* Swing_DLL.xex 0x8864F558 */
void ts4_init_vtable_zero_fields_call_base_8864F558(char *a)
{
    W(a, 20) = 0;
    *(void **)a = &lbl_880F5848;
    W(a, 16) = 0;
    W(a, 8) = 0;
    fn_8860BBD8(a);
}

/* get_indexed_pair_second */
/* Swing_DLL.xex 0x886EF4C8 */
u32 ts4_get_indexed_pair_second_886EF4C8(char *a, u32 i)
{
    char *b = LP(a, 12) + 8;
    return W(b + W(b, 0) + (i << 3), 4);
}

/* Swing_DLL.xex 0x886EF918 */
u32 ts4_get_indexed_pair_second_886EF918(char *a, u32 i)
{
    char *b = LP(a, 12) + 8;
    return W(b + W(b, 0) + (i << 3), 4);
}

/* init_vtable_and_script_constant */
/* Swing_DLL.xex 0x888AAF60 */
void ts4_init_vtable_and_script_constant_888AAF60(char *a)
{
    *(void **)a = &lbl_880D6B70;
    FL(a, 4) = g_ts4_script_constants[56];
}

/* Swing_DLL.xex 0x888AD1A8 */
void ts4_init_vtable_and_script_constant_888AD1A8(char *a)
{
    *(void **)a = &lbl_880D6B70;
    FL(a, 4) = g_ts4_script_constants[56];
}

/* set_global_flag_return_true */
/* Swing_DLL.xex 0x882A0330 */
u32 ts4_set_global_flag_return_true_882A0330(void)
{
    lbl_88D429E3 = 1;
    return 1;
}

/* Swing_DLL.xex 0x882A0438 */
u32 ts4_set_global_flag_return_true_882A0438(void)
{
    lbl_88D429E2 = 1;
    return 1;
}

/* Swing_DLL.xex 0x882A0450 */
u32 ts4_set_global_flag_return_true_882A0450(void)
{
    lbl_88D429E1 = 1;
    return 1;
}

/* swap_bytes_via_pointers */
/* Swing_DLL.xex 0x88426FE0 */
void ts4_swap_bytes_via_pointers_88426FE0(u8 *a, u8 *b)
{
    u8 t = *a;
    *a = *b;
    *b = t;
}

/* Swing_DLL.xex 0x88431D98 */
void ts4_swap_bytes_via_pointers_88431D98(u8 *a, u8 *b)
{
    u8 t = *a;
    *a = *b;
    *b = t;
}

/* Swing_DLL.xex 0x885EC518 */
void ts4_swap_bytes_via_pointers_885EC518(u8 *a, u8 *b)
{
    u8 t = *a;
    *a = *b;
    *b = t;
}

/* or_bits_into_u64_array */
/* Swing_DLL.xex 0x886EB170 */
void ts4_or_bits_into_u64_array_886EB170(u64 *a, u32 i, u64 v)
{
    a[i] |= v;
}

/* Swing_DLL.xex 0x888BFAC0 */
void ts4_or_bits_into_u64_array_888BFAC0(u64 *a, u32 i, u64 v)
{
    a[i] |= v;
}

/* Swing_DLL.xex 0x8890C568 */
void ts4_or_bits_into_u64_array_8890C568(u64 *a, u32 i, u64 v)
{
    a[i] |= v;
}

/* zero_fields_0_4_24_8_16 */
/* Swing_DLL.xex 0x881F8AB0 */
void ts4_zero_fields_0_4_24_8_16_881F8AB0(char *a)
{
    W(a, 0) = 0;
    W(a, 4) = 0;
    W(a, 24) = 0;
    W(a, 8) = 0;
    W(a, 16) = 0;
}

/* Swing_DLL.xex 0x888362D8 */
void ts4_zero_fields_0_4_24_8_16_888362D8(char *a)
{
    W(a, 0) = 0;
    W(a, 4) = 0;
    W(a, 24) = 0;
    W(a, 8) = 0;
    W(a, 16) = 0;
}

/* zero_five_words */
/* Swing_DLL.xex 0x885D94F8 */
void ts4_zero_five_words_885D94F8(char *a)
{
    W(a, 0) = 0;
    W(a, 4) = 0;
    W(a, 8) = 0;
    W(a, 12) = 0;
    W(a, 16) = 0;
}

/* Swing_DLL.xex 0x8861E9A0 */
void ts4_zero_five_words_8861E9A0(char *a)
{
    W(a, 0) = 0;
    W(a, 4) = 0;
    W(a, 8) = 0;
    W(a, 12) = 0;
    W(a, 16) = 0;
}

/* index_table_entry */
/* Swing_DLL.xex 0x887E9460 */
char * ts4_index_table_entry_887E9460(char *a, u32 i)
{
    return LP(a, 48) + (((i & 0x3FFF) + ((i << 2) & 0xFFFC)) << 2);
}

/* Swing_DLL.xex 0x887E9480 */
char * ts4_index_table_entry_887E9480(char *a, u32 i)
{
    return LP(a, 48) + (((i & 0x3FFF) + ((i << 2) & 0xFFFC)) << 2);
}

/* select_call_by_flag_with_constant */
/* Swing_DLL.xex 0x888B3C94 */
u32 ts4_select_call_by_flag_with_constant_888B3C94(char *a)
{
    if (!B(a, 104)) return fn_888B2CE8(a, g_ts4_script_constants[0]);
    return fn_888B2838(a, g_ts4_script_constants[0]);
}

/* Swing_DLL.xex 0x888B3CF0 */
u32 ts4_select_call_by_flag_with_constant_888B3CF0(char *a)
{
    if (!B(a, 104)) return fn_888B2AB0(a, g_ts4_script_constants[0]);
    return fn_888B24E8(a, g_ts4_script_constants[0]);
}

/* init_two_pointers */
/* Swing_DLL.xex 0x889314B8 */
void ts4_init_two_pointers_889314B8(char *a)
{
    *(void **)a = &lbl_880D5AA0;
    *(void **)(a + 4) = &lbl_880D5A64;
}

/* Swing_DLL.xex 0x88931F80 */
void ts4_init_two_pointers_88931F80(char *a)
{
    *(void **)a = &lbl_880D5AA0;
    *(void **)(a + 4) = &lbl_880D5A64;
}

/* forward_field156_or_36 */
/* Swing_DLL.xex 0x883EE5C8 */
u32 ts4_forward_field156_or_36_883EE5C8(char *a)
{
    char *p = LP(a, 156);
    if (p) return ts4_lookup_then_forward_88318390(p);
    return 36;
}

/* Swing_DLL.xex 0x883EE610 */
u32 ts4_forward_field156_or_36_883EE610(char *a)
{
    char *p = LP(a, 156);
    if (p) return ts4_lookup_then_forward_883183D8(p);
    return 36;
}

/* ascii_lower_to_upper */
/* Swing_DLL.xex 0x88564790 */
int ts4_ascii_lower_to_upper_88564790(int c)
{
    if (c < 97) return c;
    if (c > 122) return c;
    return c - 32;
}

/* Swing_DLL.xex 0x88818378 */
int ts4_ascii_lower_to_upper_88818378(int c)
{
    if (c < 97) return c;
    if (c > 122) return c;
    return c - 32;
}

/* rewrite_word_return_true */
/* Swing_DLL.xex 0x885FAC70 */
u32 ts4_rewrite_word_return_true_885FAC70(void *a, void *b, volatile u32 *p)
{
    *p = *p;
    return 1;
}

/* Swing_DLL.xex 0x88601B98 */
u32 ts4_rewrite_word_return_true_88601B98(void *a, void *b, volatile u32 *p)
{
    *p = *p;
    return 1;
}

/* Swing_DLL.xex 0x88602BC8 */
u32 ts4_rewrite_word_return_true_88602BC8(void *a, void *b, volatile u32 *p)
{
    *p = *p;
    return 1;
}

/* sum_fields_376_36 */
/* Swing_DLL.xex 0x8860CF60 */
u32 ts4_sum_fields_376_36_8860CF60(char *a)
{
    return W(a, 376) + W(a, 36);
}

/* Swing_DLL.xex 0x8860D8D8 */
u32 ts4_sum_fields_376_36_8860D8D8(char *a)
{
    return W(a, 376) + W(a, 36);
}

/* Swing_DLL.xex 0x8860D9C0 */
u32 ts4_sum_fields_376_36_8860D9C0(char *a)
{
    return W(a, 376) + W(a, 36);
}

/* call_with_global_object_and_one */
/* Swing_DLL.xex 0x88638688 */
u32 ts4_call_with_global_object_and_one_88638688(int a, int b)
{
    return fn_88638188(lbl_88D45B18, b, 1);
}

/* bit_mask_from_index_plus_32 */
/* Swing_DLL.xex 0x886EC198 */
u64 ts4_bit_mask_from_index_plus_32_886EC198(u32 a)
{
    return 0x8000000000000000ULL >> (a + 32);
}

/* Swing_DLL.xex 0x8890C5D0 */
u64 ts4_bit_mask_from_index_plus_32_8890C5D0(u32 a)
{
    return 0x8000000000000000ULL >> (a + 32);
}

/* alloc_16_bytes_from_global_heap */
/* Swing_DLL.xex 0x88890B68 */
void * ts4_alloc_16_bytes_from_global_heap_88890B68(int a, int b)
{
    return fn_88613268(lbl_88D45B38, b, 16, 0, 2);
}

/* Swing_DLL.xex 0x88890E18 */
void * ts4_alloc_16_bytes_from_global_heap_88890E18(int a, int b)
{
    return fn_88613268(lbl_88D45B38, b, 16, 0, 2);
}

/* init_vtable_only */
/* Swing_DLL.xex 0x88994DF8 */
void ts4_init_vtable_only_88994DF8(char *a)
{
    *(void **)a = &lbl_880D1F18;
}

/* Swing_DLL.xex 0x88995470 */
void ts4_init_vtable_only_88995470(char *a)
{
    *(void **)a = &lbl_880D1F18;
}

/* Swing_DLL.xex 0x88995480 */
void ts4_init_vtable_only_88995480(char *a)
{
    *(void **)a = &lbl_880D1F18;
}

/* call_if_field52_zero */
/* Swing_DLL.xex 0x8818ADB8 */
char * ts4_call_if_field52_zero_8818ADB8(char *a)
{
    if ((int)W(a, 52) == 0) return fn_881934E8(a);
    return a;
}

/* Swing_DLL.xex 0x8818AE50 */
char * ts4_call_if_field52_zero_8818AE50(char *a)
{
    if ((int)W(a, 52) == 0) return fn_88193748(a);
    return a;
}

/* forward_field20_with_0_0_1 */
/* Swing_DLL.xex 0x881A56C8 */
u32 ts4_forward_field20_with_0_0_1_881A56C8(char *a)
{
    return fn_8857BA40(LP(a, 20), 0, 0, 1);
}

/* Swing_DLL.xex 0x887CB678 */
u32 ts4_forward_field20_with_0_0_1_887CB678(char *a)
{
    return fn_8857BA40(LP(a, 20), 0, 0, 1);
}

/* call_field20_vtable_slot7 */
/* Swing_DLL.xex 0x8827D018 */
void ts4_call_field20_vtable_slot7_8827D018(char *a)
{
    void *o = LP(a, 20);
    ((void (*)(void *))VT(o, 7))(o);
}

/* Swing_DLL.xex 0x8844B430 */
void ts4_call_field20_vtable_slot7_8844B430(char *a)
{
    void *o = LP(a, 20);
    ((void (*)(void *))VT(o, 7))(o);
}

/* call_field24_vtable_slot4 */
/* Swing_DLL.xex 0x88403968 */
void ts4_call_field24_vtable_slot4_88403968(char *a)
{
    void *o = LP(a, 24);
    ((void (*)(void *))VT(o, 4))(o);
}

/* Swing_DLL.xex 0x8847B010 */
void ts4_call_field24_vtable_slot4_8847B010(char *a)
{
    void *o = LP(a, 24);
    ((void (*)(void *))VT(o, 4))(o);
}

/* set_pair_base_plus_u16_field */
/* Swing_DLL.xex 0x88428800 */
void ts4_set_pair_base_plus_u16_field_88428800(char *a, u32 b, char *c)
{
    u32 v = H(c, 18);
    W(a, 4) = (u32)c;
    W(a, 0) = v + b;
}

/* Swing_DLL.xex 0x88428878 */
void ts4_set_pair_base_plus_u16_field_88428878(char *a, u32 b, char *c)
{
    u32 v = H(c, 18);
    W(a, 4) = (u32)c;
    W(a, 0) = v + b;
}

/* call_field24_vtable_slot9 */
/* Swing_DLL.xex 0x8843D228 */
void ts4_call_field24_vtable_slot9_8843D228(char *a)
{
    void *o = LP(a, 24);
    ((void (*)(void *))VT(o, 9))(o);
}

/* Swing_DLL.xex 0x8843DC88 */
void ts4_call_field24_vtable_slot9_8843DC88(char *a)
{
    void *o = LP(a, 24);
    ((void (*)(void *))VT(o, 9))(o);
}

/* call_field12_vtable_slot5 */
/* Swing_DLL.xex 0x88455718 */
void ts4_call_field12_vtable_slot5_88455718(char *a)
{
    void *o = LP(a, 12);
    ((void (*)(void *))VT(o, 5))(o);
}

/* Swing_DLL.xex 0x8847E880 */
void ts4_call_field12_vtable_slot5_8847E880(char *a)
{
    void *o = LP(a, 12);
    ((void (*)(void *))VT(o, 5))(o);
}

/* zero_fields_8_12_16 */
/* Swing_DLL.xex 0x8865A688 */
void ts4_zero_fields_8_12_16_8865A688(char *a)
{
    W(a, 8) = 0;
    W(a, 12) = 0;
    W(a, 16) = 0;
}

/* Swing_DLL.xex 0x88934CE8 */
void ts4_zero_fields_8_12_16_88934CE8(char *a)
{
    W(a, 8) = 0;
    W(a, 12) = 0;
    W(a, 16) = 0;
}

/* call_adjusted_slot_at_offset64 */
/* Swing_DLL.xex 0x8872F6C8 */
void ts4_call_adjusted_slot_at_offset64_8872F6C8(char *a, int off, int x)
{
    (*(void (**)(char *, int))(a + off + 64))(a, x);
}

/* Swing_DLL.xex 0x8890CE88 */
void ts4_call_adjusted_slot_at_offset64_8890CE88(char *a, int off, int x)
{
    (*(void (**)(char *, int))(a + off + 64))(a, x);
}

/* add_if_negative */
/* Swing_DLL.xex 0x88825100 */
int ts4_add_if_negative_88825100(int a, int b)
{
    if (a >= 0) return a;
    return a + b + 1;
}

/* Swing_DLL.xex 0x8882F098 */
int ts4_add_if_negative_8882F098(int a, int b)
{
    if (a >= 0) return a;
    return a + b + 1;
}

/* field8_equals_3 */
/* Swing_DLL.xex 0x88836220 */
u32 ts4_field8_equals_3_88836220(char *a)
{
    return W(a, 8) == 3;
}

/* Swing_DLL.xex 0x88836238 */
u32 ts4_field8_equals_3_88836238(char *a)
{
    return W(a, 8) == 3;
}

/* forward_shifted_args */
/* Swing_DLL.xex 0x882742A0 */
u32 ts4_forward_shifted_args_882742A0(int a, int b, int c)
{
    return fn_88276028(b, c);
}

/* Swing_DLL.xex 0x885933A0 */
u32 ts4_forward_shifted_args_885933A0(int a, int b, int c)
{
    return fn_88888668(b, c);
}

/* Swing_DLL.xex 0x885933B0 */
u32 ts4_forward_shifted_args_885933B0(int a, int b, int c)
{
    return fn_88884DE0(b, c);
}

/* netdll_call_with_one */
/* Swing_DLL.xex 0x884EFF18 */
int ts4_netdll_call_with_one_884EFF18(int a)
{
    return NetDll_XNetUnregisterInAddr(1, a);
}

/* Swing_DLL.xex 0x884EFF28 */
int ts4_netdll_call_with_one_884EFF28(int a)
{
    return NetDll_XNetConnect(1, a);
}

/* Swing_DLL.xex 0x884EFF38 */
int ts4_netdll_call_with_one_884EFF38(int a)
{
    return NetDll_XNetGetConnectStatus(1, a);
}

/* field16_plus_24 */
/* Swing_DLL.xex 0x885F58B0 */
char * ts4_field16_plus_24_885F58B0(char *a)
{
    return LP(a, 16) + 24;
}

/* Swing_DLL.xex 0x88836150 */
char * ts4_field16_plus_24_88836150(char *a)
{
    return LP(a, 16) + 24;
}

/* Swing_DLL.xex 0x88836160 */
char * ts4_field16_plus_24_88836160(char *a)
{
    return LP(a, 16) + 24;
}

/* set_u16_field28_return_true */
/* Swing_DLL.xex 0x885F9738 */
u32 ts4_set_u16_field28_return_true_885F9738(char *a, u16 b)
{
    H(a, 28) = b;
    return 1;
}

/* Swing_DLL.xex 0x886011D0 */
u32 ts4_set_u16_field28_return_true_886011D0(char *a, u16 b)
{
    H(a, 28) = b;
    return 1;
}

/* Swing_DLL.xex 0x88602AA0 */
u32 ts4_set_u16_field28_return_true_88602AA0(char *a, u16 b)
{
    H(a, 28) = b;
    return 1;
}

/* zero_field4 */
/* Swing_DLL.xex 0x8860EFE0 */
void ts4_zero_field4_8860EFE0(char *a)
{
    W(a, 4) = 0;
}

/* Swing_DLL.xex 0x8865A1F8 */
void ts4_zero_field4_8865A1F8(char *a)
{
    W(a, 4) = 0;
}

/* Swing_DLL.xex 0x8890D7C0 */
void ts4_zero_field4_8890D7C0(char *a)
{
    W(a, 4) = 0;
}

/* call_vtable_slot11 */
/* Swing_DLL.xex 0x88197888 */
void ts4_call_vtable_slot11_88197888(char *a)
{
    ((void (*)(void *))VT(a, 11))(a);
}

/* Swing_DLL.xex 0x883AC3C8 */
void ts4_call_vtable_slot11_883AC3C8(char *a)
{
    ((void (*)(void *))VT(a, 11))(a);
}

/* memcpy_forward_shifted */
/* Swing_DLL.xex 0x882EC208 */
void * ts4_memcpy_forward_shifted_882EC208(int a, void *b, void *c, unsigned int d)
{
    return memcpy(b, c, d);
}

/* Swing_DLL.xex 0x882EC218 */
void * ts4_memset_forward_shifted_882EC218(int a, void *b, int c, unsigned int d)
{
    return memset(b, c, d);
}

/* field8_nonzero */
/* Swing_DLL.xex 0x883E41E0 */
u32 ts4_field8_nonzero_883E41E0(char *a)
{
    return W(a, 8) != 0;
}

/* Swing_DLL.xex 0x8899D988 */
u32 ts4_field8_nonzero_8899D988(char *a)
{
    return W(a, 8) != 0;
}

/* index_u16_array_at_field0 */
/* Swing_DLL.xex 0x884289F8 */
char * ts4_index_u16_array_at_field0_884289F8(char *a, u32 i)
{
    return (char *)(i * 2) + W(a, 0);
}

/* Swing_DLL.xex 0x88428A08 */
char * ts4_index_u16_array_at_field0_88428A08(char *a, u32 i)
{
    return (char *)(i * 2) + W(a, 0);
}

/* index_u64_array_at_field0 */
/* Swing_DLL.xex 0x88428A88 */
char * ts4_index_u64_array_at_field0_88428A88(char *a, u32 i)
{
    return (char *)(i * 8) + W(a, 0);
}

/* Swing_DLL.xex 0x88428AB0 */
char * ts4_index_u64_array_at_field0_88428AB0(char *a, u32 i)
{
    return (char *)(i * 8) + W(a, 0);
}

/* get_field564_of_global_object */
/* Swing_DLL.xex 0x886094B8 */
u32 ts4_get_field564_of_global_object_886094B8(void)
{
    return W(lbl_88D45B1C, 564);
}

/* Swing_DLL.xex 0x8860F098 */
u32 ts4_get_field564_of_global_object_8860F098(void)
{
    return W(lbl_88D45B1C, 564);
}

/* forward_sub_object_88_with_float24 */
/* Swing_DLL.xex 0x886C66B0 */
u32 ts4_forward_sub_object_88_with_float24_886C66B0(char *a)
{
    return fn_886C48C8(a + 88, FL(a, 24));
}

/* Swing_DLL.xex 0x886C6748 */
u32 ts4_forward_sub_object_88_with_float24_886C6748(char *a)
{
    return fn_886C4970(a + 88, FL(a, 24));
}

/* get_global_object_plus_340 */
/* Swing_DLL.xex 0x886EEC28 */
char * ts4_get_global_object_plus_340_886EEC28(void)
{
    return lbl_88D45A4C + 340;
}

/* Swing_DLL.xex 0x886EEC38 */
char * ts4_get_global_object_plus_340_886EEC38(void)
{
    return lbl_88D45A4C + 340;
}

/* call_vtable_slot15 */
/* Swing_DLL.xex 0x88778E68 */
void ts4_call_vtable_slot15_88778E68(char *a)
{
    ((void (*)(void *))VT(a, 15))(a);
}

/* Swing_DLL.xex 0x88940C90 */
void ts4_call_vtable_slot15_88940C90(char *a)
{
    ((void (*)(void *))VT(a, 15))(a);
}

/* get_byte112_of_global_object */
/* Swing_DLL.xex 0x887797D0 */
u32 ts4_get_byte112_of_global_object_887797D0(void)
{
    return B(lbl_88D45A48, 112);
}

/* Swing_DLL.xex 0x887798F0 */
u32 ts4_get_byte112_of_global_object_887798F0(void)
{
    return B(lbl_88D45A48, 112);
}

/* byte96_is_zero */
/* Swing_DLL.xex 0x88834DD8 */
u32 ts4_byte96_is_zero_88834DD8(char *a)
{
    return B(a, 96) == 0;
}

/* Swing_DLL.xex 0x88834E00 */
u32 ts4_byte96_is_zero_88834E00(char *a)
{
    return B(a, 96) == 0;
}

/* get_field40_of_global_object */
/* Swing_DLL.xex 0x88838440 */
u32 ts4_get_field40_of_global_object_88838440(void)
{
    return W(lbl_88D459E8, 40);
}

/* Swing_DLL.xex 0x88838470 */
u32 ts4_get_field40_of_global_object_88838470(void)
{
    return W(lbl_88D459E8, 40);
}

/* forward_global_object_field28 */
/* Swing_DLL.xex 0x88867F00 */
u32 ts4_forward_global_object_field28_88867F00(void)
{
    return fn_888C7AF8(W(lbl_88D45A08, 28));
}

/* Swing_DLL.xex 0x888CFD78 */
u32 ts4_forward_global_object_field28_888CFD78(void)
{
    return fn_888C7AF8(W(lbl_88D45A08, 28));
}

/* bytes_for_bit_count_field8 */
/* Swing_DLL.xex 0x88933F80 */
u32 ts4_bytes_for_bit_count_field8_88933F80(char *a)
{
    return (W(a, 8) + 7) >> 3;
}

/* Swing_DLL.xex 0x88934CD8 */
u32 ts4_bytes_for_bit_count_field8_88934CD8(char *a)
{
    return (W(a, 8) + 7) >> 3;
}

/* forward_field20_with_zero */
/* Swing_DLL.xex 0x881A5668 */
u32 ts4_forward_field20_with_zero_881A5668(char *a)
{
    return fn_8857BF40(LP(a, 20), 0);
}

/* Swing_DLL.xex 0x887CB6E0 */
u32 ts4_forward_field20_with_zero_887CB6E0(char *a)
{
    return fn_8857BF40(LP(a, 20), 0);
}

/* forward_this_plus_24 */
/* Swing_DLL.xex 0x881DD850 */
void ts4_forward_this_plus_24_881DD850(char *a)
{
    fn_881C38D0(a + 24);
}

/* Swing_DLL.xex 0x886811D0 */
void ts4_forward_this_plus_24_886811D0(char *a)
{
    fn_8890E988(a + 24);
}

/* Swing_DLL.xex 0x887CDBB8 */
void ts4_forward_this_plus_24_887CDBB8(char *a)
{
    ts4_object_finalize(a + 24);
}

/* this_plus_28 */
/* Swing_DLL.xex 0x88273610 */
char * ts4_this_plus_28_88273610(char *a)
{
    return a + 28;
}

/* Swing_DLL.xex 0x886F0038 */
char * ts4_this_plus_28_886F0038(char *a)
{
    return a + 28;
}

/* Swing_DLL.xex 0x88778968 */
char * ts4_this_plus_28_88778968(char *a)
{
    return a + 28;
}

/* forward_second_arg_with_const_24950000 */
/* Swing_DLL.xex 0x882A8E08 */
u32 ts4_forward_second_arg_with_const_24950000_882A8E08(int a, int b)
{
    return fn_88888668(b, 0x24950000);
}

/* Swing_DLL.xex 0x882A8E18 */
u32 ts4_forward_second_arg_with_const_24950000_882A8E18(int a, int b)
{
    return fn_88884DE0(b, 0x24950000);
}

/* forward_with_zero_third_arg */
/* Swing_DLL.xex 0x88320EF0 */
u32 ts4_forward_with_zero_third_arg_88320EF0(int a, int b)
{
    return fn_88319C40(a, b, 0);
}

/* Swing_DLL.xex 0x88336BB0 */
u32 ts4_forward_with_zero_third_arg_88336BB0(int a, int b)
{
    return fn_88336AD8(a, b, 0);
}

/* Swing_DLL.xex 0x887D97B8 */
u32 ts4_forward_with_zero_third_arg_887D97B8(int a, int b)
{
    return fn_887D7D98(a, b, 0);
}

/* deref_deref_ptr */
/* Swing_DLL.xex 0x883A3C60 */
u32 ts4_deref_deref_ptr_883A3C60(char *a)
{
    return W(LP(a, 0), 0);
}

/* Swing_DLL.xex 0x886447A0 */
u32 ts4_deref_deref_ptr_886447A0(char *a)
{
    return W(LP(a, 0), 0);
}

/* get_field44 */
/* Swing_DLL.xex 0x883FFAB0 */
u32 ts4_get_field44_883FFAB0(char *a)
{
    return W(a, 44);
}

/* Swing_DLL.xex 0x8841EF68 */
u32 ts4_get_field44_8841EF68(char *a)
{
    return W(a, 44);
}

/* Swing_DLL.xex 0x885F98D0 */
u32 ts4_get_field44_885F98D0(char *a)
{
    return W(a, 44);
}

/* forward_this_minus_8 */
/* Swing_DLL.xex 0x884372C0 */
u32 ts4_forward_this_minus_8_884372C0(char *a)
{
    return fn_884372E0(a - 8);
}

/* Swing_DLL.xex 0x884AB840 */
u32 ts4_forward_this_minus_8_884AB840(char *a)
{
    return fn_884AB860(a - 8);
}

/* Swing_DLL.xex 0x884B22E8 */
u32 ts4_forward_this_minus_8_884B22E8(char *a)
{
    return fn_884B2308(a - 8);
}

/* get_address_of_global */
/* Swing_DLL.xex 0x88466758 */
void * ts4_get_address_of_global_88466758(void)
{
    return &lbl_88C2289C;
}

/* Swing_DLL.xex 0x88466768 */
void * ts4_get_address_of_global_88466768(void)
{
    return &lbl_88C2289C;
}

/* forward_this_minus_32 */
/* Swing_DLL.xex 0x884A9820 */
u32 ts4_forward_this_minus_32_884A9820(char *a)
{
    return fn_884A9828(a - 32);
}

/* Swing_DLL.xex 0x884AB858 */
u32 ts4_forward_this_minus_32_884AB858(char *a)
{
    return fn_884AB860(a - 32);
}

/* Swing_DLL.xex 0x884B2300 */
u32 ts4_forward_this_minus_32_884B2300(char *a)
{
    return fn_884B2308(a - 32);
}

/* field8_plus_12 */
/* Swing_DLL.xex 0x884DA4C8 */
char * ts4_field8_plus_12_884DA4C8(char *a)
{
    return LP(a, 8) + 12;
}

/* Swing_DLL.xex 0x886F0080 */
char * ts4_field8_plus_12_886F0080(char *a)
{
    return LP(a, 8) + 12;
}

/* this_plus_32 */
/* Swing_DLL.xex 0x885037C8 */
char * ts4_this_plus_32_885037C8(char *a)
{
    return a + 32;
}

/* Swing_DLL.xex 0x88545250 */
char * ts4_this_plus_32_88545250(char *a)
{
    return a + 32;
}

/* Swing_DLL.xex 0x88834DC8 */
char * ts4_this_plus_32_88834DC8(char *a)
{
    return a + 32;
}

/* forward_with_const_248C8000 */
/* Swing_DLL.xex 0x885BE1F0 */
u32 ts4_forward_with_const_248C8000_885BE1F0(int a)
{
    return fn_88888668(a, 0x248C8000);
}

/* Swing_DLL.xex 0x885BE200 */
u32 ts4_forward_with_const_248C8000_885BE200(int a)
{
    return fn_88884DE0(a, 0x248C8000);
}

/* forward_field0_with_minus1 */
/* Swing_DLL.xex 0x885EAD68 */
u32 ts4_forward_field0_with_minus1_885EAD68(char *a)
{
    return fn_8857A128(W(a, 0), -1);
}

/* Swing_DLL.xex 0x885EAD88 */
u32 ts4_forward_field0_with_minus1_885EAD88(char *a)
{
    return fn_8857A128(W(a, 0), -1);
}

/* field16_shifted_right_3_u16 */
/* Swing_DLL.xex 0x885F5360 */
u32 ts4_field16_shifted_right_3_u16_885F5360(char *a)
{
    return (W(a, 16) >> 3) & 0xFFFF;
}

/* Swing_DLL.xex 0x885F5378 */
u32 ts4_field16_shifted_right_3_u16_885F5378(char *a)
{
    return (W(a, 16) >> 3) & 0xFFFF;
}

/* get_u16_field36 */
/* Swing_DLL.xex 0x885F53F8 */
u32 ts4_get_u16_field36_885F53F8(char *a)
{
    return H(a, 36);
}

/* Swing_DLL.xex 0x885F9520 */
u32 ts4_get_u16_field36_885F9520(char *a)
{
    return H(a, 36);
}

/* Swing_DLL.xex 0x885F97C8 */
u32 ts4_get_u16_field36_885F97C8(char *a)
{
    return H(a, 36);
}

/* return_constant_22 */
/* Swing_DLL.xex 0x885F9B80 */
u32 ts4_return_constant_22_885F9B80(void)
{
    return 22;
}

/* Swing_DLL.xex 0x886014B8 */
u32 ts4_return_constant_22_886014B8(void)
{
    return 22;
}

/* Swing_DLL.xex 0x88601650 */
u32 ts4_return_constant_22_88601650(void)
{
    return 22;
}

/* set_field48_return_true */
/* Swing_DLL.xex 0x88601170 */
u32 ts4_set_field48_return_true_88601170(char *a, u32 b)
{
    W(a, 48) = b;
    return 1;
}

/* Swing_DLL.xex 0x88602980 */
u32 ts4_set_field48_return_true_88602980(char *a, u32 b)
{
    W(a, 48) = b;
    return 1;
}

/* set_u16_field30_return_true */
/* Swing_DLL.xex 0x886011C0 */
u32 ts4_set_u16_field30_return_true_886011C0(char *a, u16 b)
{
    H(a, 30) = b;
    return 1;
}

/* Swing_DLL.xex 0x88602A90 */
u32 ts4_set_u16_field30_return_true_88602A90(char *a, u16 b)
{
    H(a, 30) = b;
    return 1;
}

/* set_u16_field0_return_2 */
/* Swing_DLL.xex 0x88603D38 */
u32 ts4_set_u16_field0_return_2_88603D38(char *a, u16 b)
{
    H(a, 0) = b;
    return 2;
}

/* Swing_DLL.xex 0x88603D68 */
u32 ts4_set_u16_field0_return_2_88603D68(char *a, u16 b)
{
    H(a, 0) = b;
    return 2;
}

/* zero_byte32 */
/* Swing_DLL.xex 0x886131E0 */
void ts4_zero_byte32_886131E0(char *a)
{
    B(a, 32) = 0;
}

/* Swing_DLL.xex 0x889328F0 */
void ts4_zero_byte32_889328F0(char *a)
{
    B(a, 32) = 0;
}

/* load_float_via_field8 */
/* Swing_DLL.xex 0x88659A70 */
float ts4_load_float_via_field8_88659A70(char *a)
{
    return FL(LP(a, 8), 0);
}

/* Swing_DLL.xex 0x88659B00 */
float ts4_load_float_via_field8_88659B00(char *a)
{
    return FL(LP(a, 8), 0);
}

/* get_address_of_global */
/* Swing_DLL.xex 0x88778348 */
void * ts4_get_address_of_global_88778348(void)
{
    return &lbl_88C476D8;
}

/* Swing_DLL.xex 0x88778358 */
void * ts4_get_address_of_global_88778358(void)
{
    return &lbl_88C476D8;
}

/* get_address_of_global */
/* Swing_DLL.xex 0x887783F8 */
void * ts4_get_address_of_global_887783F8(void)
{
    return &lbl_88C4763C;
}

/* Swing_DLL.xex 0x88778408 */
void * ts4_get_address_of_global_88778408(void)
{
    return &lbl_88C4763C;
}

/* set_fields_8_12 */
/* Swing_DLL.xex 0x88838460 */
void ts4_set_fields_8_12_88838460(char *a, u32 b, u32 c)
{
    W(a, 8) = b;
    W(a, 12) = c;
}

/* Swing_DLL.xex 0x888C0470 */
void ts4_set_fields_8_12_888C0470(char *a, u32 b, u32 c)
{
    W(a, 8) = b;
    W(a, 12) = c;
}

/* field36_plus_arg */
/* Swing_DLL.xex 0x889226F0 */
u32 ts4_field36_plus_arg_889226F0(char *a, u32 b)
{
    return W(a, 36) + b;
}

/* Swing_DLL.xex 0x88922700 */
u32 ts4_field36_plus_arg_88922700(char *a, u32 b)
{
    return W(a, 36) + b;
}

/* field36_plus_464 */
/* Swing_DLL.xex 0x8899C2A0 */
char * ts4_field36_plus_464_8899C2A0(char *a)
{
    return LP(a, 36) + 464;
}

/* Swing_DLL.xex 0x8899C6B8 */
char * ts4_field36_plus_464_8899C6B8(char *a)
{
    return LP(a, 36) + 464;
}

/* get_field588 */
/* Swing_DLL.xex 0x881A53C0 */
u32 ts4_get_field588_881A53C0(char *a)
{
    return W(a, 588);
}

/* Swing_DLL.xex 0x88639EA8 */
u32 ts4_get_field588_88639EA8(char *a)
{
    return W(a, 588);
}

/* get_field100 */
/* Swing_DLL.xex 0x881D8758 */
u32 ts4_get_field100_881D8758(char *a)
{
    return W(a, 100);
}

/* Swing_DLL.xex 0x88608990 */
u32 ts4_get_field100_88608990(char *a)
{
    return W(a, 100);
}

/* forward_this_plus_20 */
/* Swing_DLL.xex 0x881DD848 */
void ts4_forward_this_plus_20_881DD848(char *a)
{
    fn_8819C190(a + 20);
}

/* Swing_DLL.xex 0x8890DFC0 */
void ts4_forward_this_plus_20_8890DFC0(char *a)
{
    ts4_object_finalize(a + 20);
}

/* get_field132 */
/* Swing_DLL.xex 0x88207248 */
u32 ts4_get_field132_88207248(char *a)
{
    return W(a, 132);
}

/* Swing_DLL.xex 0x887FF260 */
u32 ts4_get_field132_887FF260(char *a)
{
    return W(a, 132);
}

/* this_plus_56 */
/* Swing_DLL.xex 0x882724A0 */
char * ts4_this_plus_56_882724A0(char *a)
{
    return a + 56;
}

/* Swing_DLL.xex 0x884D60C0 */
char * ts4_this_plus_56_884D60C0(char *a)
{
    return a + 56;
}

/* this_plus_80 */
/* Swing_DLL.xex 0x88273618 */
char * ts4_this_plus_80_88273618(char *a)
{
    return a + 80;
}

/* Swing_DLL.xex 0x8843E5E0 */
char * ts4_this_plus_80_8843E5E0(char *a)
{
    return a + 80;
}

/* forward_field20 */
/* Swing_DLL.xex 0x8827D778 */
u32 ts4_forward_field20_8827D778(char *a)
{
    return fn_8856CAD0(LP(a, 20));
}

/* Swing_DLL.xex 0x8827D7B0 */
u32 ts4_forward_field20_8827D7B0(char *a)
{
    return fn_8856C878(LP(a, 20));
}

/* forward_field12_of_second_arg */
/* Swing_DLL.xex 0x882F5390 */
u32 ts4_forward_field12_of_second_arg_882F5390(int a, char *b)
{
    return fn_88566FE8(LP(b, 12));
}

/* Swing_DLL.xex 0x888DA2F0 */
u32 ts4_forward_field12_of_second_arg_888DA2F0(int a, char *b)
{
    return fn_88867F10(LP(b, 12));
}

/* forward_with_zero_fourth_arg */
/* Swing_DLL.xex 0x883361E8 */
u32 ts4_forward_with_zero_fourth_arg_883361E8(int a, int b, int c)
{
    return fn_88334C60(a, b, c, 0);
}

/* Swing_DLL.xex 0x888522C8 */
u32 ts4_forward_with_zero_fourth_arg_888522C8(int a, int b, int c)
{
    return fn_88851F00(a, b, c, 0);
}

/* get_u64_field16 */
/* Swing_DLL.xex 0x883FFAA0 */
u64 ts4_get_u64_field16_883FFAA0(char *a)
{
    return D(a, 16);
}

/* Swing_DLL.xex 0x88604410 */
u64 ts4_get_u64_field16_88604410(char *a)
{
    return D(a, 16);
}

/* this_plus_40 */
/* Swing_DLL.xex 0x8841F070 */
char * ts4_this_plus_40_8841F070(char *a)
{
    return a + 40;
}

/* Swing_DLL.xex 0x8841F078 */
char * ts4_this_plus_40_8841F078(char *a)
{
    return a + 40;
}

/* return_constant_48 */
/* Swing_DLL.xex 0x88436E38 */
u32 ts4_return_constant_48_88436E38(void)
{
    return 48;
}

/* Swing_DLL.xex 0x88601A88 */
u32 ts4_return_constant_48_88601A88(void)
{
    return 48;
}

/* forward_this_minus_12 */
/* Swing_DLL.xex 0x88438260 */
u32 ts4_forward_this_minus_12_88438260(char *a)
{
    return fn_88438270(a - 12);
}

/* Swing_DLL.xex 0x8843AF10 */
u32 ts4_forward_this_minus_12_8843AF10(char *a)
{
    return fn_8843AF20(a - 12);
}

/* return_third_arg */
/* Swing_DLL.xex 0x88451378 */
int ts4_return_third_arg_88451378(int a, int b, int c)
{
    return c;
}

/* Swing_DLL.xex 0x88605DC0 */
int ts4_return_third_arg_88605DC0(int a, int b, int c)
{
    return c;
}

/* this_plus_160 */
/* Swing_DLL.xex 0x88474020 */
char * ts4_this_plus_160_88474020(char *a)
{
    return a + 160;
}

/* Swing_DLL.xex 0x88479BF0 */
char * ts4_this_plus_160_88479BF0(char *a)
{
    return a + 160;
}

/* forward_this_minus_12 */
/* Swing_DLL.xex 0x884A1308 */
u32 ts4_forward_this_minus_12_884A1308(char *a)
{
    return fn_884A1328(a - 12);
}

/* Swing_DLL.xex 0x884A14D8 */
u32 ts4_forward_this_minus_12_884A14D8(char *a)
{
    return fn_884A14F8(a - 12);
}

/* forward_this_minus_48 */
/* Swing_DLL.xex 0x884A1318 */
u32 ts4_forward_this_minus_48_884A1318(char *a)
{
    return fn_884A1328(a - 48);
}

/* Swing_DLL.xex 0x884A14E8 */
u32 ts4_forward_this_minus_48_884A14E8(char *a)
{
    return fn_884A14F8(a - 48);
}

/* forward_this_minus_40 */
/* Swing_DLL.xex 0x884AA7C8 */
u32 ts4_forward_this_minus_40_884AA7C8(char *a)
{
    return fn_884AA7D8(a - 40);
}

/* Swing_DLL.xex 0x884B0FF8 */
u32 ts4_forward_this_minus_40_884B0FF8(char *a)
{
    return fn_884B1008(a - 40);
}

/* forward_this_minus_40 */
/* Swing_DLL.xex 0x884AB848 */
u32 ts4_forward_this_minus_40_884AB848(char *a)
{
    return fn_884AB860(a - 40);
}

/* Swing_DLL.xex 0x884B22F0 */
u32 ts4_forward_this_minus_40_884B22F0(char *a)
{
    return fn_884B2308(a - 40);
}

/* get_field68 */
/* Swing_DLL.xex 0x884D60C8 */
u32 ts4_get_field68_884D60C8(char *a)
{
    return W(a, 68);
}

/* Swing_DLL.xex 0x885F94A8 */
u32 ts4_get_field68_885F94A8(char *a)
{
    return W(a, 68);
}

/* this_plus_96 */
/* Swing_DLL.xex 0x884E2160 */
char * ts4_this_plus_96_884E2160(char *a)
{
    return a + 96;
}

/* Swing_DLL.xex 0x884E5158 */
char * ts4_this_plus_96_884E5158(char *a)
{
    return a + 96;
}

/* second_arg_plus_16 */
/* Swing_DLL.xex 0x88521A88 */
char * ts4_second_arg_plus_16_88521A88(int a, char *b)
{
    return b + 16;
}

/* Swing_DLL.xex 0x88521A90 */
char * ts4_second_arg_plus_16_88521A90(int a, char *b)
{
    return b + 16;
}

/* forward_field60 */
/* Swing_DLL.xex 0x8859FFD8 */
u32 ts4_forward_field60_8859FFD8(char *a)
{
    return fn_8859F380(LP(a, 60));
}

/* Swing_DLL.xex 0x888622C0 */
u32 ts4_forward_field60_888622C0(char *a)
{
    return fn_8885EDD8(LP(a, 60));
}

/* forward_this_plus_16 */
/* Swing_DLL.xex 0x885A6190 */
void ts4_forward_this_plus_16_885A6190(char *a)
{
    ts4_if_atomic_interlocked_dec_885949C0(a + 16);
}

/* Swing_DLL.xex 0x8865A2C0 */
void ts4_forward_this_plus_16_8865A2C0(char *a)
{
    ts4_object_finalize(a + 16);
}

/* get_u16_field44 */
/* Swing_DLL.xex 0x885F53D8 */
u32 ts4_get_u16_field44_885F53D8(char *a)
{
    return H(a, 44);
}

/* Swing_DLL.xex 0x885F9500 */
u32 ts4_get_u16_field44_885F9500(char *a)
{
    return H(a, 44);
}

/* get_u16_field40 */
/* Swing_DLL.xex 0x885F53E8 */
u32 ts4_get_u16_field40_885F53E8(char *a)
{
    return H(a, 40);
}

/* Swing_DLL.xex 0x885F9510 */
u32 ts4_get_u16_field40_885F9510(char *a)
{
    return H(a, 40);
}

/* return_constant_36 */
/* Swing_DLL.xex 0x885F9EB8 */
u32 ts4_return_constant_36_885F9EB8(void)
{
    return 36;
}

/* Swing_DLL.xex 0x88603100 */
u32 ts4_return_constant_36_88603100(void)
{
    return 36;
}

/* forward_with_zero_first_arg */
/* Swing_DLL.xex 0x88608848 */
char * ts4_forward_with_zero_first_arg_88608848(int a)
{
    return fn_88883CD0(0);
}

/* Swing_DLL.xex 0x88801AB0 */
char * ts4_forward_with_zero_first_arg_88801AB0(int a)
{
    return fn_88801428(0);
}

/* forward_field36 */
/* Swing_DLL.xex 0x886131D8 */
u32 ts4_forward_field36_886131D8(char *a)
{
    return fn_8860DBC8(LP(a, 36));
}

/* Swing_DLL.xex 0x888905A8 */
u32 ts4_forward_field36_888905A8(char *a)
{
    return fn_8841B5E0(LP(a, 36));
}

/* forward_with_minus1_third_arg */
/* Swing_DLL.xex 0x886918F8 */
u32 ts4_forward_with_minus1_third_arg_886918F8(int a, int b)
{
    return fn_886917F8(a, b, -1);
}

/* Swing_DLL.xex 0x88816D50 */
u32 ts4_forward_with_minus1_third_arg_88816D50(int a, int b)
{
    return fn_88816C30(a, b, -1);
}

/* forward_with_one_first_arg */
/* Swing_DLL.xex 0x88801AB8 */
char * ts4_forward_with_one_first_arg_88801AB8(int a)
{
    return fn_88801428(1);
}

/* Swing_DLL.xex 0x888134E8 */
char * ts4_forward_with_one_first_arg_888134E8(int a)
{
    return fn_885643D0(1);
}

/* get_field108 */
/* Swing_DLL.xex 0x888134C8 */
u32 ts4_get_field108_888134C8(char *a)
{
    return W(a, 108);
}

/* Swing_DLL.xex 0x88834DF8 */
u32 ts4_get_field108_88834DF8(char *a)
{
    return W(a, 108);
}

/* forward_third_arg_plus_8 */
/* Swing_DLL.xex 0x888365A0 */
u32 ts4_forward_third_arg_plus_8_888365A0(int a, int b, u32 *c)
{
    return fn_888364F8(a, b, c + 2);
}

/* Swing_DLL.xex 0x88837048 */
u32 ts4_forward_third_arg_plus_8_88837048(int a, int b, u32 *c)
{
    return fn_888368B0(a, b, c + 2);
}

/* set_float_field12 */
/* Swing_DLL.xex 0x888BFB08 */
void ts4_set_float_field12_888BFB08(char *a, float f)
{
    FL(a, 12) = f;
}

/* Swing_DLL.xex 0x8890C5B0 */
void ts4_set_float_field12_8890C5B0(char *a, float f)
{
    FL(a, 12) = f;
}

/* tail_call_noargs */
/* Swing_DLL.xex 0x88425B88 */
void ts4_tail_call_noargs_88425B88(void)
{
    fn_884259B8();
}

/* Swing_DLL.xex 0x889D01F0 */
void ts4_tail_call_noargs_889D01F0(void)
{
    fn_889D0020();
}

/* tail_call_noargs_b */
/* Swing_DLL.xex 0x889ACC18 */
void ts4_tail_call_noargs_b_889ACC18(void)
{
    fn_889AC440();
}

/* Swing_DLL.xex 0x889ACC88 */
void ts4_tail_call_noargs_b_889ACC88(void)
{
    fn_889AC4B0();
}

/* call_with_one_and_global_second */
/* Swing_DLL.xex 0x887975E8 */
u32 ts4_call_with_one_and_global_second_887975E8(int a)
{
    return fn_887961A0(a, lbl_88C6CBFC, 1);
}

/* Swing_DLL.xex 0x887975F8 */
u32 ts4_call_with_one_and_global_second_887975F8(int a)
{
    return fn_887961A0(a, lbl_88C6CBF8, 1);
}
