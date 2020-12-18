#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
void setVector(ifstream& in);

void modifyVector();
void initPage();
void nextPage();
void prevPage();
void thisPage();
bool input_task();
void saveFile();
bool insert(int a, int b, string s);
bool word_delete(int a, int b);
bool change(string a, string b);
bool search(string a);

int END_SIZE;				//끝 size저장
int ONE_PAGE_PREV = -1500; //-20*75
int LINE = 1;				//현제 페이지 시작 line
int READ_SIZE = 75;
bool print_macro = true;
vector<string> v;
vector<string>::iterator iter;
int i;
void printTelling() {
	cout << "시작 line :" << LINE << endl;

}

int main() {
	ifstream in("test.txt");
	setVector(in);
	//cout <<v[2] << endl;	//라인 3이 출력됨
	in.close();

	initPage();
	while (input_task());

}

bool input_task() {	//입력 프롬프트에서 수행하고자 하는 작업 입력 처리
	if (print_macro) {
		cout << "----------------------------------------------------------------------------------" << endl;
		cout << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료" << endl;
		//printTelling();
	}
	print_macro = true;
	string input_s;

	string word;
	string change_str[2];
	string str_temp;
	getline(cin, input_s);	//한줄 입력받기
	//cin >> input_s;
	char keyword = (char)input_s[0];
	int index = 0;
	int array[2] = { -1, -1 };
	bool flag = true;
	//cout << "LINE position : " << LINE << endl;

	switch (keyword)
	{
	case 'n':	//다음페이지
		if (input_s.size() != 1) {
			cout << "잘못된 입력입니다. " << endl;
			break;
		}
		if (LINE + 19 == (int)v.size()) {
			cout << "This is final page!" << endl;
			break;
		}
		nextPage();
		thisPage();
		break;
	case 'p':	//이전페이지
		if (input_s.size() != 1) {
			cout << "잘못된 입력입니다. " << endl;
			break;
		}
		if (LINE <= 1) {
			cout << "This is first page!" << endl;
			break;
		}
		prevPage();
		thisPage();
		break;
	case 'i':	//삽입
		index = 0;
		cout << input_s.length() << endl;
		if (input_s[1] != '(' || input_s[input_s.length() - 1] != ')') {
			//명령어 다음 입력값과 마지막 입력값은 괄호여야한다.
			cout << "괄호를 잘못입력하셨습니다. 다시 입력해주세요" << endl;
			break;
		}
		//괄호 안에 공백을 입력하면 입력오류
		for (int i = 2; i < input_s.length() - 1; i++) {
			if (input_s[i] == ' ') {
				cout << "괄호안에 공백을 입력하셨습니다. 다시입력해주세요" << endl;
				flag = false;
				break;
			}
		}
		if (flag == false) {
			break;
		}
		for (int i = 2, temp = 0; i < input_s.length() - 1; i++) {
			if (input_s[i] == ',') {
				array[index] = temp;
				index++;
				temp = 0;
				continue;
			}
			else if (index == 2) {
				word = word + input_s[i];
				continue;
			}
			else {
				if ('0' > input_s[i] || '9' < input_s[i]) {
					//숫자부분에 숫자가 아닌 부분을 입력
					//cout << "index : " << index << "input :" << input_s[i];
					cout << " 숫자가 아닌것을 입력하였습니다. 다시 입력 해주세요" << endl;
					flag = false;
					break;
				}
				temp = temp * 10 + (input_s[i] - '0');	//int로 변환하여 더한다. 
														//일의자리수가 아닐 경우
			}
		}
		if (flag == false) {
			//숫자가 아닌 부분을 입력, 출력은 위에서 한다. 
			break;
		}
		if (array[0] <= 0 || array[1] <= 0) {
			//숫자가 입력되지 않은것
			cout << "추가할 라인 또는 단어 index를 입력하지 않았습니다. 다시 입력해 주세요." << endl;
			break;
		}
		if (index != 2) {
			//쉼표 두개가 입력이 되지 않은것
			cout << "형식에 맞지 않게 입력하셨습니다. 다시 입력해 주세요." << endl;
			break;
		}
		if (word.size() == 0) {
			cout << "추가할 단어를 입력하지 않았습니다. 다시 입력해 주세요." << endl;
			break;
		}
		if (word.size() >= 75) {
			//75바이트 이상 출력 불가능, 다시 입력 요구
			cout << "75byte 이상 출력이 불가능 합니다. 다시 입력 해주세요" << endl;
			break;
		}
		if (array[0] < LINE || array[0] >= LINE + 20) {
			cout << "현재 페이지에 존재하지 않는 line입니다. 다시입력해 주세요." << endl;
			break;
		}
		if (!insert(array[0], array[1], word)) {//원하는 단어가 존재하지 않은 경우

			break;
		}
		modifyVector();
		thisPage();
		break;
	case 'd':
		index = 0;
		/*******************************************************************************/
		if (input_s[1] != '(' || input_s[input_s.length() - 1] != ')') {
			//명령어 다음 입력값과 마지막 입력값은 괄호여야한다.
			cout << "괄호를 잘못입력하셨습니다. 다시 입력해주세요" << endl;
			break;
		}
		//괄호 안에 공백을 입력하면 입력오류
		for (int i = 2; i < input_s.length() - 1; i++) {
			if (input_s[i] == ' ') {
				cout << "괄호안에 공백을 입력하셨습니다. 다시입력해주세요" << endl;
				flag = false;
				break;
			}
		}
		if (flag == false) {
			break;
		}
		/*******************************************************************************/
		for (int i = 2, temp = 0; i < input_s.length() && index < 2; i++) {
			if (input_s[i] == ',') {
				if (index >= 1) {	//쉼표가 두번이상 입력된것
					cout << "쉼표가 두번이상 입력되었습니다. 다시 입력해주세요." << endl;
					flag = false;
					break;
				}
				array[0] = temp;
				index++;
				temp = 0;
			}
			else if (input_s[i] == ')') {
				array[1] = temp;
				index++;
			}
			else {
				if ('0' > input_s[i] || '9' < input_s[i]) {
					//숫자부분에 숫자가 아닌 부분을 입력
					cout << " 숫자가 아닌것을 입력하였습니다. 다시 입력 해주세요" << endl;
					flag = false;
					break;
				}
				temp = temp * 10 + (input_s[i] - '0');	//int로 변환하여 더한다. 
			}
		}
		/*******************************************************************************/
		if (flag == false) {
			break;
		}
		if (array[0] <= 0 || array[1] <= 0) {
			//숫자가 입력되지 않은것
			cout << "추가할 라인 또는 단어 index를 입력하지 않았습니다. 다시 입력해 주세요." << endl;
			break;
		}
		if (index != 2) {
			cout << "형식에 맞지 않게 입력하셨습니다. 다시 입력해 주세요." << endl;
			break;
		}
		if (array[0] < LINE || array[0] >= LINE + 20) {
			//현재 출력창에 존재하지 않음
			cout << "삭제하려는 라인이 현재 창에 존재하지 않습니다. " << endl;
			break;
		}
		/*******************************************************************************/
		if (!word_delete(array[0], array[1])) {	//원하는 단어가 존재하지 않을 경우
			break;
		}
		modifyVector();
		thisPage();
		break;
	case 'c':

		/*******************************************************************************/
		if (input_s[1] != '(' || input_s[input_s.length() - 1] != ')') {
			//명령어 다음 입력값과 마지막 입력값은 괄호여야한다.
			cout << "괄호를 잘못입력하셨습니다. 다시 입력해주세요" << endl;
			break;
		}
		//괄호 안에 공백을 입력하면 입력오류
		for (int i = 2; i < input_s.length() - 1; i++) {
			if (input_s[i] == ' ') {
				cout << "괄호안에 공백을 입력하셨습니다. 다시입력해주세요" << endl;
				flag = false;
				break;
			}
		}
		if (flag == false) {
			break;
		}
		/*******************************************************************************/
		for (int i = 2; i < input_s.length(); i++) {
			if (input_s[i] == ',') {
				change_str[0] = str_temp;
				str_temp = "";
			}
			else if (input_s[i] == ')') {
				change_str[1] = str_temp;
			}
			else {
				str_temp += input_s[i];
			}
		}
		if (change_str[0].size() == 0 || change_str[1].size() == 0) {	//하나도 인자가 입력이 제대로 되지 안았으면 ""일것이다. 
			cout << "형식에 맞는 입력값이 아닙니다. 다시 입력해 주세요." << endl;
			break;
		}
		if (!change(change_str[0], change_str[1])) {
			break;
		}
		modifyVector();
		thisPage();
		break;
	case 's':
		/*******************************************************************************/
		if (input_s[1] != '(' || input_s[input_s.length() - 1] != ')') {
			//명령어 다음 입력값과 마지막 입력값은 괄호여야한다.
			cout << "괄호를 잘못입력하셨습니다. 다시 입력해주세요" << endl;
			break;
		}
		//괄호 안에 공백을 입력하면 입력오류
		for (int i = 2; i < input_s.length() - 1; i++) {
			if (input_s[i] == ' ') {
				cout << "괄호안에 공백을 입력하셨습니다. 다시입력해주세요" << endl;
				flag = false;
				break;
			}
		}
		if (flag == false) {
			break;
		}
		/*******************************************************************************/
		str_temp = input_s.substr(2, input_s.length() - 3);
		//cout << str_temp << endl;
		if (!search(str_temp + " ")) {
			cout << "찾는 문자가 존재하지 않습니다. 다시입력해주세요" << endl;
			break;
		}
		//찾는 문자가 존재하면
		thisPage();
		break;
	case 't':	//저장후 종료
		saveFile();
		cout << "변경내용을 파일에 저장하였습니다. 프로그램을 종료합니다." << endl;
		return false;
		break;
	default:
		if (input_s == "") {
			//아무것도 입력하지 않고 엔터키 누른것
			print_macro = false;
			break;
		}
		cout << "존재하지 입력을 입력하셨습니다. 다시 입력해주세요" << endl;
		break;
	}
	return true;

}
void saveFile() {
	ofstream out("test1.txt");
	for (int i = 0; i < v.size(); i++) {
		out << v[i];
	}
	out.close();
}
bool search(string search_word) {
	string str;
	int line = 1;
	int end_temp = 0;
	int temp = 0;
	for (int i = 0; i < v.size(); i++) {
		//반환값이 string::npos이면 찾는 문자가 없는것이다. 
		str = v[i];
		if (str.find(search_word) != string::npos) {
			//문자를 찾은것
			LINE = i + 1;
			return true;
		}
	}
	return false;
}
bool change(string prev_str, string modify_str) {
	//cout << "prev_str : " << prev_str << endl;
	int count = 0;
	//cout << "modify_str : " << modify_str << endl;
	for (int i = 0; i < v.size(); i++) {
		string str;
		string stringBuffer;
		istringstream ss(v[i]);
		while (getline(ss, stringBuffer, ' ')) {
			if (stringBuffer == prev_str) {
				str += modify_str + " ";
				count++;
				continue;
			}
			else {
				str += stringBuffer + " ";
			}
		}
		v[i] = str;
	}
	if (count == 0) {
		//바꾸려고 하였던 문자가 존재하지 않은것
		cout << "변경할 문자가 존재하지 않습니다. 다시입력해주세요." << endl;
		return false;
	}
	return true;

}
bool word_delete(int line_position, int word_position) {
	cout << "line_position : " << line_position << "word_position : " << word_position << endl;
	//string s = ;
	string str;
	string stringBuffer;
	istringstream ss(v[line_position - 1]);
	for (int i = 1; getline(ss, stringBuffer, ' '); i++) {
		//int t = stringBuffer.size();
		if (i == word_position) {
			continue;
		}
		else {
			str += stringBuffer + " ";
		}
	}
	if (i <= word_position) {	//현재 라인에 원하는 단어가 존재하지 않는 경우
		cout << line_position << "에는 " << word_position << "번째 단어가 존재하지 않습니다. 다시 입력해주세요." << endl;
		return false;
	}
	v[line_position - 1] = str;
	return true;
}
bool insert(int line_position, int word_position, string insert_word) {
	//cout << "line_position : " << line_position << "word_position : " << word_position << endl;
	int temp = 0;
	int line = 1;
	int count = 1;
	string s = v[line_position - 1];
	string str;
	string stringBuffer;
	istringstream ss(s);
	int i = 1;
	for (; getline(ss, stringBuffer, ' '); i++) {
		if (i == word_position) {
			str += stringBuffer + " " + insert_word + " ";
		}
		else {
			str += stringBuffer + " ";
		}
	}
	if (i <= word_position) {	//현재 라인에 원하는 단어가 존재하지 않는 경우
		cout << line_position << "에는 " << word_position << "번째 단어가 존재하지 않습니다. 다시 입력해주세요." << endl;
		return false;
	}
	v[line_position - 1] = str;
	return true;
}
void nextPage() {
	LINE += 20;

	if (v.size() < LINE + 20) {
		LINE = (int)v.size() - 19;
	}
}
void prevPage() {
	LINE -= 20;
	if (LINE <= 0) {
		LINE = 1;
	}
}
void thisPage() {
	int temp = 0;
	int end_temp = 0;
	int line = 1;
	string str;	//str 초기화
	int count = 1;

	for (i = LINE; i < LINE + 20 && v.size(); i++) {
		cout << i << " | " << v[i - 1] << endl;
	}
}
void initPage() {
	LINE = 1;
	thisPage();
}
void setVector(ifstream& in) {
	string s, str;
	int size = 0;
	int temp = 0;
	int i = 0;
	while (!in.eof()) {
		in >> s;
		size = (int)s.size();
		if (size + temp <= 75) {
			str += s + " ";
			temp += size + 1;
		}
		else {
			i++;
			//cout << i<< " | str: " << str << endl;
			v.push_back(str);
			str = s + " ";
			temp = size + 1;
		}
	}
	if (in.eof()) {
		v.push_back(str);
	}
}
void modifyVector() {
	string s, str;
	//한 문자열로 합쳐준다.
	for (int i = 0; i < v.size(); i++) {
		s += v[i];
	}
	v.clear();
	int size = 0;
	int temp = 0;
	int i = 0;
	string stringBuffer;
	istringstream ss(s);
	while (getline(ss, stringBuffer, ' ')) {
		size = (int)stringBuffer.size();
		if (size + temp <= 75) {
			str += stringBuffer + " ";
			temp += size + 1;
		}
		else {
			v.push_back(str);
			str = stringBuffer + " ";
			temp = size + 1;
		}
	}
	v.push_back(str);
}