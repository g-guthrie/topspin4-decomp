/* SM5: hand-matched small functions (Swing_DLL.xex 0x88700000-0x88B00000). */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
struct V4f { float x, y, z, w; };
struct VT { virtual int m0(); virtual int m1(); virtual int m2(); virtual int m3(); virtual int m4(); };
struct KF { float t; float v[3]; float pad[6]; };
extern "C" {
/* Swing_DLL.xex 0x881CE240 */
void ts4_lane_set_y_881CE240(void *unused, V4f *o, float *p) { V4f t = *(V4f*)((char*)o+0x10); t.y = *p; *(V4f*)((char*)o+0x10) = t; }
/* Swing_DLL.xex 0x881CE2A0 */
void ts4_lane_set_z_881CE2A0(void *unused, V4f *o, float *p) { V4f t = *(V4f*)((char*)o+0x10); t.z = *p; *(V4f*)((char*)o+0x10) = t; }
/* Swing_DLL.xex 0x881CE300 */
void ts4_lane_set_w_881CE300(void *unused, V4f *o, float *p) { V4f t = *(V4f*)((char*)o+0x10); t.w = *p; *(V4f*)((char*)o+0x10) = t; }
}
