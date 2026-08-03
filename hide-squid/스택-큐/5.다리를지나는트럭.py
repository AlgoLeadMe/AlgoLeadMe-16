from collections import deque

def solution(bridge_length, weight, truck_weights):
    cnt = 0
    weight_ = 0
    
    bridge = deque([0] * bridge_length) # 0,0
    truck = deque(truck_weights) # 7,4,5,6
    
    while bridge: # 2
        cnt += 1
        weight_ -= bridge.popleft()
        if truck:
            if weight_ + truck[0] <= weight:
                    t = truck.popleft()
                    bridge.append(t)
                    weight_ += t
            else:
                bridge.append(0)
                
    return cnt