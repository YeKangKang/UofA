// function of 3-1


bool fanarray(int array[], int n){

	if(n>0){

		int a = n;

		if(a%2!=0){

			a = (a+1)/2;
			int min = array[0];

			for(int i = 1; i<a; i++){
				if(array[i]>min){
					min = array[i];
				}else{
					return false;
				}
			}
			for(int p = a; p<n; p++){
				if(array[p]<min){
					min = array[p];
				}else{
					return false;
				}
			}
			return true;
		}else if(a%2==0){
			a = a/2;
			int minimum = array[0];

			for(int d=1; d<a; d++){
				if(array[d]>minimum){
					minimum = array[d];
				}else{
					return false;
				}
			}
			if(array[a]==array[a-1]){
				for(int c=(a+1); c<n; c++){
					if(array[c]<minimum){
						minimum = array[c];
					}else{
						return false;
					}
				}
			}else{
				return false;
			}
		}else{
			return false;
		}

		return true;

	}else{
		return false;
	}
}