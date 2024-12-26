impl Solution {
    pub fn find_target_sum_ways(nums: Vec<i32>, target: i32) -> i32 {
        fn dfs(nums: &[i32], target: i32) -> i32 {
            match (nums, target) {
                ([], 0) => 1,
                ([], _) => 0,
                ([head, tail @ ..], _) => dfs(tail, target-head) + dfs(tail, target+head)
            }
        }
        dfs(&nums, target)
    }
}