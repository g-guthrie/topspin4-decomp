#ifndef GP4_TYPES_H
#define GP4_TYPES_H

/*
 * GP4 (WP4): ball flight stepper (0x889C0EF8-0x889C2AB4, 0x888AA968-0x888AD3xx) and the PhysicEngine
 * wrapper over Havok (0x88878000-0x88882000).
 * Swing_DLL.xex sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 *
 * Extends GP3's Gp3BallState (src/xbox360/gp3_types.h) with the fields the stepper reads/writes.
 * Every offset below was read from machine code; see work/gameplay-notes/gp4.md section 2 for evidence.
 * Units INSIDE the stepper ("local frame", fn_889C1160): metres, seconds, origin = ball+0x70.
 * Units OUTSIDE (world frame, fn_889C0FE8): centimetres, 60 Hz ticks (positions *100 + origin).
 */

typedef unsigned char  gp4_u8;
typedef unsigned int   gp4_u32;

/* ---- hashes (zlib crc32 of the ASCII name unless marked "unnamed") ---- */
#define GP4_HASH_LET_IN        0x8F903DFBu /* ball mode "LetIn"  (net cord / let handling on) */
#define GP4_HASH_LET_OUT       0x02315629u /* ball mode "LetOut" */
#define GP4_HASH_WOOD          0x9CAFB633u /* ball mode "Wood" (racket frame hit) */
#define GP4_HASH_NET           0xCAA7531Fu /* ball mode "Net" */
#define GP4_HASH_OUT           0x81A72B79u /* ball mode "Out" */
#define GP4_HASH_MODE_LIVE_A   0x9EA301C2u /* unnamed: live ball with no net interaction (LetIn rewritten to this by prediction) */
#define GP4_HASH_MODE_LIVE_B   0x5D25ED1Du /* unnamed: same for LetOut */
#define GP4_HASH_MODE_CA68AAEC 0xCA68AAECu /* unnamed: treated like Out by fn_889C0C70 */
#define GP4_HASH_CURVE_1D      0xF9F12A60u /* template node type: 1-D piecewise-linear curve (fn_8817A688, 20-byte keys) */
#define GP4_HASH_CURVE_2D      0x7A330099u /* template node type: 2-D table (fn_8826D278) */
#define GP4_HASH_CONST         0x33799CCEu /* template node type: plain float */
/* shot "solver kind" stored at template+0x20 (= tpl_ptr+0x8, tpl_ptr = table + index + 0x18), names unknown */
#define GP4_KIND_AB8D0         0x5D90675Bu /* -> fn_888AB8D0 : min-speed / commanded-speed flight-time bisection */
#define GP4_KIND_AC748         0x2DB3EB6Fu /* -> fn_888AC748 */
#define GP4_KIND_ACDA8         0x50B89452u /* -> fn_888ACDA8 */
#define GP4_KIND_ACA68         0xC1965E5Cu /* -> fn_888ACA68 */

/* Havok wrapper: object-type hashes (crc32): Ball, Player, Environment, Standalone */
#define GP4_HASH_OBJ_BALL        0xD400E765u
#define GP4_HASH_OBJ_PLAYER      0x9FB57F53u
#define GP4_HASH_OBJ_ENVIRONMENT 0xC0BA51F5u
#define GP4_HASH_OBJ_STANDALONE  0x18C45490u
#define GP4_HASH_OBJ_F61F38CF    0xF61F38CFu /* unnamed, collision layer 5 */
#define GP4_HASH_OBJ_DFA2AFF1    0xDFA2AFF1u /* unnamed, collision layer 1 */
#define GP4_HASH_PHYSIC_NORMAL   0x26296DD2u /* "Normal": argument of fn_8887B148 (collision filter build) */
#define GP4_HASH_STATE_PAUSE     0x165BBDE9u /* "Pause": game state in which fn_8887E5F8 does not step Havok */

/* ---------------------------------------------------------------------------------------------
 * Piecewise-linear curve key blocks used by the shot template (fn_881899D8 and fn_8817A688).
 * fn_881899D8(x, curve): curve = { i32 first_key_off (-1 = none); i32 key_count; ... } keys are 16 bytes
 *    { x_a, x_b, y_a, y_b }:  y = y_a + clamp((x - x_a)/(x_b - x_a), 0, 1) * (y_b - y_a)
 *    picking the LAST key with x_a <= x (first key if none).
 * fn_8817A688(x, curve): keys are 20 bytes { x_a, x_b?, y_a, slope, ... } :
 *    y = y_a + max(min(x - x_a, x_b - x_a), 0) * slope.
 * --------------------------------------------------------------------------------------------- */
struct Gp4Curve16Key { float x_a, x_b, y_a, y_b; };

