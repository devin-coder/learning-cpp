#include "api.h"

class Param::ParamImpl{
public:
    int num;
    std::string str;// 
    std::string ext;
};

Param::Param(){
    param_impl_.reset(new ParamImpl);
}
Param::~Param() = default;
// Param::Param(Param&& rhs) = default;
// Param& Param::operator=(Param&& rhs) = default;

Param::Param(const Param& rhs)  //copy ctor
: param_impl_(std::make_unique<ParamImpl>(*rhs.param_impl_))
{}

Param& Param::operator=(const Param&& rhs)  // copy operator=
{
    *param_impl_ = * rhs.param_impl_;
    return *this;
}


void Param::SetNum(int num) {
    param_impl_->num = num;
}

int Param::GetNum() const{
    return param_impl_->num;
}

void Param::SetStr(const std::string &str)
{
    param_impl_->str = str;
}
std::string Param::GetStr() const{
    return param_impl_->str;
}

void Param::SetExt(const std::string &str)
{
    param_impl_->ext = str;
}
std::string Param::GetExt() const{
    return param_impl_->ext;
}

void TestFun(const Param& param)
{
    std::cout << "num: " << param.GetNum() 
              << ", str: " << param.GetStr().c_str() 
              << ", ext: " << param.GetExt().c_str() 
              << std::endl;
}


// void TestFun(const Param& param)
// {
//     std::cout << "num: " << param.num 
//               << ", str: " << param.str.c_str() 
//               << ", ext: " << param.ext.c_str() 
//               << std::endl;
// }