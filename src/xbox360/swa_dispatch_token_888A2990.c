/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

struct ts4_encoding {
    char pad0[0x1c];
    int (*match)(const struct ts4_encoding *, const char *, const char *, const char *);
    char pad1[0x44 - 0x20];
    int min_bytes_per_char;
};

struct ts4_parser_state {
    int (*handler)(void);
    int mode;
    char pad[0x8];
    int nesting;
};

extern char lbl_880D0568[];
int fn_888A2928(void);
int ts4_fn_888A09C0(void);

/* Swing_DLL.xex 0x888A2990: maps a token id (11..29) to a result code and installs the next state handler;
 * id 16 asks the encoding whether the input matches a keyword. */
int ts4_dispatch_token_888A2990(struct ts4_parser_state *state, int token, const char *ptr, const char *end,
                                const struct ts4_encoding *enc)
{
    int result;

    switch (token) {
    case 14:
    case 15:
        return 0;
    case 11:
        return 0x37;
    case 13:
        return 0x38;
    case 16:
        if (enc->match(enc, ptr + enc->min_bytes_per_char * 2, end, lbl_880D0568)) {
            state->handler = fn_888A2928;
            return 3;
        }
        break;
    case 29:
        result = 2;
        state->handler = ts4_fn_888A09C0;
        return result;
    }
    if (state->nesting == 0 && token == 0x1c) {
        return 0x3b;
    }
    state->handler = ts4_fn_888A09C0;
    return -1;
}
