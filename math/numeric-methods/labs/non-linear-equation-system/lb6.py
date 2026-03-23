from methods import *

'''
Input data must be set as like:
{[
    [ a11, a12, a13, b1],
    [ a21, a22, a23, b2],
    [ a31, a32, a33, b3]
]}
Including exceptions:
    |a11| >= |a12 + a13| &&
    |a22| >= |a21 + a23| &&
    |a33| >= |a31 + a32|  
aij != 0
'''

matrix = np.matrix([
    [0.63, 0.05, 0.15, 0.34],
    [0.05, 0.34, 0.10, 0.32],
    [0.15, 0.10, 0.70, 0.72]
])

'''print(matrix)

solutionSIM = SimpleIterationMethod(matrix)
print(tab.tabulate(solutionSIM, headers=solutionSIM.keys(), tablefmt="grid", stralign='center', floatfmt=".4f" ))

solutionZeidel = ZeidelMethod(matrix)

print(tab.tabulate(solutionZeidel, headers=solutionZeidel.keys(), tablefmt="grid", stralign='center', floatfmt=".4f" ))'''

matrix12 = np.matrix([
    [45.00, -3.50, 7.400, 25.00],
    [3.100, -6.00, -2.30, -15.0],
    [0.800, 7.400, -5.00, 64.00]
])
'''
print(matrix12)

solutionSIM12 = SimpleIterationMethod(matrix12)

print(tab.tabulate(solutionSIM12, headers=solutionSIM12.keys(), tablefmt="pipe", stralign='center', floatfmt=".4f" ))

solutionZeidel12 = ZeidelMethod(matrix12)

print(tab.tabulate(solutionZeidel12, headers=solutionZeidel12.keys(), tablefmt="pipe", stralign='center', floatfmt=".4f" ))'''

print(invertMatrixMethod(matrix))

print(invertMatrixMethod(matrix12))