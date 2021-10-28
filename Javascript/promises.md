# Ejemplo de una "promesa".

## Cómo crear una función que devuelve una promesa:

```javascript
// Busca un perro de nombre 'x' en nuestros datos. 
function findDog(dog)
{
    // Aca podrias estar trayendolos de una base de datos, por ej.
    const dogs = ['Roque', 'Michael', 'Johnny B.', 'Nico'];

    // Pero para este ej supongamos que solo tenemos estos, los del array 'dogs'.

    // Aqui creamos y devolvemos la promesa.
    return new Promise((resolve, reject) => {

        // Aca podrias manejar toda la logica para filtrar a los perros, o lo que fuera.
        
        // En este caso solo usamos este if.
        // "find" devuelve un boolean 
        // al primer elemento que coincida con las condiciones.
        if (dogs.find(el => dog != el)) 
        {
            // Devolvemos un reject y por parametro
            // la razon por la que se rechaza la request.
            reject(`No se encontró a "${dog}" 😓`); 
        }

        else resolve(`Se encontró a ${dog} 😎.`); // Si ta todo bien, devolves los datos 
    });
}
```

## Ejemplo de invocar la funcion, y "consumir" la promesa:

```javascript
findDog("Charlie")
.then((msg) => { // 'then' se ejecuta cuando se 'resuelve' la promesa (resolve).
    console.log(msg);
})
.catch((error) => { // y el 'catch', en caso de que haya algun error. 

    // El parametro error sera la razon del reject.

    console.log(error); // Aqui, el .then() no se ejecuta
})
.finally(() => { // 'finally' se ejecuta no importa el resultado de tu solicitud.
    console.log("Se terminaron las operaciones")
})
```
### OUTPUT:
```
❯ node promises.js 
No se encontró a "Charlie" 😓
Se terminaron las operaciones
```
