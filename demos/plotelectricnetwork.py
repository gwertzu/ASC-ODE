import numpy as np
data = np.loadtxt('../build/output_electric_network.txt', usecols=(0, 1, 2, 3))
# print (data)

import matplotlib.pyplot as plt

plt.plot(data[:,0], data[:,1], label='U_C')
plt.plot(data[:,0], data[:,2], label='U_0')
#plt.plot(data[:,0], data[:,3], label='difU_0')
plt.xlabel('time')
plt.ylabel('value')
plt.title('Electrical Network Time Evolution')
plt.legend()
plt.grid()
plt.show()


"""

plt.plot(data[:,1], data[:,2], label='phase plot')
plt.xlabel('position')
plt.ylabel('velocity')
plt.title('Electrical Network Phase Plot')
plt.legend()
plt.grid()
plt.show()

"""