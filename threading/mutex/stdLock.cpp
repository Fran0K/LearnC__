//
// Created by Frank Lin on 27/10/21.
//

//TOPIC: std: Lock()In C++11
// It is used to Lock multiply mutex at the same time
// IMPORTANT:
// syntaxーー>std::Lock(m1,m2,m3,m4);
// 1. ALL arguments are locked via a sequence of calls to Lock(), try_lock(), or unlock) on each argument
// 2. Order of Locking is not defined (it will try to Lock provided mutex in any order and ensure that
//    there is no dead Lock)
// 3. It is a blocking call.
// Example: 0                        No dead Lock
//   Thread 1                           Thread 2
// std: Lock(m1, m2)                std: Lock(m1, m2)

// [Example: 1                       No dead Lock
//     Thread 1                         Thread 2
//std: Lock(m1, m2)                 std: Lock(m2, m1)

//[Example: 3]                       No deadlock
//     Thread 1                         Thread 2
//std: Lock(m1, m2, m3, m4)         std: Lock(m2, m1)
//                                  std: Lock(m3, m4)

// [Example: 4                       dead Lock
//     Thread 1                         Thread 2
//std: Lock(m1, m2)                 std: Lock(m3, m4)
//std: Lock(m3, m4)                 std: Lock(m1, m2)