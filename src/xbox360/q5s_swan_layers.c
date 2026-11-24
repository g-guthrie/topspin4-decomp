/*
 * Q5S swan: swing animation engine, layer-list helpers (LTCG route, /Oc).
 * Check: python3 tools/fn_check_ltcg.py src/xbox360/q5s_swan_layers.c <name>=<addr> --flags /Oc --auto-context
 */
#include "include/ts4/containers.h"

extern float g_ts4_event_value; /* lbl_8814B440, 0.0f */

/* Animation layer: only the blend value is touched here. */
typedef struct Q5sAnimLayer {
    unsigned char pad_00[0x20];
    float value;                /* +0x20 V 886C4A10 (cleared) */
} Q5sAnimLayer;

typedef TS4_VECTOR(Q5sAnimLayer *) Q5sAnimLayerVec;

typedef struct Q5sAnimLayerOwner {
    unsigned char pad_00[0x4];
    Q5sAnimLayerVec layers;     /* +0x04 V 886C4A10 (begin +0x4, end +0x8) */
} Q5sAnimLayerOwner;

static __inline int q5s_layer_count(Q5sAnimLayerVec *v) { return (int)(v->end - v->begin); }
static __inline Q5sAnimLayer *q5s_layer_at(Q5sAnimLayerVec *v, int i) { return v->begin[i]; }

/* 0x886C4A10: clears every layer's value, walking from the last layer to the first.
 * The restrict element pointer lets the four unrolled element loads move above the stores; indexing
 * through q5s_layer_at(&o->layers, i) gives the per-loop reload of layers.begin. */
void ts4_layers_clear_value_886C4A10(Q5sAnimLayerOwner *o)
{
    int i;
    for (i = q5s_layer_count(&o->layers) - 1; i >= 0; i--) {
        Q5sAnimLayer *__restrict l = q5s_layer_at(&o->layers, i);
        l->value = g_ts4_event_value;
    }
}
