/* 0x889C28F0 (hand match): assigns a handle to the object through the base setter, then points both
 * attached links at the object's current target. */
typedef struct Handle12 { int a, b, c; } Handle12;
typedef struct Link { char p[8]; void *target; } Link;
typedef struct Obj { char p[0x34]; Link *link_a; Link *link_b; void *target; } Obj;
void fn_88627EC0(Obj *object, Handle12 h);
void ts4_set_handle_and_link_targets_889C28F0(Obj *o, Handle12 h)
{
    fn_88627EC0(o, h);
    o->link_a->target = o->target;
    o->link_b->target = o->target;
}
