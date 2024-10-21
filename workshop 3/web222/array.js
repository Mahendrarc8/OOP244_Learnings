let arr = new Array(2, 3, 4);

let arr1 = [1, 2, 3, 4];
console.log(arr.length); // to print the length of the first array

let arr2 = ['First', 2, 4.5, true]; //Value of any data type can be stored in JS array.
console.log(arr2[2]);

let dateString = `17/02/2001`;
let [day, month, year] = dateString.split('/');
console.log(`The day is ${day}, month is ${month}, and year is ${year}`);

let email = 'mroka1@myseneca.ca';
let [username] = email.split('@');
console.log(username);

