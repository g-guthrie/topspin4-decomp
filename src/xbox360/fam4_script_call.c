/* Script bindings of the form "obj:Method()" (Swing_DLL.xex 0x881D9730 group).
   The bound object comes from the call's owner handle, dynamic_cast to the
   class; when the first argument is a string (type 2) the object is looked up
   by name in the global object table instead and checked for the class.
   Then a virtual method (slot SLOT) is called.  The counted references are
   the intrusive ts4_counted pointers (refs at +4, interlocked).
   Verified byte-for-byte with tools/fn_check.py (/O2 /Oi). */
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif
struct ts4_counted { void *vtbl; volatile long refs; };
long ts4_if_atomic_interlocked_dec_881876D0(struct ts4_counted *c);

struct ts4_sobj;
struct ts4_sobj_vtbl { void (*slot[64])(struct ts4_sobj *self); };
struct ts4_sobj { struct ts4_sobj_vtbl *vtbl; };

struct ts4_handle { char pad[0x28]; struct ts4_sobj *obj; };
struct ts4_args { char pad[0x380]; void *first; unsigned long count; };
struct ts4_call { char pad[0xc]; struct ts4_handle *self; struct ts4_args *args; };
struct ts4_svalue { int type; int pad[3]; const char *text; int pad2[11]; };
struct ts4_reg2 { char pad[0x50]; struct ts4_counted *table; };
struct ts4_reg { char pad[0x6c]; struct ts4_reg2 *objects; };
struct ts4_found { char pad[0x28]; struct ts4_sobj *obj; };

extern void *g_ts4_default_script_value;
extern struct ts4_reg *lbl_88D41FC4;
extern char lbl_88C699F4[];
extern char lbl_88C69614[];
struct ts4_sobj *ts4_dynamic_cast_by_class_881DA460(struct ts4_sobj *o);
struct ts4_sobj *ts4_dynamic_cast_by_class_8820B298(struct ts4_sobj *o);
void fn_881C60C8(struct ts4_svalue *v, void *arg);
void ts4_call_seq_fn_881B19A0_881C6008(struct ts4_svalue *v);
void ts4_assign_text_from_c_string(char **s, const char *text);
void ts4_call_seq_u32_off0_8819AD80(char **s);
void fn_881FFA10(struct ts4_found **out, struct ts4_counted *table, char **name, int flag);
unsigned char ts4_loop_get_u32_off0_881CB498(struct ts4_sobj *o, void *cls);

#define TS4_SCRIPT_CALL_OBJ(ADDR, CAST, CLASS, SLOT) \
int ts4_script_call_obj_##ADDR(struct ts4_call *c) \
{ \
    struct ts4_sobj *obj = CAST(c->self->obj); \
    struct ts4_args *a = c->args; \
    struct ts4_svalue v; \
    struct ts4_found *f; \
    fn_881C60C8(&v, a->count > 0 ? a->first : g_ts4_default_script_value); \
    if (v.type == 2) { \
        char *name; \
        struct ts4_counted *t; \
        ts4_assign_text_from_c_string(&name, v.text); \
        t = lbl_88D41FC4->objects->table; \
        if (t != 0) _InterlockedIncrement(&t->refs); \
        fn_881FFA10(&f, t, &name, 1); \
        if (t != 0) ts4_if_atomic_interlocked_dec_881876D0(t); \
        ts4_call_seq_u32_off0_8819AD80(&name); \
        if (f == 0) goto done; \
        if (ts4_loop_get_u32_off0_881CB498(f->obj, CLASS)) { \
            obj = f->obj; \
            ts4_if_atomic_interlocked_dec_881876D0((struct ts4_counted *)f); f = 0; \
        } else { \
            if (f != 0) { ts4_if_atomic_interlocked_dec_881876D0((struct ts4_counted *)f); f = 0; } \
            goto done; \
        } \
    } \
    if (obj != 0) obj->vtbl->slot[(SLOT) / 4](obj); \
done: \
    ts4_call_seq_fn_881B19A0_881C6008(&v); \
    return 0; \
}

TS4_SCRIPT_CALL_OBJ(881D9730, ts4_dynamic_cast_by_class_881DA460, lbl_88C699F4, 0x78)
TS4_SCRIPT_CALL_OBJ(881D9888, ts4_dynamic_cast_by_class_881DA460, lbl_88C699F4, 0x7c)
TS4_SCRIPT_CALL_OBJ(881D99E0, ts4_dynamic_cast_by_class_881DA460, lbl_88C699F4, 0x80)
TS4_SCRIPT_CALL_OBJ(881D9B38, ts4_dynamic_cast_by_class_881DA460, lbl_88C699F4, 0x84)
TS4_SCRIPT_CALL_OBJ(8820A368, ts4_dynamic_cast_by_class_8820B298, lbl_88C69614, 0x7c)
TS4_SCRIPT_CALL_OBJ(8820A4C0, ts4_dynamic_cast_by_class_8820B298, lbl_88C69614, 0x80)
TS4_SCRIPT_CALL_OBJ(8820A618, ts4_dynamic_cast_by_class_8820B298, lbl_88C69614, 0x84)
TS4_SCRIPT_CALL_OBJ(8820A770, ts4_dynamic_cast_by_class_8820B298, lbl_88C69614, 0x88)
