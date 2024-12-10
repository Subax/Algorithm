import pandas as pd  # Data Organization & Calculating
import numpy as np  # Calculating Algebra linear system
import matplotlib.pyplot as plt  # Visualization as chart of plot

# ---------------------------------------Series(Same rule as List or Vector)


sr = pd.Series(
    [[10, 2, 30], "beer", "beer", "beer"], index=["pizza", "chicken", "coke", "beer"]
)
print("Series printing")
print("-" * 15)
print(sr)


# ---------------------------------------DataFrame(Same rule as Array)


print("Value of Series: {}".format(sr.index))
values = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
index = ["one", "two", "three"]
columns = ["A", "B", "C"]


df = pd.DataFrame(values, index=index, columns=columns)
print("DataFrame:")
print("-" * 15)
print(df)

print("Values of dataFrame:\n{}".format(df.values))
# ---------------------------------------DataFrame_2
data = [[1000, "hanbyul", "choi"], [1001, "soyoon", "noh"]]
df2 = pd.DataFrame(data)

print("DataFrame:")
print("-" * 15)
print(df2)

print("Values of dataFrame2:\n{}".format(df2.values))
# ---------------------------------------Roading csv
# df3 = pd.read_csv("example.csv")


# ------------------------------------------------------------------------------Numpy


vec = np.array([1, 2, 3, 4, 5])  # One dimension array = Vector
print(vec)

mat = np.array([[1, 2, 3, 4, 5], [10, 20, 30, 40, 50]])  # Two dimension array = Matrix
print(mat)

# The results are same as 'numpy.ndarray'
print("Type of vec:{}".format(type(vec)))
print("Type of mat:{}".format(type(mat)))

# Ndim & Shape (**very important**)
print("Count of ndim of vec: {}".format(vec.ndim))  # =1
print("Count of shape of vec: {}".format(vec.shape))  # = (5,)

print("Count of ndim of mat: {}".format(mat.ndim))  # =2
print("Count of shape of mat: {}".format(mat.shape))  # =(2, 3)

# All values are 0 in 2*3 matrix
zero_mat = np.zeros((2, 3))
print(zero_mat)

# All values are 1 in 2*3 matrix
one_mat = np.ones((2, 3))
print(one_mat)

# All values are specific constant in 2*2 matrix
cons_mat = np.full((2, 2), 7)
print(cons_mat)

# Unit matrix
eye_mat = np.eye(3)  # 3*3
print(eye_mat)

# Random matrix
random_mat = np.random.random((2, 2))
print(random_mat)

# Zero to n-1 vector
range_vec = np.arange(10)  # 0 to 9
print(range_vec)

# i to j, each +2
n = 2
range_n_step_vec = np.arange(1, 10, n)
print(range_n_step_vec)  # [1 3 5 7 9]

# Matrix reshape
bef_reshape_mat = np.arange(30)
aft_reshape_mat = bef_reshape_mat.reshape((5, 6))  # reshape (1, 30) -> (5, 6)
print(bef_reshape_mat)
print(aft_reshape_mat)


# ------------------------------------------------------------------------------Matplotlib


plt.title("test")
plt.plot([1, 2, 3, 4], [2, 4, 8, 6])
plt.show()
