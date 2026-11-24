/*
 * GP4 draft: CPhysicEngine wrapper around Havok 5.5 (Swing_DLL.xex 0x88878000-0x88882000).
 * Swing_DLL.xex sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 *
 * IMPORTANT FINDING: this wrapper does NOT integrate or force the tennis ball. Ball flight is the analytic stepper in
 * gp4_ball_flight.c. Havok carries (a) character/racket/ragdoll bodies that are keyframed from FrameSynchro, (b) static
 * scenery, and (c) the ball as a *collision detector / contact-event source* (plus a ray-cast "BallDetectCollision" flag).
 * A port can drop Havok for the ball entirely and keep only: contact classification, ray test, event queue semantics below.
 *
 * Read from machine code; names are roles. Havok calls are named by shape (hkpWorld::stepDeltaTime etc.), addresses given.
 */

/* ---------- world config record (0x30 bytes, cfg) consumed by fn_8887C108 (CPhysicEngineManager vtable lbl_880DF824 slot 1) ----------
 * Comes from an XData node keyed 0x56931990 inside Physics data (fn_88880440 copies 0x30-byte elements from
 * file->+0x1C table with memcpy; the same function seeds defaults: unit scale 100.0, substeps 1, dt 0.016). */
struct Gp4WorldCfg {
    float gravity[3];        /* +0x00..0x08 -> hkpWorldCinfo.m_gravity (w = 0)  [world gravity is DATA, not a literal] */
    int   solver_iterations; /* +0x0C -> fn_88475780(cinfo, v)  (hkpWorldCinfo setter; solver iteration count / contact-point config) */
    unsigned char byte_10;   /* +0x10 -> cinfo byte at +0x11d (hkpWorldCinfo flag, e.g. enableDeactivation / simulation type) */
    int   substeps;          /* +0x14 -> manager+0x08 : number of Havok stepDeltaTime calls per update */
    unsigned char byte_18;   /* +0x18 -> cinfo byte at +0x88 */
    float f_1c;              /* +0x1C -> fn_88475A30 (scalar setter on cinfo, first float arg: broad-phase world size / collision tolerance) */
    float f_20;              /* +0x20 -> cinfo float at +0xb0 */
    float unit_scale;        /* +0x24 -> manager+0x04 : gameplay cm per Havok metre (default 100.0, pool+0x20) */
    float timestep;          /* +0x28 -> manager+0x0C : seconds per game physics update (default 0.016 = pool+0x430) */
    int   i_2c;              /* +0x2C -> manager+0x14 */
};

/* ---------- manager update: fn_8887E5F8 (vtable slot 2) ---------- */
/*
 * void manager_update(Manager *m):
 *   if (!m->world_state) return;                              // m+0x34
 *   set a TLS "inside physics" byte to 1 (fn_88883CD0)
 *   paused = (current game state hash == 0x165BBDE9 "Pause") // lbl_88D45940 -> +0x24 -> [0]
 *   if (!paused) {
 *       for (b in m->bodies)  fn_8887C538(b);                 // clear last frame's contact event slots (+0x144..+0x148 vector)
 *       for (b in m->bodies)  fn_8887BEA8(b);                 // per-body control: ball re-enable timer, keyframing (below)
 *       for (p in m->processors) p->vtbl[3](p);               // CPhysicEngineCommandProcessor pre-step (+0x28 list)
 *       if (m->dirty (+0x18)) { cache = fn_8846BE08(world); fn_88472130(world, cache); fn_88471F10(world, cache);  m->dirty = 0 }  // refresh collision filters
 *       if (world && m->timestep > 0 && m->substeps > 0)
 *           for (i = 0; i < m->substeps; i++)  ts4_if_get_u32_off8_8846B398(world, m->timestep / (float)m->substeps);   // hkpWorld::stepDeltaTime
 *   }
 *   for (b in m->bodies) { fn_8887DCF0(b); b->vel_sample = ...; }   // read back Havok transforms -> FrameSynchro (below)
 *   for (p in m->processors) p->vtbl[1](p);                   // post-step
 *   if (a debug flag) debug_draw(...)
 *   clear the TLS byte
 *
 * => Integration settings handed to Havok: dt = cfg+0x28 (default 1/62.5 s = 0.016), substeps = cfg+0x14 (default 1),
 *    every call passes dt/substeps. Gravity / solver config = hkpWorldCinfo from cfg (data). Nothing else is hard coded.
 */

