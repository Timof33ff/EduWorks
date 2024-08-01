from init import *
import pandas as pd


def save(solution):

    dataX = [[], [], [], []]
    dataY = [[], [], [], []]
    title = [f"Euler | fixed step | {dt}", f"Euler | adapt step | {dt}",
             f"Runge-Kutta | fixed step | {dt}", f"Runge-Kutta | adapt step | {dt}"]

    for i in range(4):
        for j in range(len(solution[i])-1):
            dataX[i].append(solution[i][j][0])
            dataY[i].append(solution[i][j][1])

    df = pd.DataFrame({title[0]: {"x": dataX[0],
                       "y": dataY[0]},
                       title[1]: {"x": dataX[1],
                       "y": dataY[1]},
                       title[2]: {"x": dataX[2],
                       "y": dataY[2]},
                       title[3]: {"x": dataX[3],
                       "y": dataY[3]}})
    df.to_csv("out.csv")


def save_forPloting(solution):
    dataX = [[], [], [], []]
    dataY = [[], [], [], []]

    title = [f"Euler | fixed step | {0.01}", f"Euler | adapt step | {0.01}",
             f"Runge-Kutta | fixed step | {0.01}", f"Runge-Kutta | adapt step | {0.01}"]

    for i in range(4):
        for j in range(len(solution[i])-1):
            dataX[i].append(solution[i][j][0])
            dataY[i].append(solution[i][j][1])

    dfx = pd.concat([pd.DataFrame({title[0]: dataX[0]}), pd.DataFrame({title[1]: dataX[1]}),
                     pd.DataFrame({title[2]: dataX[2]}), pd.DataFrame({title[3]: dataX[3]})], axis=1, ignore_index=False)
    dfy = pd.concat([pd.DataFrame({title[0]: dataY[0]}), pd.DataFrame({title[1]: dataY[1]}),
                     pd.DataFrame({title[2]: dataY[2]}), pd.DataFrame({title[3]: dataY[3]})], axis=1, ignore_index=False)
    dfx.to_csv("outX_1e-2.csv")
    dfy.to_csv("outY_1e-2.csv")
