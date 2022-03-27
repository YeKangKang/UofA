extern int sum_elements(int*,int);
extern bool is_a_palindrome(int*,int);

int sum_if_a_palindrome(int integers[], int length){
	int final_sum = sum_elements(integers, length);
	if(length<=0){
		return -1;
	}else{
		if(is_a_palindrome(integers, length)){
			return final_sum;
		}else{
			return -2;
		}
	}
}

bool is_a_palindrome(int integers[], int length){

	int a = length/2;

	for(int i=0; i<a; i++){
		if(integers[i]!=integers[length-i-1]){
			return false;
		}
	}

	return true;
}

int sum_elements(int integers[], int length){
	int sum = 0;

	for(int i=0; i<length; i++){
		sum += integers[i];
	}

	return sum;
}