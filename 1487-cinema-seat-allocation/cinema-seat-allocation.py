class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        hmap = defaultdict(list)
        for row, seat in reservedSeats:
            hmap[row].append(seat)
        # print(hmap)
        reservedSeats.sort()
        
        ans = 0
        i=0
        j=1
        left = {2, 3, 4, 5}
        middle = {4, 5, 6, 7}
        right = {6, 7, 8, 9}
        while i < len(reservedSeats) :
            s = set()

            while  i < len(reservedSeats)  and reservedSeats[i][0]  == j:
                s.add(reservedSeats[i][1])
                i+=1

            if not s:
                ans += 2
                j += 1
                continue
            
            leftfree = len(left & s) == 0
            rightfree = len(right & s) == 0
            middlefree = len(middle & s) == 0

            if(leftfree and rightfree):
                ans += 1
            if(leftfree or middlefree or rightfree):
                ans += 1

            j += 1

        ans += (n-j+1)*2
        return ans
            
            
