typedef unsigned int u32;

typedef struct Ts4SessionStats {
    u32 field_0;
    u32 field_4;
    unsigned char reserved_8[0x48];
    u32 field_50;
    u32 field_54;
    unsigned char reserved_58[4];
    u32 field_5c;
    unsigned char reserved_60[0xC];
    u32 field_6c;
    u32 field_70;
    u32 field_74;
    unsigned char reserved_78[4];
    u32 field_7c;
    u32 field_80;
    unsigned char reserved_84[0xC];
    u32 field_90;
} Ts4SessionStats;

extern void ts4_init_search_result(Ts4SessionStats *object);

/* Swing_DLL.xex 0x88150E50. */
Ts4SessionStats *ts4_session_stats_init(Ts4SessionStats *object)
{
    object->field_4 = 0;
    object->field_50 = 0;
    object->field_54 = 0;
    object->field_5c = 0;
    object->field_6c = 0;
    object->field_70 = 0;
    object->field_74 = 0;
    object->field_7c = 0;
    object->field_80 = 0;
    object->field_90 = 0;
    ts4_init_search_result(object);
    return object;
}
