from manim import *

config.background_color = WHITE

class Bye(Scene):
    def construct(self):
        txt  = MathTex(r"C \pi \alpha c \mu \delta 0 \ \ 3 \alpha \ \ \beta \eta \mu \eta\eta \alpha \eta \mu \epsilon !")
        txt.font_size = 64
        txt.color = BLUE_E

        self.play(Write(txt))
        self.wait(1)
        self.play(Unwrite(txt))
        self.wait(1)
