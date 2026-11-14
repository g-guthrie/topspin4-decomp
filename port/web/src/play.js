// Playable match: ties ts4core (MatchSession at fixed 60 Hz) to the three.js scene.
//   - two PlayerRigs driven by snapshot position / heading / swing state, animated by RigAnimator
//   - ball, bounce / hit effects, broadcast camera with smoothing, HUD (scoreboard, messages, hints, debug)
// Everything simulated comes from the core; what is drawn here is port-side presentation (placeholders marked).
import * as THREE from "three";
import { MatchSession } from "./match.js";
import { PlayerRig } from "./player.js";
import { ClipLibrary, RigAnimator } from "./animator.js";
import {
  CM, CAM, clamp, lerp, damp, dampVec, planarSpeed, cameraGoal, guessSwingClass, swingClassForRow, isForehand, locomotionClass,
  describeEvent, phaseHint, scoreRows, effectiveSwingScale, matchConfigFrom, serveChargeTime,
} from "./helpers.js";
import { fetchJson, fmt } from "./config.js";
import { loadGltfRobust } from "./gltfload.js";

const NAMES = ["You", "CPU"];
const BTN_SHOT = 1 | 2 | 4 | 8;

export class PlayMode {
  /** env: { scene, camera, controls, canvas, cfg, manifest, anim, toast, $ } */
  constructor(env) {
    this.env = env;
    this.session = null;
    this.rigs = [];
    this.anims = [null, null];
    this.lib = null;
    this.active = false;
    this.follow = true;
    this.debug = false;
    this.group = new THREE.Group();
    this.group.name = "play";
    this.group.visible = false;
    env.scene.add(this.group);
    this.ball = new THREE.Mesh(new THREE.SphereGeometry(0.04, 20, 14), new THREE.MeshStandardMaterial({ color: 0xd8f03c, roughness: 0.7 }));
    this.ball.castShadow = true;
    this.ballShadow = new THREE.Mesh(new THREE.CircleGeometry(0.04, 16), new THREE.MeshBasicMaterial({ color: 0x000000, transparent: true, opacity: 0.35 }));
    this.ballShadow.rotation.x = -Math.PI / 2;
    this.group.add(this.ball, this.ballShadow);
    this.fx = [];                         // transient rings {mesh, age, life}
    this.traceLine = null;
    this.camPos = [-20, 5, 0]; this.camLook = [0, 1, 0]; this.camSide = -1;
    this.tun = { walk: 220, jog: 480, rush: 700, recoveryTicks: 24, delayTicks: 18, chargeTicks: 40, serveH: 270, ballRadius: 4,
                 volleyXMax: 400, splitVolley: 180, splitOther: 180, smashLoV: 180, smashHiV: 400, smashLoO: 180, smashHiO: 400 };
    this.released = [{ buttons: null }, { buttons: null }];     // last shot buttons per human player (for the swing guess)
    this.heldUnion = 0;
    this.sw = [{ prevState: 0, state2Start: 0, guess: null, clip: null, actualRow: null }, { prevState: 0, state2Start: 0, guess: null, clip: null, actualRow: null }];
    this.msgTimer = 0;
    this.log = [];
    this.fps = 0;
    this.status = "not loaded";
    this.hudLast = "";
  }

