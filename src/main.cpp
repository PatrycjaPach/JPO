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

    //geter and seter
    o2.setMatrix(1,2,80);
    try{
        o2.getMatrix(1,2);
    } catch(std::invalid_argument & e){
        e.what();
    }


    //wrong matrix addition
    try{
        pp::Matrix<int> o7=o3+o4;
    } catch(std::invalid_argument & e){
        e.what();
    }


    //good matrix addition
    try{
        pp::Matrix<int> o6=o2+o3;
    } catch(std::invalid_argument & e){
        e.what();
    }

    //matrix addition with += operator
    try{
        o2+=o3;
    } catch(std::invalid_argument & e){
        e.what();
    }

    //matrix substraction
    try{
        pp::Matrix<int> o6=o2-o3;
    } catch(std::invalid_argument & e){
        e.what();
    }

    //matrix substraction with -=
    try{
        o2-=o3;
    } catch(std::invalid_argument & e){
        e.what();
    }

    //multiplication *
    try{
        pp::Matrix<int> o6=o2*o3;
    } catch(std::invalid_argument & e){
        e.what();
    }

    //multiplication *=
    try{
        o2*=o3;
    } catch(std::invalid_argument & e){
        e.what();
    }

    //compromision and contraddiction
    (o2==o3);
    (o2!=o3);

    //miltiplication with scalar
    o4=o2*5;

    //scalar division
    o5=o5/5;

    //determinant
    try{
        o2.determinant();
    }catch(std::invalid_argument & e){
        e.what();
    }


    //transpoze
    o2=o2.transpose();

    /*OTHER MATRIX*/
    //diagonal
    pp::Diagonal<int> d(vector<int>{1,2,3});

    try{
        d.determinant();
    }catch(std::invalid_argument & e){
        e.what();
    }
    
    //determinant
    pp::Identity<int> i(6);


}