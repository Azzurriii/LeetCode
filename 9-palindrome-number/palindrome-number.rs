impl Solution {
    pub fn is_palindrome(x:i32)->bool{
        if x<0 || (x%10==0 && x!=0){
            return false;
        }

        let mut reverted = 0;
        let mut temp = x;
        while temp > 0 {
            reverted = reverted * 10 + temp % 10;
            temp /= 10;
        }

        if x == reverted {
            return true;
        } else {
            return false;
        }
    }
}