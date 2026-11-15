/* CW40 part b: script-state guard checks (hash-gated dispatch into fn_887CE478). */
typedef unsigned int u32;
typedef unsigned char u8;

extern u32 fn_887CE478(void *, void *, int);

typedef struct Cx40Inner { char pad[0x1d0]; u32 f1d0; char pad2[0x64]; u32 f238; char pad3[0x10c]; u32 f348; } Cx40Inner;
typedef struct Cx40Cfg { char pad[0x99]; u8 f99; char pad2[0x2a]; u8 fc4, fc5; } Cx40Cfg;
typedef struct Cx40Self { char pad[0x2c]; Cx40Inner *o; u32 pad4; Cx40Cfg *c; } Cx40Self;
typedef struct Cx40Out { char pad[0x30]; u32 f30; } Cx40Out;

/* 0x887D1308: when the owner hashes match and the config flags are set, queue one of two event hashes. */
u32 ts4_guard_dispatch_887D1308(Cx40Self *s, Cx40Out *out)
{
    Cx40Inner *o = s->o;
    if (o->f238 != 0xFB595DB2u && o->f1d0 == 0xE981B5D1u && o->f348 == 0) {
        Cx40Cfg *c = s->c;
        if (c->f99 == 0) {
            if (c->fc5 != 0) {
                out->f30 = 0x9CF337F8u;
                return fn_887CE478(s, out, 1);
            }
            if (c->fc4 != 0) {
                out->f30 = 0x6A26E8E6u;
                return fn_887CE478(s, out, 1);
            }
        }
    }
    return 0;
}

typedef struct Cx40Inner2 { char pad[0x238]; u32 f238; char pad2[0xc]; u32 f248; } Cx40Inner2;
typedef struct Cx40Self2 { char pad[0x2c]; Cx40Inner2 *o; } Cx40Self2;

/* 0x887D1C78: owner hash pair check, then dispatch event 0x1B0BD1BB. */
u32 ts4_guard_dispatch_887D1C78(Cx40Self2 *s, Cx40Out *out)
{
    Cx40Inner2 *o = s->o;
    if (o->f238 == 0xF202BB09u && o->f248 == 0xF7485E9Fu) {
        out->f30 = 0x1B0BD1BBu;
        return fn_887CE478(s, out, 0);
    }
    return 0;
}
