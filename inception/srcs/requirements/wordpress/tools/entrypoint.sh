#!/bin/bash

wget -O /tmp/wordpress.tar.gz "http://wordpress.org/latest.tar.gz"
tar -xvzf /tmp/wordpress.tar.gz -C /var/www/html
