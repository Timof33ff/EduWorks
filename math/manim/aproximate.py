from manim import *
import numpy as np
import random
from scipy.optimize import curve_fit


class Aproximate(Scene):
    def construct(self):

        aproximation_txt = Text("Апроксимация", color=BLACK)
        aproximation_txt.generate_target()
        aproximation_txt.target.shift(3*UP + 4*LEFT)

        x_r = [-5, 5]
        y_r = [-4, 4]

        aproximation_ax = Axes(
            x_range=x_r,
            y_range=y_r,
            x_length=5,
            axis_config={"include_numbers": True},
        )
        aproximation_ax.color = BLACK

        # create something similar to experiment`s data
        aproximation_dots = []  # dots list
        num: int = 10  # num of dots

        x = np.linspace(min(x_r)-2, max(x_r)-2, num)  # x seq
        y = [random.uniform(0.8, 1.1)*i + random.uniform(0.1, 0.2)
             for i in x]  # y seq

        for i in range(num):
            aproximation_dots.append(
                Dot(aproximation_ax.coords_to_point(x[i], y[i]), color=RED_A))

        def xab(x, a, b,):
            return a*x+b

        popt, pcov = curve_fit(xab, x, y)

        aproximation_ax.center()
        aproximation_graph = aproximation_ax.plot(
            lambda x: popt[0]*x + popt[1], x_range=(min(x_r)-2, max(x_r)-2)
        )

        # create aproximation graph

        self.play(Write(aproximation_txt))
        self.play(MoveToTarget(aproximation_txt))
        self.wait(1)
        self.play(Create(aproximation_ax))
        self.add(*aproximation_dots)
        self.play(Create(aproximation_graph))
        self.wait(2)
