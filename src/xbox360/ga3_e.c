/* GA3: facing-angle helpers (Top Spin 4, Xbox 360, Swing_DLL.xex). */
#include "ga3_types.h"

struct Ga3Angle { float rad; };
extern float lbl_880C88DC;   /* angle constant (pi) */
double fn_88564BF8(float y, float x);   /* atan2 */
void fn_8817B608(struct Ga3Angle *angle);

struct Ga3Dir { unsigned char pad_00[0x20]; float x_20; unsigned char pad_24[4]; float y_28; };
struct Ga3Court24 { unsigned char pad_00[0xB0]; int style_B0; };
struct Ga3Link4C { unsigned char pad_00[0x24]; struct Ga3Court24 *court; };
struct Ga3Actor30 { unsigned char pad_00[0x4C]; struct Ga3Link4C *link; unsigned char pad_50[0x18]; struct Ga3Dir *dir; };
struct Ga3Subject { unsigned char pad_00[0x30]; struct Ga3Actor30 *actor; };

/* out = constant - atan2(dir.y, dir.x) (+ constant for style 0xA2EDA1E7), wrapped by fn_8817B608. */
struct Ga3Angle *ga3_facing_angle_8867C918(struct Ga3Angle *out, struct Ga3Subject *subject)
{
    struct Ga3Actor30 *actor = subject->actor;
    struct Ga3Dir *dir = actor->dir;
    int style = actor->link->court->style_B0;
    float k;
    float v;
    float x = (float)fn_88564BF8(dir->y_28, dir->x_20);
    k = lbl_880C88DC;
    v = k - x;
    out->rad = v;
    if (style == (int)0xA2EDA1E7u)
        out->rad = v + k;
    fn_8817B608(out);
    return out;
}
