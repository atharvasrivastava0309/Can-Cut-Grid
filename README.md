# **Check if Grid Can Be Cut into Sections**  

## **Overview**  
This C++ project determines whether a given **n x n** grid containing non-overlapping rectangles can be split into **three sections** using exactly **two horizontal or two vertical cuts**.  

## **Problem Statement**  
Given an integer `n` representing the size of an `n x n` grid and a list of `rectangles`, where each rectangle is defined as `[startx, starty, endx, endy]`, the program checks if:  
1. Each of the three resulting sections contains **at least one rectangle**.  
2. No rectangle is split between sections.  

If valid cuts exist, the program returns **true**; otherwise, it returns **false**.  

---

## **Example**  
### **Input:**  
```
Grid Size (n): 5  
Number of Rectangles: 4  
Rectangles:  
1 0 5 2  
0 2 2 4  
3 2 5 3  
0 4 4 5  
```
### **Output:**  
```
true
```
### **Explanation:**  
A **horizontal cut** can be made at `y = 2` and `y = 4`, forming three sections, each containing at least one rectangle.  

---

## **How It Works**  
1. **Reads** user input (`n`, `rectangles`).  
2. **Stores** x and y coordinates of rectangle edges.  
3. **Sorts** these coordinates and processes them to check for valid cuts.  
4. **Determines** whether exactly two horizontal or two vertical cuts exist.  
5. **Outputs** `true` or `false` accordingly.  

---

## **Code Structure**  
- **`countValidCuts(vector<pii>& coordinates)`** → Checks if there are exactly **two valid cuts** in the sorted list.  
- **`canCutGrid(int n, vector<vector<int>>& rectangles)`** → Calls the function for both **x** and **y** coordinates.  
- **`main()`** → Takes input, calls functions, and prints the result.  

---

## **Technologies Used**  
- **C++**  
- **G++ Compiler**  
- **VS Code / Any C++ IDE**  
