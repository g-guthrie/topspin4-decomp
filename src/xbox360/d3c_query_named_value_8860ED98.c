/* Swing_DLL.xex 0x8860ED98-0x8860EE1C, executable version 0.0.0.3. */
typedef unsigned int u32;

typedef struct Ts4QueryResult {
    u32 value;
} Ts4QueryResult;

typedef struct Ts4QueryService {
    void **vtbl;
} Ts4QueryService;

typedef struct Ts4QueryModule {
    char pad[0x224];
    Ts4QueryService *service;
} Ts4QueryModule;

typedef Ts4QueryResult *(*Ts4QueryFn)(Ts4QueryResult *out, Ts4QueryService *svc, void *self, u32 a, u32 b);

extern Ts4QueryModule *lbl_88D45B1C;
extern char lbl_880D2F14[];
extern int fn_8856A3A0(void *a, const void *b);

/* When NAME matches the expected key, ask the query service for the value and return it; otherwise 0. */
u32 ts4_query_named_value_8860ED98(void *self, void *name)
{
    Ts4QueryResult tmp;
    u32 res = 0;
    if (fn_8856A3A0(name, lbl_880D2F14) == 0) {
        Ts4QueryResult *r = ((Ts4QueryFn)lbl_88D45B1C->service->vtbl[0x28 / 4])(&tmp, lbl_88D45B1C->service, self, 1, 0);
        res = r->value;
    }
    return res;
}
