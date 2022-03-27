// function to 1-2
double average(int array[],int n){
	
	double answer = 0.0;
	if(n >= 1){
		for(int i=0; i<n; i++){
			answer += array[i];
		}
	}
	answer = answer/n;

	return answer;
}