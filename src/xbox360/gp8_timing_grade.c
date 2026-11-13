/*
 * GP8: timing / hit-quality grade to factor lookup.
 * Grade names are zlib crc32 hashes of the ASCII names (python3 -c "import zlib;print(hex(zlib.crc32(b'Good')))"):
 *   VeryBad 0x555267AA, Bad 0xBA667F1B, Normal 0x26296DD2, Good 0xCCB6E1AC, VeryGood 0x703F56AE.
 * Medium 0xC1DF4081 is a hit-quality grade too but has no entry in this lookup (it returns 0.0).
 */

extern float g_ts4_script_constants[];   /* .rdata pool 0x880D0F70 */
extern float lbl_8814B910[];             /* 0.5f; lbl_8814B910 - 0x4d0 (0x8814B440) is 0.0f */

/* Swing_DLL.xex 0x8865AC08: grade hash -> quality factor.
 * VeryGood 1.0 (pool+0x00), Good 0.75 (pool+0x2A0), Normal 0.5, Bad 0.25 (pool+0x29C), anything else 0.0. */
float ts4_timing_grade_factor_8865AC08(const unsigned int *grade_hash)
{
    float r = *(const float *)((const char *)lbl_8814B910 - 0x4d0);
    switch (*grade_hash) {
    case 0xBA667F1Bu: /* Bad */
        r = g_ts4_script_constants[0x29C / 4];
        break;
    case 0x26296DD2u: /* Normal */
        r = lbl_8814B910[0];
        break;
    case 0x703F56AEu: /* VeryGood */
        r = g_ts4_script_constants[0];
        break;
    case 0xCCB6E1ACu: /* Good */
        r = g_ts4_script_constants[0x2A0 / 4];
        break;
    default:
        break;
    }
    return r;
}
