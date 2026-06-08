def add_time(time, add):
    time += add
    
    if mim:=time%100 > 59:
        time += 40
        
    return time


def solution(schedules, timelogs, startday):
    answer = 0
    employee_cnt = len(schedules)
    deadline = [add_time(s, 10) for s in schedules]
    is_late = [False for _ in range(len(schedules))]
    
    for day in range(7):
        
        is_weekend = (startday+day-1)%7 > 4
        
        if is_weekend:
            continue
            
        for employee_idx, limit in enumerate(deadline):
            if timelogs[employee_idx][day] > limit:
                is_late[employee_idx] = True
    
    return employee_cnt - sum(is_late)