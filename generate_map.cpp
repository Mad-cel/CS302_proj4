#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]) {

	if(argc != 2) {
		cerr << "use case: ./generate_map int" << endl;

	}

	else {
		srand(time(NULL));
		int random;
		int randcell;
		int N = atoi(argv[1]);
		ofstream gen_map("gen_map.txt");
		char vals[] = {'f', 'g', 'G', 'h', 'm', 'r'};
		char arr[N*N];

		for(int i = 0; i < N*N; i++) { //generate map
			random = rand() % 5 + 1;
			arr[i] = vals[random];
		}

		if(gen_map.is_open()) {
			gen_map << "6" << endl;
			gen_map << "f 3" << endl;
			gen_map << "g 1" << endl;
			gen_map << "G 2" << endl;
			gen_map << "h 4" << endl;
			gen_map << "m 7" << endl;
			gen_map << "r 5" << endl;
			gen_map << N << " " << N << endl;
			
			for(int i = 0; i < N*N; i++) {
				if(i%N < N-1){
					gen_map << arr[i] << " ";
				}

				else {
					gen_map << arr[i] << endl;
				}
			}
			randcell = rand() % (N*N + 1);
			gen_map << "0 0" << endl;
			gen_map << (randcell % N) << " " << (randcell / N) << endl;

		}

		else{
			cerr << "unable to open gen_map.txt" << endl;
			return 0;
		}


	}



}
