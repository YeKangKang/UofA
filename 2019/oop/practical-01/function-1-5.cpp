// function to 1-5

int count_even(int number){
	int count = 0;

	for(int i=number; i>0; i--){
		if(i%2==0){
			count += 1;
		}
	}

	return count;
}