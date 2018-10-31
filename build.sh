gcc -o fun_p_a fun_p_a.c
gcc -o sem_wait sem_wait.c -Wall -Werror -lpthread
gcc -o mutex_wait mutex_wait.c -Wall -Werror -lpthread
gcc -o sem_wait_process sem_wait_process.c -lpthread
