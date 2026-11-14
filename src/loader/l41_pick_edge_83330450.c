/* Loader_DLL.xex 0x83330450-0x833304D4, executable version 0.0.0.3. */
int abs(int);
#ifdef _MSC_VER
#pragma intrinsic(abs)
#endif
typedef struct ts4l_edgectx {
    char pad[0x794];
    int threshold;
} ts4l_edgectx;

short *ts4l_pick_edge_83330450(ts4l_edgectx *c, short **rows, int i, int j, int k, int *flag)
{
    short *p0, *p1, *p2;
    int a, b, t;
    p0 = rows[i];
    p2 = rows[j + 2];
    p1 = rows[k + 4];
    a = p1[0] - p0[0];
    b = p1[0] - p2[0];
    t = c->threshold;
    if (abs(b) < abs(a) + t) {
        *flag = 0;
        return p0;
    }
    *flag = 1;
    return p2;
}
