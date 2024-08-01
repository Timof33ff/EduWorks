'''import matplotlib.pyplot as plt
import numpy as np

# Sample data
np.random.seed(4072023)
x = np.random.normal(size=200)
y = np.random.normal(size=200)
z = np.random.normal(size=200)

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

# 3D scatter plot with color bar
plot = ax.scatter(x, y, z, c=z, cmap='Reds')
fig.colorbar(plot, ax=ax, shrink=0.5, aspect=10)

plt.show()
#-----------------------------------------------------
import matplotlib.pyplot as plt
import numpy as np

# Sample data
X, Y = np.meshgrid(np.linspace(-4, 4),
                   np.linspace(-4, 4))
R = np.sqrt(X**2 + Y**2)
Z = np.sin(R) / R

print(R)

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

# 3D surface plot
ax.plot_surface(X, Y, Z)

plt.show()
'''
# -------------------------------------------------------
import matplotlib.pyplot as plt

from mpl_toolkits.mplot3d import axes3d

fig = plt.figure()
ax = fig.add_subplot(projection='3d')

# Grab some example data and plot a basic wireframe.
X, Y, Z = axes3d.get_test_data(0.05)
ax.plot_wireframe(X, Y, Z, rstride=10, cstride=10)

# Set the axis labels
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')

# Rotate the axes and update
for angle in range(0, 360*4 + 1):
    # Normalize the angle to the range [-180, 180] for display
    angle_norm = (angle + 180) % 360 - 180

    # Cycle through a full rotation of elevation, then azimuth, roll, and all
    elev = azim = roll = 0
    if angle <= 360:
        elev = angle_norm
    elif angle <= 360*2:
        azim = angle_norm
    elif angle <= 360*3:
        roll = angle_norm
    else:
        elev = azim = roll = angle_norm

    # Update the axis view and title
    ax.view_init(elev, azim, roll)
    plt.title('Elevation: %d°, Azimuth: %d°, Roll: %d°' % (elev, azim, roll))

    plt.draw()
    plt.pause(.001)
