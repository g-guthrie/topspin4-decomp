/* ts4core string shim: system header on hosted targets, minimal declarations on wasm32 -nostdlib. */
#ifndef TS4_SHIM_STRING_H
#define TS4_SHIM_STRING_H
#if !defined(__wasm__)
#include_next <string.h>
#else
#include <stddef.h>
void *memcpy(void *dst, const void *src, size_t n);
void *memmove(void *dst, const void *src, size_t n);
void *memset(void *dst, int c, size_t n);
int memcmp(const void *a, const void *b, size_t n);
size_t strlen(const char *s);
#endif
#endif
