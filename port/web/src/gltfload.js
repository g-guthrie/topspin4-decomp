// glTF loading that survives a busy local dev server: the textures of a venue (90 PNGs) fetched all at once make
// python's http.server reset connections, which leaves untextured meshes.  Here every external image is fetched
// first, a few at a time with retries, and handed to GLTFLoader as a blob URL.
import * as THREE from "three";
import { GLTFLoader } from "three/addons/loaders/GLTFLoader.js";

async function fetchRetry(url, tries = 5) {
  let last = null;
  for (let i = 0; i < tries; i++) {
    try { const r = await fetch(url); if (r.ok) return r; last = new Error("HTTP " + r.status + " for " + url); if (r.status === 404) break; }
    catch (e) { last = e; }
    await new Promise((res) => setTimeout(res, 120 * (i + 1)));
  }
  throw last;
}

export async function loadGltfRobust(url, { concurrency = 4, onProgress } = {}) {
  const base = url.slice(0, url.lastIndexOf("/") + 1);
  const text = await (await fetchRetry(url)).text();
  const json = JSON.parse(text);
  const uris = [...new Set((json.images || []).map((i) => i.uri).filter((u) => u && !u.startsWith("data:")))];
  if (json.buffers) for (const b of json.buffers) if (b.uri && !b.uri.startsWith("data:")) uris.push(b.uri);
  const blobs = new Map();
  const queue = [...uris];
  let done = 0;
  const worker = async () => {
    for (let u = queue.shift(); u !== undefined; u = queue.shift()) {
      try { blobs.set(u, URL.createObjectURL(await (await fetchRetry(base + u)).blob())); } catch { /* leave it to the loader: it reports the failure */ }
      if (onProgress) onProgress(++done, uris.length);
    }
  };
  await Promise.all(Array.from({ length: concurrency }, worker));
  const manager = new THREE.LoadingManager();
  manager.setURLModifier((u) => { const rel = u.startsWith(base) ? u.slice(base.length) : u; return blobs.get(decodeURIComponent(rel)) || blobs.get(rel) || u; });
  const loader = new GLTFLoader(manager);
  const gltf = await new Promise((res, rej) => loader.parse(text, base, res, rej));
  return gltf;
}
