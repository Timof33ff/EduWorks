from manim import *

config.background_color = WHITE

class RungeKutta(Scene):
    def construct(self):

        title = Text("Метод Рунге-Кутта 4-ого порядка",
                     font = "ISOCPEUR", font_size=48, color = PURPLE_E)
        self.play(Write(title))
        self.wait(1)
        self.play(title.animate.shift(3*UP))
        self.wait(1)
        
        math0  = MathTex(
            r'y(x_{i+1}) = y(x_i)+\frac{\Delta x}{6}\cdot(k_1+k_2+k_3+k_4), \ \  i=0,1,2..'
            ).move_to([0,2,0])
        math0.color=BLACK
        math1  = MathTex(
            r'k_1=f(x_i,y_i)), \ \  i=0,1,2..'
            ).next_to(math0, DOWN)
        math1.color=BLACK
        math2  = MathTex(
            r'k_2=f(x_i + \frac{\Delta x}{2} ,y_i+\frac{\Delta x}{2}\cdot k_1)'
            ).next_to(math1, DOWN)
        math2.color=BLACK
        math3  = MathTex(
            r'k_3=f(x_i + \frac{\Delta x}{2} ,y_i+\frac{\Delta x}{2}\cdot k_2)'
            ).next_to(math2, DOWN)
        math3.color=BLACK
        math4  = MathTex(
            r'k_4=f(x_i + \Delta x ,y_i+\Delta x\cdot k_3)'
            ).next_to(math3, DOWN)
        math4.color=BLACK

        eqVg = VGroup(math0, math1, math2, math3, math4)
        self.play(Write(eqVg))
        self.wait(2)
        self.play(eqVg.animate.shift([-3,0,0]).scale(0.5))
        self.wait(2)
        
        brace = Brace(eqVg, [2,0,0], buff=0.3)
        brace.color = BLUE_E
        code = Code(code = '''# RUNGE-KUTTA method
def rk4(f, tau, u) -> float:
    i1 = f(u)
    i2 = f(u + tau*i1/2)
    i3 = f(u + tau*i2/2)
    i4 = f(u + tau*i3)
    return u + tau * (i1 + 2*i2 + 2*i3 + i4) / 6''',
                language="Python", style="monokai").scale(0.55).next_to(brace)
        self.play(Create(brace), Create(code))
        self.wait(1)
