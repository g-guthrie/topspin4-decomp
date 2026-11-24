/* nearmiss: 3 off (LTCG /Oc --auto-context); target loads out.p into r30 after the destroy(joined) call and the global reload; here it is loaded before the call. Forms that load it after the call put it in r31 (reusing the global base) and lose the r30 save: 36 off. int-typed sink gives the target's cmpwi. Sisters 0x88888e40/0x88888ee8 share the shape. */
typedef struct Text { char *p; char *last; char *end; } Text;
Text *fn_88163300(Text *r, const Text *a, const Text *b);
void ts4_if_call_seq_u32_off0_8816D140(Text *dst, const Text *src);
void ts4_destroy_owned_object(void *obj);
typedef struct Sink Sink;
typedef struct SinkVt { void *slots[0x14]; void (*post)(Sink *self, char *text); } SinkVt;
struct Sink { SinkVt *vt; };
typedef struct Engine { char pad[0x2a4]; int sink; } Engine;
extern Engine *lbl_88D45B1C;
typedef struct Named { char pad[0x1c]; int active; char pad20[8]; Text prefix; } Named;

void f(Named *self, const Text *text)
{
    if (lbl_88D45B1C->sink && self->active) {
        Text joined, out;
        char *t;
        ts4_if_call_seq_u32_off0_8816D140(&out, fn_88163300(&joined, &self->prefix, text));
        t = out.p;
        ts4_destroy_owned_object(joined.p);
        { Sink *k = (Sink *)lbl_88D45B1C->sink; k->vt->post(k, t); }
        ts4_destroy_owned_object(t);
    }
}
