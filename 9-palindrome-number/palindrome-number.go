func isPalindrome(x int) bool {
    if x < 0 || (x != 0 && x%10 == 0) {
		return false
	}
	halfReversed := 0
	for x > halfReversed {
		halfReversed = halfReversed*10 + x%10
		x /= 10
	}
	return x == halfReversed || x == halfReversed/10
}