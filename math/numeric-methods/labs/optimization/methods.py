import random
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import linprog

def lineEqCoef(xy : list[list[float]]) -> list[float]:
    xa, ya = xy[0]
    xb, yb = xy[1]
    # Canonical equation
    '''
        (x-xa)/(xb-xa) = (y-ya)/(yb-ya)
        x/(xb-xa) - xa/(xb-xa) = y/(yb-ya) - ya/(yb-ya)
        y = x*(yb-ya)/(xb-xa) + (yb-ya)*(- xa/(xb-xa) + ya/(yb-ya))
        y = x*a + b
    '''
    # then coefficients is
    a = (yb-ya)/(xb-xa)
    b = (yb-ya)*(- xa/(xb-xa) + ya/(yb-ya))
    return [a, b]

def Crossing(ab1, ab2):
    A = np.array([[-ab1[0], 1], [-ab2[0], 1]])
    B = np.array([ab1[1], ab2[1]])
    return np.linalg.solve(A, B)

def searchHighestPoint(points : dict):
    dotX = 0
    dotY = 0
    for i in points.keys():
        if dotY <= points[i][1]:
            dotY = points[i][1]
            dotX = points[i][0] 
    return [dotX, dotY]

def lineParallelTransfer(transferLine : list[list[float]], point_where_transfer : list[float]) -> list[float]:
        # Canonical equation
    '''
        dx, dy - translation offset
        ((x+dx)-xa)/(xb-xa) = ((y-dy)-ya)/(yb-ya)
        (x+dx)/(xb-xa) - xa/(xb-xa) = (y-dy)/(yb-ya) - ya/(yb-ya)
        y = (x+dx)*(yb-ya)/(xb-xa) + (yb-ya)*(- xa/(xb-xa) + ya/(yb-ya)) - dy
        y = x*(yb-ya)/(xb-xa) + dx*(yb-ya)/(xb-xa) + (yb-ya)*(- xa/(xb-xa) + ya/(yb-ya)) - dy
    '''
    xa, ya = transferLine[0]
    xb, yb = transferLine[1]

    a, b = lineEqCoef(transferLine)
    
    dx = 0
    dy = 0

    x = np.linspace(0, 1000, 10000).round(1)
    y = []
    for i in x:
        y.append(a*i+b)
        if y[-1] == point_where_transfer[1]:
            print(False, False)
            dx = abs(point_where_transfer[0]-i)
        if i == point_where_transfer[0]:
            print(True, True)
            dy = abs(point_where_transfer[1]-y[-1])

    A = (yb-ya)/(xb-xa)
    B = dx*(yb-ya)/(xb-xa) + (yb-ya)*(- xa/(xb-xa) + ya/(yb-ya)) - dy
    print(a, b, A, B, dx, dy)
    return [A, B]

def graphOptimize(df : pd.DataFrame, pltLimits):
    # expect dataframe with n columns of dots
    n = len(df.columns)
    # [[x1, y1], [x2, y2]]
    lines = [df[i] for i in df.columns]
    ab = [lineEqCoef(i) for i in lines]

    print(ab)

    a = [i[0] for i in ab]
    b = [i[1] for i in ab]
    

    fig, (ax) = plt.subplots()

    x = np.linspace(pltLimits[0][0], pltLimits[0][1], 1000).round(4)
    y : list[list[float]] = []

    ax.set_xlim(pltLimits[0])
    ax.set_ylim(pltLimits[1])
    
    colors = ["#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)]) for i in range(n-1)]

    for j in range(n-1):
        y.append([a[j]*i+b[j] for i in x])
        ax.plot(x, y[j], color=colors[j], linewidth=1, label=str(j+1)+' line')
        ax.stackplot(x, y[j], color=colors[j], alpha = 0.18)

    y.append([a[n-1]*i+b[n-1] for i in x])
    ax.plot(x, y[n-1], '--', linewidth=1.2, color='black', label='Level line')

    cross_points = {}
    k = 1
    for i in range(n-1):
        for j in range(i, n-1):
            if j == i : continue
            cross_points[str(i+1)+' : '+str(j+1)] = Crossing([a[i], b[i]], [a[j], b[j]])
            ax.scatter(cross_points[str(i+1)+' : '+str(j+1)][0], cross_points[str(i+1)+' : '+str(j+1)][1], linewidth=0.7, marker='o', color='black')
        k+=1    
    print(cross_points)
    highest_cross_point = searchHighestPoint(cross_points)
    print(highest_cross_point)
    newLevelLineCoef = lineParallelTransfer(df['levelline'], [466.66, 66.66])

    ax.scatter(highest_cross_point[0], highest_cross_point[1], marker='o', linewidth=0.9, color='red')

    ax.plot(x, [newLevelLineCoef[0]*i + newLevelLineCoef[1] for i in x], '--', linewidth=1.2, color='red', label='New level line')

    plt.grid()
    plt.legend(loc='upper right')
    plt.show()
