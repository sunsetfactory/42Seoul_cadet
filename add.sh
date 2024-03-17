#!/bin/bash

PUSH_INTERVAL=300

auto_git_push() {
    git add .
    git commit -m "Automated commit at $(date)"
    git push
}

while true; do
    auto_git_push
    echo "Push completed at $(date). Next push in $PUSH_INTERVAL seconds..."
    sleep $PUSH_INTERVAL
done