  // ---------------------------------------------------------------------------------------------- loading
  async init() {
    const { cfg, manifest, anim } = this.env;
    try {
      this.session = await MatchSession.load({ wasmUrl: cfg.wasm, blobUrl: cfg.blob });
      const missing = this.session.core.missingTunables();
      this.status = "ok: " + this.session.core.buildInfo() + (missing.length ? " (missing tunables: " + missing.join(", ") + ")" : "");
      if (missing.length) { this.session = null; this.status = "ts4core refuses to start: missing tunables " + missing.join(", "); return false; }
    } catch (e) {
      this.status = "ts4core not available: " + e.message + " (build work/port/ts4core.wasm and export the data blob, see docs/port/web.md)";
      return false;
    }
    this.session.onTick = (prev, cur, evs) => this.onTick(prev, cur, evs);
    let clipCfg = {}, clipMap = null;
    try { clipCfg = await fetchJson("clipmap.config.json"); } catch (e) { this.status += "; clipmap.config.json: " + e.message; }
    try { clipMap = await fetchJson(cfg.assets + "clip_map.json"); } catch { clipMap = null; }
    this.clipCfg = clipCfg; this.clipMapLoaded = !!clipMap;
    const skels = manifest?.skeletons || [];
    for (let i = 0; i < 2; i++) {
      const rig = new PlayerRig(i === 0 ? 0xffd34d : 0x6ec1ff);
      const sk = skels[i] || skels[0];
      const mesh = cfg.players[i] !== "none" ? cfg.meshes + cfg.players[i] + "/player.gltf" : null;
      let skinned = false;
      if (mesh) {
        try { await rig.loadSkeleton(mesh, { skinned: true }); skinned = true; }
        catch (e) { this.meshNote = (this.meshNote || "") + " player " + i + " mesh: " + e.message + ";"; }
      }
      if (skinned) { /* skinned player export loaded */ }
      else if (sk) { try { await rig.loadSkeleton(cfg.assets + sk.file); } catch (e) { this.status += "; skeleton: " + e.message; rig.showPlaceholder(); } }
      else rig.showPlaceholder();
      this.group.add(rig.root);
      this.rigs.push(rig);
    }
    this.lib = new ClipLibrary(this.rigs[0].loader, cfg.assets, anim, clipCfg, clipMap);
    if (this.rigs.some((r) => r.mixer)) {
      await this.lib.preload();
      this.anims = this.rigs.map((r) => (r.mixer ? new RigAnimator(r, this.lib) : null));
    }
    this.refreshTunables();
    return true;
  }

  /** load the exported venue glTF (metres, right-handed) in place of the procedural court; keeps the procedural net */
  async loadVenue(courtGroup) {
    const { cfg, scene } = this.env;
    if (cfg.venue === "none") return false;
    try {
      const gltf = await loadGltfRobust(cfg.meshes + cfg.venue + "/venue.gltf", { onProgress: (n, m) => { this.env.$("playStatus").textContent = "loading venue textures " + n + "/" + m; } });
      gltf.scene.traverse((o) => { if (o.isMesh) { o.receiveShadow = true; o.frustumCulled = true; } });
      gltf.scene.name = "venue";
      scene.add(gltf.scene);
      courtGroup.children.forEach((c) => { if (c.name !== "net") c.visible = false; });
      this.venue = gltf.scene;
      return true;
    } catch (e) { this.meshNote = (this.meshNote || "") + " venue: " + e.message + ";"; return false; }
  }

  get ready() { return !!this.session; }

  /** re-read the tunables the presentation depends on (call after any retuning edit) */
  refreshTunables() {
    if (!this.session) return;
    const g = (n, d) => this.session.core.getTunable(n) ?? d, t = this.tun;
    t.walk = g("move.speed_walk_cms", t.walk); t.jog = g("move.speed_jog_cms", t.jog); t.rush = g("move.speed_rush_cms", t.rush);
    t.recoveryTicks = g("swing.recovery_ticks", t.recoveryTicks); t.delayTicks = g("swing.contact_delay_ticks", t.delayTicks);
    t.chargeTicks = g("shot.charge_full_ticks", t.chargeTicks); t.serveH = g("serve.contact_height_cm", t.serveH);
    t.ballRadius = g("ball.radius_cm", t.ballRadius);
    t.volleyXMax = g("reach.volley_x_max_cm", t.volleyXMax); t.splitVolley = g("reach.split_height_volley_cm", t.splitVolley);
    t.splitOther = g("reach.split_height_other_cm", t.splitOther); t.smashLoV = g("reach.smash_lo_volley_cm", t.smashLoV);
    t.smashHiV = g("reach.smash_hi_volley_cm", t.smashHiV); t.smashLoO = g("reach.smash_lo_other_cm", t.smashLoO);
    t.smashHiO = g("reach.smash_hi_other_cm", t.smashHiO);
    const r = t.ballRadius * CM;
    this.ball.scale.setScalar(r / 0.04); this.ballShadow.scale.setScalar(r / 0.04);
  }

