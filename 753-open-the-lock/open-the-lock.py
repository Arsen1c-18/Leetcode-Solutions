import heapq

class Solution:
    def openLock(self, deadends, target):
        dead = set(deadends)
        if "0000" in dead:
            return -1
        
        def heuristic(state):
            h = 0
            for i in range(4):
                diff = abs(int(state[i]) - int(target[i]))
                h += min(diff, 10 - diff)
            return h
        
        heap = [(heuristic("0000"), 0, "0000")]
        visited = set()
        
        while heap:
            f, g, state = heapq.heappop(heap)
            
            if state in visited:
                continue
            visited.add(state)
            
            if state == target:
                return g
            
            for i in range(4):
                digit = int(state[i])
                
                for move in [-1, 1]:
                    new_digit = (digit + move) % 10
                    new_state = state[:i] + str(new_digit) + state[i+1:]
                    
                    if new_state not in dead and new_state not in visited:
                        new_g = g + 1
                        new_f = new_g + heuristic(new_state)
                        heapq.heappush(heap, (new_f, new_g, new_state))
        
        return -1