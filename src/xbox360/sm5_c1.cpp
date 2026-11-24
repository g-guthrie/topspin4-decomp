/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct V4f { float x, y, z, w; };
struct VT { virtual int m0(); virtual int m1(); virtual int m2(); virtual int m3(); virtual int m4(); };
struct KF { float t; float v[3]; float pad[6]; };
#define LANE_SET(NAME, IDX) \
  void NAME(void *unused, char *o, float *p) { V4f t = *(V4f*)(o+0x10); ((float*)&t)[IDX] = *p; *(V4f*)(o+0x10) = t; }
#define LANE_SET2(NAME, FLD) \
  void NAME(void *unused, char *o, float *p) { V4f t = *(V4f*)(o+0x10); t.FLD = *p; *(V4f*)(o+0x10) = t; }
extern "C" {
LANE_SET(lane_set_x_881CE1E0__v0, 0)
LANE_SET2(lane_set_x_881CE1E0__v1, x)
/* Swing_DLL.xex 0x881CE1E0 */
void ts4_set_vec4_lane_x_881CE1E0(void *unused, V4f *o, float *p) { V4f t = *(V4f*)((char*)o+0x10); t.x = *p; *(V4f*)((char*)o+0x10) = t; }
}
