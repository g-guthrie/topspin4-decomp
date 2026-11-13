/*
 * GP1 draft (near match): fn_8865B780 differs only in stack frame size (original 0x90, here 0x70): the
 * original reserves an extra 0x20 bytes of locals that are never touched; the struct trick used for
 * fn_88666F18 does not apply because the hash is a spilled parameter. Logic and constants are exact.
 */
/* GP1: shot-quality reward labels (WP1).
   Each reward is identified by the zlib crc32 of its name; the debug HUD prints "<Name> (S+<points>)". */

void ts4_format_text(char *buffer, unsigned int size, const char *format, ...);
const char *fn_8860C1C0(unsigned int *hash);

extern char lbl_880F4280[]; /* "%s (S+%d) \n", used for hashes without a dedicated label */

extern char lbl_880F3F2C[]; /* "UnforcedError (S+%d) \n" */
extern char lbl_880F3F44[]; /* "Wood (S+%d) \n" */
extern char lbl_880F3F54[]; /* "CounterEfficientShot (S+%d) \n" */
extern char lbl_880F3F74[]; /* "SpectacularAnimation (S+%d) \n" */
extern char lbl_880F3F94[]; /* "Ace (S+%d) \n" */
extern char lbl_880F3FA4[]; /* "Volley (S+%d) \n" */
extern char lbl_880F3FB4[]; /* "DropShot (S+%d) \n" */
extern char lbl_880F3FC8[]; /* "HighPointQuality (S+%d) \n" */
extern char lbl_880F3FE4[]; /* "ReturnEfficientShot (S+%d) \n" */
extern char lbl_880F4004[]; /* "VeryPowerfullShot (S+%d) \n" */
extern char lbl_880F4020[]; /* "VeryPowerfulService (S+%d) \n" */
extern char lbl_880F4040[]; /* "VeryEfficientShot (S+%d) \n" */
extern char lbl_880F405C[]; /* "ConnectGoodShots (S+%d) \n" */
extern char lbl_880F4078[]; /* "ConnectedEfficientShots (S+%d) \n" */
extern char lbl_880F409C[]; /* "WrongFoot (S+%d) \n" */
extern char lbl_880F40B0[]; /* "VeryWrongFoot (S+%d) \n" */
extern char lbl_880F40C8[]; /* "Let (S+%d) \n" */
extern char lbl_880F40D8[]; /* "ReachAnimation (S+%d) \n" */
extern char lbl_880F40F0[]; /* "RushingAnimation (S+%d) \n" */
extern char lbl_880F410C[]; /* "RushingToBall (S+%d) \n" */
extern char lbl_880F4124[]; /* "PowerfulShotAnimation (S+%d) \n" */
extern char lbl_880F4144[]; /* "SmashAnimation (S+%d) \n" */
extern char lbl_880F415C[]; /* "LitigiousBounce (S+%d) \n" */
extern char lbl_880F4178[]; /* "VeryEfficientSlowShot (S+%d) \n" */
extern char lbl_880F4198[]; /* "VeryPowerfulEfficientShot (S+%d) \n" */
extern char lbl_880F41BC[]; /* "VolleyPowerfulShot (S+%d) \n" */
extern char lbl_880F41D8[]; /* "ForcedError (S+%d) \n" */
extern char lbl_880F41F0[]; /* "WinnerOpportunity (S+%d) \n" */
extern char lbl_880F420C[]; /* "DoubleFault (S+%d) \n" */
extern char lbl_880F4224[]; /* "PowerfulShot (S+%d) \n" */
extern char lbl_880F423C[]; /* "VolleyShortReactionTime (S+%d) \n" */
extern char lbl_880F4260[]; /* "ReflexVolleyAnimation (S+%d) \n" */

