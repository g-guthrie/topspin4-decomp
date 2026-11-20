/* Swing_DLL.xex 0x886EC548: write the xyz of each 0x50-byte record's position (+0x10) as packed float3s. */
#include "vx1_vector.h"
typedef struct Ts4PosRec { char pad[0x10]; __vector4 pos; char pad2[0x30]; } Ts4PosRec;
typedef struct Ts4PosRecVec { Ts4PosRec *first; Ts4PosRec *last; } Ts4PosRecVec;
typedef struct Ts4Float3 { float x, y, z; } Ts4Float3;
void ts4_pos_records_to_float3_886EC548(Ts4PosRecVec *v, Ts4Float3 *out)
{
    Ts4PosRec *e = v->last, *p = v->first;
    for (; p < e; p++, out++) {
        __vector4 q = p->pos;
        __stvewx(__vspltw(q, 0), out, 0);
        __stvewx(__vspltw(q, 1), out, 4);
        __stvewx(__vspltw(q, 2), out, 8);
    }
}
