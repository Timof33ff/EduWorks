from manim import *

config.background_color = WHITE

paths = ["C:\\Users\\Админ\\Documents\\Labs\\Math\\NumericMethods\\StudVesna\\Arenstorf\\.png\\euler_rk4_fixstep_1e-05.png",
         "C:\\Users\\Админ\\Documents\\Labs\\Math\\NumericMethods\\StudVesna\\Arenstorf\\.png\\euler_rk4_adaptstep_1e-05.png",
         "C:\\Users\\Админ\\Documents\\Labs\\Math\\NumericMethods\\StudVesna\\Arenstorf\\.png\\solutions_1e-05.png",
         "C:\\Users\\Админ\\Documents\\Labs\\Math\\NumericMethods\\StudVesna\\Arenstorf\\.png\\rk4_occ_graph_1e-05.png"]
fs:int=48

def init(self):
    title1 = Text("Фиксированный шаг (1e-5) :",
                  color=BLUE_E, weight=BOLD, font='ISOCPEUR')
    # bg1 = BackgroundRectangle(title1, color=BLACK, fill_opacity=0.15)
    res1Tab = Table([["1.7e+06", "12.18"],
                    ["1.7e+06", "64.41"]],
                    col_labels=[Text("steps count", color=BLACK, font='ISOCPEUR'),
                                Text("calc time, sec", color=BLACK, font='ISOCPEUR')],
                    row_labels=[Text("Euler", color=BLACK, font='ISOCPEUR'),
                                Text("RK4", color=BLACK, font='ISOCPEUR')],
                    include_outer_lines=True
                    )
    res1Tab.color = BLACK
    title2 = Text("Адаптивный шаг (1e-5) :", color=BLUE_E,
                  weight=BOLD, font='ISOCPEUR')
    # bg2 = BackgroundRectangle(title2, color=BLACK)
    res2Tab = Table([["7371", "0.20", "5"],
                    ["191", "0.03", "38"]],
                    col_labels=[Text("step count", color=BLACK, font='ISOCPEUR'),
                                Text("calc time, sec", color=BLACK, font='ISOCPEUR'),
                                Text("fails", color=BLACK, font='ISOCPEUR')],
                    row_labels=[Text("Euler", color=BLACK, font='ISOCPEUR'),
                                Text("RK4", color=BLACK, font='ISOCPEUR')],
                    include_outer_lines=True
                    )
    res2Tab.color = BLACK

    res1Tab.next_to(title1, DOWN)
    res2Tab.next_to(title2, DOWN)

    return title1, res1Tab, title2, res2Tab  # bg1, bg2



class ResultPlot0(Scene):
    def construct(self):

        txt = Text('Все решения', color=BLACK, font='ISOCPEUR', font_size=fs). move_to([0, 0, 0])

        global paths
        path = paths[2]
        im0 = ImageMobject(path).move_to([8, 0, 0]).scale(1.8)
        self.play(Write(txt))
        self.wait(1)
        self.play(FadeOut(txt))
        #self.play(Unwrite(txt))
        self.play(FadeIn(im0), im0.animate.shift(LEFT*8))
        self.wait(2)
        # self.play(FadeOut(im0))
        self.wait(1)


class ResultPlot1(Scene):
    def construct(self):

        txt = Text('Фиксированный шаг', color=BLACK, font='ISOCPEUR', font_size=fs). move_to([0, 0, 0])

        global paths
        path = paths[0]
        im0 = ImageMobject(path).move_to([8, 0, 0]).scale(2)
        self.play(Write(txt))
        self.wait(1)
        self.play(FadeOut(txt))
        self.play(FadeIn(im0), im0.animate.shift(LEFT*8))
        self.wait(2)
        # self.play(FadeOut(im0))
        self.wait(1)


class ResultPlot2(Scene):
    def construct(self):

        txt = Text('Адаптивный шаг', color=BLACK, font='ISOCPEUR', font_size=fs). move_to([0, 0, 0])

        global paths
        path = paths[1]
        im0 = ImageMobject(path).move_to([8, 0, 0]).scale(2)
        self.play(Write(txt))
        self.wait(1)
        self.play(FadeOut(txt))
        self.play(FadeIn(im0), im0.animate.shift(LEFT*8))
        self.wait(2)
        # self.play(FadeOut(im0))
        self.wait(1)

 

class ResultPlot3(Scene):
    def construct(self):

        txt = Text('Оценка адаптивного алгоритма',
                   color=BLACK, font='ISOCPEUR', font_size=fs). move_to([0, 0, 0])

        global paths
        path = paths[3]
        im0 = ImageMobject(path).move_to([8, 0, 0]).scale(2.1)
        self.play(Write(txt))
        self.wait(1)
        self.play(FadeOut(txt))
        self.play(FadeIn(im0), im0.animate.shift(LEFT*8))
        self.wait(2)
        # self.play(FadeOut(im0))
        self.wait(1)


class ResultTab(Scene):
    def construct(self):
        # creates res manim table
        '''dic = {":": GREEN,
               "Euler": ORANGE,
               "Runge-Kutta 4 grade": RED,
               "Fixed step size (1e-5) :": PURPLE_E,
               "Adapt step size :": PURPLE_E
               }'''
        t1, tab1, t2, tab2 = init(self)
        

        vg1 = VGroup(t1, tab1).move_to([0,0,0]).scale(0.5)
        vg1.generate_target()
        vg1.target.shift([0,2,0])

        vg2 = VGroup(t2, tab2).next_to([0,2,0], DOWN).scale(0.5)
        
        self.play(Create(vg1, lag_ratio=2))
        self.play(MoveToTarget(vg1))
        self.wait(1)
        self.play(Create(vg2, lag_ratio=2))
        self.wait(1)
