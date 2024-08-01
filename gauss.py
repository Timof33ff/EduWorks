from matrix import *


def bubble_max_row(m, col):
    """Replace m[col] row with the one of the underlying rows with the modulo greatest first element.
    :param m: matrix (list of lists)
    :param col: index of the column/row from which underlying search will be launched
    :return: None. Function changes the matrix structure.
    """
    max_element = m[col][col]
    max_row = col
    for i in range(col + 1, len(m)):
        if abs(m[i][col]) > abs(max_element):
            max_element = m[i][col]
            max_row = i
    if max_row != col:
        m[col], m[max_row] = m[max_row], m[col]


def solve_gauss(m):
    """Solve linear equations system with gaussian method.
    :param m: matrix (list of lists)
    :return: None
    """
    n = len(m)
    # forward trace
    for k in range(n - 1):
        bubble_max_row(m, k)
        for i in range(k + 1, n):
            div = m[i][k] / m[k][k]
            m[i][-1] -= div * m[k][-1]
            for j in range(k, n):
                m[i][j] -= div * m[k][j]

    # check modified system for nonsingularity
    if is_singular(m):
        print('The system has infinite number of answers...')
        return

    # backward trace
    x = [0 for i in range(n)]
    for k in range(n - 1, -1, -1):
        x[k] = (m[k][-1] - sum([m[k][j] * x[j] for j in range(k + 1, n)])) / m[k][k]

    # Display results
    display_results(x)


def is_singular(m):
    """Check matrix for nonsingularity.
    :param m: matrix (list of lists)
    :return: True if system is nonsingular
    """
    for i in range(len(m)):
        if not m[i][i]:
            return True
    return False

m = read_matrix('matrix10x10.txt')
solve_gauss(m)