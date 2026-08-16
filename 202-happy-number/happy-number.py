class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        if(n==1):
            return True
        while(n):
            seen.add(n)
            prod = 0
            
            while(n!=0):
                x = n%10
                n = n //10
                prod += x * x

            if(prod in seen):
                return False
            
            if(prod == 1):
                return True
            n = prod   

        return True