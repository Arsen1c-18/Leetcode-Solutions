from collections import Counter

class Solution:
    def leastInterval(self, tasks, n):
        freq = Counter(tasks)
        maxFreq = max(freq.values())          # highest frequency
        countMaxFreq = list(freq.values()).count(maxFreq)

        # slots created by most frequent task
        result = (maxFreq - 1) * (n + 1) + countMaxFreq
        
        return max(result, len(tasks))
