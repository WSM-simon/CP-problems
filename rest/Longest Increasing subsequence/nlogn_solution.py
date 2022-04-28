import bisect

nums = [1,2,3,21,23,4]
def solve():
    if len(nums) == 0:
        return (0)

    tails = []
    for n in nums:
        idx = bisect.bisect_left(tails, n)
        tails[idx:idx + 1] = [n]
    return (len(tails))

print(solve())