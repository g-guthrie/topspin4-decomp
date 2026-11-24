/* Family FAM1: Havok reflection class registrations (dynamic initializers of the hk*Class globals).
 * Each function constructs one hkClass object (fn_8841F080 is the hkClass constructor) from its name,
 * parent class, object size, enum table, member table and default-values block.
 * The enum table and the defaults block (or member table) are statics of the original translation unit, so
 * the compiler reaches the second one from the enum table's base register. The statics below reproduce that
 * layout; their contents are placeholders (only sizes and order matter for code generation, the real data lives
 * in the game image at the lbl_ addresses). */

typedef struct ts4_hk_class_enum {
    const char *name;
    const void *items;
    int num_items;
    const void *attributes;
    unsigned int flags;
} ts4_hk_class_enum;

#ifdef _MSC_VER
#define TS4_HK_SEG(A) __pragma(const_seg(".rdata$hk" #A))
#else
#define TS4_HK_SEG(A)
#endif

#ifdef _MSC_VER
#define TS4_HK_UNUSED
#else
#define TS4_HK_UNUSED __attribute__((unused))
#endif
/* Gap between the enum table and the defaults block, as 4-byte-aligned chunks of at most 28 bytes so the
 * compiler does not 16-byte align them (which would let it move the defaults block into the hole). */
#define TS4_HK_GAP_1(A) static const int ts4_hk_gap0_##A[1] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_9(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[2] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_11(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[4] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_13(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[6] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_15(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap2_##A[1] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_16(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap2_##A[2] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_17(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap2_##A[3] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_30(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap2_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap3_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap4_##A[2] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_38(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap2_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap3_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap4_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap5_##A[3] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_41(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap2_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap3_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap4_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap5_##A[6] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_44(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap2_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap3_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap4_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap5_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap6_##A[2] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_45(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap2_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap3_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap4_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap5_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap6_##A[3] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_53(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap2_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap3_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap4_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap5_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap6_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap7_##A[4] TS4_HK_UNUSED = {1};
#define TS4_HK_GAP_157(A) static const int ts4_hk_gap0_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap1_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap2_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap3_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap4_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap5_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap6_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap7_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap8_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap9_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap10_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap11_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap12_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap13_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap14_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap15_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap16_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap17_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap18_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap19_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap20_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap21_##A[7] TS4_HK_UNUSED = {1}; static const int ts4_hk_gap22_##A[3] TS4_HK_UNUSED = {1};

/* this, name, parent, object size, interfaces, num interfaces, enums, num enums, members, num members,
 * defaults, attributes, flags */
extern void fn_8841F080(char *self, const char *name, const char *parent, int object_size, const void *interfaces,
                        int num_interfaces, const ts4_hk_class_enum *enums, int num_enums, const void *members,
                        int num_members, const void *defaults, const void *attributes, unsigned int flags);

