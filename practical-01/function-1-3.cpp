// function to 1-3

int count(int array[], int n, int number){
	int count = 0;

	if(n>=1){
		for(int i=0; i<n; i++){
			if(array[i]==number){
				count += 1;
			}
		}
	}
	
	return count;
}