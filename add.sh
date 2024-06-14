##version 1
# #!/bin/bash

# PUSH_INTERVAL=300

# auto_git_push() {
#     git add .
#     git commit -m "Automated commit at $(date)"
#     git push
# }

# while true; do
#     auto_git_push
#     echo "Push completed at $(date). Next push in $PUSH_INTERVAL seconds..."
#     sleep $PUSH_INTERVAL
# done

# #version 2
# #!/bin/bash

# PUSH_INTERVAL=300

# auto_git_push() {
#     CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
#     if [ "$CURRENT_BRANCH" == "work" ]; then
#         git add .
#         git commit -m "Automated commit at $(date)"
#         git push
#         echo "Push completed at $(date). Next push in $PUSH_INTERVAL seconds..."
#     else
#         echo "Current branch is '$CURRENT_BRANCH'. Only 'work' branch is allowed for auto push."
#     fi
# }

# while true; do
#     auto_git_push
#     sleep $PUSH_INTERVAL
# done

#version 3
#!/bin/bash

PUSH_INTERVAL=300

auto_git_push() {
    CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
    if [ "$CURRENT_BRANCH" == "work" ]; then
        git remote update
        LOCAL=$(git rev-parse @)
        REMOTE=$(git rev-parse @{u})
        BASE=$(git merge-base @ @{u})

        if [ $LOCAL = $REMOTE ]; then
            echo "The branch is up to date."
        elif [ $LOCAL = $BASE ]; then
            echo "The branch is behind. Pulling changes..."
            git pull
        elif [ $REMOTE = $BASE ]; then
            echo "The branch has unpushed changes. Pushing changes..."
            git add .
            git commit -m "Automated commit at $(date)"
            git push
            echo "Push completed at $(date). Next push in $PUSH_INTERVAL seconds..."
        else
            echo "The branch has diverged. Manual intervention required."
            return
        fi
    else
        echo "Current branch is '$CURRENT_BRANCH'. Only 'work' branch is allowed for auto push."
    fi
}

while true; do
    auto_git_push
    sleep $PUSH_INTERVAL
done
# chmod +x add.sh