tail -n +2 | while IFS=',' read -r roll name marks; do
    if [ $marks -lt 50 ]; then grade="U"
    elif [ $marks -lt 60 ]; then grade="D"
    elif [ $marks -lt 70 ]; then grade="C"
    elif [ $marks -lt 80 ]; then grade="B"
    elif [ $marks -lt 90 ]; then grade="A"
    else grade="S"
    fi 
    echo "$name :$grade" 
done