//
// Created by macbookpro on 2022/11/15.
//

#include "stock00.h"
#include <iostream>

void Stock::acquire(const std::string &co,long n,double pr){
    company =co;//可以直接访问成员变量
    if(n<0){
        std::cout <<"Number of share can't be negative:" <<company <<" set to be zero";
        shares=0;
    }
    else{
        shares=n;
    }
    share_val=pr;
    set_tot(); //可以直接访问私有函数
}

void Stock::buy(long num,double pr){
    if(num <0){
        std::cout <<"Number of share can't be negative:交易失败";
        return;
    }
    else{
        shares +=num;
        share_val=pr;
        set_tot();
    }
}

void Stock::sell(long num,double pr){
    using std::cout;
    if(num < 0){
        cout <<"卖出股票不能小于0"<<std::endl;
        return;
    }
    else if(num >shares){
        cout <<"不能超过卖出的数量\n";
        return;

    }else{
        shares -=num;
        share_val=pr;
        set_tot();
    }

}

void Stock::update(double price) {
    share_val=price;
    set_tot();
}

void Stock::show() {
    std::cout <<"---\nCompany: " << company<<std::endl;
    std::cout <<"Count: " << shares<<std::endl;
    std::cout <<"Value: " << share_val<<std::endl;
    std::cout <<"Total: " << total_val <<" $\n----\n" << std::endl;
}

std::string *  Stock::show_name(){
    return &company;

}