def solution(s):
    list_ = []
    
    if s[0] == ')':
        return False
    for parentheses in s:
        if parentheses == '(':
            list_.append(parentheses)
        else:
            if len(list_) == 0:
                return False
            list_.pop()
    if len(list_) == 0:
        return True
    else:
        return False