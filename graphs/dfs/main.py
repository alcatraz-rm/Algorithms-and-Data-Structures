import numpy as np
import scipy
from scipy.sparse import csgraph


def dfs(v, visited, matrix):
    visited.add(v)

    for u, is_adjacent in enumerate(matrix[v]):
        if is_adjacent and u not in visited:
            visited = dfs(u, visited, matrix)

    return visited


def connected_components(Q, matrix):
    result = []

    while Q:
        v = Q[0]
        component = dfs(v, set(), matrix)
        result.append(component)

        Q = [node for node in Q if node not in component]

    return result


n = int(input("nodes number: "))
matrix = np.array([np.array(list(map(int, input().split()))) for _ in range(n)])
result = connected_components(list(range(0, n)), matrix)

# scipy method just for checking
# print(csgraph.connected_components(matrix))

for component in result:
    print(component)
print('total components number:', len(result))
