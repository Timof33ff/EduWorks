import numpy as np

x = np.matrix([
    [0.63, 0.05, 0.15, 0.34],
    [0.05, 0.34, 0.10, 0.32],
    [0.15, 0.10, 0.70, 0.72]
])

print(x[:3, :3])
