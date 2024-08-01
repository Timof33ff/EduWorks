import numpy as np
import pandas as pd
import tabulate as tab
import scipy.integrate 
import matplotlib.pyplot as plt


def Eiler(function, f0, start, end, n):
    U : list[float] = [f0]
    X : list[float] = [start]

    step = (end-start)/n

    for i in range(0, n):
        
        if X[i] == end: break
        
        U.append(U[i] + step*function(X[i], U[i]))
        X.append(X[i] + step)

    return [X, U]

def embeddedEiler(function, f0, start, end, n):
    U : list[float] = [f0]
    X : list[float] = [start]

    step = (end-start)/n

    for i in range(0, n):
        
        if X[i] == end: break
        
        U.append(U[i] + 0.5*step*(function(X[i], U[i]) + function(X[i]+step, U[i] + step*function(X[i], U[i]))))  #, U[i]))
        X.append(X[i] + step)

    return [X, U]

def RungeKutta(function, f0, start, end, n):
    U : list[float] = [f0]
    X : list[float] = [start]

    step = (end-start)/n

    for i in range(0, n):
        
        if X[i] == end: break
        
        k1 = function(X[i], U[i])
        k2 = function(X[i]+step*0.5, U[i]+step*0.5*k1)
        k3 = function(X[i]+step*0.5, U[i]+step*0.5*k2)
        k4 = function(X[i]+step, U[i]+step*k3)

        U.append(U[i] + (step/6)*(k1+2*k2+2*k3+k4))
        X.append(X[i] + step)

    return [X, U]

def showMerge(function, f0, start, end, n, methods):
    solutions = [{}, {}]
    y : list[float] = []
    delta = [{}, {}]
    sigma = [{}, {}]
    
    for k in range(2):
        for i in methods.keys():
            y = methods[i](function, f0, start, end, n)[1]
            solutions[k][i] = y
        n*=2

    for k in range(2):
        for i in methods.keys():
            delta[k][i] = round(abs(solutions[k][i][-1] - solutions[k]['RK4'][-1]), 4)
            sigma[k][i] = str(round(100*delta[k][i] / abs(solutions[k][i][-1]), 4)) + '%'

            if delta[k][i] == 0 or sigma[k][i] == 0:
                delta[k][i] = '#--#'
                sigma[k][i] = '#--#'
    
    print("#-----------Оценка погрешности численного решения------------\n-----------обыкновенного дифференциального уравнения----------#")
    print(tab.tabulate(pd.DataFrame({
            "": [i for i in methods.keys()],
            "Y¹⁰n": [solutions[0][i][-1] for i in methods.keys()],
            "Δ(Y¹⁰n)": [delta[0][i] for i in methods.keys()],
            "δ(Y¹⁰n)": [sigma[0][i] for i in methods.keys()],
            "Y²⁰n": [solutions[1][i][-1] for i in methods.keys()],
            "Δ(Y²⁰n)": [delta[1][i] for i in methods.keys()],
            "δ(Y²⁰n)": [sigma[1][i] for i in methods.keys()]
                        }), tablefmt='pipe', headers='keys', showindex=False))

def f(x : float, y : float) -> float:  
    return x**2 + y**2

a = 0; b = 1; n = 10; eps = 0.001; y0 = -1

def f12(x : float, y : float) -> float:  
    return 0.5*x**(-2) - 2*y**2

a12 = 1; b12 = 2; y012 = 1

methods = {'Eiler': Eiler, 'Embedded Eiler' : embeddedEiler, 'RK4': RungeKutta}
