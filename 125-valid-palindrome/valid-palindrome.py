class Solution:
    def isPalindrome(self, s: str) -> bool:

        def ispali(s):
            l = 0
            r = len(s) - 1

            while(l<=r):
                if s[l] == s[r]:
                    l += 1
                    r -= 1
                else:
                    return False
            return True

        ss = ""

        for ch in s:
            if ch.isalnum():
                ss += ch.lower()
        print(ss)
        return ispali(ss)