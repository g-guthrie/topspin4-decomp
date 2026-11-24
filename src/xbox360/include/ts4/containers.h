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

/* Engine narrow string (CStringT-like): the object is one `char *` to the data; a refcounted header sits
 * just before it (data - sizeof(Ts4StrHdr)). q5s_cont: Right (8819BE18) reads length/alloc and clones the header. */
typedef struct Ts4StrHdr {
    void *alloc;                                 /* +0x00 V 8819BE18 (string manager passed to assign) */
    int length;                                  /* +0x04 V 8819BE18 */
    int alloc_length;                            /* +0x08 U (CStringData order) */
    int refs;                                    /* +0x0C U (CStringData order) */
} Ts4StrHdr;
TS4_ASSERT_OFFSET(Ts4StrHdr, length, 0x4);
TS4_ASSERT_SIZE(Ts4StrHdr, 0x10);
typedef struct Ts4String {
    char *data;                                  /* +0x00 V 8819BE18 */
} Ts4String;
TS4_ASSERT_SIZE(Ts4String, 0x4);
#define TS4_STR_HDR(s) ((Ts4StrHdr *)(s)->data - 1)

/* Growable text buffer {first, last, end} (vector<char>-like). assign(const char *) = 8816CAA0. */
typedef struct Ts4Text {
    char *first;                                 /* +0x00 V 8816CAA0 */
    char *last;                                  /* +0x04 V 8816CAA0 */
    char *end;                                   /* +0x08 V 8816CAA0 */
} Ts4Text;
TS4_ASSERT_SIZE(Ts4Text, 0xC);

/* Bit iterator (vector<bool> style): word pointer plus bit offset 0..31. */
typedef struct Ts4BitIt {
    unsigned int *word;                                   /* +0x00 V 8816FE78 */
    int bit;                                     /* +0x04 V 8816FE78 */
} Ts4BitIt;
TS4_ASSERT_SIZE(Ts4BitIt, 0x8);

/* Chained hash table (bucket array of singly linked nodes; node keeps its full hash). */
typedef struct Ts4HashNode {
    unsigned char _pad00[0x14];                             /* +0x00 key/value payload (varies) */
    struct Ts4HashNode *next;                    /* +0x14 V 8818FF70 88190190 */
    unsigned int hash;                                    /* +0x18 V 8818FF70 88190190 */
} Ts4HashNode;
TS4_ASSERT_OFFSET(Ts4HashNode, next, 0x14);
TS4_ASSERT_OFFSET(Ts4HashNode, hash, 0x18);
typedef struct Ts4HashTable {
    unsigned char _pad00[0x14];
    Ts4HashNode **buckets;                       /* +0x14 V 8818FF70 */
    unsigned int count;                                   /* +0x18 U (88190190 path) */
    unsigned int bucket_count;                            /* +0x1C V 8818FF70 */
} Ts4HashTable;
TS4_ASSERT_OFFSET(Ts4HashTable, buckets, 0x14);
TS4_ASSERT_OFFSET(Ts4HashTable, bucket_count, 0x1C);
typedef struct Ts4HashIter {
    Ts4HashTable *table;                         /* +0x00 V 8818FF70 */
    Ts4HashNode *node;                           /* +0x04 V 8818FF70 */
} Ts4HashIter;
TS4_ASSERT_SIZE(Ts4HashIter, 0x8);

/* 16-byte key: pointer identity when size == 0, else 16 inline bytes compared with memcmp. */
typedef struct Ts4Key16 {
    union { void *ptr; unsigned char bytes[16]; } u;        /* +0x00 V 8818A210 */
    unsigned int size;                                    /* +0x10 V 8818A210 */
} Ts4Key16;
TS4_ASSERT_OFFSET(Ts4Key16, size, 0x10);
TS4_ASSERT_SIZE(Ts4Key16, 0x14);

#endif /* TS4_CONTAINERS_H */
