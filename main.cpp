#include <armadillo>
#include <iostream>
#include "main.h"


int main(){
	vec a = {1,2,3};
	vec b = {4,5,6};
	vec c = {7,8,9};
	vector<vec> vecteurs = {a,b,c};
	cout << diameter(vecteurs);
}

double diameter(vector<vec> vecteurs){

	// Compute the diameter of a set of points
	// Complexity is d*n*n ; it is not optimal.

	double distance = 0.0;
	for(vec n : vecteurs){
		for(vec m : vecteurs){
			distance = max(distance,norm(n-m));
		}
	}
	return distance;
}

vector<vec> randRotation(vector<vec> vecteurs_in){

	// Generate random orthogonal matrix

	// Apply it to the points
	vector<vec> vecteurs_out;

	return vecteurs_out;
}