import numpy as np
import pandas as pd
import tabulate as tab

# numpy | matrix
#   cs.mipt.ru/advanced_python/lessons/lab16.html#numpy-1
#   https://physics.susu.ru/vorontsov/language/numpy.html

'''
Input data must be set as matrix:
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

def SimpleIterationMethod(system : np.matrix[float], epsilon = 0.001):
    delta = np.matrix([[None], [None], [None]])
    x = np.matrix([[0.0], [0.0], [0.0]])
    max = [None]
    comment = ["(˘･_･˘)"]
    i : int = 0 # current X collunm

    while True:
        newRow = np.matrix([
            [system[0, 1] * x[1, i] + system[0, 2] * x[2, i]],
            [system[1, 0] * x[0, i] + system[1, 2] * x[2, i]],
            [system[2, 0] * x[0, i] + system[2, 1] * x[1, i]]
                           ]) 
               
        newRow = np.divide(np.subtract(system[:3, 3:], newRow),
                            np.vstack(( system[0, 0],
                                        system[1, 1],
                                        system[2, 2]))) 
        x = np.hstack((x, newRow))

        i+=1
        delta = np.hstack((delta, abs(np.subtract(x[:3, i], x[:3, i-1]))))
        max.append(np.max(delta[:3, i:i+1]))

        if  max[len(max)-1] < epsilon:
            comment.append("(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧")
            break
        comment.append("(˘･_･˘)")

    return  pd.DataFrame({
        "X1" : list(x[:1].round(4).flat), "X2" : list(x[1:2].round(4).flat), "X3" : list(x[2:3].round(4).flat),
        "Δ1" : list(delta[:1].flat), "Δ2" : list(delta[1:2].flat), "Δ3" : list(delta[2:3].flat),
        "Maximum" : max,
        "Comment" : comment })


def ZeidelMethod(system : np.matrix[float], epsilon = 0.001):
    delta1 = [None]; delta2 = [None]; delta3 = [None]
    x1 = [0.0];      x2 = [0.0];      x3 = [0.0]
    max = [None]
    comment = ["(˘･_･˘)"]
    i : int = 0 # current Xi collunm

    while True:

        x1.append((system[0, 3] - (system[0, 1] * x2[i] + system[0, 2] * x3[i])) / system[0, 0])
        x2.append((system[1, 3] - (system[1, 0] * x1[i+1] + system[1, 2] * x3[i])) / system[1, 1])  
        x3.append((system[2, 3] - (system[2, 0] * x1[i+1] + system[2, 1] * x2[i+1])) / system[2, 2])

        i+=1

        delta1.append(abs(x1[i] - x1[i-1]))
        delta2.append(abs(x2[i] - x2[i-1]))
        delta3.append(abs(x3[i] - x3[i-1]))

        max.append(np.max([delta1[i], delta2[i], delta3[i]]))

        if  max[len(max)-1] < epsilon:
            comment.append("(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧")
            break
        comment.append("(˘･_･˘)")

    return  pd.DataFrame({
        "X1" : x1, "X2" : x2, "X3" : x3,
        "Δ1" : delta1, "Δ2" : delta2, "Δ3" : delta3,
        "Maximum" : max,
        "Comment" : comment })

def invertMatrixMethod(system):
    #находим обратную матрицу среза по первым трем столбцам системы(Aij)
    # и умножаем на последний столбец (B)
    return np.linalg.inv(system[:3, :3])*system[:3, 3:4]