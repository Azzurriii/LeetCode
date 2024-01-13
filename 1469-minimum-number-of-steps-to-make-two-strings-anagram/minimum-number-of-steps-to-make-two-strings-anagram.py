class Solution(object):
    def minSteps(self, s, t):
        return sum((Counter(s) - Counter(t)).values())
        