  // ---------------------------------------------------------------------------------------------- match control
  start(form) {
    if (!this.session) return -1;
    const rc = this.session.start(matchConfigFrom(form));
    this.log = [];
    this.sw.forEach((s) => Object.assign(s, { prevState: 0, state2Start: 0, guess: null, clip: null, actualRow: null }));
    this.anims.forEach((a) => a && a.endSwing());
    this.refreshTunables();
    if (rc === 0) {
      this.camSide = Math.sign(this.session.cur.players[0].pos[0]) || -1;
      this.snapCamera();
    }
    return rc;
  }

  setActive(on) {
    this.active = on && this.ready;
    this.group.visible = this.active;
    if (this.env.controls) this.env.controls.enabled = !(this.active && this.follow);
  }

  setFollow(on) {
    this.follow = on;
    if (this.env.controls) this.env.controls.enabled = !(this.active && this.follow);
    if (!on && this.env.controls) { this.env.controls.target.set(...this.camLook); this.env.controls.update(); }
  }

  // ---------------------------------------------------------------------------------------------- per tick (animation triggers)
  onTick(prev, cur, evs) {
    const t = this.tun;
    for (let i = 0; i < 2; i++) {
      const p = cur.players[i], s = this.sw[i], an = this.anims[i];
      const st = p.swingState, was = s.prevState;
      if (st === 1 && was === 0) {
        const cls = guessSwingClass({ buttons: this.released[i].buttons, playerPos: p.pos, ballPos: cur.ball.pos, bounceCount: cur.ball.bounceCount,
                                      tun: t, leftHanded: !!(p.flags & 2) });
        s.guess = cls; s.actualRow = null;
        s.clip = an ? an.beginSwing(cls) : null;
      } else if (st === 2 && was === 0) {
        // serve: the core launches the ball on the release tick, there is no swing_state 1 phase
        if (an && !an.swingActive) { s.guess = "serve"; s.clip = an.beginSwing("serve"); }
      }
      if (st === 2 && was !== 2) s.state2Start = cur.tick;
      if (st === 0 && was !== 0 && an) an.endSwing();
      s.prevState = st;
    }
    for (const e of evs) {
      if (e.type === "hit") {
        const s = this.sw[e.a];
        if (s) s.actualRow = e.b;
        this.addRing(e.pos, 0xffffff, 0.5, 0.25, true);
      } else if (e.type === "bounce") this.addRing([e.pos[0], 0, e.pos[2]], 0xffd34d, 0.25, 0.5);
      else if (e.type === "net") this.addRing(e.pos, 0xff3366, 0.3, 0.4, true);
      const msg = describeEvent(e, NAMES);
      if (msg) this.say(msg);
      this.log.push(e.type + (e.type === "hit" ? " p" + e.a + " row " + e.b : e.type === "point_end" ? " win " + e.a + " why " + e.b : "") + " @" + e.tick);
      if (this.log.length > 8) this.log.shift();
    }
  }

  say(msg) { this.msgTimer = 1.8; this.message = msg; }

  addRing(posCm, color, size, life, vertical = false) {
    const m = new THREE.Mesh(new THREE.RingGeometry(0.6, 1, 28), new THREE.MeshBasicMaterial({ color, transparent: true, opacity: 0.9, side: THREE.DoubleSide, depthTest: false }));
    m.position.set(posCm[0] * CM, vertical ? posCm[1] * CM : 0.02, posCm[2] * CM);
    if (!vertical) m.rotation.x = -Math.PI / 2;
    m.renderOrder = 5;
    this.group.add(m);
    this.fx.push({ mesh: m, age: 0, life, size, vertical });
  }

