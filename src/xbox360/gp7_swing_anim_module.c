/*
 * GP7 (WP7): CSwingAnimation module shell and the registration of its two XData node types
 * ("SwingAnimationEngine" 28-byte object, "SwingAnimationEngineController" 32-byte object).
 * The module shell has a no-op Update (vtable slot 2); simulation lives in the engine object
 * whose Update is fn_886E5F50 (see work/gameplay-notes/gp7.md).
 */

extern char lbl_880F36AC[];   /* "SwingAnimationEngine" */
extern char lbl_880F36C4[];   /* "SwingAnimationEngineController" */
extern char lbl_880C8F91[];   /* byte 0: unregister */
extern char lbl_880C8F37[];   /* byte 1: register */
extern void *lbl_88D45B20;    /* node-type registry */

int fn_88608590(int seed, const char *text);          /* crc32(text) */
void ts4_keyed_item_list_add_unique_if_mode_886D2910(void *registry, int *hash, const char *mode);
void ts4_keyed_item_list_add_unique_if_mode_886D1B90(void *registry, int *hash, const char *mode);
void fn_881B9148(void *list);
void fn_88627EC0(void *module, long long a, long long b);

/* Swing_DLL.xex 0x886D75B8: register (mode byte == 1) or unregister the two swing animation node types. */
void ts4_swing_anim_register_node_types_886D75B8(const char *mode)
{
    int hash = fn_88608590(0, lbl_880F36AC);
    ts4_keyed_item_list_add_unique_if_mode_886D2910(lbl_88D45B20, &hash, mode);
    hash = fn_88608590(0, lbl_880F36C4);
    ts4_keyed_item_list_add_unique_if_mode_886D1B90(lbl_88D45B20, &hash, mode);
}

/* Swing_DLL.xex 0x886D8FE0: unregister helper (mode byte 0). */
void ts4_swing_anim_unregister_886D8FE0(void)
{
    ts4_swing_anim_register_node_types_886D75B8(lbl_880C8F91);
}

/* Swing_DLL.xex 0x886D8FF0: register helper (mode byte 1). */
void ts4_swing_anim_register_886D8FF0(void)
{
    ts4_swing_anim_register_node_types_886D75B8(lbl_880C8F37);
}

/* Entry in the engine's table of per-slot AOD/plan request objects (index slot + 0xc of the table). */
struct Gp7PlanRequest {
    unsigned char pad00[0x20];
    int arg_a;               /* +0x20 */
    int armed;               /* +0x24 set to 1 */
    int arg_b;               /* +0x28 */
};

void fn_886D3A00(void *table, struct Gp7PlanRequest *request, int flag);

/* Swing_DLL.xex 0x886D3AB0: fill the request object of `slot` and run it (tail call). */
void ts4_swing_anim_arm_request_886D3AB0(struct Gp7PlanRequest **table, int slot, int arg_a, int arg_b)
{
    struct Gp7PlanRequest *request = table[slot + 0xc];
    request->arg_b = arg_b;
    request->arg_a = arg_a;
    request->armed = 1;
    fn_886D3A00(table, request, 1);
}

/* ---- thunks of the swing request object (this+0x28 = player animation object P, this+0x30 = planner) ---- */
struct Gp7AnimRoot { unsigned char pad[0x94]; unsigned char query_a[0x0c]; unsigned char query_b[1]; };
struct Gp7Engine { unsigned char pad[0x48]; struct Gp7AnimRoot *root; };
struct Gp7PlayerAnimState { unsigned char pad[0x3b5]; unsigned char swing_request; };
struct Gp7PlayerAnim {
    unsigned char pad[0x10];
    struct Gp7Engine *engine;           /* +0x10 owning SwingAnimationEngine */
    struct Gp7PlayerAnimState *state;   /* +0x14 gameplay player state (Gp0PlayerState) */
};
struct Gp7SwingRequester {
    unsigned char pad[0x28];
    struct Gp7PlayerAnim *player;       /* +0x28 */
    unsigned char pad2c[4];
    void *planner;                      /* +0x30 */
};

unsigned char fn_886D3AD8(void *planner, void *query_list);

/* Swing_DLL.xex 0x886D7508: run the clip fitter over query list A when the player state requests a swing. */
unsigned char ts4_swing_anim_fit_list_a_886D7508(struct Gp7SwingRequester *self)
{
    unsigned char found = 0;
    struct Gp7PlayerAnim *player = self->player;
    if (player->state->swing_request) {
        found = fn_886D3AD8(self->planner, (char *)player->engine->root + 0x94);
    }
    return found;
}

/* Swing_DLL.xex 0x886D7540: same as above with query list B. */
unsigned char ts4_swing_anim_fit_list_b_886D7540(struct Gp7SwingRequester *self)
{
    unsigned char found = 0;
    struct Gp7PlayerAnim *player = self->player;
    if (player->state->swing_request) {
        found = fn_886D3AD8(self->planner, (char *)player->engine->root + 0xa0);
    }
    return found;
}
