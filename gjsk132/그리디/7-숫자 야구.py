from collections import defaultdict


def compare(a, b):

    a, b = str(a), str(b)

    s_cnt = 0
    b_cnt = 0

    for i in range(4):
        if a[i] == b[i]:
            s_cnt += 1
            b_cnt -= 1

        b_cnt += b.count(a[i])

    return s_cnt, b_cnt


def solution(n, submit):

    nums = []

    for i in range(1000, 10000):
        if len(set(str(i))) == 4:
            nums.append(i)

    def check(num):
        result = submit(num)

        return int(result[0]), int(result[3])

    def pick(cands):

        best_worst = len(cands) + 1
        best_num = cands[0]

        for g in cands:
            groups = defaultdict(int)

            for c in cands:
                key = compare(g, c)
                groups[key] += 1

            worst = max(groups.values())

            if worst < best_worst:
                best_worst = worst
                best_num = g

        return best_num

    first = [1234]

    while not len(nums) == 1:
        if first:
            target = first.pop()
        else:
            target = pick(nums)

        r_s, r_b = check(target)

        next_nums = []

        for n in nums:
            c_s, c_b = compare(target, n)

            if r_s == c_s and r_b == c_b:
                next_nums.append(n)

        nums = next_nums.copy()

    return nums[0]
