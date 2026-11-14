// Optional bridge from the play view (src/play.js, PlayMode) to the venue crowd.  Not wired in by default: play.js
// is owned by other agents.  To use it, after PlayMode.load() resolves:
//
//   import { attachVenueCrowd } from "./venue/play_hook.js";
//   const crowd = await attachVenueCrowd(play, { assets: cfg.assets, venue: "Amsterdam" });
//   // in the frame loop:  crowd.update(dt);
//
// It loads the trackside officials, the net rig and the instanced crowd of work/port/assets/venues/<venue>/ (not
// the static stadium, which PlayMode.loadVenue already loads from the older ts4_assets export) and chains the
// session's onTick so every core event reaches the crowd director.
// Frame note: the venue exports mirror game z (z_gl = -z_game, see coreToVenue); PlayMode places players and the
// ball at +z_game.  The court is symmetric so the mismatch only swaps the two sides of the stands; set
// `mirror: true` to flip the crowd group instead (scale.z = -1, front faces flip, so double-sided materials help).
import { VenueScene } from "./venue_scene.js";

export async function attachVenueCrowd(play, { assets, venue = "Amsterdam", tier = 2, mirror = false, status } = {}) {
  const v = new VenueScene(assets, venue);
  await v.load({ staticScene: false, lights: false, tier, status: status || (() => {}) });
  if (mirror) v.group.scale.z = -1;
  play.env.scene.add(v.group);
  const s = play.session;
  if (s) {
    const prev = s.onTick;
    s.onTick = (a, b, fresh) => { if (prev) prev(a, b, fresh); for (const e of fresh) v.onEvent(e, b); };
  }
  return v;
}
