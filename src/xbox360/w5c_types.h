#ifndef W5C_TYPES_H
#define W5C_TYPES_H
/* W5C: shared helpers for float functions (docs/agents/near-misses/FP1.md, PP1.md).
 * Define W5C_SEL before including to get the named zero and the fsel-style min/max helpers. */
#ifdef W5C_SEL
static const float w5c_zero = 0.0f;
static __inline float w5c_max(float a, float b) { return (a - b >= w5c_zero) ? a : b; }
static __inline float w5c_min(float a, float b) { return (a - b >= w5c_zero) ? b : a; }
#endif
#endif
