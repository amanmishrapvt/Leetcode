from collections import defaultdict, deque

class Solution:
    def shortestAlternatingPaths(self, n: int, redEdges: List[List[int]], blueEdges: List[List[int]]) -> List[int]:
        red_edges  = defaultdict(list)
        blue_edges = defaultdict(list)

        for u, v in redEdges:
            red_edges[u].append(v)
        for u, v in blueEdges:
            blue_edges[u].append(v)
        
        res = [-1] * n
        res[0] = 0

        queue = deque([(0, 0), (0, 1)])
        visited = set([(0, 0), (0, 1)])

        dist = 0
        while queue:
            for _ in range(len(queue)):
                node, color = queue.popleft()

                if res[node] == -1:
                    res[node] = dist
                elif dist < res[node]:
                    res[node] = dist
                if color == 0:
                    for neighbour in blue_edges[node]:
                        if (neighbour, 1) not in visited:
                            visited.add((neighbour, 1))
                            queue.append((neighbour, 1))
                else:
                    for neighbour in red_edges[node]:
                        if (neighbour, 0) not in visited:
                            visited.add((neighbour, 0))
                            queue.append((neighbour, 0))
            dist += 1
        return res
                