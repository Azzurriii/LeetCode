impl Solution {
    pub fn min_days(grid: Vec<Vec<i32>>) -> i32 {
        fn is_single_island(mut grid: Vec<Vec<i32>>) -> bool {
            let mut count = 0;
            for row in 0..grid.len() {
                for col in 0..grid[row].len() {
                    if grid[row][col] == 1 {
                        if count > 0 { return false }
                        count += 1;
                        let mut stack = vec![(row,col)];
                        while !stack.is_empty() {
                            let (row, col) = stack.pop().unwrap();
                            grid[row][col] = 0;
                            if row>0 && grid[row-1][col] == 1 { stack.push((row-1,col)) };
                            if row<grid.len()-1 && grid[row+1][col] == 1 { stack.push((row+1,col)) };
                            if col>0 && grid[row][col-1] == 1 { stack.push((row,col-1)) };
                            if col<grid[row].len()-1 && grid[row][col+1] == 1 { stack.push((row, col+1)) }
                        }
                    }
                }
            }
            count != 0
        }
        if !is_single_island(grid.clone()) { return 0 }
        for row in 0..grid.len() {
            for col in 0..grid[row].len() {
                let mut new_grid = grid.clone();
                new_grid[row][col] = 0;
                if !is_single_island(new_grid) { return 1 }    
            }
        }
        2
    }
}