from init import *
# CALCULATIONS
# About step selection


def fix_stepsize(f, y0, tmax, method, tau=0.1):  # calculate system by fixed (tau) step
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
    return np.array(T), np.array(solution)


def adapt_stepsize(f, y0, tmax, method, tol, tau=0.01):
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
    return np.array(T), np.array(solution), steps, failed


def lin(start, stop, num) -> list[float]:
    h = (stop-start)/num
    return [start+h*i for i in range(num)]
