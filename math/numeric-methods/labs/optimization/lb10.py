from methods import *

# Графический метод решения задачи оптимизации
'''
DF = pd.DataFrame({
    '1line' : [[25, 0], [0, 75]],
    '2line' : [[30, 0], [0, 30]],
    '3line' : [[84, 0], [0, 21]],
    'levelline' : [[40, 0], [0, 30]]
})

graphOptimize(DF, [[-1, 90], [0, 40]])
'''

DF = pd.DataFrame({
    '1line' : [[500, 0], [0, 1000]],
    '2line' : [[0, 360], [900, 0]],
    '3line' : [[0, 562.5], [562.5/1.065, 0]],
    'levelline' : [[10, 0], [0, 16]]
})

graphOptimize(DF, [[-1, 1000], [0, 1000]])


# Библиотечный метод 
'''
F_coefficients = [-30, -40]

left_eq = [[12, 4],
           [4, 4],
           [3, 12]]

right_eq = [300, 120, 252]

limits = [(0.0, float('inf')),
          (0.0, float('inf'))]

solution = linprog(c=F_coefficients, A_ub=left_eq, b_ub=right_eq, bounds=limits, method='highs')

print(solution)
print(-solution.fun)
print(solution.x)
'''

# Var12 : 
#  c1   c2  a11  a12  a21  a22   a31  a32   b1   b2   b3 
# 160, 100, 0.2, 0.1, 0.2, 0.5, 0.17, 0.16, 100, 180, 90

F_coefficients = [-160, -100]

left_eq = [[0.2, 0.1],
           [0.2, 0.5],
           [0.17, 0.16]]

right_eq = [100, 180, 90]

limits = [(0.0, float('inf')),
          (0.0, float('inf'))]

solution = linprog(c=F_coefficients, A_ub=left_eq, b_ub=right_eq, bounds=limits, method='highs')

print(solution)
print(-solution.fun)
print(solution.x)
