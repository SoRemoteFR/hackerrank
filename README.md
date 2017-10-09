

# Implement a queue using two stacks

## Intro
Many programming languages, notably functional languages like Lisp, implement
singly-linked lists and therefore stacks efficiently. In this tutorial, I show
how to create a queue with enqueue(), dequeue() and peek() functions using 2
stacks as the underlying data structure. 

## Idea
The idea is simple. A stack is first in first out, like a stack of paper.
Imagine you have two empty stacks of paper. The first one is your in-stack.
Whenever you get a new sheet, you put it onto your in-stack. This is enqueue().
When you dequeue(), you check if your second stack (out-stack) is empty. If it's
empty, you pop your in-stack and push each element onto your out-stack. Your
out-stack then contains the in-stack in reverse order. Then, simply pop your
out-stack (dequeue()). 

## Implementation
I wrote a small C program that takes input in the following format:

	6
	1 4
	1 5
	2
	1 6
	3
	3

The first digit is the amount of requests
The following lines are either	
*1 = enqueue the following digit
*2 = dequeue
*3 = peek

The program reads the requests and writes each peek to STDOUT.

## How to run
This program is written for OS X. To compile, simply
```
gcc -o queue q2s.c
```
Then to run, 
```
./queue input
```

## Purpose
I wrote this code to make sure I really understand the concept of making a queue
using 2 stacks. I find the best way to learn algorithms is to code them, so here
we are. Obviously, the code is not optimized and barely useful for real
applications. It would be cool the extend this to allow the queue to hold
arbitrary data, not just integers.

## Credit
I got the idea for this program from hackerrank.com, I site that I really love
and recommend to anyone looking for cool coding challenges. 
