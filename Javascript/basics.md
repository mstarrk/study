# JS basics

**Summary**

* [SOURCE](https://www.youtube.com/watch?v=hdI2bqOjy3c)
* [FULL CODE](https://embed.plnkr.co/plunk/8ujYdL1BxZftGoS4Cf14)
* [JAVASCRIPT DOCS](https://javascript.info/)
________________________________________________________________________________________________________________________

## 0 - Variable declaration


**`var` `let` & `const`**

```javascript
var name = "John"; // Globally Scoped.

let age; // Not globally scoped

age = 36;

const birthdate =  new Date("12/03/1985"); // Must be initialized. let can be re-assigned, const can not
```
________________________________________________________________________________________________________________________


## 1 - Console

```javascript
// LOGGING OUTPUT

alert('Hello World'); // Do not use for debugging. Stops script and only strings

console.log(`Hello world, my name is ` + name); // Hello world, my name is John

console.error('This is an error');

console.warn('This is a warning');
```
________________________________________________________________________________________________________________________


## 2.0 - Primitive data types

**DATA TYPES** - String, Number, Boolean, null, undefined
```javascript
const name = 'Brad';
const age = 37;
const rating = 3.5;
const isCool = true;
const x = null;
const y = undefined;
```
**Number Types**

- In this example, *both* variables are type **"number"**.

```javascript
let a = 35;
let b = 3.5;

console.log(typeof a); // number
console.log(typeof b); // number
```

**Undefined**

- Not assigned variables are **undefined**.

```javascript
let z; // undefined
```

________________________________________________________________________________________________________________________

## 2.1 - Strings

**String properties & methods** (**Method:** A *function* associated with an *object*.)

The [String](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String) object is used to represent and manipulate a sequence of characters. 

```javascript
    let s = `Hello world`;

    console.log(s.length); // 11
    console.log(s.toUpperCase()); // HELLO WORLD
    console.log(s.toLowerCase()); // hello world
    
    // Substring - args: (start, end indexes). Start at s[0] and end at s[5].
    console.log(s.substring(0,5)); // Hello

    let fruits = "apple, banana, pear, orange";

    console.log(fruits.split(', ')); // Returns an array of strings (4) ["apple", "banana", "pear", "orange"]
```

**Interpolation**

```javascript
// Interpolation requires string to be between grave accents (`).

console.log(`Hello world, my name is ${name}`); // Hello world, my name is John
``` 

________________________________________________________________________________________________________________________

## 3 - Arrays

The **[JavaScript Array class](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array)** is a global object that is used in the construction of arrays; which are high-level, list-like objects.

**Declaration**

```javascript

    const numbers = new Array(1,2,3,4,5); // Using a constructor.
    const empty = []; // Most commonly used.

    const fruits = ['apple', 'orange', 'pear'];     

    const weird = ['a string', true, 5, fruits]; // different types are allowed.

    fruits[3] = 'grape'; // Even though the array is a const, its contained elements can change.

```

- **Multiple types** are **allowed** in an array, that's the case with *weird*. 

- **Array size** is *not mandatory*.

**Methods**

```javascript

    Array.isArray(fruits); // true!

    fruits.push('mango'); // Add to the array (last position).
    
    fruits.unshift('strawberry'); // Add to the array (first position).

    fruits.pop(); // Remove from the array (last position). Bye bye mango.

    fruits.indexOf('orange'); // = 2

```
________________________________________________________________________________________________________________________

## 4 - Objects Literals

**Declaration**

```javascript

        const john = {
            firstName : 'John',
            lastName : 'Doe',
            age : 36,
            hobbies : ['programming', 'games', 'music', 'movies & tv shows'],
            address : {
                street : 'Some street 120',
                city : 'Some City',
                country : 'Some country'

            }
        };

        const toDos = [
            {
                id : 1,
                text : 'study JS',
                isCompleted : false
            },
            {
                id : 2,
                text : 'make dinner',
                isCompleted : false
            },
            {
                id : 3,
                text : 'take out thrash',
                isCompleted : true
            }
        ];
        
    
    console.log(`${john.firstName} is ${john.age} years old and he likes ${john.hobbies[0]}.`)
    // OUTPUT : John is 36 years old and he likes programming.
```

## 4.1 - Object to JSON

**CONVERT to JSON** : *Object* to **.JSON**

>The [JSON](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/JSON) object contains methods for parsing JavaScript Object Notation (JSON) and converting values to JSON. It can't be called or constructed, and aside from >its two method properties, it has no interesting functionality of its own. 

```javascript

    const toDosJSON = JSON.stringify(toDos);

```
________________________________________________________________________________________________________________________

## 5.1 - Loops: for, while, do while

**for loop**

```javascript


    for(let i = 0; i < 10; i++){
        console.log(i);
    }

```

**for loop:** Arrays/Objects.

```javascript

    for (let todo of toDos){
        console.log(todo.text);
    }

```

**while loop**

```javascript

    let i = 0;
    while(i < 10){
        console.log(i);
        i++;
    }

```

**do...while**

```javascript
let result = '';
let i = 0;

do {
  i = i + 1;
  result = result + i;
} while (i < 5);

console.log(result);
// OUTPUT: "12345"
```

________________________________________________________________________________________________________________________

## 5.2 - High Order Arrays methods: forEach, map, filter

**forEach:** Loops through array

```javascript

    toDos.forEach(function (todo) {
        console.log(todo.text)
    });

```

**map:** Loop through and create new array

```javascript

    const toDoText = toDos.map(function (todo) {
        return todo.text
    });

```

**filter:** Returns array based on condition

```javascript

    const toDoCompleted = toDos.filter(function (todo) {
        return todo.isCompleted === true; // '===' checks for data types. '==' does not. x = 10 and y = "10" are == but not ===
    });

```

## 6 - Functions

**Functions with default values**

```javascript

    function Sum(num1 = 1, num2 = 2){
        console.log(num1+num2);
    }

    // Sum() or Sum(num1, num2); are allowed.    
```

**Arrow function**

```javascript

    const Sum = (num1 = 1, num2 = 2) => {     // Sum() or Sum(num1, num2); are allowed.    
        console.log(num1+num2);
    }

    const Multiply = (num1 = 5, num2 = 5) => num1 * num2; // Return is not necessary.

    todos.forEach ( (todo) => console.log(todo.text) );

```

## 7 - OOP

**Constructors & prototypes**

```javascript

    function person(firstName, lastName, dob){
        this.firstName = firstName;
        this.lastName = lastName;
        this.dob = new Date(dob);
    }

    Person.prototype.getBirthYear = function() {
        return this.dob.getFullYear();
    }

    Person.prototype.getFullName = function() {
        return `${this.firstName} ${this.lastName}`;
    }

    // Instantiate object

    const person1 = new Person('Juan Jose', 'Morales', '24-7-1995');
```

**Classes:** same thing as before, but with *OOP* syntax.

```javascript

class Person {    
    constructor(firstName, lastName, dob){
        this.firstName = firstName;
        this.lastName = lastName;
        this.dob = new Date(dob);
    }

    GetBirthYear(){
        return this.dob.getFullYear();
    }

    GetFullName(){
        return `${this.firstName} ${this.lastName}`;
    }
}

const john = new Person('John', 'Doe', '12/03/1985');

console.log(john.GetBirthYear()); // 1985
```


## 8 - DOM: Document Object Model

**Window object**

```javascript
    console.log(window);
```

**Selectors**

```html

    section class="container">
      <form id="my-form">
        <h1>Add User</h1>
        <div class="msg"></div>
        <div>
          <label for="name">Name:</label>
          <input type="text" id="name">
        </div>
        <div>
          <label for="email">Email:</label>
          <input type="text" id="email">
        </div>
        <input class="btn" type="submit" value="Submit">
      </form>

      <ul id="users"></ul>

      <ul class="items">
        <li class="item">Item 1</li>
        <li class="item">Item 2</li>
        <li class="item">Item 3</li>
      </ul>
    </section>

```

- *Single Element*

```javascript

    document.getElementById(); // Get by HTML id.
    const form = document.getElementById('my-form');
    console.log(form);

    document.querySelector('.container'); // Query selector can get classes and tags elements. 
    document.querySelector('h1'); // Single element. It will get the first one that matches the parameter only.

```

- *Multiple Element*

```javascript
    document.querySelectorAll('h1'); // returns a NodeList. It is similar to an array and has the same methods.

    document.getElementsByClassName('item'); // returns an HTMLCollection. Cannot use Array methods.
    document.getElementsByTagName('li'); // returns an HTMLCollection. Cannot use Array methods.
```

**Looping**

```javascript

const items = document.querySelectorAll('.item'); // returns a NodeList. It is similar to an array and has the same methods.

items.forEach((item) => console.log(item));

```

**DOM manipulation**

```javascript

    const ul = document.querySelector('.items'); // UL is an Unordered List.

    ul.remove(); // Removes the entire UL

    ul.lastElementchild.remove(); //Get Last Element . Remove

    ul.firstElementchild.textContent = 'This has been changed.'; //Get First Element . Text property

    ul.children[1].innerText = 'This has been changed as well.'; // Same as the last example.

    ul.children[1].innerHTML = '<h1>This has been changed as well.<h1>'; // Adds HTML

    const btn = document.querySelector('.btn');
    btn.style.background = 'red';
```

## 9 - Events

```javascript

    const btn = document.querySelector('.btn');

    btn.addEventListener('click', (e) => {
        e.preventDefault();
        const className = e.target.className;
        console.log('click');
    })

    myForm.addEventListener('submit', onSubmit);

    function onSubmit(e){
        e.preventDefault();

        console.log(nameInput.value);
    }

// USER FORM SCRIPT

// Put DOM elements into variables
const myForm = document.querySelector('#my-form');
const nameInput = document.querySelector('#name');
const emailInput = document.querySelector('#email');
const msg = document.querySelector('.msg');
const userList = document.querySelector('#users');

// Listen for form submit
myForm.addEventListener('submit', onSubmit);

function onSubmit(e) {
  e.preventDefault();
  
  if(nameInput.value === '' || emailInput.value === '') {
    // alert('Please enter all fields');
    msg.classList.add('error');
    msg.innerHTML = 'Please enter all fields';

    // Remove error after 3 seconds
    setTimeout(() => msg.remove(), 3000);
  } else {
    // Create new list item with user
    const li = document.createElement('li');

    // Add text node with input values
    li.appendChild(document.createTextNode(`${nameInput.value}: ${emailInput.value}`));

    // Add HTML
    // li.innerHTML = `<strong>${nameInput.value}</strong>e: ${emailInput.value}`;

    // Append to ul
    userList.appendChild(li);

    // Clear fields
    nameInput.value = '';
    emailInput.value = '';
  }
}
```

## 10 - Others

**Switch**

```javascript
color = 'blue';

switch(color) {
  case 'red':
    console.log('color is red');
  case 'blue':
    console.log('color is blue');
  default:  
    console.log('color is not red or blue')
}

```

**Ternary operator**

```javascript
const z = color === 'red' ? 10 : 20;
```
