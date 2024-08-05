impl Solution {
    pub fn kth_distinct(arr: Vec<String>, k: i32) -> String {
        let mut distinct_count = 0;
        for i in 0..arr.len() {
            if Self::is_distinct(&arr, i) {
                distinct_count += 1;
                if distinct_count == k {
                    return arr[i].clone();
                }
            }
        }
        String::new()
    }

    fn is_distinct(arr: &Vec<String>, index: usize) -> bool {
        arr.iter().filter(|&s| s == &arr[index]).count() == 1
    }
}