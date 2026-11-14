/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

struct ts4_seq_result {
    unsigned int words[8];
};

void ts4_call_seq_u32_off10_888377C0(struct ts4_seq_result *out, const char *a, const char *b);
void fn_881B19A0(struct ts4_seq_result *value);

/* Swing_DLL.xex 0x881C7D08: for a type-12 entry, decodes a sequence value and maps its kind (0..9) to a result
 * code; other types return the type byte. */
unsigned int ts4_classify_entry_881C7D08(const char **handle)
{
    const char *entry = *handle;
    struct ts4_seq_result seq;
    unsigned int result = *(const unsigned char *)(entry + 8);

    if (result == 12) {
        const char *payload = entry + 0xc;
        ts4_call_seq_u32_off10_888377C0(&seq, payload, payload + 0x20);
        switch (seq.words[2]) {
        case 0:
            fn_881B19A0(&seq);
            return 0;
        case 1:
            fn_881B19A0(&seq);
            return 1;
        case 2:
            fn_881B19A0(&seq);
            return 0;
        case 3:
            fn_881B19A0(&seq);
            return 7;
        case 4:
            fn_881B19A0(&seq);
            return 10;
        case 5:
            fn_881B19A0(&seq);
            return 0;
        case 6:
            fn_881B19A0(&seq);
            return 0;
        case 7:
            fn_881B19A0(&seq);
            return 0;
        case 8:
            fn_881B19A0(&seq);
            return 0;
        case 9:
            fn_881B19A0(&seq);
            return 11;
        default:
            fn_881B19A0(&seq);
            result = 0;
            break;
        }
    }
    return result;
}
