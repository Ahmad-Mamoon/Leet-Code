class Solution:
    def lengthOfLastWord(self, s: str) -> int:

        last_word = s.strip().split()[-1]
        
        return len(last_word)