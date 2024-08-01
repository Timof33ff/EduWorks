import numpy as np
import pandas as pd
import tabulate as tab
import scipy.integrate 
import matplotlib.pyplot as plt

def f(x):
    return np.sin(x)#return round(1 / np.sqrt(x**4+5), 5)

def variantF(x):
    return round(np.exp(-x) / np.sqrt(0.2*x**2 + 1), 5)

a = 1; b = 4; n = 10; eps = 0.001

def rectanglesLeft(function, start, end, n):
    step = abs(end-start)/n
    return step*sum([function(start + step*i) for i in range(0, int(abs(end-start)/step))])

def rectanglesRight(function, start, end, n):
    step = abs(end-start)/n
    return step*sum([function(end - step*i) for i in range(0, int(abs(end-start)/step))])

def rectanglesCenter(function, start, end, n):
    step = abs(end-start)/n
    return step*sum([(function(start + (i-1)*step) + function(start + i*step))/2 for i in range(1, int(abs(end-start)/step)+1)])

def Accuracy( method, function, start, end, n, epsilon):
    In = method(function, start, end, n)
    I2n = method(function, start, end, 2*n)
    if(abs(In-I2n)<=epsilon): return n, In
    else: return Accuracy( method, function, start, end, 2*n, epsilon)

'''nLeft, resultLeft = Accuracy(rectanglesLeft, f, a, b, n, eps)
nCenter, resultCenter = Accuracy(rectanglesCenter, f, a, b, n, eps)
nRight, resultRight = Accuracy(rectanglesRight, f, a, b, n, eps)

print(f"#----------------------------- TASK[1&2] Rectangle formulas -----------------------------#")
print(f"#------------f(x) = 1 / sqrt(x^4+5); | a = {a}; b = {b}; n = {n}; ε = {eps}; -----------#")
print(tab.tabulate(pd.DataFrame({
    "": ["Rects amount", "Result"],
    "Left" : [nLeft, resultLeft],
    "Center" : [nCenter, resultCenter],
    "Right" : [nRight, resultRight]
}), tablefmt='pipe', headers='keys', showindex=False))'''


X = np.linspace(a, b,n)
Y = [f(x) for x in X]
plt.plot(X, Y, color = 'black')
plt.fill_between(X, Y, 0, color='r', alpha = 0.5)
plt.grid(True)
plt.show()

def trapeze(function, start, end, n):
    step = abs(end-start)/n
    Y = [function(start+i*step) for i in range(0, n+1)]
    return step*(sum(Y[1:len(Y)-1:1]) + 0.5*(Y[0]+Y[len(Y)-1]))

'''print(f"#------------------------- TASK[3] Trapeze formula -----------------------------#")
print(f"#------------f(x) = 1 / sqrt(x^4+5); | a = {a}; b = {b}; n = {n}; ------------#")
print(f"#-- Result : {trapeze(f, a, b, n)}")

print(f"#------------f(x) = 1 / sqrt(x^4+5); | a = {a}; b = {b}; n = {2*n}; ------------#")
print(f"#-- Result : {trapeze(f, a, b, 2*n)}")

print(f"#------------------------- TASK[4] Trapeze formula -----------------------------#")
print(f"#------------f(x) = exp(-x) / sqrt(0.2*x^2+1); | a = {1.3}; b = {2.5}; n = {n}; ------------#")
print(f"#-- Result : {trapeze(variantF, 1.3, 2.5, n)}")
print(f"#------------f(x) = exp(-x) / sqrt(0.2*x^2+1); | a = {1.3}; b = {2.5}; n = {2*n}; ------------#")
print(f"#-- Result : {trapeze(variantF, 1.3, 2.5, 2*n)}")'''

def simpson(function, start, end, n):
    step = abs(end-start)/n
    Y = [function(start+i*step) for i in range(0, n+1)]
    return (step/3)*(Y[0] + Y[len(Y)-1] + 2*sum(Y[2:len(Y)-1:2]) + 4*sum(Y[1:len(Y)-1:2]))
