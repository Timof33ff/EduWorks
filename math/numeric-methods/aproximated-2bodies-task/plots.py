from init import *
from calc import *
# DRAW PLOTS


def orbPlots(solution):  # create a four solution`s canva
    dataX = [[], [], [], []]
    dataY = [[], [], [], []]
    title = [f"Euler | fixed step | {dt}", f"Euler | adapt step | {dt}",
             f"Runge-Kutta | fixed step | {dt}", f"Runge-Kutta | adapt step | {dt}"]

    sb: int = 221
    for i in range(4):
        for j in range(len(solution[i])-1):
            dataX[i].append(solution[i][j][0])
            dataY[i].append(solution[i][j][1])
        # print(dataX)
        '''
        plt.subplot(sb)  # create graph
        sb += 1
        plt.plot(dataX[i],
                 dataY[i], color="red")
        plt.scatter([0.0],
                    [0.0], marker='o', color="green", s=100)
        plt.scatter([0.994],
                    [0.0], marker='o', color="gray", s=45)
        plt.legend(("Trajectory",
                    "Earth", "Moon"), loc='upper right')
        plt.title(title[i])
        plt.grid(True)
    plt.show()
    '''


# create 3d plot by calculation`s steps count (x), fails count (y), occurassy (z)
def methodOccurasyPlot(f, y0, tmax, method, occurassy):
    stepcount = []
    fails = []
    for j in occurassy:
        _, _, step, fail = adapt_stepsize(f, y0, tmax, method, j)
        stepcount.append(step)
        fails.append(fail)

    fig = plt.figure()
    ax = fig.add_subplot(projection='3d')
    # 3D scatter plot with color bar
    # fax.plot_trisurf(stepcount, fails, occurassy, cmap=plt.cm.CMRmap)
    ax.scatter(stepcount, fails, occurassy)

    ax.set_xlabel("Steps")
    ax.set_ylabel("Fails")
    ax.set_zlabel("Occurassy")
    plt.title(method.name+"`s method occurassy graph")
    plt.show()


# create euler & rk4 plots on a single canva
def orbPlotEulerRK4(s1, s2, step_type: str):
    dataX1 = []
    dataY1 = []
    for i in s1:
        dataX1.append(i[0])
        dataY1.append(i[1])

    dataX2 = []
    dataY2 = []
    for i in s2:
        dataX2.append(i[0])
        dataY2.append(i[1])
    plt.plot(dataX1, dataY1, color="red")
    plt.plot(dataX2, dataY2, color="blue")
    plt.scatter([0.0],
                [0.0], marker='o', color="green", s=100)
    plt.scatter([0.994],
                [0.0], marker='o', color="gray", s=45)
    plt.legend(("Euler", "Runge-Kutta", "Earth", "Moon"), loc='upper right')
    plt.title(f"Euler & Runge-Kutta | {step_type} | {dt}")
    plt.grid(True)
    plt.show()
