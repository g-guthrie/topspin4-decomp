// Pure helpers of appearance.js (no three.js; tested in test/players.test.mjs).
/** pick the LOD level for a camera distance in cm and the part's [Distance1, Distance2] (pure) */
export function lodLevel(distCm, dists) {
  const [d1, d2] = dists && dists[0] > 0 ? dists : [1000, 1500];
  return distCm < d1 ? 0 : distCm < d2 ? 1 : 2;
}

/** variant key for a match condition: sweat 0..3 and the surface (clay / grass dirt on the F maps), pure */
export function variantKey(sweat, surface) {
  const s = Math.max(0, Math.min(3, Math.round(sweat || 0)));
  const dirt = surface === "clay" || surface === "grass" ? "_" + surface : "";
  return "sweat" + s + dirt;
}

/** best available variant: exact, then the same sweat without dirt, then lower sweat levels (pure) */
export function pickVariant(variants, sweat, surface) {
  if (!variants) return null;
  for (let s = Math.round(sweat || 0); s >= 0; s--) {
    for (const k of [variantKey(s, surface), variantKey(s, null)]) if (variants[k]) return variants[k];
  }
  return null;
}

/** level actually drawn for a part that has nodes for `levels`: the coarsest level <= want, else its finest (pure) */
export function useLevel(want, levels) {
  const ok = levels.filter((l) => l <= want);
  return ok.length ? Math.max(...ok) : Math.min(...levels);
}
