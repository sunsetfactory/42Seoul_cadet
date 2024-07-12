# Base image
FROM alpine:latest

# Set environment variables for MariaDB
ENV MYSQL_ROOT_PASSWORD=root_password \
    MYSQL_DATABASE=example_db \
    MYSQL_USER=example_user \
    MYSQL_PASSWORD=user_password

# Install MariaDB
RUN apk update && \
    apk add --no-cache mariadb mariadb-client && \
    mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld && \
    mkdir -p /var/lib/mysql && \
    chown -R mysql:mysql /var/lib/mysql

# Copy custom configuration files if any
# COPY ./conf/my.cnf /etc/my.cnf

# Expose the default MariaDB port
EXPOSE 3306

# Volume for database persistence
VOLUME ["/var/lib/mysql"]

# Default command to start MariaDB
CMD ["mysqld", "--user=mysql"]
