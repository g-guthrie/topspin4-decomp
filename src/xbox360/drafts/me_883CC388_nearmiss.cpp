/* 0x883CC388 near miss (2 off, /O1): per-frame tick: advances the clock delta, repositions on change (flag 0x20000), runs fn_883CC1F0 and fn_883C7508, then out->update(dt, was_flag_0x10). */
/* Residue: target emits mr r3,r31 before stb changed=0; every placement (pointer local, helper, bool, array) puts the stb first. extrwi. needs the (unsigned char) cast. */
struct Out { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual int update(int dt, unsigned int was);
    virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42();
    virtual int reposition(); };
struct Clock { char pad[0x14]; unsigned int last; };
struct T { char pad[0x60]; unsigned int flags; char p64[0xAC - 0x64]; Clock *clock; char pb0[0x138 - 0xB0]; Out *out; };
extern "C" int ts4_call_seq_fn_8857B830_8831A8B8(int *now);
extern "C" int ts4_position_changed_883C7158(T *t, unsigned char *changed);
extern "C" int fn_883CC1F0(T *t, int dt);
extern "C" int fn_883C7508(T *t);
extern "C" int ts4_tick_883CC388(T *t)
{
    unsigned int was;
    int now, dt, r;
    unsigned char changed;
    was = t->flags & 0x10;
    t->flags &= ~0x20;
    if (!(t->flags & 0x1000)) return 0;
    r = ts4_call_seq_fn_8857B830_8831A8B8(&now);
    if (r) return r;
    if (!t->clock->last) t->clock->last = now;
    dt = now - t->clock->last;
    t->clock->last = now;
    dt = dt < 0 ? 0 : dt;
    if ((unsigned char)((t->flags >> 17) & 1)) {
        changed = 0;
        r = ts4_position_changed_883C7158(t, &changed);
        if (r) return r;
        if (changed) {
            r = t->out->reposition();
            if (r) return r;
        }
    }
    r = fn_883CC1F0(t, dt);
    if (r) return r;
    if (!(t->flags & 0x1000)) return 0;
    r = fn_883C7508(t);
    if (r) return r;
    return t->out->update(dt, was);
}
