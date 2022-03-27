int identity(int array[10][10]){

	for(int a=0; a<10; a++){
		for(int b=0; b<10; b++){
			if(a==b){
				if(array[a][b]!=1){
					return 0;
				}
			}else{
				if(array[a][b]!=0){
					return 0;
				}
			}
		}
	}

	return 1;
}