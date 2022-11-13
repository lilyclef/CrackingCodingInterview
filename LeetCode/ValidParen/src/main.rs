fn is_paren(s: String) -> bool {
    let mut st: Vec<char> = Vec::new();
    for c in s.chars() {
        if c == '{' || c == '(' || c == '[' {
            st.push(c);
        }
        if c == '}' {
            if let Some(last) = st.pop() {
                if last == '{' {
                    continue;
                }
            }
            return false;
        }
        if c == ']' {
            if let Some(last) = st.pop() {
                if last == '[' {
                    continue;
                }
            }
            return false;
        }
        if c == ')' {
            if let Some(last) = st.pop() {
                if last == '(' {
                    continue;
                }
            }
            return false;
        }
    }
    st.is_empty()
}
fn main() {
    let s = "()[{}";
    println!("{}", is_paren(s.to_string()));
}
