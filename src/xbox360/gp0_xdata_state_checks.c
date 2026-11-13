#include "gp0_types.h"

struct Gp0XHandle {
    void *tree;
    gp0_u32 node_id;
    gp0_u32 extra;
};

struct Gp0XHandle *fn_8862BE08(struct Gp0XHandle *out, const char *xpath);
void fn_88169350(gp0_u32 *out, struct Gp0XHandle *handle);
gp0_u8 ts4_gp0_xdata_get_bool_88163C60(struct Gp0XHandle *handle);

extern gp0_u8 lbl_88C4589D;
/* strings in .rdata (placeholder symbols; text in the comments) */
extern const char lbl_880D8D64[];   /* "SystemData:/SystemData/Scheduler/SubModuleManager/@NextModule" */
extern const char lbl_880D8270[];   /* "GamePlayInterface:/SwingGameplayInterface/GameplayInputs/NetConfig/@IsOnlineMatch" */

/*
 * Swing_DLL.xex 0x887911B8: true when the scheduler's pending SubModuleManager/@NextModule is the
 * InGame scene (hash 0x1DCA7285 == crc32("InGame")) or scene 0xF202BB09, the match is not online
 * (GameplayInputs/NetConfig/@IsOnlineMatch false) and the global flag lbl_88C4589D is set.
 */
gp0_u8 ts4_gp0_next_module_is_local_match_887911B8(void)
{
    gp0_u8 result = 0;
    struct Gp0XHandle next_module_handle;
    gp0_u32 next_module;
    struct Gp0XHandle online_handle;
    gp0_u8 is_online;

    fn_8862BE08(&next_module_handle, lbl_880D8D64);
    fn_88169350(&next_module, &next_module_handle);
    fn_8862BE08(&online_handle, lbl_880D8270);
    is_online = ts4_gp0_xdata_get_bool_88163C60(&online_handle);
    if (lbl_88C4589D != 0 && !is_online) {
        if (next_module == 0x1DCA7285 || next_module == 0xF202BB09) {
            result = 1;
        }
    }
    return result;
}
