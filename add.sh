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

#version 2
#!/bin/bash

PUSH_INTERVAL=300

auto_git_push() {
    CURRENT_BRANCH=$(git rev-parse --abbrev-ref HEAD)
    if [ "$CURRENT_BRANCH" == "work" ]; then
        git add .
        git commit -m "Automated commit at $(date)"
        git push
        echo "Push completed at $(date). Next push in $PUSH_INTERVAL seconds..."
    else
        echo "Current branch is '$CURRENT_BRANCH'. Only 'work' branch is allowed for auto push."
    fi
}

while true; do
    auto_git_push
    sleep $PUSH_INTERVAL
done