/* ---------------------------------------------------------------------------------------------
 * Ball stepper object ("S", vtable lbl_880DCA74: slot2 fn_889C28B0 = step every ball, slot4 fn_889C28F0 = link templates)
 * ctor fn_889C1690:  +0x1C = 60.0 (ticks per second, pool+0x15C), +0x20 = 1/60 (pool+0xE0), +0x24 = 1.0,
 *                    +0x28..+0x30 vector<Gp4BallState*> of balls, +0x34/+0x38 generator objects G1/G2 (0xC bytes each:
 *                    vtable lbl_880D6B70, +4 = 1/60 s per tick, +8 = template table pointer = S+0x3C),
 *                    +0x40 = "ball currently in local frame" flag (fn_889C1160/fn_889C0FE8), +0x41 same for the launch
 *                    vectors (fn_889C0F70/fn_889C0EF8), +0x42 = flag read by the net bounce (nonzero -> keep the spin).
 * --------------------------------------------------------------------------------------------- */
struct Gp4Generator { void *vtbl; float seconds_per_tick; void *template_table; };
struct Gp4Stepper {
    void *vtbl;                 /* +0x00 */
    gp4_u8 pad_04[0x18];
    float ticks_per_second;     /* +0x1C = 60.0 */
    float seconds_per_tick;     /* +0x20 = 1/60 */
    float one;                  /* +0x24 = 1.0 */
    void **balls_begin, **balls_end, **balls_cap; /* +0x28 vector of Gp4BallState* */
    struct Gp4Generator *g1;    /* +0x34 pre-bounce arc generator   (fn_888AB558) */
    struct Gp4Generator *g2;    /* +0x38 post-bounce arc generator  (fn_888AD1C8) */
    void *templates;            /* +0x3C shot-template table (data driven, loaded by the module's XData; row pointer = table + ball.template_index) */
    gp4_u8 local_frame;         /* +0x40 */
    gp4_u8 launch_local_frame;  /* +0x41 */
    gp4_u8 keep_spin_on_net;    /* +0x42 */
};

/* ---------------------------------------------------------------------------------------------
 * Ball state view used by the stepper. Only fields that the code touches are named; everything is at the
 * real offset (use GP4_BALL_* accessors in drafts, or cast to Gp3BallState for the GP3-named ones).
 * Offsets (hex) -> meaning:
 *  +0x000 f32 flight_time        tau, seconds, from "to"-point arrival (command C+0x40); solved by the kind routines
 *  +0x004 u32 bounce_tick        first bounce at tick >= this (command C+0x44) (int)
 *  +0x008 f32 T                  template+0x54 : position scale in the closed forms (see notes)
 *  +0x014 i32 bounce_count       +0x018 i32 tick   +0x01C i32 tick_prev (time origin of the current arc)
 *  +0x020 i32 launch_frame       +0x024 tpl_ptr (table + template_index + 0x18)   +0x028 i32 hold_ticks
 *  +0x02C u32 mode
 *  +0x030..0x034 u8 flags        0x31 net check, 0x32 net is solid, 0x33 net-cord (let) deflection, 0x34 = "net/cord hit happened"
 *  +0x040 vec4 pos   +0x060 vec4 pos_prev   +0x070 vec4 origin   +0x080 vec4 drift (spin acceleration vector A)
 *  +0x090 f32 spin_a  +0x094 f32 spin_b  +0x098 f32 spin_c      (blend of template curves, fn_889C1868)
 *  +0x0A0 vec4 hold_delta
 *  +0x100 vec4 p_from  +0x110 vec4 p_to  (+0x120 vec4)  +0x124 f32 net_height_cm (read by the net test, w of +0x120)
 *  +0x130 vec4 arc2_pos   +0x140 vec4 arc2_vel   (start state of the post-bounce arc)
 *  +0x150 f32 1/T  +0x154 f32 1/a4  +0x158 f32 k=T/a4  +0x15C f32 g*a4  +0x160 1/T^2  +0x164 a4^2  +0x168 T^2
 *  +0x16C..+0x17C  scaled endpoints (p_from.x*T, p_to.x*T, p_from.y*T, p_from.z*T, p_to.z*T)  (fn_888AAEA8)
 *  +0x180 f32 E=exp(-k*tau)  +0x184 f32 1/(E-1)  +0x188..0x190 tau*A  +0x194 g*a4*tau        (fn_888AAE00)
 *  +0x340 vec4 cmd_from  +0x350 vec4 cmd_to  +0x344 f32 (w of cmd_from: argument of the spin-curves)  +0x360 u32 template_index
 *  +0x364 f32 spin_blend (0..1)   +0x368 u8 sidespin_sign_flag  +0x36C f32  +0x370 f32 speed_kmh_target  +0x3A8 f32
 *  +0x430 f32  +0x434 u32 shot id  +0x43C u8 new_shot
 *  +0x494,+0x498 f32 net-cord deflection angles (degrees)  +0x49C f32 net-cord speed loss  +0x4A0 f32 net-cord spin loss
 *  +0x4D0 f32 ball_radius_cm(?)  +0x4D4 f32 a4 (drag-time constant)  +0x4D8 f32 g (gravity, m/s^2)  +0x4DC u32 max_bounces
 *  +0x4E0 u8 frozen  +0x4E1 u8 no_sidespin   +0x4F0 vec4 velocity_per_second   +0x500 launch velocity  +0x510 arrival velocity
 *  +0x530 u8 enabled
 * --------------------------------------------------------------------------------------------- */
typedef struct Gp4Vec4 { float x, y, z, w; } Gp4Vec4;

#endif /* GP4_TYPES_H */
