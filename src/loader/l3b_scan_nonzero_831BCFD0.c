/* Loader_DLL.xex 0x831BCFD0-0x83254568, executable version 0.0.0.3.
 * Result-record probes: flag whether any entry of an array is non-zero. */

typedef struct {
    char pad[0x28];
    int enabled;
    int pad2;
    int found;
} Ts4lProbeResult;

#define TS4L_SCAN_NONZERO(NAME)                                 \
    void NAME(int *v, int n, Ts4lProbeResult *r, int kind)      \
    {                                                           \
        int i;                                                  \
        r->found = 0;                                           \
        if (kind != 3)                                          \
            return;                                             \
        if (r->enabled == 0)                                    \
            return;                                             \
        if (v == 0)                                             \
            return;                                             \
        if (n <= 0)                                             \
            return;                                             \
        for (i = 0; i < n; i++) {                               \
            if (v[i] != 0) {                                    \
                r->found = 1;                                   \
                return;                                         \
            }                                                   \
        }                                                       \
    }

TS4L_SCAN_NONZERO(ts4l_probe_any_nonzero_831BCFD0)
TS4L_SCAN_NONZERO(ts4l_probe_any_nonzero_831BD030)
TS4L_SCAN_NONZERO(ts4l_probe_any_nonzero_83254508)
TS4L_SCAN_NONZERO(ts4l_probe_any_nonzero_83254568)
