import pandas as pd
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from matplotlib import pyplot as plt

data_set = load_iris()
x_train, x_test, y_train, y_test = train_test_split(data_set['data'], data_set['target'],
                                                    test_size=0.25, random_state=0)
iris_dataframe = pd.DataFrame(x_train, columns=data_set.feature_names)
grr = pd.plotting.scatter_matrix(iris_dataframe, c=y_train, figsize=(15, 15), marker='o',
                                 hist_kwds={'bins': 20}, s=60, alpha=.8)
plt.show()
