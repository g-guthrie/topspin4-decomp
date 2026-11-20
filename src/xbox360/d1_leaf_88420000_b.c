/* Swing_DLL.xex 0x88420C20-0x88428348, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_88420A90(void *);
extern void fn_88423660(void *);
extern void fn_884259B8(void *);
extern void fn_88427CA8(void *);
extern void fn_88562DC0(void *);
extern void fn_885630C0(void *);
extern void fn_88563500(void *);
extern void fn_885646F8(void *);
extern void fn_885647D0(void *);
extern void ts4_tailcall_fn_885654E8_885655D0(void *);
extern void fn_88566A68(void *);
#ifdef _MSC_VER
#pragma function(memset)
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif
extern char lbl_8803A308[];
extern char lbl_88B3C350[];

void ts4_forward_88421458(void *object)
{
    fn_88562DC0(object);
}

void *ts4_forward_88421460(void *object, int value, unsigned int count)
{
    return memset(object, value, count);
}

void ts4_forward_field_c_88424750(char *object)
{
    fn_88566A68(*(void **)(object + 0xc));
}

void ts4_forward_field_8_88425108(char *object)
{
    fn_88566A68(*(void **)(object + 0x8));
}
