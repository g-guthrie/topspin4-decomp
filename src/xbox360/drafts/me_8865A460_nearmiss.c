/* me_8865A460 near-miss: 73 off (LTCG + primer; plain route listed in the report). Hue -> packed 0xFFRRGGBB colour
   (sret; negative hue gives 0xFFADADAD). Reading the 0.0/2.0 externs into locals reproduces the target's f31/f30
   saved-FPR constants. Residue: hue*two fmuls operand order, the target recomputes (1 - frac) twice, extern
   relocations (0x8814B440/0x8814B45C share one base), and the fctidz/pack register order. 8 variants. */
extern float g_ts4_event_value;   /* 0.0f (0x8814B440) */
extern float lbl_8814B45C;        /* 2.0f */
extern const float lbl_880C8F9C;  /* 4.0f */
extern double floor(double);
typedef struct Color { unsigned int argb; } Color;

Color *fn_8865A460(Color *c, float hue)
{
    float zero = g_ts4_event_value;
    float two, h, i, frac, t, q, r, g, b;
    if (hue < zero) {
        c->argb = 0xFFADADADu;
        return c;
    }
    two = lbl_8814B45C;
    h = hue * two;
    i = (float)floor(h);
    frac = h - i;
    q = 1.0f - frac;
    t = 1.0f - q;
    if (i == zero) { r = 1.0f; g = t; b = zero; }
    else if (i == 1.0f) { g = 1.0f; r = q; b = zero; }
    else if (i == two) { g = 1.0f; r = zero; b = t; }
    else if (i == 3.0f) { r = zero; g = q; b = 1.0f; }
    else if (i == lbl_880C8F9C) { g = zero; r = t; b = 1.0f; }
    else { r = 1.0f; g = zero; b = q; }
    c->argb = ((((0xFF00u + (unsigned int)(r * 255.0f)) << 8) + (unsigned int)(g * 255.0f)) << 8) + (unsigned int)(b * 255.0f);
    return c;
}
