// Disassemble big-endian Xenon (PPC64 + AltiVec + VMX128) code.
// Usage: ppcdis <base_hex> < raw.bin ; prints "ADDR WORD text" per instruction.
use std::io::Read;
use powerpc::{Extensions, Ins};
fn main() {
    let base = u32::from_str_radix(std::env::args().nth(1).unwrap_or("0".into()).trim_start_matches("0x"), 16).unwrap();
    let mut buf = Vec::new();
    std::io::stdin().read_to_end(&mut buf).unwrap();
    let ext = Extensions::xenon();
    for (i, w) in buf.chunks_exact(4).enumerate() {
        let code = u32::from_be_bytes([w[0], w[1], w[2], w[3]]);
        let addr = base + (i as u32) * 4;
        let ins = Ins::new(code, ext);
        let mut text = format!("{}", ins.simplified());
        if let Some(dest) = ins.branch_dest(addr) { text = format!("{} -> {:#010x}", text, dest); }
        println!("{:08X} {:08x} {}", addr, code, text);
    }
}
