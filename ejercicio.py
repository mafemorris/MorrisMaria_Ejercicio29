from numpy import *
from matplotlib.pylab import *

t = loadtxt("tiempo.txt")
n30 = loadtxt("n30.txt")

for i in range(len(n30[0])):
    plot(linspace(-1,1,len(n30[1,:])),n30[i,:])
savefig("grafica2.png")
figure()
imshow(n30, aspect = 0.01)
savefig("grafica1.png")