import numpy as np
import random
import matplotlib.pyplot as plt

# 700 -1100  450 -700  

colors = ["#"+''.join([random.choice('0123456789ABCDEF') for j in range(6)])for i in range(6)]

x = np.linspace(0, 1500, 10000)

ab = [[-2.0, 1000.0], [-0.4, 360.0], [-1.06499, 562.5], [-1.6, 16.0]]
points = [[400.0, 200.0], [466.666, 66.666], [304.511, 238.195]]

fig, (ax) = plt.subplots()
ax.set_xlim([-1, 1500])
ax.set_ylim([-1, 1500])
for j in range(len(ab)-1):
    ax.plot(x, [ab[j][0]*i+ab[j][1] for i in x], color=colors[j], linewidth=1, label=str(j+1)+' line')
    ax.stackplot(x, [ab[j][0]*i+ab[j][1] for i in x], color=colors[j], alpha = 0.18)

ax.scatter(points[0][0], points[0][1], linewidth=0.7, marker='o', color='black')
ax.scatter(points[2][0], points[2][1], linewidth=0.7, marker='o', color='black')

ax.plot(x, [ab[-1][0]*i+ab[-1][1] for i in x], '--', linewidth=1.2, color='black', label='Level line')
ax.plot(x, [-0.625*i+508.3225 for i in x], '--', linewidth=1.2, color='red', label='Level line')
ax.scatter(points[1][0], points[1][1], marker='o', linewidth=0.9, color='red')

plt.grid()
plt.legend(loc='upper left')
plt.show()
