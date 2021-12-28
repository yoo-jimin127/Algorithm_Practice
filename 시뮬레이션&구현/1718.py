#1718번 문제
#백준 여부 :

sent = list(input()) #평문 입력
key = list(input()) #암호화 키 입력

while len(sent) > len(key):
  key += key
res = ""
sent_alpha = list()
key_alpha = list()

for i in range(len(sent)) : #sent 배열의 알파벳을 아스키문자로 변환(a = 0 ~)
  sent_alpha.append(ord(sent[i])-96)

for j in range(len(key)) : #key 배열의 알파벳을 아스키문자로 변환(a = 0 ~)
  key_alpha.append(ord(key[j])-96)

for i in range(len(sent_alpha)) :
  if sent_alpha[i] == 32-96:
    res += ' '

  elif (sent_alpha[i] - key_alpha[i]) > 0 :
    res += (chr((sent_alpha[i] - key_alpha[i]) + 96))

  else :
    res += (chr((sent_alpha[i] - key_alpha[i]) + 96 + 26))

    # if (res[i] == '.') :
    #   res[i] = chr(32)

# print(sent_alpha)
# print(key_alpha)

print(res)
