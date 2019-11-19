from numpy import *
from matplotlib.pylab import *

t = loadtxt("tiempo.txt")
n30 = loadtxt("n30.txt")

plot(linspace(-1,1,len(n30[1,:])),n30[15,:])
savefig("grafica1.png")