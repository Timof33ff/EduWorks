import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
np.seterr(divide='ignore', invalid='ignore')

def le(x): # get last element
    return x[len(x)-1]

def dfdx(function, x, epsilon):
    return 0.5*(function(x + epsilon)-function(x - epsilon))/epsilon

def d2fdx2(function, x, epsilon):
    return (function(x-epsilon)-2*function(x)+function(x+epsilon))/epsilon**2

def Newton(function, start, epsilon):
    currentX: list[float] = [start]
    newX: list[float] = []; epsControl: list[float] = []; zeroControl: list[float] = []
    iter: list[int] = []
    i = 0
    
    while True:
        
        i+=1                                    # f(x) / df(x)dx
        newX.append(currentX[len(currentX)-1] - function(currentX[len(currentX)-1])/dfdx(function, currentX[len(currentX)-1], epsilon))
        zeroControl.append(function(newX[len(newX)-1]))
        iter.append(i)

        if abs(newX[len(newX)-1] - currentX[len(currentX)-1]) < epsilon:
            epsControl.append(f"Root={newX[len(newX)-1]}")
            break
        epsControl.append(abs(currentX[len(currentX)-1] - newX[len(newX)-1]))
        currentX.append(newX[len(newX)-1])

    return pd.DataFrame({
        "Xn": currentX,
        "Xn+1": newX,
        "Оценка погрешности": epsControl,
        "Контроль нуля Y(Xn+1)": zeroControl,
        "Число итераций": iter
    })

def chordsTangents(function, a0, b0, epsilon):
    a : list[float] = [a0]; b : list[float] = [b0]
    fa : list[float] = [function(a0)]; fb : list[float] = [function(b0)]
    dfda : list[float] = [dfdx(function, a0, epsilon)]; dfdb : list[float] = [dfdx(function, b0, epsilon)]
    epsControl : list[float] = [abs(le(b)-le(a))]; left : bool = True

    if le(fa)*le(fb)>0.0:
        print(f"#--No roots--\nfa = {fa};\nfb = {fb};------------#")
        return None
    elif le(fa)*le(fb)==0.0:
        print("#--fa*fb==0.0--")
        
    while True:
            
        if le(fa)*d2fdx2(function, le(a), epsilon) > 0.0:
            # tangents - left, chords - right
            a.append(le(a)-le(fa)/le(dfda))
            b.append((le(a)*le(fb)-le(b)*le(fa))/(le(fb)-le(fa)))

            fa.append(function(le(a)))
            dfda.append(dfdx(function, le(a), epsilon))
            fb.append(function(le(b)))
            dfdb.append(dfdx(function, le(b), epsilon))

            left = True
        
        elif le(fb)*d2fdx2(function, le(b), epsilon) > 0.0:
            # tangents - right, chords - left
            b.append(le(b)-le(fb)/le(dfdb))
            a.append((le(a)*le(fb)-le(b)*le(fa))/(le(fb)-le(fa)))

            fa.append(function(le(a)))
            dfda.append(dfdx(function, le(a), epsilon))
            fb.append(function(le(b)))
            dfdb.append(dfdx(function, le(b), epsilon))
            
            left = False

        if abs(le(b)-le(a))<epsilon:
            epsControl.append(f'Корень = {(le(b)+le(a))/2}')
            break
        epsControl.append(abs(le(b)-le(a)))         
    
    if left:
        return pd.DataFrame({
            "a":a, "b": b,
            "f(a)": fa, "f(b)":fb,
            "df(a)dx": dfda,
            "Оценка погрешности": epsControl
        })
    else:
        return pd.DataFrame({
            "a":a, "b": b,
            "f(a)": fa, "f(b)":fb,
            "df(b)dx": dfdb,
            "Оценка погрешности": epsControl
        })
