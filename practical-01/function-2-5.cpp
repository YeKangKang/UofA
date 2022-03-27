// function to 2-5

bool descending(int array[], int n){

	if(n>0){

		int big=array[0];

		for(int i=1; i<n; i++){
		
			if(array[i]<=big){
				big=array[i];
			}else{
				return false;
			}
		}

		return true;
	
	}else{
		return false;
	}
}