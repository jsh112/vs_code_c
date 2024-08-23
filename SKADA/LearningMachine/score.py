import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import folium as folium
from folium import plugins
from folium.plugins import HeatMap
from pandas.plotting import scatter_matrix
import warnings

# Fetching the dataset
from sklearn.datasets import fetch_california_housing
dataset = fetch_california_housing(as_frame=True)
X = dataset.data
Y = dataset.target
data = pd.concat([X, Y], axis=1)

print(data.isna().sum())

# train_test_split
