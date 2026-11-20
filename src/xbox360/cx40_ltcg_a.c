/* CW40 ltcg part a: hash-gated dispatch callers that keep r4 across ts4_check_hash_pair. LTCG route, context cx40_ctx_a.c. */
typedef unsigned int u32;
typedef unsigned char u8;

extern u32 fn_887CE478(void *, void *, int);
u8 ts4_check_hash_pair_887CE408(void *);

typedef struct Cx40I3 { char pad[0x240]; u32 f240; } Cx40I3;
typedef struct Cx40H3 { char pad[0x2c]; u32 f2c; } Cx40H3;
typedef struct Cx40S3 { char pad[0x2c]; Cx40I3 *o; u32 pad4, pad5; Cx40H3 *h; } Cx40S3;
typedef struct Cx40O3 { char pad[0x30]; u32 f30; } Cx40O3;

/* 0x887D1CC0: pick the dispatch hash from the owner state and the hash pair check. */
u32 ts4_guard_dispatch_887D1CC0(Cx40S3 *s, Cx40O3 *out)
{
    if (s->o->f240 == 0xEAE9069Eu) {
        u32 h = s->h->f2c;
        if (h == 0xF202BB09u) {
            out->f30 = 0x872AD78Bu;
            return fn_887CE478(s, out, 0);
        }
        if (h != 0xF7485E9Fu && ts4_check_hash_pair_887CE408(s) != 0) {
            out->f30 = 0x38EAC221u;
            return fn_887CE478(s, out, 0);
        }
    }
    return 0;
}

/* 0x887D1E98: look up the hash in the self-relative table at +0x2c+0x214 and dispatch one of two events. */
u32 ts4_guard_dispatch_887D1E98(char *self, char *out)
{
    char *t = *(char **)(self + 0x2c) + 0x214;
    if (*(u32 *)(t + (*(u32 *)(out + 0x14) * 32 + *(int *)t) + 0x18) == 0x64A3FAF1u && ts4_check_hash_pair_887CE408(self) != 0)
        *(u32 *)(out + 0x30) = 0x8378FCBFu;
    else
        *(u32 *)(out + 0x30) = 0x073D4C08u;
    return fn_887CE478(self, out, 0);
}
