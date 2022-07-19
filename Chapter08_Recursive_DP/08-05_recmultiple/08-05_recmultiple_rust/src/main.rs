// a * b aをb回足す
// a + (aをb-1回足す)
// a + a + ... (1回足す=>aを返す)
// O(b)

// 8 * 7 -> (4 * 7) + (4 * 7) [bit] -> (2 * 7) * 2 * 2
// 11 * 7 -> 7 + 10 * 7 -> 7 + (5 * 7) * 2 ->7 + ((2 * 7) * 2 + 7) * 2 -> 
// bitを使うために2で割って計算すると早いね
// 掛け算どのくらい

fn __multi(mut bigger:u32, smaller:u32) -> u32 {
    if smaller == 1 {
        return bigger
    }
    if (smaller & 1u32) == 1u32 {
        // odd
        bigger + __multi(bigger, smaller - 1u32)
    } else {
        // even
        __multi(bigger, smaller >> 1) << 1
    }
}

fn multi(a:u16, b:u16) -> u32 {
    if a > b {
        __multi(a as u32, b as u32)
    } else {
        __multi(b as u32, a as u32)
    }
}
// u16 (2^32)

fn main() {
    // 7 * 8 = 56
    assert_eq!(multi(8, 7), 56);
    println!("End!");
}
