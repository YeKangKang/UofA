//function to 1-1

int sum_array(int array[],int n){
	
	int answer = 0;

	if(n>=1){
		for(int i=0;i<n;i++){
			answer += array[i];
		}
	}
	return answer;
}
