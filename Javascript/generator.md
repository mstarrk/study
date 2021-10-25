# function*
The function* *declaration* (function keyword followed by an *asterisk* \*) defines a generator function, which returns a Generator object.

```js

function* idGenerator(){
	let id = 1; // Initial value of id

	while(true) // Infinite loop
	{
		yield id; // returns current iteration of id.
		id++;
	}
}

const gen = idGenerator();

console.log(gen.next()); //1
// It does not get stucked on the infite loop because of the yield keyword.
console.log(gen.next()); //2
console.log(gen.next()); //3
console.log(gen.next()); //4
// . . .
```
