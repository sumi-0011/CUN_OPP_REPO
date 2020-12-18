#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void initPage(std::ifstream& in);
void nextPage(std::ifstream& in);
void prevPage(std::ifstream& in);
void inputWord(std::ifstream& in,int a,int b,string word);
//in.seekg(0, std::ios::end); // 위치 지정자를 파일 끝으로 옮긴다.
//int size = in.tellg();// 그리고 그 위치를 읽는다. (파일의 크기)
//s.resize(size); // 그 크기의 문자열을 할당한다.
//in.seekg(0, std::ios::beg);// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
//in.read(&s[0], 75);// 파일 전체 내용을 읽어서 문자열에 저장한다.
int END_SIZE;
int ONE_PAGE_BEG  = -1500; //-20*75
int LINE = 1;
int main() {
	ifstream in("test1.txt");  //파일을 읽기 위함
    
    string line;
    string s;
    if (in.is_open())
    {
        in.seekg(0, std::ios::end);
         END_SIZE=(int) in.tellg();
         in.seekg(0, std::ios::beg);
        initPage(in);
        
       
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후 종료" << endl;
        /*nextPage(in);*/
        /*inputWord(in, 2, 2, "hello\n");*/
        nextPage(in);
        
        cout << LINE;
        cout << "----------------------------------------------------------------------------------" << endl;
        nextPage(in);
        cout << "----------------------------------------------------------------------------------" << endl;
        cout << "prev";
        prevPage(in);
/*
       
        cout << "----------------------------------------------------------------------------------" << endl;
        prevPage(in);
        cout << "----------------------------------------------------------------------------------" << endl;
        */prevPage(in);
        cout << "----------------------------------------------------------------------------------" << endl;

        prevPage(in);
    }  
    in.close();
    return 0;
}
void initPage(std::ifstream& in) {
    in.seekg(0, ios::beg);
    char x[100];
    int cur_line = LINE;
    for(int i=0;i<20 && (!in.eof());i++, cur_line++){
        in.read(x, 75);
        x[76] = '\0';
        cout << cur_line << " | " << x << '\n';    //지금은 읽은 문자열 바로 출력.
    }
    in.seekg(ONE_PAGE_BEG, ios::cur);
}
void nextPage(std::ifstream& in) {
    //현재 페이지가 21이면 /20 하면 1이므로 다음페이지는 2페이지다.  
    //시작은 21line부터 -> 20 *(n-1) +1;
    in.seekg(75 * 20, ios::cur);
    char x[100];
    int read_size=75;
    int cur_size = in.tellg();
    if(LINE*75 <= END_SIZE()) {
}
    int cur_line = LINE:
    for (int i = 0; i < 20 && (!in.eof()); i++, cur_line++)
    {
       if (cur_size + 75 > END_SIZE) {
            read_size = END_SIZE - cur_size;
            cout << "read_size: " << read_size << endl;
            in.read(x, read_size);
            x[read_size+1] = '\0';
            cout << cur_line << " | " << x << '\n';    //지금은 읽은 문자열 바로 출력.
            break;
        }
        in.read(x, read_size);
        x[76] = '\0';
        cout << cur_line << " | " << x << '\n';    //지금은 읽은 문자열 바로 출력.
       
        cur_size += 75;
    }
    if (in.eof()) {
        cout << "끝"<< '\n';
    }
    else {
        cout << "no" << '\n';
    }
    cout << "cur_line" <<cur_line << '\n';
    in.seekg(ONE_PAGE_BEG, ios::cur);     //현재 페이지의 첫부분으로 포인트를 넘겨줌
     


}
void prevPage(std::ifstream& in) {
    //이전페이지이므로 40줄, 한줄당 75byte이므로 40*75 byte 이전(-)으로 포인터를 이동
    int cur_line = LINE;
    int temp = LINE % 20;
    if (temp!= 0) {
        cur_line -= (temp+19);
    }
    else {
        cur_line -= 40;
    }
    cout << in.tellg() << endl;
    in.seekg(ONE_PAGE_BEG ,ios::cur);

    char x[100];
    for (int i = 0; i < 20 && (!in.eof()); i++, cur_line++)
    {
        in.read(x, 75);
        x[76] = '\0';
        cout << cur_line << " | " << x << '\n';    //지금은 읽은 문자열 바로 출력.
    }
    in.seekg(ONE_PAGE_BEG, ios::cur);
}
void inputWord(std::ifstream&in,int line_position,int word_position, string word) {
    //현재 페이지의 시작 페이지로
    string s;
    string str;
    ofstream fout("test1.txt", ios::in | ios::out);
    char x[100];
    int temp = (line_position -1) * 75;  //삭제할 라인으로
    in.seekg(temp, std::ios::cur);
    int line = in.tellg()/75;
    int count = 0;
    in.seekg(0, ios::beg);  //위치 지정자를 파일의 첫부분으로 옮겨 처음부터 탐색
    while ((!in.eof()) &&  (count < line))  //삭제할 라인전까지는 파일에 그냥 출력
    {
        in.read(x, 75);
        x[76] = '\0';
        fout << x;
        count++;
    }
    for (int i = 0; i < word_position; i++) {   //원하는 위치에 추가
        in >> s;
        temp += s.length() + 1;
        str += s+" ";
    }
    str = str+ word;
    cout << str << endl;
    int read_size = 75;
    int cur_size = in.tellg();
    
    fout << str;
    while (!in.eof())
    {
        if (cur_size + 75 > END_SIZE) {
            read_size = END_SIZE - cur_size;
            in.read(x, read_size);
            x[read_size + 1] = '\0';
             fout << x;
            break;
        }
        in.read(x, read_size);
        x[read_size+1] = '\0';
        fout << x;
        cur_size += read_size;
    }
}
