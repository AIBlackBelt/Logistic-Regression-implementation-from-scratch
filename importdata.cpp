#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<bits/stdc++.h> 
#include "importdata.h"
using namespace std; 
     
     
     
// We define a data related class that contains all the informations about data, you give the number of features and the size (number of records in the dataset), plus an absolute path to the csv.file
// NOTE : You dataset columns must follow this order : feature1,feature2,feature3...............,featureN,TARGET varibale      
// See blow the class constuctor feature represents the number of features, datasizes represents the number of records    
     Data::Data(int feature,int datasizes,std::string path)
     {   this->feature = feature;
         this->datasize = datasizes;
         std::vector<std::vector<double>> data(datasizes);
         std::vector<int> target(datasizes);
         ifstream stream1(path);
         std::string a;
         stream1 >> a;
         int j = 0;
         double instances;
         while (j <= datasizes-1){
             std::string word;
             stream1 >> a;
             stringstream s(a);
             int i = 0;
             std::vector<double> tmp(feature);
             while (getline(s, word, ',')) { 
                instances = stod(word);
                if (i <= feature-1){
                 tmp[i] = instances;
                }
                else{
                 target[j] = instances;
                }
                 i = i + 1;
             }
             data[j]=tmp;
             j = j + 1;
            }
         this->data = data;
         this->target = target;
     }


     int Data::getfeature() const {
         return this->feature;}

     
     int Data::getdatasize(){
         return this->datasize;}
     
    // This method is provided to standarize the data, by substracting the mean and dividing by the standard deviation
     void Data::featurescaling(){
            vector<double> mean((this->feature));
            vector<double> std((this->feature));
            for(int k=0;k<=(this->feature)-1;k++){
                mean[k] = 0;
                std[k] = 0;}
               
            for(int k=0;k<=(this->datasize)-1;k++){
                for(int i=0;i<=(this->feature)-1;i++){
                    mean[i] = mean[i] + this->data[k][i];}
            }
            for(int i=0;i<=(this->feature)-1;i++){
                mean[i] = mean[i]/this->datasize;}
                for(int k=0;k<=(this->datasize)-1;k++){
                    for(int i=0;i<=(this->feature)-1;i++){
                        std[i] = std[i] + pow(this->data[k][i]-mean[i],2.0);}
                }
                for(int i=0;i<=(this->feature)-1;i++){
                    std[i] = std[i]/this->datasize;}
    
                for(int k=0;k<=(this->datasize)-1;k++){
                      
                      for(int i=0;i<=(this->feature)-1;i++){
                      this->data[k][i] = (this->data[k][i] - mean[i])/std[i];}
                      }
            }

  // this method actually gives you the two dimensional matrix
  std::vector<std::vector<double>> Data::getdata(){
           return this->data;}
  // this method actually gives you the target variable
  std::vector<int> Data::gettarget(){
           return this->target;}

