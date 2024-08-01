from manim import *

class CodeInit(Scene):
    def construct(self):
        
        py = Code(code='''dt: float = 1e-5  # calculation occurassy 
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
sys_tmax: float = t_max  # period''', tab_width=4, background="window",
                            language="Python", style="monokai")
        py.scale(0.7)

        self.play(Create(py))
        self.wait(1)
