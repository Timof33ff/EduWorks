import pandas as pd
import numpy as np
# from IPython.display import display
import os

parent_dir = os.path.dirname(os.path.abspath(__file__))
parent_dir = os.path.split(parent_dir)
parent_dir = os.path.split(parent_dir[0])
path = os.path.join(parent_dir[0], "StudVesna\\outX_1e-2.csv")
# print(path)

DATAX = pd.DataFrame()
DATAX = pd.read_csv(path)
DATAY = pd.DataFrame()
DATAY = pd.read_csv(path)
dt = 1e-2

titles = [f"Euler | fixed step | {dt}", f"Euler | adapt step | {dt}",
          f"Runge-Kutta | fixed step | {dt}", f"Runge-Kutta | adapt step | {dt}"]
# display(DATA)
