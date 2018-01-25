# Import the libraries
import numpy
import matplotlib.pyplot
import pandas

# Importing the dataset
dataset = pandas.read_csv('Data.csv')
X = dataset.iloc[:, :-1].values
#print (X)
y = dataset.iloc[:, 3].values
#print (y)


# Taking care of missing data
from sklearn.preprocessing import Imputer
imputer = Imputer(missing_values = 'NaN', strategy = 'mean', axis = 0)
imputer = imputer.fit(X[:, 1:3])
X[:, 1:3] = imputer.transform(X[:, 1:3])
print(X[4])
print(X[6])