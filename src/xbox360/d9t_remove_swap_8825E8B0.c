/* Swing_DLL.xex 0x8825E8B0-0x8825E8FC, executable version 0.0.0.3. */
typedef struct Ts4KV { unsigned val; int key; } Ts4KV;
typedef struct Ts4KVVec { Ts4KV *begin; Ts4KV *end; } Ts4KVVec;
void ts4_remove_swap_8825E8B0(Ts4KVVec *v, int key)
{
    Ts4KV *p = v->begin;
    Ts4KV *e = v->end;
    if (p == e) { return; }
    for (; p != e; ++p) {
        if (p->key == key) {
            p->val = (--e)->val;
            p->key = e->key;
            v->end = v->end - 1;
            return;
        }
    }
}
