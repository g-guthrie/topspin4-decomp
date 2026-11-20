/* Loader_DLL.xex 0x83430370-0x834866A0, executable version 0.0.0.3. */

#ifdef _MSC_VER
void __emit(unsigned);
void __storewordbytereverse(unsigned int, int, void *);
unsigned int __loadwordbytereverse(int, void *);
int _CountLeadingZeros(unsigned int);
double __fabs(double);
#pragma intrinsic(__emit)
#pragma intrinsic(__storewordbytereverse)
#pragma intrinsic(__loadwordbytereverse)
#pragma intrinsic(_CountLeadingZeros)
#pragma intrinsic(__fabs)
#define TS4L_EMIT(x) __emit(x)
#define TS4L_STWBR(v, p) __storewordbytereverse(v, 0, p)
#define TS4L_LWBR(p) __loadwordbytereverse(0, p)
#define TS4L_CLZ(x) _CountLeadingZeros(x)
#define TS4L_FABS(x) __fabs(x)
#else
#define TS4L_EMIT(x) ((void)0)
#define TS4L_STWBR(v, p) (*(unsigned int *)(p) = (v))
#define TS4L_LWBR(p) (*(unsigned int *)(p))
#define TS4L_CLZ(x) ((unsigned int)(x))
#define TS4L_FABS(x) ((x) < 0 ? -(x) : (x))
#endif

int ts4l_field_op_83430370(float fa1)
{
    return (int)(fa1);
}

int ts4l_field_op_83447338(unsigned int a3, unsigned int a4)
{
    if (!a3) {
        return 0;
    }
    if (a4) {
        return (int)((a4 + (unsigned int)(32)));
    }
    return 0;
}

int ts4l_field_op_8344A270(float fa1)
{
    return (int)(fa1);
}

unsigned int ts4l_field_op_834546A8(char * a3)
{
    unsigned int t0;
    unsigned int t1;
    unsigned int t2;
    unsigned int t3;
    t0 = *(unsigned char *)a3;
    t1 = *(unsigned char *)(a3 + 1);
    t2 = *(unsigned char *)(a3 + 2);
    t3 = *(unsigned char *)(a3 + 3);
    return (((((((t0 << 8) | (t0 >> 24)) + t1) << 8) + t2) << 8) + t3);
}

unsigned int ts4l_count_zeros_83470378(unsigned int a3)
{
    return ((unsigned int)(32) - TS4L_CLZ(((a3 >> 16) - (unsigned int)(1))));
}

unsigned int ts4l_count_zeros_83470390(unsigned int a3)
{
    return ((unsigned int)(32) - TS4L_CLZ(((a3 & 0xFFFFU) - (unsigned int)(1))));
}

int ts4l_field_op_83473CB0(float fa1)
{
    return (int)(fa1);
}

int ts4l_field_op_83477658(float fa1)
{
    return (int)(fa1);
}

int ts4l_field_op_834866A0(float fa1)
{
    return (int)(fa1);
}