'''
print(f"#------------------------- TASK[5] Simpson formula -----------------------------#")
print(f"#------------f(x) = 1 / sqrt(x^4+5); | a = {a}; b = {b}; n = {n}; ------------#")
print(f"#-- Result : {simpson(f, a, b, n)}")

print(f"#------------f(x) = 1 / sqrt(x^4+5); | a = {a}; b = {b}; n = {2*n}; ------------#")
print(f"#-- Result : {simpson(f, a, b, 2*n)}")

print(f"#------------------------- TASK[6] Simpson formula -----------------------------#")
print(f"#------------f(x) = exp(-x) / sqrt(0.2*x^2+1); | a = {1.3}; b = {2.5}; n = {n}; ------------#")
print(f"#-- Result : {simpson(variantF, 1.3, 2.5, n)}")
print(f"#------------f(x) = exp(-x) / sqrt(0.2*x^2+1); | a = {1.3}; b = {2.5}; n = {2*n}; ------------#")
print(f"#-- Result : {simpson(variantF, 1.3, 2.5, 2*n)}")
'''
print(f"#------------------------- TASK[7] Accurasy table -----------------------------#")
print(f"#------------f(x) = 1 / sqrt(x^4+5); | a = {a}; b = {b}; n = {n}; ------------#")


leftRectFormula10 = rectanglesLeft(f, a, b, n)
rightRectFormula10 = rectanglesRight(f, a, b, n)
centerRectFormula10 = rectanglesCenter(f, a, b, n)
trapezeFormula10 = trapeze(f, a, b, n)
simpsonFormula10 = simpson(f, a, b, n)

leftRectFormula20 = rectanglesLeft(f, a, b, 2*n)
rightRectFormula20 = rectanglesRight(f, a, b, 2*n)
centerRectFormula20 = rectanglesCenter(f, a, b, 2*n)
trapezeFormula20 = trapeze(f, a, b, 2*n)
simpsonFormula20 = simpson(f, a, b, 2*n)

delta_leftRectFormula10 = abs(leftRectFormula10-simpsonFormula20)
delta_rightRectFormula10 = abs(rightRectFormula10-simpsonFormula20)
delta_centerRectFormula10 = abs(centerRectFormula10-simpsonFormula20)
delta_trapezeFormula10 = abs(trapezeFormula10-simpsonFormula20)
delta_simpsonFormula10 = abs(simpsonFormula10-simpsonFormula20)

delta_leftRectFormula20 = abs(leftRectFormula20-simpsonFormula20)
delta_rightRectFormula20 = abs(rightRectFormula20-simpsonFormula20)
delta_centerRectFormula20 = abs(centerRectFormula20-simpsonFormula20)
delta_trapezeFormula20 = abs(trapezeFormula20-simpsonFormula20)

data = pd.DataFrame({
    "" : ["Левая ф-ла прямоугольников", "Правая ф-ла прямоугольников", "Усл. ф-ла прямоугольников", "Ф-ла трапеции", "Ф-ла Симпсона"],
    "I₁₀" : [leftRectFormula10, rightRectFormula10, centerRectFormula10,
                trapezeFormula10, simpsonFormula10],
    "Δ(I₁₀)" : [delta_leftRectFormula10, delta_rightRectFormula10, delta_centerRectFormula10,
                 delta_trapezeFormula10, delta_simpsonFormula10],
    "δ(I₁₀), %" : [100*delta_leftRectFormula10/abs(leftRectFormula10),
                 100*delta_rightRectFormula10/abs(rightRectFormula10),
                   100*delta_centerRectFormula10/abs(centerRectFormula10),
                     100*delta_trapezeFormula10/abs(trapezeFormula10),
                       100*delta_simpsonFormula10/abs(simpsonFormula10)],
    "I₂₀" : [leftRectFormula20, rightRectFormula20, centerRectFormula20,
                trapezeFormula20, simpsonFormula20],
    "Δ(I₂₀)" : [delta_leftRectFormula20, delta_rightRectFormula20, delta_centerRectFormula20,
                   delta_trapezeFormula20, None],
    "δ(I₂₀), %" : [100*delta_leftRectFormula20/abs(leftRectFormula20),
                 100*delta_rightRectFormula20/abs(rightRectFormula20),
                   100*delta_centerRectFormula20/abs(centerRectFormula20),
                     100*delta_trapezeFormula20/abs(trapezeFormula20),
                       None]
})