  // ---------------------------------------------------------------------------------------------- per frame
  /** input: a Ts4Input-like {stick_x, stick_z, buttons} from InputMapper.toTs4Input() (neutral while a form field has focus) */
  update(dt, input) {
    if (!this.active || !this.session) return;
    const ses = this.session;
    if (dt > 0) this.fps = lerp(this.fps || 60, 1 / dt, 0.05);
    const typing = /^(INPUT|SELECT|TEXTAREA)$/.test(document.activeElement?.tagName || "") && document.activeElement.type !== "range" && document.activeElement.type !== "checkbox";
    const inp = typing ? { stick_x: 0, stick_z: 0, buttons: 0 } : input;
    ses.setInput(0, { x: inp.stick_x, z: inp.stick_z, buttons: inp.buttons });
    // remember the shot buttons of the swing being released (the core reports the row only after the hit)
    const shot = inp.buttons & BTN_SHOT;
    if (shot) this.heldUnion |= inp.buttons & (BTN_SHOT | 16);
    else if (this.heldUnion) { this.released[0] = { buttons: this.heldUnion }; this.heldUnion = 0; }
    ses.frame(dt);
    const view = ses.view();
    if (!view) return;
    this.draw(dt, view, inp);
    for (let i = this.fx.length - 1; i >= 0; i--) {
      const f = this.fx[i];
      f.age += dt;
      const k = f.age / f.life;
      if (k >= 1) { this.group.remove(f.mesh); f.mesh.geometry.dispose(); f.mesh.material.dispose(); this.fx.splice(i, 1); continue; }
      f.mesh.scale.setScalar(f.size * (0.4 + k));
      f.mesh.material.opacity = 0.9 * (1 - k);
      if (f.vertical) f.mesh.lookAt(this.env.camera.position);
    }
    if (this.msgTimer > 0) this.msgTimer -= dt;
    this.updateHud(view);
  }

  draw(dt, view, inp) {
    const t = this.tun, ses = this.session;
    // players
    for (let i = 0; i < 2; i++) {
      const p = view.players[i], rig = this.rigs[i];
      rig.root.position.set(p.pos[0] * CM, 0, p.pos[2] * CM);
      rig.root.rotation.y = -p.heading;
      rig.root.scale.z = (p.flags & 2) ? -1 : 1;              // left-handed: mirror the rig
      const an = this.anims[i];
      if (an) {
        const s = this.sw[i];
        const cur = ses.cur.players[i];
        let windUp = null;
        if (i === 0 && view.phase === "serve" && view.score.server === 0 && cur.swingState === 0) {
          const down = inp.buttons & BTN_SHOT;
          if (down && !an.swingActive) { s.guess = "serve"; s.clip = an.beginSwing("serve"); }
          if (down && an.swing) windUp = serveChargeTime(an.swing.contact, (view.pointTicks - (this.chargeStart ?? view.pointTicks)) / t.chargeTicks);
          if (!down) this.chargeStart = null; else if (this.chargeStart == null) this.chargeStart = view.pointTicks;
          if (!down && an.swingActive && cur.swingState === 0) an.endSwing();
        }
        const tf = view.tickF ?? ses.cur.tick;
        an.update(dt, { speed: planarSpeed(cur), tun: t, swingState: cur.swingState, swingT: p.swingT,
                        recoveryFrac: (tf - s.state2Start) / Math.max(1, t.recoveryTicks), windUp });
      }
    }
    // ball (render-only: toss placeholder while serving)
    const b = view.ball;
    let by = b.pos[1];
    if (view.phase === "serve" && !b.live) {
      const sv = view.score.server;
      const charge = sv === 0 && this.chargeStart != null ? clamp((view.pointTicks - this.chargeStart) / t.chargeTicks, 0, 1) : 0;
      by = lerp(100, t.serveH, charge);                       // PLACEHOLDER toss: the core has no toss model yet
    }
    this.ball.visible = this.ballShadow.visible = view.phase !== "idle";
    this.ball.position.set(b.pos[0] * CM, by * CM, b.pos[2] * CM);
    this.ballShadow.position.set(b.pos[0] * CM, 0.005, b.pos[2] * CM);
    this.updateCamera(dt, view);
  }

  snapCamera() {
    const v = this.session?.cur;
    if (!v) return;
    const g = cameraGoal({ side: this.camSide, player: v.players[0].pos, ball: v.ball.pos });
    this.camPos = g.pos; this.camLook = g.look;
    if (this.follow) { this.env.camera.position.set(...g.pos); this.env.camera.lookAt(...g.look); }
  }

  updateCamera(dt, view) {
    if (!this.follow) return;
    const side = Math.sign(view.players[0].pos[0]) || this.camSide;
    if (side !== this.camSide) { this.camSide = side; this.snapCamera(); return; }
    const g = cameraGoal({ side, player: view.players[0].pos, ball: view.ball.pos });
    this.camPos = dampVec(this.camPos, g.pos, CAM.lambdaPos, dt);
    this.camLook = dampVec(this.camLook, g.look, CAM.lambdaLook, dt);
    const cam = this.env.camera;
    cam.position.set(...this.camPos);
    cam.lookAt(...this.camLook);
    if (Math.abs(cam.fov - CAM.fov) > 0.01) { cam.fov = CAM.fov; cam.updateProjectionMatrix(); }
  }

