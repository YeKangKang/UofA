// function to 2-2

int maximum(int array[], int n){
	int maximum = 0;

	if(n>=1){
		maximum = array[1];
		for(int i=1; i<n; i++){
			if(array[i]>=maximum){
				maximum = array[i];
			}
		}
	}

	return maximum;
}