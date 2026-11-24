/* W5A shared helpers. Dead locals that shift the operand-order symbol numbering (matching-tips: Operand order)
 * exist only for MSVC; the host syntax check sees nothing. */
#ifndef W5A_TYPES_H
#define W5A_TYPES_H
#ifdef _MSC_VER
extern float __fsqrts(float);
#pragma intrinsic(__fsqrts)
#define W5A_PAD1 int w5a_pad0 = 0;
#define W5A_PAD2 int w5a_pad0 = 0; int w5a_pad1 = 0;
#define W5A_PAD3 int w5a_pad0 = 0; int w5a_pad1 = 0; int w5a_pad2 = 0;
#else
#include <math.h>
#define __fsqrts(x) sqrtf(x)
#define __fres(x) (1.0f / (x))   /* host syntax check only; MSVC has the intrinsic */
#define W5A_PAD1
#define W5A_PAD2
#define W5A_PAD3
#endif
#endif
