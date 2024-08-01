import numpy as np
import pandas as pd
from scipy.linalg import solve
import matplotlib.pyplot as plt
import tabulate 

def mul(list): # поэлементное умножение векторов (П(i=0, n)(Ai))
    result = 1
    for i in list:
        result *= i
    return result

def Lagrange(y, x, dot):
    result = 0
    lst = []
    for i in range(0, len(y)):
            lst = x[0:i]+x[i+1::1]
            result += y[i] * mul([dot - j for j in lst]) / mul([x[i] - j for j in lst])   
    
    return result

def drawLagrange(y, x, dots): 
    lag = np.array([Lagrange(y, x, i) for i in dots])
    
    plt.scatter(x, y, marker='o', color="green", s = 50)
    plt.scatter(dots, lag, marker='s', color="red", s = 50)
    plt.legend((f"X:{x[:3]}\nY:{y[:3]}", f"L:{lag[:3].round(2)}"))
    plt.title("LB7 Lagrange")
    plt.grid(True)
    plt.show()


def linearSystem(x, y):
    leftMatrix = np.matrix([
        [len(x), sum(x)],
        [sum(x), sum([i**2 for i in x])]
    ])
    rightMatrix = np.matrix([
        [sum(y)],
        [sum([x[i]*y[i] for i in range(0, len(x))])]
    ])

    return solve(leftMatrix, rightMatrix).reshape((2,))

def quadricSystem(x, y):
    leftMatrix = np.matrix([
        [len(x), sum(x), sum([i**2 for i in x])],
        [sum(x), sum([i**2 for i in x]), sum([i**3 for i in x])],
        [sum([i**2 for i in x]), sum([i**3 for i in x]), sum([i**4 for i in x])]
    ])
    rightMatrix = np.matrix([
        [sum(y)],
        [sum([x[i]*y[i] for i in range(0, len(x))])],
        [sum([(x[i]**2)*y[i] for i in range(0, len(x))])]
    ])

    return solve(leftMatrix, rightMatrix).reshape((3,))

def MMQ(x, y, type): 
    match type:
        case 'lin': 
            coef = linearSystem(x, y)
            return coef
        case 'quad': 
            coef = quadricSystem(x, y)
            return coef
        case _: 
            coef = linearSystem(x, y)
            return coef
    
def drawMMQ(x, y, type):
    coef = MMQ(x, y, type)
    match type:
        case 'lin': res = [coef[0]+coef[1]*i for i in x]
        case 'quad': res = [coef[0]+coef[1]*i+coef[2]*i**2 for i in x]
        case _: res = [coef[0]+coef[1]*i for i in x]
    
    dt = pd.DataFrame({
        "Xi": x, "Yi": y,
        f"МНК {type}":res,
        "Расхождение": [abs(y[i]-res[i]) for i in range(0, len(y))]})

    print(tabulate.tabulate(dt,headers='keys', tablefmt='psql', showindex=False))

    plt.scatter(x, y, marker='o', color='red')
    plt.plot(x, res, color='green')
    plt.scatter(x, res, color='green', marker='s')
    plt.title(f"LB7 МНК ({type})")
    plt.legend(("Заданно", "МНК", "МНК"))
    plt.show()