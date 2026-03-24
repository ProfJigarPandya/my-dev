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
print()
print("Attempt # 1 without outlier KM++" )
centers, indices = kmeans_plusplus(X, n_clusters=2, random_state=0)
print("centers",centers)
print("indices",indices)

print()
print("Attempt # 2 with outlier KM++ ")
X = np.array([[1], [2], [3],[8], [9], [10], [25]])
centers, indices = kmeans_plusplus(X, n_clusters=2, random_state=0)
print("centers",centers)
print("indices",indices)

print()
print("Attempt # 3 without outlier KM lloyd default")
X = np.array([[1], [2], [3],[8], [9], [10]])
centroid, label, inertia = k_means(X, n_clusters=2)
print("centroid",centroid)
print("label",label)
print("inertia",inertia)

print()
print("Attempt # 4 with outlier KM lloyd default")
X = np.array([[1], [2], [3],[8], [9], [10], [25]])
centroid, label, inertia = k_means(X, n_clusters=2)
print("centroid",centroid)
print("label",label)
print("inertia",inertia)


print()
print("Attempt # 5 without outlier KM elkan")
X = np.array([[1], [2], [3],[8], [9], [10]])
centroid, label, inertia = k_means(X, n_clusters=2,algorithm="elkan")
print("centroid",centroid)
print("label",label)
print("inertia",inertia)

print()
print("Attempt # 6 with outlier KM elkan")
X = np.array([[1], [2], [3],[8], [9], [10], [25]])
centroid, label, inertia = k_means(X, n_clusters=2,algorithm="elkan")
print("centroid",centroid)
print("label",label)
print("inertia",inertia)



print()
print("Attempt # 7 with outlier centroid 3 and 10" )
initial_centroids = np.array([[3], [10]])
X = np.array([[1], [2], [3],[8], [9], [10], [25]])
centroid, label, inertia = k_means(X, n_clusters=2,n_init=1,init=initial_centroids)
print("centroid",centroid)
print("label",label)
print("inertia",inertia)

print()
print("Attempt # 8 with outlier")
#initial_centers = np.array([[2], [15]])
X = np.array([[1], [2], [3],[8], [9], [10], [25]])
initial_centers = np.array([[8], [9]])
centroid, label, inertia = k_means(X, n_clusters=2,n_init=1, init=initial_centers,max_iter=1)
print("label",label)
print("inertia",inertia)

print()
print("Attempt # 9 with outlier")
#initial_centers = np.array([[2], [15]])
X = np.array([[1], [2], [3],[8], [9], [10], [25]])
initial_centers = np.array([[9], [10]])
centroid, label, inertia = k_means(X, n_clusters=2,n_init=1, init=initial_centers,max_iter=1)
print("label",label)
print("inertia",inertia)
