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

extern char lbl_880D05F0[];
int fn_888A1278(void);
int fn_888A1410(void);
int fn_888A1628(void);
int ts4_fn_888A09C0(void);

/* Swing_DLL.xex 0x888A16C0: maps a token id (15..41) to a result code and installs the next state handler;
 * id 20 first asks the encoding whether the input matches a keyword. */
int ts4_dispatch_token_888A16C0(struct ts4_parser_state *state, int token, const char *ptr, const char *end,
                                const struct ts4_encoding *enc)
{
    switch (token) {
    case 15:
        return 0x27;
    case 20:
        if (enc->match(enc, ptr + enc->min_bytes_per_char, end, lbl_880D05F0)) {
            state->handler = fn_888A1628;
            return 0x2b;
        }
        break;
    case 23:
        state->handler = fn_888A1410;
        state->mode = 2;
        return 0x2c;
    case 18:
    case 41:
        state->handler = fn_888A1278;
        return 0x33;
    case 30:
        state->handler = fn_888A1278;
        return 0x35;
    case 31:
        state->handler = fn_888A1278;
        return 0x34;
    case 32:
        state->handler = fn_888A1278;
        return 0x36;
    }
    if (state->nesting == 0 && token == 0x1c) {
        return 0x3b;
    }
    state->handler = ts4_fn_888A09C0;
    return -1;
}
