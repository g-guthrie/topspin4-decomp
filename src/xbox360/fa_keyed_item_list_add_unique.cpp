/* Family A: component pointer-list "add if absent" thunks (Swing_DLL.xex).
   Each function scans the pointer vector [begin,end) for an element whose
   field +4 equals *key; if none, allocates an 8-byte object (vtable, key)
   with the shared allocator and appends its pointer to the vector. */
extern "C" {
extern void *lbl_88D45B38;   /* shared allocator heap, placeholder name */
void *fn_88613268(void *heap, int size, int align, int flags, int tag);
void fn_881898E8(void *vector, void *element_ptr);   /* push_back-like */
extern int lbl_880D56BC;
extern int lbl_880D56C8;
extern int lbl_880D56D4;
extern int lbl_880D56E0;
extern int lbl_880D56EC;
extern int lbl_880D56F8;
extern int lbl_880D5704;
extern int lbl_880D5710;
extern int lbl_880D571C;
extern int lbl_880D5728;
extern int lbl_880D5734;
extern int lbl_880D5740;
extern int lbl_880D574C;
extern int lbl_880D5758;
extern int lbl_880D5764;
extern int lbl_880D5770;
extern int lbl_880D577C;
extern int lbl_880D5788;
extern int lbl_880D5794;
extern int lbl_880D57A0;
extern int lbl_880D57AC;
extern int lbl_880D57B8;
extern int lbl_880D57C4;
extern int lbl_880D57D0;
extern int lbl_880D57DC;
extern int lbl_880D57E8;
extern int lbl_880D57F4;
extern int lbl_880D5800;
extern int lbl_880D580C;
extern int lbl_880D5818;
extern int lbl_880D5824;
extern int lbl_880D5830;
extern int lbl_880D583C;
extern int lbl_880D5848;
extern int lbl_880D60EC;
extern int lbl_880D6D6C;
extern int lbl_880D7198;
extern int lbl_880D71A4;
extern int lbl_880D71B0;
extern int lbl_880D71BC;
extern int lbl_880D71C8;
extern int lbl_880D71D4;
extern int lbl_880D71F8;
extern int lbl_880D7204;
extern int lbl_880D7210;
extern int lbl_880D721C;
extern int lbl_880D7630;
extern int lbl_880DB85C;
extern int lbl_880DB868;
extern int lbl_880DB874;
extern int lbl_880DB880;
extern int lbl_880DB9A4;
extern int lbl_880DB9B0;
extern int lbl_880DB9BC;
extern int lbl_880DB9D0;
extern int lbl_880DB9DC;
extern int lbl_880DB9E8;
extern int lbl_880DB9F4;
extern int lbl_880DBA00;
extern int lbl_880DBA0C;
extern int lbl_880DBA18;
extern int lbl_880DBA24;
extern int lbl_880DBA30;
extern int lbl_880DBA3C;
extern int lbl_880DBA48;
extern int lbl_880DBA54;
extern int lbl_880DBA60;
extern int lbl_880DBA6C;
extern int lbl_880DBA78;
extern int lbl_880DBA84;
extern int lbl_880DBA90;
extern int lbl_880DBA9C;
extern int lbl_880DBAA8;
extern int lbl_880DBAB4;
extern int lbl_880DBAC0;
extern int lbl_880DBACC;
extern int lbl_880DBAD8;
extern int lbl_880DBAE4;
extern int lbl_880DBAF0;
extern int lbl_880DBAFC;
extern int lbl_880DBB08;
extern int lbl_880DBB14;
extern int lbl_880DBB20;
extern int lbl_880DBB2C;
extern int lbl_880DBB38;
extern int lbl_880DBB44;
extern int lbl_880DBB50;
extern int lbl_880DBB5C;
extern int lbl_880DBB68;
extern int lbl_880DBB74;
extern int lbl_880DBB80;
extern int lbl_880DBB8C;
extern int lbl_880DBB98;
extern int lbl_880DBBA4;
extern int lbl_880DBBB0;
extern int lbl_880DBBBC;
extern int lbl_880DBBC8;
extern int lbl_880DBBD4;
extern int lbl_880DBBE0;
extern int lbl_880DBBEC;
extern int lbl_880DBBF8;
extern int lbl_880DC9E4;
extern int lbl_880DC9F0;
extern int lbl_880DC9FC;
extern int lbl_880DCA08;
extern int lbl_880DCA14;
extern int lbl_880DCA20;
extern int lbl_880DCA2C;
extern int lbl_880DCA38;
extern int lbl_880DCA44;
extern int lbl_880DCA50;
extern int lbl_880DCA5C;
extern int lbl_880DCA68;
extern int lbl_880DD8B4;
extern int lbl_880DEF50;
extern int lbl_880DF4C0;
extern int lbl_880DF4CC;
extern int lbl_880DF4D8;
extern int lbl_880DF4E4;
extern int lbl_880DF4F0;
extern int lbl_880DF4FC;
extern int lbl_880DF508;
extern int lbl_880DF990;
extern int lbl_880DFA14;
extern int lbl_880E07A4;
extern int lbl_880E07B0;
extern int lbl_880E07BC;
extern int lbl_880E07C8;
extern int lbl_880E07D4;
extern int lbl_880E07E0;
extern int lbl_880E07EC;
extern int lbl_880E175C;
extern int lbl_880E1768;
extern int lbl_880E1774;
extern int lbl_880E1780;
extern int lbl_880E178C;
extern int lbl_880E1798;
extern int lbl_880E3860;
extern int lbl_880E386C;
extern int lbl_880E3878;
extern int lbl_880E3884;
extern int lbl_880E3890;
extern int lbl_880E389C;
extern int lbl_880E38A8;
extern int lbl_880E38B4;
extern int lbl_880E3ADC;
extern int lbl_880E4380;
extern int lbl_880E447C;
extern int lbl_880E49C4;
extern int lbl_880E49D0;
extern int lbl_880E4D20;
extern int lbl_880E4D2C;
extern int lbl_880E4D38;
extern int lbl_880E4D44;
extern int lbl_880E7280;
extern int lbl_880E728C;
extern int lbl_880E7298;
extern int lbl_880E72A4;
extern int lbl_880E72B0;
extern int lbl_880E72BC;
extern int lbl_880E72C8;
extern int lbl_880E72D4;
extern int lbl_880E72E0;
extern int lbl_880E72EC;
extern int lbl_880E72F8;
extern int lbl_880E7304;
extern int lbl_880E7310;
extern int lbl_880EA3FC;
extern int lbl_880EA408;
extern int lbl_880EA414;
extern int lbl_880EA728;
extern int lbl_880EA734;
extern int lbl_880EA740;
extern int lbl_880EF7AC;
extern int lbl_880EF7FC;
extern int lbl_880EF808;
extern int lbl_880EF814;
extern int lbl_880EF820;
extern int lbl_880EF82C;
extern int lbl_880EF838;
extern int lbl_880EF844;
extern int lbl_880EF850;
extern int lbl_880EF85C;
extern int lbl_880EF868;
extern int lbl_880EF874;
extern int lbl_880F316C;
extern int lbl_880F3178;
extern int lbl_880F3184;
extern int lbl_880F3190;
extern int lbl_880F319C;
extern int lbl_880F31A8;
extern int lbl_880F31B4;
extern int lbl_880F31C0;
extern int lbl_880F31CC;
extern int lbl_880F3568;
extern int lbl_880F3838;
extern int lbl_880F4ED4;
extern int lbl_880F520C;
extern int lbl_880F5218;
extern int lbl_880F5224;
extern int lbl_880F594C;
extern int lbl_880F5958;
extern int lbl_880F5964;
extern int lbl_880F5970;
extern int lbl_880F597C;
extern int lbl_880F5988;
extern int lbl_880F5994;
extern int lbl_880F59A0;
extern int lbl_880F59AC;
extern int lbl_880F59B8;
extern int lbl_880F59C4;
extern int lbl_880F59D0;
extern int lbl_880F59DC;
extern int lbl_880F59E8;
extern int lbl_880F59F4;
extern int lbl_880F5A00;
extern int lbl_880F5A0C;
extern int lbl_880F5A18;
extern int lbl_880F6074;
extern int lbl_880F6334;
extern int lbl_880F6468;
extern int lbl_880F6474;
extern int lbl_880F8DC8;
extern int lbl_880F8DD4;
extern int lbl_880F8DE0;
extern int lbl_880F8DEC;
extern int lbl_880F8DF8;
extern int lbl_880F8E04;
extern int lbl_880F8E10;
extern int lbl_880F8E1C;
extern int lbl_880F8E28;
extern int lbl_880F8E34;
extern int lbl_880F8E40;
extern int lbl_880F8E4C;
extern int lbl_880F8E58;
extern int lbl_880F8E64;
extern int lbl_880F8E70;
extern int lbl_880F8E7C;
extern int lbl_880F8E88;
extern int lbl_880F8E94;
extern int lbl_880F8EA0;
extern int lbl_880F8EAC;
extern int lbl_880F8EB8;
extern int lbl_880F8EC4;
extern int lbl_880F8ED0;
extern int lbl_880F8EDC;
extern int lbl_880F8EE8;
extern int lbl_880F8EF4;
extern int lbl_880F8F00;
extern int lbl_880F8F0C;
extern int lbl_880F8F18;
extern int lbl_880F8F24;
extern int lbl_880F8F30;
extern int lbl_880F8F3C;
extern int lbl_880F8F48;
extern int lbl_880F8F54;
extern int lbl_880F8F60;
extern int lbl_880F8F6C;
extern int lbl_880F8F78;
extern int lbl_880F8F84;
extern int lbl_880F8F90;
extern int lbl_880F8F9C;
extern int lbl_880F8FA8;
extern int lbl_880F8FB4;
extern int lbl_880F8FC0;
extern int lbl_880F8FCC;
extern int lbl_880F8FD8;
extern int lbl_880F8FE4;
}

