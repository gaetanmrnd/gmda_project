#include <armadillo>
// Bibliothèque d'algèbre linéaire. Doc ici : http://arma.sourceforge.net/docs.html
// Pour compiler : g++ -std=c++11 main.cpp -o main -O2 -larmadillo


#include <iostream>
#include "main.h"

const int n = 3; // Dimension de l'espace

int main(){

	arma_rng::set_seed_random(); // Initialisation du générateur aléatoire

	vec a = randu<vec>(n);
	vec b = randu<vec>(n);
	vec c = randu<vec>(n);
	vector<vec> vecteurs = {a,b,c};
	
	cout << "Diamètre avant rotation : " << diameter(vecteurs) << "\n";
	cout << "Diamètre après rotation : "  << diameter(randRotation(vecteurs)) << "\n";
}

double diameter(vector<vec> vecteurs){

	// Compute the diameter of a set of points
	// Complexity is d*n*n ; it is not optimal.

	double distance = 0.0;
	for(vec x : vecteurs){
		for(vec y : vecteurs){
			distance = max(distance,norm(x-y));
		}
	}
	return distance;
}

vector<vec> randRotation(vector<vec> vecteurs_in){

	// Generate random orthogonal matrix
	// Source : https://en.wikipedia.org/wiki/Orthogonal_matrix#Randomization

	mat M = mat(1,1,fill::ones);

	for(int i = 1; i < n; i++){

		// On prend un vecteur unitaire aléatoire (uniforme) et on calcule la transformation de Householder
		vec  v = normalise(randu<vec>(i + 1));
		mat P = mat(i + 1,i + 1,fill::eye) - 2*v*trans(v);

		M.insert_rows(i,1);
		M.insert_cols(i,1);
		M(i,i) = 1;
		M = P*M;
	}

	// Apply it to the points

	vector<vec> vecteurs_out;

	for(vec v : vecteurs_in){
		vecteurs_out.push_back(M*v);
	}

	return vecteurs_out;
}