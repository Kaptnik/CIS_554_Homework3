# CIS_554_Homework3
Homework 3 of the CIS 554 (Object Oriented Programming) course, summer 2018

# Requirement

Homework Objective: Provide students with an opportunity to write a more complex C++ classes using functions. 

Description: Problem from the text:

## 6.56 (Computer-Assisted Instruction) 
The use of computers in education is referred to as com-puter-assisted instruction (CAI). Write a program that will help an elementary school student learn multiplication. Use the rand function to produce two positive one-digit integers. The program should then prompt the user with a question, such as 

        How much is 6 times 7? 

The student then inputs the answer. Next, the program checks the student's answer. If its correct, display the message "very good!" and ask another multiplication question. If the answer is wrong, display the message "No. Please try again." and let the student try the same question repeatedly until the student finally gets it right. A separate function should be used to generate each new ques-tion. This function should be called once when the application begins execution and each time the user answers the question correctly. 

## 6.57 (Computer-Assisted Instruction: Reducing Student Fatigue) 
One problem in CAI environ-ments is student fatigue. This can be reduced by varying the computer's responses to hold the stu-dent's attention. Modify the program of Exercise 6.56 so that various comments are displayed for each answer as follows: 
Possible responses to a correct answer: 
    
        Very good! 
        Excellent! 
        Nice work! 
        Keep up the good work! 
        
Possible responses to an incorrect answer: 
    
      No. Please try again. 
      Wrong. Try once more. 
      Don't give up! 
      No. Keep trying. 
      
Use random-number generation to choose a number from 1 to 4 that will be used to select ne of the four appropriate responses to each correct or incorrect answer. Use a switch statement to issue the responses. 

Notes: In order to implement this problem, you must create a class called CAI. This class will contain various public and private methods to implement the entire solution. The problem as stated above requires you to help elementary students with multiplication. You must also help the students with division as well as multiplication. You should create 5 random multiplication and 5 random division problems to present to the student. After all questions have been answered correctly, you should provide a summary of how they did (i.e. how many they got right on the first try, and how many wrong guesses it took, on average, to get each of the other ones correct.)

In this assignment, you will make good use of functions, along with the following constructs:
1.	For loop
2.	If statements
3.	Switch statement

In this homework you should make good use of private data members as well. NO public data members will be allowed. 
