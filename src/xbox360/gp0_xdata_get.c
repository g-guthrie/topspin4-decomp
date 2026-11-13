#include "gp0_types.h"

/*
 * XData typed value readers (Swing_DLL.xex). A handle names one attribute
 * node of an XData tree: { tree, node id, extra }. Id 0x000FFFFF is the
 * invalid / not-yet-resolved id (see fn_8862BE08, which resolves an XPath
 * string such as "GamePlayInterface:/...@IsOnlineMatch" into a handle).
 * The tree's vtable has, among others:
 *   +0x24 get_value_ptr(tree, handle, node_id, size)
 *   +0x30 has_type(tree, node_id, type_code)       type codes seen: 1 bool, 2 int32, 9 u32/hash
 *   +0x38 create_with_default(tree, handle, node_id, out, size, default_object)
 */
struct Gp0XTree;

struct Gp0XTreeVtbl {
    gp0_u32 slots_00_to_20[9];
    void *(*get_value_ptr)(struct Gp0XTree *tree, void *handle, gp0_u32 node_id, int size);
    gp0_u32 slot_28_2c[2];
    gp0_u8 (*has_type)(struct Gp0XTree *tree, gp0_u32 node_id, int type_code);
    gp0_u32 slot_34;
    void (*create_with_default)(struct Gp0XTree *tree, void *handle, gp0_u32 node_id,
                                void *out, int size, void *default_object);
};

struct Gp0XTree {
    struct Gp0XTreeVtbl *vt;
};

struct Gp0XHandle {
    struct Gp0XTree *tree;
    gp0_u32 node_id;
    gp0_u32 extra;
};

struct Gp0XDefault {
    void *vtbl;
};

extern int lbl_880D4B08;

/* Swing_DLL.xex 0x88163C60: read a bool attribute, creating it with the default value when its type does not match. */
gp0_u8 ts4_gp0_xdata_get_bool_88163C60(struct Gp0XHandle *handle)
{
    struct Gp0XTree *tree = handle->tree;
    gp0_u8 matches = tree->vt->has_type(tree, handle->node_id, 1);
    gp0_u8 result;
    struct Gp0XDefault def;

    tree = handle->tree;
    if (!matches) {
        def.vtbl = &lbl_880D4B08;
        tree->vt->create_with_default(tree, handle, handle->node_id, &result, 1, &def);
        return result;
    }
    return *(gp0_u8 *)tree->vt->get_value_ptr(tree, handle, handle->node_id, 1);
}

extern int lbl_880D4AFC;

extern int lbl_880D4AFC;

/* Swing_DLL.xex 0x88163D18: read an int32 attribute (type code 2), creating it with the default value when its type does not match. */
int ts4_gp0_xdata_get_int32_88163D18(struct Gp0XHandle *handle)
{
    struct Gp0XTree *tree = handle->tree;
    gp0_u8 matches = tree->vt->has_type(tree, handle->node_id, 2);
    int result;
    struct Gp0XDefault def;

    tree = handle->tree;
    if (!matches) {
        def.vtbl = &lbl_880D4AFC;
        tree->vt->create_with_default(tree, handle, handle->node_id, &result, 4, &def);
        return result;
    }
    return *(int *)tree->vt->get_value_ptr(tree, handle, handle->node_id, 4);
}

void fn_88169350(gp0_u32 *out, struct Gp0XHandle *handle);

/* Swing_DLL.xex 0x88165E20: u32 attribute read with default: returns *default_value for an unresolved handle (id 0xFFFFF), else reads the node. */
gp0_u32 *ts4_gp0_xdata_get_u32_or_default_88165E20(gp0_u32 *out, struct Gp0XHandle *handle, gp0_u32 *default_value)
{
    if (handle->node_id == 0x000FFFFF) {
        *out = *default_value;
        return out;
    }
    fn_88169350(out, handle);
    return out;
}
