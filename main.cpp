#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include "logistic.h"
#include "importdata.h"
using namespace std;




int main(){
Data data(3,400,"/home/dark/Mywork/Logistic regression/binary2.csv");
std::vector<int> target = data.gettarget();
data.featurescaling();
std::vector<std::vector<double>> donnee = data.getdata();
std::vector<double> a(data.getfeature());
// initialize the weight vector by 1
for(int k = 0;k <= data.getfeature()-1; k++){
      a[k] = 1;
}
// initialize the logistic class by the vector a and a learning equal to 1 
logi ac(a,1);
std::vector<double> c(data.getfeature());
// call the gradient optimizer ang get the set of weights
c = ac.graddescent(donnee,target);
cout << "weights values :" <<endl ;
// display them on the console
for(int k = 0;k <= data.getfeature()-1; k++){
         cout << c[k] <<endl ;}
// 
int True = 0;
int Missed = 0;
for(int k = 0;k<=399;k++){
    if ( ac.predict(c,donnee[k]) > 0.5 ){
        if (target[k] == 1){
            True = True + 1;
        }
        else{
            Missed = Missed + 1;
        }
    }
    if ( ac.predict(c,donnee[k]) < 0.5 ){
        if (target[k] == 0){

            True = True + 1;
        }
        else{
            Missed = Missed + 1;
        }}
}
double ab = (double)Missed/400;
//We compute a percentage of prediction that failed to predict the right label
cout << "Emprical error :" << ab <<endl;
}