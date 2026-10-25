typedef void (*method_t)(void *, unsigned int);
struct V {
    method_t method;
};
struct O { struct V *v; };
void fn_881975E8(struct O *p) { p->v->method(p, (unsigned int)-1); }
