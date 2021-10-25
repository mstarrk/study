# [Nullish Coalescing](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Nullish_coalescing_operator)


The nullish coalescing operator (??) is a **logical operator**.
*Returns its right-hand side operand* **when** its left-hand side operand is *null* or *undefined*.

This can be contrasted with the logical *OR (||)* operator, which returns the right-hand side operand if the left operand is **any falsy value, not only null or undefined**. 

In other words, if you use **||** to provide some default value to another variable foo, you may encounter unexpected behaviors if you consider some falsy values as usable (e.g., '' or 0).

```js
const value = 0;

const money = value ?? 'Value is null or undefined.'; 

console.log(money); // 0

// If it was (value || 'Value is null or undefined.') it will assign the right-hand one.

const friends = value || 'Value is null or undefined (or empty!)';

console.log(friends); // Value is null or undefined (or empty!)
```
