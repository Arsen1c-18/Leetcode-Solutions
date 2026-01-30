# 127. Word Ladder (Bidirectional BFS)
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        wordSet = set(wordList)
        if endWord not in wordSet:
            return 0

        beginSet = {beginWord}
        endSet = {endWord}
        visited = set()
        step = 1

        while beginSet and endSet:
            if len(beginSet) > len(endSet):
                beginSet, endSet = endSet, beginSet

            nextSet = set()
            for word in beginSet:
                for i in range(len(word)):
                    for c in "abcdefghijklmnopqrstuvwxyz":
                        newWord = word[:i] + c + word[i+1:]
                        if newWord in endSet:
                            return step + 1
                        if newWord in wordSet and newWord not in visited:
                            visited.add(newWord)
                            nextSet.add(newWord)

            beginSet = nextSet
            step += 1

        return 0
  