  // ---------------------------------------------------------------------------------------------- HUD
  updateHud(view) {
    const $ = this.env.$;
    const rows = scoreRows(view.score, NAMES);
    const html = rows.map((r) =>
      "<tr><td class='srv'>" + (r.serving ? "&#9679;" : "") + "</td><td class='nm'>" + r.name + "</td>" +
      r.games.map((g, k) => "<td class='gm" + (k === view.score.curSet ? " cur" : "") + "'>" + g + "</td>").join("") +
      "<td class='pt'>" + r.game + "</td></tr>").join("");
    const msg = this.msgTimer > 0 ? this.message : "";
    const sig = html + "|" + msg + "|" + view.phase + "|" + view.score.server + "|" + view.score.secondServe;
    if (sig !== this.hudLast) {
      this.hudLast = sig;
      $("hudScore").innerHTML = "<table>" + html + "</table>" + (view.score.secondServe ? "<div class='sub'>second serve</div>" : "") + (view.score.tiebreak ? "<div class='sub'>tiebreak</div>" : "");
      $("hudMsg").textContent = msg; $("hudMsg").style.opacity = msg ? 1 : 0;
      $("hudHint").textContent = phaseHint(view, 0);
    }
    if (this.debug) $("hudDebug").textContent = this.debugText(view);
  }

  debugText(view) {
    const ses = this.session, c = ses.cur, t = this.tun;
    const lines = ["tick " + c.tick + "  phase " + c.phase + "  hash " + ses.core.stateHash().toString(16).padStart(8, "0") +
                   "  fps " + fmt(this.fps, 0) + (ses.stepper.dropped ? "  dropped " + ses.stepper.dropped : "") + "  alpha " + fmt(ses.stepper.alpha, 2)];
    for (let i = 0; i < 2; i++) {
      const p = c.players[i], s = this.sw[i], sp = planarSpeed(p);
      lines.push("P" + i + " pos " + p.pos.map((v) => fmt(v, 0)).join(",") + " spd " + fmt(sp, 0) + " " + locomotionClass(sp, t) +
                 " mv " + p.moveState + " swing " + p.swingState + " t " + fmt(p.swingT, 2) + " row " + p.templateRow);
      if (s.guess) {
        const info = this.anims[i]?.lastInfo;
        const actual = s.actualRow != null ? swingClassForRow(s.actualRow, isForehand(p.pos, c.ball.pos, !!(p.flags & 2))) : "?";
        lines.push("   swing class guess " + s.guess + " / by row " + actual + "  clip " + (info ? info.label + " [" + info.source + "]" + (info.placeholder ? " PLACEHOLDER" : "") +
                   " contact " + fmt(info.contact, 2) + "s x" + fmt(effectiveSwingScale(info.contact, t.delayTicks), 2) : "none (not exported)"));
      }
    }
    lines.push("events: " + this.log.slice(-6).join(" | "));
    if (this.lib) lines.push("clips: " + this.lib.loaded.size + " loaded" + (this.lib.missing.size ? ", NOT exported: " + [...this.lib.missing].join(",") : "") +
                             (this.clipMapLoaded ? ", clip_map.json present" : ", no clip_map.json (placeholder mapping)"));
    return lines.join("\n");
  }

  // ---------------------------------------------------------------------------------------------- probe overlay
  /** draw a probe trace (cm points) as a line in the scene; call with null to clear */
  showTrace(points, color = 0xff8a3d) {
    if (this.traceLine) { this.group.remove(this.traceLine); this.traceLine.geometry.dispose(); this.traceLine = null; }
    if (!points || !points.length) return;
    const a = new Float32Array(points.length * 3);
    points.forEach((p, i) => { a[3 * i] = p[0] * CM; a[3 * i + 1] = p[1] * CM; a[3 * i + 2] = p[2] * CM; });
    const g = new THREE.BufferGeometry(); g.setAttribute("position", new THREE.BufferAttribute(a, 3));
    this.traceLine = new THREE.Line(g, new THREE.LineBasicMaterial({ color, depthTest: false }));
    this.traceLine.renderOrder = 6;
    this.group.add(this.traceLine);
  }
}
