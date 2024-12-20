// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn reverse_odd_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut current_level = vec![root.as_ref().unwrap().clone()];
        let mut level = 0;
        
        while !current_level.is_empty() {
            let mut next_level = vec![];
            for node in &current_level {
                let node_borrow = node.borrow();
                if let Some(left) = &node_borrow.left {
                    next_level.push(left.clone());
                }
                if let Some(right) = &node_borrow.right {
                    next_level.push(right.clone());
                }
            }
            
            level += 1;
            if level % 2 != 0 && !next_level.is_empty() {
                let mut i = 0;
                let mut j = next_level.len() - 1;
                while i < j {
                    let left_val = next_level[i].borrow().val;
                    let right_val = next_level[j].borrow().val;
                    next_level[i].borrow_mut().val = right_val;
                    next_level[j].borrow_mut().val = left_val;
                    i += 1;
                    j -= 1;
                }
            }
            
            current_level = next_level;
        }
        
        root
    }
}