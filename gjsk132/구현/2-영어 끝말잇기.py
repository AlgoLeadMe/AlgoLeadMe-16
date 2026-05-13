from collections import defaultdict

def solution(n, words):
    
    word_check = defaultdict(bool)
    word_check[words[0]] = True
    
    for idx, w in enumerate(words[1:], 1):
        if word_check[w] or not w[0] == words[idx-1][-1]:
            return [idx%n + 1, idx//n + 1]
        else:
            word_check[w] = True
        
    return [0, 0]