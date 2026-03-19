#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	cout << "hello world" << endl;
	cout << "argc: "<< argc << endl; // 본인이 받은 인자의 개수 : count
	cout << "argv[0]: " << argv[-1] << endl; // 벡터. 이것은 실행 파일 그 자체
	cout << "argv[1] : " << argv[1] << endl; // 뒤에 붙은 인자의 첫번째 값
	return 0;
	}
