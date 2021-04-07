#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <ctype.h>

typedef struct node {
    char filename[10];
    struct node* next;
    struct node* prev;
}Node; //file이름을 가지고 있는 노드

typedef struct list {
    Node* head;
    Node* tail;
    int count;
}List; //파일이름을 가지고있는 더블링크드리스트

typedef struct word {
    char english[16];
    char korean[3][31];
    int koreaCount; //word구조체에 한글의 개수를 넣어서 koreaCount배열은 필요가 없게 했습니다.
}Word; //한 단어씩 구조체를 만듬

//linkedlist및 기본구조들
void WordArraySort(Word* word, int fileline); //Word구조체 포인터 오름차순 정렬
int getFileLine(char* filename); //파일의 라인수를 알려주는 함수
int StringToken(Word* word, char* wordarr); //Word구조체에 영어와 한글을 넣어주는 함수
void InitList(List* list); //list를 초기화해주는 함수
Node* MakeNode(char* filename); //node를 만드는 함수
void AddListNode(List* list, Node* node); //list에 node를 넣는 함수
Node* FindNode(List* list, int filenum); //파일명에 해당하는 node를 리턴해주는 함수
void InsertDicName(Node* node); //dic.list파일에 파일이름 넣어주는 함수
int GetDicCount(); //.dic파일의 개수를 알려주는 함수
void GetDicName(int count); //.dic파일의 이름을 저장해주는 함수
void GetDicNameSort(int count); //.dic파일의 이름을 정렬해주는 함수
char** diclist; //.dic파일의 이름이 저장되어있는 2차원 포인터

//1번 프로그램
void AnswerWord(List* list); //1번 프로그램 단어 맞추기 프로그램
void FirstMenu(int* filenun, int* output); //메뉴를 출력해주는 함수
void CompareWord(Word* word, char* answer, int i, int* correct); //단어가 맞는지 틀린지 체크해주는 함수

//2번 프로그램
int chooseSpeed(); //스피드를 리턴해주는 함수
int getFileNum(); //어떤 .dic파일을 리턴하는 함수
int getShowType(); //무작위로 출력할건지, 정렬해서 출력할건지 정하는 함수
void randomFlashCard(int speed, Word* word, int fileline); //랜덤으로 플래쉬카드를 출력하는 함수
void flashCard(List* list); //플래쉬카드를 관리하는 함수
void regularFlashCard(int speed, Word* word, int fileline); //순서대로 플래쉬카드를 출력하는 함수

//3번 프로그램
void HangmanProgram(List* list); //행맨 프로그램을 관리하는 함수
void printHangmanTitle(); //행맨게임 제목 출력
int isFileExist(List* list, int fileName_int); //list에 해당 파일이 있으면 1, 없으면 0 리턴
Word* getWordList(Node* fileNode); //해당 파일에서 word의 리스트 만들어서 리턴
void printHint(Word word); //단어의 한글 뜻을 힌트로 출력
void printHangman(int wrongCount); //wrongCount에 따라 행맨을 출력
int isAlphabet(char ch); //ch가 영문 알파벳이면 1, 아니면 0 리턴
int isCharInString(char ch, char* str, int UIAidx); //문자열 str에 문자 ch가 있으면 1 없으면 0 리턴
void ShowWord(char* blankarr, int wordLen); //단어를 보여주는 함수
void CheckWord(char* currentWordEn, char* blankarr, char inputChar, int* wrongCount); //행맨 게임 맞춘 문자 보여주기
void printWinMessage(); //이겼을 때의 메시지 출력하는 함수
void stringLower(char* word); //영단어를 모두 소문자로 변경하는 함수
int isGameStateWin(char* currentWordEn, char* blankarr); //알파벳을 모두 맞추었으면 1 아니면 0리턴

//4번 프로그램
void FourthMenu(int* menu); //단어장 관리 프로그램 메뉴
void FourthAddNewFile(List* list); //단어장 관리 프로그램중 새 파일 추가하기
void FourthAddNewWord(List* list); //단어장 관리 프로그램중 새 단어 추가하기
void FourthViewWord(List* list); //단어장 관리 프로그램중 단어장 보기
void FourthViewList(List* list); //단어장 관리 프로그램중 단어 파일 목록보기
