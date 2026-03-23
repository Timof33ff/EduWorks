from methods import *

# TASK 1: find nonlinear equation`s solution in points


def y(x) -> list[float]:
    res: list[float] = []
    for i in x:
        if i <= 0:
            res.append(round(np.sin(i), 3))
        else:
            res.append(round(i**3 + np.log(i), 3))
    return res


print(f'Task №1 : Answer is {y([-2, 0, 3])}')

# TASK 2 find nonlinear equation`s solution analytically

def f(x) -> float:
    return x**2-np.sqrt(x+4)

start = -4.0  # [a, b]
end = 7.0
step = 1

solution = equationSolution(f, np.arange(start, end, step), step)

print(f'Task №2 : Solution is \n{pd.DataFrame({
    "№": range(int(start), int(end)),
    "x": np.arange(start, end, step),"y": solution[0],
    "Comment": solution[1],
    "y`": solution[2], "y``": solution[3]
})}')

# TASK 3: x^2 - sqrt(x+4) = 0; by graphic method

showGraphMethod(f, -4.0, 7.0, 1,
                r'$ y = x^2 - \sqrt{x+4};\ \ \in [-4, 6],\ \ h = 1$')

# TASK 4: x^3 + 3*x^2 - 1 = 0; search for roots

def eq(x):
    return x**3 + 3*x**2 - 1


sol = equationSolution(eq, np.arange(start, end, step), step)

print(f'Task №4 : Solution is \n{pd.DataFrame({
    "№": range(int(start), int(end)),
    "x": np.arange(start, end, step),
    "y": sol[0],
    "Comment": sol[1],
    "y`": sol[2],
    "y``": sol[3]
})}')

showGraphMethod(eq, -4, 2, 0.01,
                r'$12. y = x^3 + 3 \cdot x^2 - 1;\ \ \in [-4, 2],\ \ h = 0.01$')
