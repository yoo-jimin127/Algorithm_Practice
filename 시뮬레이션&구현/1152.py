#1152번 문제
#백준 여부: 

#파이썬 여러줄 주석 하는 방법 : 주석 넣을 부분 드래그한 뒤 ctrl + /하면 다 #처리됨

# a = list(map(str, input().split())) #리스트로 문자열 a를 받음

# cnt = 0

# for i in range(len(a)) : #a 길이 만큼의 반복문 돌려서
#   if a[i] == " " : #i번째 인덱스의 리스트 값이 공백일 경우 cnt+1
#     cnt+=1

#   else : #아니면 계속 진행(continue)
#     continue

# print(cnt) #결과값이 이상하게 나와요...

a = input()
b = list(a.split()) #split 기본값이 공백(" ")이어서 b = list(a.split())이 같은 의미
#입력받은 문자열을 리스트에 공백자를 기준으로 넣어준 뒤, 리스트 b의 len을 출력하면 단어의 개수가 나옴
print(len(b))
