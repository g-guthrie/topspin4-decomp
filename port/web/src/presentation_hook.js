// Presentation hook (agent A3): wires the TV camera (camera_tv.js) and match audio (audio.js) into PlayMode with a
// handful of one-line calls in play.js, the same pattern as players/play_hook.js.
//
// URL options (read here so config.js stays untouched):
//   ?cam=port        keep the port's own follow camera (helpers.js cameraGoal) instead of the game's TV shot
//   ?tvcam=TVZoom    TV option: TV (default), TVFar, TVClose, TVZoom, TVZoomFar, TVZoomClose, TV3D
//   ?tvaspect=normal use the 4:3 ("Normal") records instead of the Widescreen ones
//   ?audio=off       no sound;  ?audiovenue=NAME  events.json folder under <assets>/audio/ (default Amsterdam)
// Assets (all optional, written from the user's disc into work/port/assets/, git-ignored):
//   cameras/shots.json   python3 tools/port/camera_export.py
//   audio/<venue>/events.json + audio/banks/   python3 tools/port/audio_export.py
import { TvCamera, TV_OPTIONS } from './camera_tv.js';
import { AudioDirector, MatchAudio } from './audio.js';
import { fetchJson } from './config.js';

const Q = typeof location !== 'undefined' ? new URLSearchParams(location.search) : new URLSearchParams();

export async function attachPresentation(play) {
  const { cfg } = play.env;
  const p = {
    tv: new TvCamera(), director: new AudioDirector(),
    audio: new MatchAudio({ base: cfg.assets + 'audio/', venue: Q.get('audiovenue') || 'Amsterdam' }),
    camMode: Q.get('cam') === 'port' ? 'port' : 'tv', notes: [], lastCam: null,
  };
  play.presentation = p;
  try {
    const j = await fetchJson(cfg.assets + 'cameras/shots.json');
    p.tv = new TvCamera(j.shots);
  } catch (e) { p.notes.push('TV camera: built-in fallback record (' + e.message + ')'); }
  const opt = Q.get('tvcam');
  if (opt && TV_OPTIONS.includes(opt)) p.tv.setOption(opt);
  if (Q.get('tvaspect') === 'normal') p.tv.widescreen = false;
  if (Q.get('audio') !== 'off' && typeof AudioContext !== 'undefined') {
    await p.audio.load(fetchJson);
    // browsers start audio only after a user gesture
    const unlock = () => p.audio.ensureContext();
    window.addEventListener('keydown', unlock, { once: true });
    window.addEventListener('pointerdown', unlock, { once: true });
  } else p.audio.status = 'audio off';
  play.status += '; ' + p.audio.status + '; camera: ' + (p.camMode === 'port' ? 'port follow cam' : p.tv.loaded ? 'TV (Shots.bin export)' : 'TV (fallback record)');
}

export function presentationStart(play) {
  const p = play.presentation;
  if (!p) return;
  p.audio.stopAll();
  p.director = new AudioDirector();
  p.director.start();
  p.tv.state = null;
}

export function presentationTick(play, prev, cur, evs) { play.presentation?.director.onTick(prev, cur, evs); }

export function presentationFrame(play, dt) {
  const p = play.presentation;
  if (!p) return;
  p.audio.run(p.director.frame(dt, play.session?.cur?.players || []));
}

/** returns true when the TV camera drove the view this frame */
export function presentationCamera(play, dt, view) {
  const p = play.presentation;
  if (!p || p.camMode !== 'tv') return false;
  const side = Math.sign(view.players[0].pos[0]) || play.camSide;     // film from the human's end (PORT choice)
  play.camSide = side;
  const r = p.tv.update(dt, view.players.map((pl) => pl.pos), side);
  const cam = play.env.camera;
  cam.position.set(...r.pos);
  cam.up.set(0, 1, 0);
  cam.lookAt(...r.look);
  if (Math.abs(cam.fov - r.fovDeg) > 0.01) { cam.fov = r.fovDeg; cam.updateProjectionMatrix(); }
  play.camPos = r.pos; play.camLook = r.look; p.lastCam = r;
  return true;
}
