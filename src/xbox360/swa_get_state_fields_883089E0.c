/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

/* Swing_DLL.xex 0x883089E0: copies optional state fields to out pointers; the last out gets a per-mode value (0,8,16,24,32). */
int ts4_get_state_fields_883089E0(const char *object, int *out_a, int *out_b, int *out_c,
                                  int *out_d, int *out_e, int *out_f)
{
    if (out_a) {
        *out_a = *(const int *)(object + 0x4a4);
    }
    if (out_b) {
        *out_b = *(const int *)(object + 0x4a0);
    }
    if (out_c) {
        *out_c = *(const int *)(object + 0x4b0);
    }
    if (out_d) {
        *out_d = *(const int *)(object + 0x4ac);
    }
    if (out_e) {
        *out_e = *(const int *)(object + 0x55bc);
    }
    if (out_f) {
        int value = 0;
        switch (*(const unsigned int *)(object + 0x4a0)) {
        case 0:
            value = 0;
            break;
        case 1:
            value = 8;
            break;
        case 2:
            value = 16;
            break;
        case 3:
            value = 24;
            break;
        case 4:
        case 5:
            value = 32;
            break;
        case 6: case 7: case 8: case 9: case 10: case 11:
            value = 0;
            break;
        default:
            return 0;
        }
        *out_f = value;
    }
    return 0;
}
