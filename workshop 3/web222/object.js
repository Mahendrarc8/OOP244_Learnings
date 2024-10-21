let obj = {name: 'M', college: 'Seneca College', id: 14333} //an object has key and value

let course = {
    morning: ['OPS102', 'WEB222'],
    afternoon: ['DBS211']
}

console.log(course.morning[1]);
console.log(course['morning'][1]);

let menu = {
    breakfast: ['eggs', 'toast', 'banana', 'coffee'],
    lunch: ['salad', 'chicken', 'apple', 'milk'],
    dinner: ['salmon', 'rice', 'green beans']
};

console.log(menu['breakfast'][3]);
console.log(menu.lunch[3]);
console.log(menu.dinner[0]);

let object = {};

object.name = 'Mark';

console.log(object.name);

// delete object.name;
// console.log(object.name);

