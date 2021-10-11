import numpy as np


def dfs(v, visited, matrix):
    visited.add(v)

    for u, is_adjacent in enumerate(matrix[v]):
        if is_adjacent and u not in visited:
            visited = dfs(u, visited, matrix)

    return visited


def factorize(Q, matrix):
    result = []

    while Q:
        v = Q[0]
        component = dfs(v, set(), matrix)
        result.append(component)

        Q = [node for node in Q if node not in component]

    return result

n = int(input("nodes: "))
matrix = np.array([np.array(list(map(int, input().split()))) for _ in range(n)])
result = factorize(list(range(0, n)), matrix)

for component in result:
    print(component)

print('total components number:', len(result))
