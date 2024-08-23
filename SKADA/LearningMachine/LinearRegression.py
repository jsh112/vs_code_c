import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

from ucimlrepo import fetch_ucirepo

# fetch dataset
df = fetch_ucirepo(id=242)

# data (as pandas dataframes)
X = df.data.features
y = df.data.targets

# variable information

enb = pd.concat([X, y], axis=1)

enb.columns = [
    'relative_compactness', 'surface_area', 'wall_area', 'roof_area', 'overall_height',
    'orientation', 'glazing_area', 'glazing_area_distribution', 'heating_load', 'cooling_load'
]
print(enb.keys())
print(enb.shape)

# enb.hist(figsize=(10, 10), layout=(3, 4))

# enb.plot(kind='box', figsize=(6, 6), layout=(3, 4))

# enb.plot(kind='box', subplots=True, figsize=(6, 6), layout=(3, 4))

plt.figure(figsize=(10, 10))
sns.heatmap(enb.corr().round(3), cmap='Greens', annot=True, fmt='.2f')
plt.show()
