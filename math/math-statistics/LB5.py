import numpy as np
import matplotlib.pyplot as plt
import math as math

sp = np.array([22.98, 23.86, 24.74, 25.62, 26.5], dtype=np.float64)
freq = np.array([6, 7, 8, 7, 6])
freq_t = np.array([5.04*math.exp(-50), 8.83*math.exp(-45), 7.93*math.exp(-40), -7.93*math.exp(-40), -8.83*math.exp(-45)], dtype=float)

plt.title('Graph of calculated and theoretical frequencies')
plt.grid()
plt.plot(sp, freq, 'r')
plt.plot(sp, freq_t, 'b')
plt.show()
