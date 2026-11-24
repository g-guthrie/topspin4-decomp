/* Q5: read the current camera "At" point from GameDB.
 * 0x888E1B30 returns {x, y, z} through three float lookups (one per axis
 * hash) under "GameDB:/GameDB/CameraSystem/CurrentCamera/At".
 * The three results must be held in locals and stored only after the
 * last lookup; storing x and y into the result earlier is 12 off.
 * Sister 0x888E1C38 is the same code for ".../CurrentCamera/From"
 * (lbl_880DA96C). */
typedef unsigned int u32;

typedef struct Q5Vec3 { float x, y, z; } Q5Vec3;
typedef struct Q5XRef { u32 node, offset, extra; } Q5XRef;

extern char lbl_880DA99C[]; /* "GameDB:/GameDB/CameraSystem/CurrentCamera/At" */
extern Q5XRef *ts4_if_set_u32_off0_8862C0E8(Q5XRef *out, const char *path);
extern Q5XRef *ts4_handle_forward_88150770(Q5XRef *out, Q5XRef *handle, u32 *type_hash);
extern float ts4_if_get_u32_off0_8816CCE0(Q5XRef *r);

Q5Vec3 ts4_camera_current_at_888E1B30(void)
{
    Q5Vec3 v;
    Q5XRef base, r;
    u32 hx, hy, hz;
    float x, y, z;
    ts4_if_set_u32_off0_8862C0E8(&base, lbl_880DA99C);
    hx = 0xB7B2364Bu;
    ts4_handle_forward_88150770(&r, &base, &hx);
    x = ts4_if_get_u32_off0_8816CCE0(&r);
    hy = 0xC0B506DDu;
    { Q5XRef t; r = *ts4_handle_forward_88150770(&t, &base, &hy); }
    y = ts4_if_get_u32_off0_8816CCE0(&r);
    hz = 0x59BC5767u;
    { Q5XRef t; r = *ts4_handle_forward_88150770(&t, &base, &hz); }
    z = ts4_if_get_u32_off0_8816CCE0(&r);
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}
