int diagonal(int array[4][4]){

	int count = 0;

	for(int a=0; a<4; a++){
		for(int b=0; b<4; b++){
			if(a==b){
				count += array[a][b];
			}
		}
	}

	return count;
}