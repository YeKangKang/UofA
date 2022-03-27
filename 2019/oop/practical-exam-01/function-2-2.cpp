int binary_to_number(int binary_digits[], int number_of_digits){

	int sum = 0;
	
	for(int i=0; i<number_of_digits; i++){
		sum = sum*2 + binary_digits[i];
	}

	return sum;
}