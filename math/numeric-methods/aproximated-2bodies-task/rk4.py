# RUNGE-KUTTA method
def rk4(f, tau, u) -> float:
    i1 = f(u)
    i2 = f(u + tau*i1/2)
    i3 = f(u + tau*i2/2)
    i4 = f(u + tau*i3)
    return u + tau * (i1 + 2*i2 + 2*i3 + i4) / 6


rk4.order = 2
rk4.name = "Runge-Kutta 4 grade"