/* Registration with an extern member table and a static defaults block after the enum table. */
#define TS4_HK_CLASS_REG_DEF(A, obj, name, parent, size, enums, ne, members, nm)                              \
    TS4_HK_SEG(A) static const ts4_hk_class_enum enums[ne] = {{0, 0, 1, 0, 0}};                                            \
    static const int ts4_hk_defaults_##A[1] = {1};                                                           \
    void ts4_hk_class_register_##A(void)                                                                    \
    {                                                                                                        \
        fn_8841F080(obj, name, parent, size, 0, 0, enums, ne, members, nm, ts4_hk_defaults_##A, 0, 0);       \
    }
#define TS4_HK_CLASS_REG_DEF_PAD(A, obj, name, parent, size, enums, ne, pad, members, nm)                     \
    TS4_HK_SEG(A) static const ts4_hk_class_enum enums[ne] = {{0, 0, 1, 0, 0}};                                            \
    TS4_HK_GAP_##pad(A)                                \
    static const int ts4_hk_defaults_##A[1] = {1};                                                           \
    void ts4_hk_class_register_##A(void)                                                                    \
    {                                                                                                        \
        fn_8841F080(obj, name, parent, size, 0, 0, enums, ne, members, nm, ts4_hk_defaults_##A, 0, 0);       \
    }
/* Registration with a static member table after the enum table and no defaults. */
#define TS4_HK_CLASS_REG_MEM(A, obj, name, parent, size, enums, ne, nm)                                       \
    TS4_HK_SEG(A) static const ts4_hk_class_enum enums[ne] = {{0, 0, 1, 0, 0}};                                            \
    static const int ts4_hk_members_##A[1] = {1};                                                            \
    void ts4_hk_class_register_##A(void)                                                                    \
    {                                                                                                        \
        fn_8841F080(obj, name, parent, size, 0, 0, enums, ne, ts4_hk_members_##A, nm, 0, 0, 0);               \
    }
#define TS4_HK_CLASS_REG_MEM_PAD(A, obj, name, parent, size, enums, ne, pad, nm)                              \
    TS4_HK_SEG(A) static const ts4_hk_class_enum enums[ne] = {{0, 0, 1, 0, 0}};                                            \
    TS4_HK_GAP_##pad(A)                                \
    static const int ts4_hk_members_##A[1] = {1};                                                            \
    void ts4_hk_class_register_##A(void)                                                                    \
    {                                                                                                        \
        fn_8841F080(obj, name, parent, size, 0, 0, enums, ne, ts4_hk_members_##A, nm, 0, 0, 0);               \
    }

extern char lbl_8803AA14[];
extern char lbl_8803ED14[];
extern char lbl_8803EF9C[];
extern char lbl_8803EFC0[];
extern char lbl_8803EFFC[];
extern char lbl_8803F6CC[];
extern char lbl_88040218[];
extern char lbl_88040244[];
extern char lbl_880410F8[];
extern char lbl_880411B0[];
extern char lbl_88041210[];
extern char lbl_88041238[];
extern char lbl_8804124C[];
extern char lbl_88041E68[];
extern char lbl_88045420[];
extern char lbl_88045604[];
extern char lbl_88045818[];
extern char lbl_88045AD0[];
extern char lbl_8804601C[];
extern char lbl_88046038[];
extern char lbl_88046798[];
extern char lbl_880467EC[];
extern char lbl_8804683C[];
extern char lbl_88048224[];
extern char lbl_8804881C[];
extern char lbl_88048838[];
extern char lbl_88048860[];
extern char lbl_88049410[];
extern char lbl_88073D08[];
extern char lbl_8807CD6C[];
extern char lbl_88080598[];
extern char lbl_88083A88[];
extern char lbl_88B46790[];
extern char lbl_88B4B8E8[];
extern char lbl_88B51060[];
extern char lbl_88B56790[];
extern char lbl_88B5BF80[];
extern char lbl_88B61770[];
extern char lbl_88B67960[];
extern char lbl_88B67A80[];
extern char lbl_88B67C18[];
extern char lbl_88B68500[];
extern char lbl_88B6E970[];
extern char lbl_88B6EA90[];
extern char lbl_88B6EC28[];
extern char lbl_88B6F210[];
extern char lbl_88B6F4E0[];
extern char lbl_88B72488[];
extern char lbl_88B75988[];
extern char lbl_88B75AA8[];
extern char lbl_88B75C40[];
extern char lbl_88B76228[];
extern char lbl_88B764F8[];
extern char lbl_88B795C8[];
extern char lbl_88B7CAC8[];
extern char lbl_88B7CC18[];
extern char lbl_88B7CDB0[];
extern char lbl_88B7CEB8[];
extern char lbl_88B7D3E0[];
extern char lbl_88B7D6B0[];
extern char lbl_88B80870[];
extern char lbl_88B83D70[];
extern char lbl_88B83ED8[];
extern char lbl_88B84070[];
extern char lbl_88B84178[];
extern char lbl_88B84700[];
extern char lbl_88B849D0[];
extern char lbl_88B87CB8[];
extern char lbl_88B8B330[];
extern char lbl_88B8B498[];
extern char lbl_88B8B630[];
extern char lbl_88B8B738[];
extern char lbl_88B8BE10[];
extern char lbl_88B8C128[];
extern char lbl_88B8F470[];
extern char lbl_88B92AE8[];
extern char lbl_88B92C50[];
extern char lbl_88B92DE8[];
extern char lbl_88B92EF0[];
extern char lbl_88B935C8[];
extern char lbl_88B938E0[];
extern char lbl_88B94848[];
extern char lbl_88B97638[];
extern char lbl_88B990C0[];
extern char lbl_88B9AF60[];
extern char lbl_88B9B998[];
extern char lbl_88B9BBA8[];
extern char lbl_88B9BEA8[];
extern char lbl_88B9C298[];
extern char lbl_88B9D278[];
extern char lbl_88BA0080[];
extern char lbl_88BA1B20[];
extern char lbl_88BA39C0[];
extern char lbl_88BA43F8[];
extern char lbl_88BA45F0[];
extern char lbl_88BA4908[];
extern char lbl_88BA4CF8[];
extern char lbl_88BA5F98[];
extern char lbl_88BA9B38[];
extern char lbl_88BAB638[];
extern char lbl_88BAD4D8[];
extern char lbl_88BADFD0[];
extern char lbl_88BAE1C8[];
extern char lbl_88BAE4E0[];
extern char lbl_88BAE870[];
extern char lbl_88BAFB88[];
extern char lbl_88BB35A8[];
extern char lbl_88BB50B0[];
extern char lbl_88BB6F50[];
extern char lbl_88BB7358[];
extern char lbl_88BB7C10[];
extern char lbl_88BB7E08[];
extern char lbl_88BB8120[];
extern char lbl_88BB84B0[];
extern char lbl_88BB97E0[];
extern char lbl_88BBD410[];
extern char lbl_88BBF0B0[];
extern char lbl_88BC1090[];
extern char lbl_88BC14C8[];
extern char lbl_88BC1DB0[];
extern char lbl_88BC1FF0[];
extern char lbl_88BC2308[];
extern char lbl_88BC2698[];
extern char lbl_88BC3B00[];
extern char lbl_88BC7748[];
extern char lbl_88BC93E8[];
extern char lbl_88BCB3C8[];
extern char lbl_88BCB800[];
extern char lbl_88BCC0E8[];
extern char lbl_88BCC328[];
extern char lbl_88BCC640[];
extern char lbl_88BCC9D0[];
extern char lbl_88BCDD48[];
extern char lbl_88BD19B0[];
extern char lbl_88BD37C0[];
extern char lbl_88BD5798[];
extern char lbl_88BD5BD0[];
extern char lbl_88BD64D0[];
extern char lbl_88BD6728[];
extern char lbl_88BD6A40[];
extern char lbl_88BD6DD0[];
extern char lbl_88BD8148[];
extern char lbl_88BDBE10[];
extern char lbl_88BDDC20[];
extern char lbl_88BDFBF8[];
extern char lbl_88BE0030[];
extern char lbl_88BE0A20[];
extern char lbl_88BE0C78[];
extern char lbl_88BE0F90[];
extern char lbl_88BE1320[];
extern char lbl_88BE2898[];
extern char lbl_88BE4F38[];
extern char lbl_88BE7038[];
extern char lbl_88BE8BC8[];
extern char lbl_88BEB1C0[];
extern char lbl_88BEB268[];
extern char lbl_88BEB790[];
extern char lbl_88BEC2D0[];
extern char lbl_88BECF18[];
extern char lbl_88BED170[];
extern char lbl_88BED428[];
extern char lbl_88BED800[];
extern char lbl_88BEEEE8[];
extern char lbl_88BF1450[];
extern char lbl_88BF3548[];
extern char lbl_88BF50F0[];
extern char lbl_88BF76F0[];
extern char lbl_88BF7930[];
extern char lbl_88BF7C90[];
extern char lbl_88BF8818[];
extern char lbl_88BF9460[];
extern char lbl_88BF96D0[];
extern char lbl_88BF9988[];
extern char lbl_88BF9D78[];
extern char lbl_88BFB478[];
extern char lbl_88BFDBA8[];
extern char lbl_88BFFCA8[];
extern char lbl_88C01868[];
extern char lbl_88C03E60[];
extern char lbl_88C040A0[];
extern char lbl_88C04418[];
extern char lbl_88C04FA0[];
extern char lbl_88C05BE8[];
extern char lbl_88C05E58[];
extern char lbl_88C06110[];
extern char lbl_88C06500[];
extern char lbl_88C07DE0[];
extern char lbl_88C0A120[];
extern char lbl_88C0A780[];
extern char lbl_88C0C7F8[];
extern char lbl_88C0E3A8[];
extern char lbl_88C10BB8[];
extern char lbl_88C10E10[];
extern char lbl_88C10F78[];
extern char lbl_88C11188[];
extern char lbl_88C11260[];
extern char lbl_88C113F8[];
extern char lbl_88C11F98[];
extern char lbl_88C12C10[];
extern char lbl_88C12FA0[];
extern char lbl_88C13060[];
extern char lbl_88C13450[];
extern char lbl_88C14DA8[];
extern char lbl_88C17118[];
extern char lbl_88C17778[];
extern char lbl_88C197F0[];
extern char lbl_88C1B3D0[];
extern char lbl_88C1DB68[];
extern char lbl_88C1DDC0[];
extern char lbl_88C1DF28[];
extern char lbl_88C1E138[];
extern char lbl_88C1E210[];
extern char lbl_88C1E3A8[];
extern char lbl_88C1EF48[];
extern char lbl_88C1FBC0[];
extern char lbl_88C1FF50[];
extern char lbl_88C20010[];
extern char lbl_88C20400[];
extern char lbl_88C21028[];
extern char lbl_88C21320[];
extern char lbl_88C236A0[];
extern char lbl_88C23D38[];
extern char lbl_88CACA88[];
extern char lbl_88CACF0C[];
extern char lbl_88CB04A4[];
extern char lbl_88CB20C4[];
extern char lbl_88CB303C[];
extern char lbl_88CB4FEC[];
extern char lbl_88CB5FF4[];
extern char lbl_88CB81E4[];
extern char lbl_88CB933C[];
extern char lbl_88CBB4CC[];
extern char lbl_88CBC6B4[];
extern char lbl_88CBE874[];
extern char lbl_88CBFA5C[];
extern char lbl_88CC1C1C[];
extern char lbl_88CC2EC4[];
extern char lbl_88CC2FE4[];
extern char lbl_88CC30A4[];
extern char lbl_88CC31F4[];
extern char lbl_88CC3254[];
extern char lbl_88CC3554[];
extern char lbl_88CC57A4[];
extern char lbl_88CC6A4C[];
extern char lbl_88CC6B6C[];
extern char lbl_88CC6BFC[];
extern char lbl_88CC6D4C[];
extern char lbl_88CC6DDC[];
extern char lbl_88CC713C[];
extern char lbl_88CC857C[];
extern char lbl_88CC887C[];
extern char lbl_88CC983C[];
extern char lbl_88CCA9F4[];
extern char lbl_88CCAB14[];
extern char lbl_88CCABA4[];
extern char lbl_88CCACF4[];
extern char lbl_88CCAD84[];
extern char lbl_88CCB114[];
extern char lbl_88CCBF54[];
extern char lbl_88CCC0A4[];
extern char lbl_88CCC584[];
extern char lbl_88CCC884[];
extern char lbl_88CCD814[];
extern char lbl_88CCE9FC[];
extern char lbl_88CCEB1C[];
extern char lbl_88CCEBAC[];
extern char lbl_88CCED8C[];
extern char lbl_88CCEE1C[];
extern char lbl_88CCF0EC[];
extern char lbl_88CCF11C[];
extern char lbl_88CCF20C[];
extern char lbl_88CD004C[];
extern char lbl_88CD019C[];
extern char lbl_88CD067C[];
extern char lbl_88CD097C[];
extern char lbl_88CD190C[];
extern char lbl_88CD2AF4[];
extern char lbl_88CD2C14[];
extern char lbl_88CD2CA4[];
extern char lbl_88CD2E84[];
extern char lbl_88CD2F14[];
extern char lbl_88CD31E4[];
extern char lbl_88CD3214[];
extern char lbl_88CD3304[];
extern char lbl_88CD4144[];
extern char lbl_88CD4294[];
extern char lbl_88CD4774[];
extern char lbl_88CD4A74[];
extern char lbl_88CD5A04[];
extern char lbl_88CD6BEC[];
extern char lbl_88CD6D0C[];
extern char lbl_88CD6D9C[];
extern char lbl_88CD6F7C[];
extern char lbl_88CD700C[];
extern char lbl_88CD72DC[];
extern char lbl_88CD730C[];
extern char lbl_88CD73FC[];
extern char lbl_88CD82CC[];
extern char lbl_88CD841C[];
extern char lbl_88CD89BC[];
extern char lbl_88CD8CBC[];
extern char lbl_88CD9C4C[];
extern char lbl_88CDAE34[];
extern char lbl_88CDAF54[];
extern char lbl_88CDAFE4[];
extern char lbl_88CDB1C4[];
extern char lbl_88CDB254[];
extern char lbl_88CDB524[];
extern char lbl_88CDB554[];
extern char lbl_88CDB644[];
extern char lbl_88CDC514[];
extern char lbl_88CDC664[];
extern char lbl_88CDCC04[];
extern char lbl_88CDCF04[];
extern char lbl_88CDDE94[];
extern char lbl_88CDF13C[];
extern char lbl_88CDF1FC[];
extern char lbl_88CDF22C[];
extern char lbl_88CDFDFC[];
extern char lbl_88CE0E1C[];
extern char lbl_88CE0E4C[];
extern char lbl_88CE0F9C[];
extern char lbl_88CE105C[];
extern char lbl_88CE11AC[];
extern char lbl_88CE16BC[];
extern char lbl_88CE19BC[];
extern char lbl_88CE25BC[];
extern char lbl_88CE29DC[];
extern char lbl_88CE2A0C[];
extern char lbl_88CE3CE4[];
extern char lbl_88CE3DA4[];
extern char lbl_88CE3DD4[];
extern char lbl_88CE49A4[];
extern char lbl_88CE59C4[];
extern char lbl_88CE59F4[];
extern char lbl_88CE5B44[];
extern char lbl_88CE5C04[];
extern char lbl_88CE5D54[];
extern char lbl_88CE6264[];
extern char lbl_88CE6564[];
extern char lbl_88CE7164[];
extern char lbl_88CE7584[];
extern char lbl_88CE75B4[];
extern char lbl_88CE894C[];
extern char lbl_88CE8A6C[];
extern char lbl_88CE8A9C[];
extern char lbl_88CE978C[];
extern char lbl_88CEAB3C[];
extern char lbl_88CEAB6C[];
extern char lbl_88CEACBC[];
extern char lbl_88CEAD7C[];
extern char lbl_88CEAECC[];
extern char lbl_88CEB3DC[];
extern char lbl_88CEB6DC[];
extern char lbl_88CEC2DC[];
extern char lbl_88CEC6FC[];
extern char lbl_88CEC72C[];
extern char lbl_88CEDAC4[];
extern char lbl_88CEDBE4[];
extern char lbl_88CEDC14[];
extern char lbl_88CEE634[];
extern char lbl_88CEE904[];
extern char lbl_88CEFC54[];
extern char lbl_88CEFC84[];
extern char lbl_88CEFDD4[];
extern char lbl_88CEFE94[];
extern char lbl_88CEFFE4[];
extern char lbl_88CF04F4[];
extern char lbl_88CF07F4[];
extern char lbl_88CF13F4[];
extern char lbl_88CF1814[];
extern char lbl_88CF1844[];
extern char lbl_88CF2BAC[];
extern char lbl_88CF2CCC[];
extern char lbl_88CF2CFC[];
extern char lbl_88CF371C[];
extern char lbl_88CF3A1C[];
extern char lbl_88CF4D9C[];
extern char lbl_88CF4DCC[];
extern char lbl_88CF4F1C[];
extern char lbl_88CF4FDC[];
extern char lbl_88CF512C[];
extern char lbl_88CF566C[];
extern char lbl_88CF599C[];
extern char lbl_88CF65CC[];
extern char lbl_88CF69EC[];
extern char lbl_88CF6A1C[];
extern char lbl_88CF7EA4[];
extern char lbl_88CF7FC4[];
extern char lbl_88CF7FF4[];
extern char lbl_88CF8A14[];
extern char lbl_88CF8D14[];
extern char lbl_88CFA094[];
extern char lbl_88CFA0C4[];
extern char lbl_88CFA214[];
extern char lbl_88CFA2D4[];
extern char lbl_88CFA424[];
extern char lbl_88CFA964[];
extern char lbl_88CFAC94[];
extern char lbl_88CFB8C4[];
extern char lbl_88CFBCE4[];
extern char lbl_88CFBD14[];
extern char lbl_88CFD19C[];
extern char lbl_88CFD2BC[];
extern char lbl_88CFD2EC[];
extern char lbl_88CFDD0C[];
extern char lbl_88CFE00C[];
extern char lbl_88CFF38C[];
extern char lbl_88CFF3BC[];
extern char lbl_88CFF50C[];
extern char lbl_88CFF5CC[];
extern char lbl_88CFF71C[];
extern char lbl_88CFFC5C[];
extern char lbl_88CFFF8C[];
extern char lbl_88D00C7C[];
extern char lbl_88D0109C[];
extern char lbl_88D010CC[];
extern char lbl_88D02494[];
extern char lbl_88D025B4[];
extern char lbl_88D025E4[];
extern char lbl_88D03004[];
extern char lbl_88D03304[];
extern char lbl_88D04684[];
extern char lbl_88D046B4[];
extern char lbl_88D04804[];
extern char lbl_88D048C4[];
extern char lbl_88D04A14[];
extern char lbl_88D04F54[];
extern char lbl_88D05284[];
extern char lbl_88D05F74[];
extern char lbl_88D06394[];
extern char lbl_88D063C4[];
extern char lbl_88D0784C[];
extern char lbl_88D0796C[];
extern char lbl_88D0799C[];
extern char lbl_88D079FC[];
extern char lbl_88D07ABC[];
extern char lbl_88D0841C[];
extern char lbl_88D08A4C[];
extern char lbl_88D08B6C[];
extern char lbl_88D08E9C[];
extern char lbl_88D09CDC[];
extern char lbl_88D09DCC[];
extern char lbl_88D09EEC[];
extern char lbl_88D0A15C[];
extern char lbl_88D0A2AC[];
extern char lbl_88D0A6FC[];
extern char lbl_88D0AA2C[];
extern char lbl_88D0B7AC[];
extern char lbl_88D0BC5C[];
extern char lbl_88D0BC8C[];
extern char lbl_88D0D144[];
extern char lbl_88D0D264[];
extern char lbl_88D0D294[];
extern char lbl_88D0D354[];
extern char lbl_88D0D3B4[];
extern char lbl_88D0DD14[];
extern char lbl_88D0E314[];
extern char lbl_88D0E434[];
extern char lbl_88D0E764[];
extern char lbl_88D0F5A4[];
extern char lbl_88D0F694[];
extern char lbl_88D0F7B4[];
extern char lbl_88D0FA24[];
extern char lbl_88D0FB74[];
extern char lbl_88D0FFC4[];
extern char lbl_88D102F4[];
extern char lbl_88D11074[];
extern char lbl_88D11524[];
extern char lbl_88D11554[];
extern char lbl_88D12A0C[];
extern char lbl_88D12B2C[];
extern char lbl_88D12B5C[];
extern char lbl_88D12C1C[];
extern char lbl_88D12C7C[];
extern char lbl_88D1363C[];
extern char lbl_88D13C6C[];
extern char lbl_88D13D8C[];
extern char lbl_88D140BC[];
extern char lbl_88D14EFC[];
extern char lbl_88D14FEC[];
extern char lbl_88D1510C[];
extern char lbl_88D1537C[];
extern char lbl_88D154CC[];
extern char lbl_88D1591C[];
extern char lbl_88D15C4C[];
extern char lbl_88D169CC[];
extern char lbl_88D16E7C[];
extern char lbl_88D16EAC[];
extern char lbl_88D18394[];
extern char lbl_88D18574[];
extern char lbl_88D185A4[];
extern char lbl_88D18664[];
extern char lbl_88D18724[];
extern char lbl_88D189F4[];
extern char lbl_88D18CC4[];
extern char lbl_88D18D24[];
extern char lbl_88D19144[];
extern char lbl_88D196B4[];
extern char lbl_88D197A4[];
extern char lbl_88D198C4[];
extern char lbl_88D19BF4[];
extern char lbl_88D1AA34[];
extern char lbl_88D1AAF4[];
extern char lbl_88D1AD64[];
extern char lbl_88D1AEE4[];
extern char lbl_88D1B004[];
extern char lbl_88D1B3C4[];
extern char lbl_88D1B6F4[];
extern char lbl_88D1C4A4[];
extern char lbl_88D1C954[];
extern char lbl_88D1C984[];
extern char lbl_88D1DE9C[];
extern char lbl_88D1E07C[];
extern char lbl_88D1E0AC[];
extern char lbl_88D1E16C[];
extern char lbl_88D1E22C[];
extern char lbl_88D1E4FC[];
extern char lbl_88D1E7CC[];
extern char lbl_88D1E82C[];
extern char lbl_88D1EC4C[];
extern char lbl_88D1F1BC[];
extern char lbl_88D1F2AC[];
extern char lbl_88D1F3CC[];
extern char lbl_88D1F6FC[];
extern char lbl_88D2053C[];
extern char lbl_88D205FC[];
extern char lbl_88D2086C[];
extern char lbl_88D209EC[];
extern char lbl_88D20B0C[];
extern char lbl_88D20ECC[];
extern char lbl_88D211FC[];
extern char lbl_88D21FAC[];
extern char lbl_88D2245C[];
extern char lbl_88D2248C[];
extern char lbl_88D23454[];
extern char lbl_88D23554[];
extern char lbl_88D236B4[];
extern char lbl_88D23DA4[];
extern char lbl_88D23EF4[];
extern char lbl_88D24600[];
extern char lbl_88D24B20[];
extern char lbl_88D24FF0[];
extern char lbl_88D25110[];
extern char lbl_88D25440[];
extern char lbl_88D257D0[];
extern char lbl_88D259B0[];
extern char lbl_88D267D4[];
extern char lbl_88D26954[];

/* Swing_DLL.xex 0x889D35E8 */
TS4_HK_CLASS_REG_MEM(889D35E8, lbl_88CACA88, lbl_8803AA14, lbl_88CACF0C, 56, lbl_8803A9D8, 1, 1)

/* Swing_DLL.xex 0x889E0540 */
TS4_HK_CLASS_REG_DEF(889E0540, lbl_88CB20C4, lbl_8803EFFC, lbl_88CB04A4, 0, lbl_8804CFB8, 4, lbl_88B46790, 25)

/* Swing_DLL.xex 0x889E7738 */
TS4_HK_CLASS_REG_DEF(889E7738, lbl_88CB4FEC, lbl_8803EFFC, lbl_88CB303C, 0, lbl_8804DFC8, 4, lbl_88B4B8E8, 27)

/* Swing_DLL.xex 0x889EEFF0 */
TS4_HK_CLASS_REG_DEF(889EEFF0, lbl_88CB81E4, lbl_8803EFFC, lbl_88CB5FF4, 0, lbl_8804F240, 4, lbl_88B51060, 27)

/* Swing_DLL.xex 0x889F6AE0 */
TS4_HK_CLASS_REG_DEF(889F6AE0, lbl_88CBB4CC, lbl_8803EFFC, lbl_88CB933C, 0, lbl_880500B8, 4, lbl_88B56790, 27)

/* Swing_DLL.xex 0x889FE7A0 */
TS4_HK_CLASS_REG_DEF(889FE7A0, lbl_88CBE874, lbl_8803EFFC, lbl_88CBC6B4, 0, lbl_88050F08, 4, lbl_88B5BF80, 27)

/* Swing_DLL.xex 0x88A06460 */
TS4_HK_CLASS_REG_DEF(88A06460, lbl_88CC1C1C, lbl_8803EFFC, lbl_88CBFA5C, 0, lbl_88051D10, 4, lbl_88B61770, 27)

/* Swing_DLL.xex 0x88A093F8 */
TS4_HK_CLASS_REG_DEF(88A093F8, lbl_88CC2FE4, lbl_88041210, lbl_88CC2EC4, 0, lbl_88052C18, 1, lbl_88B67960, 12)

/* Swing_DLL.xex 0x88A09928 */
TS4_HK_CLASS_REG_DEF(88A09928, lbl_88CC31F4, lbl_880411B0, lbl_88CC30A4, 0, lbl_88052CBC, 1, lbl_88B67A80, 17)

/* Swing_DLL.xex 0x88A09A30 */
TS4_HK_CLASS_REG_DEF_PAD(88A09A30, lbl_88CC3254, lbl_88040244, lbl_88CC30A4, 0, lbl_88052D50, 1, 1, lbl_88B67C18, 22)

/* Swing_DLL.xex 0x88A0F478 */
TS4_HK_CLASS_REG_DEF(88A0F478, lbl_88CC57A4, lbl_8803EFFC, lbl_88CC3554, 0, lbl_880537B8, 4, lbl_88B68500, 27)

/* Swing_DLL.xex 0x88A12410 */
TS4_HK_CLASS_REG_DEF(88A12410, lbl_88CC6B6C, lbl_88041210, lbl_88CC6A4C, 0, lbl_88054468, 1, lbl_88B6E970, 12)

/* Swing_DLL.xex 0x88A128C8 */
TS4_HK_CLASS_REG_DEF(88A128C8, lbl_88CC6D4C, lbl_880411B0, lbl_88CC6BFC, 0, lbl_8805450C, 1, lbl_88B6EA90, 17)

/* Swing_DLL.xex 0x88A12A40 */
TS4_HK_CLASS_REG_DEF_PAD(88A12A40, lbl_88CC6DDC, lbl_88040244, lbl_88CC6BFC, 0, lbl_880545A0, 1, 1, lbl_88B6EC28, 14)

/* Swing_DLL.xex 0x88A16AC0 */
TS4_HK_CLASS_REG_DEF(88A16AC0, lbl_88CC887C, lbl_88046038, lbl_88CC857C, 0, lbl_88054CAC, 1, lbl_88B6F210, 7)

/* Swing_DLL.xex 0x88A19140 */
TS4_HK_CLASS_REG_DEF(88A19140, lbl_88CC983C, lbl_8803EFFC, lbl_88CC713C, 0, lbl_880551A8, 4, lbl_88B6F4E0, 27)

/* Swing_DLL.xex 0x88A1BEA8 */
TS4_HK_CLASS_REG_DEF(88A1BEA8, lbl_88CCAB14, lbl_88041210, lbl_88CCA9F4, 0, lbl_88055B30, 1, lbl_88B75988, 12)

/* Swing_DLL.xex 0x88A1C360 */
TS4_HK_CLASS_REG_DEF(88A1C360, lbl_88CCACF4, lbl_880411B0, lbl_88CCABA4, 0, lbl_88055BD4, 1, lbl_88B75AA8, 17)

/* Swing_DLL.xex 0x88A1C4D8 */
TS4_HK_CLASS_REG_DEF_PAD(88A1C4D8, lbl_88CCAD84, lbl_88040244, lbl_88CCABA4, 0, lbl_88055C68, 1, 1, lbl_88B75C40, 14)

/* Swing_DLL.xex 0x88A1F2D8 */
TS4_HK_CLASS_REG_DEF(88A1F2D8, lbl_88CCC0A4, lbl_8803EFC0, lbl_88CCBF54, 0, lbl_8805620C, 1, lbl_88B72488, 6)

/* Swing_DLL.xex 0x88A20640 */
TS4_HK_CLASS_REG_DEF(88A20640, lbl_88CCC884, lbl_88046038, lbl_88CCC584, 0, lbl_8805640C, 1, lbl_88B76228, 7)

/* Swing_DLL.xex 0x88A22C50 */
TS4_HK_CLASS_REG_DEF(88A22C50, lbl_88CCD814, lbl_8803EFFC, lbl_88CCB114, 0, lbl_880568E0, 4, lbl_88B764F8, 27)

/* Swing_DLL.xex 0x88A25A30 */
TS4_HK_CLASS_REG_DEF(88A25A30, lbl_88CCEB1C, lbl_88041210, lbl_88CCE9FC, 0, lbl_880573F4, 1, lbl_88B7CAC8, 14)

/* Swing_DLL.xex 0x88A26040 */
TS4_HK_CLASS_REG_DEF(88A26040, lbl_88CCED8C, lbl_880411B0, lbl_88CCEBAC, 0, lbl_880574CC, 1, lbl_88B7CC18, 17)

/* Swing_DLL.xex 0x88A261B8 */
TS4_HK_CLASS_REG_DEF(88A261B8, lbl_88CCEE1C, lbl_88040244, lbl_88CCEBAC, 0, lbl_88057560, 1, lbl_88B7CDB0, 11)

/* Swing_DLL.xex 0x88A26908 */
TS4_HK_CLASS_REG_DEF(88A26908, lbl_88CCF11C, lbl_880410F8, lbl_88CCF0EC, 0, lbl_880576C0, 2, lbl_88B7CEB8, 8)

/* Swing_DLL.xex 0x88A29098 */
TS4_HK_CLASS_REG_DEF(88A29098, lbl_88CD019C, lbl_8803EFC0, lbl_88CD004C, 0, lbl_88057B94, 1, lbl_88B795C8, 6)

/* Swing_DLL.xex 0x88A2A400 */
TS4_HK_CLASS_REG_DEF(88A2A400, lbl_88CD097C, lbl_88046038, lbl_88CD067C, 0, lbl_88057D94, 1, lbl_88B7D3E0, 7)

/* Swing_DLL.xex 0x88A2CA10 */
TS4_HK_CLASS_REG_DEF(88A2CA10, lbl_88CD190C, lbl_8803EFFC, lbl_88CCF20C, 0, lbl_88058268, 4, lbl_88B7D6B0, 27)

/* Swing_DLL.xex 0x88A2F7F0 */
TS4_HK_CLASS_REG_DEF(88A2F7F0, lbl_88CD2C14, lbl_88041210, lbl_88CD2AF4, 0, lbl_88058DD4, 1, lbl_88B83D70, 15)

/* Swing_DLL.xex 0x88A2FE00 */
TS4_HK_CLASS_REG_DEF(88A2FE00, lbl_88CD2E84, lbl_880411B0, lbl_88CD2CA4, 0, lbl_88058EA4, 1, lbl_88B83ED8, 17)

/* Swing_DLL.xex 0x88A2FF78 */
TS4_HK_CLASS_REG_DEF(88A2FF78, lbl_88CD2F14, lbl_88040244, lbl_88CD2CA4, 0, lbl_88058F38, 1, lbl_88B84070, 11)

/* Swing_DLL.xex 0x88A306D0 */
TS4_HK_CLASS_REG_DEF(88A306D0, lbl_88CD3214, lbl_880410F8, lbl_88CD31E4, 0, lbl_88059110, 2, lbl_88B84178, 12)

/* Swing_DLL.xex 0x88A32E60 */
TS4_HK_CLASS_REG_DEF(88A32E60, lbl_88CD4294, lbl_8803EFC0, lbl_88CD4144, 0, lbl_880595EC, 1, lbl_88B80870, 6)

/* Swing_DLL.xex 0x88A341C8 */
TS4_HK_CLASS_REG_DEF(88A341C8, lbl_88CD4A74, lbl_88046038, lbl_88CD4774, 0, lbl_880597EC, 1, lbl_88B84700, 7)

/* Swing_DLL.xex 0x88A367D8 */
TS4_HK_CLASS_REG_DEF(88A367D8, lbl_88CD5A04, lbl_8803EFFC, lbl_88CD3304, 0, lbl_88059CC0, 4, lbl_88B849D0, 27)

/* Swing_DLL.xex 0x88A395D0 */
TS4_HK_CLASS_REG_DEF_PAD(88A395D0, lbl_88CD6D0C, lbl_88041210, lbl_88CD6BEC, 0, lbl_8805A6F0, 1, 1, lbl_88B8B330, 15)

/* Swing_DLL.xex 0x88A39BE0 */
TS4_HK_CLASS_REG_DEF(88A39BE0, lbl_88CD6F7C, lbl_880411B0, lbl_88CD6D9C, 0, lbl_8805A7C4, 1, lbl_88B8B498, 17)

/* Swing_DLL.xex 0x88A39D58 */
TS4_HK_CLASS_REG_DEF(88A39D58, lbl_88CD700C, lbl_88040244, lbl_88CD6D9C, 0, lbl_8805A858, 1, lbl_88B8B630, 11)

/* Swing_DLL.xex 0x88A3A4B0 */
TS4_HK_CLASS_REG_DEF(88A3A4B0, lbl_88CD730C, lbl_880410F8, lbl_88CD72DC, 0, lbl_8805AA30, 2, lbl_88B8B738, 12)

/* Swing_DLL.xex 0x88A3CD80 */
TS4_HK_CLASS_REG_DEF(88A3CD80, lbl_88CD841C, lbl_8803EFC0, lbl_88CD82CC, 0, lbl_8805AF58, 1, lbl_88B87CB8, 6)

/* Swing_DLL.xex 0x88A3E300 */
TS4_HK_CLASS_REG_DEF(88A3E300, lbl_88CD8CBC, lbl_88046038, lbl_88CD89BC, 0, lbl_8805B1E4, 1, lbl_88B8BE10, 7)

/* Swing_DLL.xex 0x88A40910 */
TS4_HK_CLASS_REG_DEF(88A40910, lbl_88CD9C4C, lbl_8803EFFC, lbl_88CD73FC, 0, lbl_8805B6B8, 4, lbl_88B8C128, 31)

/* Swing_DLL.xex 0x88A43708 */
TS4_HK_CLASS_REG_DEF_PAD(88A43708, lbl_88CDAF54, lbl_88041210, lbl_88CDAE34, 0, lbl_8805C0A8, 1, 1, lbl_88B92AE8, 15)

/* Swing_DLL.xex 0x88A43D18 */
TS4_HK_CLASS_REG_DEF(88A43D18, lbl_88CDB1C4, lbl_880411B0, lbl_88CDAFE4, 0, lbl_8805C17C, 1, lbl_88B92C50, 17)

/* Swing_DLL.xex 0x88A43E90 */
TS4_HK_CLASS_REG_DEF(88A43E90, lbl_88CDB254, lbl_88040244, lbl_88CDAFE4, 0, lbl_8805C210, 1, lbl_88B92DE8, 11)

/* Swing_DLL.xex 0x88A445E8 */
TS4_HK_CLASS_REG_DEF(88A445E8, lbl_88CDB554, lbl_880410F8, lbl_88CDB524, 0, lbl_8805C3E8, 2, lbl_88B92EF0, 12)

/* Swing_DLL.xex 0x88A46EB8 */
TS4_HK_CLASS_REG_DEF(88A46EB8, lbl_88CDC664, lbl_8803EFC0, lbl_88CDC514, 0, lbl_8805C910, 1, lbl_88B8F470, 6)

/* Swing_DLL.xex 0x88A48438 */
TS4_HK_CLASS_REG_DEF(88A48438, lbl_88CDCF04, lbl_88046038, lbl_88CDCC04, 0, lbl_8805CB9C, 1, lbl_88B935C8, 7)

/* Swing_DLL.xex 0x88A4AA48 */
TS4_HK_CLASS_REG_DEF(88A4AA48, lbl_88CDDE94, lbl_8803EFFC, lbl_88CDB644, 0, lbl_8805D070, 4, lbl_88B938E0, 31)

/* Swing_DLL.xex 0x88A4D958 */
TS4_HK_CLASS_REG_DEF(88A4D958, lbl_88CDF1FC, lbl_8804124C, lbl_88CDFDFC, 0, lbl_8805E960, 1, lbl_88B9AF60, 5)

/* Swing_DLL.xex 0x88A4D9D0 */
TS4_HK_CLASS_REG_DEF(88A4D9D0, lbl_88CDF22C, lbl_88041238, lbl_88CDF13C, 0, lbl_8805E9A4, 1, lbl_88B94848, 7)

/* Swing_DLL.xex 0x88A52110 */
TS4_HK_CLASS_REG_DEF(88A52110, lbl_88CE0F9C, lbl_8803EFC0, lbl_88CE0E4C, 0, lbl_8805F1C4, 1, lbl_88B97638, 6)

/* Swing_DLL.xex 0x88A52340 */
TS4_HK_CLASS_REG_DEF_PAD(88A52340, lbl_88CE105C, lbl_88041E68, lbl_88CE0E1C, 0, lbl_8805F244, 3, 9, lbl_88B9B998, 8)

/* Swing_DLL.xex 0x88A52690 */
TS4_HK_CLASS_REG_DEF_PAD(88A52690, lbl_88CE11AC, lbl_8803EF9C, lbl_88CE0E1C, 0, lbl_8805F308, 2, 15, lbl_88B9BBA8, 7)

/* Swing_DLL.xex 0x88A53AB8 */
TS4_HK_CLASS_REG_DEF(88A53AB8, lbl_88CE19BC, lbl_88046038, lbl_88CE16BC, 0, lbl_8805F5F4, 1, lbl_88B9BEA8, 7)

/* Swing_DLL.xex 0x88A55870 */
TS4_HK_CLASS_REG_DEF(88A55870, lbl_88CE25BC, lbl_8803F6CC, lbl_88CE2A0C, 0, lbl_8805F974, 1, lbl_88B990C0, 17)

/* Swing_DLL.xex 0x88A56250 */
TS4_HK_CLASS_REG_DEF(88A56250, lbl_88CE29DC, lbl_8803EFFC, lbl_88CDFDFC, 0, lbl_8805FB40, 4, lbl_88B9C298, 36)

/* Swing_DLL.xex 0x88A59230 */
TS4_HK_CLASS_REG_DEF(88A59230, lbl_88CE3DA4, lbl_8804124C, lbl_88CE49A4, 0, lbl_880608E0, 1, lbl_88BA39C0, 5)

/* Swing_DLL.xex 0x88A592A8 */
TS4_HK_CLASS_REG_DEF(88A592A8, lbl_88CE3DD4, lbl_88041238, lbl_88CE3CE4, 0, lbl_88060924, 1, lbl_88B9D278, 7)

/* Swing_DLL.xex 0x88A5D9E8 */
TS4_HK_CLASS_REG_DEF(88A5D9E8, lbl_88CE5B44, lbl_8803EFC0, lbl_88CE59F4, 0, lbl_88061154, 1, lbl_88BA0080, 6)

/* Swing_DLL.xex 0x88A5DC18 */
TS4_HK_CLASS_REG_DEF_PAD(88A5DC18, lbl_88CE5C04, lbl_88041E68, lbl_88CE59C4, 0, lbl_880611D4, 3, 9, lbl_88BA43F8, 7)

/* Swing_DLL.xex 0x88A5DF68 */
TS4_HK_CLASS_REG_DEF_PAD(88A5DF68, lbl_88CE5D54, lbl_8803EF9C, lbl_88CE59C4, 0, lbl_88061294, 2, 15, lbl_88BA45F0, 7)

/* Swing_DLL.xex 0x88A5F390 */
TS4_HK_CLASS_REG_DEF(88A5F390, lbl_88CE6564, lbl_88046038, lbl_88CE6264, 0, lbl_88061584, 1, lbl_88BA4908, 7)

/* Swing_DLL.xex 0x88A61148 */
TS4_HK_CLASS_REG_DEF(88A61148, lbl_88CE7164, lbl_8803F6CC, lbl_88CE75B4, 0, lbl_8806190C, 1, lbl_88BA1B20, 17)

/* Swing_DLL.xex 0x88A61B28 */
TS4_HK_CLASS_REG_DEF(88A61B28, lbl_88CE7584, lbl_8803EFFC, lbl_88CE49A4, 0, lbl_88061AD8, 4, lbl_88BA4CF8, 39)

/* Swing_DLL.xex 0x88A64DB0 */
TS4_HK_CLASS_REG_DEF(88A64DB0, lbl_88CE8A6C, lbl_8804124C, lbl_88CE978C, 0, lbl_88063140, 1, lbl_88BAD4D8, 5)

/* Swing_DLL.xex 0x88A64E28 */
TS4_HK_CLASS_REG_DEF(88A64E28, lbl_88CE8A9C, lbl_88041238, lbl_88CE894C, 0, lbl_88063184, 1, lbl_88BA5F98, 7)

/* Swing_DLL.xex 0x88A6A0B0 */
TS4_HK_CLASS_REG_DEF(88A6A0B0, lbl_88CEACBC, lbl_8803EFC0, lbl_88CEAB6C, 0, lbl_880639F0, 1, lbl_88BA9B38, 6)

/* Swing_DLL.xex 0x88A6A2E0 */
TS4_HK_CLASS_REG_DEF_PAD(88A6A2E0, lbl_88CEAD7C, lbl_88041E68, lbl_88CEAB3C, 0, lbl_88063A70, 3, 9, lbl_88BADFD0, 7)

/* Swing_DLL.xex 0x88A6A630 */
TS4_HK_CLASS_REG_DEF_PAD(88A6A630, lbl_88CEAECC, lbl_8803EF9C, lbl_88CEAB3C, 0, lbl_88063B30, 2, 15, lbl_88BAE1C8, 7)

/* Swing_DLL.xex 0x88A6BA58 */
TS4_HK_CLASS_REG_DEF(88A6BA58, lbl_88CEB6DC, lbl_88046038, lbl_88CEB3DC, 0, lbl_88063E1C, 1, lbl_88BAE4E0, 7)

/* Swing_DLL.xex 0x88A6D7F8 */
TS4_HK_CLASS_REG_DEF(88A6D7F8, lbl_88CEC2DC, lbl_8803F6CC, lbl_88CEC72C, 0, lbl_880641A4, 1, lbl_88BAB638, 17)

/* Swing_DLL.xex 0x88A6E1D8 */
TS4_HK_CLASS_REG_DEF(88A6E1D8, lbl_88CEC6FC, lbl_8803EFFC, lbl_88CE978C, 0, lbl_88064370, 4, lbl_88BAE870, 40)

/* Swing_DLL.xex 0x88A71460 */
TS4_HK_CLASS_REG_DEF(88A71460, lbl_88CEDBE4, lbl_8804124C, lbl_88CEE904, 0, lbl_88065088, 1, lbl_88BB6F50, 5)

/* Swing_DLL.xex 0x88A714D8 */
TS4_HK_CLASS_REG_DEF(88A714D8, lbl_88CEDC14, lbl_88041238, lbl_88CEDAC4, 0, lbl_880650CC, 1, lbl_88BAFB88, 7)

/* Swing_DLL.xex 0x88A72DC8 */
TS4_HK_CLASS_REG_DEF_PAD(88A72DC8, lbl_88CEE634, lbl_88040218, lbl_88CEDAC4, 0, lbl_880652AC, 1, 30, lbl_88BB7358, 18)

/* Swing_DLL.xex 0x88A76698 */
TS4_HK_CLASS_REG_DEF(88A76698, lbl_88CEFDD4, lbl_8803EFC0, lbl_88CEFC84, 0, lbl_880659A0, 1, lbl_88BB35A8, 6)

/* Swing_DLL.xex 0x88A768C8 */
TS4_HK_CLASS_REG_DEF_PAD(88A768C8, lbl_88CEFE94, lbl_88041E68, lbl_88CEFC54, 0, lbl_88065A20, 3, 9, lbl_88BB7C10, 7)

/* Swing_DLL.xex 0x88A76C18 */
TS4_HK_CLASS_REG_DEF_PAD(88A76C18, lbl_88CEFFE4, lbl_8803EF9C, lbl_88CEFC54, 0, lbl_88065AE0, 2, 15, lbl_88BB7E08, 7)

/* Swing_DLL.xex 0x88A78040 */
TS4_HK_CLASS_REG_DEF(88A78040, lbl_88CF07F4, lbl_88046038, lbl_88CF04F4, 0, lbl_88065DCC, 1, lbl_88BB8120, 7)

/* Swing_DLL.xex 0x88A79DE0 */
TS4_HK_CLASS_REG_DEF(88A79DE0, lbl_88CF13F4, lbl_8803F6CC, lbl_88CF1844, 0, lbl_88066154, 1, lbl_88BB50B0, 17)

/* Swing_DLL.xex 0x88A7A7C0 */
TS4_HK_CLASS_REG_DEF(88A7A7C0, lbl_88CF1814, lbl_8803EFFC, lbl_88CEE904, 0, lbl_88066320, 4, lbl_88BB84B0, 40)

/* Swing_DLL.xex 0x88A7D9E8 */
TS4_HK_CLASS_REG_DEF(88A7D9E8, lbl_88CF2CCC, lbl_8804124C, lbl_88CF3A1C, 0, lbl_880671D8, 1, lbl_88BC1090, 7)

/* Swing_DLL.xex 0x88A7DA60 */
TS4_HK_CLASS_REG_DEF(88A7DA60, lbl_88CF2CFC, lbl_88041238, lbl_88CF2BAC, 0, lbl_8806722C, 1, lbl_88BB97E0, 9)

/* Swing_DLL.xex 0x88A7F358 */
TS4_HK_CLASS_REG_DEF_PAD(88A7F358, lbl_88CF371C, lbl_88040218, lbl_88CF2BAC, 0, lbl_88067434, 1, 30, lbl_88BC14C8, 18)

/* Swing_DLL.xex 0x88A82D18 */
TS4_HK_CLASS_REG_DEF(88A82D18, lbl_88CF4F1C, lbl_8803EFC0, lbl_88CF4DCC, 0, lbl_88067B68, 1, lbl_88BBD410, 6)

/* Swing_DLL.xex 0x88A82F48 */
TS4_HK_CLASS_REG_DEF_PAD(88A82F48, lbl_88CF4FDC, lbl_88041E68, lbl_88CF4D9C, 0, lbl_88067BE8, 3, 11, lbl_88BC1DB0, 9)

/* Swing_DLL.xex 0x88A83298 */
TS4_HK_CLASS_REG_DEF_PAD(88A83298, lbl_88CF512C, lbl_8803EF9C, lbl_88CF4D9C, 0, lbl_88067CB8, 2, 16, lbl_88BC1FF0, 7)

/* Swing_DLL.xex 0x88A847A8 */
TS4_HK_CLASS_REG_DEF(88A847A8, lbl_88CF599C, lbl_88046038, lbl_88CF566C, 0, lbl_88067FAC, 1, lbl_88BC2308, 7)

/* Swing_DLL.xex 0x88A865B8 */
TS4_HK_CLASS_REG_DEF(88A865B8, lbl_88CF65CC, lbl_8803F6CC, lbl_88CF6A1C, 0, lbl_88068334, 1, lbl_88BBF0B0, 18)

/* Swing_DLL.xex 0x88A86F98 */
TS4_HK_CLASS_REG_DEF(88A86F98, lbl_88CF69EC, lbl_8803EFFC, lbl_88CF3A1C, 0, lbl_88068500, 4, lbl_88BC2698, 40)

/* Swing_DLL.xex 0x88A8A490 */
TS4_HK_CLASS_REG_DEF(88A8A490, lbl_88CF7FC4, lbl_8804124C, lbl_88CF8D14, 0, lbl_880691E8, 1, lbl_88BCB3C8, 7)

/* Swing_DLL.xex 0x88A8A508 */
TS4_HK_CLASS_REG_DEF(88A8A508, lbl_88CF7FF4, lbl_88041238, lbl_88CF7EA4, 0, lbl_8806923C, 1, lbl_88BC3B00, 9)

/* Swing_DLL.xex 0x88A8BE00 */
TS4_HK_CLASS_REG_DEF_PAD(88A8BE00, lbl_88CF8A14, lbl_88040218, lbl_88CF7EA4, 0, lbl_88069444, 1, 30, lbl_88BCB800, 18)

/* Swing_DLL.xex 0x88A8F7C0 */
TS4_HK_CLASS_REG_DEF(88A8F7C0, lbl_88CFA214, lbl_8803EFC0, lbl_88CFA0C4, 0, lbl_88069B78, 1, lbl_88BC7748, 6)

/* Swing_DLL.xex 0x88A8F9F0 */
TS4_HK_CLASS_REG_DEF_PAD(88A8F9F0, lbl_88CFA2D4, lbl_88041E68, lbl_88CFA094, 0, lbl_88069BF8, 3, 11, lbl_88BCC0E8, 9)

/* Swing_DLL.xex 0x88A8FD40 */
TS4_HK_CLASS_REG_DEF_PAD(88A8FD40, lbl_88CFA424, lbl_8803EF9C, lbl_88CFA094, 0, lbl_88069CC8, 2, 16, lbl_88BCC328, 7)

/* Swing_DLL.xex 0x88A91250 */
TS4_HK_CLASS_REG_DEF(88A91250, lbl_88CFAC94, lbl_88046038, lbl_88CFA964, 0, lbl_88069FBC, 1, lbl_88BCC640, 7)

/* Swing_DLL.xex 0x88A93060 */
TS4_HK_CLASS_REG_DEF(88A93060, lbl_88CFB8C4, lbl_8803F6CC, lbl_88CFBD14, 0, lbl_8806A36C, 1, lbl_88BC93E8, 18)

/* Swing_DLL.xex 0x88A93A40 */
TS4_HK_CLASS_REG_DEF(88A93A40, lbl_88CFBCE4, lbl_8803EFFC, lbl_88CF8D14, 0, lbl_8806A538, 4, lbl_88BCC9D0, 40)

/* Swing_DLL.xex 0x88A96F50 */
TS4_HK_CLASS_REG_DEF(88A96F50, lbl_88CFD2BC, lbl_8804124C, lbl_88CFE00C, 0, lbl_8806B258, 1, lbl_88BD5798, 7)

/* Swing_DLL.xex 0x88A96FC8 */
TS4_HK_CLASS_REG_DEF(88A96FC8, lbl_88CFD2EC, lbl_88041238, lbl_88CFD19C, 0, lbl_8806B2AC, 1, lbl_88BCDD48, 9)

/* Swing_DLL.xex 0x88A988C0 */
TS4_HK_CLASS_REG_DEF_PAD(88A988C0, lbl_88CFDD0C, lbl_88040218, lbl_88CFD19C, 0, lbl_8806B4B4, 1, 30, lbl_88BD5BD0, 19)

/* Swing_DLL.xex 0x88A9C280 */
TS4_HK_CLASS_REG_DEF(88A9C280, lbl_88CFF50C, lbl_8803EFC0, lbl_88CFF3BC, 0, lbl_8806BBF0, 1, lbl_88BD19B0, 6)

/* Swing_DLL.xex 0x88A9C4B0 */
TS4_HK_CLASS_REG_DEF_PAD(88A9C4B0, lbl_88CFF5CC, lbl_88041E68, lbl_88CFF38C, 0, lbl_8806BC70, 3, 11, lbl_88BD64D0, 10)

/* Swing_DLL.xex 0x88A9C800 */
TS4_HK_CLASS_REG_DEF_PAD(88A9C800, lbl_88CFF71C, lbl_8803EF9C, lbl_88CFF38C, 0, lbl_8806BD44, 2, 17, lbl_88BD6728, 7)

/* Swing_DLL.xex 0x88A9DD20 */
TS4_HK_CLASS_REG_DEF(88A9DD20, lbl_88CFFF8C, lbl_88046038, lbl_88CFFC5C, 0, lbl_8806C03C, 1, lbl_88BD6A40, 7)

/* Swing_DLL.xex 0x88A9FCF8 */
TS4_HK_CLASS_REG_DEF_PAD(88A9FCF8, lbl_88D00C7C, lbl_8803F6CC, lbl_88D010CC, 0, lbl_8806C470, 1, 1, lbl_88BD37C0, 18)

/* Swing_DLL.xex 0x88AA06D8 */
TS4_HK_CLASS_REG_DEF(88AA06D8, lbl_88D0109C, lbl_8803EFFC, lbl_88CFE00C, 0, lbl_8806C640, 4, lbl_88BD6DD0, 40)

/* Swing_DLL.xex 0x88AA3A20 */
TS4_HK_CLASS_REG_DEF(88AA3A20, lbl_88D025B4, lbl_8804124C, lbl_88D03304, 0, lbl_8806D410, 1, lbl_88BDFBF8, 7)

/* Swing_DLL.xex 0x88AA3A98 */
TS4_HK_CLASS_REG_DEF(88AA3A98, lbl_88D025E4, lbl_88041238, lbl_88D02494, 0, lbl_8806D464, 1, lbl_88BD8148, 9)

/* Swing_DLL.xex 0x88AA5390 */
TS4_HK_CLASS_REG_DEF_PAD(88AA5390, lbl_88D03004, lbl_88040218, lbl_88D02494, 0, lbl_8806D66C, 1, 38, lbl_88BE0030, 26)

/* Swing_DLL.xex 0x88AA8D50 */
TS4_HK_CLASS_REG_DEF(88AA8D50, lbl_88D04804, lbl_8803EFC0, lbl_88D046B4, 0, lbl_8806DE00, 1, lbl_88BDBE10, 6)

/* Swing_DLL.xex 0x88AA8F80 */
TS4_HK_CLASS_REG_DEF_PAD(88AA8F80, lbl_88D048C4, lbl_88041E68, lbl_88D04684, 0, lbl_8806DE80, 3, 11, lbl_88BE0A20, 10)

/* Swing_DLL.xex 0x88AA92D0 */
TS4_HK_CLASS_REG_DEF_PAD(88AA92D0, lbl_88D04A14, lbl_8803EF9C, lbl_88D04684, 0, lbl_8806DF54, 2, 17, lbl_88BE0C78, 7)

/* Swing_DLL.xex 0x88AAA7F0 */
TS4_HK_CLASS_REG_DEF(88AAA7F0, lbl_88D05284, lbl_88046038, lbl_88D04F54, 0, lbl_8806E24C, 1, lbl_88BE0F90, 7)

/* Swing_DLL.xex 0x88AAC7C8 */
TS4_HK_CLASS_REG_DEF_PAD(88AAC7C8, lbl_88D05F74, lbl_8803F6CC, lbl_88D063C4, 0, lbl_8806E680, 1, 1, lbl_88BDDC20, 18)

/* Swing_DLL.xex 0x88AAD1A8 */
TS4_HK_CLASS_REG_DEF(88AAD1A8, lbl_88D06394, lbl_8803EFFC, lbl_88D03304, 0, lbl_8806E850, 4, lbl_88BE1320, 40)

/* Swing_DLL.xex 0x88AB06C8 */
TS4_HK_CLASS_REG_DEF(88AB06C8, lbl_88D0796C, lbl_8804124C, lbl_88D08E9C, 0, lbl_88071194, 1, lbl_88BEB1C0, 7)

/* Swing_DLL.xex 0x88AB0740 */
TS4_HK_CLASS_REG_DEF_PAD(88AB0740, lbl_88D0799C, lbl_88041238, lbl_88D0784C, 0, lbl_880711F0, 1, 1, lbl_88BE2898, 14)

/* Swing_DLL.xex 0x88AB0840 */
TS4_HK_CLASS_REG_DEF(88AB0840, lbl_88D079FC, lbl_88041210, lbl_88D0784C, 0, lbl_88071288, 2, lbl_88BEB268, 23)

/* Swing_DLL.xex 0x88AB2150 */
TS4_HK_CLASS_REG_DEF_PAD(88AB2150, lbl_88D0841C, lbl_88040218, lbl_88D0784C, 0, lbl_88071510, 1, 45, lbl_88BEB790, 30)

/* Swing_DLL.xex 0x88AB31A0 */
TS4_HK_CLASS_REG_DEF(88AB31A0, lbl_88D08A4C, lbl_8804881C, lbl_88D07ABC, 0, lbl_880718E4, 1, lbl_88BEC2D0, 7)

/* Swing_DLL.xex 0x88AB34A0 */
TS4_HK_CLASS_REG_DEF_PAD(88AB34A0, lbl_88D08B6C, lbl_88073D08, lbl_88D07ABC, 0, lbl_880719D0, 1, 1, lbl_88BE4F38, 19)

/* Swing_DLL.xex 0x88AB6178 */
TS4_HK_CLASS_REG_DEF_PAD(88AB6178, lbl_88D09DCC, lbl_880467EC, lbl_88D09CDC, 0, lbl_88072050, 3, 11, lbl_88BECF18, 10)

/* Swing_DLL.xex 0x88AB6460 */
TS4_HK_CLASS_REG_DEF_PAD(88AB6460, lbl_88D09EEC, lbl_88046798, lbl_88D09CDC, 0, lbl_88072124, 2, 17, lbl_88BED170, 7)

/* Swing_DLL.xex 0x88AB6DC8 */
TS4_HK_CLASS_REG_DEF(88AB6DC8, lbl_88D0A2AC, lbl_8804683C, lbl_88D0A15C, 0, lbl_88072270, 1, lbl_88BE7038, 6)

/* Swing_DLL.xex 0x88AB8038 */
TS4_HK_CLASS_REG_DEF(88AB8038, lbl_88D0AA2C, lbl_8804601C, lbl_88D0A6FC, 0, lbl_880724BC, 1, lbl_88BED428, 7)

/* Swing_DLL.xex 0x88ABA168 */
TS4_HK_CLASS_REG_DEF_PAD(88ABA168, lbl_88D0B7AC, lbl_88045818, lbl_88D0BC8C, 0, lbl_88072900, 1, 1, lbl_88BE8BC8, 17)

/* Swing_DLL.xex 0x88ABAC88 */
TS4_HK_CLASS_REG_DEF(88ABAC88, lbl_88D0BC5C, lbl_88045420, lbl_88D08E9C, 0, lbl_88072C08, 4, lbl_88BED800, 39)

/* Swing_DLL.xex 0x88ABE250 */
TS4_HK_CLASS_REG_DEF(88ABE250, lbl_88D0D264, lbl_8804124C, lbl_88D0E764, 0, lbl_8807458C, 1, lbl_88BF76F0, 7)

/* Swing_DLL.xex 0x88ABE2C8 */
TS4_HK_CLASS_REG_DEF_PAD(88ABE2C8, lbl_88D0D294, lbl_88041238, lbl_88D0D144, 0, lbl_880745E8, 1, 1, lbl_88BEEEE8, 14)

/* Swing_DLL.xex 0x88ABE4D0 */
TS4_HK_CLASS_REG_DEF_PAD(88ABE4D0, lbl_88D0D354, lbl_88048224, lbl_88D0D294, 0, lbl_880746B8, 1, 1, lbl_88BF7930, 14)

/* Swing_DLL.xex 0x88ABFCD8 */
TS4_HK_CLASS_REG_DEF_PAD(88ABFCD8, lbl_88D0DD14, lbl_88040218, lbl_88D0D144, 0, lbl_880749E8, 1, 45, lbl_88BF7C90, 30)

/* Swing_DLL.xex 0x88AC0CB0 */
TS4_HK_CLASS_REG_DEF(88AC0CB0, lbl_88D0E314, lbl_8804881C, lbl_88D0D3B4, 0, lbl_88074DB8, 1, lbl_88BF8818, 7)

/* Swing_DLL.xex 0x88AC0FB0 */
TS4_HK_CLASS_REG_DEF(88AC0FB0, lbl_88D0E434, lbl_88073D08, lbl_88D0D3B4, 0, lbl_88074EA4, 1, lbl_88BF1450, 19)

/* Swing_DLL.xex 0x88AC3C88 */
TS4_HK_CLASS_REG_DEF_PAD(88AC3C88, lbl_88D0F694, lbl_880467EC, lbl_88D0F5A4, 0, lbl_880754E0, 3, 11, lbl_88BF9460, 11)

/* Swing_DLL.xex 0x88AC3F70 */
TS4_HK_CLASS_REG_DEF_PAD(88AC3F70, lbl_88D0F7B4, lbl_88046798, lbl_88D0F5A4, 0, lbl_880755B8, 2, 16, lbl_88BF96D0, 7)

/* Swing_DLL.xex 0x88AC48D8 */
TS4_HK_CLASS_REG_DEF(88AC48D8, lbl_88D0FB74, lbl_8804683C, lbl_88D0FA24, 0, lbl_88075700, 1, lbl_88BF3548, 6)

/* Swing_DLL.xex 0x88AC5B48 */
TS4_HK_CLASS_REG_DEF(88AC5B48, lbl_88D102F4, lbl_8804601C, lbl_88D0FFC4, 0, lbl_8807594C, 1, lbl_88BF9988, 8)

/* Swing_DLL.xex 0x88AC7C78 */
TS4_HK_CLASS_REG_DEF_PAD(88AC7C78, lbl_88D11074, lbl_88045818, lbl_88D11554, 0, lbl_88075D98, 1, 1, lbl_88BF50F0, 17)

/* Swing_DLL.xex 0x88AC8798 */
TS4_HK_CLASS_REG_DEF(88AC8798, lbl_88D11524, lbl_88045420, lbl_88D0E764, 0, lbl_880760A0, 4, lbl_88BF9D78, 39)

/* Swing_DLL.xex 0x88ACBD60 */
TS4_HK_CLASS_REG_DEF(88ACBD60, lbl_88D12B2C, lbl_8804124C, lbl_88D140BC, 0, lbl_8807710C, 1, lbl_88C03E60, 7)

/* Swing_DLL.xex 0x88ACBDD8 */
TS4_HK_CLASS_REG_DEF_PAD(88ACBDD8, lbl_88D12B5C, lbl_88041238, lbl_88D12A0C, 0, lbl_88077168, 1, 1, lbl_88BFB478, 14)

/* Swing_DLL.xex 0x88ACBFE0 */
TS4_HK_CLASS_REG_DEF_PAD(88ACBFE0, lbl_88D12C1C, lbl_88048224, lbl_88D12B5C, 0, lbl_88077238, 1, 1, lbl_88C040A0, 15)

/* Swing_DLL.xex 0x88ACD8D8 */
TS4_HK_CLASS_REG_DEF_PAD(88ACD8D8, lbl_88D1363C, lbl_88040218, lbl_88D12A0C, 0, lbl_88077640, 1, 45, lbl_88C04418, 30)

/* Swing_DLL.xex 0x88ACE928 */
TS4_HK_CLASS_REG_DEF(88ACE928, lbl_88D13C6C, lbl_8804881C, lbl_88D12C7C, 0, lbl_88077AA0, 1, lbl_88C04FA0, 7)

/* Swing_DLL.xex 0x88ACEC28 */
TS4_HK_CLASS_REG_DEF(88ACEC28, lbl_88D13D8C, lbl_88073D08, lbl_88D12C7C, 0, lbl_88077B8C, 1, lbl_88BFDBA8, 19)

/* Swing_DLL.xex 0x88AD1900 */
TS4_HK_CLASS_REG_DEF_PAD(88AD1900, lbl_88D14FEC, lbl_880467EC, lbl_88D14EFC, 0, lbl_880781C8, 3, 11, lbl_88C05BE8, 11)

/* Swing_DLL.xex 0x88AD1BE8 */
TS4_HK_CLASS_REG_DEF_PAD(88AD1BE8, lbl_88D1510C, lbl_88046798, lbl_88D14EFC, 0, lbl_880782A0, 2, 16, lbl_88C05E58, 7)

/* Swing_DLL.xex 0x88AD2550 */
TS4_HK_CLASS_REG_DEF(88AD2550, lbl_88D154CC, lbl_8804683C, lbl_88D1537C, 0, lbl_880783E8, 1, lbl_88BFFCA8, 6)

/* Swing_DLL.xex 0x88AD37C0 */
TS4_HK_CLASS_REG_DEF(88AD37C0, lbl_88D15C4C, lbl_8804601C, lbl_88D1591C, 0, lbl_88078634, 1, lbl_88C06110, 8)

/* Swing_DLL.xex 0x88AD58F0 */
TS4_HK_CLASS_REG_DEF_PAD(88AD58F0, lbl_88D169CC, lbl_88045818, lbl_88D16EAC, 0, lbl_88078A80, 1, 1, lbl_88C01868, 17)

/* Swing_DLL.xex 0x88AD6410 */
TS4_HK_CLASS_REG_DEF(88AD6410, lbl_88D16E7C, lbl_88045420, lbl_88D140BC, 0, lbl_88078D88, 4, lbl_88C06500, 39)

/* Swing_DLL.xex 0x88AD9C28 */
TS4_HK_CLASS_REG_DEF(88AD9C28, lbl_88D18574, lbl_88041238, lbl_88D18394, 0, lbl_8807A1BC, 1, lbl_88C07DE0, 14)

/* Swing_DLL.xex 0x88AD9CB8 */
TS4_HK_CLASS_REG_DEF(88AD9CB8, lbl_88D185A4, lbl_8804124C, lbl_88D19BF4, 0, lbl_8807A228, 1, lbl_88C10BB8, 8)

/* Swing_DLL.xex 0x88AD9EC0 */
TS4_HK_CLASS_REG_DEF_PAD(88AD9EC0, lbl_88D18664, lbl_88048224, lbl_88D18574, 0, lbl_8807A2D8, 1, 1, lbl_88C10E10, 15)

/* Swing_DLL.xex 0x88ADA798 */
TS4_HK_CLASS_REG_DEF_PAD(88ADA798, lbl_88D189F4, lbl_88048838, lbl_88D19BF4, 0, lbl_8807A5F0, 1, 1, lbl_88C10F78, 11)

/* Swing_DLL.xex 0x88ADAED0 */
TS4_HK_CLASS_REG_DEF(88ADAED0, lbl_88D18CC4, lbl_88049410, lbl_88D18724, 0, lbl_8807A78C, 1, lbl_88C11188, 9)

/* Swing_DLL.xex 0x88ADAFD8 */
TS4_HK_CLASS_REG_DEF(88ADAFD8, lbl_88D18D24, lbl_8807CD6C, lbl_88D18724, 0, lbl_8807A828, 1, lbl_88C11260, 6)

/* Swing_DLL.xex 0x88ADB9F0 */
TS4_HK_CLASS_REG_DEF_PAD(88ADB9F0, lbl_88D19144, lbl_88040218, lbl_88D18394, 0, lbl_8807A91C, 1, 44, lbl_88C113F8, 30)

/* Swing_DLL.xex 0x88ADC848 */
TS4_HK_CLASS_REG_DEF_PAD(88ADC848, lbl_88D196B4, lbl_88048860, lbl_88D18724, 0, lbl_8807AD40, 1, 9, lbl_88C0A120, 31)

/* Swing_DLL.xex 0x88ADCAC0 */
TS4_HK_CLASS_REG_DEF_PAD(88ADCAC0, lbl_88D197A4, lbl_8804881C, lbl_88D18724, 0, lbl_8807AE68, 1, 1, lbl_88C11F98, 8)

/* Swing_DLL.xex 0x88ADCDC0 */
TS4_HK_CLASS_REG_DEF(88ADCDC0, lbl_88D198C4, lbl_88073D08, lbl_88D18724, 0, lbl_8807AF5C, 1, lbl_88C0A780, 19)

/* Swing_DLL.xex 0x88ADFA20 */
TS4_HK_CLASS_REG_DEF_PAD(88ADFA20, lbl_88D1AAF4, lbl_880467EC, lbl_88D1AA34, 0, lbl_8807B5C0, 3, 11, lbl_88C12C10, 11)

/* Swing_DLL.xex 0x88AE03D8 */
TS4_HK_CLASS_REG_DEF(88AE03D8, lbl_88D1AEE4, lbl_8804683C, lbl_88D1AD64, 0, lbl_8807B6F0, 1, lbl_88C0C7F8, 6)

/* Swing_DLL.xex 0x88AE06E8 */
TS4_HK_CLASS_REG_DEF_PAD(88AE06E8, lbl_88D1B004, lbl_88046798, lbl_88D1AA34, 0, lbl_8807B780, 2, 16, lbl_88C12FA0, 7)

/* Swing_DLL.xex 0x88AE17E8 */
TS4_HK_CLASS_REG_DEF(88AE17E8, lbl_88D1B6F4, lbl_8804601C, lbl_88D1B3C4, 0, lbl_8807BA0C, 1, lbl_88C13060, 8)

/* Swing_DLL.xex 0x88AE3980 */
TS4_HK_CLASS_REG_DEF_PAD(88AE3980, lbl_88D1C4A4, lbl_88045818, lbl_88D1C984, 0, lbl_8807BE60, 1, 1, lbl_88C0E3A8, 17)

/* Swing_DLL.xex 0x88AE44A0 */
TS4_HK_CLASS_REG_DEF(88AE44A0, lbl_88D1C954, lbl_88045420, lbl_88D19BF4, 0, lbl_8807C168, 4, lbl_88C13450, 42)

/* Swing_DLL.xex 0x88AE7D28 */
TS4_HK_CLASS_REG_DEF(88AE7D28, lbl_88D1E07C, lbl_88041238, lbl_88D1DE9C, 0, lbl_8807D3E4, 1, lbl_88C14DA8, 14)

/* Swing_DLL.xex 0x88AE7DB8 */
TS4_HK_CLASS_REG_DEF(88AE7DB8, lbl_88D1E0AC, lbl_8804124C, lbl_88D1F6FC, 0, lbl_8807D450, 1, lbl_88C1DB68, 8)

/* Swing_DLL.xex 0x88AE7FC0 */
TS4_HK_CLASS_REG_DEF_PAD(88AE7FC0, lbl_88D1E16C, lbl_88048224, lbl_88D1E07C, 0, lbl_8807D508, 1, 1, lbl_88C1DDC0, 15)

/* Swing_DLL.xex 0x88AE8898 */
TS4_HK_CLASS_REG_DEF_PAD(88AE8898, lbl_88D1E4FC, lbl_88048838, lbl_88D1F6FC, 0, lbl_8807D828, 1, 1, lbl_88C1DF28, 11)

/* Swing_DLL.xex 0x88AE8FD0 */
TS4_HK_CLASS_REG_DEF(88AE8FD0, lbl_88D1E7CC, lbl_88049410, lbl_88D1E22C, 0, lbl_8807D9C4, 1, lbl_88C1E138, 9)

/* Swing_DLL.xex 0x88AE90D8 */
TS4_HK_CLASS_REG_DEF(88AE90D8, lbl_88D1E82C, lbl_8807CD6C, lbl_88D1E22C, 0, lbl_8807DA60, 1, lbl_88C1E210, 6)

/* Swing_DLL.xex 0x88AE9AF0 */
TS4_HK_CLASS_REG_DEF_PAD(88AE9AF0, lbl_88D1EC4C, lbl_88040218, lbl_88D1DE9C, 0, lbl_8807DB54, 1, 44, lbl_88C1E3A8, 30)

/* Swing_DLL.xex 0x88AEA948 */
TS4_HK_CLASS_REG_DEF_PAD(88AEA948, lbl_88D1F1BC, lbl_88048860, lbl_88D1E22C, 0, lbl_8807DF78, 1, 9, lbl_88C17118, 31)

/* Swing_DLL.xex 0x88AEABC0 */
TS4_HK_CLASS_REG_DEF(88AEABC0, lbl_88D1F2AC, lbl_8804881C, lbl_88D1E22C, 0, lbl_8807E0BC, 1, lbl_88C1EF48, 8)

/* Swing_DLL.xex 0x88AEAEC0 */
TS4_HK_CLASS_REG_DEF(88AEAEC0, lbl_88D1F3CC, lbl_88073D08, lbl_88D1E22C, 0, lbl_8807E1AC, 1, lbl_88C17778, 19)

/* Swing_DLL.xex 0x88AEDB20 */
TS4_HK_CLASS_REG_DEF_PAD(88AEDB20, lbl_88D205FC, lbl_880467EC, lbl_88D2053C, 0, lbl_8807E810, 3, 11, lbl_88C1FBC0, 11)

/* Swing_DLL.xex 0x88AEE4D8 */
TS4_HK_CLASS_REG_DEF(88AEE4D8, lbl_88D209EC, lbl_8804683C, lbl_88D2086C, 0, lbl_8807E940, 1, lbl_88C197F0, 6)

/* Swing_DLL.xex 0x88AEE7E8 */
TS4_HK_CLASS_REG_DEF_PAD(88AEE7E8, lbl_88D20B0C, lbl_88046798, lbl_88D2053C, 0, lbl_8807E9D0, 2, 16, lbl_88C1FF50, 7)

/* Swing_DLL.xex 0x88AEF8E8 */
TS4_HK_CLASS_REG_DEF(88AEF8E8, lbl_88D211FC, lbl_8804601C, lbl_88D20ECC, 0, lbl_8807EC5C, 1, lbl_88C20010, 8)

/* Swing_DLL.xex 0x88AF1A80 */
TS4_HK_CLASS_REG_DEF_PAD(88AF1A80, lbl_88D21FAC, lbl_88045818, lbl_88D2248C, 0, lbl_8807F0B0, 1, 1, lbl_88C1B3D0, 17)

/* Swing_DLL.xex 0x88AF25A0 */
TS4_HK_CLASS_REG_DEF(88AF25A0, lbl_88D2245C, lbl_88045420, lbl_88D1F6FC, 0, lbl_8807F3B8, 4, lbl_88C20400, 42)

/* Swing_DLL.xex 0x88AF4D28 */
TS4_HK_CLASS_REG_DEF(88AF4D28, lbl_88D23454, lbl_8804683C, lbl_88D23DA4, 96, lbl_88080568, 1, lbl_88080598, 6)

/* Swing_DLL.xex 0x88AF5020 */
TS4_HK_CLASS_REG_DEF_PAD(88AF5020, lbl_88D23554, lbl_880467EC, lbl_88D23EF4, 192, lbl_88080690, 3, 41, lbl_88C21028, 11)

/* Swing_DLL.xex 0x88AF5490 */
TS4_HK_CLASS_REG_DEF_PAD(88AF5490, lbl_88D236B4, lbl_88046798, lbl_88D23EF4, 96, lbl_88080988, 2, 16, lbl_88C21320, 7)

/* Swing_DLL.xex 0x88AF7468 */
TS4_HK_CLASS_REG_DEF_PAD(88AF7468, lbl_88D24600, lbl_88045818, lbl_88D259B0, 512, lbl_88083998, 1, 157, lbl_88083A88, 17)

/* Swing_DLL.xex 0x88AF81B8 */
TS4_HK_CLASS_REG_MEM_PAD(88AF81B8, lbl_88D24B20, lbl_88045604, lbl_88D257D0, 320, lbl_88084730, 1, 53, 1)

/* Swing_DLL.xex 0x88AF8E98 */
TS4_HK_CLASS_REG_DEF(88AF8E98, lbl_88D24FF0, lbl_88045420, lbl_88CACF0C, 208, lbl_88085950, 4, lbl_88C236A0, 42)

/* Swing_DLL.xex 0x88AF9950 */
TS4_HK_CLASS_REG_DEF(88AF9950, lbl_88D25440, lbl_8804601C, lbl_88D25110, 20, lbl_88086164, 1, lbl_88C23D38, 8)

/* Swing_DLL.xex 0x88AFA200 */
TS4_HK_CLASS_REG_MEM(88AFA200, lbl_88D257D0, lbl_88045AD0, lbl_88CACF0C, 12, lbl_88086700, 1, 1)

/* Swing_DLL.xex 0x88AFCE80 */
TS4_HK_CLASS_REG_MEM_PAD(88AFCE80, lbl_88D26954, lbl_8803ED14, lbl_88D267D4, 112, lbl_8808AB60, 1, 13, 8)
