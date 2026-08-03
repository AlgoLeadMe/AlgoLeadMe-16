# def solution(sizes):
#     max_w = 0
#     max_h = 0
#     for w, h in sizes:
#         w, h = max(w, h), min(w, h)
#         max_w = max(max_w, w)
#         max_h = max(max_h, h)
#     return max_w * max_h

def solution(sizes):
    for size in sizes:
        size.sort(reverse=True)
    w, h = map(list, zip(*sizes))
    return max(w) * max(h)

