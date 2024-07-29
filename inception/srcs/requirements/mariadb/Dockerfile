# Base image
FROM alpine:3.20

# Install MariaDB
RUN apk update && \
    apk add --no-cache mariadb mariadb-client && \
    mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld && \
    mkdir -p /var/lib/mysql && \
    chown -R mysql:mysql /var/lib/mysql

# MariaDB 설정 파일을 복사합니다.
COPY conf/my.cnf /etc/mysql/my.cnf

# 데이터 디렉토리 생성 및 권한 설정
RUN mkdir -p /var/lib/mysql && \
    chown -R mysql:mysql /var/lib/mysql

# MariaDB 초기화
RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

# 로그 파일 생성
RUN echo "This is a log file" > /var/log/mylog.log

# ENTRYPOINT 설정 - tail 명령어로 로그 파일을 계속해서 출력, 무한히 실행
ENTRYPOINT ["tail", "-f", "/var/log/mylog.log"]