# Student Grade Manager

##  Objective

Develop a C language program that allows a teacher to enter students' grades for multiple subjects and display various statistics about these grades.

---

##  Features

###  Grade Input
- Allows the user to enter grades for multiple students.
- Grades are entered for each subject.
- Grades are stored in two-dimensional arrays.

###  Statistics Calculation
- Calculates **average**, **median**, **minimum**, and **maximum** grades for each subject.
- All calculations are performed using dedicated functions.

###  Statistics Display
- Displays the calculated statistics on the screen in a clear and readable format.
- Statistics are shown per subject.

###  Grade Sorting
- Allows the user to sort grades in **ascending** or **descending** order.
- Sorting is based on the entered values.

###  Error Handling
- Handles input errors with appropriate error messages.
- Prompts the user to re-enter incorrect values.

---

##  Deliverables

- Source code of the program.
- A report describing the **design** and **implementation** of the program.
- Clear **compilation and execution instructions**.

---

##  Technical Constraints

- The program must be written in **C** language.
- Use **pointers** to pass two-dimensional arrays to functions.

---

##  Compilation & Execution

### Compile
```bash
gcc -o grade_manager main.c
