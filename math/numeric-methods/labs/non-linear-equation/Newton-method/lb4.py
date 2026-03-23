from methods import *

# TASK 1: x^2 - sqrt(x+4) = 0; [1, 2] eps = 0.001

x0 = 2.0
eps = 0.001

def f(x):
    return x**2 - np.sqrt(x+4)

'''print(f'\n$--TASK 1: x^2 - sqrt(x+4) = 0; [1, 2] eps = 0.001--\n{Newton(f, x0, eps)}\n-------------------------------------$')

# TASK 2: x^2 - sqrt(x+4) = 0; [-2, -1] eps = 0.001

print(f'\n$--TASK 2: x^2 - sqrt(x+4) = 0; [-2, -1] eps = 0.001--\n{Newton(f, -2, eps)}\n-------------------------------------$')'''

# TASK 3: x^3 + 3*x^2 - 1 = 0; eps = 0.001

def f1(x):
    return x**3 + 3*x**2 - 3

'''print(f'\n$--TASK 3: x^3 + 3*x^2 - 1 = 0; 1`st root; eps = 0.001--\n{Newton(f1, -3, eps)}\n-------------------------------------$')

print(f'\n$--TASK 3: x^3 + 3*x^2 - 1 = 0; 2`nd root; eps = 0.001--\n{Newton(f1, -1, eps)}\n-------------------------------------$')

print(f'\n$--TASK 3: x^3 + 3*x^2 - 1 = 0; 3`rd root; eps = 0.001--\n{Newton(f1, 0, eps)}\n-------------------------------------$')'''

# TASK 4:  ---

# TASK 5: combined chords & tangents method

'''print(f'\n$--TASK 5: combined chords & tangents method x^2 - sqrt(x+4) = 0; [-2, -1] eps = 0.001--\n{chordsTangents(f, -2.0, -1.0, eps)}\n-------------------------------------$')
print(f'\n$--TASK 5: combined chords & tangents method x^2 - sqrt(x+4) = 0; [1, 2] eps = 0.001--\n{chordsTangents(f, 1.0, 2.0, eps)}\n-------------------------------------$')'''

# TASK 6: 12. combined chords & tangents method

print(f"\n$--TASK 6: 12. combined chords & tangents method x^3 + 3*x^2 - 3 = 0; [-3.0, -2.0] eps = 0.001--\n{chordsTangents(f1, -3.0, -2.0, eps)}\n-------------------------------------$")
print(f"\n$--TASK 6: 12. combined chords & tangents method x^3 + 3*x^2 - 3 = 0; [-2.0, -1.0] eps = 0.001--\n{chordsTangents(f1, -2.0, -1.0, eps)}\n-------------------------------------$")
print(f"\n$--TASK 6: 12. combined chords & tangents method x^3 + 3*x^2 - 3 = 0; [0.0, 1.0] eps = 0.001--\n{chordsTangents(f1, 0.0, 1.0, eps)}\n-------------------------------------$")