/* ---------- collision filter: fn_8887B148(manager, mode_hash)  (called with 0x26296DD2 = "Normal") ---------- */
/*
 * f = new hkpGroupFilter (fn_88439218: all 32 layer masks = -1 (collide), nextFreeSystemGroup = 2)
 * ts4_loop_get_u32_off0_884391C8(f, -2, -2)           // disable collisions between every pair of layers 1..31 (layer 0 keeps colliding with all)
 * then fn_88439158(f, a, b) = enableCollisionsBetween(a, b) for these layer pairs:
 *   if (mode != 0x2B05E119)       (1,2) (7,2) (5,2) (1,3) (7,3) (1,4) (7,4)
 *   (7,7) (7,1)                    always
 *   if (mode != 0x01505C7E)       (2,2)
 *   (2,6) (6,4)  (11,12) (13,14) (15,16) (17,18)
 * world->setCollisionFilter(f)   (fn_88472360)
 *
 * Layer of a body = low 5 bits of its collisionFilterInfo (body+0x2C), assigned in fn_8887F190 only when the .hkx value is 1:
 *   Player 0x9FB57F53 -> 6     Ball 0xD400E765 -> 2     Standalone 0x18C45490 -> 7     0xF61F38CF -> 5
 *   Environment 0xC0BA51F5 -> 1     0xDFA2AFF1 -> 1
 * An active ball is moved to layer 3 by fn_88879EC8 (collides with 1 and 7 only); a deactivated ball gets layer 8 = collides with nothing.
 */

/* ---------- ball wrapper object (0x1C0 bytes, ctor fn_8887EBE8, created in fn_88880B88 from 0x5C-byte Physics.bin records) ----------
 *  +0x04 f32 unit scale (cm per metre, copied from the manager)       +0x10 hkpRigidBody*           +0x14 body-owner info
 *  +0x48 saved collisionFilterInfo     +0x58 object type hash (Ball ...)     +0x60/+0x64 re-enable countdown / flag
 *  +0x68 "frozen" byte  +0x69 desired-active byte  +0x6A "bone driven" flag  +0x6B "keyframed from SRP" flag
 *  +0x70 -> BallDetectCollision byte in FrameSynchro (Frame[1]/BallDetectCollision/@Value)
 *  +0x74 f32 saved max-linear-velocity (decoded from the quantised byte at body+0x18C)   +0x78 f32 ball radius override (rec+0x58)
 *  +0x144 vector<event slot ptr> (GameDB:/GameDB/Physic/EventQueue children)
 *  +0x150 -> manager      +0x15C..0x164 / +0x16C..0x174 -> FrameSynchro SRP Position X,Y,Z / Rotation X,Y,Z (read, keyframed bodies)
 *  +0x17C..0x184 / +0x18C..0x194 -> FrameSynchro output Position X,Y,Z / Rotation (written from Havok)
 *  +0x19C..0x1A4 -> Frame[2]/SRP[@Name="BallNPlus1"]/Position X,Y,Z   +0x1AC..0x1B4 -> BallNPlus2 Position X,Y,Z
 */

/* ---------- ball activation: fn_88879EC8(obj, active) ---------- */
/*
 * if (!active) { if (rec->flag) { body.filterInfo = 8 (no collisions); updateCollisionFilterOnEntity(world, body);
 *                body.maxLinearVelocity = 100000 (pool+0x2EC, effectively unlimited); setMotionType(body, 6 (keyframed)); body.quality = 9;
 *                obj->countdown = 60; obj->countdownActive = 1; } }
 * else        { setMotionType(body, 1 (dynamic)); body.quality = obj->saved_quality (+0x154);
 *                if (type == Ball) { body.filterInfo = 3; updateCollisionFilterOnEntity(...); obj->u40 = 0; } }
 * obj->desired = active; if (!obj->frozen && type in {0x18C45490 Standalone, 0xF61F38CF}) obj->desired = 1;
 */

/* ---------- per-body control per update: fn_8887BEA8 ---------- */
/*
 * wanted = *obj->wantedPtr (+0x6C) if set else obj->desired (+0x69)
 * if (obj->wakeRequest (+0x65) == 1) { obj->countdownActive = 1; obj->countdown = 60; wanted = 0 }
 * if (obj->countdownActive) { if (obj->countdown > 0) --obj->countdown; else {          // 1 s after deactivation
 *       body.filterInfo = obj->saved_filter (+0x48); updateCollisionFilterOnEntity;
 *       body.maxLinearVelocity = quantise(obj->saved_maxvel (+0x74));  obj->u40 = obj->u4c;  countdownActive = 0 } }
 * if (wanted != obj->desired && !obj->frozen) fn_88879EC8(obj, wanted);
 * if (!wanted) { setMotionType(body, 6); body.quality = 9 }
 * fn_8887B6D0(obj, wanted)                                    // keyframe transfer, below
 * if (type == Ball && motionType(body) == 6) fn_8887BD30(obj) // BallDetectCollision ray cast
 */

