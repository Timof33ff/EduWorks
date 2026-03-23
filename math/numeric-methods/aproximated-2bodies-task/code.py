from manim import *

config.background_color = WHITE

class CodeRK4(Scene):
    def construct(self):
        code = Code(code='''# RUNGE-KUTTA method
def rk4(f, tau, u) -> float:
    i1 = f(u)
    i2 = f(u + tau*i1/2)
    i3 = f(u + tau*i2/2)
    i4 = f(u + tau*i3)
    return u + tau * (i1 + 2*i2 + 2*i3 + i4) / 6

rk4.order = 2
rk4.name = "Runge-Kutta 4 grade"''',
            tab_width=4, background="window", language="Python", style="monokai")
        code.scale(0.7)
        
        self.play(Create(code))
        self.wait(1)

class CodeEuler(Scene):
    def construct(self):
        code = Code(code='''# EULER method
def euler(f, tau, u) -> float:  # f -
    return u + tau*f(u)

euler.order = 1
euler.name = "Euler"''',
            tab_width=4, background="window", language="Python", style="monokai")
        code.scale(0.7)
        
        self.play(Create(code))
        self.wait(1)

class CodeInit(Scene):
    def construct(self):
        code = Code(code='''import numpy as np
import time
import matplotlib.pyplot as plt
from matplotlib import cm

dt: float = 1e-2  # calculation occurassy

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

    F0: float = (((x + m)**2 + y**2)**(1.5))
    F1: float = (((x - M)**2 + y**2)**(1.5))

    return np.array([  # returns system solution`s array
        vx, vy,
        x + 2*vy - M*(x + m) / F0 - m*(x - M) / F1,
        y - 2*vx - M*y / F0 - m * y / F1
    ])

sys_init = np.array([x0, y0, X0, Y0])  # init system array
sys_tmax: float = t_max  # period''',
            tab_width=4, background="window", language="Python", style="monokai")
        code.scale(0.6)
        
        self.play(Create(code))
        self.wait(1)

class CodeCalcAdSS(Scene):
    def construct(self):
        code = Code(code='''def adapt_stepsize(f, y0, tmax, method, tol, tau=0.01):
    t: float = 0.0
    u = y0
    T: list[float] = [t]
    solution = [y0]
    steps: int = 0
    failed: int = 0  # fails count

    tcs = time.time()

    while t < tmax:
        if t+tau > tmax:
            tau = tmax-t
        u1 = method(f, tau, u)  # 1 step
        u2 = method(f, tau/2, u)
        u2 = method(f, tau/2, u2)  # 2 halfsteps

        err = np.linalg.norm(u1-u2)/(1-2**(-method.order))  # Runge rule
        fac = (tol/err)**(1/(method.order+1))  # set tau
        taunew = tau * min(2, max(0.25, 0.8 * fac))

        if err < tol:
            t += tau
            u = u1
            T.append(t)
            solution.append(u)
        else:
            failed += 1
        tau = taunew
        steps += 1

    tce = time.time()

    print(f"{method.name} : Steps`s count: {
          len(T)-1} | fails : {failed} : calculation time, seconds: {tce-tcs}")
    return np.array(T), np.array(solution), steps, failed''',
            tab_width=4, background="window", language="Python", style="monokai")
        code.scale(0.5)
        
        self.play(Create(code))
        self.wait(1)


class CodeCalcFixSS(Scene):
    def construct(self):
        code = Code(code='''def fix_stepsize(f, y0, tmax, method, tau=0.1):  # calculate system by fixed (tau) step
    t: float = 0.0
    u = y0
    T: list[float] = [t]
    solution = [y0]
    tcs = time.time()  # time calculation start
    while t < tmax:
        if t+tau > tmax:
            tau = tmax-t
        u = method(f, tau, u)
        t += tau
        T.append(t)
        solution.append(u)
    tce = time.time()  # time calculation end
    print(f"{method.name} : Steps`s count: {
          len(T)-1} : calculation time, seconds: {tce-tcs}")
    return np.array(T), np.array(solution)''',
            tab_width=4, background="window", language="Python", style="monokai")
        code.scale(0.7)
        
        self.play(Create(code))
        self.wait(1)
        
