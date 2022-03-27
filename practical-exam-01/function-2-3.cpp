extern bool is_a_palindrome(int*, int);
extern int sum_elements(int*, int);

int sum_if_a_palindrome(int integers[], int length){
	int result = -2;

	if(length <= 0){
		return -1;
	}else if(is_a_palindrome(integers,length)){
		result = sum_elements(integers,length);
	}

	return result;
}

bool is_a_palindrome(int integers[], int length){
	if(length <= 0){
		return false;
	}

	int check = length / 2;

	for(int i=0; i<check; i++){
		if(integers[i] != integers[length-i-1]){
			return false;
		}
	}

	return true;
}

int sum_elements(int integers[], int length){
	if(length <= 0){
		return -1;
	}

	int sum = 0;

	for(int i=0; i<length; i++){
		sum += integers[i];
	}

	return sum;
}