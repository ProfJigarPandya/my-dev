'''
Created on 19-Nov-2022

@author: jigarpandya
pip install scikit-learn

'''
from sklearn.cluster import kmeans_plusplus
from sklearn.cluster import k_means
import numpy as np
#X = np.array([[1, 2], [1, 4], [1, 0],[10, 2], [10, 4], [10, 0]])
X = np.array([[1], [2], [3],[8], [9], [10]])
print("Attempt 1 without outlier")
centers, indices = kmeans_plusplus(X, n_clusters=2, random_state=0)
print("centers",centers)
print("indices",indices)

print("Attempt 1 with outlier")
X = np.array([[1], [2], [3],[8], [9], [10], [25]])
centers, indices = kmeans_plusplus(X, n_clusters=2, random_state=0)
print("centers",centers)
print("indices",indices)

print("Attempt 2 without outlier")
X = np.array([[1], [2], [3],[8], [9], [10]])
centroid, label, inertia = k_means(X, n_clusters=2)
print("centroid",centroid)
print("label",label)
print("inertia",inertia)

print("Attempt 2 with outlier")
X = np.array([[1], [2], [3],[8], [9], [10], [25]])
centroid, label, inertia = k_means(X, n_clusters=2)
print("centroid",centroid)
print("label",label)
print("inertia",inertia)


print("Attempt 3 without outlier")
X = np.array([[1], [2], [3],[8], [9], [10]])
centroid, label, inertia = k_means(X, n_clusters=2,algorithm="elkan")
print("centroid",centroid)
print("label",label)
print("inertia",inertia)

print("Attempt 3 with outlier")
X = np.array([[1], [2], [3],[8], [9], [10], [25]])
centroid, label, inertia = k_means(X, n_clusters=2,algorithm="elkan")
print("centroid",centroid)
print("label",label)
print("inertia",inertia)