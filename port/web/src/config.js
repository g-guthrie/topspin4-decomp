// Viewer configuration from the page URL.  Serve the repository root (python3 -m http.server) and open
// /port/web/ : the defaults then point at work/port/assets/ and work/port/ts4core.wasm.
//   ?assets=URL   folder written by tools/port/export_assets.py (default ../../work/port/assets/)
//   ?wasm=URL     ts4core WebAssembly build (default ../../work/port/ts4core.wasm)
//   ?blob=URL     ts4core data blob (default <assets>/gameplay/ts4core.dat)
//   ?surface=hard|clay|grass
//   ?meshes=URL   folder of tools/ts4_assets.py exports (default ../../work/assets/)
//   ?venue=NAME   venue export folder under meshes (default venue_Amsterdam; 'none' = procedural court)
//   ?p0=NAME ?p1=NAME  player export folders (default player_Federer0 / player_Safina1; 'none' = bone drawing)
const q = new URLSearchParams(location.search);
const slash = (s) => (s.endsWith("/") ? s : s + "/");

export const cfg = {
  assets: slash(q.get("assets") || "../../work/port/assets/"),
  wasm: q.get("wasm") || "../../work/port/ts4core.wasm",
  blob: q.get("blob"),
  surface: q.get("surface") || "hard",
  meshes: slash(q.get("meshes") || "../../work/assets/"),
  venue: q.get("venue") || "venue_Amsterdam",
  players: [q.get("p0") || "player_Federer0", q.get("p1") || "player_Safina1"],
};
cfg.blob = cfg.blob || cfg.assets + "gameplay/ts4core.dat";

export async function fetchJson(url) {
  const r = await fetch(url);
  if (!r.ok) throw new Error("HTTP " + r.status + " for " + url);
  return r.json();
}

export const fmt = (v, d = 2) => (Number.isFinite(v) ? v.toFixed(d) : String(v));
