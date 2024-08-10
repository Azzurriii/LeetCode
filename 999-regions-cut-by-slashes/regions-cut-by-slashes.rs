struct UnionFind {
    parent: Vec<usize>,
    count: usize,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        let parent = (0..n).collect();
        Self { parent, count: n }
    }

    fn find(&mut self, mut x: usize) -> usize {
        while self.parent[x] != x {
            self.parent[x] = self.parent[self.parent[x]];
            x = self.parent[x];
        }
        x
    }

    fn union(&mut self, mut x: usize, mut y: usize) {
        let root_x = self.find(x);
        let root_y = self.find(y);
        if root_x != root_y {
            self.parent[root_x] = root_y;
            self.count -= 1;
        }
    }
}

impl Solution {
    pub fn regions_by_slashes(grid: Vec<String>) -> i32 {
        let n = grid.len();
        let mut uf = UnionFind::new(4 * n * n);
        for i in 0..n {
            let row = grid[i].as_bytes();
            for j in 0..n {
                let index = 4 * (i * n + j);
                match row[j] {
                    b'/' => {
                        uf.union(index, index + 3);
                        uf.union(index + 1, index + 2);
                    }
                    b'\\' => {
                        uf.union(index, index + 1);
                        uf.union(index + 2, index + 3);
                    }
                    _ => {
                        uf.union(index, index + 1);
                        uf.union(index + 1, index + 2);
                        uf.union(index + 2, index + 3);
                    }
                }
                if i > 0 {
                    uf.union(index, index - 4 * n + 2);
                }
                if j > 0 {
                    uf.union(index + 3, index - 3);
                }
            }
        }
        uf.count as i32
    }
}