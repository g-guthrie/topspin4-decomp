/* Original minimal declarations for code matching with 32-bit PPC guest pointers.
 * No implementation of memcpy/memset is supplied. This is not a general SDK.
 * Original source ABI and behavior remain unproven even when object bytes match.
 */
#ifndef TS4_MATCHING_GUEST_STD_H
#define TS4_MATCHING_GUEST_STD_H
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned int size_t;
void * __cdecl memcpy(void *destination, const void *source, size_t size);
void * __cdecl memset(void *destination, int value, size_t size);
#endif
