import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.axisartist.axislines import AxesZero


def dif1(y, dt):
    res = [(y[i] - y[i-1])/dt for i in range(len(y)-1)]
    res.insert(0, None)
    return res


def dif2(y, dt):
    res = [(y[i+1] - 2*y[i] + y[i-1])/dt**2 for i in range(len(y)-1)]
    res.insert(0, None)
    return res


def equationSolution(f, lin, dt) -> float:
    f_arr = [f(i) for i in lin]  # function array
    fd_arr = dif1(f_arr, dt)  # function derivative array
    fdd_arr = dif2(f_arr, dt)  # function derivative derivative array

    isRootExist = [None]
    for i in range(len(lin)-1):
        if f_arr[i]*f_arr[i+1] < 0:
            isRootExist.append(f'Root exist on {[lin[i], lin[i+1]]}')
        else:
            isRootExist.append('...')

    return [f_arr, isRootExist, fd_arr, fdd_arr]


def showGraphMethod(function, start: float = -5.0, end: float = 5.0, step: float = 0.01, title: str = r''):
    fig = plt.figure()
    ax = fig.add_subplot(axes_class=AxesZero)
    x = np.arange(start, end, step)
    y = np.array(function(x))
    plot = ax.plot(x, y, c='red')
    ax.axvline(0, color='black', linestyle='-', alpha=1.0, linewidth=0.8)
    ax.axhline(0, color='black', linestyle='-', alpha=1.0, linewidth=0.8)
    ax.set_title(title)
    plt.grid()
    # fig.savefig(title+'.png')
    plt.show()
    plt.close()