/* ---------- keyframe transfer: fn_8887B6D0 (bodies driven by gameplay / animation) ----------
 * Source pose = FrameSynchro SRP Position (cm) / Rotation (euler) via the pointer block, or the animation bone matrices (+0x7C/+0x80);
 * target = position / unit_scale (cm -> m), orientation quaternion;  hkpKeyFrameUtility::applyHardKeyFrame(pos, quat, 1/dt, body)  (fn_884A36F0),
 * invDt = 1 / manager.timestep.  => keyframed bodies reach their target in exactly one physics step.
 */

/* ---------- ball ray test "BallDetectCollision": fn_8887BD30 ----------
 * Runs only for the Ball wrapper while its body is KEYFRAMED (motion type 6):
 *   from = BallNPlus1.Position * 0.01  (m),   to = BallNPlus2.Position * 0.01 (m)
 *   if (|to - from| components all <= 0.001) skip
 *   hkpWorldRayCastInput { from, to, enableShapeCollectionFilter = 0, filterInfo = 4 }   // filter layer 4: collides with layers 1,7,6
 *   hkpWorld::castRay(world, in, out) (ts4_call_seq_u32_off70_8846B810);   if (out.rootCollidable != null) *(obj->+0x70) = 1;   // FrameSynchro BallDetectCollision
 * i.e. the gameplay ball path (stepper) is checked against the static scenery (+ players) by a segment test one tick ahead.
 */

/* ---------- Havok -> FrameSynchro read-back: fn_8887DCF0 ----------
 * pos_cm = body.position * unit_scale ; copies to obj+0x100.. ; velocity-ish sample at obj->+0x140: {pos, prev_pos, pos - prev_pos, |delta|^2};
 * written to the FrameSynchro SRP Position X/Y/Z outputs (obj+0x17C..0x184) when the object is not the game-mode 0x725D27D9 / 0x893C0BB8 case;
 * rotation via fn_8864E0F0 -> Rotation X/Y/Z (obj+0x18C..0x194).
 */

/* ---------- contact events ---------- */
/*
 * fn_88881B20 (listener, registered through vtable lbl_880DF84C slot via fn_88881E28) and fn_8887CB40 -> fn_8887C748 (queue writer).
 * Event record (obj+0x9C..0xBC, 0x20+ bytes) built from the two colliding wrappers via fn_88880750:
 *    +0x9C / +0xA0 u32  id of body A / B (wrapper+0x40)     +0xA4 / +0xA8 f32  speed |v| of A / B at contact (|wrapper+0x1A0|)
 *    +0xAC / +0xB0 u32  object type hash A / B (Ball D400E765, Environment C0BA51F5, Standalone 18C45490, ...)
 *    +0xB4 / +0xB8 i32  wrapper+0x44 of A / B (-1 default)      +0xC8 = 60 (ticks)      +0xBC.. vector of contact points (m * unit scale = cm)
 * fn_88881B20 only forwards pairs {Standalone, Environment} to fn_8887C748; fn_8887CB40 forwards every pair except Environment/Environment.
 * fn_8887C748 copies the record into the first free slot (byte +0x20 == 0) of the GameDB:/GameDB/Physic/EventQueue children (type hash 0x0C3C8F59
 * slot objects) and sets the slot busy; consumers (CPhysicEventSynchro, fn_888CB8F0; sound layer, gp5) read them next frame.
 * => Ground/Net/Let/scenery "contact kinds" are NOT computed in code: they come from the pair of object type hashes and the layers
 *    defined in Physics.hkx / Physics.bin.
 */

/* ---------- data files ---------- */
/*
 * <root>\Physics\Physics.hkx : Havok packfile (hkRootLevelContainer): hkpPhysicsData with bodies/shapes/materials (friction, restitution, damping, mass,
 *                              collisionFilterInfo=1 placeholder) and, in a second root class, ragdoll/constraint tables. Loaded by fn_88880B88 (names from the
 *                              string table: "Physics\Physics", ".bin", ".hkx") through fn_884CB2C8 (Havok packfile reader).
 * <root>\Physics\Physics.bin : engine XData table (fn_88922710 parser) of 0x5C-byte object records (type hash, SRP names, flags, ball radius +0x58 ...)
 *                              and the 0x30-byte world config records (key 0x56931990). fn_88958D10 resolves "Physics.bin"/"Physics.hkx" file names for the loader.
 * fn_888807E8: second loader for the character ragdolls (names prefixed "Ragdoll_" resolved to hashed ids, registered to the animation service).
 * fn_88879098 / fn_888791E8: Havok warning/log shims (PhysicData.cpp line 0x27, PhysicEngineCommandProcessor.cpp line 0x1E3), no gameplay effect.
 */
