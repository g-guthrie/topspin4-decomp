#ifndef GP7_TYPES_H
#define GP7_TYPES_H

/*
 * GP7 (WP7): swing animation engine types. Swing_DLL.xex sha256
 * dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 * Offsets were read from machine code (evidence in work/gameplay-notes/gp7.md);
 * names are roles, a trailing question mark in a comment marks a guess.
 * Time is 60 Hz ticks held in floats; positions are centimetres.
 * C++ header: the layer stack uses an STL-style vector (size()/operator[]), which is the form
 * that reproduces the original loop code.
 */

struct Gp7ClipDesc {              /* clip descriptor (data loaded from Animations.bin / AOD) */
    unsigned char pad00[0x0c];
    unsigned short slot;          /* +0x0c layer slot, 0xffff = not playing */
    unsigned char pad0e[0x14 - 0x0e];
    float time_ratio;             /* +0x14 clip time ratio; (ratio - 1.0f) scales the event offset */
    unsigned char pad18[0x70 - 0x18];
    int events_rel;               /* +0x70 relative offset (from +0x70) of the event table */
    int kind;                     /* +0x74 clip kind; 2 = the kind whose event time is at table+0x38 */
};

struct Gp7ClipRef {               /* instance->+4 -> +8 */
    unsigned char pad00[8];
    Gp7ClipDesc *desc;            /* +0x08 */
};

struct Gp7AnimLayer {             /* one playing animation instance (element of the layer stack) */
    unsigned char pad00[4];
    Gp7ClipRef *inner;            /* +0x04 */
    unsigned char pad08[0x14 - 0x08];
    float rate;                   /* +0x14 playback rate; (rate - 1.0f) is the stretch term */
    unsigned char pad18[0x24 - 0x18];
    float base_time;              /* +0x24 */
};

struct Gp7LayerVec {              /* std::vector<Gp7AnimLayer *> layout: first, last */
    Gp7AnimLayer **_Myfirst;
    Gp7AnimLayer **_Mylast;
    int size() const { return (int)(_Mylast - _Myfirst); }
    Gp7AnimLayer *&operator[](int i) { return _Myfirst[i]; }
};

struct Gp7AnimStack {             /* object at SwingAnimController+0x2c */
    unsigned char pad00[0x18];
    float now;                    /* +0x18 current animation time (ticks) */
    unsigned char pad1c[0x5c - 0x1c];
    Gp7LayerVec layers;           /* +0x5c begin, +0x60 end */
};

#endif
