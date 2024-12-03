class Solution(object):
    def addSpaces(self, s, spaces):
        result = []
        space_index = 0
        for i, char in enumerate(s):
            if space_index < len(spaces) and i == spaces[space_index]:
                result.append(" ")
                space_index += 1
            result.append(char)
        return "".join(result)
        