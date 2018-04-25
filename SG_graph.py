import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('advection.txt', delimiter = ' ')
n = len(datos)
n_x = 4000

snap_1 = datos[0:n_x-1,:]
snap_2 = datos[n_x:2*n_x-1,:]
snap_3 = datos[2*n_x:3*n_x-1,:]
snap_4 = datos[3*n_x:4*n_x-1,:]
snap_5 = datos[4*n_x:5*n_x-1,:]

plt.figure()
plt.plot(snap_1[:,0],snap_1[:,1], label = 't_0')
plt.plot(snap_2[:,0],snap_2[:,1], label = 't_1')
plt.plot(snap_3[:,0],snap_3[:,1], label = 't_2')
plt.plot(snap_4[:,0],snap_4[:,1], label = 't_3')
plt.plot(snap_5[:,0],snap_5[:,1], label = 't_4')
plt.xlabel('x')
plt.ylabel('y(x,t)')
plt.legend()
plt.savefig('PDE.pdf')
        

        
