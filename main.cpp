#include <iostream>
#include <stdexcept>

#include "Matrix.hpp"
#include "Diagonal.hpp"
#include "Identity.hpp"
using std::vector, std::cout, std::endl;

int main(){
    //vector declaration
    vector<vector<int>> m1 = {{1, 2},{},{2}};
    vector<vector<int>> m2 = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    vector<vector<int>> m3 = {{11, 22, 33},{44, 55, 66},{77, 88, 99}};
    vector<vector<int>> m4 = {{6, 5, 4},{3, 2, 1}};
    vector<vector<double>> m5 = {{6.0, 5.0, 4.0},{3.0, 2.0, 1.0}};
    
    //creating an object
    pp::Matrix<int> o1(m1); //err
    pp::Matrix<int> o2(m2); 
    pp::Matrix<int> o3(m3);
    pp::Matrix<int> o4(m4);
    pp::Matrix<double> o5(m5);
    cout<<endl;

    //geter and seter
    o2.setMatrix(1,2,80);
    try{
        cout<<o2.getMatrix(1,2)<<endl;
    } catch(std::invalid_argument const& e){
        cout<<e.what()<<endl;
    }
    cout<<endl;
    o2.read();
    cout<<endl;

    //wrong matrix addition
    try{
        pp::Matrix<int> o7=o3+o4;
        o7.read();
    } catch(std::invalid_argument const& ex){
        cout<<ex.what()<<endl;
    }
    cout<<endl;

    //good matrix addition
    try{
        pp::Matrix<int> o6=o2+o3;
        o6.read();
    } catch(std::invalid_argument const& ex){
        cout<<ex.what()<<endl;
    }
    cout<<endl;

    //matrix addition with += operator
    try{
        o2+=o3;
        o2.read();
    } catch(std::invalid_argument const& ex){
        cout<<ex.what()<<endl;
    }
    cout<<endl;

    //matrix substraction
    try{
        pp::Matrix<int> o6=o2-o3;
        o6.read();
    } catch(std::invalid_argument const& ex){
        cout<<ex.what()<<endl;
    }
    cout<<endl;

    //matrix substraction with -=
    try{
        o2-=o3;
        o2.read();
    } catch(std::invalid_argument const& ex){
        cout<<ex.what()<<endl;
    }
    cout<<endl;

    //multiplication *
    try{
        pp::Matrix<int> o6=o2*o3;
        o6.read();
    } catch(std::invalid_argument const& ex){
        cout<<ex.what()<<endl;
    }

    //multiplication *=
    try{
        o2*=o3;
        o2.read();
    } catch(std::invalid_argument const& ex){
        cout<<ex.what()<<endl;
    }
    cout<<endl;

    //compromision and contraddiction
    cout<<endl;
    cout<<(o2==o3)<<endl;
    cout<<(o2!=o3)<<endl;

    //miltiplication with scalar
    cout<<endl;
    o4=o2*5;
    o4.read();

    //scalar division
    cout<<endl;
    o5=o5/5;
    o5.read();
    cout<<endl;

    //determinant
    try{
        cout<<o2.determinant()<<endl;
    }catch(std::invalid_argument const& ex){
        cout<<ex.what()<<endl;
    }
    cout<<endl;

    //transpoze
    o2.read();
    o2=o2.transpose();
    cout<<endl;
    o2.read();

    cout<<endl;
    /*OTHER MATRIX*/
    //diagonal
    pp::Diagonal<int> d(vector<int>{1,2,3});
    d.read();
    cout<<endl;
    try{
        cout<<d.determinant()<<endl;
    }catch(std::invalid_argument const& ex){
        cout<<ex.what()<<endl;
    }
    
    //determinant
    cout<<endl;
    pp::Identity<int> i(6);
    i.read();


}