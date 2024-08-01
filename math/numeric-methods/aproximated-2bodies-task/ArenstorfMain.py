from euler import *
from rk4 import *
from calc import *
from init import *
from plots import *
from save_to_files import *

# Diff equations`s sys
'''
{
x`` = x + 2 * y` - MU * (x + mu) / D_1 - mu * (x - MU) / D_2
y`` = y - 2 * x` - MU * y / D_1 - mu * y / D_2
D_m = ((x + m)**2 + y**2)**(3/2)
D_e = ((x - M)**2 + y**2)**(3/2) 
}
'''
'''
_, solution_fix_euler = fix_stepsize(
    sys_sol, sys_init, sys_tmax, euler, dt)
_, solution_fix_rk4 = fix_stepsize(
    sys_sol, sys_init, sys_tmax, rk4, dt)

_, solution_ad_euler, _, _ = adapt_stepsize(
    sys_sol, sys_init, sys_tmax, euler, dt)
_, solution_ad_rk4, _, _ = adapt_stepsize(
    sys_sol, sys_init, sys_tmax, rk4, dt)

 '''
# orbPlots([solution_fix_euler, solution_ad_euler,
#         solution_fix_rk4, solution_ad_rk4])

methodOccurasyPlot(sys_sol, sys_init, sys_tmax, rk4,
                   lin(dt, dt*100, 300))

# orbPlotEulerRK4(solution_fix_euler, solution_fix_rk4, "fixed step")
# orbPlotEulerRK4(solution_ad_euler, solution_ad_rk4, "adapt step")
# '''

# save([solution_fix_euler, solution_ad_euler,
#      solution_fix_rk4, solution_ad_rk4])

# save_forPloting([solution_fix_euler, solution_ad_euler,
#                 solution_fix_rk4, solution_ad_rk4])
