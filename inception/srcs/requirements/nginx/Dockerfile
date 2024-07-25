# Base image
FROM alpine:3.19

# 필요한 패키지 설치
RUN apk add --no-cache bash

RUN 

# 로그 파일 생성
RUN echo "This is a log file" > /var/log/mylog.log

# ENTRYPOINT 설정
ENTRYPOINT ["tail", "-f", "/var/log/mylog.log"]