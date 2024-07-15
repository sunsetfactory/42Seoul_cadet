all: up
# Start the containers in detached mode
up:
	@docker-compose -f srcs/docker-compose.yml up -d
	@sleep 5
	@docker ps
# Stop the containers
down:
	@docker-compose -f srcs/docker-compose.yml down
# Display logs from the containers
logs:
	@echo "Nginx"
	@docker exec -it nginx /bin/sh -c "cat /var/log/nginx/error.log"
	@echo "-----------------------------------------------------------------"
	@echo "Wordpress"
	@docker exec -it wordpress /bin/sh -c "cat /var/log/php83/error.log"
	@echo "-----------------------------------------------------------------"
	@docker-compose -f srcs/docker-compose.yml logs -f
check_web:
	curl -vI https://seokjyan.42.fr
# Open a shell in the container
in_mariadb:
	@docker exec -it mariadb /bin/sh
in_wordpress:
	@docker exec -it wordpress /bin/sh
in_nginx:
	@docker exec -it nginx /bin/sh
# Build the docker containers
build:
	@mkdir -p /Users/seokjyan/data/mariadb
	@mkdir -p /Users/seokjyan/data/wordpress
	@chmod -R 777 ./srcs
	@docker-compose -f srcs/docker-compose.yml build --no-cache
# 클러 맥에서는 Users가 아니라 home일 수 있다.
.PHONY: fclean

fclean:
	@docker stop $$(docker ps -qa) 2>/dev/null || true; \
	docker rm $$(docker ps -qa) 2>/dev/null || true; \
	docker rmi -f $$(docker images -qa) 2>/dev/null || true; \
	docker volume rm $$(docker volume ls -q) 2>/dev/null || true; \
	docker network rm $$(docker network ls -q) 2>/dev/null || true

.PHONY: build up down clean logs