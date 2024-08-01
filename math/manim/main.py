from manim import *
import math

'''
class DefaultTemplate(Scene):
    def construct(self):
        circle = Circle()  # create a circle
        circle.set_fill(BLUE, opacity=0.5)  # set color and transparency

        square = Square()  # create a square
        square.flip(LEFT)  # flip horizontally
        square.rotate(-3 * TAU / 8)  # rotate a certain amount

        self.play(Create(square))  # animate the creation of the square
        # interpolate the square into the circle
        self.play(Transform(square, circle))
        self.play(FadeOut(square))  # fade out animation
'''


class ShowWrite(Scene):
    def construct(self):

        # Greeting
        hello = Text("Здраствуйте,\n\tуважаемая аудитория!", color=BLACK)
        self.play(Write(hello))
        self.wait(1)
        self.clear()
    # Square equation

        tex_exp_equation = Tex(
            r"$x^2 + 5x + 4 = 0$").set_color(BLACK)
        self.play(Write(tex_exp_equation))
        self.wait(1)
        self.play(tex_exp_equation.animate.to_edge(UP+LEFT))
    # Square equation plot
        ax = Axes(x_range=[-10, 6, 1], y_range=[-3, 3, 1],
                  axis_config={"include_numbers": True}, tips=True)
        ax.set_color(BLACK)

        labels = ax.get_axis_labels(x_label="x", y_label="f(x)")

        graph = ax.plot(lambda x: x**2 + 5*x + 4,
                        color=BLACK, x_range=[-5.5, 0.5])

        dot = Dot(ax.i2gp(graph.t_min, graph), color=BLACK)
        x1 = Dot(ax.i2gp(-4, graph), color=RED)
        x2 = Dot(ax.i2gp(-1, graph), color=RED)

        self.add(ax, labels, x1, x2)
        self.play(Create(graph))
        self.play(MoveAlongPath(dot, graph), run_time=2, rate_func=linear)
        self.wait(1)

    # Math. models

        # Рунге-Ккута

        # Эйлер

        # Коши

        #
