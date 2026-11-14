/* SM1 (/O1): walk a chain of nodes (next at +0x24) until the per-node callee reports a negative result. */
#include "sm1_types.h"
#define WALK_NODES(NAME, CALLEE) \
    int NAME(void *unused, int a, unsigned b, int c, int d) { \
        char *n = SM1_PTR(char *, ~b); \
        int r; \
        (void)unused; \
        while (1) { \
            r = CALLEE(n, a, c, d, 0); \
            if (r < 0) break; \
            n = *(char **)(n + 0x24); \
            if (!n) { r = 0; break; } \
        } \
        return r; \
    }
extern int fn_882DE948(void *, int, int, int, int);
extern int fn_882DECF0(void *, int, int, int, int);
extern int fn_882DF080(void *, int, int, int, int);
extern int fn_882DF418(void *, int, int, int, int);
extern int fn_882DF8C0(void *, int, int, int, int);
extern int fn_882DFE38(void *, int, int, int, int);
extern int fn_882E0338(void *, int, int, int, int);
extern int fn_882E0920(void *, int, int, int, int);

/* Swing_DLL.xex 0x882E0FE8 */
WALK_NODES(ts4_walk_nodes_until_negative_882E0FE8, fn_882DE948)
/* Swing_DLL.xex 0x882E10B8 */
WALK_NODES(ts4_walk_nodes_until_negative_882E10B8, fn_882DECF0)
/* Swing_DLL.xex 0x882E1188 */
WALK_NODES(ts4_walk_nodes_until_negative_882E1188, fn_882DF080)
/* Swing_DLL.xex 0x882E1240 */
WALK_NODES(ts4_walk_nodes_until_negative_882E1240, fn_882DF418)
/* Swing_DLL.xex 0x882E12F8 */
WALK_NODES(ts4_walk_nodes_until_negative_882E12F8, fn_882DF8C0)
/* Swing_DLL.xex 0x882E1358 */
WALK_NODES(ts4_walk_nodes_until_negative_882E1358, fn_882DFE38)
/* Swing_DLL.xex 0x882E1410 */
WALK_NODES(ts4_walk_nodes_until_negative_882E1410, fn_882E0338)
/* Swing_DLL.xex 0x882E1470 */
WALK_NODES(ts4_walk_nodes_until_negative_882E1470, fn_882E0920)
