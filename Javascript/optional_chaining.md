# [Optional Chaining](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Optional_chaining)

The optional chaining *operator* **(?.)** enables you to 
**read the value of a property located deep within a chain of connected objects without having to check that each reference in the chain is valid**.

The ?. operator is like the . chaining operator, except that instead of causing an *error if a reference is nullish (null or undefined)*, the expression **short-circuits with a return value of undefined**. When used with function calls, it returns undefined if the given function does not exist.

**Examples:**

```js
const adventurer = {
  name: 'Alice',
  cat: {
    name: 'Dinah'
  }
};

const dogName = adventurer.dog?.name;
console.log(dogName);
// expected output: undefined

console.log(adventurer.someNonExistentMethod?.()); // Checks if function or method exists.
// expected output: undefined

console.log(adventurer.someNonExistentArray?.[0]);
```

```js

class Dog {
	constructor(name, age, breed){
	this.name = name,
	this.age = age,
	this.breed = breed}
}

const Kursha = new Dog('Kursha', 8, 'Pug');

const Blackie = new Dog('Blackie');

const MyDog = null;

const future = undefined;

console.log(Kursha?.age); // 8
console.log('Blackie exists? If so, print its name : ' + Blackie?.name); // Blackie
console.log(MyDog?.name); // undefined
console.log(future?.job); // undefined
```
