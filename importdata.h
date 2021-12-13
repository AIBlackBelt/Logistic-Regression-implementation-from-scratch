#ifndef importdata_H 
#define importdata_H
#include<string>
#include<vector>

class Data{

private:

      int feature;
      int datasize;
      std::vector<std::vector<double>> data;
      std::vector<int> target;


public:
 
  Data(int feature,int datasizes,std::string pa);
  int getfeature() const;
  int getdatasize();
  std::vector<std::vector<double>> getdata();
  std::vector<int> gettarget();
  void featurescaling();
};
#endif /* MY_CLASS_H */