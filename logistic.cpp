#include<iostream>
#include<vector>
#include<cmath>
#include "logistic.h"
//include"operators.h"
using namespace std; 
//********************************* First we define a couple typical functions (operators) to handle mathematical operations (dot product, sum of two vectors, substraction of two vectors ext..)*********************
std::vector<double> scalaire(std::vector<double> a,double b){
     
     vector<double> c(a.size());
     for(int i = 0;i<= a.size()-1;i++){
           c[i] = a[i]*b;
    }
    
     return c;
    }



double operator*(std::vector<double> a,std::vector<double> b){
     
     double c = 0;
     for(int i = 0;i<= a.size()-1;i++){
           c = c + a[i]*b[i];
    }
    
     return c;
    }
std::vector<double> operator+(std::vector<double> a,std::vector<double> b){
     
    std::vector<double> c(a.size());
    
    for(int i = 0;i<= a.size()-1;i++){
           c[i] = a[i]+b[i];
    }
    
     return c;
    }
std::vector<double> operator-(std::vector<double> a,std::vector<double> b){
     
    std::vector<double> c(a.size());
    
    for(int i = 0;i<= a.size()-1;i++){
           c[i] = a[i]-b[i];
    }
    
     return c;
    }

void operator+=(std::vector<double> &a,std::vector<double> b){

      for(int i = 0;i<= a.size()-1;i++)
      {a[i] = a[i]+b[i];}
}

void operator-=(std::vector<double> a,std::vector<double> b){

      for(int i = 0;i<= a.size()-1;i++)
      {a[i] = a[i]-b[i];}
}



double logi::predict(std::vector<double> weigh,std::vector<double> x){

      std::vector<double> weighin = scalaire(weigh,-1);
      return 1/(1+exp(weighin*x));

}
//********************** now we start defining our logistic regression class ******************************
// our logistic regression class is defined by the initial weight vector(x0), learning rate (step)
logi::logi(std::vector<double> x0,double step){


    this->x0 = x0;
    this->step = step;
}
// our optimization algorithm gradient descent which uses a fixed learning rate (step), the gradient isn't approximated, we compute it according to its analytical formulas shown in file pseudo code 
std::vector<double> logi::graddescent(std::vector<std::vector<double>> data,std::vector<int> label){

         int k = 0;
         std::vector<double> x = this->x0;
         std::vector<double> update(x.size());
         for(int i=0;i<=x.size()-1;i++)
         {update[i] = 0;}
         for(int i=0;i<=data.size()-1;i++)
         {update += scalaire(data[i],label[i]-predict(x,data[i]));}
         double size_inverse = 1.0/(data.size());
         update = scalaire(update,size_inverse);
         // you can edit the precision below, tune the parameter 0.01, the lower it's , the higher is the precision
         // the vector "update" represents the gradient vector
         while ( sqrt(update*update) >= 0.01) {
           for(int i=0;i<=x.size()-1;i++)
           {update[i] = 0;}
           for(int i=0;i<=data.size()-1;i++)
           {update += scalaire(data[i],label[i]-predict(x,data[i]));}
             update = scalaire(update,size_inverse);
             x = x + scalaire(update,this->step);
             k = k + 1;}
         cout << k << " iterations were made" <<endl;
         return x;
}

