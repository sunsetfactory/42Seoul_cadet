#!/bin/bash

CACHE_DIRS=(
  "$HOME/Library/Caches"
  "$HOME/Library/Application Support/Code"
  "$HOME/Library/Application Support/Docker Desktop"
  "$HOME/Library/Application Support/Google"
  "$HOME/Library/Application Support/iTerm2"
)

GOINFRE_BASE="$HOME/goinfre/links"
FLAG="$GOINFRE_BASE/issetup"

function link_all_cache_dirs() {
  echo "Linking directories to goinfre/links..."
  
  for dir in "${CACHE_DIRS[@]}"; do
    dir_name=$(basename "$dir")
    target="$GOINFRE_BASE/$dir_name"
    
    if [ -d "$dir" ]; then
      mkdir -p "$target"
      cp -R "$dir"/* "$target/"  # 기존 내용을 goinfre/links로 복사
      rm -rf "$dir"
      ln -s "$target" "$dir"  # 심볼릭 링크 생성
      echo "Linked $dir to $target"
    fi
  done

  echo "Complete linking all directories!"
}

if [ ! -e "$FLAG" ]; then
  link_all_cache_dirs
  touch "$FLAG"
fi

