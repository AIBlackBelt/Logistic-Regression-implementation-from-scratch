This repo is intended to show a method to implement logistic regression from scratch in c++, the algorithm pseudo-code followed is shown in the file pseudocode.png

In order to compile the files, this command would suffices : g++ *.cpp.
An executable will be built named as a.out that you should execute in you command line to view the results of logistic regression applied to the dataset binary2.csv.

Scripts and meanings : 

importdata.cpp : it's a class that take care of the different operations made on data, from importation to scaling. It stores the data in a two dimensional matrix data structure (two dimension vector in c++), the target variable is stored in a seperate vector.

logistic.cpp : a class that implement the cross entropy function optimization, the gradient is computed directly without approximations. The weights are optimized till a certain precision on the distance between the gradient vector and the null vector is met (till this distance goes below a certain treshold) then we stop the optimization process and return the weights.

main.cpp : It puts together the two previous scripts and prodives at the end, an emperical error on the number of records whose prediction failed.
