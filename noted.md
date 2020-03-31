### Rule 13.3

A function call is considered to be a side effect for the purposes of this rule
- The increment or decrement operator is a function call by itself.

- It can significantly impair the readability of the code
- It is clearer to use these operations in isolation from any other operators

### Rule 15.1

This can lead programs that are unstructured and extremely difficult to understand. So it is not only hard to maintain them but also can lead to uncontrolled programs that we cannot predict the control flow.

### Rule 15.2

This specific rule helps to maintain the "natural" flow of the program and it also helps to minimize visual code complexity.

### Conclusion between rules

Here we can see the difference between a Required rule and an Advisory rule. Although we are suggested not to use goto, we can use it only if we comply with some regulations that ensure further safety to our program.

### Compliance checking

1. You need to know the MISRA coding rules pertinent to which version of C or C++ you’re using.

2. Continuously inspecting your code for violations is the best way to improve quality.

3. Embedded systems come with legacy codebases. By setting baselines, you can focus on making sure your new code is compliant.

4. You could have hundreds or even thousands of violations in your code. That’s why it’s important to prioritize rule violations based on risk severity. Some static code analysis tools can do this for you.

5. Sometimes there are exceptions to the rule. But when it comes to compliance, every rule deviation needs to be well-documented.

6. Keep an eye on how MISRA compliant your code is. Using a static code analyzer makes this easier by automatically generating a compliance report.

7. Choosing the right static code analyzer makes everything else easy. It takes care of scanning your code — new and legacy — for violations. It prioritizes vulnerabilities based on risk.

### Compilers
The compiler’s optimization options should be reviewed and selected carefully in order to ensure that an appropriate balance between execution speed and code size has been obtained

### Helix
Helix QAC is a commercial static code analysis software tool. You can see here, you have the code on the top left, and the report on the bottom, referencing every rule.