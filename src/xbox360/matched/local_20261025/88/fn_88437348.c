typedef void (*method_t)(void *, unsigned int);
struct V { method_t method; };
struct O { struct V *v; };
void fn_88437348(struct O *p) { p->v->method(p, 0u); }
