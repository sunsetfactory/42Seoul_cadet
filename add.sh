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

# #version 3
# #!/bin/bash

# PUSH_INTERVAL=300

# auto_git_push() {
#     CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
#     if [ "$CURRENT_BRANCH" == "work" ]; then
#         git remote update
#         LOCAL=$(git rev-parse @)
#         REMOTE=$(git rev-parse @{u})
#         BASE=$(git merge-base @ @{u})

#         if [ $LOCAL = $REMOTE ]; then
#             echo "The branch is up to date."
#         elif [ $LOCAL = $BASE ]; then
#             echo "The branch is behind. Pulling changes..."
#             git pull origin work
#         elif [ $REMOTE = $BASE ]; then
#             echo "The branch has unpushed changes. Pushing changes..."
#             git add .
#             git commit -m "Automated commit at $(date)"
#             git push origin work
#             echo "Push completed at $(date). Next push in $PUSH_INTERVAL seconds..."
#         else
#             echo "The branch has diverged. Manual intervention required."
#             return
#         fi
#     else
#         echo "Current branch is '$CURRENT_BRANCH'. Only 'work' branch is allowed for auto push."
#     fi
# }

# while true; do
#     auto_git_push
#     sleep $PUSH_INTERVAL
# done
# # chmod +x add.sh

# #version 4
# #!/bin/bash

# PUSH_INTERVAL=300

# check_branch_status() {
#     git remote update
#     LOCAL=$(git rev-parse @)
#     REMOTE=$(git rev-parse @{u})
#     BASE=$(git merge-base @ @{u})

#     if [ $LOCAL = $REMOTE ]; then
#         echo "The branch is up to date."
#         return 0
#     elif [ $LOCAL = $BASE ]; then
#         echo "The branch is behind. Pulling changes..."
#         git pull origin work
#         return 1
#     elif [ $REMOTE = $BASE ]; then
#         echo "The branch has unpushed changes. Preparing to push changes..."
#         return 2
#     else
#         echo "The branch has diverged. Manual intervention required."
#         return 3
#     fi
# }

# auto_git_push() {
#     CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
#     if [ "$CURRENT_BRANCH" == "work" ]; then
#         check_branch_status
#         STATUS=$?
#         if [ $STATUS -eq 0 ]; then
#             echo "No changes to push."
#         elif [ $STATUS -eq 1 ]; then
#             echo "Changes pulled successfully."
#         elif [ $STATUS -eq 2 ]; then
#             git add .
#             git commit -m "Automated commit at $(date)"
#             git push origin work
#             echo "Push completed at $(date). Next push in $PUSH_INTERVAL seconds..."
#         fi
#     else
#         echo "Current branch is '$CURRENT_BRANCH'. Only 'work' branch is allowed for auto push."
#     fi
# }

# while true; do
#     auto_git_push
#     sleep $PUSH_INTERVAL
# done

# #version 5
#!/bin/bash

PUSH_INTERVAL=300

update_remote() {
    git remote update
}

get_branch_status() {
    LOCAL=$(git rev-parse @)
    REMOTE=$(git rev-parse @{u})
    BASE=$(git merge-base @ @{u})

    if [ $LOCAL = $REMOTE ]; then
        echo "up-to-date"
    elif [ $LOCAL = $BASE ]; then
        echo "behind"
    elif [ $REMOTE = $BASE ]; then
        echo "ahead"
    else
        echo "diverged"
    fi
}

pull_changes() {
    git pull origin work
    if [ $? -ne 0 ]; then
        echo "Failed to pull changes. Please resolve conflicts manually."
        exit 1
    fi
}

commit_and_push_changes() {
    git add .
    if ! git diff-index --quiet HEAD; then
        git commit -m "Automated commit at $(date)"
        git push origin work
        if [ $? -ne 0 ]; then
            echo "Failed to push changes. Please resolve issues manually."
            exit 1
        fi
        echo "Push completed at $(date). Next push in $PUSH_INTERVAL seconds..."
    else
        echo "No changes to commit."
    fi
}

auto_git_push() {
    CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
    if [ "$CURRENT_BRANCH" == "work" ]; then
        update_remote
        STATUS=$(get_branch_status)
        case $STATUS in
            "up-to-date")
                echo "The branch is up to date."
                commit_and_push_changes
                ;;
            "behind")
                echo "The branch is behind. Pulling changes..."
                pull_changes
                ;;
            "ahead")
                echo "The branch has unpushed changes. Preparing to push changes..."
                commit_and_push_changes
                ;;
            "diverged")
                echo "The branch has diverged. Manual intervention required."
                exit 1
                ;;
        esac
    else
        echo "Current branch is '$CURRENT_BRANCH'. Only 'work' branch is allowed for auto push."
    fi
}

while true; do
    auto_git_push
    sleep $PUSH_INTERVAL
done
