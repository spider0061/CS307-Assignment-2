# CS307-Assignment-2
### This repository is dedicated for assignment 1 of CS307 course.
Instructor: Dr. Aditya Nigam


### Team Members

|   | Name | Roll No.  |
|--------|--------|--------|
|A| Ashutosh Sharma  | B18010 |
|B| Anuj Goel    | B18161  |
|C| Om Pandey | B18182  |

Assignment problem sheet: [Assignment Questions](https://drive.google.com/file/d/12gEN2vzhxTDoWFKWBbmj_M6AtH1VrU8N/view?usp=sharing)

### Requirements
gcc version: 9.3

### Q1. Compiling the Linux kernel from source and building a loadable module

### Libraries used:

1. linux/module.h  
2. linux/kernel.h  
3. linux/init.h  

### Running the code:

1. Hello World Module

- Type "cd Q1" on terminal
- Type "cd Hello_World" on terminal
- Type "make" on terminal
- Type "sudo insmode hello.ko" on terminal
- Type "modinfo hello.ko" on termninal to see details of module
- Type "tail /var/log/kern.log" on terminal to view kernel log
- Type "rmmod hello" to remove module from terminal

2. Divide by 0 Module

- Type "cd Q1" on terminal
- Type "cd test1" on terminal
- Type "make" on terminal
- Type "sudo insmode test1.ko" on terminal
- Type "modinfo test1.ko" on termninal to see details of module
- Type "tail /var/log/kern.log" on terminal to view kernel log
- Type "rmmod test1" to remove module from terminal

3. Return other than 1 Module

- Type "cd Q1" on terminal
- Type "cd test2" on terminal
- Type "make" on terminal
- Type "sudo insmode test2.ko" on terminal
- Type "modinfo test2.ko" on termninal to see details of module
- Type "tail /var/log/kern.log" on terminal to view kernel log
- Type "rmmod test2" to remove module from terminal

4. Dereferencing a NULL pointer module

- Type "cd Q1" on terminal
- Type "cd test3" on terminal
- Type "make" on terminal
- Type "sudo insmode test3.ko" on terminal
- Type "modinfo test3.ko" on termninal to see details of module
- Type "tail /var/log/kern.log" on terminal to view kernel log
- Type "rmmod test3" to remove module from terminal

### Q2. Round-Robin Scheduling

### Libraries used:

1. iostream
2. queue
3. vector

### Running the code

- Enter Q2 folder 
- Type "make"
- Type "./q2 <No. of processes> <array of arrival time> <array of burst time> <time quantum>"
- The program will produce the required output.    
