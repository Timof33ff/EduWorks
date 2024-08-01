import numpy as np
import pandas as pd

def f(x):
    return x**2 - np.sqrt(x+4)

def f1(x):
    return x**3 + 3*x**2 -1

def dfdx(function, x, epsilon):
    return 0.5*(function(x + epsilon)-function(x - epsilon))/epsilon

def d2fdx2(function, x, epsilon):
    return (function(x-epsilon)-2*function(x)+function(x+epsilon))/epsilon**2

def iterationsMethod(function, start, end, epsilon=0.001):
    if function(start)*function(end) > 0: 
        print(f"Error: No root on {[start, end]}")
        return None

    x0 = (start+end)/2  # X0
    current = [x0]      # Xn
    dfadx = dfdx(function, start, epsilon)  # df(a) / dx
    dfbdx = dfdx(function, end, epsilon)    # df(b) / dx

    # C = +- 1/ max[a,b]{abs|f(x)|} = +- 1/ max{abs[|f(a)|, |f(b)|]}
    # вернёт С противоположное по знаку 1/f'(x),
    # где X - либо start, если |f'(start)| > |f'(end)|,
    #         либо end, если |f'(end)| > |f'(start)|
    max = np.max([abs(dfadx), abs(dfbdx)])
    if dfadx > 0 or dfbdx > 0 : c = 1 / - max
    else: c = - 1 / - max       
    print(f"C = {c}")

    new = [x0 + c * function(x0)]    # Xn+1
    f = [function(new[len(new)-1])]  # F(Xn+1)
    epsControl = [new[len(new)-1] - current[len(current)-1]] # оценка погрешности
    it = 1  # номер итерации
    # цикл итераций
    while abs((new[len(new)-1] - current[len(current)-1])) > epsilon:
        if  new[len(new)-1] > end:
            print("No root")
            return pd.DataFrame({
        "Xn": current, "Xn+1": new,
        "Оценка погрешности": epsControl, " Контроль нуля Y(Xn+1)": f,
        "№": [i for i in range(1, it+1)]
    })
        current.append(new[len(new)-1])
        new.append(current[len(current)-1] + c * function(current[len(current)-1]))
        f.append(function(new[len(new)-1]))
        epsControl.append(abs(new[len(new)-1] - current[len(current)-1]))
        it+=1
    epsControl.pop()
    epsControl.append(f"Корень = {round(new[len(new)-1], 4)}")
    
    return pd.DataFrame({
        "Xn": current, "Xn+1": new,
        "Оценка погрешности": epsControl, " Контроль нуля Y(Xn+1)": f,
        "№": [i for i in range(1, it+1)]
    })
    