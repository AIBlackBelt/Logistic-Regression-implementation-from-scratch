
#ifndef logistic_H 
#define logistic_H


#include<vector>



double operator*(std::vector<double> a,std::vector<double> b);
std::vector<double> operator+(std::vector<double> a,std::vector<double> b);
std::vector<double> operator-(std::vector<double> a,std::vector<double> b);
void operator+=(std::vector<double> &a,std::vector<double> b);
void operator-=(std::vector<double> a,std::vector<double> b);
std::vector<double> scalaire(std::vector<double> a,double b);



class logi{

private:

std::vector<double> x0;
double step;

public:
 logi(std::vector<double> x0,double step);
 double predict(std::vector<double> weigh,std::vector<double> x);
 std::vector<double> graddescent(std::vector<std::vector<double>> data,std::vector<int> label);

};

#endif /* MY_CLASS_H */