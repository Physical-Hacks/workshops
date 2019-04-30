#include <iostream>
#include <armadillo>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;
using namespace arma;

/*
 * Armadillo tutorials/code samples. 
 * http://arma.sourceforge.net/docs.html#zeros_member
 */
int main() {

    /******************************
     * 2D matrix operations.
     ******************************/

    // Demonstrates different ways to
    // create a 5x10 matrix and set values to zero.
    mat zero_matrix(5, 10); 
    zero_matrix.zeros(); 
    cout<<"A 5x10 zero matrix:"<<endl<<zero_matrix<<endl;
    
    // An alternative way to set matrices to zero.
    mat zero_matrix1;
    zero_matrix1.zeros(10, 20);
    cout<<"A 10x20 zero matrix:"<<endl<<zero_matrix1<<endl;

    // Sets all elements to random values
	mat A = randu<mat>(4, 5);
    cout<<"Random values:"<<endl<<A<<endl;

    // Fills the desired vector with a particular value.
    mat custom_vals(4, 5);
    custom_vals.fill(155.0);
    cout<<"4x5 matrix filled with the double 155.0"<<endl<<custom_vals<<endl;

    // Determinant of a 4x4 matrix
    mat dm = randu<mat>(4, 4);
    double d = det(dm);
    cout<<"Det("<<endl<<dm<<")"<<endl;
    cout<<"Determinant of a 4x4 matrix: "<<d<<endl;

    
    /***********************************
     * lambda function with transform
     ***********************************/
    A = ones<mat>(4, 5);

    // add 123 to each element
    // A.transform( [](double val) { return (val + 123.0); } );



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
    cout<<string_success<<endl;

    // Save the file in arma_ascii format
    // Not working at the moment
    // cout<<"Saving the randomly generated matrix as an arma_ascii file...arma_ascii_f.txt\n";
    // f.save("arma_ascii_f.txt". arma_ascii); // This is not working.
    
    // Not working at the moment
    // Saving as HDF5 format with an internal dataset called "my data"
    // cout<<"Saving the randomly generated matrix as an hdf5 file...\n";
    // f.save(hdf5_name("f_hdf5.h5", "my_data"));

    // Loading files
    cout<<"Loading and printing all the saved files...\n";
    mat load_matrix;
    cout<<"Loading arma_bin_f.bin\n";
    load_matrix.load("arma_bin_f.bin");
    cout<<"Loaded matrix:\n"<<load_matrix<<endl<<endl;

    cout<<"FileIO complete\n\n";



	return 0; 
}



