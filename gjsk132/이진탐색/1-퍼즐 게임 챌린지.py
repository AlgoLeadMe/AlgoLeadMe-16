def solution(diffs, times, limit):
    # 특정 숙련도를 해결하는 시간이 제한 시간을 넘는지 확인
    def is_time_exceeded(level):
        
        total_time = times[0]
        
        for now_diff, time_cur, time_prev in zip(diffs[1:], times[1:], times[:-1]):
            
            if now_diff <= level:
                total_time += time_cur
            else:
                total_time += (now_diff-level)*(time_cur+time_prev) + time_cur
                
            if total_time > limit:
                return True
        
        return False
    
    # 숙련도에 대한 이진 탐색
    start, end = 1, max(diffs)
    
    while start <= end:
        
        mid = (start + end)//2
        
        if is_time_exceeded(mid): 
            start = mid+1
        else:
            end = mid-1
    
    return start