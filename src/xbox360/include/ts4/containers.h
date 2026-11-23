/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex) shared gameplay types: containers.h
 * Engine containers used by the gameplay classes. Conventions and evidence tags: docs/agents/types.md.
 *
 * First pass: only the two shapes the gameplay classes embed. The engine's string/text, hash-map, list and
 * ref-counted handle classes (subsystem `cont`, 732 matched functions with anonymous private structs) are
 * not covered yet: see "next pass" in docs/agents/types.md.
 */
#ifndef TS4_CONTAINERS_H
#define TS4_CONTAINERS_H

#include "base.h"

/* Self-relative array (XData): `offset` is relative to the header itself (-1 = empty). 8 bytes.
 * d1g: Ts4RelArray; q5: Q5PathArray; gp2/rt1 use the 12-byte form below. */
typedef struct Ts4RelArray {
    int offset;                                  /* +0x00 V 8868F178 8867A7C0 886AC7E0 */
    int count;                                   /* +0x04 V 8868F178 8867A7C0 886AC7E0 */
} Ts4RelArray;
TS4_ASSERT_OFFSET(Ts4RelArray, count, 0x4);
TS4_ASSERT_SIZE(Ts4RelArray, 0x8);

/* 12-byte self-relative array {offset, count, capacity}. gp2: Gp2RelArray; rt1: Rt1RangeList; d1g: Ts4CategoryList. */
typedef struct Ts4RelArray12 {
    int offset;                                  /* +0x00 U gp2_types.h / rt1_types.h */
    int count;                                   /* +0x04 U gp2_types.h / rt1_types.h */
    int capacity;                                /* +0x08 U (third word; "aux" in gp2_types.h) */
} Ts4RelArray12;
TS4_ASSERT_SIZE(Ts4RelArray12, 0xC);

/* Element `i` of a self-relative array of T (no null check: callers test offset/count the way the original does). */
#define TS4_REL_AT(T, hdr, i) ((T *)((char *)(hdr) + (hdr)->offset) + (i))

/* std::vector-like triple. Declare a typed one with TS4_VECTOR(Elem) name; */
#define TS4_VECTOR(T) struct { T *begin; T *end; T *cap; }
typedef struct Ts4PtrVector {
    void **begin;                                /* +0x00 V 8865ED78 (Player+0xA0 condition pointers) */
    void **end;                                  /* +0x04 V 8865ED78 */
    void **cap;                                  /* +0x08 U (d1g_types.h Ts4ConditionVector) */
} Ts4PtrVector;
TS4_ASSERT_OFFSET(Ts4PtrVector, end, 0x4);
TS4_ASSERT_SIZE(Ts4PtrVector, 0xC);

#endif /* TS4_CONTAINERS_H */
