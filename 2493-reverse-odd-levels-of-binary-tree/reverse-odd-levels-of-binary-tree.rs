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
		let mut a = vec![root.as_ref().unwrap().clone()];
		let mut level = 0;
		while !a.is_empty() {
			let b = a;
			a = vec![];
			for node in &b {
				if node.borrow().left.is_some() {
					a.push(node.borrow().left.as_ref().unwrap().clone());
					a.push(node.borrow().right.as_ref().unwrap().clone());
				}
			}
			level += 1;
			if level % 2 != 0 && a.len() > 0 {
				let (mut i, mut j) = (0, a.len() - 1);
				while i < j {
					let tmp = a[i].borrow().val;
					a[i].borrow_mut().val = a[j].borrow().val;
					a[j].borrow_mut().val = tmp;
					i += 1; j -= 1;
				}
			}
		}
		root
	}
}