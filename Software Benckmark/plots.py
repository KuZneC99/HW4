import matplotlib.pyplot as plt
import pandas as pd
import numpy as np
import math

df = pd.read_csv('/home/eugeneknvlv/flita/results.csv')

fig, (ax1, ax2, ax3) = plt.subplots(3)

x = df['size'].to_numpy()
theory1 = [40 * (n * math.log(n + 1, 2)) / (2.5 * 10**9) for n in x]
theory2 = [4 * n**2 / (2.5*10**9) for n in x]

ms = df['merge sort'].to_numpy()
ss = df['selection sort'].to_numpy()

ax1.plot(x, ms, 'r')
ax1.plot(x, theory1, linestyle = '--', color = 'g')
ax2.plot(x, ss, 'b')
ax2.plot(x, theory2, linestyle = '--', color = 'g') 
ax3.plot(x, ms, 'r', x, ss, 'b')

ax1.set_title('Merge sort')
ax2.set_title('Selection sort')
ax3.set_title('Comparison')

plt.tight_layout()
plt.savefig('../plot.png')

