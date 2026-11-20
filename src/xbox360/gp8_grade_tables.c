/*
 * GP8: lookup of a per-grade entry in a five-level grade table.
 * Table layout (data comes from XData, the PlayerTuning-style record that fn_886629C8 passes in):
 *   entry index 0 VeryGood 0x703F56AE, 1 Good 0xCCB6E1AC, 2 Normal 0x26296DD2, 3 Bad 0xBA667F1B, 4 VeryBad 0x555267AA
 * (names are zlib crc32 of the ASCII word). Unknown grade (e.g. Medium 0xC1DF4081) yields zeros.
 */

extern float lbl_8814B440[];   /* 0.0f */

struct Gp8GradePair {          /* two floats, 8 bytes */
    float a;
    float b;
};

struct Gp8GradeQuad {          /* four floats, 16 bytes */
    float v[4];
};

/* Swing_DLL.xex 0x8826DD20: copy the 8-byte entry for the grade. Entry stride 8. */
void ts4_grade_table_pair_8826DD20(const struct Gp8GradePair *table, const unsigned int *grade_hash,
                                   struct Gp8GradePair *out)
{
    switch (*grade_hash) {
    case 0x703F56AEu: /* VeryGood */
        *out = table[0];
        break;
    case 0xCCB6E1ACu: /* Good */
        *out = table[1];
        break;
    case 0x26296DD2u: /* Normal */
        *out = table[2];
        break;
    case 0xBA667F1Bu: /* Bad */
        *out = table[3];
        break;
    case 0x555267AAu: /* VeryBad */
        *out = table[4];
        break;
    default: {
        struct Gp8GradePair zero;
        zero.a = lbl_8814B440[0];
        zero.b = lbl_8814B440[0];
        *out = zero;
        break;
    }
    }
}

/* Swing_DLL.xex 0x8826DDF8: copy the 16-byte entry for the grade. Entry stride 16. */
void ts4_grade_table_quad_8826DDF8(const struct Gp8GradeQuad *table, const unsigned int *grade_hash,
                                   struct Gp8GradeQuad *out)
{
    switch (*grade_hash) {
    case 0x703F56AEu: /* VeryGood */
        *out = table[0];
        break;
    case 0xCCB6E1ACu: /* Good */
        *out = table[1];
        break;
    case 0x26296DD2u: /* Normal */
        *out = table[2];
        break;
    case 0xBA667F1Bu: /* Bad */
        *out = table[3];
        break;
    case 0x555267AAu: /* VeryBad */
        *out = table[4];
        break;
    default: {
        struct Gp8GradeQuad zero;
        zero.v[0] = lbl_8814B440[0];
        zero.v[1] = lbl_8814B440[0];
        zero.v[2] = lbl_8814B440[0];
        zero.v[3] = lbl_8814B440[0];
        *out = zero;
        break;
    }
    }
}
