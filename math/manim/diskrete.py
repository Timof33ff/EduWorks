from manim import *
import numpy as np


class Discrete(Scene):
    def construct(self):
        discrete_txt = Text("Дискретизация")
        discrete_txt_1 = Text("Д  и  с  к  р  е  т  и  з  а  ц  и  я")

        discrete_txt.generate_target()
        discrete_txt.target.shift(3*UP+3*LEFT)

        self.play(Write(discrete_txt))
        self.wait(1)
        self.play(Transform(discrete_txt, discrete_txt_1))
        self.remove(discrete_txt_1)
        self.play(MoveToTarget(discrete_txt))
        self.wait(1)

        axes = Axes(
            x_range=(-0.1, 7, 0.5),
            y_range=(-0.1, 4, 0.5),
            x_length=8,
            y_length=4,
        )

        func = axes.plot(lambda x: 0.7*np.sqrt(x), x_range=(0, 6.5))

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

        self.play(Create(axes), Create(func), Create(r))

        for i in rects[1:]:
            self.play(Transform(r, i))

        self.wait(0.3)
        self.wait()
