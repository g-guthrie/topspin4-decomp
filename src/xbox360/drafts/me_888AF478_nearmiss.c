/* 0x888AF478: If the pose has output targets, copies dir, pos and up into them, and copies speed when it exceeds lbl_880C960C. */
/* Near miss (agAH): /Oc, 3 off: the target loads lbl_880C960C before the last stfs and before speed; every compare form tried loads it after. */
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Pose { char p0[0xc]; Vec3 pos; Vec3 dir; Vec3 up; float speed; char p34[0x2c]; Vec3 *out_pos; Vec3 *out_dir; Vec3 *out_up; float *out_speed; } Pose;
extern const float lbl_880C960C;
static void v3_copy(Vec3 *d, const Vec3 *s)
{
    d->x = s->x;
    d->y = s->y;
    d->z = s->z;
}
void fn_888AF478(Pose *p)
{
    if ((int)p->out_pos == 0)
        return;
    v3_copy(p->out_dir, &p->dir);
    v3_copy(p->out_pos, &p->pos);
    v3_copy(p->out_up, &p->up);
    if (p->speed > lbl_880C960C)
        *p->out_speed = p->speed;
}
