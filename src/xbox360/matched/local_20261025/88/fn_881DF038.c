typedef void (*method_t)(void *, unsigned int);
struct V {
    unsigned char prefix[80];
    method_t method;
};
struct O { struct V *v; };
void fn_881DF038(struct O *p) { p->v->method(p, 1u); }
