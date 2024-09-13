# Thread Synchronization using POSIX Semaphores

This project demonstrates thread synchronization in C using POSIX semaphores. The threads correspond to tasks represented in a precedence graph, and the tasks are executed in a cyclic order based on the graph structure. The repository contains two implementations: one where threads are recreated in each cycle and another where threads run continuously in a loop.

## Project Structure

- `main.c`: Implements thread synchronization using POSIX semaphores, where threads are created and destroyed in each cycle of the principal loop. This file follows a specific precedence graph to manage thread execution.
  
- `main2.c`: Implements thread synchronization where threads are created once and continuously run in a cyclic loop, waiting for semaphore signals to execute their tasks in the correct order.

## Precedence Graph

The tasks executed by the threads in both files follow the same precedence graph:
```
       A  <--------
    /  |  \       ^
   /   |   \      |
  B    C    D     |
  |   / \   |     |
  |  /   \  |     |
  | E    F  |     |
  |  \   /  |     |
  |   \ /   |     |
  |    G    H     |
   \   |   /      |
    \  |  /       |
       I  ---------
```
Each vertex in this graph corresponds to a thread, and the edges represent the order in which the tasks must be executed, enforced through semaphores.