/* Swing_DLL.xex 0x8865B780: formats the debug label of one reward ("<Name> (S+<points>)"). */
void ts4_shot_reward_format_label_8865B780(char *buffer, unsigned int reward_hash, int points)
{
    /* 0x20 bytes of frame sit below the spilled hash in the original build. */
    struct { unsigned char unused[0x20]; unsigned int hash; } spill;

    spill.hash = reward_hash;
    if (reward_hash == 0xd2db781du) {
        ts4_format_text(buffer, 0x40, lbl_880F3F2C, points); /* UnforcedError */
    } else if (reward_hash == 0x9cafb633u) {
        ts4_format_text(buffer, 0x40, lbl_880F3F44, points); /* Wood */
    } else if (reward_hash == 0x466c7e14u) {
        ts4_format_text(buffer, 0x40, lbl_880F3F54, points); /* CounterEfficientShot */
    } else if (reward_hash == 0x2e23f28au) {
        ts4_format_text(buffer, 0x40, lbl_880F3F74, points); /* SpectacularAnimation */
    } else if (reward_hash == 0xfd119356u) {
        ts4_format_text(buffer, 0x40, lbl_880F3F94, points); /* Ace */
    } else if (reward_hash == 0x71198650u) {
        ts4_format_text(buffer, 0x40, lbl_880F3FA4, points); /* Volley */
    } else if (reward_hash == 0x990377a5u) {
        ts4_format_text(buffer, 0x40, lbl_880F3FB4, points); /* DropShot */
    } else if (reward_hash == 0x78076350u) {
        ts4_format_text(buffer, 0x40, lbl_880F3FC8, points); /* HighPointQuality */
    } else if (reward_hash == 0x3d9faab2u) {
        ts4_format_text(buffer, 0x40, lbl_880F3FE4, points); /* ReturnEfficientShot */
    } else if (reward_hash == 0xe6d36354u) {
        ts4_format_text(buffer, 0x40, lbl_880F4004, points); /* VeryPowerfullShot */
    } else if (reward_hash == 0x7f1731e8u) {
        ts4_format_text(buffer, 0x40, lbl_880F4020, points); /* VeryPowerfulService */
    } else if (reward_hash == 0x1870e00bu) {
        ts4_format_text(buffer, 0x40, lbl_880F4040, points); /* VeryEfficientShot */
    } else if (reward_hash == 0xd5db9aa0u) {
        ts4_format_text(buffer, 0x40, lbl_880F405C, points); /* ConnectGoodShots */
    } else if (reward_hash == 0x35d301fu) {
        ts4_format_text(buffer, 0x40, lbl_880F4078, points); /* ConnectedEfficientShots */
    } else if (reward_hash == 0x32a41e36u) {
        ts4_format_text(buffer, 0x40, lbl_880F409C, points); /* WrongFoot */
    } else if (reward_hash == 0x6e55faceu) {
        ts4_format_text(buffer, 0x40, lbl_880F40B0, points); /* VeryWrongFoot */
    } else if (reward_hash == 0xc9238771u) {
        ts4_format_text(buffer, 0x40, lbl_880F40C8, points); /* Let */
    } else if (reward_hash == 0x555999b1u) {
        ts4_format_text(buffer, 0x40, lbl_880F40D8, points); /* ReachAnimation */
    } else if (reward_hash == 0x39afbba7u) {
        ts4_format_text(buffer, 0x40, lbl_880F40F0, points); /* RushingAnimation */
    } else if (reward_hash == 0x7d322733u) {
        ts4_format_text(buffer, 0x40, lbl_880F410C, points); /* RushingToBall */
    } else if (reward_hash == 0x9aca4d10u) {
        ts4_format_text(buffer, 0x40, lbl_880F4124, points); /* PowerfulShotAnimation */
    } else if (reward_hash == 0x3ca36f61u) {
        ts4_format_text(buffer, 0x40, lbl_880F4144, points); /* SmashAnimation */
    } else if (reward_hash == 0x6f450666u) {
        ts4_format_text(buffer, 0x40, lbl_880F415C, points); /* LitigiousBounce */
    } else if (reward_hash == 0xfa6acf47u) {
        ts4_format_text(buffer, 0x40, lbl_880F4178, points); /* VeryEfficientSlowShot */
    } else if (reward_hash == 0xfe326900u) {
        ts4_format_text(buffer, 0x40, lbl_880F4198, points); /* VeryPowerfulEfficientShot */
    } else if (reward_hash == 0x6d63f44au) {
        ts4_format_text(buffer, 0x40, lbl_880F41BC, points); /* VolleyPowerfulShot */
    } else if (reward_hash == 0xe5723bd0u) {
        ts4_format_text(buffer, 0x40, lbl_880F41D8, points); /* ForcedError */
    } else if (reward_hash == 0x1a64fed3u) {
        ts4_format_text(buffer, 0x40, lbl_880F41F0, points); /* WinnerOpportunity */
    } else if (reward_hash == 0x891c1be2u) {
        ts4_format_text(buffer, 0x40, lbl_880F420C, points); /* DoubleFault */
    } else if (reward_hash == 0xadacb502u) {
        ts4_format_text(buffer, 0x40, lbl_880F4224, points); /* PowerfulShot */
    } else if (reward_hash == 0x50bf2728u) {
        ts4_format_text(buffer, 0x40, lbl_880F423C, points); /* VolleyShortReactionTime */
    } else if (reward_hash == 0x3559c382u) {
        ts4_format_text(buffer, 0x40, lbl_880F4260, points); /* ReflexVolleyAnimation */
    } else {
        ts4_format_text(buffer, 0x40, lbl_880F4280, fn_8860C1C0(&spill.hash), points);
    }
}
