from collections import defaultdict, deque

def solution(n, edge):
    
    graph = [[] for _ in range(n+1)]

    for n1, n2 in edge:
        graph[n1].append(n2)
        graph[n2].append(n1)

    dist = [0 for _ in range(n+1)]
    dist[1] = 1
    
    tmp = deque([(1, 1)])
    
    while tmp:
        now_dist, now_node = tmp.popleft()
        
        for next_node in graph[now_node]:
            if dist[next_node] != 0:
                continue
            
            dist[next_node] = now_dist+1
            tmp.append((now_dist+1, next_node))
    
    return dist.count(max(dist))