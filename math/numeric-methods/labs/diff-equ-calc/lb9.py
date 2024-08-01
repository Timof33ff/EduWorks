from methods import *

# TASK
'''
sol = Eiler(f, y0, a, b, n)

print({'X value' : np.array(sol[0]).round(4),
    'Y value' : np.array(sol[1]).round(4)})

plt.plot(sol[0], sol[1])
plt.scatter(sol[0], sol[1], marker='s')
plt.show()


# TASK 2
sol = Eiler(f12, y012, a12, b12, n)

print({'X value' : np.array(sol[0]).round(4),
    'Y value' : np.array(sol[1]).round(4)})

plt.plot(sol[0], sol[1])
plt.scatter(sol[0], sol[1], marker='s')
plt.show()

'''
# TASK 3 

sol = embeddedEiler(f, y0, a, b, n)

print({'X value' : np.array(sol[0]).round(4),
    'Y value' : np.array(sol[1]).round(4)})
plt.plot(sol[0], sol[1])
plt.scatter(sol[0], sol[1], marker='s')
plt.show()

# TASK 4

sol = embeddedEiler(f12, y012, a12, b12, n)

print({'X value' : np.array(sol[0]).round(4),
    'Y value' : np.array(sol[1]).round(4)})
'''
plt.plot(sol[0], sol[1])
plt.scatter(sol[0], sol[1], marker='s')
plt.show()
'''
# TASK 5

sol = RungeKutta(f, y0, a, b, n)

print({'X value' : np.array(sol[0]).round(4),
    'Y value' : np.array(sol[1]).round(4)})
'''
plt.plot(solution[0], solution[1])
plt.scatter(solution[0], solution[1], marker='s')
plt.show()
'''
# TASK 6

sol = RungeKutta(f12, y012, a12, b12, n)

print({'X value' : np.array(sol[0]).round(4),
    'Y value' : np.array(sol[1]).round(4)})
'''
plt.plot(solution[0], solution[1])
plt.scatter(solution[0], solution[1], marker='s')
plt.show()
'''
# TASK 7

showMerge(f, y0, a, b, n, methods)

# TASK 8

showMerge(f12, y012, a12, b12, n, methods)

