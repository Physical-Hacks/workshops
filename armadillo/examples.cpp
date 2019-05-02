// compile with g++ -o examples examples.cpp -l armadillo -std=c++11

#include <iostream>
#include <armadillo>
#include <string>

using namespace std;
using namespace arma;

/*
 * Armadillo tutorials/code samples. 
 * http://arma.sourceforge.net/docs.html#zeros_member
 */
int main() {

    // Demonstrates different ways to
    // create a 5x10 matrix and set values to zero.
    mat zero_matrix(5, 10);
    zero_matrix.zeros(); 
    cout << "A 5x10 zero matrix:" << endl << zero_matrix << endl;
    
    // An alternative way to set matrices to zero.
    mat zero_matrix1(10, 20, fill::zeros);
    cout << "A 10x20 zero matrix:" << endl << zero_matrix1 << endl;

    // Sets all elements to uniformly distributed random values
	mat A = randu<mat>(4, 5);
    cout << "Random values:" << endl << A << endl;

    // Fills the desired vector with a particular value.
    mat custom_vals(4, 5);
    custom_vals.fill(155.0);    
    cout<<"4x5 matrix filled with the double 155.0" << endl << custom_vals<<endl;

    // Determinant of a 4x4 matrix
    mat dm = randu<mat>(4, 4);
    double d = det(dm);
    cout << "Det(" << endl << dm << ")" << endl;
    cout << "Determinant of a 4x4 matrix: " << d << endl;

    /*******************************
     * FileIO
     *******************************/
    // Demonstrates FileIO capabilities in Armadillo.
    // http://arma.sourceforge.net/docs.html#save_load_mat 
    // All FileIO functions are members of of the Mat, Col, Row, and Cube classes.
    // On success, .save() and .load() return a boolean set to true.
    // The arma_x file types have a header that helps speed up loading.
   
    mat f = randu<mat>(5, 5);
    bool save_success;

    // Save the file in arma_binary format
    cout<<"\nSaving randoly generated matrix as an arma_bin...arma_bin_f.bin\n";
    save_success = f.save("./arma_bin_f.bin");
    string string_success = save_success ? "Save success\n" : "Save unsuccessful\n";
    cout << string_success << endl;
   
    // Loading files
    cout << "Loading and printing all the saved files...\n";
    mat load_matrix;
    cout << "Loading arma_bin_f.bin\n";
    load_matrix.load("arma_bin_f.bin");
    cout << "Loaded matrix:\n" << load_matrix << endl << endl;

    cout<<"FileIO complete\n\n";

    rowvec rand_vec = randu<rowvec>(5);
    cout << "rand_vec: " << rand_vec << endl << endl;
    // Print out the vector, but sorted.
    cout << "rand_vec sorted: " << sort(rand_vec) << endl << endl;

    // Create a second random vector, and sort it according to the indices
    // of the sorted rand_vec.
    rowvec rand_vec2 = randu<rowvec>(5);
    cout << "rand_vec2: " << rand_vec2 << endl << endl;
    cout << "rand_vec2 sorted according to rand_vec order: "
         << rand_vec2(sort_index(rand_vec)).t() << endl << endl;

    // Solve a simple eigensystem.
    mat sigma_z = {{0.0, 1.0}, {1.0, 0.0}};
    vec eigvals;
    mat eigvecs;
    eig_sym(eigvals, eigvecs, sigma_z);
    cout << "The eigenvalues of sigma_z are " << eigvals(0) << " and "
         << eigvals(1) << "." << endl << endl;
    cout << "The eigenvectors of sigma_z are " << endl << eigvecs.col(0).t() << endl
         << "and" << endl << eigvecs.col(1).t() << endl;

    // Submatrix views
    mat M = {{0.0, 1.0, 2.0},
             {3.0, 4.0, 5.0},
             {6.0, 7.0, 8.0}};
    cout << "The second row of M is: " << M.row(1) << endl << endl;
    cout << "The third column of M is: " << endl <<  M.col(2) << endl << endl;
    cout << "The second and third columns of the first and second rows of M : " << endl
         <<  M(span(0, 1), span(1, 2)) << endl << endl;
    // NON-contiguous submatrices
    uvec row_ind = {0, 2};
    uvec col_ind = {0, 1};
    cout << "The first and second columns of the first and third rows of M: "  << endl
         << M.submat(row_ind, col_ind) << endl << endl;

	return 0; 
}


