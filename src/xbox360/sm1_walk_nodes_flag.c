/* SM1 (/O1): like the node walker but the callee is called with a constant flag of 1 and no extra argument. */
#include "sm1_types.h"
#define WALK_NODES_FLAG(NAME, CALLEE) \
    int NAME(void *unused, int a, unsigned b, int c) { \
        char *n = SM1_PTR(char *, ~b); \
        int r; \
        (void)unused; \
        while (1) { \
            r = CALLEE(n, a, c, 1, 0); \
            if (r < 0) break; \
            n = *(char **)(n + 0x24); \
            if (!n) { r = 0; break; } \
        } \
        return r; \
    }
extern int fn_882DF418(void *, int, int, int, int);
extern int fn_882DF8C0(void *, int, int, int, int);
extern int fn_882E0338(void *, int, int, int, int);

/* Swing_DLL.xex 0x882E11E8 */
WALK_NODES_FLAG(ts4_walk_nodes_until_negative_flag_882E11E8, fn_882DF418)
/* Swing_DLL.xex 0x882E12A0 */
WALK_NODES_FLAG(ts4_walk_nodes_until_negative_flag_882E12A0, fn_882DF8C0)
/* Swing_DLL.xex 0x882E13B8 */
WALK_NODES_FLAG(ts4_walk_nodes_until_negative_flag_882E13B8, fn_882E0338)
