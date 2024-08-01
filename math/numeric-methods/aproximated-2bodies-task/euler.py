# EULER method
def euler(f, tau, u) -> float:  # f -
    return u + tau*f(u)


euler.order = 1
euler.name = "Euler"
