/*
 * Freestanding runtime for the wasm32 build (-nostdlib): mem* / strlen and a bump allocator for the host to
 * place the core instance and the data blob in linear memory. Compiled only for wasm32.
 */
#if defined(__wasm__)
#include <stddef.h>
#include <stdint.h>

void *memcpy(void *dst, const void *src, size_t n) { return __builtin_memcpy(dst, src, n); }
void *memmove(void *dst, const void *src, size_t n) { return __builtin_memmove(dst, src, n); }
void *memset(void *dst, int c, size_t n) { return __builtin_memset(dst, c, n); }

int memcmp(const void *a, const void *b, size_t n)
{
    const unsigned char *p = (const unsigned char *)a, *q = (const unsigned char *)b;
    size_t i;
    for (i = 0; i < n; i++)
        if (p[i] != q[i]) return (int)p[i] - (int)q[i];
    return 0;
}

size_t strlen(const char *s)
{
    size_t n = 0;
    while (s[n]) n++;
    return n;
}

extern unsigned char __heap_base;
static uintptr_t g_bump;

/* Allocate n bytes (16-byte aligned) in linear memory, growing it when needed. Returns 0 on failure.
 * Never freed individually: ts4_wasm_reset() drops everything (new match / reload). */
__attribute__((visibility("default"), used)) void *ts4_wasm_alloc(uint32_t n)
{
    uintptr_t p, end, cur;
    if (!g_bump) g_bump = (uintptr_t)&__heap_base;
    p = (g_bump + 15u) & ~(uintptr_t)15u;
    end = p + n;
    cur = (uintptr_t)__builtin_wasm_memory_size(0) * 65536u;
    if (end > cur) {
        uintptr_t pages = (end - cur + 65535u) / 65536u;
        if (__builtin_wasm_memory_grow(0, (size_t)pages) == (size_t)-1) return (void *)0;
    }
    g_bump = end;
    return (void *)p;
}

__attribute__((visibility("default"), used)) void ts4_wasm_reset(void) { g_bump = (uintptr_t)&__heap_base; }
#endif
