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
}Node; //file�̸��� ������ �ִ� ���

typedef struct list {
    Node* head;
    Node* tail;
    int count;
}List; //�����̸��� �������ִ� ����ũ�帮��Ʈ

typedef struct word {
    char english[16];
    char korean[3][31];
    int koreaCount; //word����ü�� �ѱ��� ������ �־ koreaCount�迭�� �ʿ䰡 ���� �߽��ϴ�.
}Word; //�� �ܾ ����ü�� ����

//linkedlist�� �⺻������
void WordArraySort(Word* word, int fileline); //Word����ü ������ �������� ����
int getFileLine(char* filename); //������ ���μ��� �˷��ִ� �Լ�
int StringToken(Word* word, char* wordarr); //Word����ü�� ����� �ѱ��� �־��ִ� �Լ�
void InitList(List* list); //list�� �ʱ�ȭ���ִ� �Լ�
Node* MakeNode(char* filename); //node�� ����� �Լ�
void AddListNode(List* list, Node* node); //list�� node�� �ִ� �Լ�
Node* FindNode(List* list, int filenum); //���ϸ� �ش��ϴ� node�� �������ִ� �Լ�
void InsertDicName(Node* node); //dic.list���Ͽ� �����̸� �־��ִ� �Լ�
int GetDicCount(); //.dic������ ������ �˷��ִ� �Լ�
void GetDicName(int count); //.dic������ �̸��� �������ִ� �Լ�
void GetDicNameSort(int count); //.dic������ �̸��� �������ִ� �Լ�
char** diclist; //.dic������ �̸��� ����Ǿ��ִ� 2���� ������

//1�� ���α׷�
void AnswerWord(List* list); //1�� ���α׷� �ܾ� ���߱� ���α׷�
void FirstMenu(int* filenun, int* output); //�޴��� ������ִ� �Լ�
void CompareWord(Word* word, char* answer, int i, int* correct); //�ܾ �´��� Ʋ���� üũ���ִ� �Լ�

//2�� ���α׷�
int chooseSpeed(); //���ǵ带 �������ִ� �Լ�
int getFileNum(); //� .dic������ �����ϴ� �Լ�
int getShowType(); //�������� ����Ұ���, �����ؼ� ����Ұ��� ���ϴ� �Լ�
void randomFlashCard(int speed, Word* word, int fileline); //�������� �÷���ī�带 ����ϴ� �Լ�
void flashCard(List* list); //�÷���ī�带 �����ϴ� �Լ�
void regularFlashCard(int speed, Word* word, int fileline); //������� �÷���ī�带 ����ϴ� �Լ�

//3�� ���α׷�
void HangmanProgram(List* list); //��� ���α׷��� �����ϴ� �Լ�
void printHangmanTitle(); //��ǰ��� ���� ���
int isFileExist(List* list, int fileName_int); //list�� �ش� ������ ������ 1, ������ 0 ����
Word* getWordList(Node* fileNode); //�ش� ���Ͽ��� word�� ����Ʈ ���� ����
void printHint(Word word); //�ܾ��� �ѱ� ���� ��Ʈ�� ���
void printHangman(int wrongCount); //wrongCount�� ���� ����� ���
int isAlphabet(char ch); //ch�� ���� ���ĺ��̸� 1, �ƴϸ� 0 ����
int isCharInString(char ch, char* str, int UIAidx); //���ڿ� str�� ���� ch�� ������ 1 ������ 0 ����
void ShowWord(char* blankarr, int wordLen); //�ܾ �����ִ� �Լ�
void CheckWord(char* currentWordEn, char* blankarr, char inputChar, int* wrongCount); //��� ���� ���� ���� �����ֱ�
void printWinMessage(); //�̰��� ���� �޽��� ����ϴ� �Լ�
void stringLower(char* word); //���ܾ ��� �ҹ��ڷ� �����ϴ� �Լ�
int isGameStateWin(char* currentWordEn, char* blankarr); //���ĺ��� ��� ���߾����� 1 �ƴϸ� 0����

//4�� ���α׷�
void FourthMenu(int* menu); //�ܾ��� ���� ���α׷� �޴�
void FourthAddNewFile(List* list); //�ܾ��� ���� ���α׷��� �� ���� �߰��ϱ�
void FourthAddNewWord(List* list); //�ܾ��� ���� ���α׷��� �� �ܾ� �߰��ϱ�
void FourthViewWord(List* list); //�ܾ��� ���� ���α׷��� �ܾ��� ����
void FourthViewList(List* list); //�ܾ��� ���� ���α׷��� �ܾ� ���� ��Ϻ���
