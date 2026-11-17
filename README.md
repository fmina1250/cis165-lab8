# Lab 8 Assignment Plan

## Compile & Run Instructions
Compile and run the program using the following terminal commands:
```bash
g++ -std=c++17 -Wall -Wextra geometry.cpp -o geometry
./geometry or .\geometry
```

---

## Plan for (`geometry.cpp`)
* **Menu Options:** 
  * 1: Area of a Circle
  * 2: Area of a Rectangle
  * 3: Area of a Triangle
  * 4: Quit
* **Variables:** 
  * `choice` (menu selection)
  * `PI` (named constant set to `3.14159`)
  * `radius`, `length`, `width`, `base`, `height` (dimension inputs)
  * `area` (calculated result)
* **Validation Checks:** 
  * Verify menu choice is between 1 and 4.
  * Verify dimensions are `>= 0` (negative numbers trigger an error and terminate with `return 1;`, while 0 is allowed and produces a 0 area).

---

## Test Records & Results

1. **Test 1: Circle Area**
   * **Input / Data:** Choice `1`, radius `2`
   * **Expected Result:** Area `12.56636`
   * **Actual Output:** Area `12.56636`
   * **Match:** Yes

2. **Test 2: Rectangle Area**
   * **Input / Data:** Choice `2`, length `3`, width `4.5`
   * **Expected Result:** Area `13.5`
   * **Actual Output:** Area `13.5`
   * **Match:** Yes

3. **Test 3: Triangle Area**
   * **Input / Data:** Choice `3`, base `5`, height `3`
   * **Expected Result:** Area `7.5`
   * **Actual Output:** Area `7.5`
   * **Match:** Yes

4. **Test 4: Quit Option**
   * **Input / Data:** Choice `4`
   * **Expected Result:** Ends without dimension prompts or area calculation.
   * **Actual Output:** Program exited immediately with no prompts.
   * **Match:** Yes

5. **Test 5: Invalid Choice (0)**
   * **Input / Data:** Choice `0`
   * **Expected Result:** Displays invalid-choice error.
   * **Actual Output:** `Error: Invalid choice. Please select a number between 1 and 4.`
   * **Match:** Yes

6. **Test 6: Invalid Choice (5)**
   * **Input / Data:** Choice `5`
   * **Expected Result:** Displays invalid-choice error.
   * **Actual Output:** `Error: Invalid choice. Please select a number between 1 and 4.`
   * **Match:** Yes

7. **Test 7: Negative Dimensions**
   * **Input / Data:** Choice `1`, radius `-1` (and separate runs for negative rectangle length, width, base, height)
   * **Expected Result:** Each displays an error for negative dimensions and exits.
   * **Actual Output:** `Error: Radius cannot be negative.` (and equivalent messages for other shapes).
   * **Match:** Yes

8. **Test 8: Zero Dimension**
   * **Input / Data:** Choice `1`, radius `0`
   * **Expected Result:** Area `0`
   * **Actual Output:** Area `0`
   * **Match:** Yes

9. **Test 9: Additional Valid Calculation**
   * **Input / Data:** Choice `1`, radius `5`
   * **Expected Result:** `3.14159 * 5 * 5 = 78.53975`
   * **Actual Output:** Area `78.53975`
   * **Match:** Yes
   * **Explanation:** Checking whether larger floating-point radius inputs calculate correctly with high precision.

---

## Code Explanation

1. **How does your selection logic send each choice to the right calculation?**
   * An `if-else if-else` chain evaluates the user's `choice` variable, routing execution to the corresponding block for circles, rectangles, triangles, quitting, or catching invalid menu numbers.

2. **Why is `radius * radius` correct while `radius ^ 2` is not?**
   * In C++, the `^` operator performs a bitwise XOR operation rather than the mathematical operation, while `radius * radius` correctly performs multiplication.

3. **Why does the triangle calculation use `0.5` rather than integer division `1 / 2`?**
   * Integer division `1 / 2` evaluates to `0` due to truncation because both operands are integers, while using `0.5` provides a floating-point literal of type `double`, ensuring floating-point multiplication preserves the fractional half of the triangle area calculation.

4. **Where do you check negative dimensions, and how do you handle zero and choice 4?**
   * Negative dimensions are checked immediately after input in each choice branch before any area computation occurs. Zero is permitted by the `>= 0` check resulting in a zero area, and choice 4 cleanly terminates execution without prompting for dimensions.