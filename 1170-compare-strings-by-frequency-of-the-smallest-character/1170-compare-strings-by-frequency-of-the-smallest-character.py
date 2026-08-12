class Solution:
    from collections import Counter
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:

        result = []
        arr1 = []
        for i in queries:
            new_string = "".join(sorted(i))
            arr1.append(new_string.count(new_string[0]))
            # arr1.sort()
        print(arr1)


        arr2 = []
        for i in words:
            new_string = "".join(sorted(i))
            arr2.append(new_string.count(new_string[0]))
            arr2.sort()
        print(arr2)

        for i in arr1:
            solution = 0
            for j in arr2:
                if i < j:
                   solution += 1
            result.append(solution)
        return(result)

        


        