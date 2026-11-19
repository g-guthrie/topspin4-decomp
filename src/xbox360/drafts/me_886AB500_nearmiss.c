/* 0x886AB500 near miss (105 off, /Oc plain C; first draft, 3 variants). Camera view fit: scales the view height by
 * mode (x3 full/tall, x2 wide), offsets -90 when the formatted lbl_880F3EE8 handle resolves to hash 0x93458B98 or
 * 0xF08A38F7, writes ox/oy from zoom level, then clamps the zoomed centre into [x0,x1]/[y0,y1] with __fself selects
 * on g_ts4_script_constants[26 + (a-b<0)] and k = g_ts4_script_constants[186]. Residue: callee-saved register
 * numbering (r27/r30 vs r28/r29), stack slots (target: text at 0x50 reused for the hash, handle at 0x60), and
 * the select-table base hoisted 4x. */
typedef unsigned int u32; typedef unsigned char u8;
extern float __fself(float, float, float);
#pragma intrinsic(__fself)
extern const float lbl_8814B440;
extern const float g_ts4_script_constants[];
extern const char lbl_880F3EE8[];
struct BS { char *first; char *last; char *cap; };
typedef struct Handle { u32 f0, f4; } Handle;
void ts4_assign_formatted_text(struct BS *dst, const char *src);
void ts4_if_set_u32_off0_8862BE08(Handle *out, const char *name);
void fn_88169350(u32 *out, Handle *h);
void ts4_destroy_owned_object(void *p);
typedef struct View { char _0[0x98]; float x0, x1, y0, y1; int left, right, top, bottom; char _b8[0x14]; int ox, oy; float cx, cy; } View;
typedef struct Zoom { char _0[0x130]; int level; } Zoom;
typedef struct Mode { char _0[0xD4]; u8 wide, tall; char _d6[6]; u8 full; } Mode;
typedef struct Cam { char _0[0x2C]; View *view; Zoom *zoom; Mode *mode; } Cam;
static __inline u8 ref_invalid(Handle *r) { return r->f0 == 0 || r->f4 == 0xFFFFF; }
static __inline float fmax0(float a, float b, float zero) { return __fself(g_ts4_script_constants[26 + (a - b < zero)], a, b); }
void ts4_cam_fit_view_886AB500(Cam *c)
{
    View *v = c->view;
    int w = v->right - v->left;
    int h = v->bottom - v->top;
    int off;
    char *name;
    struct BS s;
    Handle ref;
    if (c->mode->full == 1 || c->mode->tall == 1)
        h = h * 3;
    else if (c->mode->wide == 1)
        h = h * 2;
    ts4_assign_formatted_text(&s, lbl_880F3EE8);
    name = s.first;
    off = 0;
    ts4_if_set_u32_off0_8862BE08(&ref, name);
    if (!ref_invalid(&ref)) {
        u32 hash;
        fn_88169350(&hash, &ref);
        if (hash == 0x93458B98u || hash == 0xF08A38F7u)
            off = -90;
    }
    c->view->ox = c->zoom->level * w / 3 + c->view->left + off;
    c->view->oy = c->zoom->level * h / 3 + c->view->top;
    {
        View *vv = c->view;
        float zero = lbl_8814B440;
        float k = g_ts4_script_constants[186];
        float x0 = vv->x0, y0 = vv->y0, x1 = vv->x1, y1 = vv->y1;
        float cx = (x1 - x0) * (float)c->zoom->level * k + x0;
        float cy = (y1 - y0) * (float)c->zoom->level * k + y0;
        cx = __fself(g_ts4_script_constants[26 + (x0 - cx < zero)], x0, cx);
        cy = __fself(g_ts4_script_constants[26 + (y0 - cy < zero)], y0, cy);
        vv->cx = __fself(g_ts4_script_constants[26 + (x1 - cx < zero)], cx, x1);
        vv->cy = __fself(g_ts4_script_constants[26 + (y1 - cy < zero)], cy, y1);
    }
    ts4_destroy_owned_object(name);
}
