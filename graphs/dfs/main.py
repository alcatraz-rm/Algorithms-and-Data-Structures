from pprint import pprint

import numpy as np


def dfs(v, visited, matrix):
    if not visited:
        visited = set()

    visited.add(v)

    for u, is_adjacent in enumerate(matrix[v]):
        if is_adjacent and u not in visited:
            visited = dfs(u, visited, matrix)

    return visited


n = int(input("nodes: "))
matrix = np.array([np.array(list(map(int, input().split()))) for _ in range(n)])

# nodes = list(range(0, n))
not_visited = list(range(0, n))
result = 0

while not_visited:
    v = not_visited[0]
    component = dfs(v, set(), matrix)
    print(component)
    not_visited = [node for node in not_visited if node not in component]
    result += 1

print('total components number:', result)
