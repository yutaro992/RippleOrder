#include <iostream>
#include <vector>

void RippleOrder( int n, int w, int h, std::vector<int>* array);
void view(int w, int h, int* state);
			
int main(int argc, char **argv){

	int width = 11;
	int height = 11;
	
	if(argc == 3){
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	}

	std::vector<int> array;
	int* image = new int[width * height]();
	
	array.push_back(0);

	for(int i=0;!array.empty();i++){
		array.clear();
		RippleOrder( i, width, height, &array);
		
		for(int j=0;j<array.size();j++){
			image[array.at(j)]= i;
		}
	}
	view(width,height,image);

}

void view(int w, int h, int* state){
         for(int i=0;i<h;i++){
               	for(int j=0;j<w;j++){
               		printf("%3d",state[i*w+j]);
		}
               	printf("\n");
         }
	printf("\n");
}

void RippleOrder( int n, int w, int h, std::vector<int>* array){

	int cx = (w ) /2;
	int cy = (h ) /2;
	
	int nx,ny,tx,ty;


	tx=nx=cx-n;
	ty=ny=cy;
	if( 0<=nx  && nx<w && 0<=ny && ny<h )array->push_back((ny)*w+(nx));


	
	while(nx<cx){
		nx++;
		ny--;
		if( 0<=nx  && nx<w && 0<=ny && ny<h )array->push_back((ny)*w+(nx));
	}

	while(ny<cy){
		nx++;
		ny++;
		if( 0<=nx  && nx<w && 0<=ny && ny<h )array->push_back((ny)*w+(nx));
	}

	while(nx>cx){
		nx--;
		ny++;
		if( 0<=nx  && nx<w && 0<=ny && ny<h )array->push_back((ny)*w+(nx));
	}

	while(ny>cy){
		nx--;
		ny--;
		if( 0<=nx  && nx<w && 0<=ny && ny<h )array->push_back((ny)*w+(nx));
	}

}
