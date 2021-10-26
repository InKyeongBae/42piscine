find . -type f -name "*.sh" -exec basename {} \; | sed -n 's/\.sh$//g'p
