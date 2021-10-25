**Basic Javascript**

*Summary*

SOURCE = [https://www.youtube.com/watch?v=hdI2bqOjy3c]
FULL CODE = [https://embed.plnkr.co/plunk/8ujYdL1BxZftGoS4Cf14]
FULL JAVASCRIPT DOC = [https://javascript.info/]
________________________________________________________________________________________________________________________

## 0 - Variable declaration


**[var] [let] & [const]**

```javascript

var name = "Juan"; // Globally Scoped. Do not use.

let age; // Not globally scoped

age = 25;

const birthdate =  new Date("24/07/1995"); // Const must be initialized.

```
________________________________________________________________________________________________________________________


## 1 - Console

**[Basic] [Comands]**

```javascript

console.log(`Hello world, my name is Juan`);

console.error(test);

console.warn(test);

```
________________________________________________________________________________________________________________________


## 2.0 - Primitive data types.

**Strings, numbers, boolean, null, undefined, symbol**

**[Number] [Types?]**

- En este ejemplo, *ambas* variables son de tipo **"number"**. _**No** se aplican tipos estrictos como float, decimal, etc_.

```javascript

let a = 35;
let b = 3.5;

console.log(typeof a);
console.log(typeof b);
```

**[Undefined]**

- Not assigned variables are **undefined**.

________________________________________________________________________________________________________________________

## 2.1 - Strings.

**[Interpolation]**

```javascript
console.log(`Hello world, my name is ${name}`); // Interpolation requires string to be between grave accents (`).
``` 

**[String] [Properties] & [Methods()]** (**Method:** A *function* associated with an *object*.)

```javascript
    let s = `Hello world`;

    console.log(s.length);
    console.log(s.toUpperCase());
    console.log(s.toLowerCase());
    console.log(s.substring(0,1)); // Start and end indexes.

    let fruits = "apple, banana, pear, orange";

    console.log(fruits.split(', ')); // Returns an array of strings (4) ["apple", "banana", "pear", "orange"]
```

________________________________________________________________________________________________________________________

## 3 - Arrays

**[Declaration]**

```javascript

    const numbers = new Array(1,2,3,4,5); // Using a constructor.
    const empty = []; // Most commonly used.

    const fruits = ['apple', 'orange', 'pear'];     

    const weird = ['a string', true, 5, fruits]; // different types are allowed.

    fruits[3] = 'grape'; // Even though the array is a const, its contained elements can change.

```

- **Multiple types** are **allowed** in an array, that's the case with *weird*. 

- **Array size** is also *not mandatory*.

**[Functions] & [Methods]**

```javascript

    Array.isArray(fruits); // true!

    fruits.push('mango'); // Add to the array (last position).
    
    fruits.unshift('strawberry'); // Add to the array (first position).

    fruits.pop(); // Remove from the array (last position). Bye bye mango.

    fruits.indexOf('orange'); // = 2

```
________________________________________________________________________________________________________________________

## 4 - Objects Literals

**[Declaration]**

```javascript

        const person = {
            firstName : 'Juan Jose',
            lastName : 'Morales',
            age : 25,
            hobbies : ['programming', 'games', 'music', 'movies & tv shows'],
            address : {
                street : 'Kutaisi Street, 10',
                city : 'Tbilisi',
                country : 'GE'

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
        

```

## 4.1 - Object to JSON

**[CONVERTtoJSON]** : *Object* to **.JSON**

```javascript

    const toDosJSON = JSON.stringify(toDos);

```
________________________________________________________________________________________________________________________

## 5.1 - Loops: for, while

**[for]**

```javascript


    for(let i=0; i < 10; i++){
        console.log(i);
    }

```

**[for] [Arrays/Objects]**

```javascript

    for (let todo of toDos){
        console.log(todo.text);
    }

```

**[while]**

```javascript

    let i = 0;
    while(i<10){
        console.log(i);
        i++;
    }

```

________________________________________________________________________________________________________________________

## 5.2 - High Order Array: forEach, map, filter

**[forEach]** Loops through array

```javascript

    toDos.forEach(function (todo) {
        console.log(todo.text)
    });

```

**[map]** Loop through and create new array

```javascript

    const toDoText = toDos.map(function (todo) {
        return todo.text
    });

```

**[filter]** Returns array based on condition

```javascript

    const toDoCompleted = toDos.filter(function (todo) {
        return todo.isCompleted === true; // '===' checks for data type. '==' does not. x = 10 and y = "10" are == but not ===
    });

```

## 6 - Functions

**[Function] [With] [Default] [Values]**

```javascript

    function Sum(num1 = 1, num2 = 2){
        console.log(num1+num2);
    }

    // Sum() or Sum(num1, num2); are allowed.    
```

**[Arrow] [Function]**

```javascript

    const Sum = (num1 = 1, num2 = 2) => {     // Sum() or Sum(num1, num2); are allowed.    
        console.log(num1+num2);
    }

    const Multiply = (num1 = 5, num2 = 5) => num1 * num2; // Return is not necessary.

    todos.forEach ( (todo) => console.log(todo.text) );

```

## 7 - OOP

**[Constructor] & [Prototype]**

```javascript

    function Person(firstName, lastName, dob){
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

**[Classes]** Same thing, but with *OOP* syntax.

```javascript

class Person {    
    constructor(firstName, lastName, dob){
        this.firstName = firstName;
        this.lastName = lastName;
        this.dob = new Date(dob);
    }

    getBirthYear(){
        return this.dob.getFullYear();
    }

    getFullName(){
        return `${this.firstName} ${this.lastName}`;
    }
}

const person1 = new Person('Juan Jose', 'Morales', '24-7-1995');
```


## 8 - DOM = Document Object Model

**[Window] [Object]**

```javascript
    console.log(window);
```

**[Selectors]**

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

*Single Element*

```javascript

    document.getElementById(); // self explained
    const form = document.getElementById('myForm');
    console.log(document.getElementById('myForm'));

    document.querySelector('.container'); // Query selector can get classes and tags elements. 
    document.querySelector('h1'); // Single element. It will get the first one that matches the parameter only.

```

*Multiple Element*

```javascript



    document.querySelectorAll('h1'); // returns a NodeList. It is similar to an array and has the same methods.

    document.getElementsByClassName('item'); // returns an HTMLCollection. Cannot use Array methods.
    document.getElementsByTagName('li'); // returns an HTMLCollection. Cannot use Array methods.

```

**[Looping]**

```javascript

const items = document.querySelectorAll('.item'); // returns a NodeList. It is similar to an array and has the same methods.

items.forEach((item) => console.log(item));

```

**[DOM] [Manipulation]**

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

    btn.addEventListener('click', (e) =>{  //other events > mouseover, mouseout
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

**[Switch]**

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

**[Ternary] [Operator]**

```javascript
const z = color === 'red' ? 10 : 20;
```