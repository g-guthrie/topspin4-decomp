/* Swing_DLL.xex 0x886F3C28: select frame (step + 2) of display layer `layer`, clamped to its last frame, then refresh it. */
typedef struct Ts4U16Vec { unsigned short *first; unsigned short *last; } Ts4U16Vec;
typedef struct Ts4Layer {
    char pad[0x18];
    Ts4U16Vec frames;            /* +0x18 */
    char pad2[0x70];
    unsigned short current;      /* +0x90 */
    char pad3[0x1e];
} Ts4Layer;
typedef struct Ts4DisplayLayers { char pad[0x1d54]; Ts4Layer *layers; } Ts4DisplayLayers;
extern char *lbl_88D45AD4;
extern void fn_886F1A70(void *list, int layer);
static __forceinline int ts4_u16vec_size(const Ts4U16Vec *v) { return v->last - v->first; }
static __forceinline unsigned short *ts4_u16vec_at(Ts4U16Vec *v, unsigned int i) { return &v->first[i]; }
void ts4_layer_select_frame_886F3C28(int layer, int step)
{
    char *g = lbl_88D45AD4;
    Ts4Layer *l = &((Ts4DisplayLayers *)g)->layers[layer];
    unsigned int k = step + 2;
    unsigned char n = (unsigned char)ts4_u16vec_size(&l->frames);
    if (k >= n) k = n - 1;
    l->current = *ts4_u16vec_at(&l->frames, k);
    fn_886F1A70(g + 0x74, layer);
}
