extern int printer(int[10][10]);

int main(){
	int array[10][10];
	for(int a=0; a<10; a++){
		for(int b=0; b<10; b++){
			array[a][b] = 3;
		}
	}

	printer(array);

	return 0;
}
