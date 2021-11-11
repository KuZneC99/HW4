import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv('/home/eugeneknvlv/flita/results.csv')
df[['size', 'merge sort', 'selection sort']].plot(
    x = 'size'
)

plt.show()

