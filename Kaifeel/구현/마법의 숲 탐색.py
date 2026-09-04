r, c, k = map(int, input().split())

unit = [list(map(int, input().split())) for _ in range(k)]

arr = [[1] + [0] * c + [1] for _ in range(r + 3)] + [[1] * (c + 2)]
exit_set = set()

di = [-1, 0, 1, 0]
dj = [0, 1, 0, -1]

ans = 0
num = 2

def bfs(si, sj):
    q=[]
    v=[[0]*(c+2) for _ in range(r+4)]
    max_i=0

    q.append((si, sj))
    v[si][sj]=1
    while q:
        ci,cj=q.pop(0)
        max_i = max(max_i, ci)
        for di,dj in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            ni,nj=ci+di,cj+dj
            if v[ni][nj]==0 and (arr[ci][cj]==arr[ni][nj] or ((ci, cj) in exit_set and arr[ni][nj] > 1)):
                q.append((ni, nj))
                v[ni][nj] = 1
    return max_i-2


for cj, dir in unit:
    ci = 1
    while True:
        # 남쪽이 비어있는지 확인
        if arr[ci+1][cj-1]+arr[ci+2][cj]+arr[ci+1][cj+1] == 0:
            ci+=1
        # 왼쪽으로 돌아서 이동
        elif arr[ci-1][cj-1]+arr[ci][cj-2]+arr[ci+1][cj-1]+arr[ci+1][cj-2]+arr[ci+2][cj-1] == 0:
            ci+=1
            cj-=1
            dir=(dir-1)%4
        # 오른쪽으로 돌아서 이동
        elif arr[ci-1][cj+1]+arr[ci][cj+2]+arr[ci+1][cj+1]+arr[ci+2][cj+1]+arr[ci+1][cj+2] == 0:
            ci+=1
            cj+=1
            dir=(dir+1)%4
        else:
            break
    # 골렘이 구간에서 나온 경우
    if ci < 4:
        arr = [[1] + [0] * c + [1] for _ in range(r + 3)] + [[1] * (c + 2)]
        exit_set = set()
        num=2
    else:
        arr[ci+1][cj]=arr[ci-1][cj]=num
        arr[ci][cj-1:cj+2]=[num]*3
        num+=1

        exit_set.add((ci+di[dir], cj+dj[dir]))
        ans+=bfs(ci, cj)
print(ans)

