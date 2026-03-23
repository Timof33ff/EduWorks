from methods import *

'''x = [0.75, 1.50, 2.25, 3.00, 3.75] 
y = [2.50, 1.20, 1.12, 2.25, 4.28]

u = [1.125, 1.875, 2.625, 3.375, 4.125] # точки, где ищем решение'''

'''print(tabulate.tabulate(pd.DataFrame({
        "X зад.": x,  "Y зад.": y,
        "X искомые": u, "Y искомые": [Lagrange(y, x, i) for i in u]}),
        headers=["X зад.", "Y зад.", "X искомые", "Y искомые"], tablefmt='pipe'))

drawLagrange(y, x, u)'''

# TASK 2 (12 var)

'''x = [2.5, 8.3, 14.1, 20.5, 26.1]
y = [0.17, 0.13, 0.1, 0.13, 0.22]

u = [(x[i] + x[i-1])/2 for i in range(1, len(x))] # считаем точки между известными X
u.append(x[len(x)-1] + sum(u)/len(u)**2)

print(tabulate.tabulate(pd.DataFrame({
        "X зад.": x,  "Y зад.": y,
        "X искомые": u, "Y искомые": [Lagrange(y, x, i) for i in u]}),
        headers=["X зад.", "Y зад.", "X искомые", "Y искомые"], tablefmt='pipe'))

drawLagrange(y, x, u)'''


# TASK 3 

'''drawMMQ([0.65, 1.07, 1.7, 2.26, 2.78],
        [1.5, 1.8, 2.3, 2.8, 3.8], 'lin')

drawMMQ([0.75, 1.5, 2.25, 3.0, 3.75],
        [2.5, 1.2, 1.12, 2.25, 4.28], 'quad')'''

# TASK 4 (12 var)

drawMMQ([2.5, 8.3, 14.1, 20.5, 26.1],
        [0.17, 0.13, 0.1, 0.13, 0.22], 'lin')

drawMMQ([2.5, 8.3, 14.1, 20.5, 26.1],
        [0.17, 0.13, 0.1, 0.13, 0.22], 'quad')

