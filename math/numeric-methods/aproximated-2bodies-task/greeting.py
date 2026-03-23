from manim import *

config.background_color = WHITE


class Greeting(Scene):
    def construct(self):

        # Greeting
        hello = Text("Здраствуйте,\n\tуважаемая аудитория!",
                     weight=BOLD, color=BLACK).move_to([0, 0, 0])
        hello.generate_target()
        hello.target.shift(3*UP)
        theme = Text("\t\t\t  ЧИСЛЕННЫЕ МЕТОДЫ\nобработки экспериментальных данных",
                     t2w={"ЧИСЛЕННЫЕ МЕТОДЫ": BOLD},
                     t2c={"обработки экспериментальных данных": BLUE_E},
                     color=BLACK, weight=BOLD, font_size=42).move_to([0, 3, 0])
        authors = Text("Подготовлено:\nСт. К1-61Б Тимофеевым К. А.\nСт. преп. К6 Черновой Т.В.",
                       weight=BOLD, color=BLACK, font_size=28,
                       t2c={
                           "Тимофеевым К. А.": BLUE_E,
                           "Черновой Т.В.": BLUE_E
                       },
                       t2w={"Тимофеевым К. А.": BOLD,
                            "Черновой Т.В.": BOLD}
                       ).move_to([0, 0, 0])
        authors.generate_target()
        authors.target.shift(UP+4*RIGHT)
        bgr = Rectangle(color=BLUE_E, height=1)
        bgr.set_style(stroke_width=0, fill_color=BLUE_E, fill_opacity=0.15)
        bgr.surround(authors)
        bgr.generate_target()
        bgr.target.shift(UP+4*RIGHT)

        self.play(Write(hello))
        self.wait(1)
        self.play(MoveToTarget(hello))
        self.play(Transform(hello, theme))
        self.wait(1)
        self.play(Write(authors), Create(bgr))
        self.play(MoveToTarget(authors), MoveToTarget(bgr))
        self.wait(1)

        img = ImageMobject(
            "C:\\Users\\Админ\\Documents\\Labs\\Math\\NumericMethods\\StudVesna\\Arenstorf\\.png\\rk4_occ_graph_1e-05.png").move_to(-1*UP+3*LEFT).scale(1.5)
        self.play(FadeIn(img))
        self.wait(1)
