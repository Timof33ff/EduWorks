import numpy as np
import time
import matplotlib.pyplot as plt
from matplotlib import cm

dt: float = 1e-5  # calculation occurassy

# Start value
m: float = 0.012277471  # Moon mass
M: float = 1.0 - m       # Earth mass
x0: float = 0.994      # x0 value
y0: float = 0.0        # y0 value
X0: float = 0.0        # derivative x0
Y0: float = -2.001585106379
t_max: float = 17.0652165601579625588917206249  # Moon max period
# t_max: float = 1.0652165601579625588917206249  # Moon max period


def sys_sol(u) -> np.array:
    x, y, vx, vy = u  # Moon, Earth coords, Moon, Earth velocities
    global m, M      # masses

    # Dm: float = (((x + m)**2 + y**2)**(1.5))
    # De: float = (((x - M)**2 + y**2)**(1.5))

    return np.array([  # returns system solution`s array
        vx, vy,
        x + 2*vy - M*(x + m) / (((x + m)**2 + y**2)**(1.5)) - \
        m*(x - M) / (((x - M)**2 + y**2)**(1.5)),
        y - 2*vx - M*y / (((x + m)**2 + y**2)**(1.5)) - m * \
        y / (((x - M)**2 + y**2)**(1.5))
    ])


sys_init = np.array([x0, y0, X0, Y0])  # init system array
sys_tmax: float = t_max  # period
