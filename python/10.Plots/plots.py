# -*- coding: utf-8 -*-
"""Plots.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1Gs5mK7_OhYTLAqLVxd4hEowuXln9dgcX
"""

import pandas as pd
import numpy as np
from scipy import stats
from matplotlib import pyplot as plt

df = pd.read_csv("tips.csv")
print(df)
print(np.mean(df["tip"]))
print(np.median(df["tip"]))
print(np.std(df["tip"]))
print(np.var(df["tip"]))
slope = stats.linregress(df["total_bill"], df["tip"])
print(slope)
plt.scatter(df["total_bill"], df["tip"])
plt.plot(df["total_bill"], df["total_bill"] * slope.slope + slope.intercept)



df = pd.read_csv("tips.csv")
# First 10
print(df[:10])
# Scatter plot
plt.scatter(df["day"], df["tip"])

plt.plot(df["day"], df["tip"])

plt.bar(df["day"], df["tip"])

plt.hist(df["total_bill"])

tips = df["tip"]
my_dict = dict()
my_dict["pass"] = 0
my_dict["fail"] = 0
for i in tips:
  if(i > 3):
    my_dict["pass"] += 1
  else:
    my_dict["fail"] += 1
print(my_dict)