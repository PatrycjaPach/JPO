#ifndef DIAGONAL_HPP
#define DIAGONAL_HPP

/**
 * \brief Class that creates a diagonal matrix.
 *
 * Implements a diagonal matrix using a vector of values.
 * The values from the vector are placed on the main diagonal.
 */
#include <vector>
#include "Matrix.hpp"  

namespace pp{
using std::vector;
template<typename T>
class Diagonal : public Matrix<T> {
public:
   /**
     * \brief Default constructor
     *
     * Creates a 1x1 diagonal matrix with value 0
     * and passes it to the base class constructor.
     */

    Diagonal() : Matrix<T>(vector<vector<T>>{{0}}) {}

    /**
     * \brief Parametrized constructor
     *
     * Creates a diagonal matrix based on the given vector.
     * The size of the matrix is equal to the length of the vector.
     * The matrix is created using the create helper function.
     *
     * \param val Vector containing values placed on the diagonal.
     */

    Diagonal (const vector<T>& val): Matrix<T>(create(val)){
    }

private:
    /**
     * \brief Create function
     *
     * Creates a diagonal matrix using the given vector of values.
     * Values from the vector are placed on the main diagonal.
     * All other elements are set to 0. The created matrix is then
     * passed to the base class constructor.
     *
     * \param v Vector containing values for the diagonal.
     */
    static Matrix<T> create(const vector<T>& v){
        int n=v.size();
        vector<vector<T>> m;

        for(int i=0; i<n; i++){
            vector<T> row;
            for(int j=0; j<n; j++){
                if(i==j){
                    row.push_back(v[i]);
                } else{
                    row.push_back(0);
                } //if
            }//for j
            m.push_back(row);
        }//for i
        return Matrix<T>(m);
    }//void

}; //class

} //namespace
#endif

