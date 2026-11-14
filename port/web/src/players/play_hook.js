// Glue between PlayMode (../play.js, the match loop) and the game animation driver of this folder.  Enabled with
// ?anim=game.  Per tick it prefers the core's own animation state (P1's ts4_anim_view, read with core_anim.js) and
// falls back to deriving the state from Ts4PlayerView (position, velocity, heading, swing state / progress).
import { fetchJson } from "../config.js";
import { AnimTables, heightScale } from "./anim_logic.js";
import { GameAnimator, ClipStore, recordToCore } from "./game_animator.js";
import { PlayerModel, loadRoster } from "./appearance.js";
import { readAnimView, hashIndex, viewToState } from "./core_anim.js";
import { guessSwingClass, planarSpeed } from "../helpers.js";

export async function attachGameAnimation(pm) {
  const { cfg } = pm.env;
  try {
    const [rules, clipMap, animDb] = await Promise.all([
      fetchJson(cfg.assets + "players/anim_rules.json"), fetchJson(cfg.assets + "clip_map.json"), fetchJson(cfg.assets + "animations.json")]);
    const tables = new AnimTables(rules);
    let roster = [];
    try { roster = await loadRoster(cfg.assets + "players/"); } catch { roster = []; }
    let chains = null;
    try { chains = await fetchJson(cfg.assets + "players/clip_chains.json"); } catch { chains = null; }
    const store = new ClipStore(pm.rigs[0].loader, cfg.assets, animDb, recordToCore(clipMap), chains);
    pm.game = [];
    pm.gameModels = [];
    for (let i = 0; i < 2; i++) {
      const rig = pm.rigs[i];
      if (!rig.mixer || !rig.skinned) { pm.game.push(null); pm.gameModels.push(null); continue; }
      const entry = roster.find((e) => e.arc.replace(".arc", "") === cfg.players[i]) || {};
      const setup = entry.gender === "Female" ? "Women" : "Men";
      const an = new GameAnimator(rig, tables, store, { setup, leftHanded: entry.plays === "LeftHanded" });
      an.hashes = hashIndex(tables, setup);
      const s = heightScale(rules.height_steps, setup === "Women" ? 1 : 0, entry.height_cm || 0);
      an.heightScale = s;                                          // I: PlayerHeight step factor (root motion scale)
      pm.game.push(an);
      pm.gameModels.push(new PlayerModel().attach(rig.skeletonScene, cfg.meshes + cfg.players[i] + "/player.gltf"));
      await store.preload(an.wanted());
      an.calibrateFacing();
    }
    pm.gameStore = store;
    pm.status += "; game animation driver: " + store.raw.size + " clips" + (store.missing.size ? ", " + store.missing.size + " records not exported" : "");
  } catch (e) {
    pm.game = null;
    pm.status += "; ?anim=game unavailable: " + e.message + " (run tools/ts4_players.py animrules and tools/port/clip_map.py)";
  }
}

export function gameDrive(pm, i, dt, viewPlayer) {
  const an = pm.game[i], ses = pm.session, cur = ses.cur.players[i], t = pm.tun, s = pm.sw[i];
  const view = readAnimView(ses.core, i);
  const anim = view ? viewToState(view, an.hashes) : null;
  if (cur.swingState === 1 && s.prevState !== 1 && !s.gameGuess) {
    s.gameGuess = guessSwingClass({ buttons: pm.released[i].buttons, playerPos: cur.pos, ballPos: ses.cur.ball.pos,
                                    bounceCount: ses.cur.ball.bounceCount, tun: t, leftHanded: !!(cur.flags & 2) });
  }
  if (cur.swingState === 0) s.gameGuess = null;
  an.leftHanded = anim ? anim.mirrored : !!(cur.flags & 2) || an.leftHanded;
  const tf = ses.view?.()?.tickF ?? ses.cur.tick;
  an.update(dt, { pos: viewPlayer.pos, vel: cur.vel, heading: viewPlayer.heading, swingState: cur.swingState, swingT: viewPlayer.swingT,
                  recoveryFrac: (tf - s.state2Start) / Math.max(1, t.recoveryTicks), swingClass: s.gameGuess || (cur.swingState === 2 ? "serve" : null),
                  anim }, { walk: t.walk, jog: t.jog, rush: t.rush, idleMax: 30 });
  const model = pm.gameModels?.[i];
  if (model) {
    const cam = pm.env.camera.position, r = pm.rigs[i].root.position;
    model.setLodDistance(Math.hypot(cam.x - r.x, cam.y - r.y, cam.z - r.z) * 100);
  }
  return planarSpeed(cur);
}
