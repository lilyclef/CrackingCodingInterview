struct Codec {}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Codec {
    fn new() -> Self {
        Codec {}
    }

    fn encode(&self, strs: Vec<String>) -> String {
        let mut ans: String = String::from("");
        for cur_str in strs {
            let hexed_str: String = Self::char_to_hex(&cur_str);
            ans.push_str(&hexed_str);
            ans.push(',');
        }
        ans.pop();
        ans
    }

    fn decode(&self, s: String) -> Vec<String> {
        let splitted: Vec<&str> = s.split(',').collect();
        let mut ans: Vec<String> = Vec::new();

        for each_str in splitted {
            let mut es = each_str.to_string();
            es = es.chars().rev().collect();
            let mut es_ans = String::from("");
            while !es.is_empty() {
                let mut rs = String::from("");
                let first = if let Some(first) = es.pop() {
                    first
                } else {
                    todo!()
                };
                let second = if let Some(second) = es.pop() {
                    second
                } else {
                    todo!()
                };
                rs.push(first);
                rs.push(second);
                let tmp = u8::from_str_radix(&rs, 16).unwrap();
                es_ans.push(tmp as char);
            }
            ans.push(es_ans);
        }
        ans
    }

    fn char_to_hex(s: &str) -> String {
        s.chars()
            .into_iter()
            .map(|c| format!("{:x}", c as u8))
            .collect()
    }
}

/**
 * Your Codec object will be instantiated and called as such:
 * let obj = Codec::new();
 * let s: String = obj.encode(strs);
 * let ans: VecVec<String> = obj.decode(s);
 */
fn main() {
    // hello,world,name => h,ello,world,name
    // "he,l\"lo","world", "name" // RFC CSV
    // [hex],[hex],
    let obj = Codec::new();
    let strs_vec = vec!["hello", "world", "name"]
        .iter()
        .map(|s| s.to_string())
        .collect();
    let s: String = obj.encode(strs_vec);
    println!("{}", s);
    println!("----");
    let ans: Vec<String> = obj.decode(s);
    for a in ans {
        println!("{}", a);
    }
}
