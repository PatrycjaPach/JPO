#include <iostream>
#include <vector>
using std::vector, std::endl, std::cout;
int main(){

    vector<vector<int>> matrix={
        {1,2,3},
        {5,6,7}
    };

    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}