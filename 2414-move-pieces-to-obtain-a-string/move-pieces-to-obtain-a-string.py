class Solution:
    def canChange(self, start: str, target: str) -> bool:
        s_p = 0
        t_p = 0

        while True:
            while s_p < len(start) and start[s_p] == "_":
                s_p += 1
            while t_p < len(target) and target[t_p] == "_":
                t_p += 1
            if s_p == len(start) and t_p == len(target):
                return True
            if s_p == len(start) or t_p == len(target):
                return False
            # if not the same
            if start[s_p] != target[t_p]: return False
            # for L 
            if start[s_p] == "L":
                if s_p < t_p: return False
            else:
                if s_p > t_p: return False
            s_p += 1
            t_p += 1
        return 