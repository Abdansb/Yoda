import matplotlib.pyplot as plt
from sklearn.datasets import load_iris

# Load iris dataset
iris = load_iris()

# Assign data and target
X = iris.data[:, :2] # We only take the first two features for simplicity
y = iris.target

# Plot the data points
plt.scatter(X[:, 0], X[:, 1], c=y, cmap='viridis')
plt.xlabel('Sepal length')
plt.ylabel('Sepal width')
plt.title('Iris Dataset')

plt.show()
