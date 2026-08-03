# def solution(prices):
#     length = len(prices)
#     answer = [0] * length

#     for i in range(length):
#         for j in range(i+1, length):
#             answer[i] += 1
#             if prices[i] > prices[j]:
#                 break

#     return answer

def solution(prices):
    answer = [0] * len(prices)
    stack = []

    for i in range(len(prices)):
        while stack and prices[stack[-1]] > prices[i]:
            top = stack.pop()
            answer[top] = i - top
        stack.append(i)

    for i in stack:
        answer[i] = len(prices) - 1 - i

    return answer