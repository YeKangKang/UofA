#include <iostream>
using namespace std;

int *readNumbers(int n){
	int *numbers = new int[n];
	for(int i=0; i<n; i++){
		cin >> *(numbers+i);
	}

	return numbers;
}

void printSubArrays(int *numbers,int length){

	//第一个for决定了几大组可能的分组；
	//这个第二个for决定了重做多少遍“打印从给定开始到结尾的数字”
	//最后一个for只做打印步骤

	for (int i=0; i<length; i++){		/*第一个i控制着开始的位置*/

		for(int j=i; j<length; j++){			/*这个loop控制着每一row的col个数
												和结束的位置，loop从给定开头一直到
												最后的结尾*/

			cout << "{";
			for(int k=i; k<j+1; k++){				/*这个loop只打印一次从给定开头到给定结尾*/
				cout << *(numbers+k);
			}
			cout << "}";


			cout << ", ";
		}
		cout << endl;
	}
	return;
}