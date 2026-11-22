/* Q5h4: read a camera point from GameDB (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * Clone of the 0x888E1B30 template (q5_gameplay_camera_at.c). The sister 0x888E1C38 is the same code with the
 * path string lbl_880DA96C in place of lbl_880DA99C, which reads ".../CurrentCamera/From".
 * The three results are held in locals and stored only after the last lookup. */
typedef unsigned int u32;

typedef struct Q5h4Vec3 { float x, y, z; } Q5h4Vec3;
typedef struct Q5h4XRef { u32 node, offset, extra; } Q5h4XRef;

extern char lbl_880DA96C[]; /* "GameDB:/GameDB/CameraSystem/CurrentCamera/From" */
extern Q5h4XRef *ts4_if_set_u32_off0_8862C0E8(Q5h4XRef *out, const char *path);
extern Q5h4XRef *ts4_handle_forward_88150770(Q5h4XRef *out, Q5h4XRef *handle, u32 *type_hash);
extern float ts4_if_get_u32_off0_8816CCE0(Q5h4XRef *r);

Q5h4Vec3 ts4_camera_current_from_888E1C38(void)
{
    Q5h4Vec3 v;
    Q5h4XRef base, r;
    u32 hx, hy, hz;
    float x, y, z;
    ts4_if_set_u32_off0_8862C0E8(&base, lbl_880DA96C);
    hx = 0xB7B2364Bu;
    ts4_handle_forward_88150770(&r, &base, &hx);
    x = ts4_if_get_u32_off0_8816CCE0(&r);
    hy = 0xC0B506DDu;
    { Q5h4XRef t; r = *ts4_handle_forward_88150770(&t, &base, &hy); }
    y = ts4_if_get_u32_off0_8816CCE0(&r);
    hz = 0x59BC5767u;
    { Q5h4XRef t; r = *ts4_handle_forward_88150770(&t, &base, &hz); }
    z = ts4_if_get_u32_off0_8816CCE0(&r);
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}
