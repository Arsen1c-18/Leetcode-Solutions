from collections import deque

class Solution:
    def openLock(self, deadends, target):
        dead = set(deadends)
        if "0000" in dead:
            return -1
        
        queue = deque([("0000", 0)])
        visited = set("0000")
        
        while queue:
            node, steps = queue.popleft()
            
            if node == target:
                return steps
            
            for i in range(4):
                digit = int(node[i])
                
                for move in [-1, 1]:
                    new_digit = (digit + move) % 10
                    new_node = node[:i] + str(new_digit) + node[i+1:]
                    
                    if new_node not in dead and new_node not in visited:
                        visited.add(new_node)
                        queue.append((new_node, steps + 1))
        
        return -1