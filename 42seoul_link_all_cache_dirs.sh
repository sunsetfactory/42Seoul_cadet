#/bin/bash

BANNER="$(
  cat <<-EOF
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    42seoul_link_all_cache_dirs.sh                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #

#    By: seokjyan <seokjyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 15:12:41 by seokjyan          #+#    #+#              #
#    Updated: 2023/11/16 10:12:41 by seokjyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
EOF
)"

TARGET=(
  "Caches"
  "ApplicationSupport/Code/Cache"
  "ApplicationSupport/Code/CachedData"
  "ApplicationSupport/Code/CachedExtensions"
  "ApplicationSupport/Code/CachedExtensionVSIXs"
  "ApplicationSupport/Code/Code Cache"
  "ApplicationSupport/Slack/Cache"
  "ApplicationSupport/Slack/CachedData"
  "ApplicationSupport/Slack/Service Worker/CacheStorage"
  "ApplicationSupport/Slack/Service Worker/ScriptCache"
)

FLAG="$HOME/goinfre/issetup"

function link_all_cache_dirs() {
  echo "link Code Slack Cache dirs..."
  for ((i = 0; i < ${#TARGET[@]}; i++)); do
    mkdir -p "$HOME/goinfre/${TARGET[$i]}"
    rm -rf "$HOME/Library/${TARGET[$i]}"
    ln -s "$HOME/goinfre/${TARGET[$i]}" "$HOME/Library/${TARGET[$i]}"
  done
  echo "Complete link all Cache dirs!"
  git clone "https://github.com/sunsetfactory/42Seoul_cadet.git" "$HOME/goinfre/42cd"
  git clone "https://github.com/sunsetfactory/baekjoon" "$HOME/goinfre/baekjoon_solve"
  echo "Completed all Git clones!"
  touch "$FLAG"
}

if [ ! -e "$FLAG" ]; then
  echo "$BANNER"
  link_all_cache_dirs
fi
