//
//  main.cpp
//  stl算法
//
//  Created by 郭悟清 on 2017/6/7.
//  Copyright © 2017年 郭悟清. All rights reserved.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

class CLessThen9
{
public:
    bool operator()(int n)
    {
        return n<9;
    }
};
void outputSquare(int value)
{
    cout<<value*value<<" ";
}
int calculateCube(int value)
{
    return value*value*value;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    const int SIZE=10;
    int a1[]={1,2,3,4,5,6,7,8,9,10};
    int a2[]={100,2,8,1,50,3,8,9,10,2};
    vector<int> v(a1,a1+SIZE);
    ostream_iterator<int> output(cout," ");//output对象第一个参数接收要被输出的int数据
    random_shuffle(v.begin(), v.end());//随机打乱
    cout<<endl<<"1)";
    copy(v.begin(),v.end(),output);//把v拷贝到output，并用output实现输出
    copy(a2,a2+SIZE,v.begin());//把a2拷贝到v（必须保证v空间足够大）
    cout<<endl<<"2)";
    count(v.begin(),v.end(),8);//查找v中等于8的元素，输出个数
    cout<<endl<<"3)";
    cout<<count_if(v.begin(),v.end(),CLessThen9());//输出v中小于9的元素的个数
    cout<<*(min_element(v.begin(), v.end()))<<" "<<*(max_element(v.begin(), v.end()));
    cout<<endl<<"4)";
    cout<<accumulate(v.begin(), v.end(), 0);//求和，0为初始值
    cout<<endl<<"5";
    for_each(v.begin(),v.end(),outputSquare);
    vector<int> cubes(SIZE);
    transform(a1, a1+SIZE, cubes.begin(), calculateCube);
    cout<<endl<<"6)";
    copy(cubes.begin(),cubes.end(),output);
    return 0;
}
