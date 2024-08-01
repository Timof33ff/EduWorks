from manim import *
from manim_code_blocks import *
config.background_color = WHITE


class About(Scene):
    def construct(self):
        title = Text(
            "Численные методы - ", weight=BOLD, color=PURPLE_E, font='ISOCPEUR').move_to([0, 1, 0])
        par = Paragraph(
            "методы решения математических задач\n \
            в виде чисел или набора чисел.",
            alignment="left",
            font='ISOCPEUR'
        ).next_to(title, DOWN)
        par.color = BLACK
        vgp = VGroup(title, par)
        
        bc_rect = BackgroundRectangle(vgp, color=BLUE_E, fill_opacity=0.15)
        rect = Rectangle(color=BLUE_E, stroke_width=8)
        rect.surround(bc_rect, dim_to_match=0)
        
        self.add(bc_rect)
        self.play(Write(vgp))
        self.play(Create(rect))
        self.wait(2)
        self.play(FadeOut(par),
                  RemoveTextLetterByLetter(title),
                  FadeOut(rect),
                  FadeOut(bc_rect))
        self.wait(1)

        task = Text("Задача трёх тел (Земля, Луна, Тело)",
                    weight = BOLD, color = BLACK, font='ISOCPEUR', font_size=32
                    ).move_to([0,3,0])
        
        x_eq = MathTex(
            r"x``=x+2\cdot y`-M\cdot\frac{x+M}{\sqrt{(x+m)^2+y^2}^3}-m\cdot\frac{x-M}{\sqrt{(x-m)^2+y^2}^3}",
            ).next_to(task, DOWN)
        x_eq.color = BLACK

        y_eq = MathTex(
            r"y``=y-2\cdot x` -M\cdot\frac{y}{\sqrt{(x+m)^2+y^2}^3}-m\cdot\frac{y}{\sqrt{(x-m)^2+y^2}^3}",
            ).next_to(x_eq, DOWN)
        y_eq.color = BLACK

        txt = Text("Нач. условия:",
                   color=BLACK, font='ISOCPEUR', font_size=28
                   ).next_to(y_eq, DOWN)

        init = MathTex(
            r"m=0.012277471,\ \ M=1-m,"
            ).next_to(txt, DOWN)
        init.color = BLACK

        init1 = MathTex(
            r"x`(0)=0.0,\ \ y`(0)=-2.001585106,"
            ).next_to(init, DOWN)
        init1.color = BLACK

        init2 = MathTex(
            r"x(0)=0.994,\ \ y(0)=0.0;"
            ).next_to(init1, DOWN)
        init2.color = BLACK

        vg = VGroup(task, x_eq, y_eq)
        vg1 = VGroup(txt, init, init1, init2)
        self.play(Create(vg))
        self.wait(1)
        self.play(Create(vg1))
        self.wait(3)
        self.play(FadeOut())

        cb = CodeBlock(
            """
            dt: float = 1e-2  # calculation occurassy

            # Start value
            m: float = 0.012277471  # Moon mass
            M: float = 1.0 - m       # Earth mass
            x0: float = 0.994      # x0 value
            y0: float = 0.0        # y0 value
            X0: float = 0.0        # derivative x0
            Y0: float = -2.001585106379
            t_max: float = 17.0652165601579625588917206249  # Moon max period
            # t_max: float = 1.0652165601579625588917206249  # Moon max period

            def sys_sol(u) -> np.array:
                x, y, vx, vy = u  # Moon, Earth coords, Moon, Earth velocities
                global m, M      # masses
    
                D0: float = (((x + m)**2 + y**2)**(1.5))
                D1: float = (((x - M)**2 + y**2)**(1.5))

                return np.array([  # returns system solution`s array
                                vx, vy,
                                x + 2*vy - M*(x + m) / D0 - m*(x - M) / D1,
                                y - 2*vx - M*y / D0 - m * y / D1
                                ])

            sys_init = np.array([x0, y0, X0, Y0])  # init system array
            sys_tmax: float = t_max  # period
            """,
            language  = Python
        ).move_to([2,3,0])

        self.play(*cb.create(run_time=3))
        self.wait(1)
