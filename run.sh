#!/bin/bash
if [ $# -eq 0 ]; then
    # If no arguments are provided, run all .sh files in all folders
    for task in check/task_*; do
        if [ -d "$task" ]; then
            echo "Running tests from $task"
            for file in "$task"/*.sh; do
		echo "Running tests from $file"
                if [ -f "$file" ]; then
                    bash "$file"
                fi
            done
        fi
    done
else
    # If an argument is provided (e.g., run.sh 1), run tests from a specific folder
    task="check/task_$1"
    if [ -d "$task" ]; then
        echo "Running tests from $task"
        for file in "$task"/*.sh; do
	    echo "Running tests from $file"
            if [ -f "$file" ]; then
                bash "$file"
            fi
        done
    else
        echo "Folder $task doesn't exist"
    fi
fi
