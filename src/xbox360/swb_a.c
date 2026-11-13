/* Family SWB: small switch-bearing functions, batch A. */

/* Reads out two fields and maps the kind at +0x1c to a size; returns 0. */
int ts4_swb_get_fields_and_size_88336790(char *object, unsigned int *out_a, unsigned int *out_b,
                                         unsigned int *out_c, unsigned int *out_size)
{
    if (out_a) *out_a = *(unsigned int *)(object + 0x18);
    if (out_b) *out_b = *(unsigned int *)(object + 0x1c);
    if (out_c) *out_c = *(unsigned int *)(object + 0x48);
    if (out_size) {
        switch (*(unsigned int *)(object + 0x1c)) {
        case 0: *out_size = 0; break;
        case 1: *out_size = 8; break;
        case 2: *out_size = 0x10; break;
        case 3: *out_size = 0x18; break;
        case 4: *out_size = 0x20; break;
        case 5: *out_size = 0x20; break;
        case 6: case 7: case 8: case 9: case 10: case 11: *out_size = 0; break;
        }
    }
    return 0;
}
