// q5s eng: query through a global service object (LTCG, C++ virtual returning a struct).
typedef unsigned int u32;
typedef unsigned char u8;

struct EngTrip { u32 a, b, c; };

// Service at lbl_88D41F80; query is vtable slot 30 (offset 0x78).
struct EngSvc {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual EngTrip query(u32 key, u32 arg);
};
extern "C" EngSvc *lbl_88D41F80;

struct EngQuery {
    u8 pad0[8];
    u32 key;      // 0x08
    u8 padc[8];
    EngTrip res;  // 0x14
    u8 pad20[4];
    u32 mode;     // 0x24
};

extern "C" void ts4_q_query_882102A8(EngQuery *self, u32 arg)
{
    self->mode = 0x20;
    {
        EngTrip t = lbl_88D41F80->query(self->key, arg);
        u32 a = t.a, b = t.b, c = t.c;
        self->res.a = a;
        self->res.b = b;
        self->res.c = c;
    }
}
