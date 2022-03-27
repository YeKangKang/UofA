// function to 1-4

int sumtwo(int array[], int secondarray[], int n){

	int result = 0;
	if(n>=1){
		for(int i=0; i<n; i++){
			result += array[i]+secondarray[i];
		}
	}
	return result;
}