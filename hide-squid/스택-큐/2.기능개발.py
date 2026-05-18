def solution(progresses, speeds):
    answer = []
    a = []
    for i in range(len(progresses)):
        a.append((100 - progresses[i] + speeds[i] - 1) // speeds[i])
    print(a)
    
    current = a[0]
    cnt = 1
    
    for k in range(1, len(a)):
        if (a[k] <= current):
            cnt += 1
        else:
            answer.append(cnt)
            cnt = 1
            current = a[k]
    answer.append(cnt)
    return answer
