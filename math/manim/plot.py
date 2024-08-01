from manim import *
import math


class Plot(MovingCameraScene):
    def construct(self):

        self.camera.frame.save_state()

        ax = Axes(
            x_range=[-100, 100, 10], y_range=[-1000, 1000, 100], axis_config={"include_tip": True},
        )
        labels = ax.get_axis_labels(x_label="x", y_label="f(x)")

        grid = NumberPlane()

        circle = Circle(radius=2, color=YELLOW)
        dot = Dot()

        self.add(grid, ax, labels)
        self.play(Create(grid, run_time=2, lag_ratio=0.1))
        self.play(GrowFromCenter(circle, point_color=RED))

        self.play(self.camera.frame.animate.scale(0.75).move_to(dot))

        def update_curve(mob):
            mob.move_to(dot.get_center())

        self.camera.frame.add_updater(update_curve)
        self.play(MoveAlongPath(dot, circle), run_time=3)
        self.wait(0.5)
        self.camera.frame.remove_updater(update_curve)
        self.play(Restore(self.camera.frame))

        '''grid.prepare_for_nonlinear_transform()
        self.play(
            grid.animate.apply_function(
                lambda p: p
                + np.array(
                    [
                        np.sin(p[1]),
                        np.sin(p[0]),
                        0,
                    ]
                )
            ),
            run_time=3,
        )'''

        self.wait(1)
