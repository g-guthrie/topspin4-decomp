/* Shared host/target type helpers for the SM1 matching sources. */
#ifndef SM1_TYPES_H
#define SM1_TYPES_H

#ifdef _MSC_VER
typedef __int64 sm1_s64;
typedef unsigned int sm1_uptr;
#else
typedef long long sm1_s64;
typedef unsigned long sm1_uptr;
#endif

/* Pointer from a 32-bit value; the target has 32-bit pointers, the host check needs an explicit width. */
#define SM1_PTR(type, value) ((type)(sm1_uptr)(value))

#endif
