#ifndef IDENTITY_HPP
#define IDENTITY_HPP

/**
 * \brief Class that creates an identity matrix
 * implements an identity matrix based on a number
 * (the number of ones on the diagonal)
 */

#include <vector>
#include "Matrix.hpp"
/**
 * \brief namespace pp containing the matrix class
 * 
 */
namespace pp {

using std::vector;

template<typename T>
class Identity : public Matrix<T> {
public:
    /**
     * \brief Default constructor
     * 
     * passes a number representing 
     * a 1x1 identity matrix to the base class constructor
     */
    Identity() : Matrix<T>(vector<vector<T>>{{1}}){}
    /**
     * \brief parametrized constructor
     * 
     * From a number I give it, it generates an identity matrix 
     * with a given number of ones on the diagonal. 
     * The matrix is ​​created using the create helper function.
     * 
     * \param n number of ones
     */
    Identity(int n) : Matrix<T>(create(n)){}
private:
    /**
     * \brief create function 
     * Creates an identity matrix using the given number 
     * of ones on the diagonal and a new matrix m declared 
     * there, which is an object passed to the base constructor.
     * 
     */
    static Matrix<T> create(int n){
        vector<vector<T>> m;

        for(int i=0; i<n; i++){
            vector<T> row;
            for(int j=0; j<n; j++){
                if(i==j){
                    row.push_back(1);
                }else{
                    row.push_back(0);
                }//if
            }//for j
            m.push_back(row);
        }//for i
        return Matrix<T>(m);
    }//void
};

} // namespace pp

#endif