print(f"X : {[np.linspace(a, b, n).round(1)]}")

print(tab.tabulate(data, tablefmt='pipe', headers='keys', showindex=False))

print(f"#------------------------- TASK[8] Accurasy table -----------------------------#")
print(f"#------------f(x) = exp(-x) / sqrt(0.2*x^2+1); | a = {1.3}; b = {2.5}; n = {n}; ------------#")

leftRectFormula10 = rectanglesLeft(variantF, 1.3, 2.5, n)
rightRectFormula10 = rectanglesRight(variantF, 1.3, 2.5, n)
centerRectFormula10 = rectanglesCenter(variantF, 1.3, 2.5, n)
trapezeFormula10 = trapeze(variantF, 1.3, 2.5, n)
simpsonFormula10 = simpson(variantF, 1.3, 2.5, n)

leftRectFormula20 = rectanglesLeft(variantF, 1.3, 2.5, 2*n)
rightRectFormula20 = rectanglesRight(variantF, 1.3, 2.5, 2*n)
centerRectFormula20 = rectanglesCenter(variantF, 1.3, 2.5, 2*n)
trapezeFormula20 = trapeze(variantF, 1.3, 2.5, 2*n)
simpsonFormula20 = simpson(variantF, 1.3, 2.5, 2*n)

delta_leftRectFormula10 = abs(leftRectFormula10-simpsonFormula20)
delta_rightRectFormula10 = abs(rightRectFormula10-simpsonFormula20)
delta_centerRectFormula10 = abs(centerRectFormula10-simpsonFormula20)
delta_trapezeFormula10 = abs(trapezeFormula10-simpsonFormula20)
delta_simpsonFormula10 = abs(simpsonFormula10-simpsonFormula20)

delta_leftRectFormula20 = abs(leftRectFormula20-simpsonFormula20)
delta_rightRectFormula20 = abs(rightRectFormula20-simpsonFormula20)
delta_centerRectFormula20 = abs(centerRectFormula20-simpsonFormula20)
delta_trapezeFormula20 = abs(trapezeFormula20-simpsonFormula20)

data = pd.DataFrame({
    "" : ["Левая ф-ла прямоугольников", "Правая ф-ла прямоугольников", "Усл. ф-ла прямоугольников", "Ф-ла трапеции", "Ф-ла Симпсона"],
    "I₁₀" : [leftRectFormula10, rightRectFormula10, centerRectFormula10,
                trapezeFormula10, simpsonFormula10],
    "Δ(I₁₀)" : [delta_leftRectFormula10, delta_rightRectFormula10, delta_centerRectFormula10,
                 delta_trapezeFormula10, delta_simpsonFormula10],
    "δ(I₁₀), %" : [100*delta_leftRectFormula10/abs(leftRectFormula10),
                 100*delta_rightRectFormula10/abs(rightRectFormula10),
                   100*delta_centerRectFormula10/abs(centerRectFormula10),
                     100*delta_trapezeFormula10/abs(trapezeFormula10),
                       100*delta_simpsonFormula10/abs(simpsonFormula10)],
    "I₂₀" : [leftRectFormula20, rightRectFormula20, centerRectFormula20,
                trapezeFormula20, simpsonFormula20],
    "Δ(I₂₀)" : [delta_leftRectFormula20, delta_rightRectFormula20, delta_centerRectFormula20,
                   delta_trapezeFormula20, None],
    "δ(I₂₀), %" : [100*delta_leftRectFormula20/abs(leftRectFormula20),
                 100*delta_rightRectFormula20/abs(rightRectFormula20),
                   100*delta_centerRectFormula20/abs(centerRectFormula20),
                     100*delta_trapezeFormula20/abs(trapezeFormula20),
                       None]
})

print(f"X : {[np.linspace(a, b, n).round(1)]}")

print(tab.tabulate(data, tablefmt='pipe', headers='keys', showindex=False))



