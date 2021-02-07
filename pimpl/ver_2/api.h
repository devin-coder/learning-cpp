#pragma once

#include <iostream>
#include <memory>

class Param{
public:
    void SetNum(int num);
    int GetNum() const;
    void SetStr(const std::string &str);
    std::string GetStr() const;
    void SetExt(const std::string &str);
    std::string GetExt() const;
    Param();
    ~Param();
    Param(const Param& rhs); // declarations only
    Param& operator=(const Param&& rhs);
private:
    class ParamImpl;  // forward declaration  // tell compiler  class/struct pointer, not struct/class impelent.
    std::unique_ptr<ParamImpl> param_impl_;
};

// struct Param
// {
//     int num;
//     std::string str;// 
//     std::string ext;
// };

void TestFun(const Param & param);