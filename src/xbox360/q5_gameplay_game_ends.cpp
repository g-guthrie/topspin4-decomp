/* Q5: set up a game's ends and server (0x886775C8).
 * Unless the match state is frozen: puts the two players at their ends for this
 * game (they swap every six games of a twelve-game cycle) and records whether
 * the ends changed, picks the court half by game parity, asks the virtual
 * server_for() who serves, and seeds each player's slot value from the serve
 * rotation (mod 1 for singles, 2 for doubles).
 * Codegen (needs /Oc for the trap-free divw):
 *  - `count` goes through the u32& accessor serve_changes(), used for both the
 *    increment and the test; that gives the target's `clrrwi r8,r9,0` copy
 *    (late-removed load, docs/agents/near-misses/CL1.md);
 *  - q5_seed() is inlined with a literal 0 or 1, so `0 % n` stays unfolded;
 *  - the half store is an if/else, not a ternary; server() is an inline member.
 * Sister 0x88677190 has identical code (near-miss draft:
 * src/xbox360/drafts/me_88677190_nearmiss.c). */
typedef unsigned int u32;
typedef unsigned char u8;
struct Q5Slot { int value; u32 end; };
struct Q5Slots { int offset; char p4[8]; int server; u32 half;
    Q5Slot *at(int i) { return (Q5Slot *)((char *)this + (i * 8 + offset)); } };
struct Q5Side;
static inline void q5_seed(Q5Slots *t, int a, int b, int v, int n) { int r = v % n; t->at(a)->value = r; t->at(b)->value = r; }
struct Q5Side { char p[0x48]; Q5Slots slots; };
struct Q5State { char p[0x93]; u8 frozen; u8 ends_changed; char p2[0x327 - 0x95]; u8 doubles; };
struct Q5Ctx { char p[0x30]; Q5State *state; char p2[0x44 - 0x34]; Q5Side *side; int match; };
class Q5Game { public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual int server_for(int match); /* +0x20 */
    void setup_ends_and_server();
    u32 &serve_changes() { return count; }
    int server() { return server_for(ctx->match); }
    Q5Ctx *ctx; u32 p8; u32 game; u32 count; int last_server; int rotation;
};
void Q5Game::setup_ends_and_server()
{
    if (ctx->state->frozen)
        return;
    Q5Slots *t = &ctx->side->slots;
    Q5Slot *s0 = t->at(0);
    u32 prev = s0->end;
    if (game % 12 < 6) { s0->end = 0x317C51B7; t->at(1)->end = 0xA2EDA1E7; }
    else { s0->end = 0xA2EDA1E7; t->at(1)->end = 0x317C51B7; }
    ctx->state->ends_changed = t->at(0)->end != prev;
    if ((game & 1) == 0) t->half = 0x23BAED9E;
    else t->half = 0xD826E563;
    int server = this->server();
    t->server = server;
    int other = 1 - server;
    int n = ctx->state->doubles ? 2 : 1;
    if (server != last_server) {
        serve_changes()++;
        if ((serve_changes() & 3) < 2) q5_seed(t, server, other, 0, n);
        else q5_seed(t, server, other, 1, n);
    } else {
        t->at(other)->value = (1 - rotation) % n;
    }
}
