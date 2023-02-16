## Main threads explanation
<p align="center"><img src="images/readme.png" /></p>





## Useful links

 __*[pthread explanation video lesson playlist (there are 29 videos, watch 20 videos)](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=1)*__
 
 __*[Philosopher visualizer (you can understand more visually your output)](https://nafuka11.github.io/philosophers-visualizer/)*__


## NEVER FORGET ABOUT DATA RACE
### Check with the command:
valgrind --tool=helgrind ./philo 5 400 100 100 5

### How to solve data race?
Even number philos get the forks first (philo_0, philo_2, philo_4 etc), then lock the mutex.
Odd number philos get the forks next. 
### In the code 
-for first fork:
pthread_mutex_t	*resolve_f_fork(t_philo *philor)

-for second fork:
pthread_mutex_t	*resolve_s_fork(t_philo *philor)

