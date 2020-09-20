import pandas as pd
import matplotlib.pyplot as plt

raw = pd.read_csv('expSmooting.csv', index_col=0)
raw.columns =['input', 'filter0', 'filter1', 'filter2']
print(raw)

# 1
plt.figure()
plt.plot(raw)
plt.legend(raw.columns)
plt.xlabel("Time (ms)")
plt.ylabel("Value")

# 2
plt.figure()

plt.subplot(3,1,1)
plt.plot(raw['filter0'], 'orange')
plt.plot(raw['input'], 'b')
plt.title('Filter0 kF = 0.01')
plt.xlabel("Time (ms)")
plt.ylabel("Value")

plt.subplot(3,1,2)
plt.plot(raw['filter1'], 'green')
plt.plot(raw['input'], 'b')
plt.title('Filter1 kF = 0.05')
plt.xlabel("Time (ms)")
plt.ylabel("Value")

plt.subplot(3,1,3)
plt.plot(raw['filter2'], 'red')
plt.plot(raw['input'], 'b')
plt.title('Filter2 kF = 0.1')
plt.xlabel("Time (ms)")
plt.ylabel("Value")

plt.subplots_adjust(hspace=0.9, top=0.93)

plt.show()