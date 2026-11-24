/* Ball curve node evaluation by planar distance between two points.
 * Byte-matches on the LTCG route (/Oc); see work/specs/Q5S/q5s_ball_node.json. */
#include "vx1_vector.h"

#ifdef _MSC_VER
extern float __fsqrts(float);
#pragma intrinsic(__fsqrts)
#else
static float __fsqrts(float x) { return x; }
#endif

typedef unsigned int u32;
extern const float lbl_8814B440; /* shared 0.0f */
struct Ts4RelArray;
struct Ts4SegList;
float ts4_table2d_eval_8826D278(struct Ts4RelArray *table, float x, float y);
float ts4_segment_lookup_8817A688(float x, const struct Ts4SegList *list);

/* rel is a self-relative offset to the node payload; type is a hashed kind tag. */
typedef struct Ts4BallNode { int rel; u32 type; } Ts4BallNode;
static void *ts4_ball_node_data(Ts4BallNode *n) { return n->rel + (char *)n; }

/* Swing_DLL.xex 0x888AB6C8: evaluate a node at the XZ distance p1-p0 (scaled by 100).
 * 2D table kinds also take p0.y*100; constant kinds return the stored float. */
float ts4_ball_node_eval_888AB6C8(Ts4BallNode *node, const __vector4 *p0, const __vector4 *p1)
{
    float r = lbl_8814B440;
    __vector4 v = __vsubfp(*p1, *p0);
    float d = __fsqrts(v.v[2] * v.v[2] + v.v[0] * v.v[0]);
    u32 t = node->type;
    if (t == 0x7A330099)
        r = ts4_table2d_eval_8826D278((struct Ts4RelArray *)ts4_ball_node_data(node), d * 100.0f, p0->v[1] * 100.0f);
    else if (t == 0xF9F12A60)
        r = ts4_segment_lookup_8817A688(d * 100.0f, (struct Ts4SegList *)ts4_ball_node_data(node));
    else if (t == 0x33799CCE)
        r = *(float *)ts4_ball_node_data(node);
    return r;
}