struct ts4_keyed_item;
struct ts4_item_vector { ts4_keyed_item **begin; ts4_keyed_item **end; };

inline void *operator new(unsigned, void *heap, int size, int align, int flags, int tag)
{ return fn_88613268(heap, size, align, flags, tag); }

#define TS4_KEYED_ITEM_ADD_UNIQUE(NAME, VTBL) \
struct NAME##_item { void *vtbl; unsigned key; \
    NAME##_item(unsigned k) { key = k; vtbl = &VTBL; } }; \
extern "C" void NAME(ts4_item_vector *vec, unsigned *key) \
{ \
    NAME##_item **end = (NAME##_item **)vec->end; \
    NAME##_item **it = (NAME##_item **)vec->begin; \
    unsigned k = *key; \
    for (; it != end; it++) \
        if ((*it)->key == k) return; \
    NAME##_item *tmp = new(lbl_88D45B38, 8, 4, 0, 2) NAME##_item(k); \
    NAME##_item *item = tmp; \
    fn_881898E8(vec, &item); \
}

/* Swing_DLL.xex 0x8861C648 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861C648, lbl_880F8FE4)
/* Swing_DLL.xex 0x8861CE80 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861CE80, lbl_880F8FD8)
/* Swing_DLL.xex 0x8861CF30 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861CF30, lbl_880F8FCC)
/* Swing_DLL.xex 0x8861CFE0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861CFE0, lbl_880F8FC0)
/* Swing_DLL.xex 0x8861D978 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861D978, lbl_880F8FB4)
/* Swing_DLL.xex 0x8861DA28 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861DA28, lbl_880F8FA8)
/* Swing_DLL.xex 0x8861DC48 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861DC48, lbl_880F8F9C)
/* Swing_DLL.xex 0x8861DFB8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861DFB8, lbl_880F8F90)
/* Swing_DLL.xex 0x8861E068 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861E068, lbl_880F8F84)
/* Swing_DLL.xex 0x8861E648 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861E648, lbl_880F8F78)
/* Swing_DLL.xex 0x8861EB08 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861EB08, lbl_880F8F6C)
/* Swing_DLL.xex 0x8861EE78 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861EE78, lbl_880F8F60)
/* Swing_DLL.xex 0x8861EF68 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861EF68, lbl_880F8F54)
/* Swing_DLL.xex 0x8861F0C8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861F0C8, lbl_880F8F48)
/* Swing_DLL.xex 0x8861F2D0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861F2D0, lbl_880F8F3C)
/* Swing_DLL.xex 0x8861F400 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861F400, lbl_880F8F30)
/* Swing_DLL.xex 0x8861F4E8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861F4E8, lbl_880F8F24)
/* Swing_DLL.xex 0x8861F598 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861F598, lbl_880DF508)
/* Swing_DLL.xex 0x8861F648 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861F648, lbl_880F8F18)
/* Swing_DLL.xex 0x8861F6F8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861F6F8, lbl_880F8F0C)
/* Swing_DLL.xex 0x8861F8A0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861F8A0, lbl_880F8F00)
/* Swing_DLL.xex 0x8861FA60 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861FA60, lbl_880F8EF4)
/* Swing_DLL.xex 0x8861FEF8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8861FEF8, lbl_880F8EE8)
/* Swing_DLL.xex 0x886201E0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886201E0, lbl_880F8EDC)
/* Swing_DLL.xex 0x886204D8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886204D8, lbl_880F8ED0)
/* Swing_DLL.xex 0x88620588 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88620588, lbl_880F8EC4)
/* Swing_DLL.xex 0x88620638 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88620638, lbl_880F8EB8)
/* Swing_DLL.xex 0x886206E8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886206E8, lbl_880F8EAC)
/* Swing_DLL.xex 0x88620CD0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88620CD0, lbl_880F8EA0)
/* Swing_DLL.xex 0x88621148 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88621148, lbl_880F8E94)
/* Swing_DLL.xex 0x886212A8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886212A8, lbl_880F8E88)
/* Swing_DLL.xex 0x886213B0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886213B0, lbl_880F8E7C)
/* Swing_DLL.xex 0x886214F8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886214F8, lbl_880F8E70)
/* Swing_DLL.xex 0x88621D30 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88621D30, lbl_880F8E64)
/* Swing_DLL.xex 0x88621EA0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88621EA0, lbl_880F8E58)
/* Swing_DLL.xex 0x88621F50 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88621F50, lbl_880F8E4C)
/* Swing_DLL.xex 0x88622930 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88622930, lbl_880F8E40)
/* Swing_DLL.xex 0x886229E0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886229E0, lbl_880F8E34)
/* Swing_DLL.xex 0x88622B10 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88622B10, lbl_880F8E28)
/* Swing_DLL.xex 0x88622C58 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88622C58, lbl_880F8E1C)
/* Swing_DLL.xex 0x88623030 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88623030, lbl_880F8E10)
/* Swing_DLL.xex 0x886230E0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886230E0, lbl_880F8E04)
/* Swing_DLL.xex 0x88623400 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88623400, lbl_880F8DF8)
/* Swing_DLL.xex 0x88623CE0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88623CE0, lbl_880F8DEC)
/* Swing_DLL.xex 0x88623D90 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88623D90, lbl_880F8DE0)
/* Swing_DLL.xex 0x88623E40 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88623E40, lbl_880F8DD4)
/* Swing_DLL.xex 0x88623EF0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88623EF0, lbl_880F8DC8)
/* Swing_DLL.xex 0x886386C0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886386C0, lbl_880F6474)
/* Swing_DLL.xex 0x88638C60 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88638C60, lbl_880F6468)
/* Swing_DLL.xex 0x88639BD8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88639BD8, lbl_880F6334)
/* Swing_DLL.xex 0x88649138 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88649138, lbl_880F6074)
/* Swing_DLL.xex 0x8864F8A0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8864F8A0, lbl_880F5A18)
/* Swing_DLL.xex 0x8864FD60 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8864FD60, lbl_880F5A0C)
/* Swing_DLL.xex 0x88650380 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88650380, lbl_880F5A00)
/* Swing_DLL.xex 0x88650AD0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88650AD0, lbl_880F59F4)
/* Swing_DLL.xex 0x88650D10 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88650D10, lbl_880F59E8)
/* Swing_DLL.xex 0x88651160 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88651160, lbl_880F59DC)
/* Swing_DLL.xex 0x886515B8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886515B8, lbl_880F59D0)
/* Swing_DLL.xex 0x88651828 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88651828, lbl_880F59C4)
/* Swing_DLL.xex 0x886522E8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886522E8, lbl_880F59B8)
/* Swing_DLL.xex 0x88652398 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88652398, lbl_880F59AC)
/* Swing_DLL.xex 0x88652448 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88652448, lbl_880F59A0)
/* Swing_DLL.xex 0x886524F8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886524F8, lbl_880F5994)
/* Swing_DLL.xex 0x886525A8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886525A8, lbl_880F5988)
/* Swing_DLL.xex 0x88652658 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88652658, lbl_880F597C)
/* Swing_DLL.xex 0x88652708 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88652708, lbl_880F5970)
/* Swing_DLL.xex 0x886527B8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886527B8, lbl_880F5964)
/* Swing_DLL.xex 0x88652868 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88652868, lbl_880F5958)
/* Swing_DLL.xex 0x88652918 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88652918, lbl_880F594C)
/* Swing_DLL.xex 0x88657AE0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88657AE0, lbl_880F5224)
/* Swing_DLL.xex 0x88657EB8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88657EB8, lbl_880F5218)
/* Swing_DLL.xex 0x88658008 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88658008, lbl_880F520C)
/* Swing_DLL.xex 0x8868D418 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8868D418, lbl_880F4ED4)
/* Swing_DLL.xex 0x886D2838 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886D2838, lbl_880F3838)
/* Swing_DLL.xex 0x886E8398 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_886E8398, lbl_880F3568)
/* Swing_DLL.xex 0x88707E20 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88707E20, lbl_880F31CC)
/* Swing_DLL.xex 0x88707FE8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88707FE8, lbl_880F31C0)
/* Swing_DLL.xex 0x88708098 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88708098, lbl_880F31B4)
/* Swing_DLL.xex 0x88708148 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88708148, lbl_880F31A8)
/* Swing_DLL.xex 0x887081F8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887081F8, lbl_880F319C)
/* Swing_DLL.xex 0x887082A8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887082A8, lbl_880F3190)
/* Swing_DLL.xex 0x88708358 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88708358, lbl_880F3184)
/* Swing_DLL.xex 0x887136C0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887136C0, lbl_880F3178)
/* Swing_DLL.xex 0x887137A0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887137A0, lbl_880F316C)
/* Swing_DLL.xex 0x88780FE0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88780FE0, lbl_880EF874)
/* Swing_DLL.xex 0x88781090 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88781090, lbl_880EF868)
/* Swing_DLL.xex 0x88781140 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88781140, lbl_880EF85C)
/* Swing_DLL.xex 0x887811F0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887811F0, lbl_880EF850)
/* Swing_DLL.xex 0x887812A0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887812A0, lbl_880EF844)
/* Swing_DLL.xex 0x887813A0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887813A0, lbl_880EF838)
/* Swing_DLL.xex 0x88781450 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88781450, lbl_880EF82C)
/* Swing_DLL.xex 0x88781500 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88781500, lbl_880EF820)
/* Swing_DLL.xex 0x887815F0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887815F0, lbl_880EF814)
/* Swing_DLL.xex 0x887816F0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887816F0, lbl_880EF808)
/* Swing_DLL.xex 0x887817A0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887817A0, lbl_880EF7FC)
/* Swing_DLL.xex 0x88781B68 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88781B68, lbl_880EF7AC)
/* Swing_DLL.xex 0x887C7F48 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887C7F48, lbl_880EA740)
/* Swing_DLL.xex 0x887C8108 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887C8108, lbl_880EA734)
/* Swing_DLL.xex 0x887C81B8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887C81B8, lbl_880EA728)
/* Swing_DLL.xex 0x887CBC70 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887CBC70, lbl_880EA414)
/* Swing_DLL.xex 0x887CBD90 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887CBD90, lbl_880EA408)
/* Swing_DLL.xex 0x887CBEE0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887CBEE0, lbl_880EA3FC)
/* Swing_DLL.xex 0x887D5B20 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D5B20, lbl_880E7310)
/* Swing_DLL.xex 0x887D5EF8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D5EF8, lbl_880E7304)
/* Swing_DLL.xex 0x887D5FA8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D5FA8, lbl_880E72F8)
/* Swing_DLL.xex 0x887D6058 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D6058, lbl_880E72EC)
/* Swing_DLL.xex 0x887D6108 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D6108, lbl_880E72E0)
/* Swing_DLL.xex 0x887D61B8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D61B8, lbl_880E72D4)
/* Swing_DLL.xex 0x887D6268 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D6268, lbl_880E72C8)
/* Swing_DLL.xex 0x887D6318 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D6318, lbl_880E72BC)
/* Swing_DLL.xex 0x887D63C8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D63C8, lbl_880E72B0)
/* Swing_DLL.xex 0x887D6478 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D6478, lbl_880E72A4)
/* Swing_DLL.xex 0x887D7260 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D7260, lbl_880E7298)
/* Swing_DLL.xex 0x887D7310 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D7310, lbl_880E728C)
/* Swing_DLL.xex 0x887D8E78 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887D8E78, lbl_880E7280)
/* Swing_DLL.xex 0x887EBA48 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887EBA48, lbl_880E4D44)
/* Swing_DLL.xex 0x887EBFC0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887EBFC0, lbl_880E4D38)
/* Swing_DLL.xex 0x887EC070 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887EC070, lbl_880E4D2C)
/* Swing_DLL.xex 0x887EC6F0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887EC6F0, lbl_880E4D20)
/* Swing_DLL.xex 0x887F21F0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887F21F0, lbl_880E49D0)
/* Swing_DLL.xex 0x887F4808 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887F4808, lbl_880E49C4)
/* Swing_DLL.xex 0x887F9F18 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887F9F18, lbl_880E447C)
/* Swing_DLL.xex 0x887FB300 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_887FB300, lbl_880E4380)
/* Swing_DLL.xex 0x88801378 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88801378, lbl_880E3ADC)
/* Swing_DLL.xex 0x88803438 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88803438, lbl_880E38B4)
/* Swing_DLL.xex 0x888034E8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888034E8, lbl_880E38A8)
/* Swing_DLL.xex 0x88803610 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88803610, lbl_880E389C)
/* Swing_DLL.xex 0x888036C0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888036C0, lbl_880E3890)
/* Swing_DLL.xex 0x88803770 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88803770, lbl_880E3884)
/* Swing_DLL.xex 0x88803820 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88803820, lbl_880E3878)
/* Swing_DLL.xex 0x888038D0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888038D0, lbl_880E386C)
/* Swing_DLL.xex 0x88803980 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88803980, lbl_880E3860)
/* Swing_DLL.xex 0x8883E498 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8883E498, lbl_880E1798)
/* Swing_DLL.xex 0x8883E7A0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8883E7A0, lbl_880E178C)
/* Swing_DLL.xex 0x8883EAF8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8883EAF8, lbl_880E1780)
/* Swing_DLL.xex 0x888416A8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888416A8, lbl_880E1774)
/* Swing_DLL.xex 0x88841FE0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88841FE0, lbl_880E1768)
/* Swing_DLL.xex 0x88842C30 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88842C30, lbl_880E175C)
/* Swing_DLL.xex 0x88866FA8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88866FA8, lbl_880E07EC)
/* Swing_DLL.xex 0x888671B0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888671B0, lbl_880E07E0)
/* Swing_DLL.xex 0x88867260 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88867260, lbl_880E07D4)
/* Swing_DLL.xex 0x88867388 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88867388, lbl_880E07C8)
/* Swing_DLL.xex 0x88867438 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88867438, lbl_880E07BC)
/* Swing_DLL.xex 0x888674E8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888674E8, lbl_880E07B0)
/* Swing_DLL.xex 0x888678A8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888678A8, lbl_880E07A4)
/* Swing_DLL.xex 0x88878FA0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88878FA0, lbl_880DFA14)
/* Swing_DLL.xex 0x8887E4A8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8887E4A8, lbl_880DF990)
/* Swing_DLL.xex 0x88887B30 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88887B30, lbl_880DF508)
/* Swing_DLL.xex 0x88887D50 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88887D50, lbl_880DF4FC)
/* Swing_DLL.xex 0x88887E00 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88887E00, lbl_880DF4F0)
/* Swing_DLL.xex 0x88887EB0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88887EB0, lbl_880DF4E4)
/* Swing_DLL.xex 0x88888000 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88888000, lbl_880DF4D8)
/* Swing_DLL.xex 0x888880B0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888880B0, lbl_880DF4CC)
/* Swing_DLL.xex 0x88888160 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88888160, lbl_880DF4C0)
/* Swing_DLL.xex 0x8888C490 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8888C490, lbl_880DEF50)
/* Swing_DLL.xex 0x88890090 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88890090, lbl_880DD8B4)
/* Swing_DLL.xex 0x888B1DC8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B1DC8, lbl_880DCA68)
/* Swing_DLL.xex 0x888B1E78 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B1E78, lbl_880DCA5C)
/* Swing_DLL.xex 0x888B42F8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B42F8, lbl_880DCA50)
/* Swing_DLL.xex 0x888B4810 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B4810, lbl_880DCA44)
/* Swing_DLL.xex 0x888B4FC8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B4FC8, lbl_880DCA38)
/* Swing_DLL.xex 0x888B5080 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B5080, lbl_880DCA2C)
/* Swing_DLL.xex 0x888B7250 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B7250, lbl_880DCA20)
/* Swing_DLL.xex 0x888B73D8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B73D8, lbl_880DCA14)
/* Swing_DLL.xex 0x888B79B0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B79B0, lbl_880DCA08)
/* Swing_DLL.xex 0x888B8138 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B8138, lbl_880DC9FC)
/* Swing_DLL.xex 0x888B81F0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B81F0, lbl_880DC9F0)
/* Swing_DLL.xex 0x888B8338 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888B8338, lbl_880DC9E4)
/* Swing_DLL.xex 0x888CF130 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888CF130, lbl_880DBBF8)
/* Swing_DLL.xex 0x888CF1E0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888CF1E0, lbl_880DBBEC)
/* Swing_DLL.xex 0x888CF3D8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888CF3D8, lbl_880DBBE0)
/* Swing_DLL.xex 0x888CFC18 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888CFC18, lbl_880DBBD4)
/* Swing_DLL.xex 0x888CFCC8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888CFCC8, lbl_880DBBC8)
/* Swing_DLL.xex 0x888CFD88 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888CFD88, lbl_880DBBBC)
/* Swing_DLL.xex 0x888D00A0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D00A0, lbl_880DBBB0)
/* Swing_DLL.xex 0x888D0298 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D0298, lbl_880DBBA4)
/* Swing_DLL.xex 0x888D0420 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D0420, lbl_880DBB98)
/* Swing_DLL.xex 0x888D1AE0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D1AE0, lbl_880DBB8C)
/* Swing_DLL.xex 0x888D1E88 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D1E88, lbl_880DBB80)
/* Swing_DLL.xex 0x888D1F38 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D1F38, lbl_880DBB74)
/* Swing_DLL.xex 0x888D1FE8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D1FE8, lbl_880DBB68)
/* Swing_DLL.xex 0x888D2098 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D2098, lbl_880DBB5C)
/* Swing_DLL.xex 0x888D3280 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D3280, lbl_880DBB50)
/* Swing_DLL.xex 0x888D4C70 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D4C70, lbl_880DBB44)
/* Swing_DLL.xex 0x888D4D20 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D4D20, lbl_880DBB38)
/* Swing_DLL.xex 0x888D4DD0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D4DD0, lbl_880DBB2C)
/* Swing_DLL.xex 0x888D4FA0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D4FA0, lbl_880DBB20)
/* Swing_DLL.xex 0x888D5050 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D5050, lbl_880DBB14)
/* Swing_DLL.xex 0x888D5100 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D5100, lbl_880DBB08)
/* Swing_DLL.xex 0x888D5578 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D5578, lbl_880DBAFC)
/* Swing_DLL.xex 0x888D5628 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D5628, lbl_880DBAF0)
/* Swing_DLL.xex 0x888D5818 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D5818, lbl_880DBAE4)
/* Swing_DLL.xex 0x888D58C8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D58C8, lbl_880DBAD8)
/* Swing_DLL.xex 0x888D60B0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D60B0, lbl_880DBACC)
/* Swing_DLL.xex 0x888D6160 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D6160, lbl_880DBAC0)
/* Swing_DLL.xex 0x888D6210 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D6210, lbl_880DBAB4)
/* Swing_DLL.xex 0x888D62C0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D62C0, lbl_880DBAA8)
/* Swing_DLL.xex 0x888D6370 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D6370, lbl_880DBA9C)
/* Swing_DLL.xex 0x888D6420 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D6420, lbl_880DBA90)
/* Swing_DLL.xex 0x888D64D0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D64D0, lbl_880DBA84)
/* Swing_DLL.xex 0x888D6770 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D6770, lbl_880DBA78)
/* Swing_DLL.xex 0x888D6820 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D6820, lbl_880DBA6C)
/* Swing_DLL.xex 0x888D68D0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D68D0, lbl_880DBA60)
/* Swing_DLL.xex 0x888D6980 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D6980, lbl_880DBA54)
/* Swing_DLL.xex 0x888D6AB8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D6AB8, lbl_880DBA48)
/* Swing_DLL.xex 0x888D6B68 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D6B68, lbl_880DBA3C)
/* Swing_DLL.xex 0x888D6F00 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D6F00, lbl_880DBA30)
/* Swing_DLL.xex 0x888D76F0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D76F0, lbl_880DBA00)
/* Swing_DLL.xex 0x888D77A0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D77A0, lbl_880DB9F4)
/* Swing_DLL.xex 0x888D7AE8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D7AE8, lbl_880DB9E8)
/* Swing_DLL.xex 0x888D7B98 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D7B98, lbl_880DB9DC)
/* Swing_DLL.xex 0x888D7C48 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D7C48, lbl_880DB9D0)
/* Swing_DLL.xex 0x888D7D98 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D7D98, lbl_880DB9BC)
/* Swing_DLL.xex 0x888D7E48 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D7E48, lbl_880DB9B0)
/* Swing_DLL.xex 0x888D7EF8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D7EF8, lbl_880DB9A4)
/* Swing_DLL.xex 0x888D8180 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D8180, lbl_880DB880)
/* Swing_DLL.xex 0x888D8230 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D8230, lbl_880DB874)
/* Swing_DLL.xex 0x888D8680 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D8680, lbl_880DB868)
/* Swing_DLL.xex 0x888D88B8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D88B8, lbl_880DB85C)
/* Swing_DLL.xex 0x888D8968 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D8968, lbl_880DBA24)
/* Swing_DLL.xex 0x888D8A18 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D8A18, lbl_880DBA18)
/* Swing_DLL.xex 0x888D8B68 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_888D8B68, lbl_880DBA0C)
/* Swing_DLL.xex 0x8890F070 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8890F070, lbl_880D7630)
/* Swing_DLL.xex 0x88912FE8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88912FE8, lbl_880D721C)
/* Swing_DLL.xex 0x88913098 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88913098, lbl_880D7210)
/* Swing_DLL.xex 0x88913148 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88913148, lbl_880D7204)
/* Swing_DLL.xex 0x889131F8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889131F8, lbl_880D71F8)
/* Swing_DLL.xex 0x889132A8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889132A8, lbl_880D7204)
/* Swing_DLL.xex 0x88913368 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88913368, lbl_880D7204)
/* Swing_DLL.xex 0x88913428 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88913428, lbl_880D71D4)
/* Swing_DLL.xex 0x889134D8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889134D8, lbl_880D71C8)
/* Swing_DLL.xex 0x88913588 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88913588, lbl_880D71BC)
/* Swing_DLL.xex 0x88913638 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88913638, lbl_880D71B0)
/* Swing_DLL.xex 0x889137B0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889137B0, lbl_880D71A4)
/* Swing_DLL.xex 0x889138F0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889138F0, lbl_880D7198)
/* Swing_DLL.xex 0x88918DF8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88918DF8, lbl_880D6D6C)
/* Swing_DLL.xex 0x8893A8F0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8893A8F0, lbl_880D60EC)
/* Swing_DLL.xex 0x8894BE80 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894BE80, lbl_880D5848)
/* Swing_DLL.xex 0x8894BF30 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894BF30, lbl_880D583C)
/* Swing_DLL.xex 0x8894C1B8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894C1B8, lbl_880D5830)
/* Swing_DLL.xex 0x8894C268 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894C268, lbl_880D5824)
/* Swing_DLL.xex 0x8894C610 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894C610, lbl_880D5818)
/* Swing_DLL.xex 0x8894C6C0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894C6C0, lbl_880D580C)
/* Swing_DLL.xex 0x8894C770 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894C770, lbl_880D5800)
/* Swing_DLL.xex 0x8894D488 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894D488, lbl_880D57F4)
/* Swing_DLL.xex 0x8894D538 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894D538, lbl_880D57E8)
/* Swing_DLL.xex 0x8894D5E8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894D5E8, lbl_880D57DC)
/* Swing_DLL.xex 0x8894D6F8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894D6F8, lbl_880D57D0)
/* Swing_DLL.xex 0x8894D7A8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894D7A8, lbl_880D57C4)
/* Swing_DLL.xex 0x8894D968 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894D968, lbl_880D57B8)
/* Swing_DLL.xex 0x8894E1F8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894E1F8, lbl_880D57AC)
/* Swing_DLL.xex 0x8894EBE8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_8894EBE8, lbl_880D57A0)
/* Swing_DLL.xex 0x889511E8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889511E8, lbl_880D5794)
/* Swing_DLL.xex 0x88951298 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88951298, lbl_880D5788)
/* Swing_DLL.xex 0x88951348 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88951348, lbl_880D577C)
/* Swing_DLL.xex 0x889513F8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889513F8, lbl_880D5770)
/* Swing_DLL.xex 0x889514A8 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889514A8, lbl_880D5764)
/* Swing_DLL.xex 0x88951558 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88951558, lbl_880D5758)
/* Swing_DLL.xex 0x88951730 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88951730, lbl_880D574C)
/* Swing_DLL.xex 0x88951A60 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88951A60, lbl_880D5740)
/* Swing_DLL.xex 0x88951D10 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88951D10, lbl_880D5734)
/* Swing_DLL.xex 0x88951F20 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88951F20, lbl_880D5728)
/* Swing_DLL.xex 0x88951FD0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88951FD0, lbl_880D571C)
/* Swing_DLL.xex 0x88952080 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88952080, lbl_880D5710)
/* Swing_DLL.xex 0x88952130 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88952130, lbl_880D5704)
/* Swing_DLL.xex 0x889521E0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889521E0, lbl_880D56F8)
/* Swing_DLL.xex 0x88952290 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88952290, lbl_880D56EC)
/* Swing_DLL.xex 0x88952340 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88952340, lbl_880D56E0)
/* Swing_DLL.xex 0x889523F0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889523F0, lbl_880D56D4)
/* Swing_DLL.xex 0x889524A0 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_889524A0, lbl_880D56C8)
/* Swing_DLL.xex 0x88952550 */ TS4_KEYED_ITEM_ADD_UNIQUE(ts4_keyed_item_list_add_unique_88952550, lbl_880D56BC)
