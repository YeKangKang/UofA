// function to 2-4

bool ascending(int array[], int n){


	if(n>0){
		
		int max = array[0];

		for(int i=1; i<n; i++){
			if(array[i]>=max){
				max = array[i];
			}else{
				return false;
			}
		}
		return true;
	}else{
		return false;
	}
	
}