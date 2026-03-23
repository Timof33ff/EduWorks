from manim import *

config.background_color = WHITE


class Euler(Scene):
    def construct(self):

        title = Text('Метод Эйлера\n для систем дифференциальных уравнений',
                     color=PURPLE_E, font='ISOCPEUR', font_size=32)
        title.generate_target()
        title.target.shift(3*UP+2*LEFT)
        self.play(Write(title))
        self.wait(1)
        self.play(MoveToTarget(title))
        self.wait(1)

        theorem = MathTex(r' y(x_{i+1}) = y(x_i)+ f(x_i, y_i)\cdot \Delta x, \ \  i=0,1,2..').move_to([0, 2, 0]).set_color(BLACK)
        self.play(Write(theorem))
        self.wait(1)

        bgr = BackgroundRectangle(theorem, color=BLUE_E, fill_opacity=0.15)
        self.play(Create(bgr))

        axes = Axes(
            x_range=(-0.1, 7, 0.5),
            y_range=(-0.1, 4, 0.5),
            x_length=8,
            y_length=4,
        ).move_to([-3, -1, 0]).set_color(BLACK).scale(0.7)

        labels = axes.get_axis_labels(
            Text("x", color=BLACK, font='ISOCPEUR'), Text("y", color=BLACK, font='ISOCPEUR')).set_color(BLACK)

        func = axes.plot(lambda x: 0.7*np.sqrt(x),
                         x_range=(0, 6.5)).set_color(BLACK)

        rects = VGroup(*[
            axes.get_riemann_rectangles(
                func,
                x_range=[0, 6.5],
                dx=dx,
                input_sample_type="left",
                stroke_width=dx if dx > 0.1 else 0.8,
            )
            .set_color_by_gradient(PURPLE, ORANGE)
            .set_stroke(color=BLACK if dx > 0.5 else None)
            for dx in [1/(i) for i in range(1, 5)]
        ])

        r = rects[0]

        self.play(Create(axes),
                  Write(labels),
                  Create(func),
                  Create(r))

        for i in rects[1:]:
            self.play(Transform(r, i))

        self.wait(1)

        brace = Brace(axes, [2,0,0], buff=0.5)
        brace.color = BLUE_E

        code = Code(code='''
def euler(f, tau, u) -> float:
    return u + tau*f(u)''',
            language='Python', style='monokai').next_to(brace, RIGHT).scale(0.7)
        self.play(Create(brace), Create(code))
        self.wait(1)
