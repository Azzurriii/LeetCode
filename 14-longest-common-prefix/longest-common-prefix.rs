impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
    let mut prefix = String::new();
    
    if strs.is_empty() {
        return prefix;
    }
    
    for (i, c) in strs[0].chars().enumerate() {
        for s in strs.iter().skip(1) {
            match s.chars().nth(i) {
                Some(cc) => {
                    if cc != c {
                        return prefix;
                    }
                }
                None => return prefix,
            }
        }
        prefix.push(c);
    }
    
    prefix
}

}