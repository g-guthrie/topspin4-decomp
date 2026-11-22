/* Q5: forwarders that pass two vec3 arguments to fn_888D1728 with a name hash and two tuning floats
 * (Top Spin 4, Xbox 360, Swing_DLL.xex), plain route, no flags. */
#include "ga3_types.h"
/* 12-byte vector passed by value (r4/r5 and r6/r7 halves: TS4TripleArg idiom). */
typedef struct Q5Vec3 { float x, y, z; } Q5Vec3;
/* Script tuning constants read as floats (byte offset / 4). */
extern const float g_ts4_script_constants[];
extern void fn_888D1728(void *self, struct Ga3Id hash, Q5Vec3 a, Q5Vec3 b, float p, float q);

/* 0x888D93B8: fn_888D1728(self, 0x5392B268, a, b, constants +0x748, +0x74C) */
void ts4_vec3_pair_hash_5392b268_888D93B8(void *self, Q5Vec3 a, Q5Vec3 b)
{
    struct Ga3Id hash;
    hash.value = 0x5392B268u;
    fn_888D1728(self, hash, a, b, g_ts4_script_constants[0x748 / 4], g_ts4_script_constants[0x74C / 4]);
}
