/*
 * Ts4XformBlock::Set (88187B18) and Ts4XformRecord::Set (88187BC0): member-wise copies of the transform block
 * and of the 0xD0 record that embeds it. Classes: include/ts4/classes.h, notes: docs/agents/classes.md.
 * Codegen: the block copy must be a void member (a compiler-generated operator= returns *this and changes the
 * register use); memcpy must stay a call (#pragma function in classes.h); Set is noinline so the record copy calls it.
 */
#include "include/ts4/ts4.h"
#include "include/ts4/classes.h"

TS4_NOINLINE void Ts4XformBlock::Set(const Ts4XformBlock &s)
{
    a = s.a;
    b = s.b;
    c = s.c;
    m = s.m;
    dx = s.dx;
    dy = s.dy;
    dz = s.dz;
}

void Ts4XformRecord::Set(const Ts4XformRecord &s)
{
    a.Assign(s.a);
    b.Assign(s.b);
    c.Assign(s.c);
    d.Assign(s.d);
    f_30 = s.f_30;
    f_31 = s.f_31;
    block.Set(s.block);
    e.Assign(s.e);
}
