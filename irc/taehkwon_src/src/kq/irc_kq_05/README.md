# Commit convention

최대 50글자까지 작성
ex) Feat: Add Key mapping

- `✨ Feat` : 새로운 기능 추가
- `🔨 Fix` : 버그 수정
- `♻️ Refactor` : 코드 리팩토링
- `🎨 Design` : 사용자 UI 디자인 변경
- `💡 Comment` : 필요한 주석 추가 및 변경
- `💄 Style` : 스타일 변경 (코드 형식, 세미콜론, 로직에 변경 없는 경우)
- `📝 Docs` : 문서 수정, 추가, 삭제 (README)
- `🧪 Test` : 테스트 관련 (테스트 코드 추가, 수정, 삭제)
- `Chore` : 기타 변경사항 (빌드 스크립트 수정, 패키지 매니저 등)


# 실행 방법
#### 1. 서버 실행
```bash
make
./ircserv <port> <password>
```

#### 2. 클라이언트(irssi) 실행
##### 도커 실행
 ```bash
 docker run -d --name ubuntu -p 80:80 -it --privileged ubuntu:20.04
 ```

##### irssi 설치 및 서버 접속
```bash
apt-get update && apt-get upgrade -y
apt-get install irssi -y
# timezone 6, 69 선택

# irssi -c <host> -p <port> -n <nickname> -w <password>
irssi -c 10.18.222.197-p 8080 -n seokjyan -w 0000
```

##### netcat 사용
```bash
# nc [options] <host> <port>
nc -c 10.12.6.3 8080
# c : CRLF
```
